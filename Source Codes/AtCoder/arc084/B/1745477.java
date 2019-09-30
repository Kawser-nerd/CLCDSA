import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.Reader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, MyInput in, PrintWriter out) {
            final int k = in.nextInt();
            TaskD.Graph g = new TaskD.Graph(k);

            for (int i = 0; i < k; i++) {
                g.addEdge(i, 10 * i % k, 0, -1);
                g.addEdge(i, (i + 1) % k, 1, -1);
            }

            int[] dist = g.bfs01(1 % k);
            out.println(dist[0] + 1);
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

        static class Vertex {
            public final int id;
            public final List<TaskD.Edge> edges = new ArrayList<>();

            public Vertex(final int id) {
                this.id = id;
            }

            public void addEdge(TaskD.Edge e) {
                edges.add(e);
            }

        }

        static class Graph {
            int V;
            int E;
            TaskD.Vertex[] vertex;

            public Graph(int V) {
                this.V = V;
                this.E = 0;
                vertex = new TaskD.Vertex[V];
                for (int i = 0; i < V; i++) vertex[i] = new TaskD.Vertex(i);
            }

            public void addEdge(int s, int t, long c, int edgeId) {
                vertex[s].addEdge(new TaskD.Edge(t, c, edgeId));
            }

            public int[] bfs01(int r) {
                int[] dist = new int[V];
                Arrays.fill(dist, Integer.MAX_VALUE);
                dist[r] = 0;
                int[] deq = new int[2 * V + 1];
                int s = V, t = V;
                deq[--s] = r;
                while (s != t) {
                    final int v = deq[s++];
                    for (TaskD.Edge e : vertex[v].edges) {
                        if (dist[e.to] > dist[v] + e.cost) {
                            dist[e.to] = dist[v] + (int) e.cost;
                            deq[e.cost == 0 ? --s : t++] = e.to;
                        }
                    }
                }
                return dist;
            }

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

        static class EndOfFileRuntimeException extends RuntimeException {
        }

    }
}