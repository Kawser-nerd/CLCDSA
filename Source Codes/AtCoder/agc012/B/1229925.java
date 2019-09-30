import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int n = in.nextInt();
        int m = in.nextInt();
        List<Integer> edges[] = new List[n];
        for (int i = 0; i < n; ++i) {
            edges[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            edges[a].add(b);
            edges[b].add(a);
        }
        int q = in.nextInt();
        int v[] = new int[q];
        int d[] = new int[q];
        int c[] = new int[q];
        for (int i = 0; i < q; ++i) {
            v[i] = in.nextInt() - 1;
            d[i] = in.nextInt();
            c[i] = in.nextInt();
        }
        int color[] = new int[n];
        int dist[] = new int[n];
        for (int i = q - 1; i >= 0; --i) {
            class Vertex {
                int v, d, c;

                Vertex(int v, int d, int c) {
                    this.v = v;
                    this.d = d;
                    this.c = c;
                }
            }
            Queue<Vertex> queue = new ArrayDeque<>();
            queue.add(new Vertex(v[i], d[i], c[i]));
            while (queue.size() > 0) {
                Vertex x = queue.poll();
                if (color[x.v] == 0) color[x.v] = x.c;
                if (dist[x.v] < x.d) {
                    for (Integer k : edges[x.v]) {
                        queue.add(new Vertex(k, x.d - 1, x.c));
                    }
                    dist[x.v] = x.d;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            out.println(color[i]);
        }
        out.flush();
    }

    class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int next() {
            if (numChars == -1) throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.