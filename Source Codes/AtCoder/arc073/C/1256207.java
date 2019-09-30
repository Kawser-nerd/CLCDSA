// package atcoder.arc.arc073;

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
        long[][] balls = in.nextLongTable(n, 2);
        for (int i = 0; i < n ; i++) {
            if (balls[i][0] > balls[i][1]) {
                long tmp = balls[i][0];
                balls[i][0] = balls[i][1];
                balls[i][1] = tmp;
            }
        }
        Arrays.sort(balls, (a, b) -> Long.compare(a[0], b[0]));

        if (n == 1) {
            out.println(0);
            out.flush();
            return;
        }

        long ptnA = solveA(balls);
        long ptnB = solveB(balls);

        out.println(Math.min(ptnA, ptnB));
        out.flush();
    }

    private static long solveB(long[][] balls) {
        int n = balls.length;
        long[] yminUp = new long[n+1];
        long[] ymaxUp = new long[n+1];
        long[] yminDw = new long[n+1];
        long[] ymaxDw = new long[n+1];

        yminUp[0] = yminDw[0] = Long.MAX_VALUE;
        for (int i = 0; i < n ; i++) {
            yminUp[i+1] = Math.min(yminUp[i], balls[i][1]);
            ymaxUp[i+1] = Math.max(ymaxUp[i], balls[i][1]);
            yminDw[i+1] = Math.min(yminDw[i], balls[n-1-i][1]);
            ymaxDw[i+1] = Math.max(ymaxDw[i], balls[n-1-i][1]);
        }

        long best = Long.MAX_VALUE;
        for (int take = 1 ; take < n ; take++) {
            long bmin = Math.min(yminUp[take], balls[take][0]);
            long bmax = Math.max(ymaxUp[take], balls[n-1][0]);
            long rmin = Math.min(yminDw[n-take], balls[0][0]);
            long rmax = Math.max(ymaxDw[n-take], balls[take-1][0]);
            best = Math.min(best, (rmax-rmin)*(bmax-bmin));
        }
        return best;
    }

    private static long solveA(long[][] balls) {
        int n = balls.length;
        long rmin = Long.MAX_VALUE;
        long rmax = Long.MIN_VALUE;
        long bmin = Long.MAX_VALUE;
        long bmax = Long.MIN_VALUE;
        for (int i = 0; i < n ; i++) {
            rmin = Math.min(rmin, balls[i][0]);
            rmax = Math.max(rmax, balls[i][0]);
            bmin = Math.min(bmin, balls[i][1]);
            bmax = Math.max(bmax, balls[i][1]);
        }
        return (rmax-rmin)*(bmax-bmin);
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