// package atcoder.arc.arc051;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

/**
 * Created by hama_du on 5/2/16.
 */
public class Main {
    private static final int INF = 1145141919;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int w = in.nextInt();
        int h = in.nextInt();
        int[] a = in.nextInts(w);
        int[] b = in.nextInts(h);

        long[][] wmax = build(a);
        long[][] hmax = build(b);

        int q = in.nextInt();
        while (--q >= 0) {
            int wl = in.nextInt() - 1;
            int hl = in.nextInt() - 1;
            out.println(solve(wmax[wl], hmax[hl], wl+1, hl+1));
        }
        out.flush();
    }

    private static long solve(long[] a, long[] b, int W, int H) {
        ConvexHullTechnique cht = new ConvexHullTechnique(H);
        for (int i = 1; i <= H ; i++) {
            cht.addLine(i, b[i]);
        }

        long max = - (Long.MAX_VALUE / 2);
        for (int i = 1 ; i <= W ; i++) {
            double q = a[i] * 1.0d / i;
            long[] line = cht.queryMax(q);
            max = Math.max(max, a[i] * line[0] + i * line[1]);
        }
        return max;
    }

    private static long[][] build(int[] a) {
        int n = a.length;
        long[][] ret = new long[n][n+1];
        for (int i = 0; i < n ; i++) {
            Arrays.fill(ret[i], -INF);
        }

        for (int i = 0 ; i < n ; i++) {
            ret[i][0] = 0;
            int sum = 0;
            int len = 0;
            for (int fi = i ; fi >= 0 ; fi--) {
                sum += a[fi];
                len++;
                ret[i][len] = Math.max(ret[i][len], sum);
            }
            if (i+1 < n) {
                for (int j = 0; j <= n ; j++) {
                    ret[i+1][j] = Math.max(ret[i+1][j], ret[i][j]);
                }
            }
        }
        return ret;
    }

    static class ConvexHullTechnique {
        long[][] stk;
        int tail = 0;

        ConvexHullTechnique(int maxLines) {
            stk = new long[maxLines][2];
        }

        // add line : ax + b
        void addLine(long a, long b) {
            stk[tail][0] = a;
            stk[tail][1] = b;
            tail++;
            while (tail >= 3 && compare(stk[tail-3], stk[tail-2], stk[tail-1])) {
                stk[tail-2][0] = stk[tail-1][0];
                stk[tail-2][1] = stk[tail-1][1];
                tail--;
            }
        }

        // a1 <= a2 <= a3
        private boolean compare(long[] l1, long[] l2, long[] l3) {
            long a1 = l1[0];
            long a2 = l2[0];
            long a3 = l3[0];
            long b1 = l1[1];
            long b2 = l2[1];
            long b3 = l3[1];
            return  (a2 - a1) * (b3 - b2) >= (a3 - a2) * (b2 - b1);
        }

        double val(int lidx, double x) {
            return stk[lidx][0] * x + stk[lidx][1];
        }

        long[] queryMax(double x) {
            int min = -1;
            int max = tail - 1;
            while (max - min > 1) {
                int med = (max + min) / 2;
                if (val(med, x) <= val(med+1, x)) {
                    min = med;
                } else {
                    max = med;
                }
            }
            return stk[max];
        }

        static void verify() {
            ConvexHullTechnique tech = new ConvexHullTechnique(100);
            tech.addLine(-1, 3);    // y = -x + 3
            tech.addLine(0, -3);    // y = -3
            tech.addLine(0, -6);    // y = -6
            tech.addLine(1, -12);   // y = x - 12
            tech.addLine(2, -16);   // y = 2x - 16

            for (int x = 0 ; x <= 20 ; x++) {
                debug(x, tech.queryMax(x));
            }
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
            for (int i = 0; i < n ; i++) {
                ret[i] = nextInt();
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