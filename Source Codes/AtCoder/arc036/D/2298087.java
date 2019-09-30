class UnionFind {
  private int[] table;
  private int[] rank;
  
  public UnionFind(int size) {
      this.table = new int[size];
      this.rank = new int[size];
      for (int i = 0; i < size; i ++) {
          this.table[i] = i;
          this.rank[i] = 1;
      }
  }

  public boolean isSame(int node1, int node2) {
      return find(node1) == find(node2);
  }

  public int find(int node) {
      if (table[node] == node) {
          return node;
      } else {
          return table[node] = find(table[node]);
      }
  }

  public void union(int node1, int node2) {
      int root1 = find(node1);
      int root2 = find(node2);
      
      if (rank[root1] < rank[root2]) {
          table[root1] = root2;
      } else if (rank[root1] > rank[root2]) {
          table[root2] = root1;
      } else if (root1 != root2) {
          table[root2] = root1;
          rank[root1] ++;
      }
  }
}

public class Main {

  private static void solve() {
    int n = ni();
    int q = ni();
    
    UnionFind uf = new UnionFind(n * 2);
    
    for (int i = 0; i < q; i ++) {
      int w = ni();
      int x = ni() - 1;
      int y = ni() - 1;
      int z = ni();

      if (w == 1) {
        if (z % 2 == 0) {
          uf.union(x, y);
          uf.union(x + n, y + n);
        } else {
          uf.union(x + n, y);
          uf.union(x, y + n);
        }
      } else {
        System.out.println(uf.isSame(x, y) ? "YES" : "NO");
      }
    }
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