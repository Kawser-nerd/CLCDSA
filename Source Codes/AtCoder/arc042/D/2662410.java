import java.util.Arrays;


public class Main {

  private static void solve() {

    long x = ni();
    int p = ni();
    int a = ni();
    int b = ni();
    int d = b - a;
    if (d < 30000000) {
      System.out.println(solve(x, p, a, b));
    } else if (a / (p -1) != b / (p - 1)) {
      System.out.println(1);
    } else {
      a %= p - 1;
      b %= p - 1;
      table(x, p);
      for (int c = 1; c <= p; c ++) {
        long ret = bsgs(x, c, p);
        if (ret < a || ret > b) continue;
        System.out.println(c);
        return;
      }
    }
  }

  static long val = 1;
  static long[] table;
  static int m;
  static long ainvm;
  private static void table(long alpha, int p) {
    m = (int)Math.sqrt(p)+1;
    table = new long[m];
    val = 1;
    for(int j = 0;j < m;j++){
        table[j] = val<<32|j;
        val = val * alpha % p;
    }
    Arrays.sort(table);
    ainvm = invl(val, p);
  }

  public static long bsgs(long alpha, long beta, int p)
  {
      long g = beta;
      for(int i = 0;i < m;i++){
          int ind = Arrays.binarySearch(table, g<<32);
          if(ind < 0)ind = -ind-1;
          if(ind < m && table[ind]>>>32 == g){
              return i*m+(int)table[ind];
          }
          g = g * ainvm % p;
      }
      return -1;
  }
  
  public static long invl(long a, long mod)
  {
      long b = mod;
      long p = 1, q = 0;
      while(b > 0){
          long c = a / b;
          long d;
          d = a; a = b; b = d % b;
          d = p; p = q; q = d - c * q;
      }
      return p < 0 ? p + mod : p;
  }
  
  private static int solve(long x, int p, int a, int b) {
    long now = pow(x, a, p);
    int d = b - a;

    long ret = Long.MAX_VALUE;
    for (int i = 0; i <= d; i++) {
      ret = Math.min(ret, now);
      if (ret == 1) return 1;
      now = now * x % p;
    }
    return (int)ret;
  }

  public static long pow(long a, long n, long mod) {
    long ret = 1;
    int x = 63 - Long.numberOfLeadingZeros(n);
    for (; x >= 0; x--) {
      ret = ret * ret % mod;
      if (n << ~x < 0)
        ret = ret * a % mod;
    }
    return ret;
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