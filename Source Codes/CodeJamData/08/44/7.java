import java.util.*;
import java.io.*;

public class x {
  static int mn, a[], l, k;
  static char [] c1, c2;
  static boolean []b;


  static void rec (int x) {
    if (x >= k) {
      for (int j = 0; j < l / k; j++)
        for (int d = 0; d < k; d++) {
          c2[k * j + a[d]] = c1[k * j + d];
        };

      char cc = '@';
      int cnt = 0;

      for (int j = 0; j < l; j++)
        if (c2[j] != cc) {
          cc = c2[j];
          ++cnt;
        };

      mn = Math.min (cnt, mn);


    } else {
      for (int i = 0; i < k; i++)
        if (!b[i]) {
          b[i] = true;
          a[x] = i;
          rec (x + 1);
          b[i] = false;
        };
    };
  };


  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      k = in.nextInt ();
      String s = in.next ();
      l = s.length ();
      c1 = s.toCharArray ();
      c2 = new char [l];
      mn = (int)1e9;
      a = new int [k];
      b = new boolean [k];

      rec (0);

      System.out.println ("Case #" + tt + ": " + mn);
    };
  };
};