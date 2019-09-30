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
    TaskD solver = new TaskD();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskD {

    int n;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      n = in.nextInt();
      int[] a = new int[n];
      for (int i = 0; i < n; ++i) {
        a[i] = in.nextInt();
      }
      if (n == 1) {
        out.printLine(a[0] % 2 == 1 ? "Second" : "First");
        return;
      }
      int s = superScore(a);
      if (s == 1) {
        out.printLine("First");
      } else {
        out.printLine("Second");
      }
    }

    int superScore(int[] a) {
      int s = score(a);
      if (s == 1) {
        return s;
      } else if (s == -1) {
        return s;
      }
      int ind = 0;
      while (a[ind] % 2 == 0 || a[ind] == 1) {
        ++ind;
      }
      --a[ind];
      int g = 0;
      for (int i = 0; i < n; ++i) {
        g = IntegerUtils.gcd(g, a[i]);
      }
      for (int i = 0; i < n; ++i) {
        a[i] /= g;
      }
      return -superScore(a);
    }

    int score(int[] a) {
      int cnt0 = 0, cnt1 = 0, cntRealOne = 0;
      for (int x : a) {
        if (x % 2 == 0) {
          ++cnt0;
        } else {
          ++cnt1;
        }
        if (x == 1) {
          ++cntRealOne;
        }
      }
      if (cnt0 % 2 == 1) {
        return 1;
      }
      if (cnt1 > 1) {
        return -1;
      }
      if (cntRealOne >= 1) {
        return -1;
      }
      return 0;
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

  static class IntegerUtils {

    public static int gcd(int x, int y) {
      if (y == 0) {
        return x;
      }
      return gcd(y, x % y);
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