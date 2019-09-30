public class Main {
  private static void solve() {
    int n = ni();
    int k = ni();
    
    int[] par = new int[n];
    for (int i = 0; i < n; i ++) {
      par[i] = ni() - 1;
    }
    int rootTo = par[0];
    par[0] = -1;
    int[][] g = parentToG(par);

    int[] ret = dfs(0, -1, g, k);
    
    int result = ret[1] + (rootTo != 0 ? 1 : 0);
    System.out.println(result);
    
  }

  private static int[] dfs(int now, int pre, int[][] g, int k) {
    int[] ret = {0, 0};
    for (int next : g[now]) {
      if (next == pre) continue;
      
      int[] v = dfs(next, now, g, k);
      ret[0] = Math.max(ret[0], v[0] + 1);
      ret[1] += v[1];
    }
    if (ret[0] == k - 1) {
      if (pre > 0) {
        ret[0] = -1;
        ret[1] ++;
      }
    }
    return ret;
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