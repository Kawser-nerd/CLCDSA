import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    private static final int MOD = 1000000007;

    static long __startTime = System.currentTimeMillis();

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        char[] s = in.nextToken().toCharArray();

        int[] one = new int[n+1];
        for (int i = 0; i < n ; i++) {
            one[i+1] = one[i] + (s[i] == '1' ? 1 : 0);
        }

        int[] maxTo = new int[n];
        Arrays.fill(maxTo, -1);
        for (int i = 0; i < m ; i++) {
            int l = in.nextInt()-1;
            int r = in.nextInt();
            maxTo[l] = Math.max(maxTo[l], r);
        }

        int max = 0;
        int[][] events = new int[n][4];
        for (int i = 0; i < n ; i++) {
            Arrays.fill(events[i], -1);
        }
        for (int i = 0; i < n ; i++) {
            max = Math.max(max, i);
            if (max < maxTo[i]) {
                events[i] = new int[]{i, maxTo[i], maxTo[i]-max, one[maxTo[i]]-one[max]};
                max = maxTo[i];
            }
        }
        
        int[][] dp = new int[2][n+10];
        dp[0][0] = 1;

        int poolSum = 0;
        for (int i = 0; i < n ; i++) {
            int fr = i % 2;
            int to = 1 - fr;
            Arrays.fill(dp[to], 0);

            if (events[i][0] != -1) {
                poolSum = events[i][1];
            }
            for (int j = 0; j < dp[0].length ; j++) {
                int base = dp[fr][j];
                if (base == 0) {
                    continue;
                }
                if (j == 0 && events[i][0] == -1) {
                    add(dp, to, j, base);
                    continue;
                }
                int cj = j;
                if (events[i][0] != -1) {
                    cj += events[i][3];
                }

                if (cj >= 1) {
                    add(dp, to, cj-1, base);
                }

                int left = poolSum - i;
                if (cj < left) {
                    add(dp, to, cj, base);
                }
            }

        }

        out.println(dp[n%2][0]);
        out.flush();
    }

    static void add(int[][] dp, int i, int j, int a) {
        dp[i][j] += a;
        dp[i][j] -= dp[i][j] >= MOD ? MOD : 0;
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