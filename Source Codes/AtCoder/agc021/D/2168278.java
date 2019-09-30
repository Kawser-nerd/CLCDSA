// package agc.agc021;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    public static void updMax(int[][][] dp, int i, int j, int k, int a) {
        dp[i][j][k] = Math.max(dp[i][j][k], a);
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        char[] s = in.nextToken().toCharArray();
        int k = in.nextInt();

        int n = s.length;

        // dp[i][j][k]: i < j
        int[][][] dp = new int[n][n+1][k+1];
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        dp[0][n-1][0] = 0;

        for (int i = 0; i < n ; i++) {
            for (int j = n-1 ; j > i ; j--) {
                for (int l = 0; l <= k ; l++) {
                    if (dp[i][j][l] == -1) {
                        continue;
                    }
                    int base = dp[i][j][l];
                    if (i+1 <= j) {
                        updMax(dp, i+1, j, l, base);
                    }
                    if (i <= j-1) {
                        updMax(dp, i, j-1, l, base);
                    }
                    if (s[i] != s[j]) {
                        if (l+1 <= k) {
                            updMax(dp, i+1, j-1, l+1, base+2);
                        }
                    } else {
                        updMax(dp, i+1, j-1, l, base+2);
                    }
                }
            }
        }

        int best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n ; j++) {
                for (int l = 0; l <= k; l++) {
                    best = Math.max(best, dp[i][j][l] + ((i == j) ? 1 : 0));
                }
            }
        }
        out.println(best);
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