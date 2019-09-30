import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
    TaskE solver = new TaskE();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskE {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      String S = in.nextToken();
      StringBuilder res = new StringBuilder();
      int[] bal = new int[2 * n + 2];
      while (S.length() > 0) {
        char[] s = S.toCharArray();
        int delta = 0, best = 0;
        for (int i = 0; i < s.length; ++i) {
          if (s[i] == 'b') {
            ++delta;
          } else {
            --delta;
          }
          bal[i] = delta;
          if (delta > bal[best]) {
            best = i;
          }
        }
        int numBest = bal[best];
        if (numBest <= 0) {
          res.append('a');
          res.append('b');
          int ca = 0;
          int pos = 0;
          Assert.assertTrue(s[pos] == 'a');
          ArrayList<Integer> toRemove = new ArrayList<>();
          while (s[pos] != 'b') {
            toRemove.add(pos);
            ++ca;
            ++pos;
          }
          while (ca > 0) {
            if (s[pos] == 'b') {
              --ca;
              toRemove.add(pos);
            }
            ++pos;
          }
          Collections.reverse(toRemove);
          for (int x : toRemove) {
            S = S.substring(0, x) + S.substring(x + 1);
          }
          continue;
        }
        String part = null;
        int pi = -1;
        for (int i = 0; i < s.length; ++i) {
          if (bal[i] == numBest) {
            StringBuilder cand = new StringBuilder();
            int cb = numBest;
            int j;
            for (j = i + 1; ; ++j) {
              if (s[j] == 'b') {
                ++cb;
              } else {
                --cb;
              }
              cand.append(s[j]);
              if (cb == 0) {
                break;
              }
            }
            if (part == null) {
              part = cand.toString();
              pi = j + 1;
            } else if (part.compareTo(cand.toString()) < 0) {
              part = cand.toString();
              pi = j + 1;
            }
          }
        }
        for (int i = 0; i < numBest; ++i) {
          res.append('b');
        }
        res.append(part);
        S = S.substring(pi);
      }
      out.printLine(res.toString());
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

    public String nextToken() {
      int c = readSkipSpace();
      StringBuilder sb = new StringBuilder();
      while (!isSpace(c)) {
        sb.append((char) c);
        c = read();
      }
      return sb.toString();
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