import java.util.*;
import java.io.*;
import java.math.*;

public class x {
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    long [][] C = new long [41][41];

    for (int i = 0; i <= 40; i++) {
      C[i][0] = 1;
      for (int j = 1; j <= i; j++)
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }


    MathContext mc = new MathContext (50, RoundingMode.HALF_EVEN);
    for (int tt = 1; tt <= t; tt++) {
      int A = in.nextInt (), N = in.nextInt ();

      BigDecimal [] E = new BigDecimal [A + 1];
      E[A] = new BigDecimal (0, mc);
      for (int i = A - 1; i >= 0; i--) {
        E[i] = new BigDecimal (C[A][N], mc);
        for (int j = i + 1; j <= Math.min (A, i + N); j++) {
          BigDecimal P = new BigDecimal (C[A - i][j - i], mc);
          P = P.multiply (new BigDecimal (C[i][N - j + i], mc), mc);
          //System.out.println (i + " " + j + " " + P);
          E[i] = E[i].add (P.multiply (E[j], mc), mc);
        }
        BigDecimal D = new BigDecimal (C[A][N], mc).subtract (
                         new BigDecimal (C[i][N], mc), mc);
        E[i] = E[i].divide (D, mc);
        //System.out.println (E[i]);
      }

      System.out.println ("Case #" + tt + ": " + E[0]);
    };
  };
};