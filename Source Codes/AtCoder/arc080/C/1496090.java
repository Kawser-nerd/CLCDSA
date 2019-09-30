import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;


public class Main {
  private static final SegmentTreeRMQPos[] st = new SegmentTreeRMQPos[2];
  private static PriorityQueue<int[]> queue;

  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();
    int[] p = sc.nextIntList(N);

    st[0] = new SegmentTreeRMQPos(N);
    st[1] = new SegmentTreeRMQPos(N);

    queue = new PriorityQueue<>((o1, o2) -> o1[2] - o2[2]);
    
    for (int i = 0; i < N; i++) {
      st[i % 2].update(i, p[i]);
    }

    queue.add(new int[] {0, N, p[min(0, N)]});
    
    int[] ret = new int[N];
    int ptr = 0;
    while (queue.size() > 0) {
      int[] range = queue.poll();
      int left = min(range[0], range[1]);
      int right = min(left + 1, range[1]);
      
      ret[ptr ++] = p[left];
      ret[ptr ++] = p[right];
      
      int[] nl = {range[0], left + 1, right + 1};
      int[] nr = {left, right, range[1]};
      
      for (int i = 0; i < 3; i ++) {
        if (nl[i] < nr[i])
          queue.add(new int[] {nl[i], nr[i], p[min(nl[i], nr[i])]});
      }
    }
    
    StringBuilder sb = new StringBuilder();
    for (int v : ret) {
      sb.append(v);
      sb.append(" ");
    }
    System.out.println(sb.substring(0, sb.length() - 1));
  }
  
   private static int min(int left, int right) {
     int flg = left % 2;
    st[flg].min(left, right);
    
    return st[flg].minpos;
  }
}


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

  public int min(int l, int r) {
    minpos = -1;
    minval = Integer.MAX_VALUE;
    min(l, r, 0, H, 1);
    return minval;
  }

  private void min(int l, int r, int cl, int cr, int cur) {
    if (l <= cl && cr <= r) {
      if (st[cur] < minval) {
        minval = st[cur];
        minpos = pos[cur];
      }
    } else {
      int mid = cl + cr >>> 1;
      if (cl < r && l < mid)
        min(l, r, cl, mid, 2 * cur);
      if (mid < r && l < cr)
        min(l, r, mid, cr, 2 * cur + 1);
    }
  }
}


class FastScanner {
  public static String debug = null;

  private final InputStream in = System.in;
  private int ptr = 0;
  private int buflen = 0;
  private byte[] buffer = new byte[1024];
  private boolean eos = false;

  private boolean hasNextByte() {
    if (ptr < buflen) {
      return true;
    } else {
      ptr = 0;
      try {
        if (debug != null) {
          buflen = debug.length();
          buffer = debug.getBytes();
          debug = "";
          eos = true;
        } else {
          buflen = in.read(buffer);
        }
      } catch (IOException e) {
        e.printStackTrace();
      }
      if (buflen < 0) {
        eos = true;
        return false;
      } else if (buflen == 0) {
        return false;
      }
    }
    return true;
  }

  private int readByte() {
    if (hasNextByte())
      return buffer[ptr++];
    else
      return -1;
  }

  private static boolean isPrintableChar(int c) {
    return 33 <= c && c <= 126;
  }

  private void skipUnprintable() {
    while (hasNextByte() && !isPrintableChar(buffer[ptr]))
      ptr++;
  }

  public boolean isEOS() {
    return this.eos;
  }

  public boolean hasNext() {
    skipUnprintable();
    return hasNextByte();
  }

  public String next() {
    if (!hasNext())
      throw new NoSuchElementException();
    StringBuilder sb = new StringBuilder();
    int b = readByte();
    while (isPrintableChar(b)) {
      sb.appendCodePoint(b);
      b = readByte();
    }
    return sb.toString();
  }

  public long nextLong() {
    if (!hasNext())
      throw new NoSuchElementException();
    long n = 0;
    boolean minus = false;
    int b = readByte();
    if (b == '-') {
      minus = true;
      b = readByte();
    }
    if (b < '0' || '9' < b) {
      throw new NumberFormatException();
    }
    while (true) {
      if ('0' <= b && b <= '9') {
        n *= 10;
        n += b - '0';
      } else if (b == -1 || !isPrintableChar(b)) {
        return minus ? -n : n;
      } else {
        throw new NumberFormatException();
      }
      b = readByte();
    }
  }

  public int nextInt() {
    return (int) nextLong();
  }

  public long[] nextLongList(int n) {
    return nextLongTable(1, n)[0];
  }

  public int[] nextIntList(int n) {
    return nextIntTable(1, n)[0];
  }

  public long[][] nextLongTable(int n, int m) {
    long[][] ret = new long[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ret[i][j] = nextLong();
      }
    }
    return ret;
  }

  public int[][] nextIntTable(int n, int m) {
    int[][] ret = new int[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ret[i][j] = nextInt();
      }
    }
    return ret;
  }
}