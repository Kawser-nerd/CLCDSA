import java.util.*;
import java.io.*;

public class x {
  static int p, z, M [], A[][];

  static long D[][][];
  static boolean F[][][];

  static long rec (int m, int l, int v) {
    if (l == p) {
      if (m > M[v]) {
        return Integer.MAX_VALUE;
      } else {
        return 0;
      }
    }
    if (F[m][l][v]) {
      return D[m][l][v];
    }
    D[m][l][v] = Math.min (rec (m + 1, l + 1, 2 * v) + rec (m + 1, l + 1, 2 * v + 1),
                           rec (m, l + 1, 2 * v) + rec (m, l + 1, 2 * v + 1) + A[p - l - 1][v]);
    F[m][l][v] = true;
    //System.out.println (m + " " + l + " " + v + ": " + D[m][l][v]);
    return D[m][l][v];
  }

  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      p = in.nextInt ();
      z = 1 << p;
      M = new int [z];
      A = new int [p][z];
      for (int i = 0; i < z; i++)
        M[i] = in.nextInt ();
      for (int i = 0; i < p; i++)
        for (int j = 0; j < (1 << (p - i - 1)); j++)
          A[i][j] = in.nextInt ();

      D = new long [p][p][z];
      F = new boolean [p][p][z];

      System.out.println ("Case #" + tt + ": " + rec (0, 0, 0));
    };
  };
};