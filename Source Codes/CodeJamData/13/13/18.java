import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.System.out;
import static java.lang.Math.*;

public class BaiC implements Runnable {

  int r, n, m, k;
  int[] a;
  int[] v;
  int[] res;

  void duyet(int i) {
    if (res != null) return;
    if (i == n) {
      boolean[] z = new boolean[k];
      for (int b = 0; b < (1<<n); ++b) {
        int p = 1;
        for (int j = 0; j < n; ++j) if ((b&(1<<j))!=0) p*=v[j];
        for (int j = 0; j < k; ++j) if (a[j] == p) z[j] = true;
      }
      boolean ok = true;
      for (int j = 0; j < k; ++j) if (!z[j]) ok = false;
      if (ok) {
        res = v.clone();
      }
      return;
    }
    for (int j = 2; j <= m; ++j) {
      v[i] = j;
      duyet(i+1);
    }
  }

  public void run() {
    int ntest = getint();
    for (int test = 1; test <= ntest; ++test) {
      r = getint();
      n = getint();
      m = getint();
      k = getint();
      out.println("Case #" + test + ":");
      for (int t = 0; t < r; ++t) {
        a = new int[k];
        for (int i = 0; i < k; ++i) a[i] = getint();
        v = new int[n];
        res = null;
        duyet(0);
        for (int i = 0; i < res.length; ++i) out.print(res[i]);
        out.println();
      }
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
        new BaiC().run();
    }
}