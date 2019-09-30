import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.util.Set;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
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
        agc014d solver = new agc014d();
        solver.solve(1, in, out);
        out.close();
    }

    static class agc014d {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();

            Set[] g = new Set[n];

            for (int i = 0; i < n; i++) {
                g[i] = new TreeSet();
            }

            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt();
                int b = in.nextInt();

                a--;
                b--;

                g[a].add(b);
                g[b].add(a);
            }

            TreeSet<Integer> leaves = new TreeSet<>();

            for (int i = 0; i < n; i++) {
                int l = 0;
                for (int v : (Set<Integer>) g[i]) {
                    if (g[v].size() == 1) {
                        l++;
                        leaves.add(v);
                    }
                }

                if (l > 1) {
                    out.println("First");
                    return;
                }
            }

//        if (n % 2 == 1) {
//            out.println("First");
//            return;
//        }
//
//        Map<Integer, Integer> mp = new HashMap<>();
//
//        int rn = n;
//
//
//        int lev = 0;
//        while (rn > 0) {
//            Map<Integer, Integer> nmp = new HashMap<>();
//
//            TreeSet<Integer> nleaves = new TreeSet<>();
//
//            for (int l : leaves) {
//                if (g[l].size() <= 1) {
//                    if (g[l].size() == 1) {
//                        int v = ((TreeSet<Integer>) g[l]).first();
//                        g[v].remove(l);
//                        nmp.merge(v, 1, (x, y) -> x + y);
//                        nleaves.add(v);
//                    }
//                    rn--;
//                    if (lev % 2 == 1 && mp.getOrDefault(l, 0) > 1) {
//                        out.println("First");
//                        return;
//                    }
//                }
//            }
//
//            leaves = nleaves;
//            mp = nmp;
//            lev++;
//        }
//
//        out.println("Second");

            while (leaves.size() > 0) {
                int u = leaves.first();

                if (g[u].size() == 0) {
                    leaves.remove(u);
                    continue;
                }

                int v = ((TreeSet<Integer>) g[u]).first();

                g[v].remove(u);

                for (int ver : ((TreeSet<Integer>) g[v])) {
                    if (leaves.contains(ver)) {
                        out.println("First");
                        return;
                    }
                    g[ver].remove(v);

                    if (g[ver].size() == 0) {
                        out.println("First");
                        return;
                    }

                    if (g[ver].size() == 1) {
                        leaves.add(ver);
                    }
                }

                leaves.remove(u);
            }

            out.println("Second");
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