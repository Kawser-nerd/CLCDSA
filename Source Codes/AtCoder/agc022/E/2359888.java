// package agc.agc022;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    private static final int MOD = 1000000007;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int[][] thetable = new int[][]{
                {1, 2}, // 0 = ""
                {3, 4}, // 1 = "0"
                {5, 6}, // 2 = "1",
                {1, 1}, // 3 = "00",
                {1, 2}, // 4 = "01",
                {7, 2}, // 5 = "10",
                {6, 6}, // 6 = "11",
                {5, 5}, // 7 = "100
        };

        char[] s = in.nextToken().toCharArray();
        int n = s.length;
        int S = thetable.length;
        int[][] dp = new int[2][S];
        dp[0][0] = 1;
        for (int i = 0; i < n ; i++) {
            int fr = i % 2;
            int to = 1 - fr;
            Arrays.fill(dp[to], 0);
            for (int j = 0; j < S ; j++) {
                int base = dp[fr][j];
                if (base == 0) {
                    continue;
                }
                // zero
                if (s[i] == '0' || s[i] == '?') {
                    dp[to][thetable[j][0]] += base;
                    dp[to][thetable[j][0]] %= MOD;
                }

                // one
                if (s[i] == '1' || s[i] == '?') {
                    dp[to][thetable[j][1]] += base;
                    dp[to][thetable[j][1]] %= MOD;
                }
            }
        }

        out.println((dp[n%2][6] + dp[n%2][2]) % MOD);
        out.flush();
    }

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
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
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}