import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashSet;
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
        DGridGame solver = new DGridGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class DGridGame {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int h = in.nextInt();
            int w = in.nextInt();
            int n = in.nextInt();

            TreeSet[] pairs = new TreeSet[h];

            for (int i = 0; i < h; i++) {
                pairs[i] = new TreeSet();
            }

            for (int i = 0; i < n; i++) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;

                pairs[x].add(y);
            }

            Set<Integer> csa = new HashSet<>();
            Set<Integer> csr = new HashSet<>();

            csa.add(0);
            csr.add(0);

            for (int i = 1; i < h; i++) {
                TreeSet<Integer> cts = (TreeSet<Integer>) pairs[i];
                for (Integer num : cts) {
                    if (csa.contains(num)) {
                        out.println(i);
                        return;
                    }
                }

                Set<Integer> ns = new HashSet<>();

                for (Integer num : csr) {
                    if (!cts.contains(num + 1) && num + 1 < w) {
                        csa.add(num + 1);
                        if (num + 2 < w && !csa.contains(num + 2)) {
                            ns.add(num + 1);
                        }
                    } else if (num + 1 < w) {
                        ns.add(num);
                    }
                }

                csr = ns;
            }

            out.println(h);
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