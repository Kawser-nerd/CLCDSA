import java.util.*;
import java.math.*;

public class x {
  static class Order implements Comparable <Order> {
    int c, a, b;

    Order (int cc, int aa, int bb) {
      c = cc;
      a = aa;
      b = bb;
    };

    public int compareTo (Order z) {
      if (a != z.a) return a - z.a;
      if (b != z.b) return b - z.b;
      if (c != z.c) return c - z.c;
      return 0;
    };
  };
  
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int tn = in.nextInt ();
    for (int tt = 1; tt <= tn; tt++) {
      int n = in.nextInt ();

      HashMap <String, Integer> col = new HashMap <String, Integer> ();
      
      int cc = 0;

      Order [] o = new Order [n];

      for (int j = 0; j < n; j++) {
        String s = in.next ();
        Integer cn = col.get (s);
        if (cn == null) {
          col.put (s, cc);
          cn = cc;
          ++cc;
        };
        int a = in.nextInt ();
        int b = in.nextInt ();
        o[j] = new Order (cn, a, b);
      };


      Arrays.sort (o);

      int ans = Integer.MAX_VALUE;

      for (int a = 0; a < cc; a++)
        for (int b = a; b < cc; b++) {
          int [] lcur = new int [cc];
          int [] lplus = new int [cc];
          int [] lcnt = new int [cc];
          Arrays.fill (lcur, 1);
          Arrays.fill (lplus, -1);
          Arrays.fill (lcnt, 0);

          for (int i = 0; i < n; i++) {
            for (int j = 0; j < cc; j++) {
              if (lcur[j] < o[i].a) {
                lcur[j] = lplus[j];
                ++lcnt[j];
              };
            };
            if (o[i].c == a || o[i].c == b) {
              for (int j = 0; j < cc; j++) {
                if (lcur[j] >= o[i].a) {
                  if (lplus[j] <= o[i].b) lplus[j] = o[i].b + 1;
                };
              };
            } else {
              if (lcur[o[i].c] >= o[i].a) {
                if (lplus[o[i].c] <= o[i].b)
                  lplus[o[i].c] = o[i].b + 1;
              };
            };
          };

          for (int j = 0; j < cc; j++) {
            if (lcur[j] <= 10000) {
              lcur[j] = lplus[j];
              ++lcnt[j];
            };
          };

          for (int i = 0; i < cc; i++)
            if (lcur[i] > 10000)
              ans = Math.min (ans, lcnt[i]);


        };


      System.out.print ("Case #" + tt + ": ");
      if (ans < Integer.MAX_VALUE) System.out.println (ans); else System.out.println ("IMPOSSIBLE");

    };
  };
};
