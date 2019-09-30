import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

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

    void dfs(int cur, int pos, int[] num, int[] cnt, TreeSet<Integer> set) {
      if (pos == num.length) {
        set.add(cur);
        return;
      }
      dfs(cur, pos + 1, num, cnt, set);
      for (int i = 0; i < cnt[pos]; i++) {
        cur *= num[pos];
        dfs(cur, pos + 1, num, cnt, set);
      }
    }

    ArrayList<Integer> divisors(int N) {
      TreeMap<Integer, Integer> map = new TreeMap<>();
      for (long i = 2; i * i <= N; i++) {
        if (N % i != 0) continue;
        int count = 0;
        while (N % i == 0) {
          N /= i;
          count++;
        }
        map.put((int) i, count);
      }
      if (N != 1) map.put(N, 1);
      int[] num = new int[map.size()];
      int[] cnt = new int[map.size()];
      int i = 0;
      for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
        num[i] = entry.getKey();
        cnt[i] = entry.getValue();
        i++;
      }
      TreeSet<Integer> ret = new TreeSet<>();
      dfs(1, 0, num, cnt, ret);
      ArrayList<Integer> list = new ArrayList<>();
      for (int r : ret) list.add(r);
      return list;
    }

    public static long modPow(long x, long e, long MOD) {
      long ret = 1;
      long cur = x;
      while (e > 0) {
        if ((e & 1) != 0) ret = (ret * cur) % MOD;
        cur = (cur * cur) % MOD;
        e /= 2;
      }
      return ret;
    }
    void solve(FastScanner in, PrintWriter out) throws Exception {
      int MOD = (int) (1e9 + 7);
      int N = in.nextInt();
      long K = in.nextInt();
      if (N == 1) {
        out.println(K);
        return;
      }

      ArrayList<Integer> divisors = divisors(N);
      Collections.sort(divisors);

      long[] num = new long[divisors.size()];
      for (int i = 0; i < num.length; i++) {
        num[i] = modPow(K, (divisors.get(i) + 1) / 2, MOD);
        for (int j = 0; j < i; j++) {
          if (divisors.get(i) % divisors.get(j) == 0) {
            num[i] -= num[j];
            if (num[i] <= 0) num[i] += MOD;
          }
        }
      }

      long ans = 0;
      for (int i = 0; i < num.length; i++) {
        long d = divisors.get(i);
        if (d % 2 == 0) d /= 2;
        ans += num[i] * d;
        ans %= MOD;
      }
      out.println(ans);
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