import java.util.Arrays;

public class Main {
  private static void solve() {
    int a = ni();
    int b = ni();
    int[][] d = ntable(a, b);

    int m = 100;

    int[][] c = new int[m + 1][m + 1];
    for (int[] v : c)
      Arrays.fill(v, Integer.MIN_VALUE);

    
    // d[x][y] <= i*x + j*y + c[i][j]
    for (int x = 1; x <= a; x++) {
      for (int y = 1; y <= b; y++) {
        for (int i = 0; i <= m; i++) {
          for (int j = 0; j <= m; j++) {
            c[i][j] = Math.max(c[i][j], d[x - 1][y - 1] - i * x - j * y);
          }
        }
      }
    }

    for (int x = 1; x <= a; x++) {
      for (int y = 1; y <= b; y++) {
        int test = Integer.MAX_VALUE;
        for (int i = 0; i <= m; i++) {
          for (int j = 0; j <= m; j++) {
            if (c[i][j] >= 0) {
              test = Math.min(test, i * x + j * y + c[i][j]);
            }
          }
        }
        if (test != d[x - 1][y - 1]) {
          System.out.println("Impossible");
          return;
        }
      }
    }
    int edges = m * 2;
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= m; j++) {
        if (c[i][j] >= 0) {
          edges ++;
        }
      }
    }

    System.out.println("Possible");
    System.out.println((m + 1) * 2 + " " + edges);
    for (int i = 1; i < m + 1; i++) {
      System.out.println(i + " " + (i + 1) + " X");
    }
    for (int i = m + 2; i < (m + 1) * 2; i++) {
      System.out.println(i + " " + (i + 1) + " Y");
    }
    for (int i = 0; i <= m; i ++) {
      for (int j = 0; j <= m; j ++) {
        if (c[i][j] >= 0)
          System.out.println((i + 1) + " " + ((m + 1) * 2 - j) + " " + c[i][j]);
      }
    }
    System.out.println("1 " + (m + 1) * 2);
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