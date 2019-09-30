public class Main {
  private static void solve() {
    int n = ni();
    int m = ni();

    int[] from = new int[m];
    int[] to = new int[m];

    for (int i = 0; i < m; i++) {
      from[i] = ni() - 1;
      to[i] = ni() - 1;
    }

    int[][] g = packU(n, from, to);

    // {2,4,6}
    for (int i = 0; i < n; i++) {
      if (g[i].length % 2 == 1) {
        System.out.println("No");
        return;
      }
    }

    int ptr = 0;
    int[] four = new int[n];
    for (int i = 0; i < n; i++) {
      if (g[i].length >= 6) {
        System.out.println("Yes");
        return;
      }
      if (g[i].length == 4) {
        four[ptr++] = i;
      }
    }

    if (ptr >= 3) {
      System.out.println("Yes");
      return;
    } else if (ptr <= 1) {
      System.out.println("No");
      return;
    }

    for (int v : g[four[0]]) {
      if (dfs(v, four[0], four[0], four[1], g)) {
        System.out.println("Yes");
        return;
      }
    }
    System.out.println("No");

  }


  private static boolean dfs(int now, int pre, int s, int t, int[][] g) {

    if (now == s)
      return true;
    else if (now == t)
      return false;
    
    for (int v : g[now]) {
      if (v == pre)
        continue;
      return dfs(v, now, s, t, g);
    }
    return false;
  }

  static int[][] packU(int n, int[] from, int[] to) {
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