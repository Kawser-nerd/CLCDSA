import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.System.out;
import static java.lang.Math.*;

public class BaiB implements Runnable {

  public void run() {
    int ntest = getint();
    for (int test = 1; test <= ntest; ++test) {
      long E = getlong();
      long R = getlong();
      int n = getint();
      int[] v = new int[n];
      for (int i = 0; i < n; ++i)
        v[i] = getint();
      TreeSet<int[]> se = new TreeSet<int[]>(new Comparator<int[]>() {
        public int compare(int[] x, int[] y) {
          if (x[0] != y[0]) return y[0] - x[0];
          return y[1] - x[1];
        }
      });
      R = min(R, E);
      long cur = E;
      long res = 0;
      long[] rem = new long[n];
      for (int i = 0; i < n; ++i) {
        if (i == 0) rem[i] = E;
        else rem[i] = R;

        se.add(new int[]{v[i], i});
        int[] last;
        while (((last = se.last()) != null) && last[0] <= v[i] && last[1] != i) {
          rem[i] += rem[last[1]];
          rem[last[1]] = 0;
          se.remove(se.last());
        }
        if (cur + R > E || i == n - 1) {
          long claim = cur + R - E;
          if (i == n - 1) claim = cur;

          while (claim > 0) {
            int[] f = se.first().clone();
            long sub = min(claim, rem[f[1]]);
            // if (sub < 0) System.err.println("WRONG");
            sub = max(sub, 0);
            claim -= sub;
            rem[f[1]] -= sub;
            res += sub * v[f[1]];
            // out.println(sub + " " + v[f[1]]);
            if (rem[f[1]] <= 0) {
              se.remove(f);
            }
          }
          cur = E;
        } else cur += R;
      }

      out.println("Case #" + test + ": " + res);
    }
  }

    int[] ar(int st, int en) { int[] res = new int[Math.max(en - st, 0)]; for (int i = st; i < en; ++i) res[i - st] = i; return res; }
    int[] ar(int n) { return ar(0, n); }
    void viet(Object...os) { System.err.println(Arrays.deepToString(os)); }
    BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer strtok = null;

    String getstr() {
        try {
            while(strtok == null || !strtok.hasMoreTokens())
                strtok = new StringTokenizer(keyboard.readLine());
            return strtok.nextToken();
        }
        catch(Exception ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
            return null;
        }
    }

    int getint() {
        return Integer.parseInt(getstr());
    }

    long getlong() {
        return Long.parseLong(getstr());
    }

    double getdouble() {
        return Double.parseDouble(getstr());
    }

    public static void main(String[] args) {
        new BaiB().run();
    }
}