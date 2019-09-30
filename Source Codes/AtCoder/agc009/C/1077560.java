// package atcoder.agc.agc009;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    private static final long MOD = 1000000007;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long A = in.nextLong();
        long B = in.nextLong();
        long[] S = in.nextLongs(n);
        if (n == 1) {
            out.println(2);
            out.flush();
            return;
        }

        S = Arrays.copyOf(S, n+1);
        S[n] = (long)9e18;

        long X = Math.min(A, B);
        long Y = Math.max(A, B);
        long[][] dp = new long[n+1][2];
        int[] canX = doit(S, X);
        dp[0][0] = 1;
        dp[1][1] = 1;
        for (int i = 2 ; i <= n ; i++) {
            dp[i][1] = canX[0] >= i-1 ? 1 : 0;
        }

        long[] summation = new long[n+10];
        int ti = 0;
        for (int i = 0; i <= n ; i++) {
            dp[i][1] += summation[i];
            dp[i][1] %= MOD;
            summation[i+1] = (summation[i+1]+summation[i]+MOD)%MOD;

            if (i == n) {
                continue;
            }

            while (ti < n && S[ti] - S[i] < Y) {
                ti++;
            }

            // should be ok for X : i+1, i+2, ..., ti-1
            if (i+1 < ti && canX[i+1] < ti-1) {
                continue;
            }

            for (int j = 0; j < 2; j++) {
                if (dp[i][j] == 0) {
                    continue;
                }
                long base = dp[i][j];
                if (S[i+1] - S[i] >= Y) {
                    dp[i+1][0] += base;
                    dp[i+1][0] %= MOD;
                }

                if (j == 1 && S[i+1] - S[i-1] < X) {
                    continue;
                }

                int ok = Math.max(ti, i+2);
                int ng = canX[i+1]+2;
                if (ok <= ng) {
                    // debug(i, j, base, ok, ng);
                    summation[ok] += base;
                    summation[ok] %= MOD;
                    summation[ng] += (MOD-base)%MOD;
                    summation[ng] %= MOD;
                }
            }
        }
        out.println((dp[n][0]+dp[n][1])%MOD);
        out.flush();
    }

    static int[] doit(long[] S, long X) {
        int n = S.length-1;
        int[] canX = new int[n+1];
        for (int i = 0 ; i < n ; ) {
            int ti = i;
            while (ti+1 <= n &&  S[ti+1] - S[ti] >= X) {
                ti++;
            }
            for (int j = i ; j <= ti ; j++) {
                canX[j] = ti;
            }
            i = ti+1;
        }
        canX[n-1] = n;
        canX[n] = n;
        return canX;
    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int[] nextInts(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        private int[][] nextIntTable(int n, int m) {
            int[][] ret = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i][j] = nextInt();
                }
            }
            return ret;
        }

        private long[] nextLongs(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }

        private long[][] nextLongTable(int n, int m) {
            long[][] ret = new long[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i][j] = nextLong();
                }
            }
            return ret;
        }

        private double[] nextDoubles(int n) {
            double[] ret = new double[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextDouble();
            }
            return ret;
        }

        private int next() {
            if (numChars == -1)
                throw new InputMismatchException();
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
            int c = next();
            while (isSpaceChar(c))
                c = next();
            if ('a' <= c && c <= 'z') {
                return (char) c;
            }
            if ('A' <= c && c <= 'Z') {
                return (char) c;
            }
            throw new InputMismatchException();
        }

        public String nextToken() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }

        public long nextLong() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}