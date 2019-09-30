import java.util.*;
import java.io.*;

public class x {
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      int m = in.nextInt ();
      int n = in.nextInt ();

      int [] F = new int [m];

      for (int i = 0; i < m; i++) {
        String s = in.next ();
        for (int j = 0; j < n; j++)
          if (s.charAt (j) == 'x') F[i] |= 1 << j;
      };

      int [][] D = new int [m + 1][1 << n];

      for (int i = 0; i <= m; i++)
        for (int j = 0; j < 1 << n; j++)
          D[i][j] = (int)-1e8;

      D[0][0] = 0;

      boolean [] v = new boolean [1 << n];
      int [] bc = new int [1 << n];

      for (int i = 0; i < 1 << n; i++) {
        int x = i, pr = 0;
        while (x > 0) {
          int c = x & 1;
          if (c == 1 && pr == 1) v[i] = true;
          pr = c;
          x >>= 1;
          bc[i] += c;
        };
      };


      for (int k = 0; k < m; k++)
        for (int a = 0; a < 1 << n; a++)
          if (D[k][a] >= 0) {
            //System.out.println (k + " " + a);
            for (int b = 0; b < 1 << n; b++)
              if (!v[b] && (F[k] & b) == 0 && ((a << 1) & b) == 0 && (a & (b << 1)) == 0) {
                //System.out.println ((k + 1) + " " + b);
                D[k + 1][b] = Math.max (D[k + 1][b], D[k][a] + bc[b]);
              };
          };


      int ans = 0;
      for (int a = 0; a < 1 << n; a++) 
        ans = Math.max (ans, D[m][a]);


      System.out.println ("Case #" + tt + ": " + ans);
    };
  };
};