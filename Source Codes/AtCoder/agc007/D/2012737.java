// package agc.agc007;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    private static final long INF = (long)1e18;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long E = in.nextInt();
        long T = in.nextInt();
        long[] a = new long[n+1];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextInt();
        }
        a[n] = E;

        long[] init = new long[n+10];
        Arrays.fill(init, INF);
        init[0] = a[0];

        SegmentTreeRARMQ far = new SegmentTreeRARMQ(init);
        SegmentTreeRARMQ near = new SegmentTreeRARMQ(init);

        int l = 0;
        for (int i = 0 ; i <= n ; i++) {
            if (i >= 1) {
                long D = a[i] - a[i - 1];
                near.add(0, i, D);
                far.add(0, i, 3*D);
            }
            if (i == n) {
                break;
            }

            while (l < i && a[i] - a[l] > T / 2) {
                l++;
            }

            long cost = near.min(l, i+1) + T;
            if (l >= 1) {
                cost = Math.min(cost, far.min(0, l));
            }
            cost += a[i+1] - a[i];

            near.set(i+1, cost);
            far.set(i+1, cost);
        }

        out.println(Math.min(near.min(n, n+1), far.min(n, n+1)));
        out.flush();
    }

    public static class SegmentTreeRARMQ {
        int N;
        int M;
        long[] segMin;
        long[] lazy;

        public SegmentTreeRARMQ(long[] data) {
            N = Integer.highestOneBit(data.length-1)<<2;
            M = (N >> 1) - 1;

            segMin = new long[N];
            lazy = new long[N];
            Arrays.fill(segMin, Long.MAX_VALUE);
            for (int i = 0 ; i < data.length ; i++) {
                segMin[M+i] = data[i];
            }
            for (int i = M-1 ; i >= 0 ; i--) {
                segMin[i] = compute(i);
            }
        }

        private void propagate(int i) {
            if (lazy[i] == 0) {
                return;
            }
            segMin[i] += lazy[i];
            if (i*2+2 < segMin.length) {
                lazy[i*2+1] += lazy[i];
                lazy[i*2+2] += lazy[i];
            }
            lazy[i] = 0;
        }

        private long compute(int i) {
            return Math.min(segMin[i*2+1], segMin[i*2+2]);
        }

        public void set(int l, long x) {
            long m = min(l, l+1);
            long d = x - m;
            add(l, l + 1, d);
        }

        public void add(int l, int r, long k) {
            add(l, r, k, 0, 0, M+1);
        }

        public void add(int l, int r, long x, int idx, int fr, int to) {
            propagate(idx);

            if (to <= l || r <= fr) {
                return;
            }
            if (l <= fr && to <= r) {
                lazy[idx] += x;
                propagate(idx);
                return;
            }

            int med = (fr + to) / 2;
            add(l, r, x, idx*2+1, fr, med);
            add(l, r, x, idx*2+2, med, to);

            segMin[idx] = compute(idx);
        }

        public long min(int l, int r) {
            return min(l, r, 0, 0, M+1);
        }

        public long min(int l, int r, int idx, int fr, int to) {
            propagate(idx);

            if (to <= l || r <= fr) {
                return Long.MAX_VALUE;
            }
            if (l <= fr && to <= r) {
                return segMin[idx];
            }

            int med = (fr+to) / 2;
            long ret = Long.MAX_VALUE;
            ret = Math.min(ret, min(l, r, idx*2+1, fr, med));
            ret = Math.min(ret, min(l, r, idx*2+2, med, to));
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