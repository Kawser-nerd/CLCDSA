import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.util.Random;
import java.io.OutputStreamWriter;

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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
        int N = in.nextInt();
A = new long[N];
        for (int i = 0; i < N; i++) A[i] = in.nextInt();
        Graph G = new Graph(N);
        for (int i = 0; i < N - 1; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            G.add(a,b);
            G.add(b,a);
        }
        int ans = -1;
        for(int i=0;i<10;i++) {
            int r = new Random().nextInt(N);
            long res = dfs(G, r, -1);
            int tmp = res == (lastDeg <= 1 ? A[r] : 0) ? 1 : 0;
            if (ans == -1) ans = tmp;
            else if (ans != tmp){
                ans = -2;
                break;
            }
        }
        if (ans >= 0) {
            out.println(ans==1 ? "YES" : "NO");
        } else {
            throw new RuntimeException();
}
    }

    long[] A;
    int lastDeg;

    private long dfs(Graph g, int root, int prev) {
        long S = 0;
        long max = 0;
        int deg = 0;
        for(Edge e : g.edges(root)) {
            if (e.to() != prev) {
                deg++;
                long v = dfs(g, e.to(), root);
                if (v < 0) return -1;
                S += v;
                max = Math.max(max, v);
            }
        }
        if (A[root] < max) return -1;
        if (deg > 0 && A[root] > S) return -1;
        long res = deg == 0 ? A[root] : S - 2 * (S - A[root]);
        if (res < 0) return -1;
        lastDeg = deg;
        return res;
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

interface Edge {
    int from();

    int to();

    Edge reversed();
}

class SimpleEdge implements Edge {
    final int from;
    final int to;

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

    public Edge reversed() {
        return null;
    }

}