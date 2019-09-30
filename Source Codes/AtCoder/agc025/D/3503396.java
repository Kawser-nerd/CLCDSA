public class Main {
  private static void solve() {
    int n = ni();
    int d1 = ni();
    int d2 = ni();
    
    boolean[][] map1 = f(n, d1);
    boolean[][] map2 = f(n, d2);
    int cnt = 0;
    outer: for (int i = 0; i < n * 2; i ++) {
      for (int j = 0; j < n * 2; j ++) {
        if (map1[i][j] && map2[i][j]) {
          out.println(i + " " + j);
          if (++ cnt == n * n) break outer;
        }
      }
    }
  }
  
  private static boolean[][] f(int n, int d) {
    int two = 0;
    while (d % 2 == 0) {
      two ++;
      d /= 2;
    }

    int cell = 1;
    for (int i = 0; i < two / 2; i ++) {
      cell *= 2;
    }

    boolean[][] ret = new boolean[n * 2][n * 2];
    for (int i = 0; i < n * 2; i ++) {
      for (int j = 0; j < n * 2; j ++) {
        if (two % 2 == 0 && (i / cell + j / cell) % 2 == 0) {
          ret[i][j] = true;
        } else if (two % 2 == 1 && i / cell % 2 == 0) {
          ret[i][j] = true;
        }
      }
    }
    //dump(ret);
    return ret;
  }

  private static void dump(boolean[][] map) {
    int n = map.length;
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < n; j ++) {
        out.print(map[i][j] ? 'o' : '.');
      }
      out.println();
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