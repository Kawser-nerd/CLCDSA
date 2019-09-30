import java.util.Arrays;

public class Main {

  private static void solve() {
    char[] s = ns();
    int k = ni();
    System.out.println(solve(s, k));

  }

  public static int solve(char[] a, int K) {
    int n = a.length;
    int[][][] dp = new int[n + 1][n + 1][K + 1];
    for (int pos = n - 1; pos >= 0; pos --) {
      Arrays.fill(dp[pos][1], 1);
      for (int len = 2; pos + len <= n; len ++) {
        if (a[pos] == a[pos + len - 1]) {
          for (int k = 0; k <= K; k ++) {
            dp[pos][len][k] = 2 + dp[pos + 1][len - 2][k];
          }
        } else {
          for (int k = 0; k <= K; k ++) {
            dp[pos][len][k] = Math.max(dp[pos + 1][len - 1][k], dp[pos][len - 1][k]);
            if (k > 0) {
              dp[pos][len][k] = Math.max(dp[pos][len][k], dp[pos + 1][len - 2][k - 1] + 2);
            }
          }
        }
      }
    }
    int ret = 0;
    for (int k = 0; k <= K; k ++) {
      ret = Math.max(ret, dp[0][n][k]);
    }
    return ret;
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