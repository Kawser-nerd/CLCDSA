import java.util.Arrays;

public class Main {
  static class DisjointSet {
    public int[] upper; 

    public DisjointSet(int n) {
      upper = new int[n];
      Arrays.fill(upper, -1);
      // w = new int[n];
    }

    public DisjointSet(DisjointSet ds) {
      this.upper = Arrays.copyOf(ds.upper, ds.upper.length);
    }

    public int root(int x) {
      return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
    }

    public boolean equiv(int x, int y) {
      return root(x) == root(y);
    }

    public boolean union(int x, int y) {
      x = root(x);
      y = root(y);
      if (x != y) {
        if (upper[y] < upper[x]) {
          int d = x;
          x = y;
          y = d;
        }
        // w[x] += w[y];
        upper[x] += upper[y];
        upper[y] = x;
      }
      return x == y;
    }

    public int count() {
      int ct = 0;
      for (int u : upper) {
        if (u < 0)
          ct++;
      }
      return ct;
    }

    public int[][] toBucket() {
      int n = upper.length;
      int[][] ret = new int[n][];
      int[] rp = new int[n];
      for (int i = 0; i < n; i++) {
        if (upper[i] < 0)
          ret[i] = new int[-upper[i]];
      }
      for (int i = 0; i < n; i++) {
        int r = root(i);
        ret[r][rp[r]++] = i;
      }
      return ret;
    }
  }


  private static void solve() {
    int n = ni();
    int m = ni();

    int[] from = new int[m];
    int[] to = new int[m];
    DisjointSet dj = new DisjointSet(n);
    for (int i = 0; i < m; i++) {
      from[i] = ni() - 1;
      to[i] = ni() - 1;
      dj.union(from[i], to[i]);
    }
    int[][] buk = dj.toBucket();
    
    int[][] g = packU(n, from, to);
    long ret = 0;
    int[] color = new int[n];
    long[] cnt = new long[3];
    for (int[] v: buk) {
      if (v == null || v.length == 0) {
        continue;
      }
      if (v.length == 1) {
        cnt[0] ++;
      } else {
        if (dfs(v[0], g, 1, color)) {
          cnt[2] ++;
        } else {
          cnt[1] ++;
        }
      }
    }
    ret += cnt[0] * (n - cnt[0]) * 2 + cnt[0] * cnt[0];
    ret += cnt[2] * cnt[2] * 2 + cnt[2] * cnt[1] * 2 + cnt[1] * cnt[1];
    System.out.println(ret);
  }
  
  private static boolean dfs(int n, int[][] g, int c, int[] color) {
    color[n] = c;
    
    for (int next : g[n]) {
      if (color[next] != 0) {
        if (color[next] != -c) {
          return false;
        }
        continue;
      }
      if (!dfs(next, g, -c, color)) {
        return false;
      }
    }
    return true;
  }

  public static int[][] packU(int n, int[] from, int[] to){ return packU(n, from, to, from.length); }
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