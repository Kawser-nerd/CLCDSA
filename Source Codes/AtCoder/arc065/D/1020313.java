// package atcoder.arc.arc065;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    private static final long MOD = 1000000007;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        char[] s = in.nextToken().toCharArray();

        int[][] op = new int[m][2];
        for (int i = 0; i < m ; i++) {
            op[i][0] = in.nextInt()-1;
            op[i][1] = in.nextInt()-1;
        }

        int[] lmax = new int[n];
        Arrays.fill(lmax, -1);
        for (int i = 0; i < m ; i++) {
            lmax[op[i][0]] = Math.max(lmax[op[i][0]], op[i][1]);
        }

        List<int[]> q = new ArrayList<>();
        int maxR = -1;
        for (int i = 0; i < n ; i++) {
            if (lmax[i] <= maxR) {
                continue;
            }
            q.add(new int[]{i, lmax[i]});
            maxR = lmax[i];
        }

        int[] imos = new int[n+1];
        for (int i = 0; i < n ; i++) {
            imos[i+1] = imos[i] + (s[i] == '0' ? 1 : 0);
        }


        for (int[] qqq : q) {
            //debug(qqq);
        }

        int tail = -1;
        int qi = 0;
        int qn = q.size();
        long[][] dp = new long[2][n+1];
        dp[0][0] = 1;

        int dec = 0;
        int freeOne = 0;
        int filledZero = 0;
        for (int i = 0; i < n ; i++) {
            int fr = i % 2;
            int to = 1 - fr;

            if (qi < qn) {
                int[] pa = q.get(qi);
                if (pa[0] == i) {
                    int from = Math.max(tail+1, pa[0]);
                    int ttail = pa[1];
                    // debug(i, "add",from,ttail,imos[ttail+1] - imos[from]);
                    int zcnt = imos[ttail+1] - imos[from];

                    freeOne += ttail+1-from-zcnt;
                    filledZero += zcnt;

                    //debug(freeOne);


                    tail = ttail;

                    // copy
                    Arrays.fill(dp[to], 0);
                    for (int f = 0 ; f+zcnt <= n ; f++) {
                        dp[to][f+zcnt] = dp[fr][f];
                    }
                    for (int j = 0; j < n ; j++) {
                        dp[fr][j] = dp[to][j];
                    }
                    qi++;
                }
            }

//            debug(i, tail);
//            debug(dp[fr]);

            Arrays.fill(dp[to], 0);
            for (int f = 0 ; f <= n ; f++) {
                if (dp[fr][f] == 0) {
                    continue;
                }
                long base = dp[fr][f];
                int usedZero = filledZero - f;
                int usedOne = dec - usedZero;
                int leftOne = freeOne - usedOne;


                if (i <= tail) {
                    if (f >= 1) {
                        dp[to][f-1] += base;
                        dp[to][f-1] %= MOD;
                    }
                    if (leftOne >= 1) {
                        dp[to][f] += base;
                        dp[to][f] %= MOD;
                    }
                } else {
                    dp[to][f] += base;
                    dp[to][f] %= MOD;
                }
            }

            if (i <= tail) {
                dec++;
            }
            if (i == tail) {
                boolean wash = false;
                if (qi+1 < qn) {
                    int[] pa = q.get(qi+1);
                    if (tail < pa[0]) {
                        wash = true;
                    }
                } else {
                    wash = true;
                }
                if (wash) {
                    for (int j = 1; j <= n; j++) {
                        dp[to][j] = 0;
                    }
                }
            }
            //debug(i, dp[to]);
        }


        // debug(dp[n%2]);

        out.println(dp[n%2][0] % MOD);
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