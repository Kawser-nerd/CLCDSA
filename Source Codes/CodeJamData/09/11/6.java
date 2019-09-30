import java.util.*;
import java.io.*;

public class x {
  public static void main (String args []) throws Exception {
    BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
    int t = Integer.parseInt (in.readLine ());

    boolean [][] isL = new boolean [11][20000000];
    for (int j = 2; j <= 10; j++)
      isL[j][1] = true;
    for (int i = 2; i < 20000000; i++) {
      if ((i & 1048575) == 0) System.err.println (i);
      for (int j = 2; j <= 10; j++)
        if (i < 100) {
          HashSet <Integer> h = new HashSet <Integer> ();
          int c = i;
          for (;;) {
            h.add (c);
            //System.out.println (j + " " + c);
            int q = 0;
            while (c > 0) {
              int d = c % j;
              q = q + d * d;
              c /= j;
            }
            c = q;
            if (c < i || h.contains (c)) break;
          }
          isL[j][i] = isL[j][c];
        } else {
          int c = i;
          int q = 0;
          while (c > 0) {
            int d = c % j;
            q = q + d * d;
            c /= j;
          }
          c = q;
          assert c < i;
          isL[j][i] = isL[j][c];
        }
      }
    
    for (int tt = 1; tt <= t; tt++) {
      boolean [] f = new boolean [11];
      StringTokenizer tok = new StringTokenizer (in.readLine ());
      while (tok.hasMoreTokens ()) {
        int a = Integer.parseInt (tok.nextToken ());
        f[a] = true;
      }
      int ans = -1;
      for (int i = 2; i < 20000000; i++) {
        boolean ok = true;
        for (int j = 2; j <= 10; j++)
          if (f[j])
            ok &= isL[j][i];
        if (ok) {
          ans = i;
          break;
        }
      }
      System.out.println ("Case #" + tt + ": " + ans);
    };
  };
};