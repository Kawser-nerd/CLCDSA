// package atcoder.arc.arc073;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    static final long INF = Long.MAX_VALUE / 10;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int q = in.nextInt();
        int a = in.nextInt()-1;
        int b = in.nextInt()-1;

        long[] tblL = new long[Math.max(n, 16)];
        long[] tblR = new long[Math.max(n, 16)];
        Arrays.fill(tblL, INF);
        Arrays.fill(tblR, INF);
        for (int i = 0; i < n ; i++) {
            tblL[i] = i;
            tblR[n-i-1] = i;
        }
        SegmentTreeRARMQ segL = new SegmentTreeRARMQ(tblL);
        SegmentTreeRARMQ segR = new SegmentTreeRARMQ(tblR);

        segL.add(0, b, INF / 10);
        segL.add(b+1, n, INF / 10);
        segR.add(0, b, INF / 10);
        segR.add(b+1, n, INF / 10);

        int last = a;
        while (--q >= 0) {
            int pos = in.nextInt()-1;
            long toLast = segL.min(last, last+1)-last + Math.abs(last-pos);
            long possibleMinLast = Math.min(segR.min(0, pos+1)-(n-pos-1), segL.min(pos, n)-pos);
            segL.add(0, n, Math.abs(last-pos));
            segR.add(0, n, Math.abs(last-pos));
            if (toLast > possibleMinLast) {
                long save = toLast - possibleMinLast;
                segL.add(last, last+1, -save);
                segR.add(last, last+1, -save);
            }
            last = pos;
        }


        long min = INF;
        for (int i = 0; i < n ; i++) {
            min = Math.min(min, segL.min(i, i+1)-i);
        }
        out.println(min);
        out.flush();
    }

    /**
     * Segment tree (range add, range minimum query).
     */
    public static class SegmentTreeRARMQ {
        int N;
        int M;
        long[] segMin;
        long[] segAdd;

        public SegmentTreeRARMQ(long[] data) {
            N = Integer.highestOneBit(data.length-1)<<2;
            M = (N >> 1) - 1;

            segMin = new long[N];
            segAdd = new long[N];
            Arrays.fill(segMin, INF);
            for (int i = 0 ; i < data.length ; i++) {
                segMin[M+i] = data[i];
            }
            for (int i = M-1 ; i >= 0 ; i--) {
                segMin[i] = compute(i);
            }
        }

        public long compute(int i) {
            return Math.min(segMin[i*2+1], segMin[i*2+2]) + segAdd[i];
        }

        public void add(int l, int r, long k) {
            add(l, r, k, 0, 0, M+1);
        }

        public void add(int l, int r, long x, int idx, int fr, int to) {
            if (to <= l || r <= fr) {
                return;
            }
            if (l <= fr && to <= r) {
                segAdd[idx] += x;
                while (idx >= 1) {
                    idx = (idx - 1) / 2;
                    segMin[idx] = Math.min(segMin[idx*2+1] + segAdd[idx*2+1], segMin[idx*2+2] + segAdd[idx*2+2]);
                }
                return;
            }

            int med = (fr + to) / 2;
            add(l, r, x, idx*2+1, fr, med);
            add(l, r, x, idx*2+2, med, to);
        }

        public long min(int l, int r) {
            return min(l, r, 0, 0, M+1);
        }

        public long min(int l, int r, int idx, int fr, int to) {
            if (to <= l || r <= fr) {
                return INF;
            }
            if (l <= fr && to <= r) {
                return segMin[idx] + segAdd[idx];
            }

            int med = (fr+to) / 2;
            long ret = INF;
            ret = Math.min(ret, min(l, r, idx*2+1, fr, med));
            ret = Math.min(ret, min(l, r, idx*2+2, med, to));
            return ret + segAdd[idx];
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