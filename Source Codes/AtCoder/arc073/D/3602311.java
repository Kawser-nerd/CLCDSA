import java.util.Arrays;

public class Main {
  private static void solve() {
    int n = ni();
    int q = ni();
    int a = ni() - 1;
    int b = ni() - 1;
    int[] x = new int[q + 1];
    x[0] = b;
    for (int i = 0; i < q; i ++) {
      x[i + 1] = ni() - 1;
    }
    
    //dp[i][j] + j
    StarrySkyTreeL sst1 = new StarrySkyTreeL(n);
    //dp[i][j] - j
    StarrySkyTreeL sst2 = new StarrySkyTreeL(n);
    
    long inf = 500000L * 500000L;

    for (int i = 0; i < n; i ++) {
      if (i == a) {
        sst1.add(i, i + 1, a);
        sst2.add(i, i + 1, -a);
      } else {
        sst1.add(i, i + 1, inf + i);
        sst2.add(i, i + 1, inf - i);
      }
    }
    
    for (int i = 0; i < q; i ++) {
      int d = Math.abs(x[i + 1] - x[i]);

      long y = Math.min(sst2.min(0, x[i + 1]) + x[i + 1], sst1.min(x[i + 1], n) - x[i + 1]);

      sst1.add(0, n, d);
      sst2.add(0, n, d);
      
      long w = sst1.min(x[i], x[i] + 1) - x[i];
      if (y < w) {
        sst1.add(x[i], x[i] + 1, -w + y);
        sst2.add(x[i], x[i] + 1, -w + y);
      }
    }

    long ret = Long.MAX_VALUE;
    for (int i = 0; i < n; i ++) {
      ret = Math.min(ret, sst1.min(i, i + 1) - i);
    }
    System.out.println(ret);
  }
  
  
  static class StarrySkyTreeL {
    public int M, H, N;
    public long[] st;
    public long[] plus;
    public long I = Long.MAX_VALUE/4; // I+plus<long
    
    public StarrySkyTreeL(int n)
    {
        N = n;
        M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
        H = M>>>1;
        st = new long[M];
        plus = new long[H];
    }
    
    public StarrySkyTreeL(long[] a)
    {
        N = a.length;
        M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
        H = M>>>1;
        st = new long[M];
        for(int i = 0;i < N;i++){
            st[H+i] = a[i];
        }
        plus = new long[H];
        Arrays.fill(st, H+N, M, I);
        for(int i = H-1;i >= 1;i--)propagate(i);
    }
    
    private void propagate(int i)
    {
        st[i] = Math.min(st[2*i], st[2*i+1]) + plus[i];
    }
    
    public void add(int l, int r, long v){ if(l < r)add(l, r, v, 0, H, 1); }
    
    private void add(int l, int r, long v, int cl, int cr, int cur)
    {
        if(l <= cl && cr <= r){
            if(cur >= H){
                st[cur] += v;
            }else{
                plus[cur] += v;
                propagate(cur);
            }
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
    
    public long min(int l, int r){ return l >= r ? I : min(l, r, 0, H, 1);}
    
    private long min(int l, int r, int cl, int cr, int cur)
    {
        if(l <= cl && cr <= r){
            return st[cur];
        }else{
            int mid = cl+cr>>>1;
            long ret = I;
            if(cl < r && l < mid){
                ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
            }
            if(mid < r && l < cr){
                ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
            }
            return ret + plus[cur];
        }
    }
    
    public void fall(int i)
    {
        if(i < H){
            if(2*i < H){
                plus[2*i] += plus[i];
                plus[2*i+1] += plus[i];
            }
            st[2*i] += plus[i];
            st[2*i+1] += plus[i];
            plus[i] = 0;
        }
    }
    
    public int firstle(int l, long v) {
        int cur = H+l;
        for(int i = 1, j = Integer.numberOfTrailingZeros(H)-1;i <= cur;j--){
            fall(i);
            i = i*2|cur>>>j&1;
        }
        while(true){
            fall(cur);
            if(st[cur] <= v){
                if(cur < H){
                    cur = 2*cur;
                }else{
                    return cur-H;
                }
            }else{
                cur++;
                if((cur&cur-1) == 0)return -1;
                cur = cur>>>Integer.numberOfTrailingZeros(cur);
            }
        }
    }
    
    public int lastle(int l, long v) {
        int cur = H+l;
        for(int i = 1, j = Integer.numberOfTrailingZeros(H)-1;i <= cur;j--){
            fall(i);
            i = i*2|cur>>>j&1;
        }
        while(true){
            fall(cur);
            if(st[cur] <= v){
                if(cur < H){
                    cur = 2*cur+1;
                }else{
                    return cur-H;
                }
            }else{
                if((cur&cur-1) == 0)return -1;
                cur = cur>>>Integer.numberOfTrailingZeros(cur);
                cur--;
            }
        }
    }
    
    public void addx(int l, int r, long v){
        if(l >= r)return;
        while(l != 0){
            int f = l&-l;
            if(l+f > r)break;
            if(f == 1){
                st[(H+l)/f] += v;
            }else{
                plus[(H+l)/f] += v;
            }
            l += f;
        }
        
        while(l < r){
            int f = r&-r;
            if(f == 1){
                st[(H+r)/f-1] += v;
            }else{
                plus[(H+r)/f-1] += v;
            }
            r -= f;
        }
    }
    
    public long minx(int l, int r){
        long lmin = I;
        if(l >= r)return lmin;
        if(l != 0){
            for(int d = 0;H>>>d > 0;d++){
                if(d > 0){
                    int id = (H+l-1>>>d);
                    lmin += plus[id];
                }
                if(l<<~d<0 && l+(1<<d) <= r){
                    long v = st[H+l>>>d];
                    if(v < lmin)lmin = v;
                    l += 1<<d;
                }
            }
        }
        long rmin = I;
        for(int d = 0;H>>>d > 0;d++){
            if(d > 0 && r < H)rmin += plus[H+r>>>d];
            if(r<<~d<0 && l < r){
                long v = st[(H+r>>>d)-1];
                if(v < rmin)rmin = v;
                r -= 1<<d;
            }
        }
        long min = Math.min(lmin, rmin);
        return min;
    }
    
    public long[] toArray() { return toArray(1, 0, H, new long[H]); }
    
    private long[] toArray(int cur, int l, int r, long[] ret)
    {
        if(r-l == 1){
            ret[cur-H] = st[cur];
        }else{
            toArray(2*cur, l, l+r>>>1, ret);
            toArray(2*cur+1, l+r>>>1, r, ret);
            for(int i = l;i < r;i++)ret[i] += plus[cur];
        }
        return ret;
    }
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