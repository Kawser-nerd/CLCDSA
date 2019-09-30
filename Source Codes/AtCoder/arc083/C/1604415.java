import java.util.Arrays;

public class Main {
  private static void solve() {
    int n = ni();
    
    
    int[] p = na(n - 1);
    int[] x = na(n);
    int[] par = new int[n];
    par[0] = -1;
    for (int i = 0; i < n - 1; i ++) {
      par[i + 1] = p[i] - 1;
    }
    int[][] g = parentToG(par);
    
    int[] ret = dfs(0, -1, g, x);
    System.out.println(ret[0] >= 0 ? "POSSIBLE" : "IMPOSSIBLE");
  }
  
  private static int[] dfs(int now, int pre, int[][] g, int[] x) {
    int m = g[now].length + (now == 0 ? 0 : -1);
    if (m == 0) {
      return new int[] {0, x[now]};
    }

    int[] w = new int[m];
    int total = 0;
    int ptr = 0;

    int min = 0;
    for (int next : g[now]) {
      if (next != pre) {
        int[] y = dfs(next, now, g, x);
        if (y[0] < 0) {
          return y;
        }
        min += y[0];
        w[ptr ++] = y[1] - y[0];
        total += y[1];
      }
    }
    
    int v = x[now] - min;
    if (v < 0) {
      return new int[] {-1, -1};
    }

    boolean[][] dp = new boolean[2][v + 1];
    dp[0][0] = true;
    for (int i = 0; i < m; i ++) {
      int from = i % 2;
      int to = (i + 1) % 2;
      Arrays.fill(dp[to], false);
      for (int j = 0; j <= v; j ++) {
        dp[to][j] |= dp[from][j];
        if (j + w[i] <= v)
          dp[to][j + w[i]] |= dp[from][j];
      }
    }
    int np = m % 2;
    
    for (int i = v; i >= 0; i --) {
      if (dp[np][i]) {
        return new int[] { Math.min(x[now], total - i), Math.max(x[now],  total - i)};
      }
    }
    throw new RuntimeException();
  }
  
  public static int[][] parentToG(int[] par)
  {
      int n = par.length;
      int[] ct = new int[n];
      for(int i = 0;i < n;i++){
          if(par[i] >= 0){
              ct[i]++;
              ct[par[i]]++;
          }
      }
      int[][] g = new int[n][];
      for(int i = 0;i < n;i++){
          g[i] = new int[ct[i]];
      }
      for(int i = 0;i < n;i++){
          if(par[i] >= 0){
              g[par[i]][--ct[par[i]]] = i;
              g[i][--ct[i]] = par[i];
          }
      }
      return g;
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