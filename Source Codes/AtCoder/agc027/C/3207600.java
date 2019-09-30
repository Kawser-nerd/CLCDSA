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
import java.util.ArrayDeque;
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
        agc027c solver = new agc027c();
        solver.solve(1, in, out);
        out.close();
    }

    static class agc027c {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            String s = in.next();

            DsuInteger dsu = new DsuInteger(n);

            for (int i = 0; i < n; i++) {
                dsu.createSet(i);
            }

            int[] isa = new int[n];
            int[] isb = new int[n];

            List[] g = new List[n];

            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList();
            }

            boolean[] iss = new boolean[n];

            int ca = 0, cb = 0;
            for (int i = 0; i < m; i++) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;

                if (u == v) {
                    iss[u] = true;
                    if (s.charAt(u) == 'A') {
                        isa[u]++;
                    } else {
                        isb[u]++;
                    }
                    continue;
                }

                if (s.charAt(u) == 'A') {
                    isa[v]++;
                } else {
                    isb[v]++;
                }

                if (s.charAt(v) == 'A') {
                    isa[u]++;
                } else {
                    isb[u]++;
                }

                g[u].add(v);
                g[v].add(u);
            }

            ArrayDeque<Integer> dq = new ArrayDeque<>();

            for (int i = 0; i < n; i++) {
                if (isa[i] == 0 || isb[i] == 0) {
                    dq.addLast(i);
                }
            }

            boolean[] isd = new boolean[n];
            while (dq.size() > 0) {
                int ele = dq.removeFirst();

                isd[ele] = true;

                char ch = s.charAt(ele);

                for (int v : (List<Integer>) g[ele]) {
                    if (!isd[v]) {
                        if (ch == 'A') {
                            isa[v]--;
                            if (isa[v] <= 0) {
                                dq.addLast(v);
                            }
                        } else {
                            isb[v]--;
                            if (isb[v] <= 0) {
                                dq.addLast(v);
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                if (!isd[i]) {
                    if (s.charAt(i) == 'A') {
                        ca++;
                        if (iss[i])
                            ca++;
                    } else {
                        cb++;
                        if (iss[i])
                            cb++;
                    }
                }
            }

            if (ca >= 2 && cb >= 2) {
                out.println("Yes");
            } else {
                out.println("No");
            }

        }

        class DsuInteger {
            int[] parent;
            int[] rank;
            int n;

            public DsuInteger(int n) {
                this.n = n;
                this.parent = new int[n];
                this.rank = new int[n];
            }

            int createSet(int x) {
                parent[x] = x;
                rank[x] = 0;
                return x;
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

        public String nextString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public String next() {
            return nextString();
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.