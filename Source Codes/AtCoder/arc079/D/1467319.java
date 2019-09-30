import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.ListIterator;
import java.util.InputMismatchException;
import java.util.Stack;
import java.util.ArrayList;
import java.util.Vector;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;
import java.io.Writer;
import java.util.BitSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ogiekako
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyScanner in = new MyScanner(inputStream);
        MyPrintWriter out = new MyPrintWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
            int N = in.nextInt();
            Graph graph = new Graph(N);
            for (int i = 0; i < N; i++) {
                int p = in.nextInt() - 1;
                graph.add(p, i);
            }
            int cycle = -1;
            Pair<int[], int[][]> comp = SCC.sccWithComponents(graph);
            for (int i = 0; i < comp.second.length; i++) {
                if (comp.second[i].length > 1) {
                    if (cycle >= 0) throw new RuntimeException();
                    cycle = i;
                }
            }
            int[] grundy = new int[N];
            Arrays.fill(grundy, -1);
            for (int i = 0; i < N; i++) {
                if (comp.first[i] != cycle) {
                    recur(grundy, graph, i);
                }
            }
            for (int i = 0; i < N; i++) {
                if (comp.first[i] == cycle) {
                    BitSet b = new BitSet();
                    int nxt = -1;
                    for (Edge e : graph.edges(i)) {
                        if (grundy[e.to()] != -1) {
                            b.set(grundy[e.to()]);
                        } else {
                            if (nxt >= 0) throw new RuntimeException();
                            nxt = e.to();
                        }
                    }
                    int[] tmp = grundy.clone();
                    int g = b.nextClearBit(0);
                    tmp[i] = g;
                    recur(tmp, graph, nxt);
                    if (tmp[nxt] != g) {
                        out.println("POSSIBLE");
                        return;
                    }

                    tmp = grundy.clone();
                    b.set(g);
                    tmp[i] = b.nextClearBit(0);
                    recur(tmp, graph, nxt);
                    if (tmp[nxt] == g) {
                        out.println("POSSIBLE");
                        return;
                    }
                    out.println("IMPOSSIBLE");
                    return;
                }
            }
        }

        private void recur(int[] grundy, Graph graph, int i) {
            BitSet b = new BitSet();
            for (Edge e : graph.edges(i)) {
                if (grundy[e.to()] == -1) recur(grundy, graph, e.to());
                b.set(grundy[e.to()]);
            }
            grundy[i] = b.nextClearBit(0);
        }

    }

    static class SCC {
        public static int[] sccNonRecursive(Graph graph) {
            int[] postorder = createPostorder(graph);// KAERIGAKE
            // if there is a path from u to v:
            // 1. postorder[u] > postorder[v] or
            // 2. postorder[u] < postorder[v] and there is a path from v to u.

            // if component B is reachable from component A,
            // for any vertex v in A and u in B postorder[v] is larger than postorder[u].

            Graph rGraph = GraphUtils.transposed(graph);

            return new DFS<int[]>(rGraph) {
                int group = -1;
                int[] result = new int[n];

                // the root is the unvisited vertex that has the largest postorder.

                protected void enterRoot(int root) {
                    group++;
                }

                // Thm. visited vertices are connected component that ths root vertex belongs to.
                // ->) if u and v are in the same connected component, there are a path from u to v.
                // Hence u is visited in this dfs.
                // <-) if u is visited in this dfs, there is a path from u to v and postorder[u] < postorder[v].
                // Thus there is a path from v to u.

                protected boolean enter(Edge e) {
                    if (visited[e.to()]) return false;
                    result[e.to()] = group;
                    return true;
                }


                protected int[] result() {
                    return result;
                }
            }.run(ArrayUtils.reversed(postorder));
        }

        private static int[] createPostorder(Graph graph) {
            DFS<int[]> dfs = new DFS<int[]>(graph) {
                int ptr = 0;
                int[] result = new int[n];


                protected void exit(Edge e) {
                    result[ptr++] = e.to();
                }


                protected int[] result() {
                    return result;
                }


                protected boolean enter(Edge e) {
                    return !visited[e.to()];
                }
            };
            return dfs.run();
        }

        public static Pair<int[], int[][]> sccWithComponents(Graph graph) {
            int[] comp = sccNonRecursive(graph);
            int[][] res = ArrayUtils.classify(comp);
            return new Pair<int[], int[][]>(comp, res);
        }

    }

    static class ArrayUtils {
        public static int[][] classify(int[] comp) {
            int n = comp.length;
            int numComp = max(comp) + 1;
            int[] counts = new int[numComp];
            for (int aComp : comp) counts[aComp]++;
            int[][] res = new int[numComp][];
            for (int i = 0; i < numComp; i++) {
                res[i] = new int[counts[i]];
                counts[i] = 0;
            }
            for (int i = 0; i < n; i++) {
                int c = comp[i];
                res[c][counts[c]++] = i;
            }
            return res;
        }

        public static int max(int... is) {
            int res = Integer.MIN_VALUE;
            for (int i : is) res = Math.max(res, i);
            return res;
        }

        public static int[] createOrder(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) res[i] = i;
            return res;
        }

        public static void reverse(int[] is) {
            int n = is.length;
            for (int i = 0; i * 2 < n; i++) {
                int tmp = is[i];
                is[i] = is[n - 1 - i];
                is[n - 1 - i] = tmp;
            }
        }

        public static int[] reversed(int[] is) {
            is = is.clone();
            reverse(is);
            return is;
        }

    }

    static class Graph {
        final int vertexCount;
        private Graph.EdgeList[] edges;

        public Graph(int vertexCount) {
            this.vertexCount = vertexCount;
            edges = new Graph.EdgeList[vertexCount];
            for (int i = 0; i < vertexCount; i++) edges[i] = new Graph.EdgeList();
        }

        public void add(Edge edge) {
            edges[edge.from()].add(edge);
            Edge rev = edge.reversed();
            if (rev != null) {
                edges[rev.from()].add(rev);
            }
        }

        public void add(int from, int to) {
            add(new SimpleEdge(from, to));
        }

        public List<Edge> edges(int vertex) {
            return edges[vertex];
        }

        public int size() {
            return vertexCount;
        }


        public String toString() {
            StringBuilder es = new StringBuilder();
            for (int i = 0; i < vertexCount; i++) {
                if (i > 0) es.append('\n');
                es.append(edges(i));
            }
            return "Graph{" +
                    "edges=" + es +
                    '}';
        }

        private static class EdgeList extends ArrayList<Edge> {
            EdgeList() {
                super(0);
            }

        }

    }

    static class MyPrintWriter {
        PrintWriter out;

        public MyPrintWriter(OutputStream outputStream) {
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public MyPrintWriter(Writer writer) {
            out = new PrintWriter(writer);
        }

        public void println(Object... os) {
            if (os.length == 0) {
                out.println();
                return;
            }
            for (int i = 0; i < os.length - 1; i++) {
                out.print(os[i]);
                out.print(' ');
            }
            out.println(os[os.length - 1]);
        }

        public void close() {
            out.close();
        }

    }

    static class Pair<F, S> implements Comparable<Pair<F, S>> {
        public final F first;
        public final S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }


        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair pair = (Pair) o;

            return first.equals(pair.first) && second.equals(pair.second);
        }


        public int hashCode() {
            int result = first.hashCode();
            result = 31 * result + second.hashCode();
            return result;
        }


        public int compareTo(Pair<F, S> o) {

            int i = ((Comparable<F>) first).compareTo(o.first);
            if (i != 0) return i;

            Comparable<S> tmp = (Comparable<S>) second;
            return tmp.compareTo(o.second);

            // Use lines below to avoid unchecked warning.

//        TreeSet<Object> A = new TreeSet<Object>();
//        A.add(first);
//        if (!A.contains(o.first)) {
//            return A.headSet(o.first).isEmpty() ? 1 : -1;
//        }
//        TreeSet<Object> B = new TreeSet<Object>();
//        B.add(second);
//        if (!B.contains(o.second)) {
//            return B.headSet(o.second).isEmpty() ? 1 : -1;
//        }
//        return 0;
        }


        public String toString() {
            return first + " " + second;
        }

    }

    static interface Edge {
        int from();

        int to();

        Edge transposed();

        Edge reversed();

    }

    static class SimpleEdge implements Edge {
        final int from;
        final int to;
        private Edge transposed;

        public SimpleEdge(int from, int to) {
            this.from = from;
            this.to = to;
        }


        public String toString() {
            return from() + " -> " + to();
        }

        public int from() {
            return from;
        }

        public int to() {
            return to;
        }

        public Edge transposed() {
            if (transposed == null)
                return transposed = new TransposedEdge();
            return transposed;
        }

        public Edge reversed() {
            return null;
        }

        private class TransposedEdge implements Edge {
            public int from() {
                return to;
            }

            public int to() {
                return from;
            }

            public Edge reversed() {
                return null;
            }

            public Edge transposed() {
                return SimpleEdge.this;
            }


            public String toString() {
                return from() + " -> " + to();
            }

        }

    }

    static abstract class DFS<V> {
        protected final int n;
        protected final Graph graph;
        protected final boolean[] visited;
        private final ListIterator<Edge>[] is;

        public DFS(Graph graph) {
            this.graph = graph;
            n = graph.size();
            visited = new boolean[n];
            //noinspection unchecked
            is = new ListIterator[n];
            for (int i = 0; i < n; i++) is[i] = graph.edges(i).listIterator();
        }

        public V run() {
            return run(ArrayUtils.createOrder(n));
        }

        public V run(int[] order) {
            Arrays.fill(visited, false);
            for (int vertex : order)
                if (!visited[vertex]) {
                    enterRoot(vertex);
                    run(vertex);
                }
            return result();
        }

        private void run(int vertex) {
            Stack<Edge> path = new Stack<Edge>();
            Edge parent = new SimpleEdge(-1, vertex);
            path.push(null);
            enter(parent);
            while (!path.isEmpty()) {
                visited[parent.to()] = true;
                boolean found = false;
                for (; is[parent.to()].hasNext();
                     is[parent.to()].next()
                        ) {
                    Edge e = is[parent.to()].next();
                    is[parent.to()].previous();
                    if (e.transposed() != parent) {
                        if (enter(e)) {
                            found = true;
                            path.push(parent);
                            is[parent.to()].next();
                            parent = e;
                            break;
                        }
                    }
                }
                if (!found) {
                    exit(parent);
                    if (parent.from() >= 0)
                        process(parent);
                    parent = path.pop();
                }
            }
        }

        protected V result() {
            return null;
        }

        protected void enterRoot(int root) {
        }

        protected boolean enter(Edge e) {
            return true;
        }

        protected void exit(Edge e) {
        }

        protected void process(Edge e) {
        }

    }

    static class GraphUtils {
        public static Graph transposed(Graph graph) {
            Graph res = new Graph(graph.size());
            for (int i = 0; i < graph.size(); i++) {
                for (Edge e : graph.edges(i)) {
                    res.add(e.transposed());
                }
            }
            return res;
        }

    }

    static class MyScanner {
        private final InputStream in;
        private static final int BUFSIZE = 65536;
        int bufLen;
        int bufPtr;
        byte[] buf = new byte[BUFSIZE];

        public MyScanner(InputStream in) {
            this.in = in;
        }

        public int read() {
            if (bufLen == -1)
                throw new InputMismatchException();
            if (bufPtr >= bufLen) {
                bufPtr = 0;
                try {
                    bufLen = in.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (bufLen <= 0)
                    return -1;
            }
            return buf[bufPtr++];
        }

        public int nextInt() {
            int c = read();
            if (c == -1) throw new NoSuchElementException();
            while (c != '-' && (c < '0' || '9' < c)) {
                c = read();
                if (c == -1) throw new NoSuchElementException();
            }
            if (c == '-') return -nextInt();
            int res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while ('0' <= c && c <= '9');
            return res;
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.