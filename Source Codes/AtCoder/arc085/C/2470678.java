import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
  private static void solve() {
    int n = ni();
    int[] a = na(n);

    // 0:S n+1:T
    List<Edge> edges = new ArrayList<>();
    for (int i = 1; i <= n; i++) {
      if (a[i - 1] < 0) {
        edges.add(new Edge(0, i, -a[i - 1]));
      } else {
        edges.add(new Edge(i, n + 1, a[i - 1]));
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j += i) {
        edges.add(new Edge(i, j, Integer.MAX_VALUE));
      }
    }
    Edge[][] e = compileWD(n + 2, edges);
    long ret = -maximumFlowDinic(e, 0, n + 1);
    for (int v : a) {
      if (v > 0) {
        ret += v;
      }
    }
    System.out.println(ret);
  }

  public static Edge[][] compileWD(int n, List<Edge> edges) {
    Edge[][] g = new Edge[n][];
    // cloning
    for (int i = edges.size() - 1; i >= 0; i--) {
      Edge origin = edges.get(i);
      Edge clone = new Edge(origin.to, origin.from, origin.capacity);
      clone.flow = origin.capacity;
      clone.complement = origin;
      clone.cloned = true;
      origin.complement = clone;
      edges.add(clone);
    }

    int[] p = new int[n];
    for (Edge e : edges)
      p[e.from]++;
    for (int i = 0; i < n; i++)
      g[i] = new Edge[p[i]];
    for (Edge e : edges)
      g[e.from][--p[e.from]] = e;
    return g;
  }

  static class Edge {
    public int from, to;
    public int capacity;
    public int flow;
    public Edge complement;
    public boolean cloned;

    public Edge(int from, int to, int capacity) {
      this.from = from;
      this.to = to;
      this.capacity = capacity;
    }
  }

  public static long maximumFlowDinic(Edge[][] g, int source, int sink) {
    int n = g.length;
    int[] d = new int[n];
    int[] q = new int[n];
    long ret = 0;
    while (true) {
      Arrays.fill(d, -1);
      q[0] = source;
      int r = 1;
      d[source] = 0;

      for (int v = 0; v < r; v++) {
        int cur = q[v];
        for (Edge ne : g[cur]) {
          if (d[ne.to] == -1 && ne.capacity - ne.flow > 0) {
            q[r++] = ne.to;
            d[ne.to] = d[cur] + 1;
          }
        }
      }
      if (d[sink] == -1)
        break;
      int[] sp = new int[n];
      for (int i = 0; i < n; i++)
        sp[i] = g[i].length - 1;
      ret += dfsDinic(d, g, sp, source, sink, Long.MAX_VALUE);
    }

    return ret;
  }

  private static long dfsDinic(int[] d, Edge[][] g, int[] sp, int cur, int sink, long min) {
    if (cur == sink)
      return min;
    long left = min;
    for (int i = sp[cur]; i >= 0; i--) {
      Edge ne = g[cur][i];
      if (d[ne.to] == d[cur] + 1 && ne.capacity - ne.flow > 0) {
        long fl = dfsDinic(d, g, sp, ne.to, sink, Math.min(left, ne.capacity - ne.flow));
        if (fl > 0) {
          left -= fl;
          ne.flow += fl;
          ne.complement.flow -= fl;
          if (left == 0) {
            sp[cur] = i;
            return min;
          }
        }
      }
    }
    sp[cur] = -1;
    return min - left;
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