// package atcoder.agc.agc005;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    private static final int MOD = 924844033;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int k = in.nextInt();

        // cnt,post,last
        int TAIL = 2001;
        int[][][] dp = new int[2][2010][2010];
        dp[0][0][0] = 1;
        for (int f = 0; f < Math.min(n, 2*k) ; f++) {
            for (int ct = 0 ; ct <= n ; ct++) {
                for (int x = f ; ; x += 2*k) {
                    boolean gonext = (x + 2*k >= n);
                    int next = gonext ? f+1 : x + 2*k;
                    int flg = gonext ? 0 : 1;
                    if (gonext && f+1 == Math.min(n, 2*k)) {
                        next = TAIL;
                    }

                    for (int l = 0; l <= 1; l++) {
                        if (dp[l][ct][x] == 0) {
                            continue;
                        }
                        int base = dp[l][ct][x];
                        dp[0][ct][next] = (dp[0][ct][next]+base)%MOD;
                        if (l == 0 && x-k >= 0) {
                            dp[0][ct+1][next] = (dp[0][ct+1][next]+base)%MOD;
                        }
                        if (x+k < n) {
                            dp[1&flg][ct+1][next] = (dp[1&flg][ct+1][next]+base)%MOD;
                        }
                    }

                    if (gonext) {
                        break;
                    }
                }
            }
        }

        long[] fact = new long[2001];
        fact[0] = 1;
        for (int i = 1 ; i < fact.length ; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }

        long ans = 0;
        for (int i = 0; i <= n; i++) {
            long ptn = dp[0][i][TAIL] % MOD * fact[n-i] % MOD;
            ans += (i % 2 == 0) ? ptn : (MOD - ptn);
        }
        ans %= MOD;

        out.println(ans);
        out.flush();
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