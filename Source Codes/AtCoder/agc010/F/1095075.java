import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Queue;
import java.util.ArrayDeque;
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
    TaskF solver = new TaskF();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskF {

    int n;
    int[] w;
    ArrayList<Integer>[] g;
    ArrayList<Integer>[] gr;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      n = in.nextInt();
      w = new int[n];
      for (int i = 0; i < n; ++i) {
        w[i] = in.nextInt();
      }
      g = new ArrayList[n];
      gr = new ArrayList[n];
      for (int i = 0; i < n; ++i) {
        g[i] = new ArrayList<>();
        gr[i] = new ArrayList<>();
      }
      for (int i = 0; i < n - 1; ++i) {
        int x = in.nextInt() - 1;
        int y = in.nextInt() - 1;
        if (w[x] < w[y]) {
          g[y].add(x);
          gr[x].add(y);
        }
        if (w[x] > w[y]) {
          g[x].add(y);
          gr[y].add(x);
        }
      }

      int[] d = new int[n];
      int[] deg = new int[n];
      for (int i = 0; i < n; ++i) {
        deg[i] = g[i].size();
      }
      Queue<Integer> q = new ArrayDeque<>();
      for (int i = 0; i < n; ++i) {
        if (g[i].size() == 0) {
          d[i] = -1;
          q.add(i);
        }
      }
      while (!q.isEmpty()) {
        int x = q.poll();
        if (d[x] == -1) {
          for (int y : gr[x]) {
            if (d[y] != 0) {
              continue;
            }
            d[y] = 1;
            q.add(y);
          }
        } else {
          for (int y : gr[x]) {
            if (d[y] != 0) {
              continue;
            }
            --deg[y];
            if (deg[y] == 0) {
              d[y] = -1;
              q.add(y);
            }
          }
        }
      }
      for (int i = 0; i < n; ++i) {
        if (d[i] == 1) {
          out.print((i + 1) + " ");
        }
      }
      out.printLine();
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.