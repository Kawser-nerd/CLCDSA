import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;

/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass System Test!
*/

public class Main {
  private static class Task {
    final int MOD = (int) (1e9 + 7);
    void solve(FastScanner in, PrintWriter out) throws Exception {
      int N = in.nextInt();
      int M = in.nextInt();
      char[] S = in.next().toCharArray();

      int[] right = new int[N];
      Arrays.fill(right, -1);
      for (int i = 0; i < M; i++) {
        int l = in.nextInt() - 1;
        int r = in.nextInt() - 1;
        if (right[l] < r) right[l] = r;
      }
      int max = 0;
      for (int i = 0; i < N; i++) {
        max = Math.max(max, i);
        max = Math.max(max, right[i]);
        right[i] = max;
      }

      int[] sum = new int[N];
      for (int i = 0; i < N; i++) sum[i] = S[i] - '0';
      for (int i = 0; i < N - 1; i++) sum[i + 1] += sum[i];

      long[][] dp = new long[N + 1][N + 1];
      dp[0][0] = 1;
      for (int i = 0; i < N; i++) {
        //i??????????
        for (int usedOne = 0; usedOne < N; usedOne++) {
          int r = right[i];
          int restOne = sum[r] - usedOne;
          if (restOne < 0) continue;
          if (restOne > 0) {
            dp[i + 1][usedOne + 1] += dp[i][usedOne];
            if (dp[i + 1][usedOne + 1] >= MOD) dp[i + 1][usedOne + 1] -= MOD;
          }
          if (r - i + 1 != restOne) {
            dp[i + 1][usedOne] += dp[i][usedOne];
            if (dp[i + 1][usedOne] >= MOD) dp[i + 1][usedOne] -= MOD;
          }
        }
      }
      out.println(dp[N][sum[N - 1]]);
    }
  }

  /**
   * ???????????????
   */
  public static void main(String[] args) throws Exception {
    OutputStream outputStream = System.out;
    FastScanner in = new FastScanner();
    PrintWriter out = new PrintWriter(outputStream);
    Task solver = new Task();
    solver.solve(in, out);
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
      if (hasNextByte()) return buffer[ptr++];
      else return -1;
    }

    private static boolean isPrintableChar(int c) {
      return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
      while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
    }

    boolean hasNext() {
      skipUnprintable();
      return hasNextByte();
    }

    public String next() {
      if (!hasNext()) throw new NoSuchElementException();
      StringBuilder sb = new StringBuilder();
      int b = readByte();
      while (isPrintableChar(b)) {
        sb.appendCodePoint(b);
        b = readByte();
      }
      return sb.toString();
    }

    long nextLong() {
      if (!hasNext()) throw new NoSuchElementException();
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
      for (int i = 0; i < n; i++) array[i] = nextInt();
      return array;
    }

    public long[] nextLongArray(int n) {
      long[] array = new long[n];
      for (int i = 0; i < n; i++) array[i] = nextLong();
      return array;
    }

    public String[] nextStringArray(int n) {
      String[] array = new String[n];
      for (int i = 0; i < n; i++) array[i] = next();
      return array;
    }

    public char[][] nextCharMap(int n) {
      char[][] array = new char[n][];
      for (int i = 0; i < n; i++) array[i] = next().toCharArray();
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