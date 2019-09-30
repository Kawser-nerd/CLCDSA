import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {

  private final int[] Di = new int[]{-1, 1, 0, 0};
  private final int[] Dj = new int[]{0, 0, -1, 1};

  private void solve(FastScanner in, PrintWriter out) {
    int H = in.nextInt();
    int W = in.nextInt();
    int K = in.nextInt();
    char[][] maze = new char[H][];
    for (int i = 0; i < H; i++) {
      maze[i] = in.next().toCharArray();
    }

    int si = -1, sj = -1;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (maze[i][j] == 'S') {
          si = i;
          sj = j;
        }
      }
    }

    int[][] dist = new int[H][W];
    for (int[] d : dist) {
      Arrays.fill(d, 10000000);
    }

    ArrayDeque<int[]> deque = new ArrayDeque<>();
    dist[si][sj] = 0;
    deque.add(new int[]{si, sj});
    while (!deque.isEmpty()) {
      int[] q = deque.poll();
      int i = q[0];
      int j = q[1];

      for (int d = 0; d < 4; d++) {
        int ni = i + Di[d];
        int nj = j + Dj[d];

        if (ni < 0 || ni == H || nj < 0 || nj == W) {
          continue;
        }
        if (maze[ni][nj] == '#') {
          continue;
        }
        if (dist[ni][nj] > dist[i][j] + 1) {
          dist[ni][nj] = dist[i][j] + 1;
          deque.add(new int[]{ni, nj});
        }
      }
    }

    int ans = Integer.MAX_VALUE;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (dist[i][j] > K) {
          continue;
        }

        int h = Math.min(i, H - 1 - i);
        int w = Math.min(j, W - 1 - j);
        int magic = (Math.min(h, w) + K - 1) / K + 1;
        ans = Math.min(ans, magic);
      }
    }

    out.println(ans);
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