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
    TaskC solver = new TaskC();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskC {

    ArrayList<Integer>[] g;
    int[] u;
    int v;
    int e;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
      g = new ArrayList[n];
      for (int i = 0; i < n; ++i) {
        g[i] = new ArrayList<>();
      }
      for (int i = 0; i < m; ++i) {
        int x = in.nextInt() - 1;
        int y = in.nextInt() - 1;
        g[x].add(y);
        g[y].add(x);
      }
      int sum = 0, num3 = 0;
      ArrayList<Integer> ss = new ArrayList<>();
      for (int i = 0; i < n; ++i) {
        if (g[i].size() % 2 != 0) {
          out.printLine("No");
          return;
        }
        sum += g[i].size() / 2 - 1;
        if (g[i].size() >= 6) {
          ++num3;
        }
        if (g[i].size() >= 4) {
          ss.add(i);
        }
      }
      if (sum < 2) {
        out.printLine("No");
        return;
      }
      if (sum > 2 || num3 > 0) {
        out.printLine("Yes");
        return;
      }
      // sum == 2, num3 == 0
      Assert.assertTrue(ss.size() == 2);
      int s1 = ss.get(0), s2 = ss.get(1);

      u = new int[n];
      u[s1] = -1;
      v = 0;
      e = 0;
      dfs(s2);
      if (e > v - 1) {
        out.printLine("Yes");
        return;
      }

      u = new int[n];
      u[s2] = -1;
      v = 0;
      e = 0;
      dfs(s1);
      if (e > v - 1) {
        out.printLine("Yes");
        return;
      }
      out.printLine("No");
    }

    private void dfs(int x) {
      u[x] = 1;
      ++v;
      for (int y : g[x]) {
        if (u[y] == -1) {
          continue;
        }
        if (u[y] == 1) {
          ++e;
          continue;
        }
        dfs(y);
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

  static class Assert {

    public static void assertTrue(boolean flag) {
      // if (!flag)
      // while (true);
      if (!flag) {
        throw new AssertionError();
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.