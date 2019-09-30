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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int l = in.nextInt();
            int n = in.nextInt();
            int[] a = new int[n];
            long[] sa = new long[n + 1];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                sa[i + 1] = sa[i] + a[i];
            }
            long res = l / 2;
            for (int it = 0; it < 2; ++it) {


                for (int i = 0; i < n; ++i) {
                    if (i == n - 1) {
                        res = Math.max(res, a[i]);
                        continue;
                    }

//                long ocur = a[i];
//                for (int j = i, k = n - 1, t = 0; j < k; ++t) {
//                    if (t % 2 == 0) {
//                        ocur += l + a[j] - a[k];
//                        ++j;
//                    } else {
//                        ocur += l + a[j] - a[k];
//                        --k;
//                    }
//                }

                    int m = (n - 1 - i) / 2;
                    m += 2;
                    while (i + m >= n - 1 - m) --m;
                    long firstHalf = sa[i + m + 1] - sa[i];
                    long secondHalf = sa[n] - sa[n - 1 - m];
                    long cur = firstHalf - secondHalf;
                    cur *= 2L;
                    cur += l * 2L * (long) (m + 1);
                    if (i + m + 1 < n - 1 - m)
                        cur += a[i + m + 1];
                    else
                        cur += a[n - 1 - m] - l;
//                Assert.assertTrue(cur == ocur);
                    if (cur > res)
                        res = cur;
                }

                for (int i = 0; i < n - i - 1; ++i) {
                    int t = a[i];
                    a[i] = a[n - i - 1];
                    a[n - i - 1] = t;
                }
                for (int i = 0; i < n; ++i) {
                    a[i] = l - a[i];
                }
                for (int i = 0; i < n; ++i) {
                    sa[i + 1] = sa[i] + a[i];
                }
            }
            out.printLine(res);
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
}