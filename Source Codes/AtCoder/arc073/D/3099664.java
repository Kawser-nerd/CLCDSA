import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    static long __startTime = System.currentTimeMillis();
    static long INF = (long)1e12;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int q = in.nextInt();
        int a = in.nextInt()-1;
        int b = in.nextInt()-1;

        long[] left = new long[200010];
        long[] right  = new long[200010];
        for (int i = 0; i < n ; i++) {
            left[i] = i + ((i == b) ? 0 : INF);
            right[i] = n-1-i + ((i == b) ? 0 : INF);
        }
        SegmentTreeRARMQ ll = new SegmentTreeRARMQ(left);
        SegmentTreeRARMQ rr = new SegmentTreeRARMQ(right);

        int last = a;
        while (--q >= 0) {
            int x = in.nextInt()-1;
            long toVal = Math.min(ll.min(x, n) - x, rr.min(0, x+1) - (n-1-x));

            long diff = Math.abs(last - x);
            ll.add(0, n, diff);
            rr.add(0, n, diff);

            long val = ll.min(last, last+1) - last;
            if (val > toVal) {
                long d = toVal-val;
                ll.add(last, last+1, d);
                rr.add(last, last+1, d);
            }
            last = x;
        }

        long best = INF;
        for (int i = 0; i < n ; i++) {
            best = Math.min(best, ll.min(i, i+1) - i);
        }
        out.println(best);
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
            Arrays.fill(segMin, Long.MAX_VALUE);
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
                return Long.MAX_VALUE;
            }
            if (l <= fr && to <= r) {
                return segMin[idx] + segAdd[idx];
            }

            int med = (fr+to) / 2;
            long ret = Long.MAX_VALUE;
            ret = Math.min(ret, min(l, r, idx*2+1, fr, med));
            ret = Math.min(ret, min(l, r, idx*2+2, med, to));
            return ret + segAdd[idx];
        }
    }

    private static void printTime(String label) {
        debug(label, System.currentTimeMillis() - __startTime);
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