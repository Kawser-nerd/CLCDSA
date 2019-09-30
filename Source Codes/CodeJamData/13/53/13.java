import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class C {
  static class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    public FastScanner(InputStream in) {
      br = new BufferedReader(new InputStreamReader(in));
      st = new StringTokenizer("");
    }

    public FastScanner(File f) throws IOException {
      br = new BufferedReader(new FileReader(f));
      st = new StringTokenizer("");
    }

    public int nextInt() throws IOException {
      return Integer.parseInt(next());
    }

    public long nextLong() throws IOException {
      return Long.parseLong(next());
    }

    public double nextDouble() throws IOException {
      return Double.parseDouble(next());
    }

    public String next() throws IOException {
      if (st.hasMoreTokens()) return st.nextToken();
      st = new StringTokenizer(br.readLine());
      return next();
    }
  }

  static final String OKAY = "Looks Good To Me";

  public static void main(String[] args) throws IOException {
    PrintWriter out = new PrintWriter(new File("C.out"));
    FastScanner in = new FastScanner(System.in);
    int cases = in.nextInt();
    for (int caseOn = 1; caseOn <= cases; caseOn++) {
      int n = in.nextInt();
      int m = in.nextInt();
      int p = in.nextInt();
      Edge[] eList = new Edge[m];
      ArrayList<Edge>[] g = new ArrayList[n];
      for (int i = 0; i < n; i++) {
        g[i] = new ArrayList<Edge>();
      }

      ArrayList<Edge>[] rev = new ArrayList[n];
      for (int i = 0; i < n; i++) {
        rev[i] = new ArrayList<Edge>();
      }

      for (int i = 0; i < m; i++) {
        int a = in.nextInt() - 1;
        int b = in.nextInt() - 1;
        int cost1 = in.nextInt();
        int cost2 = in.nextInt();
        Edge e = new Edge(a, b, cost1, cost2, i);
        g[a].add(e);
        rev[b].add(new Edge(b, a, cost1, cost2, i));
        eList[i] = e;
      }

      int[] path = new int[p];
      HashSet<Integer> hs = new HashSet<Integer>();
      for (int i = 0; i < path.length; i++) {
        path[i] = in.nextInt() - 1;
        hs.add(path[i]);
      }

      for (Edge e : eList) {
        e.setActual(hs);
      }

      for (ArrayList<Edge> el : rev) {
        for (Edge e : el) {
          e.setActual(hs);
        }
      }
      long cheapestPossibleCost = dijkstras2(0, 1, g, false);

      long[] cost = new long[p];
      cost[0] = eList[path[0]].actualCost;
      int[] at = new int[p];
      at[0] = eList[path[0]].end;
      long totalPathCost = 0;
      totalPathCost += eList[path[0]].cost1;
      HashSet<Integer> repeatedNodes = new HashSet<Integer>();
      boolean[] seen = new boolean[n];
      seen[at[0]] = true;
      for (int i = 1; i < p; i++) {
        cost[i] = cost[i - 1] + eList[path[i]].actualCost;
        at[i] = eList[path[i]].end;
        if (seen[at[i]]) {
          repeatedNodes.add(at[i]);
        } else {
          seen[at[i]] = true;
        }
        totalPathCost += eList[path[i]].cost1;
      }

      int breakEdge = -1;
      for (int i = 0; i < p; i++) {
        if (repeatedNodes.contains(eList[path[i]].start)) {
          breakEdge = i;
          break;
        }
      }

      long[] cheapCost = dijkstras(1, rev, true);
      long[] expensiveCost = dijkstras(0, g, false);

      int brokenEdge = -1;
      long currentCost = 0;
      long remainingCost = totalPathCost;
      for (int i = 0; i < p; i++) {
        currentCost += eList[path[i]].cost1;
        remainingCost -= eList[path[i]].cost1;
        int loc = eList[path[i]].end;
        if (expensiveCost[loc] < currentCost) {
          brokenEdge = i;
          break;
        }

        long costFromStart = dijkstras2(eList[path[i]].start, 1, g, false);
        long costFromEnd = cheapCost[eList[path[i]].end] + eList[path[i]].cost1;
        if (currentCost + costFromEnd - eList[path[i]].cost1 > cheapestPossibleCost) {
          brokenEdge = i;
          break;
        }

        if (costFromStart < costFromEnd) {
          brokenEdge = i;
          break;
        }
      }

      if (brokenEdge == -1 && breakEdge == -1) {
        out.printf("Case #%d: %s\n", caseOn, OKAY);
      } else {
        if (brokenEdge == -1) brokenEdge = p;
        if (breakEdge == -1) breakEdge = p;
        int edge = Math.min(breakEdge, brokenEdge);
        out.printf("Case #%d: %d\n", caseOn, path[edge] + 1);
      }
    }

    out.close();
  }

  static long dijkstras2(int start, int end, ArrayList<Edge>[] g, boolean cheap) {
    long[] res = new long[g.length];
    Arrays.fill(res, (long) 1e10);
    PriorityQueue<Edge> q = new PriorityQueue<Edge>();
    q.add(new Edge(start, 0));
    res[start] = 0;
    while (!q.isEmpty()) {
      Edge at = q.poll();
      if (res[at.end] != at.actualCost) {
        continue;
      }
      for (Edge e : g[at.end]) {
        if (res[e.end] > at.actualCost + e.cost(cheap)) {
          res[e.end] = at.actualCost + e.cost(cheap);
          q.add(new Edge(e.end, at.actualCost + e.cost(cheap)));
        }
      }
    }
    return res[end];
  }

  static long[] dijkstras(int start, ArrayList<Edge>[] g, boolean cheapEdge) {
    long[] res = new long[g.length];
    Arrays.fill(res, (long) 1e10);
    PriorityQueue<Edge> q = new PriorityQueue<Edge>();
    q.add(new Edge(start, 0));
    res[start] = 0;
    while (!q.isEmpty()) {
      Edge at = q.poll();
      if (res[at.end] != at.actualCost) {
        continue;
      }
      for (Edge e : g[at.end]) {
        if (res[e.end] > at.actualCost + e.cost(cheapEdge)) {
          res[e.end] = at.actualCost + e.cost(cheapEdge);
          q.add(new Edge(e.end, at.actualCost + e.cost(cheapEdge)));
        }
      }
    }
    return res;
  }

  static class Edge implements Comparable<Edge> {
    int start, end, index;
    long actualCost, cost1, cost2;

    public Edge(int a, int b, long cost1, long cost2, int index) {
      this.start = a;
      this.end = b;
      this.cost1 = cost1;
      this.cost2 = cost2;
      this.index = index;
    }

    public Edge(int at, long ac) {
      this.end = at;
      this.actualCost = ac;
    }

    public long cost(boolean cheap) {
      if (cheap) return cost1;
      return cost2;
    }

    public long cost2(boolean cheap) {
      if (cheap) return cost1;
      return actualCost;
    }

    public void setActual(HashSet<Integer> path) {
      if (path.contains(index)) {
        actualCost = cost1;
      } else {
        actualCost = cost2;
      }
    }

    public int compareTo(Edge o) {
      return Long.compare(actualCost, o.actualCost);
    }
  }
}
