// package atcoder.agc.agc018;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    static final long MOD = 1000000007;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        prec(2000050);

        int[] xs = in.nextInts(6);
        int[] ys = in.nextInts(6);

        long H = ys[3]-ys[2]+1;
        long W = xs[3]-xs[2]+1;

        int[][] fp = new int[][]{
                {xs[0]-1, ys[0]-1, 1},
                {xs[1], ys[0]-1, -1},
                {xs[0]-1, ys[1], -1},
                {xs[1], ys[1], 1}
        };
        int[][] tp = new int[][]{
                {xs[4], ys[4], 1},
                {xs[4], ys[5]+1, -1},
                {xs[5]+1, ys[4], -1},
                {xs[5]+1, ys[5]+1, 1}
        };

        long ans = 0;
        for (int[] f : fp) {
            for (int[] t : tp) {
                int[][] bo = new int[2][2];
                int[][] to = new int[2][2];
                int[][] le = new int[2][2];
                int[][] ri = new int[2][2];
                for (int x = xs[2] ; x <= xs[3] ; x++) {
                    // bottom
                    bo[0][0] = x;
                    bo[0][1] = ys[2]-1;
                    bo[1][0] = x;
                    bo[1][1] = ys[2];
                    long B = (MOD+xs[2]-x)%MOD;
                    ans += way(f, bo[0], f[2]) * way(bo[1], t, t[2]) % MOD * B % MOD;

                    // top
                    to[0][0] = x;
                    to[0][1] = ys[3];
                    to[1][0] = x;
                    to[1][1] = ys[3]+1;
                    long T = (H+x-xs[2])%MOD;
                    ans += way(f, to[0], f[2]) * way(to[1], t, t[2]) % MOD * T % MOD;

                    ans %= MOD;
                }

                for (int y = ys[2] ; y <= ys[3] ; y++) {
                    // left
                    le[0][0] = xs[2]-1;
                    le[0][1] = y;
                    le[1][0] = xs[2];
                    le[1][1] = y;
                    long L = (MOD+ys[2]-y)%MOD;
                    ans += way(f, le[0], f[2]) * way(le[1], t, t[2]) % MOD * L % MOD;

                    // right
                    ri[0][0] = xs[3];
                    ri[0][1] = y;
                    ri[1][0] = xs[3]+1;
                    ri[1][1] = y;
                    long R = (W+y-ys[2])%MOD;
                    ans += way(f, ri[0], f[2]) * way(ri[1], t, t[2]) % MOD * R % MOD;

                    ans %= MOD;
                }
            }
        }


        out.println(ans);
        out.flush();
    }

    static long way(int[] from, int[] to, int sign) {
        int dx = Math.abs(from[0]-to[0]);
        int dy = Math.abs(from[1]-to[1]);
        long a = comb(dx+dy, dx);
        if (sign == -1) {
            a = (MOD - a) % MOD;
        }
        return a;
    }

    static int[][] rectToPoints(int fx, int fy, int tx, int ty) {
        return new int[][] {
                {fx, fy, 1},
                {fx, ty+1, -1},
                {tx+1, fy, -1},
                {tx+1, ty+1, 1}
        };
    }

    static long pow(long a, long x) {
        long res = 1;
        while (x > 0) {
            if (x%2 != 0) {
                res = (res*a)%MOD;
            }
            a = (a*a)%MOD;
            x /= 2;
        }
        return res;
    }

    static long inv(long a) {
        return pow(a, MOD-2)%MOD;
    }

    static long[] _fact;
    static long[] _invfact;

    static long comb(long ln, long lr) {
        int n = (int) ln;
        int r = (int) lr;
        if (n < 0 || r < 0 || r > n) {
            return 0;
        }
        if (r > n/2) {
            r = n-r;
        }
        return (((_fact[n]*_invfact[n-r])%MOD)*_invfact[r])%MOD;
    }

    static void prec(int n) {
        _fact = new long[n+1];
        _invfact = new long[n+1];
        _fact[0] = 1;
        _invfact[0] = 1;
        for (int i = 1; i <= n; i++) {
            _fact[i] = _fact[i-1]*i%MOD;
            _invfact[i] = inv(_fact[i]);
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