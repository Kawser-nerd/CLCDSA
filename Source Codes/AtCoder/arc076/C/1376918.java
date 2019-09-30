import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {

  class Pair {

    private final int x1, y1, x2, y2;

    Pair(int x1, int y1, int x2, int y2) {
      this.x1 = x1;
      this.y1 = y1;
      this.x2 = x2;
      this.y2 = y2;
    }
  }

  class Edge {

    final long from, to;

    Edge(long from, long to) {
      this.from = from;
      this.to = to;
    }
  }

  private int R, C;

  private void solve(FastScanner in, PrintWriter out) {
    R = in.nextInt();
    C = in.nextInt();
    int N = in.nextInt();

    ArrayList<Edge> edges = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      Pair pair = new Pair(in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt());
      if (onBorder(pair.x1, pair.y1) && onBorder(pair.x2, pair.y2)) {
        long c1 = convert(pair.x1, pair.y1);
        long c2 = convert(pair.x2, pair.y2);

        long l = Math.max(c1, c2);
        long s = Math.min(c1, c2);

        Edge edge = new Edge(s, l);
        edges.add(edge);
      }
    }

    edges.sort((o1, o2) -> Long.signum(o1.from - o2.from));

    ArrayDeque<Long> stop = new ArrayDeque<>();
    for (Edge edge : edges) {
      while (!stop.isEmpty() && stop.peekFirst() < edge.from) {
        stop.pollFirst();
      }
      if (!stop.isEmpty() && stop.peekFirst() < edge.to) {
        out.println("NO");
        return;
      }
      stop.addFirst(edge.to);
    }

    out.println("YES");
  }

  private long convert(long x, long y) {
    if (y == 0) {
      return x;
    }
    if (x == R) {
      return R + y;
    }
    if (y == C) {
      return R + C + (R - x);
    }
    return R + C + R + (C - y);
  }

  private boolean onBorder(int x, int y) {
    return (x == 0 || x == R) || (y == 0 || y == C);

  }

  class UnionFind {

    // par[i]????i???????????i == par[i]???????i??????????
    private int[] par;
    // sizes[i]?????i?????????????i???????????????????
    private int[] sizes;

    // ???
    private int size;

    UnionFind(int n) {
      par = new int[n];
      sizes = new int[n];
      size = n;
      Arrays.fill(sizes, 1);
      // ?????????i?????i?????????????
      for (int i = 0; i < n; i++) {
        par[i] = i;
      }
    }

    /**
     * ???x??????????
     */
    int find(int x) {
      if (x == par[x]) {
        return x;
      }
      return par[x] = find(par[x]);  // ????????????????????
    }

    /**
     * 2?????x, y????????????
     * ???????? true ???
     */
    boolean unite(int x, int y) {
      // ???????????
      x = find(x);
      y = find(y);

      // ???????????????????
      if (x == y) {
        return false;
      }

      // x???y??????????????
      if (sizes[x] < sizes[y]) {
        int tx = x;
        x = y;
        y = tx;
      }

      // x?y????????????
      par[y] = x;
      sizes[x] += sizes[y];
      sizes[y] = 0;  // sizes[y]???????????0??????????

      size--;
      return true;
    }

    /**
     * 2?????x, y??????????true???
     */
    boolean isSame(int x, int y) {
      return find(x) == find(y);
    }

    /**
     * ???x?????????????
     */
    int partialSizeOf(int x) {
      return sizes[find(x)];
    }

    /**
     * ??????
     */
    int size() {
      return size;
    }
  }

  public static void main(String[] args) {
    PrintWriter out = new PrintWriter(System.out);
    new Main().solve(new FastScanner(), out);
    out.close();
  }

  private static class FastScanner {

    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int bufferLength = 0;

    private boolean hasNextByte() {
      if (ptr < bufferLength) {
        return true;
      } else {
        ptr = 0;
        try {
          bufferLength = in.read(buffer);
        } catch (IOException e) {
          e.printStackTrace();
        }
        if (bufferLength <= 0) {
          return false;
        }
      }
      return true;
    }

    private int readByte() {
      if (hasNextByte()) {
        return buffer[ptr++];
      } else {
        return -1;
      }
    }

    private static boolean isPrintableChar(int c) {
      return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
      while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
        ptr++;
      }
    }

    boolean hasNext() {
      skipUnprintable();
      return hasNextByte();
    }

    public String next() {
      if (!hasNext()) {
        throw new NoSuchElementException();
      }
      StringBuilder sb = new StringBuilder();
      int b = readByte();
      while (isPrintableChar(b)) {
        sb.appendCodePoint(b);
        b = readByte();
      }
      return sb.toString();
    }

    long nextLong() {
      if (!hasNext()) {
        throw new NoSuchElementException();
      }
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

    double nextDouble() {
      return Double.parseDouble(next());
    }

    double[] nextDoubleArray(int n) {
      double[] array = new double[n];
      for (int i = 0; i < n; i++) {
        array[i] = nextDouble();
      }
      return array;
    }

    double[][] nextDoubleMap(int n, int m) {
      double[][] map = new double[n][];
      for (int i = 0; i < n; i++) {
        map[i] = nextDoubleArray(m);
      }
      return map;
    }

    public int nextInt() {
      return (int) nextLong();
    }

    public int[] nextIntArray(int n) {
      int[] array = new int[n];
      for (int i = 0; i < n; i++) {
        array[i] = nextInt();
      }
      return array;
    }

    public long[] nextLongArray(int n) {
      long[] array = new long[n];
      for (int i = 0; i < n; i++) {
        array[i] = nextLong();
      }
      return array;
    }

    public String[] nextStringArray(int n) {
      String[] array = new String[n];
      for (int i = 0; i < n; i++) {
        array[i] = next();
      }
      return array;
    }

    public char[][] nextCharMap(int n) {
      char[][] array = new char[n][];
      for (int i = 0; i < n; i++) {
        array[i] = next().toCharArray();
      }
      return array;
    }

    public int[][] nextIntMap(int n, int m) {
      int[][] map = new int[n][];
      for (int i = 0; i < n; i++) {
        map[i] = nextIntArray(m);
      }
      return map;
    }
  }
}