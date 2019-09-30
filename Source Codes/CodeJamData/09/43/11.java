import java.util.*;
import java.io.*;

public class x {
  static boolean [][] G;

  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      int n = in.nextInt ();
      int k = in.nextInt ();
      
      G = new boolean [n][n];
      int [][] A = new int [n][k];
      for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
          A[i][j] = in.nextInt ();

      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
          boolean ok = true;
          for (int l = 0; l < k; l++)
            if (A[i][l] <= A[j][l]) {
              ok = false;
              break;
            }
          G[i][j] = ok;
        }

      int Z = 1 << n;

      boolean [] Q = new boolean [Z];

      for (int i = 0; i < Z; i++) {
        Q[i] = true;
        for (int a = 0; a < n; a++)
          if ((i & (1 << a)) != 0)
            for (int b = 0; b < n; b++)
              if (a != b && ((i & (1 << b)) != 0))
                if (!G[a][b] && !G[b][a])
                  Q[i] = false;
      }

      /*for (int i = 0; i < 8; i++)
        System.out.println (Q[i]);*/
                
      int [] D = new int [Z];
      
      Arrays.fill (D, 1000);

      D[0] = 0;
      for (int i = 0; i < Z; i++)
        for (int j = i; j < Z; j = (j + 1) | i)
          if (Q[i ^ j])
            D[j] = Math.min (D[j], D[i] + 1);
       
      System.out.println ("Case #" + tt + ": " + D[Z - 1]);
    };
  };
};