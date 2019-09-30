// package atcoder.agc.agc008;

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
        int[] a = in.nextInts(n);

        int[] ans = solve(a);
        if (ans == null) {
            out.println("No");
        } else {
            out.println("Yes");
            for (int i = 0; i < n*n ; i++) {
                if (i >= 1) {
                    out.print(' ');
                }
                out.print(ans[i]);
            }
            out.println();
        }
        out.flush();
    }

    private static int[] solve(int[] a) {
        int n = a.length;
        int[][] pa = new int[n][2];
        for (int i = 0; i < n ; i++) {
            pa[i][0] = i+1;
            pa[i][1] = a[i];
        }
        Arrays.sort(pa, (u, v) -> u[1] - v[1]);

        int[] ret = new int[n*n];
        for (int i = 0; i < n ; i++) {
            ret[a[i]-1] = i+1;
        }

        int[] consumeQue = new int[n*n];
        int ch = 0;
        int ct = 0;
        for (int l = 0 ; l < n ; l++) {
            int num = pa[l][0];
            for (int r = 0 ; r < num-1 ; r++) {
                consumeQue[ch++] = num;
            }
        }

        int[] cnt = new int[n+1];
        int[] freeQue = new int[n*n];
        int qh = 0;
        int qt = 0;

        for (int i = 0; i < ret.length; i++) {
            if (ret[i] != 0) {
                // make sure consumed
                if (cnt[ret[i]] != ret[i]-1) {
                    return null;
                }
                // yay! add numbers to queue!
                for (int k = ret[i] ; k < n ; k++) {
                    freeQue[qh++] = ret[i];
                }
            } else {
                if (ct < ch) {
                    ret[i] = consumeQue[ct++];
                    cnt[ret[i]]++;
                } else if (qt < qh) {
                    ret[i] = freeQue[qt++];
                } else  {
                    return null;
                }
            }
        }
        if (ct != ch || qt != qh) {
            //return null;
        }
        return ret;
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