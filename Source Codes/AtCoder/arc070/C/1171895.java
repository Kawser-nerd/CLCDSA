// package atcoder.arc.arc070;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.TreeSet;

public class Main {
    private static final int INF = 100000000;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[][] lr = in.nextIntTable(n, 2);
        for (int i = 0; i < n ; i++) {
            lr[i][1] = lr[i][1] - lr[i][0];
        }

        TreeSet<LinePoint> left = new TreeSet<>((a, b) -> a.p == b.p ? a.idx - b.idx : Long.compare(a.p, b.p));
        TreeSet<LinePoint> right = new TreeSet<>((a, b) -> a.p == b.p ? a.idx - b.idx : Long.compare(a.p, b.p));
        long exLeft = 0;
        long exRight = 0;

        left.add(LinePoint.create(lr[0][0]));
        right.add(LinePoint.create(lr[0][0]));

        long bottom = 0;
        for (int i = 1 ; i < n ; i++) {
            exLeft -= lr[i][1];
            exRight += lr[i-1][1];
            long zeroFrom = left.last().p + exLeft;
            long zeroTo = right.first().p + exRight;

            if (zeroFrom <= lr[i][0] && lr[i][0] <= zeroTo) {
                left.add(LinePoint.create(lr[i][0] - exLeft));
                right.add(LinePoint.create(lr[i][0] - exRight));
            } else if (lr[i][0] < zeroFrom) {
                long add = Math.abs((left.last().p + exLeft) - lr[i][0]);

                left.add(LinePoint.create(lr[i][0] - exLeft));
                left.add(LinePoint.create(lr[i][0] - exLeft));
                left.pollLast();

                LinePoint pt = right.first();
                right.add(LinePoint.create(pt.p - (zeroTo - zeroFrom)));

                bottom += add;
            } else {
                long add = Math.abs((right.first().p + exRight) - lr[i][0]);

                right.add(LinePoint.create(lr[i][0] - exRight));
                right.add(LinePoint.create(lr[i][0] - exRight));
                right.pollFirst();

                LinePoint pt = left.last();
                left.add(LinePoint.create(pt.p + (zeroTo - zeroFrom)));

                bottom += add;
            }
        }

        // debug("all", left.last().p + exLeft, right.first().p + exRight, bottom);


        out.println(bottom);
        out.flush();
    }


    static class LinePoint {
        static int seq = 0;
        long p;
        int idx;

        static LinePoint create(long p) {
            return new LinePoint(p, ++seq);
        }

        public LinePoint(long p, int i) {
            this.p = p;
            this.idx = i;
        }

        @Override
        public String toString() {
            return String.format("%d - %d", p, idx);
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