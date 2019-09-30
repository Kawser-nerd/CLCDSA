import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Main {


  private static void solve() {
    int n = ni();
    int[] a = na(n);
    int[] b = na(n);
    
    
    Map<Integer, Integer> map = new HashMap<>();
    int x = 0;
    int y = 0;
    for (int i = 0; i <= n; i ++) {   

      if (i < n) {
        x ^= a[i];
        y ^= b[i];
      }
      int s = i == n ? x : a[i];
      int t = i == n ? y : b[i];

      map.putIfAbsent(s, 0);
      map.put(s, map.get(s) + 1);
      map.putIfAbsent(t, 0);
      map.put(t, map.get(t) - 1);
      
      if (map.get(s) == 0) {
        map.remove(s);
      }
      if (map.containsKey(t) && map.get(t) == 0) {
        map.remove(t);
      }
    }

    if (map.size() > 0) {
      System.out.println(-1);
      return;
    }

    int[] c = new int[n + 1];
    int[] d = new int[n + 1];
    c[0] = x;
    d[0] = y;
    int ptr = 1;
    for (int i = 0; i < n; i ++) {
      if (a[i] != b[i]) {
        c[ptr] = a[i];
        d[ptr] = b[i];
        ptr ++;
      }
    }
    c = Arrays.copyOf(c, ptr);
    d = Arrays.copyOf(d, ptr);
    
    int[] sa = shrink(c);
    int[] sb = shrink(d);
    int max = Arrays.stream(sa).max().getAsInt();

    DisjointSet djset = new DisjointSet(max + 1);
    int cnt = 0;
    for (int i = 0; i < ptr; i ++) {
      if (sa[i] != sb[i]) {
        djset.union(sa[i], sb[i]);
        if (i > 0) cnt ++;
      }
    }
    System.out.println(cnt + djset.count() - 1);
  }

  public static int[] shrink(int[] a)
  {
      int n = a.length;
      long[] b = new long[n];
      for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
      Arrays.sort(b);
      int[] ret = new int[n];
      int p = 0;
      for(int i = 0;i < n;i++) {
          if(i>0 && (b[i]^b[i-1])>>32!=0)p++;
          ret[(int)b[i]] = p;
      }
      return ret;
  }
  
  static class DisjointSet {
    public int[] upper; // minus:num_element(root) plus:root(normal)
//  public int[] w;
    
    public DisjointSet(int n)
    {
        upper = new int[n];
        Arrays.fill(upper, -1);
//      w = new int[n];
    }
    
    public DisjointSet(DisjointSet ds)
    {
        this.upper = Arrays.copyOf(ds.upper, ds.upper.length);
    }       
    
    public int root(int x)
    {
        return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
    }
    
    public boolean equiv(int x, int y)
    {
        return root(x) == root(y);
    }
    
    public boolean union(int x, int y)
    {
        x = root(x);
        y = root(y);
        if(x != y) {
            if(upper[y] < upper[x]) {
                int d = x; x = y; y = d;
            }
//          w[x] += w[y];
            upper[x] += upper[y];
            upper[y] = x;
        }
        return x == y;
    }
    
    public int count()
    {
        int ct = 0;
        for(int u : upper){
            if(u < 0)ct++;
        }
        return ct;
    }
    
    public int[][] toBucket()
    {
        int n = upper.length;
        int[][] ret = new int[n][];
        int[] rp = new int[n];
        for(int i = 0;i < n;i++){
            if(upper[i] < 0)ret[i] = new int[-upper[i]];
        }
        for(int i = 0;i < n;i++){
            int r = root(i);
            ret[r][rp[r]++] = i;
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