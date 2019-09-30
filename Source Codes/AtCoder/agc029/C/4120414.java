import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
  private static void solve() {
    int n = ni();
    long[] a = nal(n);
    
    int ok = 100000000;
    int ng = -1;
    while (ok - ng > 1) {
      int k = (ok + ng) / 2;
      if (check(a, k)) {
        ok = k;
      } else {
        ng = k;
      }
    }
    System.out.println(ok + 1);
  }


  private static boolean check(long[] a, long k) {
    int n = a.length;
    Deque<long[]> q = new ArrayDeque<>();
    long len = 0;
    for (int i = 0; i < n; i ++) {
      if (a[i] > len) {
        if (q.size() > 0) {
          if (q.peekLast()[0] == 0) {
            q.peekLast()[1] += a[i] - len;
          } else {
            q.add(new long[] {0, a[i] - len});
          }
        } else {
          q.add(new long[] {0, a[i]});
        }
      } else {
        long d = len - a[i];
        while (d > 0) {
          long[] now = q.peekLast();
          if (now[1] <= d) {
            q.pollLast();
            d -= now[1];
          } else {
            now[1] -= d;
            d = 0;
          }
        }
        
        long y = 0;
        while (q.size() > 0 && q.peekLast()[0] == k) {
          y += q.pollLast()[1];
        }
        if (q.size() == 0) {
          return false;
        }
        
        long[] now = q.peekLast();
        now[1] --;
        if (now[1] == 0) {
          q.pollLast();
        }
        q.add(new long[] {now[0] + 1, 1});
        if (y > 0) q.add(new long[] {0, y});
      }
      len = a[i];
    }
    return true;
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