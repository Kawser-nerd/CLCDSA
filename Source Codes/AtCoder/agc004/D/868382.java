import java.util.ListIterator;
import java.util.concurrent.atomic.AtomicInteger;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.List;
import java.math.BigInteger;
import java.io.OutputStream;
import java.util.Vector;
import java.util.Stack;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collections;
import java.io.IOException;
import java.util.Arrays;
import java.util.TreeSet;
import java.io.InputStream;
import java.util.Random;
import java.util.Collection;
import java.io.OutputStreamWriter;
import java.io.PrintStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ogiekako
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		MyScanner in = new MyScanner(inputStream);
		MyPrintWriter out = new MyPrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
        int N = in.nextInt();
        int K = in.nextInt();
        int[] a = new int[N];
        for (int i = 0; i < N; i++) a[i] = in.nextInt() - 1;
        int res = a[0] == 0 ? 0 : 1;
        a[0] = 0;
        out.println(res + solve(a,K));
    }

    int[] a;
    int K;
    Graph graph;
    int[] val;
    int res;
    private int solve(int[] a, int K) {
        this.a=a;
        this.K = K;
        int N = a.length;
        res = 0;
        val = new int[N];
        graph = new Graph(N);
        for (int i = 1; i < N; i++) {
            graph.add(a[i], i);
        }
        final AtomicInteger globalRes = new AtomicInteger(0);
        new DFS<Integer>(graph){
            protected void process(Edge e) {
                int n = (val[e.to()]+1) % K;
                val[e.from()] = Math.max(val[e.from()], n);
            }

            protected void exit(Edge e) {
                if (val[e.to()] == K - 1) {
                    if (a[e.to()] != 0) {
                        globalRes.addAndGet(1);
                    }
                }
            }
        }.run();
        return globalRes.get();
    }

}

class MyScanner {
    private final InputStream in;

    public MyScanner(InputStream in) {
        this.in = in;
    }

    private static final int BUFSIZE = 65536;
    int bufLen;
    int bufPtr;
    byte[] buf = new byte[BUFSIZE];

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

class MyPrintWriter {
    PrintWriter out;

    public MyPrintWriter(OutputStream outputStream) {
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void println(int a) {
        out.println(a);
    }

    public void close() {
        out.close();
    }

}

class Graph {
    final int vertexCount;
    private EdgeList[] edges;

    public Graph(int vertexCount) {
        this.vertexCount = vertexCount;
        edges = new EdgeList[vertexCount];
        for (int i = 0; i < vertexCount; i++) edges[i] = new EdgeList();
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

abstract class DFS<V> {
    protected final int n;
    protected final Graph graph;
    protected final boolean[] visited;
    private final ListIterator<Edge>[] is;

    public DFS(Graph graph) {
        this.graph = graph;
        n = graph.size();
        visited = new boolean[n];
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
                Edge e = is[parent.to()].next(); is[parent.to()].previous();
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

    protected V result() {return null;}

    protected void enterRoot(int root) {}

    protected boolean enter(Edge e) {return true;}

    protected void exit(Edge e) {}

    protected void process(Edge e) {}
}

interface Edge {
    int from();

    int to();

    Edge transposed();

    Edge reversed();
}

class SimpleEdge implements Edge {
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

class ArrayUtils {


    public static int[] createOrder(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) res[i] = i;
        return res;
    }

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.