import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ilyakor
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static final int mod = 1000 * 1000 * 1000 + 7;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt() + 2;
            long a = in.nextLong();
            long b = in.nextLong();
            if (a > b) {
                long t = a;
                a = b;
                b = t;
            }
            long[] s = new long[n];
            for (int i = 1; i < n - 1; ++i)
                s[i] = in.nextLong();
            s[0] = Long.MIN_VALUE / 3;
            s[n - 1] = Long.MAX_VALUE / 3;
            for (int i = 0; i + 2 < n; ++i)
                if (s[i + 2] - s[i] < a) {
                    out.printLine(0);
                    return;
                }
            int[] cntA = new int[n + 1];
            int[] cntB = new int[n + 1];
            for (int i = n - 1; i >= 0; --i) {
                if (i < n - 1 && s[i + 1] - s[i] >= a)
                    cntA[i] = cntA[i + 1] + 1;
                else
                    cntA[i] = 1;
                if (i < n - 1 && s[i + 1] - s[i] >= b)
                    cntB[i] = cntB[i + 1] + 1;
                else
                    cntB[i] = 1;
            }

            int ra = 0, rb = 0;
            long[] dsa = new long[n + 1];
            long[] dsb = new long[n + 1];
            long curA = 0;
            long curB = 0;
            dsb[0] = 1;
            dsb[1] = mod - 1;
            for (int i = 0; i < n; ++i) {
//            while (ra < n && s[ra] - s[i] < a) ++ra;
                while (rb < n && s[rb] - s[i] < b) ++rb;

//            curA += dsa[i];
//            curA = (curA % mod + mod) % mod;
                curB += dsb[i];
                curB = (curB % mod + mod) % mod;

                {
                    int l = rb;
                    int r = i + 1 + cntA[i + 1];
                    if (r > n - 1) r = n - 1;
                    if (l <= r) {
                        dsb[l] += curB;
                        dsb[l] = (dsb[l] % mod + mod) % mod;
                        dsb[r + 1] -= curB;
                        dsb[r + 1] = (dsb[r + 1] % mod + mod) % mod;
                    }
                }
            }
            out.printLine(curB);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buffer = new byte[10000];
        private int cur;
        private int count;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public static boolean isSpace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int read() {
            if (count == -1) {
                throw new InputMismatchException();
            }
            try {
                if (cur >= count) {
                    cur = 0;
                    count = stream.read(buffer);
                    if (count <= 0)
                        return -1;
                }
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            return buffer[cur++];
        }

        public int readSkipSpace() {
            int c;
            do {
                c = read();
            } while (isSpace(c));
            return c;
        }

        public int nextInt() {
            int sgn = 1;
            int c = readSkipSpace();
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10 + c - '0';
                c = read();
            } while (!isSpace(c));
            res *= sgn;
            return res;
        }

        public long nextLong() {
            long sgn = 1;
            int c = readSkipSpace();
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10L + (long) (c - '0');
                c = read();
            } while (!isSpace(c));
            res *= sgn;
            return res;
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

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}