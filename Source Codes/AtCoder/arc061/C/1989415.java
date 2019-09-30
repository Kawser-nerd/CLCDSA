import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;


class RestorableDisjointSet2 {
  public int[] upper;
  public long[] hist;
  private final int offset = 1000000000;
  public int hp = 0;
  
  public RestorableDisjointSet2(int n, int m)
  {
      upper = new int[n];
      Arrays.fill(upper, -1);
//        w = new int[n];
      hist = new long[2*m];
  }
  
  public RestorableDisjointSet2(RestorableDisjointSet2 ds)
  {
      this.upper = Arrays.copyOf(ds.upper, ds.upper.length);
      this.hist = Arrays.copyOf(ds.hist, ds.hist.length);
      this.hp = ds.hp;
  }
  
  private void rec(int x)
  {
      hist[hp++] = (long)x<<32|upper[x]+offset;
  }
  
  public int root(int x)
  {
      return upper[x] < 0 ? x : root(upper[x]);
  }
  
  public boolean equiv(int x, int y)
  {
      return root(x) == root(y);
  }
  
  public boolean union(int x, int y)
  {
      x = root(x);
      y = root(y);
      if(x != y) {
          if(upper[y] < upper[x]) {
              int d = x; x = y; y = d;
          }
//            w[x] += w[y];
          rec(x);
          upper[x] += upper[y];
          rec(y);
          upper[y] = x;
      }
      return x == y;
  }
  
  public int time() { return hp; }
  
  public void revert(int to)
  {
      while(hp > to){
          upper[(int)(hist[hp-1]>>>32)] = ((int)hist[hp-1])-offset;
          hp--;
      }
  }
  
  public int count()
  {
      int ct = 0;
      for(int u : upper){
          if(u < 0)ct++;
      }
      return ct;
  }
  
  public int[][] makeUp()
  {
      int n = upper.length;
      int[][] ret = new int[n][];
      int[] rp = new int[n];
      for(int i = 0;i < n;i++){
          if(upper[i] < 0)ret[i] = new int[-upper[i]];
      }
      for(int i = 0;i < n;i++){
          int r = root(i);
          ret[r][rp[r]++] = i;
      }
      return ret;
  }

}


public class Main {

  static List<List<int[]>> g = new ArrayList<>();

  private static void solve() {
    int n = ni();
    int m = ni();

    int[][] es = new int[m][];
    for (int i = 0; i < m; i++) {
      es[i] = new int[] {ni() - 1, ni() - 1, ni()};
    }
    Arrays.sort(es, (o1, o2) -> o1[2] - o2[2]);
    RestorableDisjointSet2 uf = new RestorableDisjointSet2(n, m);

    int[] cen = new int[n];
    Arrays.fill(cen, -1);
    int id = n;
    int[] from = new int[2 * m];
    int[] to = new int[2 * m];
    int[] w = new int[2 * m];
    Arrays.fill(w, 1);
    int ep = 0;
    for (int i = 0; i < m;) {
      int j = i;
      while (j < m && es[j][2] == es[i][2])
        j++;

      for (int k = i; k < j; k++) {
        uf.union(es[k][0], es[k][1]);
      }

      for (int k = i; k < j; k++) {
        for (int u = 0; u < 2; u++) {
          int root = uf.root(es[k][u]);
          if (cen[root] == -1) {
            cen[root] = id;
            id++;
          }
          from[ep] = es[k][u];
          to[ep] = cen[root];
          ep++;
        }
      }
      for (int k = i; k < j; k ++) {
        for (int u = 0; u < 2; u ++) {
          cen[uf.root(es[k][u])] = -1;
        }
      }
      uf.revert(0);
      i = j;
    }

    int[][][] g = packWU(id, from, to, w, ep);
    int[] d = dijk(g, 0);
    if (d[n - 1] == Integer.MAX_VALUE) {
      System.out.println(-1);
    } else {
      System.out.println(d[n - 1] / 2);
    }
  }

  public static int[] dijk(int[][][] g, int from) {
    int n = g.length;
    int[] d = new int[n];
    Arrays.fill(d, Integer.MAX_VALUE);
    Queue<int[]> q = new PriorityQueue<int[]>(100000, new Comparator<int[]>() {
      public int compare(int[] a, int[] b) {
        if (a[1] - b[1] != 0)
          return a[1] - b[1];
        return a[0] - b[0];
      }
    });
    q.add(new int[] {from, 0});

    d[from] = 0;
    while (q.size() > 0) {
      int[] cur = q.poll();
      for (int[] e : g[cur[0]]) {
        int next = e[0];
        int nd = d[cur[0]] + e[1];
        if (nd < d[next]) {
          d[next] = nd;
          q.add(new int[] {next, nd});
        }
      }
    }
    return d;
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