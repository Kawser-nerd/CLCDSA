import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
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
    TaskE solver = new TaskE();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskE {

    ArrayList<Integer>[] g;
    int h;
    boolean[] u;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      h = in.nextInt();
      g = new ArrayList[2 * h + 2];
      for (int i = 0; i < g.length; ++i) {
        g[i] = new ArrayList<>();
      }
      for (int i = 0; i < n; ++i) {
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        int d = in.nextInt();
        int from = getFrom(c, a);
        int to = getTo(d, b);
        g[from].add(to);
      }

      int cntPlus = 0, cntMinus = 0, vPlus = -1, vMinus = -1;
      int[] degIn = new int[g.length];
      for (int i = 0; i < g.length; ++i) {
        for (int j : g[i]) {
          degIn[j]++;
        }
      }
      MaxFlowDinic G = new MaxFlowDinic();
      int S = g.length, T = g.length + 1;
      G.init(g.length + 2);
      int need = 0;
      for (int i = 0; i < g.length; ++i) {
        int cur = g[i].size() - degIn[i];
        if (cur == 0) {
          continue;
        }
        if (cur < 0 && i > h) {
          out.printLine("NO");
          return;
        }
        if (cur > 0 && i <= h) {
          out.printLine("NO");
          return;
        }
        if (cur > 0) {
          G.addEdge(S, i, cur);
          need += cur;
        } else {
          G.addEdge(i, T, -cur);
        }
      }
      for (int i = 0; i < g.length; ++i) {
        for (int j : g[i]) {
          G.addEdge(i, j, 1);
        }
      }
      int fl = G.maxFlow(S, T);
      if (fl < need) {
        out.printLine("NO");
        return;
      }

      u = new boolean[g.length];
      for (int i = 0; i < g.length; ++i) {
        int cur = g[i].size() - degIn[i];
        if (cur == 0) {
          continue;
        }
        if (u[i]) {
          continue;
        }
        dfs(i);
      }
      for (int i = 0; i < g.length; ++i) {
        if (g[i].size() > 0 || degIn[i] > 0) {
          if (!u[i]) {
            out.printLine("NO");
            return;
          }
        }
      }

      out.printLine("YES");
//        for (int i = 0; i < g.length; ++i) {
//            int cur = g[i].size() - degIn[i];
//            if (cur == 0) continue;
//            if (cur < -1 || cur > 1) {
//                out.printLine("NO");
//                return;
//            }
//            if (cur == -1) {
//                ++cntMinus;
//                vMinus = i;
//            }
//            else {
//                vPlus = i;
//                ++cntPlus;
//            }
//        }
//        if (cntMinus > 1 || cntPlus > 1 || cntMinus != cntPlus) {
//            out.printLine("NO");
//            return;
//        }
//        if (cntMinus == 0) {
//            // Cycles don't work?
//            out.printLine("NO");
//            return;
//        }
//        if (cntMinus == 1) {
//            if (vPlus <= h || vMinus > h) {
//                out.printLine("NO");
//                return;
//            }
//
//            g[vMinus].add(vPlus);
//        }
//
//        boolean[][] d = new boolean[g.length][g.length];
//        for (int i = 0; i < g.length; ++i) {
//            d[i][i] = true;
//            for (int j : g[i]) d[i][j] = true;
//        }
//        for (int i = 0; i < g.length; ++i)
//            for (int j = 0; j < g.length; ++j)
//                for (int k = 0;k < g.length; ++k)
//                    if (d[j][i] && d[i][k]) d[j][k] = true;
//        for (int i = 0; i < g.length; ++i) if (g[i].size() != 0 || degIn[i] != 0)
//            for (int j = 0; j < g.length; ++j) if (g[j].size() != 0 || degIn[j] != 0)
//                if (!d[i][j] || !d[j][i]) {
//                    out.printLine("NO");
//                    return;
//                }
//        out.printLine("YES");
    }

    private void dfs(int x) {
      u[x] = true;
      for (int y : g[x]) {
        if (!u[y]) {
          dfs(y);
        }
      }
    }

    private int getTo(int height, int size) {
      if (height == 0) {
        return size;
      }
      return h + height;
    }

    private int getFrom(int height, int size) {
      if (height == 0) {
        return h + size;
      }
      return height;
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

  static class MaxFlowDinic {

    public ArrayList<MaxFlowDinic.Edge>[] graph;
    int src;
    int dest;
    int[] ptr;
    int[] Q;
    int[] dist;

    public void init(int nodes) {
      graph = new ArrayList[nodes];
      for (int i = 0; i < nodes; i++) {
        graph[i] = new ArrayList<MaxFlowDinic.Edge>();
      }
      ptr = new int[nodes];
      Q = new int[nodes];
      dist = new int[nodes];
    }

    public void addEdge(int s, int t, int cap) {
      graph[s].add(new MaxFlowDinic.Edge(s, t, graph[t].size(), cap));
      graph[t].add(new MaxFlowDinic.Edge(t, s, graph[s].size() - 1, 0));
    }

    boolean dinic_bfs() {
      Arrays.fill(dist, -1);
      dist[src] = 0;
      int sizeQ = 0;
      Q[sizeQ++] = src;
      for (int i = 0; i < sizeQ; i++) {
        int u = Q[i];
        for (MaxFlowDinic.Edge e : graph[u]) {
          if (dist[e.t] < 0 && e.f < e.cap) {
            dist[e.t] = dist[u] + 1;
            Q[sizeQ++] = e.t;
          }
        }
      }
      return dist[dest] >= 0;
    }

    int dinic_dfs(int u, int f) {
      if (u == dest) {
        return f;
      }
      for (; ptr[u] < graph[u].size(); ++ptr[u]) {
        MaxFlowDinic.Edge e = graph[u].get(ptr[u]);
        if (dist[e.t] == dist[u] + 1 && e.f < e.cap) {
          int df = dinic_dfs(e.t, Math.min(f, e.cap - e.f));
          if (df > 0) {
            e.f += df;
            graph[e.t].get(e.rev).f -= df;
            return df;
          }
        }
      }
      return 0;
    }

    public int maxFlow(int src, int dest) {
      this.src = src;
      this.dest = dest;
      int flow = 0;
      while (dinic_bfs()) {
        Arrays.fill(ptr, 0);
        while (true) {
          int df = dinic_dfs(src, Integer.MAX_VALUE);
          if (df == 0) {
            break;
          }
          flow += df;
        }
      }
      return flow;
    }

    static public class Edge {

      public int s;
      public int t;
      public int rev;
      public int cap;
      public int f;

      public Edge(int s, int t, int rev, int cap) {
        this.s = s;
        this.t = t;
        this.rev = rev;
        this.cap = cap;
      }

    }

  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.