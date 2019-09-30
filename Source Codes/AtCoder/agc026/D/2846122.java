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
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
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
    int n;
    int[] h;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      n = in.nextInt();
      h = new int[n + 1];
      for (int i = 0; i < n; ++i) {
        h[i] = in.nextInt();
      }
      h[n] = 1;

      // long[][] d = new long[n + 1][];
      // d[n] = new long[]{1};
      // for (int i = n - 1; i >= 0; --i) {
      //     d[i] = new long[h[i]];
      //     int rem = h[i] - h[i + 1];
      //     if (rem <= 0) {
      //         for (int j = 0; j < h[i + 1]; ++j) {
      //             if (j < h[i + 1] - 1 && j < h[i] - 1) {
      //                 d[i][j] += d[i + 1][j];
      //                 d[i][j] %= mod;
      //             } else {
      //                 d[i][h[i] - 1] += 2L * d[i + 1][j];
      //                 d[i][h[i] - 1] %= mod;
      //             }
      //         }
      //     } else {
      //         for (int j = 0; j < h[i]; ++j) {
      //             if (j < h[i + 1] - 1 && j < h[i] - 1) {
      //                 d[i][j] += d[i + 1][j] * IntegerUtils.pow(2, rem, mod);
      //                 d[i][j] %= mod;
      //             } else {
      //                 int arem = h[i] - j - 2;
      //                 if (arem < 0) arem = 0;
      //                 d[i][j] += d[i + 1][h[i + 1] - 1] * IntegerUtils.pow(2, arem + 1, mod);
      //                 d[i][j] %= mod;
      //             }
      //         }
      //     }
      // }
      // long res = 0;
      // for (int i = 0; i < h[0]; ++i) {
      //     res += d[0][i];
      //     res %= mod;
      // }

      TaskD.Seg[] D = new TaskD.Seg[]{new TaskD.Seg(0, 0, 1L, 1L)};
      for (int i = n - 1; i >= 0; --i) {
        ArrayList<TaskD.Seg> nd = new ArrayList<>();
        int rem = h[i] - h[i + 1];
        if (rem <= 0) {
          long total = 0;
          for (TaskD.Seg s : D) {
            if (s.r < h[i] - 1) {
              nd.add(s);
            } else {
              Pair<TaskD.Seg, TaskD.Seg> parts = s.split(h[i] - 1);
              if (parts.first != null) {
                nd.add(parts.first);
              }
              if (parts.second != null) {
                total += parts.second.sum();
              }
            }
          }
          nd.add(new TaskD.Seg(h[i] - 1, h[i] - 1, total * 2L, 1));
        } else {
          long p = IntegerUtils.pow(2, rem, mod);
          for (TaskD.Seg s : D) {
            if (s.r < h[i + 1] - 1) {
              nd.add(new TaskD.Seg(s.l, s.r, s.start * p, s.base));
            } else {
              Pair<TaskD.Seg, TaskD.Seg> parts = s.split(h[i + 1] - 1);
              if (parts.first != null) {
                nd.add(parts.first);
              }
              long val = parts.second.at(h[i + 1] - 1);
              val *= 2L;
              val %= mod;
              nd.add(new TaskD.Seg(h[i + 1] - 1, h[i] - 2, val, 2L));
              nd.add(new TaskD.Seg(h[i] - 1, h[i] - 1, val, 1L));
            }
          }
        }
        D = new TaskD.Seg[nd.size()];
        for (int j = 0; j < nd.size(); ++j) {
          D[j] = nd.get(j);
        }
        // for (Seg s : D) {
        //     for (int j = s.l; j <= s.r; ++j) {
        //         if (s.at(j) != d[i][j]) {
        //             throw new RuntimeException();
        //         }
        //     }
        // }
      }
      long res = 0;
      for (TaskD.Seg s : D) {
        res += s.sum();
        res %= mod;
      }
      out.printLine(res);
    }

    static class Seg {

      int l;
      int r;
      long start;
      long base;

      public Seg(int l, int r, long start, long base) {
        this.l = l;
        this.r = r;
        Assert.assertTrue(r >= l);
        this.start = start % mod;
        this.base = base;
      }

      long at(int ind) {
        Assert.assertTrue(ind >= l && ind <= r);
        long res = start;
        if (base != 1) {
          res *= IntegerUtils.pow(2, r - ind, mod);
          res %= mod;
        }
        return res;
      }

      public long sum() {
        long res;
        if (base == 1) {
          res = start * (r - l + 1L);
          res %= mod;
        } else {
          res = start * (IntegerUtils.pow(2, r - l + 1, mod) + mod - 1);
          res %= mod;
        }
        return res;
      }

      Pair<TaskD.Seg, TaskD.Seg> split(int ind) {
        if (ind <= l) {
          return new Pair<>(null, this);
        }
        if (ind > r) {
          return new Pair<>(this, null);
        }
        if (base == 1) {
          return new Pair<>(
              new TaskD.Seg(l, ind - 1, start, 1),
              new TaskD.Seg(ind, r, start, 1));
        } else {
          return new Pair<>(
              new TaskD.Seg(l, ind - 1, at(ind - 1), 2),
              new TaskD.Seg(ind, r, at(r), 2));
        }
      }

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

  static class IntegerUtils {

    public static int pow(long x, long y, int mod) {
      x %= mod;
      long res = 1;
      while (y > 0) {
        if (y % 2 == 1) {
          --y;
          res = (res * x) % mod;
        } else {
          y /= 2;
          x = (x * x) % mod;
        }
      }
      return (int) (res % mod);
    }

  }

  static class Assert {

    public static void assertTrue(boolean flag) {
      // if (!flag)
      // while (true);
      if (!flag) {
        throw new AssertionError();
      }
    }

  }
}