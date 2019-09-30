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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();

            if (n == 3) {
                out.printLine(61);
                return;
            }

            final long MOD = (long) 1e9 + 7;

            long[] dp = new long[1 << 8];
            Arrays.fill(dp, 1);
            for (int i = 0; i < 1 << 8; i++) {
                int[] a = new int[4];
                for (int j = 0; j < 4; j++) {
                    a[j] = (i >> (j * 2)) & 3;
                }

                if (a[0] == 0 && a[1] == 1 && a[2] == 2
                        || a[1] == 0 && a[2] == 1 && a[3] == 2) {
                    dp[i] = 0;
                }

                for (int j = 0; j < 3; j++) {
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;

                    if (a[0] == 0 && a[1] == 1 && a[2] == 2
                            || a[1] == 0 && a[2] == 1 && a[3] == 2) {
                        dp[i] = 0;
                    }

                    tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                }
            }

            for (int i = 0; i < n - 4; i++) {
                long[] next = new long[1 << 8];
                for (int j = 0; j < 1 << 8; j++) {
                    for (int k = 0; k < 4; k++) {
                        int cand = (j << 2) & ~(-1 << 8) | k;
                        if (dp[cand] == 0) continue;

                        next[cand] = (next[cand] + dp[j]) % MOD;
                    }
                }
                dp = next;
            }

            long ans = 0;
            for (int i = 0; i < 1 << 8; i++) {
                ans = (ans + dp[i]) % MOD;
            }

            out.printLine(ans);
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

        public int readInt() {
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

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
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

        public void printLine(long i) {
            writer.println(i);
        }

        public void printLine(int i) {
            writer.println(i);
        }

    }
}