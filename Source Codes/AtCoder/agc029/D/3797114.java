import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
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

    static int m;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      m = in.nextInt();
      int cnt = in.nextInt();
      ArrayList<Integer>[] bads = new ArrayList[n];
      for (int i = 0; i < n; ++i) {
        bads[i] = new ArrayList<>();
      }
      for (int i = 0; i < cnt; ++i) {
        int x = in.nextInt() - 1;
        bads[x].add(in.nextInt() - 1);
      }
      TaskD.Seg s = new TaskD.Seg();
      for (int i = 0; i < n - 1; ++i) {
        if (s.remove(bads[i + 1])) {
          out.printLine(i + 1);
          return;
        }
        s.expand();
        s.remove(bads[i + 1]);
      }
      out.printLine(n);
    }

    static class Seg {

      int r = 0;
      HashSet<Integer> baddies = new HashSet<>();

      boolean remove(ArrayList<Integer> inds) {
        boolean hadAny = false;
        for (int x : inds) {
          if (x <= r) {
            if (!baddies.contains(x)) {
              hadAny = true;
              baddies.add(x);
            }
          }
        }
        while (r > 0 && baddies.contains(r)) {
          baddies.remove(r);
          --r;
        }
        return hadAny;
      }

      void expand() {
        ArrayList<Integer> gone = new ArrayList<>();
        for (int x : baddies) {
          if (x > 0 && !baddies.contains(x - 1)) {
            gone.add(x);
          }
        }
        for (int x : gone) {
          baddies.remove(x);
        }
        ++r;
        if (r > m - 1) {
          r = m - 1;
        }
        while (r > 0 && baddies.contains(r)) {
          baddies.remove(r);
          --r;
        }
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