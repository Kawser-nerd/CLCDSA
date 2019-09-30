import java.util.HashSet;
import java.util.Set;

public class Main {


  private static void solve() {
    int n = ni();
    int m = ni();
    Set<Integer> set = new HashSet<>();
    for (int i = 0; i < m; i ++) {
      int a = ni() - 1;
      int b = ni() - 1;
      set.add(a * 1000 + b);
      set.add(b * 1000 + a);
    }
    
    int[] from = new int[n * n];
    int[] to = new int[n * n];
    int ptr = 0;
    for(int i = 0; i < n; i ++) {
      for (int j = i + 1; j < n; j ++) {
        
        if (!set.contains(i * 1000 + j)) {
          from[ptr] = i;
          to[ptr] = j;
          ptr ++;
        }
      }
    }
    int[][] g = packU(n, from, to, ptr);
    int[] color = new int[n];
    boolean[][] dp = new boolean[n + 1][n + 1];
    dp[0][0] = true;
    for (int i = 0; i < n; i ++) {
      int[] v = new int[2];
      if (color[i] == 0) {
        v = dfs(i, g, color, 1);
        if (v[0] < 0) {
          System.out.println(-1);
          return;
        }
      }
      for (int j = 0; j < n; j ++) {
        if (!dp[i][j]) continue;

        if (v[0] + j <= n) {
          dp[i + 1][v[0] + j] = true;
        }
        if (v[1] + j <= n) {
          dp[i + 1][v[1] + j] = true;
        }
      }
    }
    
    int min = Integer.MAX_VALUE;
    for (int i = 0; i <= n; i ++) {
      if (!dp[n][i]) continue;
      int x = Math.max(0, i * (i - 1) / 2);
      int y = Math.max(0, (n - i) * (n - i - 1) / 2);
      min = Math.min(min, x + y);
    }
    System.out.println(min);
  }

  private static int[] dfs(int now, int[][] g, int[] color, int c) {
    color[now] = c;
    int nc = c == 1 ? 2 : 1;
    
    int[] ret = {c == 1 ? 1 : 0, c == 2 ? 1 : 0};
    for (int next : g[now]) {
      if (color[next] > 0) {
        if (color[next] != nc) {
          return new int[]{-1, -1};
        } else {
          continue;
        }
      }
      
      color[next] = nc;
      int[] v = dfs(next, g, color, nc);
      if (v[0] < 0) {
        return new int[] {-1, -1};
      }
      ret[0] += v[0];
      ret[1] += v[1];
    }
    return ret;
  }

  public static int[][] packU(int n, int[] from, int[] to, int sup)
  {
      int[][] g = new int[n][];
      int[] p = new int[n];
      for(int i = 0;i < sup;i++)p[from[i]]++;
      for(int i = 0;i < sup;i++)p[to[i]]++;
      for(int i = 0;i < n;i++)g[i] = new int[p[i]];
      for(int i = 0;i < sup;i++){
          g[from[i]][--p[from[i]]] = to[i];
          g[to[i]][--p[to[i]]] = from[i];
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