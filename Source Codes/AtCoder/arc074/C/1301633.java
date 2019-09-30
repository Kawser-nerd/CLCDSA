// package atcoder.arc.arc074;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    private static final int MOD = 1000000007;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        int[][] conditions = in.nextIntTable(m, 3);
        int[] gsz = new int[n+1];
        for (int i = 0; i < m; i++) {
            gsz[conditions[i][1]]++;
        }
        int[][][] guards = new int[n+1][][];
        for (int i = 0; i <= n; i++) {
            guards[i] = new int[gsz[i]][3];
        }
        for (int i = 0 ; i < m ; i++) {
            int idx = conditions[i][1];
            guards[idx][--gsz[idx]] = conditions[i];
        }

        int[][][][] dp = new int[2][3][301][301];
        dp[1][0][0][0] = 1;

        for (int i = 1 ; i <= n ; i++) {
            int fr = i % 2;
            int to = 1 - fr;
            for (int j = 0; j <= 2; j++) {
                for (int k = 0; k <= 300; k++) {
                    Arrays.fill(dp[to][j][k], 0);
                }
            }

            for (int lastColor = 0 ; lastColor <= 2 ;lastColor++) {
                for (int other1 = 0 ; other1 < i ; other1++) {
                    for (int other2 = 0 ; other2 < i ; other2++) {
                        long base = dp[fr][lastColor][other1][other2];
                        if (base == 0) {
                            continue;
                        }

                        for (int nextColor = 0 ; nextColor <= 2 ; nextColor++) {
                            int diff = (nextColor - lastColor + 3) % 3;
                            int nlast = nextColor;
                            int nother1 = diff == 1 ? i-1 : other1;
                            int nother2 = diff == 2 ? i-1 : other2;

                            boolean valid = true;
                            for (int[] cond : guards[i]) {
                                int kind = 1 + ((cond[0] <= nother1) ? 1 : 0) + ((cond[0] <= nother2) ? 1 : 0);
                                if (kind != cond[2]) {
                                    valid = false;
                                    break;
                                }
                            }
                            if (valid) {
                                dp[to][nlast][nother1][nother2] += base;
                                dp[to][nlast][nother1][nother2] -= dp[to][nlast][nother1][nother2] >= MOD ? MOD : 0;
                            }
                        }
                    }
                }
            }
        }

        long sum = 0;
        for (int lastColor = 0 ; lastColor <= 2 ;lastColor++) {
            for (int other1 = 0 ; other1 <= n ; other1++) {
                for (int other2 = 0; other2 <= n ; other2++) {
                    sum += dp[(n+1)%2][lastColor][other1][other2];
                }
            }
        }
        out.println(sum % MOD);
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