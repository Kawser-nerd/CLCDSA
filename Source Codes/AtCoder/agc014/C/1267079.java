import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

public class Main {


  class State implements Comparable<State> {

    final int x, y;
    int breaking;
    int magic;

    State(int x, int y, int breaking, int magic) {
      if (breaking < 0) {
        throw new IllegalArgumentException();
      }
      this.x = x;
      this.y = y;
      this.breaking = breaking;
      this.magic = magic;
    }

    @Override
    public int compareTo(State o) {
      if (this.magic == o.magic) {
        return o.breaking - this.breaking;
      }
      return this.magic - o.magic;
    }
  }

  private final int[] Dx = new int[]{-1, 1, 0, 0};
  private final int[] Dy = new int[]{0, 0, -1, 1};
  private final int INF = Integer.MAX_VALUE / 10;

  private int[][] firstBfs(int sx, int sy, char[][] maze) {
    int H = maze.length;
    int W = maze[0].length;

    int[][] dist = new int[H][W];
    for (int[] d : dist) {
      Arrays.fill(d, INF);
    }

    ArrayDeque<int[]> deque = new ArrayDeque<>();
    deque.add(new int[]{sx, sy});
    dist[sx][sy] = 0;
    while (!deque.isEmpty()) {
      int[] q = deque.poll();
      int x = q[0];
      int y = q[1];

      for (int d = 0; d < 4; d++) {
        int nx = x + Dx[d];
        int ny = y + Dy[d];
        if (nx < 0 || ny < 0 || nx == H || ny == W) {
          continue;
        }

        if (maze[nx][ny] == '#') {
          continue;
        }
        if (dist[nx][ny] <= dist[x][y] + 1) {
          continue;
        }

        dist[nx][ny] = dist[x][y] + 1;
        deque.add(new int[]{nx, ny});
      }
    }
    return dist;
  }

  private boolean goal(int h, int w, int H, int W) {
    return h == 0 || h == H - 1 || w == 0 || w == W - 1;
  }

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

    int[][] magic = new int[H][W];
    for (int[] d : magic) {
      Arrays.fill(d, INF);
    }

    int[][] first = firstBfs(si, sj, maze);

    PriorityQueue<State> queue = new PriorityQueue<>();
    for (int h = 0; h < H; h++) {
      for (int w = 0; w < W; w++) {
        if (first[h][w] > K) {
          continue;
        }

        if (goal(h, w, H, W)) {
          out.println(1);
          return;
        }

        magic[h][w] = 1;
        queue.add(new State(h, w, K, 2));
      }
    }

    while (!queue.isEmpty()) {
      State state = queue.poll();

      if (goal(state.x, state.y, H, W)) {
        out.println(state.magic);
        return;
      }

      if (state.breaking == 0) {
        state.magic++;
        state.breaking = K;
        queue.add(state);
        continue;
      }

      for (int d = 0; d < 4; d++) {
        int nx = state.x + Dx[d];
        int ny = state.y + Dy[d];

        if (magic[nx][ny] > state.magic) {
          magic[nx][ny] = state.magic;
          queue.add(new State(nx, ny, state.breaking - 1, state.magic));
        }
      }
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