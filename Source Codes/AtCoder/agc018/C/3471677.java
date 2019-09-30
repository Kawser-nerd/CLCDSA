import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {
  private static void solve() {
    int x = ni();
    int y = ni();
    int z = ni();

    int n = x + y + z;
    int[][] c = ntable(n, 3);

    Arrays.sort(c, (o1, o2) -> (o1[1] - o1[0]) - (o2[1] - o2[0]));

    PriorityQueue<int[]> qx = new PriorityQueue<>((o1, o2) -> {
      if (o1[0] - o1[2] == o2[0] - o2[2]) return o1.hashCode() - o2.hashCode();
      return (o1[0] - o1[2]) - (o2[0] - o2[2]);
    });
    PriorityQueue<int[]> qy = new PriorityQueue<>((o1, o2) -> {
      if (o1[1] - o1[2] == o2[1] - o2[2]) return o1.hashCode() - o2.hashCode();
      return (o1[1] - o1[2]) - (o2[1] - o2[2]);
    });
    PriorityQueue<int[]> qny = new PriorityQueue<>((o1, o2) -> {
      if (o2[1] - o2[2] == o1[1] - o1[2]) return o1.hashCode() - o2.hashCode();
      return (o2[1] - o2[2]) - (o1[1] - o1[2]);
    });
    
    long now = 0;
    for (int i = 0; i < x; i ++) {
      qx.add(c[i]);
      now += c[i][0];
    }
    for (int i = x; i < n; i ++) {
      qy.add(c[i]);
      now += c[i][1];
      if (qy.size() > y) {
        int[] v = qy.poll();
        qny.add(v);
        now += -v[1] + v[2];
      }
    }
    long ret = now;

    for (int i = x; i < n - y; i ++) {
      qx.add(c[i]);
      int[] v = qx.poll();
      now += c[i][0] - v[0] + v[2];
      
      if (qy.contains(c[i])) {
        qy.remove(c[i]);
        int[] u = qny.poll();
        qy.add(u);
        now += u[1] - u[2] - c[i][1];
      } else {
        qny.remove(c[i]);
        now += -c[i][2];
      }
      
      ret = Math.max(ret, now);
    }
    System.out.println(ret);
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