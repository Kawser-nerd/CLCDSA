import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
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

    HashMap<Pair<Long, Long>, Long> d;
    HashMap<Pair<Long, Long>, Long>[][] od;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      long a = in.nextLong();
      long b = in.nextLong();
      long res = doSolve(a, b);
      out.printLine(res);
    }

    public long doSolve(long a, long b) {
      d = new HashMap<>();
      od = new HashMap[2][61];
      for (int i = 0; i < od.length; ++i) {
        for (int j = 0; j < od[i].length; ++j) {
          od[i][j] = new HashMap<>();
        }
      }
      return calc(a, b);
    }

    private long calc(long a, long b) {
      Assert.assertTrue(a <= b);
      if (a == b) {
        return 1;
      }
      Pair<Long, Long> key = new Pair<>(a, b);
      if (d.containsKey(key)) {
        return d.get(key);
      }
      int bit = 60;
      while ((a >> (long) bit) % 2L == (b >> (long) bit) % 2L) {
        --bit;
      }
      Assert.assertTrue(bit >= 0);
      long rest = (1L << (long) bit) - 1L;
      long na = a & rest;
      long nb = b & rest;
      long res = calc(na, rest);
      res += calc2(nb, na, bit, 0);
      d.put(key, res);
      return res;
    }

    private long calc2(long a, long b, int len, int must) {
      if (a >= b) {
        a = b;
      }

//        if (a >= b && must == 0) {
//            return 1L << (long) len;
//        }
      if (len == 0) {
        return 1L;
      }
      Pair<Long, Long> key = new Pair<>(a, b);
      if (od[must][len].containsKey(key)) {
        return od[must][len].get(key);
      }
      long res = 0;

      long bit1 = ((a >> (long) (len - 1)) % 2L);
      long bit2 = ((b >> (long) (len - 1)) % 2L);
      long part = 1L << (long) (len - 1);
      if (bit1 == bit2) {
        if (bit1 == 0) {
          res += part;
          res += calc2(a & (part - 1), b & (part - 1), len - 1, must);
        } else {
          if (must == 0) {
            res += part;
            res += part;
          } else {
            res += calc2(part - 1, b & (part - 1), len - 1, must);
          }
        }
      } else {
        Assert.assertTrue(bit1 < bit2);
        if (must == 0) {
          res += calc(0, a & (part - 1));
        }
        res += calc2(a & (part - 1), b & (part - 1), len - 1, 1);
      }

      od[must][len].put(key, res);
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

  static class Assert {

    public static void assertTrue(boolean flag) {
//        if (!flag)
//        while (true);
      if (!flag) {
        throw new AssertionError();
      }
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

    public long nextLong() {
      long sgn = 1;
      int c = readSkipSpace();
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      long res = 0;
      do {
        if (c < '0' || c > '9') {
          throw new InputMismatchException();
        }
        res = res * 10L + (long) (c - '0');
        c = read();
      } while (!isSpace(c));
      res *= sgn;
      return res;
    }

  }

  static class Pair<P, Q> {

    public P first;
    public Q second;

    public Pair() {
    }

    public Pair(P first, Q second) {
      this.first = first;
      this.second = second;
    }


    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }

      Pair pair = (Pair) o;

      if (first != null ? !first.equals(pair.first) : pair.first != null) {
        return false;
      }
      if (second != null ? !second.equals(pair.second) : pair.second != null) {
        return false;
      }

      return true;
    }


    public int hashCode() {
      int result = first != null ? first.hashCode() : 0;
      result = 31 * result + (second != null ? second.hashCode() : 0);
      return result;
    }

  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.