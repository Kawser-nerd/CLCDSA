import java.util.*;
import java.io.*;

public class x {
  static final int MOD = 100003;
  static final int MAXN = 500;
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();


    int [][] C = new int [MAXN + 1][MAXN + 1];

    for (int i = 0; i <= MAXN ; i++) {
      C[i][0] = 1;
      for (int j = 1; j <= i; j++) {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
      }
    }

    int [][] D = new int [MAXN + 1][MAXN + 1];
    int [] A = new int [MAXN + 1];

    D[1][0] = 1;
    for (int i = 2; i <= MAXN; i++) {
      for (int j = 1; j < i; j++) {
        for (int k = 0; k < j; k++)
          if (j - k - 1 >= 0 && j - k - 1 <= i - j - 1) {
            long cur = D[j][k];
            cur = (D[i][j] + cur * C[i - j - 1][j - k - 1]) % MOD;
            D[i][j] = (int)cur;
            //System.out.println (i + " " + j + " " + k + ": " + D[i][j] + " " + D[j][k] + " " + C[i - j - 1][j - k - 1]);
          }
        A[i] = (A[i] + D[i][j]) % MOD;
      }
    }


    for (int tt = 1; tt <= t; tt++) {
      int n = in.nextInt ();

      System.out.println ("Case #" + tt + ": " + A[n]);
    };
  };
};