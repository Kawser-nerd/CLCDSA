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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, MyInput in, PrintWriter out) {
            int n = in.nextInt();
            int[] parents = in.nextIntArray(n - 1);
            int[] x = in.nextIntArray(n);

            Graph g = Graph.fromParents(n, parents);
            int[] order = g.inversedDfsOrder(0);

            int[] val = new int[n];
            int[] sum = new int[n];
            String ans = "POSSIBLE";
            for (int v : order) {
                sum[v] += x[v];
                for (Edge e : g.vertex[v].edges) {
                    sum[v] += sum[e.to];
                }

                int[] xs = new int[x[v] + 1];
                Arrays.fill(xs, Integer.MAX_VALUE / 2);
                xs[0] = 0;
                for (Edge e : g.vertex[v].edges) {
                    int v0 = x[e.to];
                    int v1 = val[e.to];
                    for (int i = x[v]; i >= 0; i--) {
                        int va = Integer.MAX_VALUE / 2;
                        if (i - v0 >= 0) va = Math.min(va, xs[i - v0] + v1);
                        if (i - v1 >= 0) va = Math.min(va, xs[i - v1] + v0);
                        xs[i] = va;
                    }
                }
                val[v] = Integer.MAX_VALUE / 2;
                for (int i = 0; i < xs.length; i++) {
                    val[v] = Math.min(val[v], xs[i]);
                }

                if (val[v] == Integer.MAX_VALUE / 2) {
//                dump(v, val, xs);
                    ans = "IMPOSSIBLE";
                    break;
                }
            }
            out.println(ans);
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

        static class EndOfFileRuntimeException extends RuntimeException {
        }

    }

    static class Tree {
        int V;
        int root;
        Vertex[] vertex;

        public Tree(int V, int root) {
            this.V = V;
            this.root = root;
            vertex = new Vertex[V];
            for (int i = 0; i < V; i++) vertex[i] = new Vertex();
        }

        public void addEdge(int s, Edge e) {
            vertex[s].addEdge(e);
        }

        public int[] dfsOrder() {
            int[] st = new int[V];
            int sp = 0, len = 0;
            int[] order = new int[V];
            boolean[] vis = new boolean[V];

            vis[root] = true;
            st[sp++] = root;
            while (sp > 0) {
                int v = st[--sp];
                order[len++] = v;
                for (Edge e : vertex[v].edges)
                    if (!vis[e.to]) {
                        vis[e.to] = true;
                        st[sp++] = e.to;
                    }
            }
            return order;
        }

    }

    static class Vertex {
        public final List<Edge> edges = new ArrayList<>();

        public void addEdge(Edge e) {
            edges.add(e);
        }

    }

    static class Graph {
        int V;
        Vertex[] vertex;

        public Graph(int V) {
            this.V = V;
            vertex = new Vertex[V];
            for (int i = 0; i < V; i++) vertex[i] = new Vertex();
        }

        public static Graph fromParents(int n, int[] parent) {
            Graph g = new Graph(n);
            for (int i = 0; i < parent.length; i++) {
                int s = parent[i] - 1, t = i + 1;
                g.addEdge(s, t, i);
            }
            return g;
        }

        public void addEdge(int s, int t, int edgeId) {
            vertex[s].addEdge(new Edge(t, edgeId));
//        vertex[t].addEdge(new Edge(s, edgeId));
        }

        public Tree dfsTree(int r) {
            Tree tree = new Tree(V, r);
            int[] st = new int[V];
            int sp = 0;
            int len = 0;
            boolean[] vis = new boolean[V];

            vis[r] = true;
            st[sp++] = r;
            while (sp > 0) {
                int v = st[--sp];
                for (Edge e : vertex[v].edges)
                    if (!vis[e.to]) {
                        vis[e.to] = true;
                        st[sp++] = e.to;
                        tree.addEdge(v, e);
                    }
            }
            return tree;
        }

        public int[] inversedDfsOrder(int r) {
            return ArrayAlgorithms.reverse(dfsOrder(r));
        }

        public int[] dfsOrder(int r) {
            return dfsTree(r).dfsOrder();
        }

    }

    static class Edge {
        public final int edgeId;
        public final int to;

        public Edge(int to, int edgeId) {
            this.to = to;
            this.edgeId = edgeId;
        }


        public String toString() {
            return String.format("[Edge id=%d, to=%d]", edgeId, to);
        }

    }

    static class ArrayAlgorithms {
        public static int[] reverse(int[] ary) {
            int V = ary.length;
            for (int i = 0; i < V / 2; i++) {
                int t = ary[i];
                ary[i] = ary[V - 1 - i];
                ary[V - 1 - i] = t;
            }
            return ary;
        }

    }
}