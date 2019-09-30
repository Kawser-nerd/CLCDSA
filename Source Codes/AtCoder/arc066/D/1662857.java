// package arc.arc066;

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
        long[] t = new long[n];
        for (int i = 0; i < n ; i++) {
            t[i] = in.nextLong();
        }
        sumleft = new long[n+1];
        for (int i = 0; i < n ; i++) {
            sumleft[i+1] = sumleft[i] + t[i];
        }

        long[] rt = new long[n];
        for (int i = 0; i < n ; i++) {
            rt[i] = t[n-1-i];
        }
        sumright = new long[n+1];
        for (int i = 0; i < n ; i++) {
            sumright[i+1] = sumright[i] + rt[i];
        }

        dpleft = build(t);
        dpright = build(rt);
        best = new long[n];
        dpcover = new long[n];
        for (int i = 0; i < n ; i++) {
            dpcover[i] = 1 - t[i];
        }
        cht = new ConvexHullTech(n + 10);



        solveRange(0, n);

//        debug(dpleft);
//        debug(dpright);
//        debug(dpcover);

        int q = in.nextInt();
        while (--q >= 0) {
            int p = in.nextInt()-1;
            long x = in.nextInt();
            // debug(dpleft[p] + dpright[n-p-1], dpcover[p] + t[p] - x);
            long max = Math.max(dpleft[p] + dpright[n-p-1], dpcover[p] + t[p] - x);
            out.println(max);
        }

        out.flush();
    }

    static long INF = (long)1e18;

    static long[] dpleft;
    static long[] dpright;
    static long[] sumleft;
    static long[] sumright;

    static long[] best;
    static long[] dpcover;
    static ConvexHullTech cht;

    static void solveRange(int l, int r) {
        if (l + 1 == r) {
            return;
        }
        int n = best.length;
        int med = (l + r) / 2;

        cht.tail = 0;
        if (l == 0) {
            // cht.addLine(0, 0);
        }
        for (int i = l ; i < med ; i++) {
            int li = i+1;
            cht.addLine(-li, ((long) li * li - 3L * li) / 2 + dpleft[i] + sumleft[i]);
        }
        for (int i = med ; i < r ; i++) {
            int j = n - i - 1;
            int li = i+1;
            best[i] = ((long) li * li + 3L * li) / 2 + cht.computesMax(li) + dpright[j] - sumleft[li] + 1;
        }

        cht.tail = 0;
        if (r == n) {
            // cht.addLine(0, 0);
        }
        for (int i = r-1  ; i >= med ; i--) {
            int j = n - i - 1;
            int lj = j+1;
            cht.addLine(-lj, ((long) lj * lj - 3L * lj) / 2 + dpright[j] + sumright[j]);
        }
        for (int i = med-1 ; i >= l ; i--) {
            int j = n - i - 1;
            int lj = j+1;
            best[i] = ((long) lj * lj + 3L * lj) / 2 + cht.computesMax(lj) + dpleft[i] - sumright[lj] + 1;
        }

        long max = -INF;
        for (int i = r-1 ; i >= med ; i--) {
            max = Math.max(max, best[i]);
            dpcover[i] = Math.max(dpcover[i], max);
        }
        max = -INF;
        for (int i = l ; i <= med ; i++) {
            max = Math.max(max, best[i]);
            dpcover[i] = Math.max(dpcover[i], max);
        }

        // debug(l, r, best);

        solveRange(l, med);
        solveRange(med, r);
    }

    static long[] build(long[] t) {
        int n = t.length;
        long[] timos = new long[n+1];
        for (int i = 0; i < n ; i++) {
            timos[i+1] = timos[i] + t[i];
        }

        ConvexHullTech tech = new ConvexHullTech(n+10);
        tech.addLine(0, 0);
        long[] dp = new long[n+1];
        for (int i = 1 ; i <= n ; i++) {
            dp[i] = Math.max(dp[i-1], dp[i]);

            long take = ((long) i * (i + 1)) / 2 - timos[i] + tech.computesMax(i);
            dp[i] = Math.max(dp[i], take);

            tech.addLine(-i, ((long) i * (i - 1)) / 2 + timos[i] + dp[i]);
        }
        return dp;
    }

    /**
     * Convex hull technique.
     * Given many lines(say y = a_{i} * x + b_{i}), computes many query:
     *   what is the maximum y of current lines with given x?
     *
     * O(n+qlogn) where q = (number of queries), n = (maximum number of lines).
     */
    public static class ConvexHullTech {
        long[][] stk;
        int tail = 0;

        public ConvexHullTech(int maxLines) {
            stk = new long[maxLines][2];
        }

        // add line : ax + b
        public void addLine(long a, long b) {
            stk[tail][0] = a;
            stk[tail][1] = b;
            tail++;
            while (tail >= 3 && compare(stk[tail-3], stk[tail-2], stk[tail-1])) {
                stk[tail-2][0] = stk[tail-1][0];
                stk[tail-2][1] = stk[tail-1][1];
                tail--;
            }

//            long[] dbg = new long[tail];
//            for (int i = 0 ; i < tail ; i++) {
//                dbg[i] = stk[tail-i-1][0];
//            }
//            debug(dbg);
        }

        private boolean compare(long[] l1, long[] l2, long[] l3) {
            long a1 = l1[0];
            long a2 = l2[0];
            long a3 = l3[0];
            long b1 = l1[1];
            long b2 = l2[1];
            long b3 = l3[1];
            return  (a2 - a1) * (b3 - b2) <= (a3 - a2) * (b2 - b1);
        }

        long val(int lidx, long x) {
            return stk[lidx][0] * x + stk[lidx][1];
        }

        public long[] queryMax(long x) {
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

        public long computesMax(long x) {
            long[] line = queryMax(x);
            return line[0] * x + line[1];
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