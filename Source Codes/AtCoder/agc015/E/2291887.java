// package agc.agc015;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class Main {
    private static final long MOD = 1000000007;

    static class TakahashiKun {
        int x;
        int v;

        TakahashiKun(int _x, int _v) {
            x = _x;
            v = _v;
        }
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        TakahashiKun[] t = new TakahashiKun[n];

        {
            int[] x = new int[n];
            int[] v = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = in.nextInt();
                v[i] = in.nextInt();
            }
            x = unique(x);
            v = unique(v);
            for (int i = 0; i < n; i++) {
                t[i] = new TakahashiKun(x[i], v[i]);
            }
        }
        Arrays.sort(t, (a, b) -> a.x - b.x);

        int[] vs = new int[n];
        for (int i = 0; i < n; i++) {
            vs[i] = t[i].v;
        }
        SegmentTreePURMQ seg = new SegmentTreePURMQ(vs);
        int[][] vrange = new int[n][2];
        for (int i = 0; i < n ; i++) {
            vrange[i][0] = seg.min(i, n);
            vrange[i][1] = seg.max(0, i+1);
        }
        Arrays.sort(vrange, (u, v) -> (u[0] == v[0]) ? u[1] - v[1] : u[0] - v[0]);

        // debug(vrange);

        FenwickTree fen = new FenwickTree(n+10);
        fen.add(1, 1);
        for (int i = 0; i < n ; i++) {
            int min = vrange[i][0];
            int max = vrange[i][1];
            long f = fen.range(min, n+9) % MOD;
            fen.add(max+1, f);
        }

        out.println(fen.range(n+1, n+9) % MOD);
        out.flush();
    }

    static int[] unique(int[] x) {
        int n = x.length;
        int[] ux = x.clone();
        Arrays.sort(ux);
        Map<Integer,Integer> map = new HashMap<>();
        for (int i = 0; i < n ; i++) {
            map.put(ux[i], i+1);
        }
        for (int i = 0; i < n; i++) {
            x[i] = map.get(x[i]);
        }
        return x;
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
            return s % MOD;
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
            return (sum(j) - sum(i - 1) + MOD) % MOD;
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
                data[i] %= MOD;
                i += i & (-i);
            }
        }
    }

    public static class SegmentTreePURMQ {
        int N;
        int M;
        int[] segMin;
        int[] segMax;

        public SegmentTreePURMQ(int[] data) {
            N = Math.max(Integer.highestOneBit(data.length-1)<<2, 16);
            M = (N >> 1) - 1;

            segMin = new int[N];
            segMax = new int[N];
            Arrays.fill(segMin, Integer.MAX_VALUE);
            Arrays.fill(segMin, Integer.MIN_VALUE);
            for (int i = 0 ; i < data.length ; i++) {
                segMin[M+i] = data[i];
                segMax[M+i] = data[i];
            }
            for (int i = M-1 ; i >= 0 ; i--) {
                segMin[i] = Math.min(segMin[i*2+1], segMin[i*2+2]);
                segMax[i] = Math.max(segMax[i*2+1], segMax[i*2+2]);
            }
        }

        public int min(int l, int r) {
            return min(l, r, 0, 0, M+1);
        }

        private int min(int l, int r, int idx, int fr, int to) {
            if (to <= l || r <= fr) {
                return Integer.MAX_VALUE;
            }
            if (l <= fr && to <= r) {
                return segMin[idx];
            }

            int med = (fr+to) / 2;
            int ret = Integer.MAX_VALUE;
            ret = Math.min(ret, min(l, r, idx*2+1, fr, med));
            ret = Math.min(ret, min(l, r, idx*2+2, med, to));
            return ret;
        }

        public int max(int l, int r) {
            return max(l, r, 0, 0, M+1);
        }

        private int max(int l, int r, int idx, int fr, int to) {
            if (to <= l || r <= fr) {
                return Integer.MIN_VALUE;
            }
            if (l <= fr && to <= r) {
                return segMax[idx];
            }

            int med = (fr+to) / 2;
            int ret = Integer.MIN_VALUE;
            ret = Math.max(ret, max(l, r, idx*2+1, fr, med));
            ret = Math.max(ret, max(l, r, idx*2+2, med, to));
            return ret;
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