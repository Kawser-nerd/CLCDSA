import java.util.*;
import java.io.*;

public class x {
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      int n = in.nextInt (), k = in.nextInt ();
      long b = in.nextInt (), T = in.nextInt ();
      long [] x = new long [n], v = new long [n];
      for (int i = 0; i < n; i++) x[i] = in.nextInt ();
      for (int i = 0; i < n; i++) v[i] = in.nextInt ();
      int good = 0, bad = 0, swaps = 0;
      for (int i = n - 1; i >= 0 && good < k; i--) {
        if (b - x[i] <= T * v[i]) {
          ++good;
          swaps += bad;
        } else ++bad;
      }

      if (good < k) {
        System.out.println ("Case #" + tt + ": " + "IMPOSSIBLE");
      } else {
        System.out.println ("Case #" + tt + ": " + swaps);
      }
    };
  };
};