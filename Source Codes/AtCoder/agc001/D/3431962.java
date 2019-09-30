public class Main {
  private static void solve() {
    int n = ni();
    int m = ni();
    int[] a = na(m);
    int[] ax = new int[m];
    int ptr = 1;  
    int op = 0;
    for (int v : a) {
      if (v % 2 == 1) {
        if (op == 2) {
          System.out.println("Impossible");
          return;
        }
        ax[op == 0 ? 0 : m - 1] = v;
        op ++;
      } else {
        ax[(ptr ++) % m] = v;
      }
    }
    
    int l;
    int[] bx;
    
    if (m > 1) {
      l = ax[m - 1] == 1 ? (m - 1) : m;
      bx = new int[l];
      for (int i = 0; i < l; i ++) {
        if (i == m - 1) {
        bx[i] = ax[i] - 1;
        } else if (i == 0) {
          bx[i] = ax[i] + 1;
        } else {
          bx[i] = ax[i];
        }
      }
    } else if (ax[0] > 1) {
      l = 2;
      bx = new int[] {ax[0] - 1, 1};
    } else {
      l = 1;
      bx = new int[] {1};
    }
    
    for (int i = 0; i < m; i ++) {
      System.out.print(ax[i] + (i < m - 1 ? " " : ""));
    }
    System.out.println();
    System.out.println(l);
    for (int i = 0; i < l; i ++) {
      System.out.print(bx[i] + (i < l - 1 ? " " : ""));
    }
    System.out.println();
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