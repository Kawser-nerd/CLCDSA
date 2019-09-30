// package agc.agc013;

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

        int n = in.nextInt();
        int m = in.nextInt();
        
        int[][][] dp = new int[2][2][n+1];
        Arrays.fill(dp[0][0], 1);
        dp[0][0][0] = 0;
        dp[0][1][0] = 1;
        for (int i = 0; i < m ; i++) {
            int fr = i % 2;
            int to = 1 - fr;
            Arrays.fill(dp[to][0], 0);
            Arrays.fill(dp[to][1], 0);
            for (int f = 0 ; f <= 1 ; f++) {
                for (int r = 0; r <= n ; r++) {
                    int base = dp[fr][f][r];
                    int b = n-r;

                    if (r >= 1) {
                        // rr
                        add(dp, to, r == 1 ? 1 : f, r-1, base);

                        // rb
                        add(dp, to, r == 1 ? 1 : f, r, base);
                    }

                    if (b >= 1) {
                        // bb
                        add(dp, to, f, r+1, base);

                        // br
                        add(dp, to, f, r, base);
                    }
                }
            }
        }

        long ways = 0;
        for (int i = 0; i <= n ; i++) {
            ways += dp[m%2][1][i];
        }
        out.println(ways % MOD);
        out.flush();
    }

    static void add(int[][][] dp, int i, int j, int k, int a) {
        dp[i][j][k] += a;
        dp[i][j][k] -= dp[i][j][k] >= MOD ? MOD : 0;
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