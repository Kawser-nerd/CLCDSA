import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Main {
  private static void solve() {
    int h = ni();
    int w = ni();
    char[][] map = new char[h][w];
    for (int i = 0; i < h; i++) {
      map[i] = ns();
    }

    for (int k = 0; k < 2; k ++) {
      if (h % 2 == 1) {
        boolean flg = false;
        for (int c = 0; c < h; c ++) {
          swap(map, c, h / 2);
          if (dfs(0, map, k == 1)) {
            flg = true;
            break;
          }
          swap(map, c, h / 2);
        }
        if (!flg) {
          System.out.println("NO");
          return;
        }
      } else {
        if (!dfs(0, map, k == 1)) {
          System.out.println("NO");
          return;
        }
      }

      map = tr(map);
      int tmp = h;
      h = w;
      w = tmp;
    }

    if (!checkOdd(map)) {
      System.out.println("NO");
      return;
    }

    System.out.println("YES");
  }

  private static boolean checkOdd(char[][] map) {
    int h = map.length;
    int w = map[0].length;

    if (h % 2 == 1) {
      for (int j = 0, k = w - 1; j < k; j ++, k --) {
        if (map[h/2][j] != map[h/2][k]) {
          return false;
        }
      }
    }
    if (w % 2 == 1) {
      for (int i = 0, k = h - 1; i < k; i ++, k --) {
        if (map[i][w/2] != map[k][w/2]) {
          return false;
        }
      }
    }
    return true;
  }

  private static char[][] tr(char[][] map) {
    int h = map.length;
    int w = map[0].length;
    char[][] ret = new char[w][h];
    for (int i = 0; i < h; i ++) {
      for (int j = 0; j < w; j ++) {
        ret[j][i] = map[i][j];
      }
    }
    return ret;
  }

  private static boolean dfs(int p, char[][] map, boolean flg) {
    int h = map.length;
    int w = map[0].length;
    if (p == h / 2) {
      return true;
    }

    char[] u = Arrays.copyOf(map[p], w);
    for (int i = p + 1; i < h - p; i++) {
      char[] v = Arrays.copyOf(map[i], w);

      if (equal(u, v, flg)) {
        swap(map, i, h - p - 1);
        if (dfs(p + 1, map, flg)) {
          return true;
        }
        swap(map, i, h - p - 1);
      }
    }
    return false;
  }

  private static void swap(char[][] map, int i, int j) {
    char[] tmp = map[i];
    map[i] = map[j];
    map[j] = tmp;
  }

  private static boolean equal(char[] u, char[] v, boolean flg) {
    int w = u.length;
    if (flg) {
      for (int j = 0, k = w - 1; j <= k; j ++, k --) {
        if (u[j] != v[k]) {
          return false;
        }
      }
      return true;
    } else {
      Map<Integer, Integer> map = new HashMap<>();
      for (int j = 0; j < w; j++) {
        int key = (1 << (u[j] - 'a')) | (1 << (v[j] - 'a'));
        map.putIfAbsent(key, 0);
        map.put(key, map.get(key) + 1);
      }
      int max = w % 2;
      int now = 0;
      for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
        if (entry.getValue() % 2 == 1) {
          now++;
          if (Integer.bitCount(entry.getKey()) > 1) {
            return false;
          }
          if (now > max) {
            return false;
          }
        }
      }
      return true;
    }
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