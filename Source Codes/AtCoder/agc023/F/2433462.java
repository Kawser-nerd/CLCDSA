import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;




public class Main {
  static Comparator<long[]> cmp = (o1, o2) -> {
    long x = f(o1, o2);
    if (x == 0) {
      return Long.compare(o1[3], o2[3]);
    } else {
      return Long.compare(x, 0);
    }
  };

  private static int f(long[] o1, long[] o2) {
    return Long.compare(o2[0] * o1[1],  o2[1] * o1[0]);
  }

  private static void solve() {
    int n = ni();
    int[] p = new int[n];

    for (int i = 1; i < n; i++) {
      p[i] = ni() - 1;
    }
    int[] v = na(n);
    
    List<PriorityQueue<long[]>> qa = new ArrayList<>();
    for (int i = 0; i < n; i ++) {
      qa.add(new PriorityQueue<long[]>(cmp));
    }
    
    for (int i = n - 1; i >= 0; i --) {
      long[] e = {0, 0, 0, i};
      e[v[i]] ++;
      
      PriorityQueue<long[]> q = qa.get(i);
      PriorityQueue<long[]> qp = qa.get(p[i]);

      while (!q.isEmpty() && f(q.peek(), e) < 0) {
        long[] f = q.poll();
        e[2] += f[2] + f[0] * e[1];
        e[0] += f[0];
        e[1] += f[1];
      }
      q.add(e);
      
      if (i > 0) {
        if (q.size() > qa.get(p[i]).size()) {
          qa.set(i, qp);
          qa.set(p[i], q);
          PriorityQueue<long[]> tmp = q;
          q = qp;
          qp = tmp;
        }
        for (long[] x : q) {
          qp.add(x);
        }
        q.clear();
      }
    }

    long[] s = {0, 0, 0};
    while(qa.get(0).size() > 0) {
      long[] x = qa.get(0).poll();
      s[2] += x[2] + s[1] * x[0];
      s[1] += x[1];
      s[0] += x[0];
    }
    System.out.println(s[2]);
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