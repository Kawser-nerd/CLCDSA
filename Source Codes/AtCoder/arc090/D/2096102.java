public class Main {

  public static long modpow(long a, long n, long mod) {
    long ret = 1;
    long mul = a;
    for (; n > 0; n >>>= 1) {
      if ((n & 1) == 1) {
        ret = (ret * mul) % mod;
      }
      mul = (mul * mul) % mod;
    }
    return ret;
  }
  
  
  private static void solve() {
    int s = ni();

    long ret = 0;
    int mod = 1_000_000_007;
    
    long total = 1;
    int R = 1;
    int NL = 10, NR = 10, LC = 1, RC = 1;
    for (int L = 1 ; L < 100000000;) {
      while (total < s) {
        R ++;
        if (R == NR) {
          NR *= 10;
          RC ++;
        }
        total += RC;
      }

      if (total == s) {
        ret ++;
      }
      total -= LC;
      L ++;
      if (L == NL) {
        NL *= 10;
        LC ++;
      }
    }
    
    for (int i = 1; i <= s; i ++) {
      int div = s / i;
      if (div <= 8) continue;
      if (s % i > 0) {
        ret ++;
      } else {
        ret += 9 * modpow(10, div - 1, mod) - i + 1 + mod;;
        ret %= mod;
      }
    }
    System.out.println(ret % mod);
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