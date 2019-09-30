import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {
  private static void solve() {
    char[] s = ns();
    int n = s.length;
    
    int p = 0;
    char pre = 0;
    boolean flg = false;
    Set<Character> set = new HashSet<>();
    for (char c : s) {
      p = (p + (c - 'a')) % 3;
      if (pre == c) {
        flg = true;
      }
      pre = c;
      set.add(c);
    }
    if (set.size() == 1) {
      System.out.println(1);
      return;
    }
    if (n == 3) {
      if (set.size() == 3) {
        System.out.println(3);
      } else {
        System.out.println(6 + (flg ? 0 : 1));
      }
      return;
    } else if (n == 2) {
      if (set.size() == 2) {
        System.out.println(2);
      }
      return;
    }
    

    // dp[from/to][??][?????][??]
    long[][][][] dp = new long[2][3][3][2];
    int mod = 998244353;
    dp[0][0][0][0] = 1;
    for (int i = 0; i < n; i++) {
      int from = i & 1;
      int to = from ^ 1;

      // j:???? k:???? l:????
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          for (int l = 0; l < 3; l++) {
            int r = (j + l) % 3; // ????
            int f = i > 0 && k == l ? 1 : 0;

            dp[to][r][l][f] += dp[from][j][k][0];
            dp[to][r][l][f] %= mod;
            dp[to][r][l][1] += dp[from][j][k][1];
            dp[to][r][l][1] %= mod;
          }
        }
      }
      for (long[][] v : dp[from])
        for (long[] u : v)
          Arrays.fill(u, 0);
    }

    long ret = 0;
    for (int j = 0; j < 3; j++) {
      ret += dp[n % 2][p][j][1];
      ret %= mod;
    }
    if (!flg) ret ++;
    System.out.println(ret);
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