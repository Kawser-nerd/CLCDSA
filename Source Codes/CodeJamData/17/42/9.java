import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("rollercoasterscheduling.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("rollercoasterscheduling.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        RollerCoasterScheduling solver = new RollerCoasterScheduling();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class RollerCoasterScheduling {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            System.err.println("TEST " + testNumber);
            int n = in.nextInt();
            int customers = in.nextInt();
            int tickets = in.nextInt();
            int[] pos = new int[tickets];
            int[] man = new int[tickets];
            for (int i = 0; i < tickets; i++) {
                pos[i] = in.nextInt() - 1;
                man[i] = in.nextInt() - 1;
            }
            RollerCoasterScheduling.Graph graph = new RollerCoasterScheduling.Graph(customers + 3 * n + 2);
            int start = customers + 3 * n;
            int finish = customers + 3 * n + 1;
            final int INF = Integer.MAX_VALUE / 2;
            for (int i = 0; i < n - 1; i++) {
                graph.addEdge(i + customers + 1, i + customers + n, INF, 1);
                graph.addEdge(i + 1 + customers + n, i + customers + n, INF, 0);
            }
            for (int i = 0; i < n; i++) {
                graph.addEdge(i + customers + n, i + customers + 2 * n, INF, 0);
                graph.addEdge(i + customers, i + customers + 2 * n, INF, 0);
            }
            int[] ridesPerMan = new int[customers];
            for (int i : man) {
                ridesPerMan[i]++;
            }
            int maxRides = 0;
            for (int i : ridesPerMan) {
                maxRides = Math.max(maxRides, i);
            }
            for (int i = 0; i < customers; i++) {
                graph.addEdge(start, i, ridesPerMan[i], 0);
            }
            for (int i = 0; i < tickets; i++) {
                graph.addEdge(man[i], pos[i] + customers, 1, 0);
            }
            long flow = 0;
            int rides = maxRides;
            for (int i = 0; i < n; i++) {
                graph.addEdge(i + customers + 2 * n, finish, maxRides, 0);
            }
            long cost = 0;
            long[] flowCost = graph.minCostFlow(start, finish);
            flow += flowCost[0];
            cost += flowCost[1];
            while (flow < tickets) {
                graph.clearFlow();
                rides++;
                for (int i = 0; i < n; i++) {
                    graph.addEdge(i + customers + 2 * n, finish, 1, 0);
                }
                flowCost = graph.minCostFlow(start, finish);
                flow = flowCost[0];
                cost = flowCost[1];
            }
            out.println("Case #" + testNumber + ": " + rides + " " + cost);
        }

        public static class QItem implements Comparable<RollerCoasterScheduling.QItem> {
            long d;
            int v;

            public QItem(long d, int v) {
                this.d = d;
                this.v = v;
            }

            public int compareTo(RollerCoasterScheduling.QItem q) {
                return d < q.d ? -1 : d > q.d ? 1 : 0;
            }

        }

        public static class Graph {
            public final int n;
            public List<RollerCoasterScheduling.Edge>[] edges;

            @SuppressWarnings("unchecked")
            public Graph(int n) {
                this.n = n;
                edges = new List[n];
                for (int i = 0; i < n; i++) {
                    edges[i] = new ArrayList<RollerCoasterScheduling.Edge>();
                }
            }

            public void addEdge(int u, int v, int cap, int cost) {
                RollerCoasterScheduling.Edge e1 = new RollerCoasterScheduling.Edge(v, cap, cost);
                RollerCoasterScheduling.Edge e2 = new RollerCoasterScheduling.Edge(u, 0, -cost);
                e1.rev = e2;
                e2.rev = e1;
                edges[u].add(e1);
                edges[v].add(e2);
            }

            public void clearFlow() {
                for (List<RollerCoasterScheduling.Edge> edgesList : edges) {
                    for (RollerCoasterScheduling.Edge e : edgesList) {
                        e.flow = 0;
                    }
                }
            }

            public long[] minCostFlow(int s, int t) {
                final long INF = 1L << 50;
                long flow = 0;
                long flowCost = 0;
                long[] u = new long[n];
                long[] d = new long[n];
                RollerCoasterScheduling.Edge[] p = new RollerCoasterScheduling.Edge[n];
                Queue<RollerCoasterScheduling.QItem> q = new PriorityQueue<RollerCoasterScheduling.QItem>();
                while (true) {
                    q.clear();
                    q.add(new RollerCoasterScheduling.QItem(0, s));
                    Arrays.fill(d, INF);
                    Arrays.fill(p, null);
                    d[s] = 0;
                    while (!q.isEmpty()) {
                        RollerCoasterScheduling.QItem cur = q.poll();
                        if (cur.d != d[cur.v]) {
                            continue;
                        }
                        for (int i = 0; i < edges[cur.v].size(); i++) {
                            RollerCoasterScheduling.Edge e = edges[cur.v].get(i);
                            long nd = d[cur.v] + e.cost + u[cur.v] - u[e.to];
                            if (e.cap > e.flow && d[e.to] > nd) {
                                d[e.to] = nd;
                                p[e.to] = e;
                                q.add(new RollerCoasterScheduling.QItem(nd, e.to));
                            }
                        }
                    }
                    if (p[t] == null) {
                        break;
                    }
                    for (int i = 0; i < n; i++) {
                        if (p[i] != null) {
                            u[i] += d[i];
                        }
                    }
                    int min = Integer.MAX_VALUE;
                    for (RollerCoasterScheduling.Edge e = p[t]; e != null; e = p[e.rev.to]) {
                        min = Math.min(min, e.cap - e.flow);
                    }

                    flow += min;
                    for (RollerCoasterScheduling.Edge e = p[t]; e != null; e = p[e.rev.to]) {
                        e.flow += min;
                        e.rev.flow -= min;
                        flowCost += (long) min * e.cost;
                    }
                }
                return new long[]{flow, flowCost};
            }

        }

        public static class Edge {
            public int to;
            public int cap;
            public int flow;
            public int cost;
            public RollerCoasterScheduling.Edge rev;

            public Edge(int to, int cap, int cost) {
                this.to = to;
                this.cap = cap;
                this.cost = cost;
            }

        }

    }

    static class InputReader {
        public BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            return nextToken();
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (line == null) {
                    return null;
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

    }
}

