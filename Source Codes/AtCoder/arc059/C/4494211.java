import java.util.Arrays;

public class Main {
  private static void solve() {
    int n = ni();
    int c = ni();
    int[] a = na(n);
    int[] b = na(n);

    int maxAB = Math.max(Arrays.stream(a).max().getAsInt(), Arrays.stream(b).max().getAsInt());

    int mod = 1000000000 + 7;

    // p[i][j] = i^j
    long[][] p = new long[maxAB + 1][c + 1];
    for (int i = 0; i <= maxAB; i++) {
      for (int j = 0; j <= c; j++) {
        p[i][j] = 1;
        for (int k = 0; k < j; k++) {
          p[i][j] *= i;
          p[i][j] %= mod;
        }
      }
    }

    // x[i][j] = a[i]^j + (a[i]+1)^j + .. +b[i]^j
    long[][] x = new long[n + 1][c + 1];
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= c; j++) {
        for (int k = a[i - 1]; k <= b[i - 1]; k++) {
          x[i][j] += p[k][j];
          x[i][j] %= mod;
        }
      }
    }

    long[][] dp = new long[n + 1][c + 1];
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= c; j++) {
        for (int k = 0; j + k <= c; k++) {
          dp[i][j + k] += dp[i - 1][j] * x[i][k];
          dp[i][j + k] %= mod;
        }
      }
    }

    System.out.println(dp[n][c]);
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