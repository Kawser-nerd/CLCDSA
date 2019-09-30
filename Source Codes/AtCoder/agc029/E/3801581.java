import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Objects;
import java.io.Writer;
import java.io.OutputStreamWriter;
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

    ArrayList<Integer>[] g;
    int[] M;
    static int[] R;
    int[] par;
    int[] p;
    int[] cnt;
    ArrayList<TaskE.Query>[] q;
    HashMap<TaskE.Query, Integer> qd;
    int[] st;
    int[] pos;
    int ss;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      g = new ArrayList[n];
      for (int i = 0; i < n; ++i) {
        g[i] = new ArrayList<>();
      }
      for (int i = 0; i < n - 1; ++i) {
        int x = in.nextInt() - 1;
        int y = in.nextInt() - 1;
        g[x].add(y);
        g[y].add(x);
      }

      // p = new ArrayList[n];
      // cnt = new ArrayList[n];
      // ts = new ArrayList[n];
      // for (int i = 0; i < n; ++i) {
      //     cnt[i] = new ArrayList<>();
      //     p[i] = new ArrayList<>();
      //     ts[i] = new ArrayList<>();
      //     ts[i].add(-1);
      //     cnt[i].add(1);
      //     p[i].add(i);
      // }
      //
      // for (int i = 0; i < n; ++i) {
      //     for (int x : g[i]) if (x <= i) {
      //         int ri = root(i, i * 10, true), rx = root(x, i * 10, true);
      //         if (ri != rx) {
      //             p[ri].add(rx);
      //             ts[ri].add(i * 10 + 5);
      //             cnt[ri].add(0);
      //             cnt[rx].add(cnt[rx].get(cnt[rx].size() - 1) + cnt[ri].get(cnt[ri].size() - 1));
      //             p[rx].add(rx);
      //             ts[rx].add(i * 10 + 5);
      //         }
      //     }
      // }

      M = new int[n];
      R = new int[n];
      q = new ArrayList[n];
      qd = new HashMap<>();
      for (int i = 0; i < n; ++i) {
        q[i] = new ArrayList<>();
      }

      st = new int[n + 10];
      pos = new int[n];
      ss = 0;

      par = new int[n];
      dfs(0, 0, -1);

      p = new int[n];
      cnt = new int[n];
      for (int i = 0; i < n; ++i) {
        p[i] = i;
        cnt[i] = 1;
      }
      for (int i = 0; i < n; ++i) {
        for (int x : g[i]) {
          if (x <= i) {
            int ri = root(i), rx = root(x);
            if (ri != rx) {
              p[ri] = rx;
              cnt[rx] += cnt[ri];
              cnt[ri] = 0;
            }
          }
        }
        for (TaskE.Query query : q[i]) {
          int x = query.x;
          int cur = cnt[root(x)];
          if (x > i) {
            for (int y : g[x]) {
              if (y <= i/* && y != par[x]*/) {
                cur += cnt[root(y)];
              }
            }
          } else {
            // TODO
          }
          qd.put(query, cur);
        }
      }

      R[0] = 1;
      dfs1(0, -1);

      for (int i = 1; i < n; ++i) {
        out.print((R[i] - 1) + " ");
      }
      out.printLine();
    }

    private int root(int x) {
      if (x == p[x]) {
        return x;
      }
      int r = root(p[x]);
      p[x] = r;
      return r;
    }

    private void dfs(int x, int m, int p) {
      par[x] = p;
      st[ss] = x;
      pos[x] = ss;
      ++ss;
      M[x] = m;
      if (x > 0) {
        if (m == 0) {
        } else {
          int r = st[pos[m] + 1];
          if (r < M[m]) {
            q[M[m] - 1].add(new TaskE.Query(r, M[m] - 1));
          }
          q[m - 1].add(new TaskE.Query(x, m - 1));
        }
      }
      for (int y : g[x]) {
        if (y != p) {
          dfs(y, Math.max(x, m), x);
        }
      }
      --ss;
    }

    private void dfs1(int x, int p) {
      st[ss] = x;
      pos[x] = ss;
      ++ss;
      int m = M[x];
      if (x > 0) {
        if (m == 0) {
          R[x] = 2;
        } else {
          int r = st[pos[m] + 1];
          R[x] = R[m];
          if (r < M[m]) {
            R[x] -= qd.get(new TaskE.Query(r, M[m] - 1));
          }
          R[x] += qd.get(new TaskE.Query(x, m - 1));
        }
      }
      for (int y : g[x]) {
        if (y != p) {
          dfs1(y, x);
        }
      }
      --ss;
    }

    static class Query {

      int x;
      int m;

      public Query(int x, int m) {
        this.x = x;
        this.m = m;
      }

      public boolean equals(Object o) {
        if (this == o) {
          return true;
        }
        if (!(o instanceof TaskE.Query)) {
          return false;
        }
        TaskE.Query query = (TaskE.Query) o;
        return x == query.x &&
            m == query.m;
      }

      public int hashCode() {
        return Objects.hash(x, m);
      }

      public String toString() {
        return "Query{" +
            "x=" + x +
            ", m=" + m +
            '}';
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