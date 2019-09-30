import java.util.Arrays;
class SegmentTreeRSQ {
  public int M, H, N;
  public long[] st;
  public long[] plus;
  
  public SegmentTreeRSQ(int n)
  {
      N = n;
      M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
      H = M>>>1;
      st = new long[M];
      plus = new long[H];
  }
  
  public SegmentTreeRSQ(int[] a)
  {
      N = a.length;
      M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
      H = M>>>1;
      st = new long[M];
      plus = new long[H];
      for(int i = 0;i < N;i++){
          st[H+i] = a[i];
      }
      for(int i = (M>>1)-1;i >= 1;i--){
          propagate(i);
      }
  }
  
  public void add(int pos, int v)
  {
      for(int i = H+pos;i >= 1;i >>>= 1){
          st[i] += v;
      }
  }
  
  private void propagate(int i)
  {
      int count = H/Integer.highestOneBit(i);
      st[i] = st[2*i]+st[2*i+1]+plus[i]*count;
  }
  
  public void add(int l, int r, int v) { if(l < r)add(l, r, v, 0, H, 1); }
  
  private void add(int l, int r, int v, int cl, int cr, int cur)
  {
      if(cur >= H){
          st[cur] += v;
      }else if(l <= cl && cr <= r){
          plus[cur] += v;
          propagate(cur);
      }else{
          int mid = cl+cr>>>1;
          if(cl < r && l < mid){
              add(l, r, v, cl, mid, 2*cur);
          }
          if(mid < r && l < cr){
              add(l, r, v, mid, cr, 2*cur+1);
          }
          propagate(cur);
      }
  }
  
  private long gsum;
  
  public long sum(int l, int r) { 
      gsum = 0;
      sum(l, r, 0, H, 1);
      return gsum;
  }
  
  private void sum(int l, int r, int cl, int cr, int cur)
  {
      if(l <= cl && cr <= r){
          gsum += st[cur];
      }else{
          int mid = cl+cr>>>1;
          if(cl < r && l < mid){
              sum(l, r, cl, mid, 2*cur);
          }
          if(mid < r && l < cr){
              sum(l, r, mid, cr, 2*cur+1);
          }
          gsum += plus[cur]*(Math.min(r,cr)-Math.max(l,cl));
      }
  }
}

public class Main {


  private static void solve() {
    int n = ni();
    int[][] pos = new int[n][2];
    for (int i = 0; i < n * 2; i ++) {
      int c = ns()[0] == 'B' ? 0 : 1;
      int a = ni() - 1;
      
      pos[a][c] = i;
    }

    long[][] dp = new long[n + 1][n + 1];
    for (long[] v : dp) Arrays.fill(v, Long.MAX_VALUE / 2);
    dp[0][0] = 0;

    SegmentTreeRSQ st1 = new SegmentTreeRSQ(n * 2);
    for (int i = 0; i <= n; i ++) {
      if (i > 0) {
        st1.add(pos[i - 1][0], 1);
      }

      SegmentTreeRSQ st2 = new SegmentTreeRSQ(n * 2);
      for (int j = 0; j <= n; j ++) {
        if (i == j && j == 0) continue;
        
        if (j > 0) {
          st2.add(pos[j - 1][1], 1);
        }

        if (i > 0) {
          int p = pos[i - 1][0];
          dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + (p - st1.sum(0, p) - st2.sum(0, p)));
        }
        if (j > 0) {
          int p = pos[j - 1][1];
          dp[i][j] = Math.min(dp[i][j], dp[i][j - 1] + (p - st1.sum(0, p) - st2.sum(0, p)));
        }
      }
    }
    System.out.println(dp[n][n]);
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