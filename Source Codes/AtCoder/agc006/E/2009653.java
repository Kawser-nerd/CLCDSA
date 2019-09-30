// package agc.agc006;

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
        int[][] table = new int[3][n];
        for (int i = 0; i < 3 ; i++) {
            for (int j = 0; j < n ; j++) {
                table[i][j] = in.nextInt() - 1;
            }
        }

        out.println(solve(table) ? "Yes" : "No");
        out.flush();
    }

    private static boolean solve(int[][] table) {
        int n = table[0].length;


        int[] p = new int[n];
        int[] f = new int[n];

        for (int j = 0; j < n ; j++) {
            int x = table[0][j];
            int y = table[1][j];
            int z = table[2][j];
            int[] ct = new int[3];
            ct[x%3]++;
            ct[y%3]++;
            ct[z%3]++;
            if (!(ct[0] == 1 && ct[1] == 1 && ct[2] == 1)) {
                return false;
            }
            if (!(x / 3 == y / 3 && y / 3 == z / 3)) {
                return false;
            }
            if (y % 3 != 1) {
                return false;
            }
            p[j] = x / 3;
            f[j] = (x % 3 == 2) ? 1 : 0;
        }

        for (int j = 0; j < n ; j++) {
            if (j % 2 != p[j] % 2) {
                return false;
            }
        }
        return solve2(p, f);
    }

    private static boolean solve2(int[] p, int[] f) {
        int n = p.length;
        int[] ep = new int[(n+1)/2];
        int[] ef = new int[ep.length];
        for (int i = 0; i < n ; i += 2) {
            ep[i/2] = p[i];
            ef[i/2] = f[i];
        }
        int[] op = new int[n-ep.length];
        int[] of = new int[op.length];
        for (int i = 1 ; i < n ; i += 2) {
            op[i/2] = p[i];
            of[i/2] = f[i];
        }

        long flagO = (swap(ep) + diff(op, of)) % 2;
        long flagE = (swap(op) + diff(ep, ef)) % 2;

        return flagO == 0 && flagE == 0;
    }

    private static long swap(int[] ep) {
        int n = ep.length;

        int M = n*2+10;
        FenwickTree f = new FenwickTree(M);
        long co = 0;
        for (int i = 0; i < n ; i++) {
            int E = ep[i]+1;
            co += f.range(E+1, M);
            f.add(E, 1);
        }
        return co;
    }

    private static int diff(int[] ep, int[] flg) {
        int[] op = new int[ep.length];
        int n = flg.length;

        for (int i = 0; i < n ; i++) {
            op[ep[i]/2] = flg[i] ^ (i % 2);
        }
        int c = 0;
        for (int i = 0; i < op.length; i++) {
            if (op[i] != i % 2) {
                c++;
            }
        }
        return c;
    }


    public static class FenwickTree {
        long N;
        long[] data;

        public FenwickTree(int n) {
            N = n;
            data = new long[n + 1];
        }

        /**
         * Computes value of [1, i].
         * <p>
         * O(logn)
         *
         * @param i
         * @return
         */
        public long sum(int i) {
            long s = 0;
            while (i > 0) {
                s += data[i];
                i -= i & (-i);
            }
            return s;
        }

        /**
         * Computes value of [i, j].
         * <p>
         * O(logn)
         *
         * @param i
         * @param j
         * @return
         */
        public long range(int i, int j) {
            return sum(j) - sum(i - 1);
        }

        /**
         * Sets value x into i-th position.
         * <p>
         * O(logn)
         *
         * @param i
         * @param x
         */
        public void set(int i, long x) {
            add(i, x - range(i, i));
        }

        /**
         * Adds value x into i-th position.
         * <p>
         * O(logn)
         *
         * @param i
         * @param x
         */
        public void add(int i, long x) {
            while (i <= N) {
                data[i] += x;
                i += i & (-i);
            }
        }
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