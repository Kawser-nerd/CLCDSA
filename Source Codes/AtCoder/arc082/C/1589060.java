import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Main {

  private static void solve() {
    int n = ni();
    int[][] p = ntable(n, 2);
    int mod = 998244353;

    long ret = modpow(2, n, mod);
    Map<Long, Set<Integer>> map = new HashMap<>();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        long a = p[i][1] - p[j][1];
        long b = p[i][0] - p[j][0];
        long c = p[i][0] * (p[j][1] - p[i][1]) - p[i][1] * (p[j][0] - p[i][0]);
        long gcd = gcd(a, gcd(b, c));

        long hash = (a * 100000L * 100000L + b * 100000L + c) / gcd;
        if (hash < 0) hash = -hash;
        if (!map.containsKey(hash)) map.put(hash, new HashSet<>());
        map.get(hash).add(i);
        map.get(hash).add(j);
      }
    }
    for (Set<Integer> v : map.values()) {
      ret += mod - modpow(2, v.size(), mod) + v.size() + 1;
      ret %= mod;
    }
    ret += mod - n - 1;
    ret %= mod;
    out.println(ret);
  }

  public static long gcd(long a, long b) {
    if (a > b) {
      long tmp = a;
      a = b;
      b = tmp;
    }
    while (a != 0) {
      long c = a;
      a = b % c;
      b = c;
    }
    return b;
  }

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
      a[i] = ni();
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