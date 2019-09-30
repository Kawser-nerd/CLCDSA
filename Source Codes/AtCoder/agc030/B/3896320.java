public class Main {


  private static void solve() {
    long l = nl();
    int n = ni();
    long[] x = new long[n + 2];
    for (int i = 0; i < n; i ++) {
      x[i + 1] = nl();
    }
    x[n + 1] = l;
    
    long[] y = new long[n + 2];
    for (int i = 0; i <= n; i ++) {
      y[i + 1] = l - x[n - i];
    }
    
    long[] xs = new long[n + 2];
    long[] ys = new long[n + 2];
    for (int i = 1; i <= n; i ++) {
      xs[i] = x[i] + xs[i - 1];
      ys[i] = y[i] + ys[i - 1];
    }

    long ret = 0;
    for (int k = 0; k < 2; k ++) {
      for (int i = 0; i <= n; i ++) {
        long now;
        if (k == 0) {
          now = x[i];
          int len = (n - i) / 2;
          int mod = (n - i) % 2;
          now += ys[len] * 2;
          now += (xs[i + len] - xs[i]) * 2;
          if (mod == 1) {
            now += y[len + 1] + x[i];
          } else {
            now -= x[i + len] - x[i];
          }
        } else {
          now = y[i];
          int len = (n - i) / 2;
          int mod = (n - i) % 2;
          now += xs[len] * 2;
          now += (ys[i + len] - ys[i]) * 2;
          if (mod == 1) {
            now += x[len + 1] + y[i];
          } else {
            now -= y[i + len] - y[i];
          }
        }
        ret = Math.max(ret, now);
      }
    }
    System.out.println(ret);
  }

  public static void main(String[] args) {
    new Thread(null, new Runnable() {
      @Override
      public void run() {
        long start = System.currentTimeMillis();
        String debug = args.length > 0 ? args[0] : null;
        if (debug != null) {
          try {
            is = java.nio.file.Files.newInputStream(java.nio.file.Paths.get(debug));
          } catch (Exception e) {
            throw new RuntimeException(e);
          }
        }
        reader = new java.io.BufferedReader(new java.io.InputStreamReader(is), 32768);
        solve();
        out.flush();
        tr((System.currentTimeMillis() - start) + "ms");
      }
    }, "", 64000000).start();
  }

  private static java.io.InputStream is = System.in;
  private static java.io.PrintWriter out = new java.io.PrintWriter(System.out);
  private static java.util.StringTokenizer tokenizer = null;
  private static java.io.BufferedReader reader;

  public static String next() {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new java.util.StringTokenizer(reader.readLine());
      } catch (Exception e) {
        throw new RuntimeException(e);
      }
    }
    return tokenizer.nextToken();
  }

  private static double nd() {
    return Double.parseDouble(next());
  }

  private static long nl() {
    return Long.parseLong(next());
  }

  private static int[] na(int n) {
    int[] a = new int[n];
    for (int i = 0; i < n; i++)
      a[i] = ni();
    return a;
  }

  private static char[] ns() {
    return next().toCharArray();
  }

  private static long[] nal(int n) {
    long[] a = new long[n];
    for (int i = 0; i < n; i++)
      a[i] = nl();
    return a;
  }

  private static int[][] ntable(int n, int m) {
    int[][] table = new int[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        table[i][j] = ni();
      }
    }
    return table;
  }

  private static int[][] nlist(int n, int m) {
    int[][] table = new int[m][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        table[j][i] = ni();
      }
    }
    return table;
  }

  private static int ni() {
    return Integer.parseInt(next());
  }

  private static void tr(Object... o) {
    if (is != System.in)
      System.out.println(java.util.Arrays.deepToString(o));
  }
}