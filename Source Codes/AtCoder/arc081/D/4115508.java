public class Main {
  private static void solve() {
    int h = ni();
    int w = ni();
    
    int[][] map = new int[h][w];
    for (int i = 0; i < h; i ++) {
      char[] s = ns();
      for (int j = 0; j < w; j ++) {
        map[i][j] = s[j] == '.' ? 0 : 1;
      }
    }
    
    boolean[][] can = new boolean[h - 1][w - 1];
    for (int i = 0; i < h - 1; i ++) {
      for (int j = 0; j < w - 1; j ++) {
        int s = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
        can[i][j] = (s & 1) == 0;
      }
    }
    int[][] cnt = new int[h - 1][w - 1];
    for (int i = 0; i < h - 1; i ++) {
      for (int j = 0; j < w - 1; j ++) {
        cnt[i][j] = can[i][j] ? (i > 0 ? cnt[i - 1][j] : 0) + 1 : 0;
      }
    }
    long ret = Math.max(h, w);
    for (int i = 0; i < h  -1; i ++) {
      ret = Math.max(ret, maxRect(cnt[i]));
    }
    System.out.println(ret);
  }

  public static long maxRect(int[] a)
  {
      int n = a.length;
      int[] stack = new int[n];
      int[] left = new int[n];
      int p = 0;
      long max = 0;
      for(int i = 0;i < n;i++){
          int o = p;
          while(p > 0 && stack[p-1] >= a[i]){
              p--;
              max = Math.max(max, (long)(i-1-left[p]+2)*(stack[p] + 1));
          }
          if(o == p)left[p] = i;
          stack[p++] = a[i];
      }
      while(p > 0){
          p--;
          max = Math.max(max, (long)(n-1-left[p]+2)*(stack[p] + 1));
      }
      return max;
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