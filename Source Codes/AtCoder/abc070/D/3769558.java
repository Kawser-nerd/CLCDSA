import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Queue;
import java.util.LinkedList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        DTransitTreePath solver = new DTransitTreePath();
        solver.solve(1, in, out);
        out.close();
    }

    static class DTransitTreePath {
        List<Edge>[] graph;
        long[] dist;
        boolean[] visited;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            graph = new ArrayList[n + 1];
            dist = new long[n + 1];
            visited = new boolean[n + 1];

            for (int i = 0; i < n + 1; i++) {
                graph[i] = new ArrayList<>();
            }

            for (int i = 1; i < n; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                int w = in.nextInt();
                graph[u].add(new Edge(v, w));
                graph[v].add(new Edge(u, w));
            }

            Queue<Integer> q = new LinkedList<>();
            int Q = in.nextInt();
            int k = in.nextInt();
            q.add(k);
            dist[k] = 0;
            visited[k] = true;
            while (!q.isEmpty()) {
                int u = q.poll();
                for (Edge e : graph[u]) {
                    if (!visited[e.to]) {
                        dist[e.to] = dist[u] + e.w;
                        visited[e.to] = true;
                        q.add(e.to);
                    }
                }
            }

            for (int i = 0; i < Q; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                long distance = dist[u] + dist[v];
                out.println(distance);
            }
        }

        class Edge {
            int to;
            int w;

            public Edge(int to, int w) {
                this.to = to;
                this.w = w;
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.