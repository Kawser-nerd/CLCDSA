import java.util.Arrays;

public class Main {

  private static void solve() {
    int n = ni();
    long[] s = nal(n);
    int[] par = new int[n];
    par[0] = -1;
    for (int i = 1; i < n; i++) {
      int u = ni() - 1;
      int v = ni() - 1;
      par[v] = u;
    }
    int[][] g = parentToG(par);

    int m = ni();
    long[] t = nal(m);
    
    int[] cnt = new int[n];
    dfs(0, -1, g, cnt);
    long[] min = dfs(0, -1, g, s, cnt);
    
    Arrays.sort(t);
    for (int i = 0, j = m - 1; i < j; i ++, j --) {
      long tmp = t[i];
      t[i] = t[j];
      t[j] = tmp;
    }
    for (int i = 1; i < m; i ++) {
      t[i] += t[i - 1];
    }

    long sum = Arrays.stream(s).sum();
    long ret = sum;
    for (int i = 0; i < Math.min(n, m); i ++) {
      ret = Math.max(ret, sum - min[i] + t[i]);
    }
    System.out.println(ret);
  }

  private static void dfs(int now, int pre, int[][] g, int[] cnt) {
    cnt[now] ++;
    for (int next : g[now]) {
      if (next == pre) continue;
      dfs(next, now, g, cnt);
      cnt[now] += cnt[next];
    }
  }

  private static long[] dfs(int now, int pre, int[][] g, long[] s, int[] cnt) {
    long[][] dp = new long[2][cnt[now]];
    Arrays.fill(dp[0], Long.MAX_VALUE / 3);
    dp[0][0] = s[now];
    
    int k = 0;
    for (int next : g[now]) {
      if (next == pre) continue;
      long[] d = dfs(next, now, g, s, cnt);
      int from = k % 2;
      int to = from ^ 1;

      dp[to][0] = dp[from][0];
      for (int i = 1; i < cnt[now]; i ++) {
        dp[to][i] = dp[from][i];
        
        int max = Math.min(i, d.length);
        for (int j = max - 1; j >= 0; j --) {
          if (dp[from][i - j - 1] >= Long.MAX_VALUE / 3) continue;
          dp[to][i] = Math.min(dp[to][i], dp[from][i - j - 1] + d[j]);
        }
      }
      k ++;
    }
    return dp[k % 2];
  }

  public static int[][] parentToG(int[] par) {
    int n = par.length;
    int[] ct = new int[n];
    for (int i = 0; i < n; i++) {
      if (par[i] >= 0) {
        ct[par[i]]++;
      }
    }
    int[][] g = new int[n][];
    for (int i = 0; i < n; i++) {
      g[i] = new int[ct[i]];
    }
    for (int i = 0; i < n; i++) {
      if (par[i] >= 0) {
        g[par[i]][--ct[par[i]]] = i;
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