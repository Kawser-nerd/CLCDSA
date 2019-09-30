import java.awt.geom.Line2D;
import java.util.Arrays;
import java.util.Comparator;

public class Main {


  private static void solve() {
    int n = ni();
    double[] x = new double[n];
    double[] y = new double[n];
    for (int i = 0; i < n; i ++) {
      x[i] = ni();
      y[i] = ni();
    }

    int[] ch = convexHull(x, y);
    int m = ch.length;
    double[] prob = new double[m];
    
    for (int i = 0; i < m; i ++) {
      int pre = (i + m - 1) % m;
      int next = (i + 1) % m;
      
      double dx1 = x[ch[pre]] - x[ch[i]];
      double dy1 = y[ch[pre]] - y[ch[i]];
      double dx2 = x[ch[next]] - x[ch[i]];
      double dy2 = y[ch[next]] - y[ch[i]];
      
      double a = Math.abs(Math.atan2(dy2, dx2) - Math.atan2(dy1, dx1));
      if (a < Math.PI) {
        a = 2 * Math.PI - a;
      }
      prob[i] = (a - Math.PI) / (2 * Math.PI);
    }
    double[] ans = new double[n];
    for (int i = 0; i < m; i ++) {
      ans[ch[i]] = prob[i];
    }
    for (double v : ans) {
      System.out.printf("%.12f\n", v);
    }
  }
  
  public static int[] convexHull(final double[] x, final double[] y)
  {
      int n = x.length;
      Integer[] ord = new Integer[n];
      for(int i = 0;i < n;i++)ord[i] = i;
      Arrays.sort(ord, new Comparator<Integer>(){
          public int compare(Integer a, Integer b){
              if(x[a] != x[b])return x[a] < x[b] ? -1 : 1;
              if(y[a] != y[b])return y[a] < y[b] ? -1 : 1;
              return 0;
          }
      });
      
      int[] ret = new int[n + 1];
      int p = 0;
      for(int i = 0;i < n;i++){
          if(p >= 1 && x[ret[p-1]] == x[ord[i]] && y[ret[p-1]] == y[ord[i]])continue;
          while(p >= 2 && Line2D.relativeCCW(
                  x[ret[p-2]], y[ret[p-2]],
                  x[ret[p-1]], y[ret[p-1]],
                  x[ord[i]], y[ord[i]]) == 1)p--;
          ret[p++] = ord[i];
      }
      
      int inf = p + 1;
      for(int i = n - 2;i >= 0;i--){
          if(x[ret[p-1]] == x[ord[i]] && y[ret[p-1]] == y[ord[i]])continue;
          while(p >= inf && Line2D.relativeCCW(
                  x[ret[p-2]], y[ret[p-2]],
                  x[ret[p-1]], y[ret[p-1]],
                  x[ord[i]], y[ord[i]]) == 1)p--;
          ret[p++] = ord[i];
      }
      
      return Arrays.copyOf(ret, p - 1);
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