import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author prakharjain
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        agc010c solver = new agc010c();
        solver.solve(1, in, out);
        out.close();
    }

    static class agc010c {
        List[] g;
        int[] a;
        boolean isp = true;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();

            a = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }

            g = new List[n];

            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList();
            }

            for (int i = 0; i < n - 1; i++) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;

                g[u].add(v);
                g[v].add(u);
            }

            long val = dfs(0, -1);

            if ((g[0].size() == 1 || val == 0) && isp) {
                out.print("YES");
            } else {
                out.print("NO");
            }
        }

        long dfs(int u, int p) {

            long sum = 0;
            int tot = 0;
            List<Long> rl = new ArrayList<>();

            for (int v : (List<Integer>) g[u]) {
                if (v != p) {
                    tot++;
                    long val = dfs(v, u);
                    sum += val;
                    rl.add(val);
                }
            }

            rl.sort((x, y) -> (int) Math.signum(x - y));

            long minsum = 0;

            if (tot == 0) {
                return a[u];
            }

            if (tot == 1) {
                if (sum != a[u]) {
                    isp = false;
                    return -1;
                } else {
                    return sum;
                }
            }

            for (int i = 0; i < rl.size() - 1; i++) {
                minsum += rl.get(i);
            }

            if (sum < a[u]) {
                isp = false;
                return -1;
            }

            if (sum == a[u]) {
                return sum;
            }

            if (sum > a[u]) {
                long rem = sum - a[u];
                if (rem <= a[u] && 2 * rem <= sum && minsum >= rem) {
                    return a[u] - rem;
                } else {
                    isp = false;
                    return -1;
                }
            }

            return -1;
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void close() {
            writer.close();
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

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
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

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.