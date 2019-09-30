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
        AC_GC_22_C solver = new AC_GC_22_C();
        solver.solve(1, in, out);
        out.close();
    }

    static class AC_GC_22_C {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();

            int[] a = new int[n];
            int[] b = new int[n];

            for (int i = 0; i < n; i++)
                a[i] = in.nextInt();

            for (int i = 0; i < n; i++)
                b[i] = in.nextInt();

            Set[] sa = new Set[n];

            for (int i = 0; i < n; i++) {
                sa[i] = new HashSet();
                sa[i].add(a[i]);
            }

            long ans = 0;
            int i;
            for (i = 50; i >= 1; i--) {
                boolean isreq = false;
                for (int j = 0; j < n; j++) {
                    isreq |= isreq(sa[j], i, b[j]);
                    if (isreq)
                        break;
                }

                if (isreq) {
                    ans += (1l << i);
                    for (int j = 0; j < n; j++) {
                        sa[j] = mod(sa[j], i);
                    }
                }

                boolean done = true;
                for (int j = 0; j < n; j++) {
                    if (!sa[j].contains(b[j])) {
                        done = false;
                        break;
                    }
                }

                if (done)
                    break;
            }

            if (i == 0) {
                out.println(-1);
                return;
            }
            out.println(ans);
        }

        boolean isreq(Set<Integer> set, int k, int b) {
            if (set.contains(b))
                return false;

            for (Integer num : set) {
                if (isposs(num, b, k - 1))
                    return false;
            }

            return true;
        }

        boolean isposs(int num, int b, int k) {
            if (num <= 2 * b)
                return false;

            if (num - b <= k)
                return true;

            for (int j = k; j >= 1; j--) {
                int n2 = num % j;

                if (n2 == b)
                    return true;

                if (n2 > 2 * b) {
                    return true;
                }
            }

            return false;
        }

        Set<Integer> mod(Set<Integer> set, int k) {
            Set<Integer> nset = new HashSet<>(set);
            for (Integer num : set) {
                nset.add(num % k);
            }
            return nset;
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

        public void println(int i) {
            writer.println(i);
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.