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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static final int mod = 1000 * 1000 * 1000 + 7;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            long[][] d = new long[n][n];
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] = (a[i] < a[j] ? 1 : 0);
            long inv2 = IntegerUtils.pow(2, mod - 2, mod);
            for (int it = 0; it < q; ++it) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                Assert.assertTrue(x != y);
                for (int i = 0; i < n; ++i) {
                    if (i == x || i == y) continue;
                    d[i][x] = (((d[i][x] + d[i][y]) * inv2) % mod);
                    d[i][y] = d[i][x];
                    d[x][i] = (((d[x][i] + d[y][i]) * inv2) % mod);
                    d[y][i] = d[x][i];
                }
                long val = (d[x][y] + d[y][x]) * inv2;
                val %= mod;
                d[x][y] = val;
                d[y][x] = val;
            }
            long mult = IntegerUtils.pow(2, q, mod);
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                System.err.print((d[i][j] * (long) mult) % mod + " ");
//            }
//            System.err.println();
//        }
//        System.err.flush();
            long res = 0;
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j) {
                    res += d[j][i];
                    res %= mod;
                }
//        for (int i = 0; i < 30; ++i)
//            System.err.println(i + ": " + (res * IntegerUtils.pow(2, i, mod)) % mod);
            res *= mult;
            res %= mod;
            out.printLine(res);
        }

    }

    static class IntegerUtils {
        public static int pow(long x, long y, int mod) {
            x %= mod;
            long res = 1;
            while (y > 0) {
                if (y % 2 == 1) {
                    --y;
                    res = (res * x) % mod;
                } else {
                    y /= 2;
                    x = (x * x) % mod;
                }
            }
            return (int) (res % mod);
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

    static class Assert {
        public static void assertTrue(boolean flag) {
//        if (!flag)
//        while (true);
            if (!flag)
                throw new AssertionError();
        }

    }
}