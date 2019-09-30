import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = in.nextLongArray(n);

            long sum = 0;
            long INF = Long.MAX_VALUE;
            int s = 0;
            int t = n + 1;
            List<MaxFlowDinicL.Edge>[] graph = Stream.generate(ArrayList::new).limit(n + 2).toArray(List[]::new);
            for (int i = 1; i <= n; i++) {
                sum += a[i - 1] > 0 ? a[i - 1] : 0;
                MaxFlowDinicL.addEdge(graph, s, i, a[i - 1] < 0 ? -a[i - 1] : 0);
                MaxFlowDinicL.addEdge(graph, i, t, a[i - 1] > 0 ? a[i - 1] : 0);
                for (int j = 2 * i; j <= n; j += i) {
                    MaxFlowDinicL.addEdge(graph, i, j, INF);
                }
            }

            out.println(sum - MaxFlowDinicL.maxFlow(graph, s, t));
        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tok;

        public String nextString() {
            while (!tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(in.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return tok.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public long nextLong() {
            return Long.parseLong(nextString());
        }

        public long[] nextLongArray(int n) {
            long[] res = new long[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextLong();
            }
            return res;
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }

    static class MaxFlowDinicL {
        public static void addEdge(List<MaxFlowDinicL.Edge>[] graph, int s, int t, long cap) {
            graph[s].add(new MaxFlowDinicL.Edge(t, graph[t].size(), cap));
            graph[t].add(new MaxFlowDinicL.Edge(s, graph[s].size() - 1, 0));
        }

        static boolean dinicBfs(List<MaxFlowDinicL.Edge>[] graph, int src, int dest, int[] dist) {
            Arrays.fill(dist, -1);
            dist[src] = 0;
            int[] Q = new int[graph.length];
            int sizeQ = 0;
            Q[sizeQ++] = src;
            for (int i = 0; i < sizeQ; i++) {
                int u = Q[i];
                for (MaxFlowDinicL.Edge e : graph[u]) {
                    if (dist[e.t] < 0 && e.f < e.cap) {
                        dist[e.t] = dist[u] + 1;
                        Q[sizeQ++] = e.t;
                    }
                }
            }
            return dist[dest] >= 0;
        }

        static long dinicDfs(List<MaxFlowDinicL.Edge>[] graph, int[] ptr, int[] dist, int dest, int u, long f) {
            if (u == dest)
                return f;
            for (; ptr[u] < graph[u].size(); ++ptr[u]) {
                MaxFlowDinicL.Edge e = graph[u].get(ptr[u]);
                if (dist[e.t] == dist[u] + 1 && e.f < e.cap) {
                    long df = dinicDfs(graph, ptr, dist, dest, e.t, Math.min(f, e.cap - e.f));
                    if (df > 0) {
                        e.f += df;
                        graph[e.t].get(e.rev).f -= df;
                        return df;
                    }
                }
            }
            return 0;
        }

        public static long maxFlow(List<MaxFlowDinicL.Edge>[] graph, int src, int dest) {
            long flow = 0;
            int[] dist = new int[graph.length];
            while (dinicBfs(graph, src, dest, dist)) {
                int[] ptr = new int[graph.length];
                while (true) {
                    long df = dinicDfs(graph, ptr, dist, dest, src, Long.MAX_VALUE);
                    if (df == 0)
                        break;
                    flow += df;
                }
            }
            return flow;
        }

        public static class Edge {
            int t;
            int rev;
            long cap;
            long f;

            public Edge(int t, int rev, long cap) {
                this.t = t;
                this.rev = rev;
                this.cap = cap;
            }

        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.