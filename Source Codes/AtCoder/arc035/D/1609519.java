class SegmentTreeRSQ {
  public int M, H, N;
  public double[] st;
  public double[] plus;
  
  public SegmentTreeRSQ(int n)
  {
      N = n;
      M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
      H = M>>>1;
      st = new double[M];
      plus = new double[H];
  }
  
  public SegmentTreeRSQ(double[] a)
  {
      N = a.length;
      M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
      H = M>>>1;
      st = new double[M];
      plus = new double[H];
      for(int i = 0;i < N;i++){
          st[H+i] = a[i];
      }
      for(int i = (M>>1)-1;i >= 1;i--){
          propagate(i);
      }
  }
  
  public void add(int pos, double v)
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
  
  public void add(int l, int r, double v) { if(l < r)add(l, r, v, 0, H, 1); }
  
  private void add(int l, int r, double v, int cl, int cr, int cur)
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
  
  private double gsum;
  
  public double sum(int l, int r) { 
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

  static int M = 2000001;
  static double[] f = new double[M];
  static int[][] p;
  static int n;
  private static void solve() {
    n = ni();
    p = ntable(n, 2);
    
    f[0] = 0;
    for (int i = 1; i < M; i ++) {
      f[i] = f[i - 1] + Math.log(i);
    }

    SegmentTreeRSQ st = new SegmentTreeRSQ(n);
    for (int i = 0; i < n - 1; i ++) {
      int w = Math.abs(p[i][0] - p[i + 1][0]);
      int h = Math.abs(p[i][1] - p[i + 1][1]);
      //(w+h)Cw
      double v = f[w+h] - f[w] - f[h];
      
      st.add(i, v);
    }
    
    
    int q = ni();
    for (int i = 0; i < q; i ++) {
      int t = ni();
      if (t == 1) {
        int k = ni() - 1;
        int a = ni();
        int b = ni();
        if (k > 0) {
          int w = Math.abs(p[k - 1][0] - a);
          int h = Math.abs(p[k - 1][1] - b);
          double nd = f[w+h] - f[w] - f[h];
          st.add(k - 1, nd - st.sum(k - 1, k));
          //System.out.println("c d1:" + Math.exp(st.sum(k - 1,  k)));
        }
        if (k < n - 1) {
          int w = Math.abs(p[k + 1][0] - a);
          int h = Math.abs(p[k + 1][1] - b);
          double nd = f[w+h] - f[w] - f[h];
          st.add(k, nd - st.sum(k, k + 1));
          //System.out.println("c d2:" + Math.exp(st.sum(k,  k + 1)));
        }
        p[k][0] = a;
        p[k][1] = b;
      } else {
        int l1 = ni() - 1;
        int r1 = ni() - 1;
        int l2 = ni() - 1;
        int r2 = ni() - 1;
        
        double d1 = st.sum(l1, r1);
        double d2 = st.sum(l2, r2);
        //System.out.println("d1:" + Math.exp(d1) + " d2:" + Math.exp(d2));
        if (d1 < d2) {
          out.println("SECOND");
        } else {
          out.println("FIRST");
        }
      }
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