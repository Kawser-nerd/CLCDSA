import java.util.Arrays;

public class Main {
  private static void solve() {
    int mod = 1000000000 + 7;
    int n = ni();
    int[] from = new int[n - 1];
    int[] to = new int[n - 1];
    for (int i = 0; i < n - 1; i ++) {
      from[i] = ni() - 1;
      to[i] = ni() - 1;
    }
    int[][] g = packU(n, from, to);
    int[][] par3 = parents(g, 0);
    int[] ord = par3[1];
    int[] par = par3[0];
    int[] sep = separators(g, par, ord);
    int[][] fif = enumFIF(10000, mod);

    if (sep.length == 2) {
      int x = dfsCount(sep[0], sep[1], g);
      long ret = (long)fif[0][x] * fif[0][x] % mod;
      System.out.println(ret);
    } else {
      int c = sep[0];
      int m = g[c].length;
      int[] a = new int[m];
      for (int i = 0; i < m; i ++) {
        a[i] = dfsCount(g[c][i], c, g);
      }
      
      long[][] dp = new long[m + 1][n + 1];
      dp[0][0] = 1;
      int sum = 0;
      for (int i = 0; i < m; i ++) {
        for (int j = 0; j <= sum; j ++) {
          for (int k = 0; k <= a[i]; k ++) {
            long comb = CX(a[i], k, mod, fif);
            dp[i + 1][j + k] += dp[i][j] * comb % mod * comb % mod * fif[0][k] % mod;
            dp[i + 1][j + k] %= mod;
          }
        }
        sum += a[i];
      }
      
      long ret = 0;
      for (int i = 0; i <= n; i ++) {
        long now = fif[0][n - i] * dp[m][i] % mod;
        
        ret += now * (i % 2 == 0 ? 1: -1) + mod;
        ret %= mod;
      }
      System.out.println(ret);
    }

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
  
  private static int dfsCount(int now, int pre, int[][] g) {
    int ret = 1;
    for (int next : g[now]) {
      if (next == pre) {
        continue;
      }
      ret += dfsCount(next, now, g);
    }
    return ret;
  }

  static int[] separators(int[][] g, int[] par, int[] ord)
  {
      int n = g.length;
      int[] ret = new int[2];
      int p = 0;
      int[] des = new int[n];
      outer:
      for(int i = n-1;i >= 0;i--){
          int cur = ord[i];
          des[cur] = 1;
          for(int e : g[cur]){
              if(par[cur] != e)des[cur] += des[e];
          }
          if(n-des[cur] <= n/2){
              for(int e : g[cur]){
                  if(par[cur] != e && des[e] >= n/2+1)continue outer;
              }
              ret[p++] = cur;
          }
      }
      return Arrays.copyOf(ret, p);
  }

  public static int[][] parents(int[][] g, int root) {
    int n = g.length;
    int[] par = new int[n];
    Arrays.fill(par, -1);

    int[] depth = new int[n];
    depth[0] = 0;

    int[] q = new int[n];
    q[0] = root;
    for (int p = 0, r = 1; p < r; p++) {
      int cur = q[p];
      for (int nex : g[cur]) {
        if (par[cur] != nex) {
          q[r++] = nex;
          par[nex] = cur;
          depth[nex] = depth[cur] + 1;
        }
      }
    }
    return new int[][] {par, q, depth};
  }


  public static int[][] packU(int n, int[] from, int[] to) {
    return packU(n, from, to, from.length);
  }

  public static int[][] packU(int n, int[] from, int[] to, int sup) {
    int[][] g = new int[n][];
    int[] p = new int[n];
    for (int i = 0; i < sup; i++)
      p[from[i]]++;
    for (int i = 0; i < sup; i++)
      p[to[i]]++;
    for (int i = 0; i < n; i++)
      g[i] = new int[p[i]];
    for (int i = 0; i < sup; i++) {
      g[from[i]][--p[from[i]]] = to[i];
      g[to[i]][--p[to[i]]] = from[i];
    }
    return g;
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