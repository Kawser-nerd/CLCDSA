import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class Main {

  private static void solve() {
    int n = ni();
    
    PriorityQueue<int[]> q = new PriorityQueue<>((o1, o2) -> {
      return o2[1] == o1[1] ? o1[0] - o2[0] : o2[1] - o1[1];
    });

    int[][] work = new int[n][3];
    for (int i = 0; i < n; i ++) {
      work[i][0] = i;
      work[i][1] = ni();
      work[i][2] = ni();
      q.add(work[i]);
    }
    
    int count = 0;
    int[] now = {-1, Integer.MAX_VALUE, Integer.MAX_VALUE};
    List<Integer> list = new ArrayList<>();
    while (q.size() > 0) {
      while (q.size() > 0 && q.peek()[2] > now[1]) {
        q.poll();
      }
      if (q.size() > 0) {
        now = q.poll();
        list.add(now[0]);
        count ++;
      }
    }
    Collections.reverse(list);
    list.add(-1);

    PriorityQueue<int[]> q2 = new PriorityQueue<>((o1, o2) -> {
      return o1[2] == o2[2] ? o1[0] - o2[0] : o1[2] - o2[2];
    });
    for (int[] v : work) q2.add(v);
    
    int[] ret = new int[count];
    int ptr = 0;
    for (int i = 0; i < count; i ++) {
      int next = list.get(i + 1);
      int min = Integer.MAX_VALUE;
      
      while (q2.size() > 0 && (next < 0 || q2.peek()[2] <= work[next][1])) {
        int[] v = q2.poll();
        if (ptr == 0 || v[1] >= work[ret[ptr - 1]][2]) {
          min = Math.min(min, v[0]);
        }
      }
      ret[ptr ++] = min;
    }
    
    out.println(count);
    int i = 0;
    for (int v : ret) {
      i ++;
      out.print(v + 1);
      if (i < count) out.print(" ");
    }
    out.println();
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