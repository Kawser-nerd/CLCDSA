import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        long res;
        int n;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            res = 0;
            Vertex[] vs = new Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new Vertex();
            }
            for (int i = 0; i < n - 1; ++i) {
                Vertex a = vs[in.nextInt() - 1];
                Vertex b = vs[in.nextInt() - 1];
                int c = in.nextInt();
                a.outgo.add(new TaskD.Edge(b, c));
                b.outgo.add(new TaskD.Edge(a, c));
            }
            Vertex root = vs[0];
            root.dfs1(null);
            Vertex center = root.findCenter(null);
            TaskD.Edge middleEdge = null;
            for (TaskD.Edge e : center.outgo) {
                if (e.dest.subtreeSize < center.subtreeSize && e.dest.subtreeSize * 2 == n) {
                    if (middleEdge != null) throw new RuntimeException();
                    middleEdge = e;
                }
            }
            if (middleEdge != null) {
                res -= middleEdge.length;
            } else {
                long best = 0;
                for (TaskD.Edge e : center.outgo) {
                    best = Math.max(best, res - e.length);
                }
                res = best;
            }
            out.println(res);
        }

        static class Edge {
            Vertex dest;
            int length;

            public Edge(Vertex dest, int length) {
                this.dest = dest;
                this.length = length;
            }

        }

        class Vertex {
            List<TaskD.Edge> outgo = new ArrayList<>();
            int subtreeSize = 0;

            public void dfs1(Vertex parent) {
                subtreeSize = 1;
                for (TaskD.Edge e : outgo)
                    if (e.dest != parent) {
                        e.dest.dfs1(this);
                        subtreeSize += e.dest.subtreeSize;
                        res += e.length * 2L * Math.min(e.dest.subtreeSize, n - e.dest.subtreeSize);
                    }
            }

            public Vertex findCenter(Vertex parent) {
                if (subtreeSize * 2 <= n) return null;
                for (TaskD.Edge e : outgo)
                    if (e.dest != parent) {
                        Vertex v = e.dest.findCenter(this);
                        if (v != null) return v;
                    }
                return this;
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}