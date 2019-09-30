import java.util.Arrays;

public class Main {
  private static void solve() {
    int n = ni();
    int[] from = new int[n - 1];
    int[] to = new int[n - 1];
    
    for (int i = 0; i < n - 1; i ++) {
      from[i] = ni() - 1;
      to[i] = ni() - 1;
    }
    int[][] g = packU(n, from, to);
    int[] center = center(g);

    long[] ret;
    if (center.length == 1) {
      int v = center[0];
      ret = f1(v, g);
      for (int next : g[v]) {
        long[] now = f2(v, next, g);
        if (now[0] < ret[0] || now[0] == ret[0] && now[1] < ret[1]) {
          ret = now;
        }
      }
    } else {
      ret = f2(center[0], center[1], g);
    }
    System.out.println(ret[0] + " " + ret[1]);
  }

  private static long[] f2(int root1, int root2, int[][] g) {
    int n = g.length;
    int[] deg1 = new int[n + 1];
    int[] deg2 = new int[n + 1];
    Arrays.fill(deg1, -1);
    Arrays.fill(deg2, -1);
    dfs(root1, root2, g, deg1, 0);
    dfs(root2, root1, g, deg2, 0);
    
    int[] deg = new int[n + 1];
    int maxDepth = 0;
    for (int i = 0; i < deg.length; i ++) {
      deg[i] = Math.max(deg1[i], deg2[i]);
      if (deg[i] < 0) {
        maxDepth = i;
        break;
      }
    }

    long leaf = 2;
    for (int i = 0; i < maxDepth - 1; i ++) {
      leaf *= deg[i];
    }
    return new long[] {maxDepth, leaf};
  }

  private static void dfs(int now, int pre, int[][] g, int[] deg, int depth) {

    for (int next : g[now]) {
      if (next == pre) continue;
      
      dfs(next, now, g, deg, depth + 1);
    }
    
    deg[depth] = Math.max(deg[depth], g[now].length - 1);
  }

  private static long[] f1(int root, int[][] g) {
    int[][] p3 = parents(g, root);
    int[] depth = p3[2];
    int maxDepth = Arrays.stream(depth).max().getAsInt() + 1;
    int[] deg = new int[maxDepth];
    int n = g.length;
    
    for (int i = 0; i < n; i ++) {
      int x = i == root ? 0 : -1;
      deg[depth[i]] = Math.max(deg[depth[i]], g[i].length + x);
    }
    
    long leaf = 1;
    for (int i = 0; i < maxDepth - 1; i ++) {
      leaf *= deg[i];
    }
    return new long[] {maxDepth, leaf};
  }
  
  public static int[][] parents(int[][] g, int root)
  {
      int n = g.length;
      int[] par = new int[n];
      Arrays.fill(par, -1);
      
      int[] depth = new int[n];
      depth[0] = 0;
      
      int[] q = new int[n];
      q[0] = root;
      for(int p = 0, r = 1;p < r;p++) {
          int cur = q[p];
          for(int nex : g[cur]){
              if(par[cur] != nex){
                  q[r++] = nex;
                  par[nex] = cur;
                  depth[nex] = depth[cur] + 1;
              }
          }
      }
      return new int[][] {par, q, depth};
  }
  
  public static int[][] packU(int n, int[] from, int[] to){ return packU(n, from, to, from.length); }
  public static int[][] packU(int n, int[] from, int[] to, int sup)
  {
      int[][] g = new int[n][];
      int[] p = new int[n];
      for(int i = 0;i < sup;i++)p[from[i]]++;
      for(int i = 0;i < sup;i++)p[to[i]]++;
      for(int i = 0;i < n;i++)g[i] = new int[p[i]];
      for(int i = 0;i < sup;i++){
          g[from[i]][--p[from[i]]] = to[i];
          g[to[i]][--p[to[i]]] = from[i];
      }
      return g;
  }
  
  public static int[] center(int[][] g)
  {
      int n = g.length;
      int start = 0;
      int[] d1 = dist(g, start);
      int maxd1 = -1;
      int argmaxd1 = -1;
      for(int i = 0;i < n;i++){
          if(d1[i] > maxd1){
              maxd1 = d1[i];
              argmaxd1 = i;
          }
      }
      
      int[] d2 = dist(g, argmaxd1);
      int maxd2 = -1;
      int argmaxd2 = -1;
      for(int i = 0;i < n;i++){
          if(d2[i] > maxd2){
              maxd2 = d2[i];
              argmaxd2 = i;
          }
      }
      
      if(maxd2 % 2 == 0){
          int h = maxd2/2;
          int j = argmaxd2;
          outer:
          for(int i = maxd2;i > h;i--){
              for(int e : g[j]){
                  if(d2[e] == i-1){
                      j = e;
                      continue outer;
                  }
              }
              throw new RuntimeException();
          }
          return new int[]{j};
      }else{
          int h = maxd2/2;
          int j = argmaxd2;
          int[] cs = new int[2];
          int p = 0;
          outer:
          for(int i = maxd2;i >= h;i--){
              if(i <= h+1)cs[p++] = j;
              if(i > h){
                  for(int e : g[j]){
                      if(d2[e] == i-1){
                          j = e;
                          continue outer;
                      }
                  }
                  throw new RuntimeException();
              }
          }
          return cs;
      }
  }
  
  public static int[] dist(int[][] g, int start)
  {
      int n = g.length;
      int[] d = new int[n];
      Arrays.fill(d, n+3);
      int[] q = new int[n];
      int p = 0;
      q[p++] = start;
      d[start] = 0;
      for(int r = 0;r < p;r++){
          int cur = q[r];
          for(int e : g[cur]){
              if(d[e] > d[cur] + 1){
                  d[e] = d[cur] + 1;
                  q[p++] = e;
              }
          }
      }
      return d;
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