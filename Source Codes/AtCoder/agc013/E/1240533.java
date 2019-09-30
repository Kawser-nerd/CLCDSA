// package atcoder.agc.agc013;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        long[][] mat0 = new long[4][4];
        long[][] mat1 = new long[4][4];
        for (int ball = 0 ; ball <= 3 ; ball++) {
            for (int nextBall = 0 ; (nextBall | ball) <= 3 ; nextBall++) {
                if ((nextBall & ball) != 0) {
                    continue;
                }
                for (int s = 0 ; s <= 1; s++) {
                    int nb = ball | nextBall;
                    if (s == 1 && nb != 3) {
                        continue;
                    }
                    if (s == 1) {
                        nb = 0;
                    }
                    mat0[nb][ball]++;
                    if (s == 0) {
                        mat1[nb][ball]++;
                    }
                }
            }
        }

        long[][] now = Matrix.e(4);
        
        int n = in.nextInt();
        int m = in.nextInt();
        int[] x = in.nextInts(m);
        int last = 0;
        for (int i = 0 ; i < m ; i++) {
            int to = x[i] - last - 1;
            now = Matrix.mul(Matrix.pow(mat0, to), now);
            now = Matrix.mul(mat1, now);
            last = x[i];
        }
        int to = n - last;
        now = Matrix.mul(Matrix.pow(mat0, to), now);

        out.println(now[3][0]);
        out.flush();
    }

    public static class Matrix {
        static final int MOD = 1000000007;
        static final long MOD2 = (long)MOD * MOD * 8;

        static long[][] e(int n) {
            long[][] mat = new long[n][n];
            for (int i = 0; i < n ; i++) {
                mat[i][i] = 1;
            }
            return mat;
        }

        static long[][] pow(long[][] x, long p) {
            int n = x.length;
            long[][] ret = e(n);
            while (p >= 1) {
                if ((p & 1) == 1) {
                    ret = mul(ret, x);
                }
                x = mul(x, x);
                p >>>= 1;
            }
            return ret;
        }

        static long[][] mul(long[][] a, long[][] b) {
            int n = a.length;
            int k = a[0].length;
            int m = b[0].length;

            long[][] ret = new long[n][m];
            long[] row = new long[m];
            for (int i = 0; i < n ; i++) {
                Arrays.fill(row, 0);
                for (int l = 0; l < k ; l++) {
                    for (int j = 0; j < m ; j++) {
                        row[j] += a[i][l] * b[l][j];
                        if (row[j] >= MOD2) {
                            row[j] -= MOD2;
                        }
                    }
                }
                for (int j = 0; j < m ; j++) {
                    ret[i][j] = (row[j] % MOD);
                }
            }
            return ret;
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