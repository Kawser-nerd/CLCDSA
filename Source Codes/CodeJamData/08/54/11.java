import java.util.*;
import java.io.*;

public class x {

  static int fla (int p, int q) {
    int ti = 2 * q - p;
    int tj = 2 * p - q;

    if (ti % 3 != 0 || tj % 3 != 0) return 0;
    ti /= 3;
    tj /= 3;
    return 0;
  };

  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      int h = in.nextInt ();
      int w = in.nextInt ();
      int r = in.nextInt ();

      int [] a = new int [r], b = new int [r];

      boolean [][] f = new boolean [h + 1][w + 1];

      for (int i = 0; i < r; i++) {
        a[i] = in.nextInt ();
        b[i] = in.nextInt ();
        //System.out.println (h + " " + w + " " + a[i] + " " + b[i]);
        f[a[i]][b[i]] = true;
      };

      int [][] D = new int [h + 1][w + 1];

      D[1][1] = 1;

      for (int i = 2; i <= h; i++)
        for (int j = 2; j <= w; j++)
          if (!f[i][j])
            D[i][j] += (D[i - 2][j - 1] + D[i - 1][j - 2]) % 10007;

      System.out.println ("Case #" + tt + ": " + D[h][w]);
    };
  };
};