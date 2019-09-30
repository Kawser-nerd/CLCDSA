import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.LinkedList;
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
        private static final long INF = Long.MAX_VALUE;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt();
            int[] A = new int[N];
            for (int i = 0; i < N; i++) {
                A[i] = in.nextInt();
            }
            long X = 0;

            for (int i = 0; i < N; i++) {
                if (A[i] > 0) X += A[i];
            }

            FlowNetwork network = new FlowNetwork(2 + N);

            int S = 0, T = N + 1;
            for (int i = 1; i <= N; i++) {
                int penalty = A[i - 1];
                if (penalty <= 0) {
                    network.addEdge(new FlowEdge(S, i, -penalty));
                } else {
                    network.addEdge(new FlowEdge(i, T, penalty));
                }
            }

            for (int i = 1; i <= N; i++) {
                for (int j = 2 * i; j <= N; j += i) {
                    network.addEdge(new FlowEdge(i, j, INF));
                }
            }

            FordFulkerson fulkerson = new FordFulkerson(network, S, T);

            out.println(X - fulkerson.value());
        }

        class FordFulkerson {
            private boolean[] marked;
            private FlowEdge[] edgeTo;
            private long value;

            public FordFulkerson(FlowNetwork G, int s, int t) {
                while (hasAugmentingPath(G, s, t)) { // While there exists an augmenting path, use it.
                    // Compute bottleneck capacity.
                    long bottle = Long.MAX_VALUE;
                    for (int v = t; v != s; v = edgeTo[v].other(v))
                        bottle = Math.min(bottle, edgeTo[v].residualCapacityTo(v));
                    // Augment flow.
                    for (int v = t; v != s; v = edgeTo[v].other(v))
                        edgeTo[v].addResidualFlowTo(v, bottle);
                    value += bottle;
                }

            }

            public long value() {
                return value;
            }

            private boolean hasAugmentingPath(FlowNetwork G, int s, int t) {
                edgeTo = new FlowEdge[G.V()];
                marked = new boolean[G.V()];

                // breadth-first search
                Queue<Integer> q = new LinkedList<Integer>();
                q.add(s);
                marked[s] = true;
                while (!q.isEmpty()) {
                    int v = q.remove();
                    for (FlowEdge e : G.adj(v)) {
                        int w = e.other(v);

                        // if residual capacity from v to w
                        if (e.residualCapacityTo(w) > 0) {
                            if (!marked[w]) {
                                edgeTo[w] = e;
                                marked[w] = true;
                                q.add(w);
                            }
                        }
                    }
                }

                // is there an augmenting path?
                return marked[t];
            }

        }

        class FlowNetwork {
            private final int V;
            private int E;
            private List<FlowEdge>[] adj;

            public FlowNetwork(int V) {
                this.V = V;
                this.E = 0;
                adj = (List<FlowEdge>[]) new LinkedList[V];
                for (int v = 0; v < V; v++)
                    adj[v] = new LinkedList<FlowEdge>();
            }

            public int V() {
                return V;
            }

            public void addEdge(FlowEdge e) {
                int v = e.from();
                int w = e.to();
                adj[v].add(e);
                adj[w].add(e);
                E++;
            }

            public Iterable<FlowEdge> adj(int v) {
                return adj[v];
            }

        }

        class FlowEdge {
            private final int v;
            private final int w;
            private final long capacity;
            private long flow;

            public FlowEdge(int v, int w, long capacity) {
                this.v = v;
                this.w = w;
                this.capacity = capacity;
                this.flow = 0;
            }

            public int from() {
                return v;
            }

            public int to() {
                return w;
            }

            public int other(int vertex) {
                if (vertex == v) return w;
                else if (vertex == w) return v;
                else throw new IllegalArgumentException("Illegal endpoint");
            }

            public long residualCapacityTo(int vertex) {
                if (vertex == v) return flow;              // backward edge
                else if (vertex == w) return capacity - flow;   // forward edge
                else throw new IllegalArgumentException("Illegal endpoint");
            }

            public void addResidualFlowTo(int vertex, long delta) {
                if (vertex == v) flow -= delta;           // backward edge
                else if (vertex == w) flow += delta;           // forward edge
                else throw new IllegalArgumentException("Illegal endpoint");
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.