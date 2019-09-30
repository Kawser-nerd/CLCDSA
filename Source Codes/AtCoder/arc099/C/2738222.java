import java.util.HashSet;
import java.util.Set;

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
    int m = ni();
    Set<Integer> con = new HashSet<>();
    for (int i = 0; i < m; i++) {
      int u = ni() - 1;
      int v = ni() - 1;
      if (u > v) {
        int tmp = u;
        u = v;
        v = tmp;
      }
      con.add(u * 1000 + v);
    }
    UnionFind uf = new UnionFind(n);
    int[] from = new int[n * (n-1)/2];
    int[] to = new int[n * (n-1)/2];
    int ptr = 0;
    for (int i = 0; i < n; i ++) {
      for (int j = i + 1; j < n; j ++) {
        if (!con.contains(i * 1000 + j)) {
          from[ptr] = i;
          to[ptr] = j;
          uf.union(from[ptr], to[ptr]);
          ptr ++;
        }
      }
    }
    Set<Integer> roots = new HashSet<>();
    for (int i = 0; i < n; i ++) {
      roots.add(uf.find(i));
    }

    int[][] g = packU(n, from, to, ptr);
    int k = roots.size();
    int[] a = new int[k];
    int total = 0;
    ptr = 0;
    for (int root : roots) {
      int[] color = new int[n];
      if (!dfs(root, g, 1, color)) {
        System.out.println(-1);
        return;
      }
      
      int[] cnt = count(color);
      total += cnt[0];
      a[ptr ++] = cnt[1];
    }
    
    boolean[][] dp = new boolean[2][n + 1];
    dp[0][total] = true;
    for (int i = 0; i < k; i ++) {
      int p = i % 2;
      int q = p ^ 1;
      for (int j = 0; j <= n - a[i]; j ++) {
        dp[q][j + a[i]] |= dp[p][j];
      }
      for (int j = 0; j <= n; j ++) {
        dp[p][j] = dp[q][j];
      }
    }
    
    int min = Integer.MAX_VALUE;
    for (int i = 0; i <= n; i ++) {
      if (dp[k % 2][i]) {
        int n1 = i;
        int n2 = n - i;
        min = Math.min(min, n1 * (n1 - 1) / 2 + n2 * (n2 - 1) / 2);
      }
    }
    System.out.println(min);
  }

  private static int[] count(int[] color) {
    int[] cnt = new int[3];
    for (int v : color) {
      cnt[v] ++;
    }
    return new int[] {Math.min(cnt[1], cnt[2]), Math.abs(cnt[1] - cnt[2])};
  }
  private static boolean dfs(int now, int[][] g, int nowColor, int[] color) {
    color[now] = nowColor;
    int nextColor = nowColor == 1 ? 2 : 1;
    for (int next : g[now]) {
      if (color[next] > 0) {
        if (color[next] == nowColor) {
          return false;
        } else {
          continue;
        }
      }
      if (!dfs(next, g, nextColor, color)) {
        return false;
      }
    }
    return true;
  }

  public static int[][] packU(int n, int[] from, int[] to) {
    return packU(n, from, to, from.length);
  }

  public static int[][] packU(int n, int[] from, int[] to, int sup) {
    int[][] g = new int[n][];
    int[] p = new int[n];
    for (int i = 0; i < sup; i++)
      p[from[i]]++;
    for (int i = 0; i < sup; i++)
      p[to[i]]++;
    for (int i = 0; i < n; i++)
      g[i] = new int[p[i]];
    for (int i = 0; i < sup; i++) {
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