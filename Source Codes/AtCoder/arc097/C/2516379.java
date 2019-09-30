import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[][] balls = new int[2*n][2];
        for (int i = 0; i < 2*n ; i++) {
            int c = in.nextToken().toCharArray()[0] == 'W' ? 0 : 1;
            int a = in.nextInt()-1;
            balls[i][0] = c;
            balls[i][1] = a;
        }

        int[][][] costTable = new int[2][n][];
        for (int i = 0; i < 2*n ; i++) {
            int co = balls[i][0];
            int wo = co ^ 1;
            int sameCost = 0;
            int[] tbl = new int[n+1];
            for (int j = 0; j < i ; j++) {
                if (balls[j][0] == wo) {
                    tbl[balls[j][1]]++;
                } else if (balls[j][1] > balls[i][1]) {
                    sameCost++;
                }
            }
            for (int j = n-2 ; j >= 0 ; j--) {
                tbl[j] += tbl[j+1];
            }
            for (int j = 0; j <= n; j++) {
                tbl[j] += sameCost;
            }
            costTable[co][balls[i][1]] = tbl;
        }

        final int INF = (int)1e9;
        int[][] dp = new int[n+1][n+1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], INF);
        }

        dp[0][0] = 0;
        for (int i = 0; i <= n ; i++) {
            for (int j = 0; j <= n ; j++) {
                int base = dp[i][j];
                if (base == INF) {
                    continue;
                }
                if (i+1 <= n) {
                    dp[i+1][j] = Math.min(dp[i+1][j], base + costTable[0][i][j]);
                }
                if (j+1 <= n) {
                    dp[i][j+1] = Math.min(dp[i][j+1], base + costTable[1][j][i]);
                }
            }
        }

        out.println(dp[n][n]);
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