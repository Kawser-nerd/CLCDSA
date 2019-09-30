package kz.abishev.round1c;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import javax.print.attribute.standard.MediaSize;

public class A {
  public static final String NAME = "A";
  public static final int ATTEMPT = 0;

  public static void runTest(Scanner input, PrintWriter output) {
    int n = input.nextInt();
    int k = input.nextInt();
    long[] r = new long[n];
    long[] h = new long[n];

    for (int i = 0; i < n; i++) {
      r[i] = input.nextInt();
      h[i] = input.nextInt();
    }

    // ans for k == 1, ans is being / Math.PI
    long[] ans = new long[n];
    for (int i = 0; i < n; i++) {
      ans[i] = 2L * h[i] * r[i] + r[i] * r[i];
    }

    for (int ii = 1; ii < k; ii++) {
      long[] nAns = new long[n];

      for (int i = 0; i < n; i++) {
        nAns[i] = -1;
        for (int prev = 0; prev < n; prev++) {
          if (r[prev] > r[i] || (r[prev] == r[i] && h[prev] > h[i]) ||
              (r[prev] == r[i] && h[prev] == h[i] && prev > i)) {
            if (ans[prev] != -1) {
              nAns[i] = Math.max(nAns[i], ans[prev] + 2L * r[i] * h[i]);
            }
          }
        }
      }

      ans = nAns;
    }

    long optimal = -1;
    for (int i = 0; i < n; i++) {
      optimal = Math.max(optimal, ans[i]);
    }

    assert optimal != -1;

    output.format("%.7f%n", optimal * Math.PI);
  }

  public static void run(InputStream _input, OutputStream _output) {
    Scanner input = new Scanner(_input);
    PrintWriter output = new PrintWriter(_output);
    int t = input.nextInt();
    input.nextLine();
    for (int tt = 1; tt <= t; tt++) {
      output.print("Case #" + tt + ": ");
      runTest(input, output);
      output.flush();
    }
  }

  public static void runConsole() {
    run(System.in, System.out);
  }

  public static void runWithFiles(String inputFile, String outputFile) throws FileNotFoundException {
    InputStream input = new FileInputStream(new File(inputFile));
    OutputStream output = new FileOutputStream(new File(outputFile));
    try {
      run(input, output);
    } finally {
      try {
        output.close();
      } catch (IOException e) {
        e.printStackTrace();
      }
      try {
        input.close();
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
  }

  public static void runSmall() throws FileNotFoundException {
    runWithFiles(NAME + "-small-attempt" + ATTEMPT + ".in.txt",
        NAME + "-small-attempt" + ATTEMPT + ".out.txt");
  }

  public static void runLarge() throws FileNotFoundException {
    runWithFiles(NAME + "-large.in.txt", NAME + "-large.out.txt");
  }

  public static void main(String[] args) throws FileNotFoundException {
//    runConsole();
//    runSmall();
    runLarge();
  }
}
