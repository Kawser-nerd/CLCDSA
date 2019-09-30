import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.IOException;
import java.io.Reader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.AbstractCollection;
import java.util.List;
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
        MyInput in = new MyInput(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, MyInput in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int S = in.nextInt() - 1;
            int T = in.nextInt() - 1;
            int[][] es = in.nextIntArray2D(m, 3);
            Graph g = Graph.fromEdges(n, es, true);
            long[][] dcS = g.dijkstra(S);
            long[][] dcT = g.dijkstra(T);
            long distST = dcS[0][T];
            long cntST = dcS[1][T];

            long ans = 0;

            final int mod = (int) 1e9 + 7;
            for (int v = 0; v < n; v++) {
                if (dcS[0][v] + dcT[0][v] != distST) {
                    continue;
                }
                if (dcS[0][v] == dcT[0][v]) {
                    long c = dcS[1][v] * dcT[1][v] % mod;
                    ans += c * (cntST - c) % mod;
//                dump(v);
                }
                for (Edge e : g.vertex[v].edges) {
                    final int t = e.to;
                    if (dcS[0][v] + dcT[0][t] + e.cost != distST) {
                        continue;
                    }
                    if (dcS[0][v] < dcT[0][v] && dcS[0][t] > dcT[0][t]) {
                        long c = dcS[1][v] * dcT[1][t] % mod;
                        ans += c * (cntST - c) % mod;
//                    dump(v, t);
                    }
                }
            }
            out.println((ans % mod + mod) % mod);
        }

    }

    static class Vertex {
        public final int id;
        public final List<Edge> edges = new ArrayList<>();

        public Vertex(final int id) {
            this.id = id;
        }

        public void addEdge(Edge e) {
            edges.add(e);
        }

    }

    static class Graph {
        int V;
        int E;
        Vertex[] vertex;

        public Graph(int V) {
            this.V = V;
            this.E = 0;
            vertex = new Vertex[V];
            for (int i = 0; i < V; i++) vertex[i] = new Vertex(i);
        }

        public static Graph fromEdges(int n, int[][] edges, boolean bidirectional) {
            Graph g = new Graph(n);
            g.addEdges(bidirectional, edges);
            return g;
        }

        public void addEdges(boolean bidirectional, int[]... edges) {
            for (int[] e : edges) {
                int s = e[0] - 1, t = e[1] - 1;
                long cost = e.length < 3 ? 0 : e[2];
                final int eid = this.E++;
                this.addEdge(s, t, cost, eid);
                if (bidirectional) this.addEdge(t, s, cost, eid);
            }
        }

        public void addEdge(int s, int t, long c, int edgeId) {
            vertex[s].addEdge(new Edge(t, c, edgeId));
        }

        public long[][] dijkstra(int r) {
            final int mod = (int) 1e9 + 7;

            long[] dist = new long[V];
            long[] cnt = new long[V];
            Arrays.fill(dist, Long.MAX_VALUE);
            dist[r] = 0;
            cnt[r] = 1;
            PriorityQueue<long[]> que = new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));
            que.add(new long[]{0, r});
            while (!que.isEmpty()) {
                long[] q = que.poll();
                long d = q[0];
                int v = (int) q[1];
                if (d != dist[v]) continue;
                for (Edge e : vertex[v].edges) {
                    if (dist[e.to] > d + e.cost) {
                        dist[e.to] = d + e.cost;
                        cnt[e.to] = 0;
                        que.add(new long[]{dist[e.to], e.to});
                    }
                    if (dist[e.to] == d + e.cost) {
                        cnt[e.to] += cnt[v];
                        if (cnt[e.to] >= mod) cnt[e.to] -= mod;
                    }
                }
            }
            return new long[][]{dist, cnt};
        }

    }

    static class MyInput {
        private final BufferedReader in;
        private static int pos;
        private static int readLen;
        private static final char[] buffer = new char[1024 * 8];
        private static char[] str = new char[500 * 8 * 2];
        private static boolean[] isDigit = new boolean[256];
        private static boolean[] isSpace = new boolean[256];
        private static boolean[] isLineSep = new boolean[256];

        static {
            for (int i = 0; i < 10; i++) {
                isDigit['0' + i] = true;
            }
            isDigit['-'] = true;
            isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
            isLineSep['\r'] = isLineSep['\n'] = true;
        }

        public MyInput(InputStream is) {
            in = new BufferedReader(new InputStreamReader(is));
        }

        public int read() {
            if (pos >= readLen) {
                pos = 0;
                try {
                    readLen = in.read(buffer);
                } catch (IOException e) {
                    throw new RuntimeException();
                }
                if (readLen <= 0) {
                    throw new MyInput.EndOfFileRuntimeException();
                }
            }
            return buffer[pos++];
        }

        public int nextInt() {
            int len = 0;
            str[len++] = nextChar();
            len = reads(len, isSpace);
            int i = 0;
            int ret = 0;
            if (str[0] == '-') {
                i = 1;
            }
            for (; i < len; i++) ret = ret * 10 + str[i] - '0';
            if (str[0] == '-') {
                ret = -ret;
            }
            return ret;
        }

        public char nextChar() {
            while (true) {
                final int c = read();
                if (!isSpace[c]) {
                    return (char) c;
                }
            }
        }

        int reads(int len, boolean[] accept) {
            try {
                while (true) {
                    final int c = read();
                    if (accept[c]) {
                        break;
                    }
                    if (str.length == len) {
                        char[] rep = new char[str.length * 3 / 2];
                        System.arraycopy(str, 0, rep, 0, str.length);
                        str = rep;
                    }
                    str[len++] = (char) c;
                }
            } catch (MyInput.EndOfFileRuntimeException e) {
            }
            return len;
        }

        public int[] nextIntArray(final int n) {
            final int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
        }

        public int[][] nextIntArray2D(final int n, final int k) {
            final int[][] res = new int[n][];
            for (int i = 0; i < n; i++) {
                res[i] = nextIntArray(k);
            }
            return res;
        }

        static class EndOfFileRuntimeException extends RuntimeException {
        }

    }

    static class Edge {
        public final int edgeId;
        public final int to;
        public long cost;

        public Edge(int to, long cost, int edgeId) {
            this.to = to;
            this.cost = cost;
            this.edgeId = edgeId;
        }


        public String toString() {
            return String.format("[Edge id=%d, to=%d, cost=%d]", edgeId, to, cost);
        }

    }
}