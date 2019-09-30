public class Main {


  private static void solve() {
    int n = ni();
    int[] a = na(n);
    
    int turn = 1;
    while (true) {
      int even = 0;
      int odd = 0;
      int oddNum = 0;
      for (int v : a) {
        if (v % 2 == 0) {
          even ++;
        } else {
          odd ++;
          oddNum = v;
        }
      }
      
      if (even % 2 == 1) {
        System.out.println(turn == 1 ? "First" : "Second");
        break;
      } else if (even % 2 == 0 && (odd != 1 || oddNum == 1)) {
        System.out.println(turn == 1 ? "Second" : "First");
        break;
      }
      turn = -turn;

      int gcd = 0;
      for (int i = 0; i < n; i ++) {
        if (a[i] % 2 == 1) {
          a[i] --;
        }
        gcd = gcd == 0 ? a[i] : gcd(a[i], gcd);
      }
      for (int i = 0; i < n; i ++) {
        a[i] /= gcd;
      }
    }
  }
  

  public static int gcd(int a, int b) {
    while (b > 0){
        int c = a;
        a = b;
        b = c % b;
    }
    return a;
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