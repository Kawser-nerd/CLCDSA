import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    private static final long MOD = (long) 1e9 + 7;
    static long __startTime = System.currentTimeMillis();

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        long n = in.nextLong();

        long[][][][] dp = new long[61][2][2][2];
        dp[60][0][0][0] = 1;


        long ans = 0;
        for (int k = 60; k >= 0 ; k--) {
            long mask = 1L<<k;
            long zero = n & mask;
            for (int uv = 0; uv <= 3 ; uv++) {
                int u = uv & 1;
                int v = (uv & 2) >> 1;
                int[][] tbl = new int[][]{{1, 0}, {1, 0}};
                for (int i = 0 ; i < 2 ; i++) {
                    if ((i == 0 ? u : v) == 1 || (n & mask) == mask) {
                        tbl[i][1] = 1;
                    }
                }
                for (int kuri = 0; kuri <= 1 ; kuri++) {
                    long base = dp[k][u][v][kuri];
                    for (int nk = 0; nk <= 1; nk++) {
                        int[][] oktbl = new int[][]{{0, 0},{0, 0}};
                        for (int a = 0; a <= 1; a++) {
                            for (int b = 0; b <= 1; b++) {
                                int tu = a ^ b;
                                int plu = a + b + nk;
                                if (plu / 2 != kuri) {
                                    continue;
                                }
                                int tv = plu % 2;
                                oktbl[tu][tv] = 1;
                            }
                        }
                        for (int i = 0; i < 2 ; i++) {
                            for (int j = 0; j < 2 ; j++) {
                                if (oktbl[i][j] == 0 || tbl[i][j] == 0) {
                                    continue;
                                }
                                int tu = u == 1 ? 1 : ((i == 0 && zero >= 1) ? 1 : 0);
                                int tv = v == 1 ? 1 : ((j == 0 && zero >= 1) ? 1 : 0);
                                if (zero == 0) {
                                    if (u == 0 && i == 1) {
                                        continue;
                                    }
                                    if (v == 0 && j == 1) {
                                        continue;
                                    }
                                }


                                if (k-1 >= 0) {
                                    dp[k - 1][tu][tv][nk] += base;
                                    dp[k - 1][tu][tv][nk] %= MOD;
                                } else {
                                    if (nk == 0) {
                                        ans += base;
                                        ans %= MOD;
                                    }
                                }
                            }
                        }

                    }
                }
            }
        }
        out.println(ans);
        out.flush();
    }

    private static void printTime(String label) {
        debug(label, System.currentTimeMillis() - __startTime);
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