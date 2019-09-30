import java.util.Arrays;

class SegmentTreeRMQPos {
  public int M, H, N;
  public int[] st;
  public int[] pos;

  public SegmentTreeRMQPos(int n) {
    N = n;
    M = Integer.highestOneBit(Math.max(N - 1, 1)) << 2;
    H = M >>> 1;
    st = new int[M];
    pos = new int[M];
    for (int i = 0; i < N; i++)
      pos[H + i] = i;
    Arrays.fill(st, 0, M, Integer.MAX_VALUE);
    for (int i = H - 1; i >= 1; i--)
      propagate(i);
  }

  public SegmentTreeRMQPos(int[] a) {
    N = a.length;
    M = Integer.highestOneBit(Math.max(N - 1, 1)) << 2;
    H = M >>> 1;
    st = new int[M];
    pos = new int[M];
    for (int i = 0; i < N; i++) {
      st[H + i] = a[i];
      pos[H + i] = i;
    }
    Arrays.fill(st, H + N, M, Integer.MAX_VALUE);
    for (int i = H - 1; i >= 1; i--)
      propagate(i);
  }

  public void update(int pos, int x) {
    st[H + pos] = x;
    for (int i = (H + pos) >>> 1; i >= 1; i >>>= 1)
      propagate(i);
  }

  private void propagate(int i) {
    if (st[2 * i] <= st[2 * i + 1]) {
      st[i] = st[2 * i];
      pos[i] = pos[2 * i];
    } else {
      st[i] = st[2 * i + 1];
      pos[i] = pos[2 * i + 1];
    }
  }

  public int minpos;
  public int minval;

  public int minx(int l, int r) {
    minval = Integer.MAX_VALUE;
    minpos = -1;
    if (l >= r)
      return minval;
    while (l != 0) {
      int f = l & -l;
      if (l + f > r)
        break;
      int v = st[(H + l) / f];
      if (v < minval) {
        minval = v;
        minpos = pos[(H + l) / f];
      }
      l += f;
    }

    while (l < r) {
      int f = r & -r;
      int v = st[(H + r) / f - 1];
      if (v < minval) {
        minval = v;
        minpos = pos[(H + r) / f - 1];
      }
      r -= f;
    }
    return minval;
  }
}


public class Main {


  private static void solve() {
    int n = ni();
    int m = ni();

    int[] a = na(n - 1);
    int[][] b = ntable(n, m);
    long[][] imos = new long[n + 1][n + 1];

    SegmentTreeRMQPos st = new SegmentTreeRMQPos(n);
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        st.update(i, -b[i][j]);
      }
      rec(imos, 0, n, st);
    }
    sum(imos);

    long ret = Long.MIN_VALUE;
    for (int min = 0; min < n; min++) {
      long len = 0;
      for (int max = min; max < n; max++) {
        long now = imos[min][max] - len;
        if (max < n - 1) {
          len += a[max];
        }
        ret = Math.max(ret, now);
      }
    }
    System.out.println(ret);
  }

  private static void sum(long[][] imos) {
    int n = imos.length - 1;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < n; j++) {
        imos[i][j] += imos[i][j - 1];
      }
    }

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        imos[i][j] += imos[i - 1][j];
      }
    }
  }

  private static void rec(long[][] imos, int left, int right, SegmentTreeRMQPos st) {
    if (left >= right)
      return;
    st.minx(left, right);
    int opt = st.minpos;

    int y1 = left;
    int x1 = opt;
    int y2 = opt + 1;
    int x2 = right;
    int v = -st.minval;
    imos[y1][x1] += v;
    imos[y2][x1] += -v;
    imos[y1][x2] += -v;
    imos[y2][x2] += v;

    rec(imos, opt + 1, right, st);
    rec(imos, left, opt, st);
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