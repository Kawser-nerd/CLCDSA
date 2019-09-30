import java.util.Arrays;

public class Main {

  private static void solve() {
    int[] a = {ni(), ni()};
    
    
    char black = '#';
    char white = '.';
    if (a[0] < a[1]) {
      black = '.';
      white = '#';
      int tmp = a[0];
      a[0] = a[1];
      a[1] = tmp;
    }
    
    // a >= b
    int h = 100;
    int w = 100;
    
    char[][] map = new char[h][w];
    for (char[] v : map) Arrays.fill(v, white);
    int usedH = -1;
    outer: for (int i = 0; i < h; i ++) {
      for (int j = 0; j < w; j ++) {
        int x = (i + j) % 2;
        int y = x ^ 1;
        map[i][j] = x == 0 ? white : black;

        if (i == 0) {
          if (x == 1)
            a[x] --;
        } else {
          if (x == 1) {
            a[y] --;
            a[x] --;
          }
        }
        if (a[y] <= 1 || a[x] <= 1) {
          usedH = i;
          break outer;
        }
      }
    }
    
    if (a[0] < a[1]) {
      black = '.';
      white = '#';
      int tmp = a[0];
      a[0] = a[1];
      a[1] = tmp;
    } else {
      a[0] --;
    }
    // a >= b
    for (int i = usedH + 2; i < h; i ++) Arrays.fill(map[i], black);
    
    outer: for (int i = usedH + 3; i < h; i += 2) {
      for (int j = 0; j < w; j += 2) {
        if (a[0] == 0) break outer;
        map[i][j] = white;
        a[0] --;
      }
    }
    System.out.println("100 100");
    for (int i = 0; i < h; i ++) {
      out.println(map[i]);
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