import java.util.Arrays;

public class Main {

  private static void solve() {
    long x = nl();
    int k = ni();
    long[] r = nal(k);
    int qq = ni();
    long[][] query = new long[qq + k][2];
    for (int i = 0; i < qq; i ++) {
      query[i][0] = nl();
      query[i][1] = nl();
    }
    for (int i = 0; i < k; i ++) {
      query[i + qq][0] = r[i];
      query[i + qq][1] = -1;
    }
    Arrays.sort(query, (o1, o2) -> Long.compare(o1[0], o2[0]));
    
    //f_t(x) =
    //  a + c (0 <= x <= a)
    //  x + c (a <= x <= b)
    //  b + c (b <= x < X)

    long a = 0;
    long b = x;
    long c = 0;
    long t = 0;
    boolean up = true;
    
    for (long[] q : query) {
      long[] next = f(q[0] - t, a, b, c, x, up);
      if (q[1] < 0) {
        up = !up;
      } else {
        if (q[1] < next[0]) {
          out.println(next[0] + next[2]);
        } else if (q[1] > next[1]) {
          out.println(next[1] + next[2]);
        } else {
          out.println(q[1] + next[2]);
        }
        out.flush();
      }
      t = q[0];
      a = next[0];
      b = next[1];
      c = next[2];
    }
  }
  
  private static long[] f(long d, long a, long b, long c, long X, boolean up) {
    long[] ret = new long[3];
    if (up) {
      ret[0] = a + c > d ? a : Math.min(d - c, X);
      ret[1] = Math.max(b, ret[0]);
      ret[2] = Math.max(c - d, -X);
    } else {
      ret[1] = b + c + d < X ? b : Math.max(X - (c + d), 0);
      ret[0] = Math.min(ret[1], a);
      ret[2] = Math.min(c + d, X);
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