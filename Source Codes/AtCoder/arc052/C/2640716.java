import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeSet;
 
public class Main {
  private static void solve() {
    int n = ni();
    int m = ni();
    int[][] e = nlist(m, 3);
    int[][][] g = packWU(n, e[1], e[2], e[0]);
    int[] b = dijk(g);
    System.gc();
    int[] ret = dijk(g, b);
    for (int v : ret) {
      System.out.println(v);
    }
  }
 
  public static int[] dijk(int[][][] g, int[] b) {
    int[] from = {0, 0};
    int n = g.length;
    int bcntMax = (int)Math.sqrt(2 * n) + 1;
    final int[][] td = new int[n][bcntMax];
    for (int[] v : td) Arrays.fill(v, Integer.MAX_VALUE);
    TreeSet<int[]> q = new TreeSet<int[]>((o1, o2) -> {
      if (td[o1[0]][o1[1]] == td[o2[0]][o2[1]])
        return o1[0] == o2[0] ? o1[1] - o2[1] : o1[0] - o2[0];
      
      return td[o1[0]][o1[1]] - td[o2[0]][o2[1]];
    });
 
    q.add(from);
    td[from[0]][from[1]] = 0;
 
    while (q.size() > 0) {
      int[] cur = q.pollFirst();
      int v = cur[0];
      int bcnt = cur[1];
 
      for (int i = 0; i < g[cur[0]].length; i++) {
        int type = g[v][i][1];
 
        int len = type == 0 ? 1 : (b[v] + bcnt + 1);
        int nd = td[v][bcnt] + len;
        int ncnt = type == 0 ? bcnt : (bcnt + 1);
        int u = g[v][i][0];
        int[] next = {u, ncnt + b[v] - b[u]};
        if (next[1] >= bcntMax) continue;
        if (nd < td[next[0]][next[1]]) {
          q.remove(next);
          td[next[0]][next[1]] = nd;
          q.add(next);
        }
      }
    }
    int[] ret = new int[n];
    Arrays.fill(ret, Integer.MAX_VALUE);
    for (int i = 0; i < n; i ++) {
      for (int v : td[i]) {
        ret[i] = Math.min(ret[i], v);
      }
    }
    return ret;
  }
 
  public static int[] dijk(int[][][] g) {
    int from = 0;
    int n = g.length;
    final int[] td = new int[n];
    Arrays.fill(td, Integer.MAX_VALUE);
    TreeSet<Integer> q = new TreeSet<Integer>(new Comparator<Integer>() {
      public int compare(Integer a, Integer b) {
        if (td[a] - td[b] != 0)
          return td[a] - td[b];
        return a - b;
      }
    });
    q.add(from);
    td[from] = 0;
 
    while (q.size() > 0) {
      int cur = q.pollFirst();
 
      for (int i = 0; i < g[cur].length; i++) {
        int next = g[cur][i][0];
        int len = g[cur][i][1];
        int nd = td[cur] + len;
        if (nd < td[next]) {
          q.remove(next);
          td[next] = nd;
          q.add(next);
        }
      }
    }
 
    return td;
  }
 
 
  public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
    return packWU(n, from, to, w, from.length);
  }
 
  public static int[][][] packWU(int n, int[] from, int[] to, int[] w, int sup) {
    int[][][] g = new int[n][][];
    int[] p = new int[n];
    for (int i = 0; i < sup; i++)
      p[from[i]]++;
    for (int i = 0; i < sup; i++)
      p[to[i]]++;
    for (int i = 0; i < n; i++)
      g[i] = new int[p[i]][2];
    for (int i = 0; i < sup; i++) {
      --p[from[i]];
      g[from[i]][p[from[i]]][0] = to[i];
      g[from[i]][p[from[i]]][1] = w[i];
      --p[to[i]];
      g[to[i]][p[to[i]]][0] = from[i];
      g[to[i]][p[to[i]]][1] = w[i];
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