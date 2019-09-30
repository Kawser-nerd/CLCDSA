import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
    TaskE solver = new TaskE();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskE {

    static final int mod = 1000 * 1000 * 1000 + 7;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
      int[] a = new int[m + 1];
      for (int i = 0; i < m; ++i) {
        a[i] = in.nextInt();
      }
      a[m] = n;
//        // Stupid.
//        int[] d = new int[n + 1];
//        d[0] = 1;
//        for (int i = 1, t = 0; i <= n; ++i) {
//            while (t < m && a[t] < i) ++t;
//            if (t < m && a[t] == i) {
//                d[i] = 0;
//                continue;
//            }
//            for (int j = 0; j < i; ++j) {
//                long s = (((long) (i - j) * (long) (i - j)) % mod);
//                d[i] = (int)((d[i] + s * d[j]) % mod);
//            }
//        }
//        out.printLine(d[n]);

//        // Less stupid.
//        long sum2 = 0, sum1 = 0, sum0 = 0;
//        sum0 += 1;
//        sum1 += 1;
//        sum2 += 1;
//        long di = 1;
//        for (int i = 1, t = 0; i <= n; ++i) {
//            while (t < m && a[t] < i) ++t;
//            if (t < m && a[t] == i) {
//                di = 0;
//            } else {
//                di = sum2;
//            }
//            sum2 = (sum2 + 2L * sum1 + sum0 + di);
//            sum1 = (sum1 + sum0 + di);
//            sum0 = (sum0 + di);
//            if (sum2 > BUBEN) sum2 %= mod;
//            if (sum1 > BUBEN) sum1 %= mod;
//            if (sum0 > BUBEN) sum0 %= mod;
//        }
//        di %= mod;
//        out.printLine(di);

      // Smart.
      Matrix trans = new Matrix(3);
      trans.a[0][0] = 1;
      trans.a[0][2] = 1;
      trans.a[1][0] = 1;
      trans.a[1][1] = 1;
      trans.a[1][2] = 1;
      trans.a[2][0] = 1;
      trans.a[2][1] = 2;
      trans.a[2][2] = 2;
      long sum2 = 0, sum1 = 0, sum0 = 0;
      sum0 += 1;
      sum1 += 1;
      sum2 += 1;
      long di = 1;
//        for (int i = 1, t = 0; i <= n; ++i) {
//            while (t < m && a[t] < i) ++t;
//            if (t < m && a[t] == i) {
//                di = 0;
//                sum2 = (sum2 + 2L * sum1 + sum0 + di);
//                sum1 = (sum1 + sum0 + di);
//                sum0 = (sum0 + di);
//                sum2 %= mod;
//                sum1 %= mod;
//                sum0 %= mod;
//            } else {
//                di = sum2;
//                long[] sums = trans.multiply(new long[]{sum0, sum1, sum2}, mod);
//                sum0 = sums[0];
//                sum1 = sums[1];
//                sum2 = sums[2];
//            }
//        }

      int t = 0;
      int prev = 0;
      for (int i : a) {
        while (t < m && a[t] < i) {
          ++t;
        }
        {
          long[] sums = trans.pow(i - prev - 1, mod)
              .multiply(new long[]{sum0, sum1, sum2}, mod);
          sum0 = sums[0];
          sum1 = sums[1];
          sum2 = sums[2];
        }
        prev = i;
        if (t < m && a[t] == i) {
          di = 0;
          sum2 = (sum2 + 2L * sum1 + sum0 + di);
          sum1 = (sum1 + sum0 + di);
          sum0 = (sum0 + di);
          sum2 %= mod;
          sum1 %= mod;
          sum0 %= mod;
        } else {
          di = sum2;
          long[] sums = trans.multiply(new long[]{sum0, sum1, sum2}, mod);
          sum0 = sums[0];
          sum1 = sums[1];
          sum2 = sums[2];
        }
      }

      di %= mod;
      out.printLine(di);
    }

  }

  static class Matrix {

    public long[][] a;

    public Matrix(int n) {
      a = new long[n][n];
    }

    public Matrix(int n, int m) {
      a = new long[n][m];
    }

    public static Matrix uni(int n) {
      Matrix res = new Matrix(n);
      for (int i = 0; i < n; ++i) {
        res.a[i][i] = 1;
      }
      return res;
    }

    public Matrix multiply(Matrix b, int mod) {
      Matrix res = new Matrix(a.length);
      for (int i = 0; i < a.length; ++i) {
        for (int j = 0; j < a.length; ++j) {
          for (int k = 0; k < a.length; ++k) {
            res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
          }
        }
      }
      return res;
    }

    public long[] multiply(long[] v, long mod) {
      long[] res = new long[a.length];
      for (int i = 0; i < a.length; ++i) {
        for (int j = 0; j < a.length; ++j) {
          res[i] = ((res[i] + a[i][j] * (long) v[j]) % mod);
        }
      }
      return res;
    }

    public Matrix pow(long y, int mod) {
      Matrix res = Matrix.uni(a.length);
      Matrix x = this;
      while (y > 0) {
        if (y % 2L == 0) {
          x = x.multiply(x, mod);
          y /= 2L;
        } else {
          res = res.multiply(x, mod);
          --y;
        }
      }
      return res;
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