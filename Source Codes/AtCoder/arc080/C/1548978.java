// package arc.arc080;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    private static final int INF = 1000000000;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextInt();
        }

        int[] even = new int[n];
        int[] odd = new int[n];
        for (int i = 0; i < n ; i++) {
            even[i] = i % 2 == 0 ? a[i] : INF;
            odd[i] = i % 2 == 0 ? INF : a[i];
        }
        zero = new SegmentTreePURMQ(even);
        one = new SegmentTreePURMQ(odd);


        Queue<Seg> q = new PriorityQueue<>();
        q.add(new Seg(0, n));

        int[] ans = new int[n];
        int ai = 0;
        while (q.size() >= 1) {
            Seg seg = q.poll();
            ans[ai++] = seg.L;
            ans[ai++] = seg.R;
            for (int[] nextRange : seg.childSegPair) {
                q.add(new Seg(nextRange[0], nextRange[1]));
            }
        }

        for (int i = 0; i < n ; i++) {
            if (i >= 1) {
                out.print(' ');
            }
            out.print(ans[i]);
        }
        out.println();
        out.flush();
    }

    static SegmentTreePURMQ zero;
    static SegmentTreePURMQ one;

    static class Seg implements Comparable<Seg> {
        int L;
        int R;
        List<int[]> childSegPair;

        public Seg(int i, int j) {
            int[] a, b;
            if (i % 2 == 0) {
                // zero -> one
                a = zero.min(i, j);
                b = one.min(a[1], j);
            } else {
                a = one.min(i, j);
                b = zero.min(a[1], j);
            }
            L = a[0];
            R = b[0];
            childSegPair = new ArrayList<>();
            if (a[1] - i >= 2) {
                childSegPair.add(new int[]{i, a[1]});
            }
            if (j - b[1] >= 2) {
                childSegPair.add(new int[]{b[1]+1, j});
            }
            if (a[1] + 1 < b[1]) {
                childSegPair.add(new int[]{a[1]+1, b[1]});
            }
        }

        @Override
        public int compareTo(Seg o) {
            return L - o.L;
        }
    }

    /**
     * Segment tree (point update, range minimum query)
     */
    public static class SegmentTreePURMQ {
        int N;
        int M;
        int[] seg;
        int[] minidx;

        public SegmentTreePURMQ(int[] data) {
            N = Integer.highestOneBit(data.length-1)<<2;
            M = (N >> 1) - 1;

            seg = new int[N];
            minidx = new int[N];
            Arrays.fill(seg, Integer.MAX_VALUE);
            for (int i = 0 ; i < data.length ; i++) {
                seg[M+i] = data[i];
                minidx[M+i] = i;
            }
            for (int i = M-1 ; i >= 0 ; i--) {
                compute(i);
            }
        }

        private void compute(int i) {
            if (seg[i*2+1] < seg[i*2+2]) {
                seg[i] = seg[i*2+1];
                minidx[i] = minidx[i*2+1];
            } else {
                seg[i] = seg[i*2+2];
                minidx[i] = minidx[i*2+2];
            }
        }

        /**
         * Finds minimum value from range [l,r).
         *
         * @param l
         * @param r
         * @return minimum value
         */
        public int[] min(int l, int r) {
            return min(l, r, 0, 0, M+1);
        }

        static final int[] none = new int[]{INF, INF};

        private int[] min(int l, int r, int idx, int fr, int to) {
            if (to <= l || r <= fr) {
                return none;
            }
            if (l <= fr && to <= r) {
                return new int[]{seg[idx], minidx[idx]};
            }
            int med = (fr+to) / 2;
            int[] a = min(l, r, idx*2+1, fr, med);
            int[] b = min(l, r, idx*2+2, med, to);
            return a[0] < b[0] ? a : b;
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