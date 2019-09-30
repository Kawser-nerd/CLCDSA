// package atcoder.agc.agc004;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int h = in.nextInt();
        int w = in.nextInt();

        int ey = -1;
        int ex = -1;
        char[][] cmap = new char[h][];
        for (int i = 0; i < h ; i++) {
            cmap[i] = in.nextToken().toCharArray();
            for (int j = 0; j < w ; j++) {
                if (cmap[i][j] == 'E') {
                    ey = i;
                    ex = j;
                }
            }
        }

        imos = new int[h+1][w+1];
        for (int i = 0; i < h ; i++) {
            for (int j = 0; j < w ; j++) {
                imos[i+1][j+1] = imos[i+1][j] + imos[i][j+1] - imos[i][j] + ((cmap[i][j] == 'o') ? 1 : 0);
            }
        }

        int U = ey;
        int D = h - U - 1;
        int L = ex;
        int R = w - L - 1;

        int[][][][] dp = new int[U+1][D+1][L+1][R+1];
        for (int u = 0; u <= U ; u++) {
            for (int d = 0; d <= D; d++) {
                for (int l = 0; l <= L; l++) {
                    Arrays.fill(dp[u][d][l], -1);
                }
            }
        }
        dp[0][0][0][0] = 0;

        for (int u = 0; u <= U ; u++) {
            for (int d = 0; d <= D ; d++) {
                for (int l = 0; l <= L ; l++) {
                    for (int r = 0; r <= R ; r++) {
                        int base = dp[u][d][l][r];
                        if (base < 0) {
                            continue;
                        }
                        int tu = Math.max(ey-u, d);
                        int td = Math.min(ey+d, h-u-1);
                        int tl = Math.max(ex-l, r);
                        int tr = Math.min(ex+r, w-l-1);

                        if (u < U && d <= ey-u-1) {
                            dp[u+1][d][l][r] = Math.max(dp[u+1][d][l][r], base + inclusiveSum(ey-u-1, ey-u-1, tl, tr));
                        }
                        if (d < D && u <= (h-1)-(ey+d+1)) {
                            dp[u][d+1][l][r] = Math.max(dp[u][d+1][l][r], base + inclusiveSum(ey+d+1, ey+d+1, tl, tr));
                        }
                        if (l < L && r <= ex-l-1) {
                            dp[u][d][l+1][r] = Math.max(dp[u][d][l+1][r], base + inclusiveSum(tu, td, ex-l-1, ex-l-1));
                        }
                        if (r < R && l <= (w-1)-(ex+r+1)) {
                            dp[u][d][l][r+1] = Math.max(dp[u][d][l][r+1], base + inclusiveSum(tu, td, ex+r+1, ex+r+1));
                        }
                    }
                }
            }
        }

        int max = 0;
        for (int u = 0; u <= U ; u++) {
            for (int d = 0; d <= D; d++) {
                for (int l = 0; l <= L; l++) {
                    for (int r = 0; r <= R; r++) {
                        max = Math.max(max, dp[u][d][l][r]);
                    }
                }
            }
        }
        out.println(max);
        out.flush();
    }

    static int[][] imos;

    static int inclusiveSum(int u, int d, int l, int r) {
        if (u > d) {
            return 0;
        }
        if (l > r) {
            return 0;
        }
        return imos[d+1][r+1] - imos[d+1][l] - imos[u][r+1] + imos[u][l];
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