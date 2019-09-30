import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Random;
import java.util.Set;

public class Main {


  private static void solve() {
    int n = ni();
    int m = ni();

    int[] from = new int[n - 1];
    int[] to = new int[n - 1];
    for (int i = 0; i < n - 1; i++) {
      from[i] = ni() - 1;
      to[i] = ni() - 1;
    }
    Map<Integer, Set<Integer>> map = new HashMap<>();
    for (int i = 0; i < n; i++) {
      map.put(i, new HashSet<>());
    }
    int[][] g = packU(n, from, to);

    int[][] paths = new int[m][2];
    for (int i = 1; i <= m; i++) {
      int u = ni() - 1;
      int v = ni() - 1;
      paths[i - 1] = new int[] {u + 1, v + 1};
      map.get(u).add(-i);
      map.get(v).add(i);
    }
    dfs(0, -1, g, map);
    int score = 0;
    int[] dir = new int[m];

    for (Set<Integer> set : map.values()) {
      if (set.size() >= 2) {
        score += 2;
      } else if (set.size() == 1) {
        score += 1;
      }
    }

    Random gen = new Random();
    outer: while (true) {
      for (Set<Integer> set : map.values()) {
        if (set.size() >= 2) {
          int[] idx = new int[set.size()];
          int[] cnt = new int[2];
          int[] flg = new int[set.size()];
          int ptr = 0;
          for (int e : set) {
            if (e < 0) {
              int i = -e - 1;
              cnt[dir[i] ^ 1]++;
              flg[ptr] = -1;
              idx[ptr++] = i;
            } else {
              int i = e - 1;
              cnt[dir[i]]++;
              flg[ptr] = 1;
              idx[ptr++] = i;
            }
          }
          if (cnt[0] == 0 || cnt[1] == 0) {
            int target = gen.nextInt(ptr);
            dir[idx[target]] ^= 1;
            continue outer;
          }
        }
      }
      break;
    }


    System.out.println(score);
    for (int i = 0; i < m; i++) {
      if (dir[i] > 0) {
        System.out.println(paths[i][0] + " " + paths[i][1]);
      } else {
        System.out.println(paths[i][1] + " " + paths[i][0]);
      }
    }
  }

  private static void dfs(int now, int[] dir, int[][] d, int nd) {
    int m = d.length;
    dir[now] = nd;
    for (int i = 0; i < m; i++) {
      if (dir[i] != 0)
        continue;
      if (d[now][i] != 0) {
        dfs(i, dir, d, -nd * d[now][i]);
      }
    }
  }

  private static void dfs(int now, int pre, int[][] g, Map<Integer, Set<Integer>> map) {
    for (int next : g[now]) {
      if (next == pre)
        continue;

      dfs(next, now, g, map);

      for (int v : map.get(next)) {
        if (map.get(now).contains(-v)) {
          map.get(now).remove(-v);
        } else {
          map.get(now).add(v);
        }
      }
    }
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