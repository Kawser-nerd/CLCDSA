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

  private static long enc(int v, int bcnt) {
    long ret = 0;
    ret += bcnt;
    ret *= 10000;
    ret += v;
    return ret;
  }

  private static int[] dec(long h) {
    int v = (int) (h % 10000);
    h /= 10000;
    int bcnt = (int) (h % 10000);
    return new int[] {v, bcnt};
  }

  public static int[] dijk(int[][][] g, int[] b) {
    int n = g.length;
    int bcntMax = (int) Math.sqrt(2 * n) + 1;

    int[][] td = new int[n][bcntMax];
    for (int[] v : td) Arrays.fill(v, Integer.MAX_VALUE);
    TreeSet<Long> q = new TreeSet<>((o1, o2) -> {
      int[] h1 = dec(o1);
      int[] h2 = dec(o2);
      int d = td[h1[0]][h1[1] - b[h1[0]]] - td[h2[0]][h2[1] - b[h2[0]]];
      if (d == 0)
        return h1[1] == h2[1] ? h1[0] - h2[0] : h1[1] - h2[1];

      return d;
    });
    int[] ret = new int[n];
    Arrays.fill(ret, Integer.MAX_VALUE);

    q.add(enc(0, 0));
    td[0][0] = 0;

    while (q.size() > 0) {
      long h = q.pollFirst();
      int[] cur = dec(h);
      int v = cur[0];
      int bcnt = cur[1];
      ret[v] = Math.min(ret[v], td[v][bcnt - b[v]]);


      for (int i = 0; i < g[cur[0]].length; i++) {
        int type = g[v][i][1];

        int len = type == 0 ? 1 : (bcnt + 1);
        int ncnt = type == 0 ? bcnt : (bcnt + 1);
        int nd = td[v][bcnt - b[v]] + len;
        int u = g[v][i][0];

        if (ncnt - b[u] >= bcntMax)
          continue;
        long nh = enc(u, ncnt);

        if (td[u][ncnt - b[u]] > nd) {
          q.remove(nh);
          td[u][ncnt - b[u]] = nd;
          q.add(nh);
        }
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