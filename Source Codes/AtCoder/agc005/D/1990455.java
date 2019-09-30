// package agc.agc005;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    private static final long MOD = 924844033;

    public static void add(long[][][] dp, int i, int j, int k, long x) {
        dp[i][j][k] += x;
        if (dp[i][j][k] >= MOD) {
            dp[i][j][k] -= MOD;
        }
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int k = in.nextInt();

        long[][][] dp = new long[2][2][n+1];
        dp[0][0][0] = 1;
        {
            int num = 0;
            int grpi = 0;
            for (int i = 0; i < n; i++) {
                int lw = num - k;
                int hi = num + k;
                int ne = num + 2 * k;

                int fr = i % 2;
                int to = 1 - fr;
                for (int j = 0; j < 2 ; j++) {
                    Arrays.fill(dp[to][j], 0);
                }
                for (int last = 0 ; last <= 1 ; last++) {
                    for (int wrongCount = 0 ; wrongCount < n ; wrongCount++) {
                        long base = dp[fr][last][wrongCount];
                        if (base == 0) {
                            continue;
                        }

                        add(dp, to, 0, wrongCount, base);
                        if (lw >= 0 && last == 0) {
                            add(dp, to, 0, wrongCount+1, base);
                        }
                        if (hi < n) {
                            add(dp, to, (ne >= n) ? 0 : 1, wrongCount+1, base);
                        }
                    }
                }
                num += 2 * k;
                if (num >= n) {
                    num = ++grpi;
                }
            }
        }

        long[] fact = new long[n+1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }

        long total = 0;
        for (int i = 0; i <= n ; i++) {
            long w = dp[n%2][0][i] + dp[n%2][1][i];
            w %= MOD;
            w *= fact[n-i];
            w %= MOD;
            if (i % 2 == 0) {
                total += w;
            } else {
                total += MOD - w;
            }
            total %= MOD;
        }

        out.println(total);
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