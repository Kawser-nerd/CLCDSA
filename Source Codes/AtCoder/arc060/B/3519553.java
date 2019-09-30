import java.util.Arrays;

public class Main {


  private static void solve() {
    long n = nl();
    long s = nl();

    if (n < s) {
      System.out.println(-1);
      return;
    }
    
    if (n == s) {
      System.out.println(n + 1);
      return;
    }

    for (long b = 2; b < 1000000; b ++) {
      if (f(b, n) == s) {
        System.out.println(b);
        return;
      }
    }
    
    int[] primes = sieveEratosthenes(1000000);
    long[] div = enumDivisors(n - s, primes);
    Arrays.sort(div);
    for (long b : div) {
      long a1 = (n - s) / b;
      long a2 = s - a1;
      if (0 <= a1 && a1 <= b && 0 <= a2 && a2 <= b) {
        System.out.println(b + 1);
        return;
      }
    }
    
    
    System.out.println(-1);
  }
  public static int[] sieveEratosthenes(int n) {
    if(n <= 32){
        int[] primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
        for(int i = 0;i < primes.length;i++){
            if(n < primes[i]){
                return Arrays.copyOf(primes, i);
            }
        }
        return primes;
    }

    int u = n + 32;
    double lu = Math.log(u);
    int[] ret = new int[(int) (u / lu + u / lu / lu * 1.5)];
    ret[0] = 2;
    int pos = 1;

    int[] isp = new int[(n + 1) / 32 / 2 + 1];
    int sup = (n + 1) / 32 / 2 + 1;

    int[] tprimes = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    for(int tp : tprimes){
        ret[pos++] = tp;
        int[] ptn = new int[tp];
        for(int i = (tp - 3) / 2;i < tp << 5;i += tp)
            ptn[i >> 5] |= 1 << (i & 31);
        for(int i = 0;i < tp;i++){
            for(int j = i;j < sup;j += tp)
                isp[j] |= ptn[i];
        }
    }

    // 3,5,7
    // 2x+3=n
    int[] magic = { 0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4,
            13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14 };
    int h = n / 2;
    for(int i = 0;i < sup;i++){
        for(int j = ~isp[i];j != 0;j &= j - 1){
            int pp = i << 5 | magic[(j & -j) * 0x076be629 >>> 27];
            int p = 2 * pp + 3;
            if(p > n)
                break;
            ret[pos++] = p;
            for(int q = pp;q <= h;q += p)
                isp[q >> 5] |= 1 << (q & 31);
        }
    }

    return Arrays.copyOf(ret, pos);
}
  public static long[] enumDivisors(long n, int[] primes)
  {
      int m = 1;
      long[] divs = {1L};
      int t = 1;
      long u = n;
      for(int p : primes){
          if((long)p*p > u)break;
          int e = 0;
          while(u % p == 0){
              u /= p;
              e++;
          }
          if(e > 0){
              divs = Arrays.copyOf(divs, t*(e+1));
              for(int q = t-1;q >= 0;q--){
                  long b = divs[q];
                  for(int k = 0;k < e;k++){
                      b *= p;
//                    if((long)b*b <= n)divs[t++] = b;
                      divs[t++] = b;
                  }
              }
              m *= e+1;
          }
      }
      if(u > 1){
          long p = u;
          int e = 1;
          divs = Arrays.copyOf(divs, t*(e+1));
          for(int q = t-1;q >= 0;q--){
              long b = divs[q];
              for(int k = 0;k < e;k++){
                  b *= p;
//                if((long)b*b <= n)divs[t++] = b;
                  divs[t++] = b;
              }
          }
          m *= e+1;
      }
      
      return Arrays.copyOf(divs, t);
  }
  
  private static long f(long b, long n) {
    long ret = 0;
    while (n > 0) {
      ret += n % b;
      n /= b;
    }
    return ret;
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