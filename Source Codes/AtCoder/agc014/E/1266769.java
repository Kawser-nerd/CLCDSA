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
import java.util.HashSet;
import java.util.AbstractCollection;
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
    TaskE solver = new TaskE();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskE {

    static int[] root;
    static TaskE.State[] states;

    static int get(int x) {
      if (x == root[x]) {
        return x;
      }
      int r = get(root[x]);
      root[x] = r;
      return r;
    }

    static int merge(int x, int y) {
      x = get(x);
      y = get(y);
      if (x == y) {
        return x;
      }
      if (states[x].outBlack.size() < states[y].outBlack.size()) {
        HashSet<Integer> tmp = states[x].outBlack;
        states[x].outBlack = states[y].outBlack;
        states[y].outBlack = tmp;
      }
      if (states[x].outRed.size() < states[y].outRed.size()) {
        HashSet<Integer> tmp = states[x].outRed;
        states[x].outRed = states[y].outRed;
        states[y].outRed = tmp;
      }
      states[x].outRed.addAll(states[y].outRed);
      states[x].outBlack.addAll(states[y].outBlack);
      states[x].outRed.remove(x);
      states[x].outRed.remove(y);
      states[x].outBlack.remove(x);
      states[x].outBlack.remove(y);

      states[y].outBlack.clear();
      states[y].outRed.clear();
      states[y] = null;

      root[y] = x;
      return x;
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      root = new int[n];
      for (int i = 0; i < n; ++i) {
        root[i] = i;
      }
      states = new TaskE.State[n];
      for (int i = 0; i < n; ++i) {
        states[i] = new TaskE.State();
      }
      for (int i = 0; i < n - 1; ++i) {
        int x = in.nextInt() - 1;
        int y = in.nextInt() - 1;
        states[x].outRed.add(y);
        states[y].outRed.add(x);
      }
      for (int i = 0; i < n - 1; ++i) {
        int x = in.nextInt() - 1;
        int y = in.nextInt() - 1;
        states[x].outBlack.add(y);
        states[y].outBlack.add(x);
      }
      Queue<Integer> q = new ArrayDeque<>();
      for (int i = 0; i < n; ++i) {
        q.add(i);
      }
      while (!q.isEmpty()) {
        int x = q.poll();
        if (get(x) != x) {
          continue;
        }
        //states[x].normalize(x);
        ArrayList<Integer> neigh = states[x].evict();
        for (int y : neigh) {
          int r1 = get(x);
          int r2 = get(y);
          Assert.assertTrue(r1 == x);
          Assert.assertFalse(r1 == r2);
          for (int z : states[r2].outRed) {
            states[z].outRed.remove(r2);
            states[z].outRed.add(r1);
          }
          for (int z : states[r2].outBlack) {
            states[z].outBlack.remove(r2);
            states[z].outBlack.add(r1);
          }
          merge(r1, r2);
        }
        Assert.assertTrue(get(x) == x);
        if (!neigh.isEmpty()) {
          q.add(x);
        }
      }
      HashSet<Integer> roots = new HashSet<>();
      for (int i = 0; i < n; ++i) {
        roots.add(get(i));
      }
      if (roots.size() == 1) {
        out.printLine("YES");
      } else {
        out.printLine("NO");
      }

    }

    static class State {

      HashSet<Integer> outRed = new HashSet<>();
      HashSet<Integer> outBlack = new HashSet<>();

      ArrayList<Integer> evict() {
        ArrayList<Integer> res = new ArrayList<>();
        for (int x : outRed) {
          if (outBlack.contains(x)) {
            res.add(x);
          }
        }
        for (int x : res) {
          outBlack.remove(x);
          outRed.remove(x);
        }
        return res;
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

  static class Assert {

    public static void assertTrue(boolean flag) {
//        if (!flag)
//        while (true);
      if (!flag) {
        throw new AssertionError();
      }
    }

    public static void assertFalse(boolean flag) {
      if (flag) {
        throw new AssertionError();
      }
    }

  }
}