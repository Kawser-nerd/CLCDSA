// package agc.agc019;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int x1 = in.nextInt();
        int y1 = in.nextInt();
        int x2 = in.nextInt();
        int y2 = in.nextInt();
        int n = in.nextInt();
        int[][] fountains = new int[n][2];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < 2 ; j++) {
                fountains[i][j] = in.nextInt();
            }
        }
        int minX = Math.min(x1, x2);
        int maxX = Math.max(x1, x2);
        int minY = Math.min(y1, y2);
        int maxY = Math.max(y1, y2);

        List<int[]> availablefountains = new ArrayList<>();
        for (int i = 0 ; i < n ; i++) {
            if (minX <= fountains[i][0] && fountains[i][0] <= maxX) {
                if (minY <= fountains[i][1] && fountains[i][1] <= maxY) {
                    availablefountains.add(new int[]{ Math.abs(x1-fountains[i][0]), Math.abs(y1-fountains[i][1])});
                }
            }
        }

        out.println(String.format("%.15f", solve(maxX-minX, maxY-minY, availablefountains)));
        out.flush();
    }

    static final double HALF = 20 * Math.PI / 2;
    static final double QUARTER = HALF / 2;
    static final double CORNER = 20;
    static final double HALF_LOSS = HALF - CORNER;
    static final double QUARTER_GAIN = QUARTER - CORNER;
    static final double LATTICE_SIZE = 100;

    private static double solve(int W, int H, List<int[]> fountains) {
        int n = fountains.size();
        Collections.sort(fountains, (u, v) ->  u[0] - v[0]);

        int[] a = new int[n];
        for (int i = 0; i < n ; i++) {
            a[i] = fountains.get(i)[1];
        }

        int x = lis(a);

        double base = (W + H) * LATTICE_SIZE;
        if (x == Math.min(W, H) + 1) {
            if (x == 1) {
                return base + HALF_LOSS;
            }
            return base + (x - 1) * QUARTER_GAIN + HALF_LOSS;
        }
        return base + x * QUARTER_GAIN;
    }

    /**
     * Computes longest increasing sequence.
     * If you want to get actual sequence, see dp[1..ans].
     * <p>
     * O(nlogn)
     *
     * @param values
     * @return
     */
    public static int lis(int[] values) {
        int n = values.length;
        long[] lval = new long[n];
        for (int i = 0; i < values.length; i++) {
            lval[i] = values[i] * 1000000000L + i;
        }
        int ans = 0;
        long[] dp = new long[n + 1];
        Arrays.fill(dp, Long.MIN_VALUE);
        for (int i = 0; i < n; i++) {
            int idx = Arrays.binarySearch(dp, 0, ans + 1, lval[i]);
            if (idx < 0) {
                idx = -idx - 2;
                dp[idx + 1] = lval[i];
                if (idx >= ans) {
                    ans++;
                }
            }
        }
        return ans;
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