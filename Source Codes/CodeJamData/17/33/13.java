package kz.abishev.round1c;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
  public static final String NAME = "C";
  public static final int ATTEMPT = 0;

  public static final double EPS = 0.000001;

  public static void runTest(Scanner input, PrintWriter output) {
    int n = input.nextInt();
    int k = input.nextInt();

    double u = input.nextDouble();
    double[] p = new double[n];
    for (int i = 0; i < n; i++) p[i] = input.nextDouble();
    Arrays.sort(p);

    assert n == k;
    while (u >= EPS) {
      // number of equal
      int eq = 0;
      while (eq < n && Math.abs(p[eq] - p[0]) < EPS) eq++;
      // add equally to first eq
      // what to add?
      double nextP = eq == n ? 1 : p[eq];
      double toAdd = Math.min(u / eq, nextP - p[0]);
      for (int i = 0; i < eq; i++) p[i] += toAdd;
      u -= toAdd * eq;
    }

    double ans = 1;
    for (int i = 0; i < n; i++) ans *= p[i];

    output.format("%.7f%n", ans);
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
    runWithFiles(NAME + "-small-1-attempt" + ATTEMPT + ".in.txt",
        NAME + "-small-1-attempt" + ATTEMPT + ".out.txt");
  }

  public static void runLarge() throws FileNotFoundException {
    runWithFiles(NAME + "-large.in.txt", NAME + "-large.out.txt");
  }

  public static void main(String[] args) throws FileNotFoundException {
//    runConsole();
    runSmall();
//    runLarge();
  }
}
