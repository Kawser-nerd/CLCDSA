import java.util.Arrays;

public class Main {

  private final static int INF = 1000000000;
  private static void solve() {
    int n = ni();
    int[] from = new int[n - 1];
    int[] to = new int[n - 1];
    for (int i = 0; i < n - 1; i++) {
      from[i] = ni() - 1;
      to[i] = ni() - 1;
    }
    int[][] g = packU(n, from, to);
    int[][] range = new int[n][2];
    for (int i = 0; i < n; i ++) {
      range[i] = new int[] {-INF, INF};
    }
    
    int k = ni();
    for (int i = 0; i < k; i ++) {
      int v = ni() - 1;
      int p = ni();
      range[v] = new int[] {p, p};
    }
    int[] eo = new int[n];
    Arrays.fill(eo, -1);
    for (int i = 0; i < 2; i ++) {
      if (!dfs(0, -1, g, range, 0, eo) ) {
        System.out.println("No");
        return;
      }
    }
    if (rev == 1) {
      for (int i = 0; i < n; i ++) {
        eo[i] = (eo[i] + 1) % 2;
      }
    }
    out.println("Yes");
    for (int i = 0; i < n; i ++) {
      int offset = 0;
      if (eo[i] != Math.abs(range[i][0]) % 2) {
        offset ++;
      }
      out.println(range[i][0] + offset);
    }
  }
  
  static int rev = -1;
  private static boolean dfs(int now, int pre, int[][] g, int[][] range, int depth, int[] eo) {
    eo[now] = depth % 2;
    range[now][0] = Math.max(pre < 0 ? -INF: (range[pre][0] - 1), range[now][0]);
    range[now][1] = Math.min(pre < 0 ? INF : (range[pre][1] + 1), range[now][1]);
    if (range[now][0] > range[now][1]) return false;

    for (int next : g[now]) {
      if (next == pre) continue;
      if (!dfs(next, now, g, range, depth + 1, eo)) return false;
      
      range[now][0] = Math.max(range[next][0] - 1, range[now][0]);
      range[now][1] = Math.min(range[next][1] + 1, range[now][1]);
      
      if (range[now][0] > range[now][1]) return false;
    }
    if (range[now][0] == range[now][1]) {
      if (range[now][0] % 2 != eo[now]) {
        if (rev < 0 || rev == 1) {
          rev = 1;
        } else {
          return false;
        }
      } else {
        if (rev < 0 || rev == 0) {
          rev = 0;
        } else {
          return false;
        }
      }
    }
    return true;
  }

  private static int[][] packU(int n, int[] from, int[] to) {
    int[][] g = new int[n][];
    int[] p = new int[n];
    for (int f : from)
      p[f]++;
    for (int t : to)
      p[t]++;
    for (int i = 0; i < n; i++)
      g[i] = new int[p[i]];
    for (int i = 0; i < from.length; i++) {
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