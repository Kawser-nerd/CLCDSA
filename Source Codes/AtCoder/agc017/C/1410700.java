import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.HashMap;
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
    TaskC solver = new TaskC();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskC {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int m = in.nextInt();
      SegmentTreeAddZeroCount tree = new SegmentTreeAddZeroCount(n + 10);
      HashMap<Integer, Integer> groups = new HashMap<>();
      int[] a = new int[n];
      for (int i = 0; i < n; ++i) {
        a[i] = in.nextInt();
        groups.put(a[i], groups.getOrDefault(a[i], 0) + 1);
      }
      for (int r : groups.keySet()) {
        int cnt = groups.get(r);
        int l = r - cnt + 1;
        tree.add(l, r, +1);
      }
      for (int it = 0; it < m; ++it) {
        int x = in.nextInt() - 1;
        int y = in.nextInt();
        int l, r;
        r = a[x];
        l = a[x] - groups.get(a[x]) + 1;
        tree.add(l, r, -1);
        if (groups.containsKey(y)) {
          r = y;
          l = y - groups.get(y) + 1;
          tree.add(l, r, -1);
        }

        int z = a[x];
        a[x] = y;
        if (groups.get(z) - 1 == 0) {
          groups.remove(z);
        } else {
          groups.put(z, groups.get(z) - 1);
        }
        groups.put(y, groups.getOrDefault(y, 0) + 1);
        if (groups.containsKey(z)) {
          r = z;
          l = z - groups.get(z) + 1;
          tree.add(l, r, +1);
        }
        r = y;
        l = y - groups.get(y) + 1;
        tree.add(l, r, +1);

        out.printLine(tree.zeroCount(1, n));
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

  static class SegmentTreeAddZeroCount {

    int[] delta;
    int[] minCnt;
    int[] min;
    int n;

    public SegmentTreeAddZeroCount(int n) {
      this.n = n;
      delta = new int[4 * n];
      minCnt = new int[4 * n];
      min = new int[4 * n];
      buildTree(1, 0, n - 1);
    }

    void buildTree(int node, int left, int right) {
      minCnt[node] = right - left + 1;
      if (left < right) {
        int mid = (left + right) >> 1;
        buildTree(node * 2, left, mid);
        buildTree(node * 2 + 1, mid + 1, right);
      }
    }

    public void add(int a, int b, int value) {
      add(a, b, value, 1, 0, n - 1);
    }

    void add(int a, int b, int value, int node, int left, int right) {
      if (left > b || right < a) {
        return;
      }
      if (left >= a && right <= b) {
        delta[node] += value;
        return;
      }
      int mid = (left + right) >> 1;
      int n0 = node * 2;
      int n1 = node * 2 + 1;
      add(a, b, value, n0, left, mid);
      add(a, b, value, n1, mid + 1, right);

      min[node] = Math.min(min[n0] + delta[n0], min[n1] + delta[n1]);
      minCnt[node] =
          (min[node] == min[n0] + delta[n0] ? minCnt[n0] : 0) + (min[node] == min[n1] + delta[n1]
              ? minCnt[n1] : 0);
    }

    public int zeroCount(int a, int b) {
      return zeroCount(a, b, 0, 1, 0, n - 1);
    }

    int zeroCount(int a, int b, int sumAdd, int node, int left, int right) {
      sumAdd += delta[node];
      if (left >= a && right <= b) {
        return min[node] + sumAdd == 0 ? minCnt[node] : 0;
      }
      int mid = (left + right) >> 1;
      int res = 0;
      if (a <= mid) {
        res += zeroCount(a, b, sumAdd, node * 2, left, mid);
      }
      if (b > mid) {
        res += zeroCount(a, b, sumAdd, node * 2 + 1, mid + 1, right);
      }
      return res;
    }

  }
}