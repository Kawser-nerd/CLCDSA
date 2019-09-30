import java.util.Arrays;

class SegmentTreeRMQL {
  public int M, H, N;
  public long[] st;
  
  public SegmentTreeRMQL(int n)
  {
      N = n;
      M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
      H = M>>>1;
      st = new long[M];
      Arrays.fill(st, 0, M, Long.MAX_VALUE / 10);
  }
  
  public SegmentTreeRMQL(long[] a)
  {
      N = a.length;
      M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
      H = M>>>1;
      st = new long[M];
      for(int i = 0;i < N;i++){
          st[H+i] = a[i];
      }
      Arrays.fill(st, H+N, M, Long.MAX_VALUE);
      for(int i = H-1;i >= 1;i--)propagate(i);
  }
  
  public void update(int pos, long x)
  {
      st[H+pos] = x;
      for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
  }
  
  private void propagate(int i)
  {
      st[i] = Math.min(st[2*i], st[2*i+1]);
  }
  
  public long minx(int l, int r){
      long min = Long.MAX_VALUE;
      if(l >= r)return min;
      while(l != 0){
          int f = l&-l;
          if(l+f > r)break;
          long v = st[(H+l)/f];
          if(v < min)min = v;
          l += f;
      }
      
      while(l < r){
          int f = r&-r;
          long v = st[(H+r)/f-1];
          if(v < min)min = v;
          r -= f;
      }
      return min;
  }
}

public class Main {
  private static void solve() {
    int n = ni();
    int q = ni();
    int a = ni() - 1;
    int b = ni() - 1;
    int[] x = new int[q + 1];
    x[0] = a;
    long sum = 0;
    for (int i = 1; i <= q; i++) {
      x[i] = ni() - 1;
      sum += Math.abs(x[i] - x[i - 1]);
    }

    SegmentTreeRMQL stL = new SegmentTreeRMQL(n);
    SegmentTreeRMQL stR = new SegmentTreeRMQL(n);
    long[] dp = new long[n];
    Arrays.fill(dp, Long.MAX_VALUE / 10);
    dp[b] = 0;
    stL.update(b, dp[b] - b);
    stR.update(b, dp[b] + b);

    for (int i = 1; i <= q; i++) {
      long d = Math.abs(x[i] - x[i - 1]);
      dp[x[i-1]] = Math.min(stL.minx(0, x[i]) + x[i], stR.minx(x[i], n) - x[i]) - d;
      stL.update(x[i-1], dp[x[i-1]] - x[i-1]);
      stR.update(x[i-1], dp[x[i-1]] + x[i-1]);
    }

    System.out.println(Arrays.stream(dp).min().getAsLong() + sum);
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