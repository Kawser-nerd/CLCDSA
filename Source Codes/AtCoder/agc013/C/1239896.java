// package atcoder.agc.agc013;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long L = in.nextLong();
        long T = in.nextLong();
        long[][] ants = in.nextLongTable(n, 2);

        List<Integer> clockWiseAnts = new ArrayList<>();
        List<Integer> counterClockWiseAnts = new ArrayList<>();
        for (int i = 0; i < n ; i++) {
            if (ants[i][1] == 1) {
                clockWiseAnts.add(i);
            } else {
                counterClockWiseAnts.add(i);
            }
        }

        long[][] goalPositions = new long[n][3];
        for (int i = 0; i < n ; i++) {
            goalPositions[i][0] = i;
            goalPositions[i][1] = ants[i][0] + ((ants[i][1] == 1) ? (T % L) : (L - T % L));
            goalPositions[i][1] %= L;
            goalPositions[i][2] = ants[i][1];
        }

        if (clockWiseAnts.size() == 0 || counterClockWiseAnts.size() == 0) {
            for (int i = 0; i < n ; i++) {
                out.println(goalPositions[i][1]);
            }
            out.flush();
            return;
        }


        long p = ants[clockWiseAnts.get(0)][0];
        long[] ctr = new long[counterClockWiseAnts.size()];
        for (int i = 0 ; i < counterClockWiseAnts.size() ; i++) {
            ctr[i] = (ants[counterClockWiseAnts.get(i)][0] + L - p) % L;
        }
        Arrays.sort(ctr);

        long hit = (T / L) * 2 * counterClockWiseAnts.size();
        long mod = T % L; // [0, mod)

        for (int i = 0 ; i < ctr.length ; i++) {
            if (ctr[i] < mod * 2) {
                hit++;
            }
            if (ctr[i] + L < mod * 2) {
                hit++;
            }
        }

        long[] ans = new long[n];
        Arrays.sort(goalPositions, (a, b) -> (a[1] == b[1]) ? Long.compare(a[2], b[2]) : Long.compare(a[1], b[1]));
        for (int i = 0 ; i < n ; i++) {
            if (goalPositions[i][0] == clockWiseAnts.get(0)) {
                int start = (int)(n + i - (hit % n)) % n;
                int aStart = clockWiseAnts.get(0);
                for (int j = 0; j < n ; j++) {
                    ans[(j+aStart)%n] = goalPositions[(j+start)%n][1];
                }
                break;
            }
        }
        for (int i = 0; i < n ; i++) {
            out.println(ans[i]);
        }

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