import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ilyakor
 */
public class Main {

  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    OutputWriter out = new OutputWriter(outputStream);
    TaskD solver = new TaskD();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskD {

    static final int mod = 1000 * 1000 * 1000 + 7;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
      int[] dn = calc(n, m);
      int[] dn1 = calc(n - 1, m);
      int res = 0;
      for (int x : dn) {
        res = (res + x) % mod;
      }
      for (int x : dn1) {
        res = (res - x) % mod;
      }
      res = (res % mod + mod) % mod;
      out.printLine(res);
    }

    private int[] calc(int n, int m) {
      int[][] d = new int[2][n + 1];
      for (int i = 0; i <= n; ++i) {
        d[0][i] = 1;
      }
      for (int i = 0; i < m; ++i) {
        int[] cur = d[i % 2];
        int[] next = d[(i + 1) % 2];
        Arrays.fill(next, 0);
        for (int j = 0; j <= n; ++j) {
          for (int c1 = 0; c1 < 2; ++c1) {
            int t0 = j, t1 = n - j;
            if (c1 == 0) {
              --t0;
            } else {
              --t1;
            }
            if (t0 < 0 || t1 < 0) {
              continue;
            }
            for (int c2 = 0; c2 < 2; ++c2) {
              int tt0 = t0, tt1 = t1;
              if (c2 == 0) {
                --tt0;
              } else {
                --tt1;
              }
              tt0 += 1;
              tt1 += 1;
              if (tt0 < 0 || tt1 < 0 || tt0 + tt1 != n) {
                throw new RuntimeException();
              }
              next[tt0] += cur[j];
              next[tt0] %= mod;
            }
          }
        }
      }
      return d[m % 2];
    }

  }

  static class InputReader {

    private InputStream stream;
    private byte[] buffer = new byte[10000];
    private int cur;
    private int count;

    public InputReader(InputStream stream) {
      this.stream = stream;
    }

    public static boolean isSpace(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public int read() {
      if (count == -1) {
        throw new InputMismatchException();
      }
      try {
        if (cur >= count) {
          cur = 0;
          count = stream.read(buffer);
          if (count <= 0) {
            return -1;
          }
        }
      } catch (IOException e) {
        throw new InputMismatchException();
      }
      return buffer[cur++];
    }

    public int readSkipSpace() {
      int c;
      do {
        c = read();
      } while (isSpace(c));
      return c;
    }

    public int nextInt() {
      int sgn = 1;
      int c = readSkipSpace();
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      int res = 0;
      do {
        if (c < '0' || c > '9') {
          throw new InputMismatchException();
        }
        res = res * 10 + c - '0';
        c = read();
      } while (!isSpace(c));
      res *= sgn;
      return res;
    }

  }

  static class OutputWriter {

    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
      writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
      this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
      for (int i = 0; i < objects.length; i++) {
        if (i != 0) {
          writer.print(' ');
        }
        writer.print(objects[i]);
      }
    }

    public void printLine(Object... objects) {
      print(objects);
      writer.println();
    }

    public void close() {
      writer.close();
    }

  }
}