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

public class B {
  public static final String NAME = "B";
  public static final int ATTEMPT = 0;

  public final static int LENGTH = 720 * 2;
  public final static int IMPOSSIBLE = 2000;
  public final static int OFFSET = 720;

  public static void runTest(Scanner input, PrintWriter output) {
    int ac = input.nextInt();
    int aj = input.nextInt();

    int n = ac + aj;

    int[] who = new int[LENGTH];
    Arrays.fill(who, 0);

    for (int i = 0; i < ac; i++) {
      int l = input.nextInt();
      int r = input.nextInt();
      for (int j = l; j < r; j++) who[j] = 1;
    }
    for (int i = 0; i < aj; i++) {
      int l = input.nextInt();
      int r = input.nextInt();
      for (int j = l; j < r; j++) who[j] = 2;
    }

    int ans = IMPOSSIBLE;
    for (int first = 1; first <= 2; first++) {
      if (who[0] == first || who[0] == 0) {
        // start from first
        int[][] d = new int[3][722 * 2];
        Arrays.fill(d[1], IMPOSSIBLE);
        Arrays.fill(d[2], IMPOSSIBLE);

        if (first == 1) {
          d[1][OFFSET + 1] = 0;
        } else {
          d[2][OFFSET - 1] = 0;
        }

        // go
        for (int i = 1; i < LENGTH; i++) {
          int[][] dNew = new int[3][722 * 2];
          Arrays.fill(dNew[1], IMPOSSIBLE);
          Arrays.fill(dNew[2], IMPOSSIBLE);

          for (int prevValue = 1; prevValue <= 2; prevValue++) {
            for (int prevOffset = -720; prevOffset <= 720; prevOffset++) {
              if (d[prevValue][OFFSET + prevOffset] != IMPOSSIBLE) {
                int current = d[prevValue][OFFSET + prevOffset];
//                System.out.println("d[" + prevValue + ", " + prevOffset + "]=" + current);

                for (int newValue = 1; newValue <= 2; newValue++) {
                  if (who[i] == newValue || who[i] == 0) {
                    int newOffset = prevOffset + (newValue == 1 ? 1 : -1);
                    if (newOffset >= -720 && newOffset <= 720) {
                      dNew[newValue][OFFSET + newOffset] = Math.min(
                          dNew[newValue][OFFSET + newOffset],
                          current + (prevValue == newValue ? 0 : 1)
                      );
                    }
                  }
                }
              }
            }
          }
          d = dNew;
//          System.out.println("----");
//          try {
//            Thread.sleep(2000);
//          } catch (InterruptedException e) {
//            e.printStackTrace();
//          }
        }
        // check ans
        ans = Math.min(ans, d[1][OFFSET + 0] + (first == 1 ? 0 : 1));
        ans = Math.min(ans, d[2][OFFSET + 0] + (first == 2 ? 0 : 1));
      }
    }

    output.println(ans);
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
