import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
    static long __startTime = System.currentTimeMillis();

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n ; i++) {
            p[i] = in.nextInt()-1;
        }

        int[] odd = new int[n];
        int[] even = new int[n];
        Arrays.fill(odd, n+10);
        Arrays.fill(even, n+10);
        for (int i = 0; i < n ; i++) {
            if (i % 2 == 0) {
                even[i] = p[i];
            } else {
                odd[i] = p[i];
            }
        }
        oddSeg = new SegmentTreePURMQ(odd);
        evenSeg = new SegmentTreePURMQ(even);

        ans = new int[n];
        pos = new int[n];
        for (int i = 0; i < n ; i++) {
            pos[p[i]] = i;
        }
        
        Queue<int[]> q = new PriorityQueue<>((u, v) -> u[0] == v[0] ? u[1] - v[1] :  u[0] - v[0]);
        q.add(findMin(0, n));
        while (q.size() >= 1) {
            int[] r = q.poll();
            ans[ai++] = r[0];
            ans[ai++] = r[1];
            // [L, [lp, rp], R)
            int L = r[2];
            int lp = r[3];
            int rp = r[4];
            int R = r[5];
            if (L < lp) {
                q.add(findMin(L, lp));
            }
            if (lp + 1 < rp) {
                q.add(findMin(lp+1, rp));
            }
            if (rp+1 < R) {
                q.add(findMin(rp+1, R));
            }
        }

        StringBuilder line = new StringBuilder();
        for (int i = 0; i < ans.length; i++) {
            line.append(' ').append(ans[i]+1);
        }
        out.println(line.substring(1));
        out.flush();
    }


    static int[] ans;
    static int ai;

    static int[] pos;
    static SegmentTreePURMQ oddSeg;
    static SegmentTreePURMQ evenSeg;



    // [l, r)
    static int[] findMin(int l, int r) {
        int L = l % 2 == 0 ? evenSeg.min(l, r) : oddSeg.min(l, r);
        int lpos = pos[L];
        int R = l % 2 == 0 ? oddSeg.min(lpos+1, r) : evenSeg.min(lpos+1, r);
        int rpos = pos[R];
        return new int[]{L, R, l, lpos, rpos, r};
    }


    /**
     * Segment tree (point update, range minimum query)
     */
    public static class SegmentTreePURMQ {
        int N;
        int M;
        int[] seg;

        public SegmentTreePURMQ(int[] data) {
            N = Math.max(8, Integer.highestOneBit(data.length-1)<<2);
            M = (N >> 1) - 1;

            seg = new int[N];
            Arrays.fill(seg, Integer.MAX_VALUE);
            for (int i = 0 ; i < data.length ; i++) {
                seg[M+i] = data[i];
            }
            for (int i = M-1 ; i >= 0 ; i--) {
                seg[i] = compute(i);
            }
        }

        /**
         * Uodates value at position minIndexSum.
         *
         * @param idx
         * @param value
         */
        public void update(int idx, int value) {
            seg[M+idx] = value;
            int i = M+idx;
            while (true) {
                i = (i-1) >> 1;
                seg[i] = compute(i);
                if (i == 0) {
                    break;
                }
            }
        }

        private int compute(int i) {
            return Math.min(seg[i*2+1], seg[i*2+2]);
        }

        /**
         * Finds minimum value from range [l,r).
         *
         * @param l
         * @param r
         * @return minimum value
         */
        public int min(int l, int r) {
            return min(l, r, 0, 0, M+1);
        }

        private int min(int l, int r, int idx, int fr, int to) {
            if (to <= l || r <= fr) {
                return Integer.MAX_VALUE;
            }
            if (l <= fr && to <= r) {
                return seg[idx];
            }

            int med = (fr+to) / 2;
            int ret = Integer.MAX_VALUE;
            ret = Math.min(ret, min(l, r, idx*2+1, fr, med));
            ret = Math.min(ret, min(l, r, idx*2+2, med, to));
            return ret;
        }
    }

    // 1 2 3 4 5 6
    // 2 5 //

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