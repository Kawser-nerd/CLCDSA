import java.util.Arrays;

public class Main {

  private static void solve() {
    int n = ni();
    char[] s = ns();
    int m = s.length;
    
    //dp[????????][??????]
    long[][] dp = new long[2][n + 1];
    dp[0][0] = 1;
    int mod = 1000000000 + 7;
    for (int i = 0; i < n; i ++) {
      int from = i % 2;
      int to = (i + 1) % 2;

      for (int j = 0; j <= Math.min(i + 1, n); j ++) {
        if (j < n) {
          dp[to][j] += dp[from][j + 1];
        }
        if (j > 0) {
          dp[to][j] += dp[from][j - 1] * 2;
        }
        if (j == 0) {
          dp[to][j] += dp[from][j];
        }
        dp[to][j] %= mod;
      }
      Arrays.fill(dp[from], 0);
    }
    
    long two = 1;
    for (int i = 0; i < m; i ++) {
      two *= 2;
      two %= mod;
    }
    
    System.out.println(dp[n % 2][m] * inverse(two, mod) % mod);
  }

  public static long[] extgcd(long a, long b) {
    long u = 1;
    long v = 0;
    long x = 0;
    long y = 1;

    while (a > 0) {
        long q = b / a;
        x -= q * u;
        y -= q * v;
        b -= q * a;

        long tmp;
        tmp = x;
        x = u;
        u = tmp;
        tmp = y;
        y = v;
        v = tmp;
        tmp = b;
        b = a;
        a = tmp;
    }

    return new long[] { b, x, y };
}

public static long inverse(long n, long mod) {
    long[] gcd = extgcd(n, mod);
    if (gcd[0] == 1) {
        return (gcd[1] + mod) % mod;
    } else {
        return 0;
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