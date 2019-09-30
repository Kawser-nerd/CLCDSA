public class Main {
  private static void solve() {
    int n = ni();
    int[] a = na(n);
    int[] b = na(n);

    long cost = 0;

    boolean[][] can = new boolean[n][51];
    for (int i = 0; i < n; i ++) {
      can[i][a[i]] = true;
    }

    for (int k = 50; k >= 0; k --) {
      boolean[][] g = new boolean[51][51];
      for (int i = 0; i <= 50; i ++) {
        g[i][i] = true;
        for (int j = 1; j <= k; j ++) {
          g[i][i % j] = true;
        }
      }
      wf(g);

      boolean use = false;
      for (int i = 0; i < n; i ++) {
        boolean flg = false;
        for (int j = 0; j <= 50; j ++) {
          if (can[i][j] && g[j][b[i]]) {
            flg = true;
            break;
          }
        }

        if (!flg) {
          if (k == 50) {
            System.out.println(-1);
            return;
          }
          cost |= 1L << k + 1;
          use = true;
          break;
        }
      }
      
      if (use) {
        for (int i = 0; i < n; i ++) {
          boolean[] tmp = new boolean[51];
          
          for (int j = 0; j <= 50; j ++) {
            tmp[j] |= can[i][j];
            tmp[j % (k + 1)] |= can[i][j];
          }
          can[i] = tmp;
        }
      }
    }
    System.out.println(cost);
  }

  public static boolean[][] wf(boolean[][] d)
  {
      int n = d.length;
      for(int k = 0;k < n;k++){
          for(int i = 0;i < n;i++){
              for(int j = 0;j < n;j++){
                  if(d[i][k] && d[k][j]){
                      d[i][j] = true;
                  }
              }
          }
      }
      return d;
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