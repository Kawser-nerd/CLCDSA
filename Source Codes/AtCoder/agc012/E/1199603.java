// package atcoder.agc.agc012;

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
        int v = in.nextInt();

        int[] x = in.nextInts(n);
        int vv = v;
        int maxJump = 0;
        while (vv >= 1) {
            maxJump++;
            vv /= 2;
        }
        maxJump++;

        int[][] nextRight = new int[maxJump][n];
        for (int d = 0 ; d < maxJump ; d++) {
            int canGo = v >>> d;

            for (int i = 0 ; i < n ;) {
                int j = i+1;
                while (j < n && x[j] - x[j-1] <= canGo) {
                    j++;
                }
                for (int k = i ; k < j ; k++) {
                    nextRight[d][k] = j;
                }
                i = j;
            }
        }

        int requiredStep = 0;
        for (int i = 0 ; i < n ; ) {
            int j = nextRight[0][i];
            requiredStep++;
            i = j;
        }
        if (requiredStep >= 22) {
            for (int i = 0; i < n ; i++) {
                out.println("Impossible");
            }
            out.flush();
            return;
        }

        int[][] nextLeft = new int[maxJump][n];
        for (int d = 0 ; d < maxJump ; d++) {
            int canGo = v >>> d;
            for (int i = n-1 ; i >= 0 ;) {
                int j = i-1;
                while (j >= 0 && x[j+1] - x[j] <= canGo) {
                    j--;
                }
                for (int k = i ; k > j ; k--) {
                    nextLeft[d][k] = j;
                }
                i = j;
            }
        }

        int[] dpLeft = new int[1<<maxJump];
        for (int i = 0 ; i < (1<<maxJump) ; i += 2) {
            for (int k = 1 ; k < maxJump ; k++) {
                if (((i >> k) & 1) == 0) {
                    int ti = i | (1<<k);
                    dpLeft[ti] = Math.max(dpLeft[ti], dpLeft[i] == n ? n : nextRight[k][dpLeft[i]]);

                }
            }
        }

        int[] dpRight = new int[1<<maxJump];
        Arrays.fill(dpRight, n-1);
        for (int i = 0 ; i < (1<<maxJump) ; i += 2) {
            for (int k = 1 ; k < maxJump ; k++) {
                if (((i >> k) & 1) == 0) {
                    int ti = i | (1<<k);
                    dpRight[ti] = Math.min(dpRight[ti], dpRight[i] == -1 ? -1 : nextLeft[k][dpRight[i]]);
                }
            }
        }

        for (int i = 0 ; i < n ; ) {
            boolean isOK = false;
            int from = nextLeft[0][i] + 1;
            int to = nextRight[0][i] - 1;
            int fullPtn = (1<<maxJump)-2;
            for (int leftPtn = 0 ; leftPtn < (1<<maxJump) ; leftPtn += 2) {
                int rightPtn = fullPtn-leftPtn;
                int leftPart = dpLeft[leftPtn];
                int rightPart = dpRight[rightPtn];
                if (from <= leftPart && rightPart <= to) {
                    isOK = true;
                    break;
                }
            }
            for (int j = from ; j <= to ; j++) {
                out.println(isOK ? "Possible" : "Impossible");
            }
            i = to+1;
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
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
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
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
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