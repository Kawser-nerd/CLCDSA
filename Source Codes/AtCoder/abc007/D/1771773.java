import java.util.Arrays;

public class Main {

  static int[] a = new int[20];
  static int[] b = new int[20];
  private static void solve() {
    long A = nl();
    long B = nl();
    long total = B - A + 1;
    for (int i = 0; i < 20; i ++) {
      a[i] = (int)(A % 10);
      b[i] = (int)(B % 10);
      A /= 10;
      B /= 10;
    }
    
    for (long[][] v : memo) for (long[] u : v) {
      Arrays.fill(u, -1);
    }
    System.out.println(total - dfs(19, 1, 1));
  }
  
  
  static long[][][] memo = new long[20][2][2];
  private static long dfs(int i, int minFlg, int maxFlg) {
    if (i < 0) return 1;
    if (memo[i][minFlg][maxFlg] >= 0) return memo[i][minFlg][maxFlg];

    long ret = 0;
    for (int d = 0; d < 10; d ++) {
      if (d == 4 || d == 9) continue;
      if ((minFlg == 0 || a[i] <= d) && (maxFlg == 0 || d <= b[i])) {
        ret += dfs(i - 1, minFlg == 1 && a[i] == d ? 1 : 0, maxFlg == 1 && b[i] == d ? 1 : 0);
      }
    }
    memo[i][minFlg][maxFlg] = ret;
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