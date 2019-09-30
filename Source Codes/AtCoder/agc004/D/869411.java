import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
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
    int solve(int K, int[] a) {
      int N = a.length;
      int ans = 0;
      ArrayList<Integer>[] graph = new ArrayList[N];
      for (int i = 0; i < N; i++) graph[i] = new ArrayList<>();
      if (a[0] != 0) ans++;
      for (int i = 1; i < N; i++) {
        graph[a[i]].add(i);
      }

      ArrayDeque<Integer> stack = new ArrayDeque<>();
      boolean[] vis = new boolean[N];
      int[] heights = new int[N];
      stack.addFirst(0);
      while (!stack.isEmpty()) {
        int v = stack.peekFirst();
        if (!vis[v]) {
          for (int u : graph[v]) {
            stack.addFirst(u);
          }
          vis[v] = true;
        } else {
          int height = 0;
          for (int u : graph[v]) {
            int cur = heights[u] + 1;
            if (cur == K && v != 0) ans++;
            else height = Math.max(cur, height);
          }
          heights[v] = height;
          stack.pollFirst();
        }
      }
      return ans;
    }

    void solve(FastScanner in, PrintWriter out) {
      int N = in.nextInt();
      int K = in.nextInt();
      int[] a = new int[N];
      for (int i = 0; i < N; i++) {
        a[i] = in.nextInt() - 1;
      }
      out.println(solve(K, a));
    }
  }

  /**
   * ???????????????
   */
  public static void main(String[] args) {
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
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.