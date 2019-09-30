import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

public class Main {

  private void solve(FastScanner in, PrintWriter out) {
    int N = in.nextInt();
    int M = in.nextInt();
    int Q = in.nextInt();
    int[][] map = new int[N][M];
    for (int i = 0; i < N; i++) {
      String S = in.next();
      for (int j = 0; j < M; j++) {
        map[i][j] = S.charAt(j) - '0';
      }
    }

    int[][] edgeV = new int[N][M];
    int[][] edgeH = new int[N][M];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (j + 1 < M) {
          edgeH[i][j] = map[i][j] == 1 && map[i][j + 1] == 1 ? 1 : 0;
        }
        if (i > 0) {
          edgeV[i][j] = map[i][j] == 1 && map[i - 1][j] == 1 ? 1 : 0;
        }
      }
    }

    CumulativeSum sum = new CumulativeSum(map);
    CumulativeSum sumV = new CumulativeSum(edgeV);
    CumulativeSum sumH = new CumulativeSum(edgeH);
    for (int q = 0; q < Q; q++) {
      int i1 = in.nextInt() - 1;
      int j1 = in.nextInt() - 1;
      int i2 = in.nextInt() - 1;
      int j2 = in.nextInt() - 1;
      int ans = sum.getSum(i1, j1, i2, j2);
      ans -= sumV.getSum(i1 + 1, j1, i2, j2);
      ans -= sumH.getSum(i1, j1, i2, j2 - 1);
      out.println(ans);
    }

  }

  public class CumulativeSum {

    int nx, ny;
    int[][] sum;

    CumulativeSum(final int[][] a) {
      ny = a.length;
      nx = a[0].length;
      sum = new int[ny + 1][nx + 1];
      for (int i = 0; i < ny; i++) {
        for (int j = 0; j < nx; j++) {
          sum[i + 1][j + 1] = a[i][j] + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
        }
      }
    }

    int getSum(int y1, int x1, int y2, int x2) {
      if (y1 > y2 || x1 > x2) {
        return 0;
      }
      y1 = Math.max(y1, 0);
      x1 = Math.max(x1, 0);
      y2 = Math.min(y2, ny - 1);
      x2 = Math.min(x2, nx - 1);
      return sum[y2 + 1][x2 + 1] - sum[y1][x2 + 1] - sum[y2 + 1][x1] + sum[y1][x1];
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

    public int loadChar(char[] buf) {
      if (!hasNext()) {
        throw new NoSuchElementException();
      }
      int pos = 0;
      int b = readByte();
      while (isPrintableChar(b)) {
        buf[pos] = (char) b;
        b = readByte();
        pos++;
      }
      return pos;
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