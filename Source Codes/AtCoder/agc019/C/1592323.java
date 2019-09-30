import java.util.Arrays;
import java.util.function.Predicate;

public class Main {

  private static void solve() {
    int[] sg = na(4);
    int maxX = Math.max(sg[0], sg[2]);
    int minX = Math.min(sg[0], sg[2]);
    int maxY = Math.max(sg[1], sg[3]);
    int minY = Math.min(sg[1], sg[3]);
    int flgY = sg[1] > sg[3] ? -1 : 1;
    int flgX = sg[0] > sg[2] ? -1 : 1;

    int n = ni();
    int[][] p = ntable(n, 2);
    Arrays.sort(p, (o1, o2) -> o1[0] == o2[0] ? o1[1] - o2[1] : (o1[0] - o2[0]) * flgX);
    Predicate<int[]> pred = v -> minX <= v[0] && v[0] <= maxX && minY <= v[1] && v[1] <= maxY;
    int[] y = Arrays.stream(p).filter(pred).mapToInt(v -> v[1] * flgY).toArray();
    int ball = lis(y);

    double total = ((maxX - minX) + (maxY - minY)) * 100.0;
    double arg1 = 20.0 - Math.PI * 5.0;
    double arg2 = Math.PI * 10.0 - 20.0;

    int lenMin = Math.min(maxX - minX, maxY - minY);
    if (lenMin <= ball - 1) {
      out.printf("%.13f\n", total - arg1 * lenMin + arg2);
    } else {
      out.printf("%.13f\n", total - arg1 * ball);
    }
  }
  
  public static int lis(int[] in)
  {
      int n = in.length;
      int ret = 0;
      int[] h = new int[n + 1];
      Arrays.fill(h, Integer.MIN_VALUE / 2);
      for(int i = 0;i < n;i++){
          int ind = Arrays.binarySearch(h, 0, ret + 1, in[i]);
          if(ind < 0){
              ind = -ind-2;
              h[ind+1] = in[i];
              if(ind >= ret)ret++;
          }
      }
      return ret;
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