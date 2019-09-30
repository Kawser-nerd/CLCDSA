import java.util.Arrays;

public class Main {

  private static void solve() {
    int n = ni();
    int m = ni();
    long[][] d = new long[n][n];
    long INF = Integer.MAX_VALUE;
    for (long[] v : d)
      Arrays.fill(v, INF);
    for (int i = 0; i < n; i++) {
      d[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int a = ni() - 1;
      int b = ni() - 1;
      d[a][b] = d[b][a] = ni();
    }

    wf(d);
    int k = ni();
    for (int i = 0; i < k; i++) {
      int x = ni() - 1;
      int y = ni() - 1;
      int w = ni();
      pwf(d, x, y, w);
      System.out.println(sum(d));
    }
  }

  public static void pwf(long[][] d, int x, int y, int w) {
    int n = d.length;
    if (d[x][y] > w)
      d[x][y] = d[y][x] = w;
    int[] l = {x, y};
    for (int k : l) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (d[i][j] > d[i][k] + d[k][j]) {
            d[i][j] = d[i][k] + d[k][j];
          }
        }
      }
    }
  }
  
  public static long sum(long[][] d) {
    int n = d.length;
    long s = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        s += d[i][j];
      }
    }
    return s;
  }

  public static long[][] wf(long[][] d) {
    int n = d.length;
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (d[i][j] > d[i][k] + d[k][j]) {
            d[i][j] = d[i][k] + d[k][j];
          }
        }
      }
    }
    return d;
  }

  public static void main(String[] args) {
    new Thread(null, new Runnable() {
      @Override
      public void run() {
        long start = System.currentTimeMillis();
        String debug = System.getProperty("debug");
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
      a[i] = ni();
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