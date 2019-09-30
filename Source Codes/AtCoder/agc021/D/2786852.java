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
 * @author prakharjain
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        agc021_d solver = new agc021_d();
        solver.solve(1, in, out);
        out.close();
    }

    static class agc021_d {
        public void solve(int testNumber, InputReader in, OutputWriter out) {

            String s = in.next();

            int n = s.length();

            int k = in.nextInt();

            int[][][] dp = new int[n][n][k + 1];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int l = 0; l <= k; l++) {
                        dp[i][j][l] = -1;
                    }
                }
            }

            out.println(rec(dp, 0, n - 1, k, s));
        }

        int rec(int[][][] dp, int i, int j, int k, String s) {
            if (i > j)
                return 0;

            if (dp[i][j][k] != -1)
                return dp[i][j][k];

            if (i == j) {
                return dp[i][j][k] = 1;
            }

            int ans = 0;
            if (s.charAt(i) == s.charAt(j)) {
                ans = 2 + rec(dp, i + 1, j - 1, k, s);
            } else {
                ans = Math.max(rec(dp, i, j - 1, k, s), rec(dp, i + 1, j, k, s));
                if (k > 0) {
                    ans = Math.max(ans, 2 + rec(dp, i + 1, j - 1, k - 1, s));
                }

            }

            return dp[i][j][k] = ans;
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
}