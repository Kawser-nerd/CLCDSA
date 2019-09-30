import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            Vertex[] vertices = new Vertex[n];
            for (int i = 0; i < n; i++)
                vertices[i] = new Vertex();
            for (int i = 0; i < m; i++) {
                int f = in.nextInt() - 1;
                int t = in.nextInt() - 1;
                vertices[f].setEdge(vertices[t]);
                vertices[t].setEdge(vertices[f]);
            }
            for (Vertex cv : vertices)
                out.println(getFF(cv));
        }

        int getFF(Vertex v) {
            Set<Vertex> f = new HashSet<>();
            for (Edge e : v.getEdges())
                f.add(e.getTo());
            Set<Vertex> ff = new HashSet<>();
            for (Vertex cv : f)
                for (Edge e : cv.getEdges())
                    if (e.getTo() != v && !f.contains(e.getTo()))
                        ff.add(e.getTo());
            return ff.size();
        }

    }

    static class Edge {
        private Vertex from;
        private Vertex to;
        private long cost;

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

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
            this.in = in;
            this.bufPointer = 0;
            this.bufLength = 0;
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

        public int nextInt() {
            int n = 0;

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

    }

    static class Vertex {
        private long value;
        private List<Edge> edges = new ArrayList<>();

        public Vertex() {
        }

        public Vertex(long v) {
            this.value = v;
        }

        public void setEdge(Vertex v) {
            this.edges.add(new Edge(v));
        }

        public void setEdge(Edge e) {
            this.edges.add(e);
        }

        public List<Edge> getEdges() {
            return edges;
        }

    }
}