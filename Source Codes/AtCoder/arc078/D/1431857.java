import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            TaskF.Edge[] es = new TaskF.Edge[m];
            int ss = 0;
            int[][] cc = new int[n][n];
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1, c = in.nextInt();
                es[i] = new TaskF.Edge(a, b, c);
                ss += c;
                cc[a][b] = cc[b][a] = c;
            }
            int[] cost = new int[1 << n];
            for (int i = 0; i < 1 << n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        if (((i >> j) & 1) == 1 && ((i >> k) & 1) == 1) {
                            cost[i] += cc[j][k];
                        }
                    }
                }
            }

            int[][] dp = new int[n][1 << n];
            for (int[] x : dp) Arrays.fill(x, -(1 << 29));
            for (int i = 0; i < 1 << n; i++) {
                if (((i >> (n - 1)) & 1) == 0)
                    dp[0][i] = cost[i];
            }

            for (int cmask = 0; cmask < 1 << n; cmask++) {
                for (int cnode = 0; cnode < n; cnode++) {
                    if (((cmask >> cnode) & 1) == 0 || dp[cnode][cmask] < 0) continue;

                    int omask = ((1 << n) - 1) ^ cmask;
                    for (int nmask = omask; nmask != 0; nmask = (nmask - 1) & omask) {
                        for (int nnode = 0; nnode < n; nnode++) {
                            if (((nmask >> nnode) & 1) == 0 || cc[cnode][nnode] == 0) continue;
                            int t = dp[cnode][cmask] + cost[nmask] + cc[cnode][nnode];
                            if (t > dp[nnode][nmask | cmask]) {
                                dp[nnode][nmask | cmask] = t;
                            }
                        }
                    }
                }
            }

            out.println(ss - dp[n - 1][(1 << n) - 1]);
        }

        static class Edge {
            public int from;
            public int to;
            public int weight;

            public Edge(int from, int to, int weight) {
                this.from = from;
                this.to = to;
                this.weight = weight;
            }

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

        public void println(int i) {
            writer.println(i);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}