public class Main {
  private static void solve() {
    int n = ni();
    int max = 2000;
    int m = max * 2 + 1;
    int[][] cnt = new int[m][m];
    int mod = 1000000000 + 7;
    int[][] fif = enumFIF(8010, mod);

    long z = 0;
    for (int i = 0; i < n; i ++) {
      int a = ni();
      int b = ni();
      cnt[max - a][max - b] --;
      cnt[max + a][max + b] ++;
      
      z += CX((a + b) * 2, a * 2, mod, fif);
      z %= mod;
    }
    

    int[][] dp = new int[m][m];
    long ret = 0;
    for (int i = 0; i < m; i ++) {
      for (int j = 0; j < m; j ++) {
        if (cnt[i][j] < 0) {
          dp[i][j] += -cnt[i][j];
        } else if (cnt[i][j] > 0) {
          ret += (long)dp[i][j] * cnt[i][j] % mod;
          ret %= mod;
        }
        if (i < m - 1) {
          dp[i + 1][j] += dp[i][j];
          dp[i + 1][j] %= mod;
        }
        if (j < m - 1) {
          dp[i][j + 1] += dp[i][j];
          dp[i][j + 1] %= mod;
        }
      }
    }
    
    System.out.println((ret + mod - z) * invl(2, mod) % mod);
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
  
  public static long CX(long n, long r, int p, int[][] fif)
  {
      if(n < 0 || r < 0 || r > n)return 0;
      int np = (int)(n%p), rp = (int)(r%p);
      if(np < rp)return 0;
      if(n == 0 && r == 0)return 1;
      int nrp = np-rp;
      if(nrp < 0)nrp += p;
      return (long)fif[0][np]*fif[1][rp]%p*fif[1][nrp]%p*CX(n/p, r/p, p, fif)%p;
  }

  public static int[][] enumFIF(int n, int mod)
  {
      int[] f = new int[n+1];
      int[] invf = new int[n+1];
      f[0] = 1;
      for(int i = 1;i <= n;i++){
          f[i] = (int)((long)f[i-1] * i % mod);
      }
      long a = f[n];
      long b = mod;
      long p = 1, q = 0;
      while(b > 0){
          long c = a / b;
          long d;
          d = a; a = b; b = d % b;
          d = p; p = q; q = d - c * q;
      }
      invf[n] = (int)(p < 0 ? p + mod : p);
      for(int i = n-1;i >= 0;i--){
          invf[i] = (int)((long)invf[i+1] * (i+1) % mod);
      }
      return new int[][]{f, invf};
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