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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int h = in.nextInt();
            int w = in.nextInt();

            Vertex[] hv = new Vertex[h];
            Vertex[] wv = new Vertex[w];
            for (int i = 0; i < h; i++)
                hv[i] = new Vertex();
            for (int i = 0; i < w; i++)
                wv[i] = new Vertex();

            Vertex s = new Vertex();
            Vertex t = new Vertex();
            Edge e;
            int sx = 0, sy = 0, tx = 0, ty = 0;
            for (int y = 0; y < h; y++) {
                String cs = in.next();
                for (int x = 0; x < w; x++) {
                    char cc = cs.charAt(x);
                    if (cc == 'o') {
                        e = new Edge(wv[x], hv[y], 1);
                        e.setReverseEdge(1);
                    } else if (cc == 'S') {
                        sx = x;
                        sy = y;
                        e = new Edge(s, hv[y], Long.MAX_VALUE);
                        e.setReverseEdge();
                        e = new Edge(s, wv[x], Long.MAX_VALUE);
                        e.setReverseEdge();
                    } else if (cc == 'T') {
                        tx = x;
                        ty = y;
                        e = new Edge(hv[y], t, Long.MAX_VALUE);
                        e.setReverseEdge();
                        e = new Edge(wv[x], t, Long.MAX_VALUE);
                        e.setReverseEdge();
                    }
                }
            }

            if (sx == tx || sy == ty)
                out.println(-1);
            else
                out.println(Search.maxFlow(s, t));
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

        public void setDist(long dist) {
            this.dist = dist;
        }

        public long getDist() {
            return dist;
        }

    }

    static class Search {
        private static Set<Vertex> checked = new HashSet<>();

        public static long maxFlow(Vertex source, Vertex sink) {
            long flow = 0;
            while (true) {
                sink.setDist(-1);
                setDistBFS(source);
                if (sink.getDist() < 0)
                    return flow;
                //start.clear();
                long f = sendFlowDFS(source, sink, Long.MAX_VALUE);
                while (f > 0) {
                    flow += f;
                    f = sendFlowDFS(sink, source, Long.MAX_VALUE);
                }
            }
        }

        private static void setDistBFS(Vertex start) {
            Queue<Vertex> q = new ArrayDeque<>();
            q.add(start);
            start.setDist(0);
            checked.clear();
            checked.add(start);
            while (!q.isEmpty()) {
                Vertex cv = q.poll();
                for (int i = 0; i < cv.getDegree(); i++) {
                    Edge ce = cv.getEdge(i);
                    if (ce.getCost() > 0 && !checked.contains(ce.getTo())) {
                        ce.getTo().setDist(cv.getDist() + 1);
                        q.add(ce.getTo());
                        checked.add(ce.getTo());
                    }
                }
            }
        }

        private static long sendFlowDFS(Vertex cv, Vertex source, long f) {
            if (cv == source)
                return f;
            for (int i = 0; i < cv.getDegree(); i++) {
                Edge e = cv.getEdge(i);
                Vertex to = e.getTo();
                if (e.getCost() > 0 && cv.getDist() < to.getDist()) {
                    long d = sendFlowDFS(to, source, Math.min(f, e.getCost()));
                    if (d > 0) {
                        e.addCost(-d);
                        e.getReverseEdge().addCost(d);
                        return d;
                    }
                }
                //start.put(cv, i);
            }
            return -1;
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
            from.setEdge(this);
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
            reverseEdge = r;
            r.setReverseEdge(this);
        }

        public void setReverseEdge(long c) {
            Edge r = new Edge(to, from, c);
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

        private static boolean isPrintableChar(int c) {
            return c >= 33 && c <= 126;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            StringBuilder sb = new StringBuilder();

            int b = readByte();
            while (!isPrintableChar(b))
                b = readByte();

            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }

            return sb.toString();
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