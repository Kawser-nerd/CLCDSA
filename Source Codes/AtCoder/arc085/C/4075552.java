import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            Vertex[] vertices = new Vertex[n + 1];
            for (int i = 0; i <= n; i++)
                vertices[i] = new Vertex();
            Vertex s = new Vertex();
            Vertex t = new Vertex();
            long sum = 0;
            for (int i = 1; i <= n; i++) {
                long a = in.nextLong();
                if (a <= 0) {
                    Edge e = new Edge(s, vertices[i], -a);
                    s.setEdge(e);
                    e.setReverseEdge();
                } else {
                    Edge e = new Edge(vertices[i], t, a);
                    vertices[i].setEdge(e);
                    e.setReverseEdge();
                    sum += a;
                }
                for (int j = i + i; j <= n; j += i) {
                    Edge e = new Edge(vertices[i], vertices[j], Long.MAX_VALUE);
                    vertices[i].setEdge(e);
                    e.setReverseEdge();
                }
            }

            out.println(sum - Search.maxFlow(s, t));
        }

    }

    static class Vertex {
        private long value;
        private long dist;
        private List<Edge> edges = new ArrayList<>();

        public Vertex() {
        }

        public Vertex(long v) {
            this.value = v;
        }

        public void setEdge(Edge e) {
            this.edges.add(e);
        }

        public long getDegree() {
            return this.edges.size();
        }

        public Edge getEdge(int index) {
            return this.edges.get(index);
        }

        public List<Edge> getEdges() {
            return edges;
        }

        public void setDist(long dist) {
            this.dist = dist;
        }

        public long getDist() {
            return dist;
        }

    }

    static class Search {
        public static long maxFlow(Vertex source, Vertex sink) {
            long flow = 0;
            while (true) {
                sink.setDist(-1);
                setDistBFS(source);
                if (sink.getDist() < 0)
                    return flow;
                long f = dfsDinic(source, sink, Long.MAX_VALUE);
                while (f > 0) {
                    flow += f;
                    f = dfsDinic(source, sink, Long.MAX_VALUE);
                }
            }
        }

        private static void setDistBFS(Vertex start) {
            Queue<Vertex> q = new ArrayDeque<>();
            q.add(start);
            start.setDist(0);
            Set<Vertex> checked = new HashSet<>();
            checked.add(start);
            while (!q.isEmpty()) {
                Vertex cv = q.poll();
                for (Edge ce : cv.getEdges()) {
                    if (ce.getCost() > 0 && !checked.contains(ce.getTo())) {
                        ce.getTo().setDist(cv.getDist() + 1);
                        q.add(ce.getTo());
                        checked.add(ce.getTo());
                    }
                }
            }
        }

        private static long dfsDinic(Vertex cv, Vertex t, long f) {
            if (cv == t)
                return f;
            for (int i = 0; i < cv.getDegree(); i++) {
                Edge e = cv.getEdge(i);
                Vertex to = e.getTo();
                if (e.getCost() > 0 && cv.getDist() < to.getDist()) {
                    long d = dfsDinic(to, t, Math.min(f, e.getCost()));
                    if (d > 0) {
                        e.addCost(-d);
                        e.getReverseEdge().addCost(d);
                        return d;
                    }
                }
            }
            return 0;
        }

    }

    static class Edge {
        private Vertex from;
        private Vertex to;
        private long cost;
        private Edge reverseEdge;

        public Edge() {
        }

        public Edge(Vertex to) {
            this.to = to;
        }

        public Edge(Vertex to, long c) {
            this.to = to;
            this.cost = c;
        }

        public Edge(Vertex from, Vertex to, long c) {
            this.from = from;
            this.to = to;
            this.cost = c;
        }

        public Vertex getTo() {
            return this.to;
        }

        public long getCost() {
            return this.cost;
        }

        public void addCost(long d) {
            cost += d;
        }

        public void setReverseEdge(Edge reverseEdge) {
            this.reverseEdge = reverseEdge;
        }

        public void setReverseEdge() {
            Edge r = new Edge(to, from, 0);
            to.setEdge(r);
            reverseEdge = r;
            r.setReverseEdge(this);
        }

        public Edge getReverseEdge() {
            return reverseEdge;
        }

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
            this.in = in;
        }

        private int readByte() {
            if (bufPointer >= bufLength) {
                if (bufLength == -1)
                    throw new InputMismatchException();

                bufPointer = 0;
                try {
                    bufLength = in.read(buffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (bufLength <= 0)
                    return -1;
            }
            return buffer[bufPointer++];
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public long nextLong() {
            long n = 0;

            int b = readByte();
            while (isSpaceChar(b))
                b = readByte();

            boolean minus = (b == '-');
            if (minus)
                b = readByte();

            while (b >= '0' && b <= '9') {
                n *= 10;
                n += b - '0';
                b = readByte();
            }

            if (!isSpaceChar(b))
                throw new NumberFormatException();

            return minus ? -n : n;
        }

        public int nextInt() {
            long n = nextLong();

            if (n < Integer.MIN_VALUE || n > Integer.MAX_VALUE)
                throw new NumberFormatException();

            return (int) n;
        }

    }
}