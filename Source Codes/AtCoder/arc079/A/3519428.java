import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.io.IOException;
import java.util.NoSuchElementException;
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
        FasterScanner in = new FasterScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        public void solve(int testNumber, FasterScanner in, PrintWriter out) {
            final int n = in.nextInt();
            final int m = in.nextInt();

            Vertex[] vertices = new Vertex[n];

            for (int i = 0; i < n; i++) {
                vertices[i] = new Vertex();
            }

            for (int i = 0; i < m; i++) {
                int f = in.nextInt() - 1;
                int t = in.nextInt() - 1;

                vertices[f].setEdge(vertices[t]);
                vertices[t].setEdge(vertices[f]);
            }

            for (int i = 0; i < vertices[0].getDegree(); i++) {
                Vertex cv = vertices[0].getEdge(i).getVertex();
                for (int j = 0; j < cv.getDegree(); j++) {
                    if (cv.getEdge(j).getVertex() == vertices[n - 1]) {
                        out.println("POSSIBLE");
                        return;
                    }
                }
            }

            out.println("IMPOSSIBLE");
        }

    }

    static class FasterScanner {
        private InputStream in;
        private byte[] buffer;
        private int bufPointer;
        private int bufLength;

        public FasterScanner(InputStream in) {
            this.in = in;
            buffer = new byte[1024];
        }

        private boolean hasNextByte() {
            if (bufPointer < bufLength) return true;
            bufPointer = 0;
            try {
                bufLength = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            return (bufLength > 0);
        }

        private int readByte() {
            if (hasNextByte()) return buffer[bufPointer++];
            return -1;
        }

        private static boolean isPrintableChar(int c) {
            return (c >= 33 && c <= 126);
        }

        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[bufPointer])) bufPointer++;
            return hasNextByte();
        }

        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }

        public long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || b > '9') throw new NumberFormatException();

            while (true) {
                if (b >= '0' && b <= '9') {
                    n *= 10;
                    n += b - '0';
                } else if (b == -1 || !isPrintableChar(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }

    }

    static class Vertex {
        private int value;
        private List<Edge> edges = new ArrayList<Edge>();

        public Vertex() {
        }

        public Vertex(int v) {
            this.value = v;
        }

        public void setEdge(Vertex v) {
            this.edges.add(new Edge(v));
        }

        public int getDegree() {
            return this.edges.size();
        }

        public Edge getEdge(int index) {
            return this.edges.get(index);
        }

    }

    static class Edge {
        private Vertex vertex;
        private int cost;

        public Edge() {
        }

        public Edge(Vertex v) {
            this.vertex = v;
        }

        public Edge(Vertex v, int c) {
            this.vertex = v;
            this.cost = c;
        }

        public Vertex getVertex() {
            return this.vertex;
        }

    }
}