import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;


public class Main {

  private int LARGE = 100000000;
  private int H, W, h, w;


  private int[][] solve1() {
    int[][] matrix = new int[H][W];
    for (int[] row : matrix) {
      Arrays.fill(row, 1);
    }
    for (int i = h - 1; i < H; i += h) {
      for (int j = 0; j < W; j += w) {
        matrix[i][j] = LARGE + 1;
      }
    }
    for (int i = h - 1; i < H; i += h) {
      for (int j = w - 1; j < W; j += w) {
        matrix[i][j] = -h * w - LARGE;
      }
    }

    return matrix;
  }

  private int[][] solve2() {
    int hw = 10000000;
    int[][] matrix = new int[H][W];
    for (int i = h - 1; i < H; i += h) {
      for (int j = w - 1; j < W; j += w) {
        matrix[i][j] = -hw;
      }
    }
    for (int i = 0; i < H; i += h) {
      for (int j = 0; j < W; j += w) {
        matrix[i][j] = hw - 1;
      }
    }

    return matrix;
  }

  private void solve(FastScanner in, PrintWriter out) {
    H = in.nextInt();
    W = in.nextInt();
    h = in.nextInt();
    w = in.nextInt();
    if (H % h == 0 && W % w == 0) {
      out.println("No");
      return;
    }

    int[][] matrix = solve1();
    if (check(matrix)) {
      print(out, matrix);
      return;
    }

    matrix = solve2();
    if (check(matrix)) {
      print(out, matrix);
      return;
    }
    out.println("No");
  }

  private boolean check(int[][] matrix) {

    long sum = 0;
    for (int[] row : matrix) {
      for (int x : row) {
        sum += x;
      }
    }
    return sum > 0;
  }

  private void print(PrintWriter out, int[][] matrix) {
    out.println("Yes");
    for (int[] row : matrix) {
      for (int x : row) {
        out.print(x + " ");
      }
      out.println();
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