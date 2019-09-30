import java.util.*;
import java.io.*;

public class x {
  static int o [], c [], v [], q;

  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      int m = in.nextInt (), r = in.nextInt ();
      q = (m - 1) / 2;
      o = new int [q + 1];
      c = new int [q + 1];
      v = new int [m + 1];
      for (int j = 1; j <= q; j++) {
        o[j] = in.nextInt ();
        c[j] = in.nextInt ();
      };
      for (int j = q + 1; j <= m; j++)
        v[j] = in.nextInt ();

      int [][] D = new int [m + 1][2];

      for (int i = 0; i <= m; i++)
        for (int j = 0; j <= 1; j++)
          D[i][j] = (int)1e9;

      for (int i = q + 1; i <= m; i++)
        D[i][v[i]] = 0;

      for (int i = q; i >= 1; i--) {
        int allz = D[2 * i][0] + D[2 * i + 1][0];
        int andz = (int)1e9;
        if (c[i] == 1 || o[i] == 1)
            andz = Math.min (D[2 * i][1] + D[2 * i + 1][0],
                             D[2 * i][0] + D[2 * i + 1][1]) + (1 - o[i]);
        allz = Math.min (allz, andz);
        D[i][0] = Math.min (D[i][0], allz);

        int allt = D[2 * i][1] + D[2 * i + 1][1];
        int andt = (int)1e9;
        
        if (c[i] == 1 || o[i] == 0)
            andt = Math.min (D[2 * i][1] + D[2 * i + 1][0],
                             D[2 * i][0] + D[2 * i + 1][1]) + o[i];
        allt = Math.min (allt, andt);
        D[i][1] = Math.min (D[i][1], allt);
        //System.out.println (i + " " + D[i][0] + " " + D[i][1]);
      };


      if (D[1][r] >= (int)1e9)
        System.out.println ("Case #" + tt + ": IMPOSSIBLE");
      else
        System.out.println ("Case #" + tt + ": " + D[1][r]);
    };
  };
};