import java.util.*;
import java.io.*;

public class x {
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      int n = in.nextInt ();

      int [] x = new int [n], y = new int [n], r = new int [n];

      for (int i = 0; i < n; i++) {
        x[i] = in.nextInt ();
        y[i] = in.nextInt ();
        r[i] = in.nextInt ();
      }

      double ans = -1;

      if (n == 1) ans = r[0]; else
      if (n == 2) ans = Math.max (r[0], r[1]); else
      if (n == 3) {
        ans = Math.max (r[0], 0.5 * (Math.hypot (x[2] - x[1], y[2] - y[1]) + r[1] + r[2]));
        ans = Math.min (ans,
          Math.max (r[1], 0.5 * (Math.hypot (x[2] - x[0], y[2] - y[0]) + r[0] + r[2]))
        );
        ans = Math.min (ans,
          Math.max (r[2], 0.5 * (Math.hypot (x[1] - x[0], y[1] - y[0]) + r[0] + r[1]))
        );
      }

      System.out.println ("Case #" + tt + ": " + ans);
    };
  };
};