import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;


public class Main {
  private static void solve() {
    int n = ni();
    int k = ni();
    int q = ni();
    int[] a = na(n);
    int[][] b = new int[n][2];
    for (int i = 0; i < n; i++) {
      b[i][0] = a[i];
      b[i][1] = i;
    }
    Arrays.sort(b, (o1, o2) -> o1[0] - o2[0]);
    int ret = Integer.MAX_VALUE;
    loop: for (int i = 0; i < n; i++) {
      boolean[] ok = new boolean[n];
      Arrays.fill(ok, true);
      int min = b[i][0];
      for (int j = 0; j < n; j++) {
        if (a[j] < min) {
          ok[j] = false;
        }
      }

      Map<int[], Integer> ptr = new HashMap<>();
      PriorityQueue<int[]> queue = new PriorityQueue<>((o1, o2) -> {
        if (o1[0] - o2[0] == 0)
          return o1.hashCode() - o2.hashCode();
        else
          return o1[ptr.get(o1)] - o2[ptr.get(o2)];
      });
      for (int s = 0; s < n;) {
        int e = s;
        for (; e < n && ok[e]; e++) {
        }
        if (e == s) {
          s ++;
          continue;
        }
        
        if (e - s >= k) {
          int[] arr = Arrays.copyOfRange(a, s, e);
          Arrays.sort(arr);
          ptr.put(arr, 0);
          queue.add(arr);
        }
        s = e;
      }

      int x = Integer.MAX_VALUE;
      int y = 0;
      for (int j = 0; j < q; j ++) {
        int[] v = queue.poll();
        if (v == null) {
          continue loop;
        }
        int p = ptr.get(v);
        x = Math.min(x, v[p]);
        y = Math.max(y, v[p]);
        
        if (v.length - p > k) {
          ptr.put(v, p + 1);
          queue.add(v);
        }
      }
      ret = Math.min(ret, y - x);
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