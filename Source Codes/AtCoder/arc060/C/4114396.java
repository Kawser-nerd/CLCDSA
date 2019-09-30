public class Main {
  private static void solve() {
    int n = ni();
    int[] x = na(n);
    int l = ni();
    int q = ni();
    
    int m = 30;
    int[][] pars = new int[m][n];
    pars[0][0] = -1;
    for (int i = 1; i < n; i ++) {
      pars[0][i] = lowerBound(x, x[i] - l);
    }

    for (int j = 1; j < m; j ++) {
      for (int i = 0; i < n; i ++) {
        pars[j][i] = pars[j - 1][i] == -1 ? -1 : pars[j - 1][pars[j-1][i]];
      }
    }
    
    for (int i = 0; i < q; i ++) {
      int a = ni() - 1;
      int b = ni() - 1;
      if (a > b) {
        int tmp = b;
        b = a;
        a = tmp;
      }
      
      int ok = Integer.MAX_VALUE / 3;
      int ng = 0;
      while (ok - ng > 1) {
        int k = (ng + ok) / 2;
        
        int now = b;
        for (int j = 29; j >= 0; j --) {
          if (((k >> j) & 1) != 0) {
            now = pars[j][now];
            if (now < 0) break;
          }
        }
        if (now <= a) {
          ok = k;
        } else {
          ng = k;
        }
      }
      out.println(ok);
    }
  }
  
  public static int lowerBound(int[] a, int v)
  {
      int low = -1, high = a.length;
      while(high-low > 1){
          int h = high+low>>>1;
          if(a[h] >= v){
              high = h;
          }else{
              low = h;
          }
      }
      return high;
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