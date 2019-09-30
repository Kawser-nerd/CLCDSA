import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.stream.LongStream;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = new long[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextLong();
            }
            long steps = Arrays.stream(a).sum() - n * (n - 1);
            if (steps < 0) {
                steps = 0;
            }
            long[] b = new long[n];
            long total = 0;
            for (int i = 0; i < n; ++i) {
                long choose = 0;
                for (long step = 1L << 55; step > 0; step /= 2) {
                    long curr = choose + step;
                    long nvalue = a[i] + (steps - curr) - curr * n;
                    if (total + curr <= steps && nvalue >= 0) {
                        choose += step;
                    }
                }
                b[i] = choose;
                total += choose;
            }
            long ans = 0;
            for (int i = 0; i < n; ++i) {
                a[i] -= b[i] * n;
                for (int j = 0; j < n; ++j) {
                    if (i != j) {
                        a[j] += b[i];
                    }
                }
                ans += b[i];
            }
            if (total != steps) {
                throw new RuntimeException();
            }

            while (true) {
                int pos = -1;
                for (int i = 0; i < n; ++i) {
                    if (a[i] >= n) {
                        pos = i;
                        break;
                    }
                }
                if (pos == -1) {
                    break;
                }
                long add = a[pos] / n;
                ans += add;
                a[pos] %= n;
                for (int i = 0; i < n; ++i) {
                    if (i != pos) {
                        a[i] += add;
                    }
                }
            }
            out.println(ans);
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
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}