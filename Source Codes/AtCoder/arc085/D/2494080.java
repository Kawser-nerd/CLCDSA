import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextInt();
        }
        int[] zeros = new int[n+1];
        int[] ones = new int[n+1];
        for (int i = 0; i < n ; i++) {
            zeros[i+1] = zeros[i] + (a[i] == 0 ? 1 : 0);
            ones[i+1] = ones[i] + (a[i] == 1 ? 1 : 0);
        }

        int q = in.nextInt();
        int[][] ranges = new int[q][2];
        for (int i = 0; i < q ; i++) {
            for (int j = 0; j < 2 ; j++) {
                ranges[i][j] = in.nextInt();
            }
            ranges[i][0]--;
        }

        Arrays.sort(ranges, (u, v) -> u[0] == v[0] ? u[1] - v[1] : u[0] - v[0]);


        final int INF = n+10;
        SegmentTreeRARMQ dp0, dp1;
        {
            int[] dp = new int[n + 10];
            Arrays.fill(dp, INF);
            dp[0] = ones[n];
            dp0 = new SegmentTreeRARMQ(dp.clone());
            dp[0] = INF;
            dp1 = new SegmentTreeRARMQ(dp.clone());
        }

        int qf = 0;
        for (int i = 0 ; i < n ; i++) {
            if (qf >= q || ranges[qf][0] != i) {
                continue;
            }
            int qt = qf;
            while (qt < q && ranges[qf][0] == ranges[qt][0]) {
                qt++;
            }

            int beforeCost = dp0.min(0, i+1) - (ones[n] - ones[i]);
            for (; qf < qt ; qf++) {
                int to = ranges[qf][1];
                int useCost = zeros[to] - zeros[i];
                int contCost = dp1.min(i, to) - (zeros[n] - zeros[to]);
                int best = Math.min(beforeCost + useCost, contCost);
                int t0 = best + (ones[n] - ones[to]);
                dp0.updIfSmaller(to, t0);
                int t1 = best + (zeros[n] - zeros[to]);
                dp1.updIfSmaller(to, t1);
            }
        }
        
        int best = ones[n];
        for (int i = 0; i < q ; i++) {
            best = Math.min(best, dp0.min(ranges[i][1], ranges[i][1]+1));
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
        int[] segMin;
        int[] segAdd;

        public SegmentTreeRARMQ(int[] data) {
            N = Integer.highestOneBit(data.length-1)<<2;
            M = (N >> 1) - 1;

            segMin = new int[N];
            segAdd = new int[N];
            Arrays.fill(segMin, Integer.MAX_VALUE);
            for (int i = 0 ; i < data.length ; i++) {
                segMin[M+i] = data[i];
            }
            for (int i = M-1 ; i >= 0 ; i--) {
                segMin[i] = compute(i);
            }
        }

        public int compute(int i) {
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


        public void updIfSmaller(int idx, int a) {
            int now = min(idx, idx+1, 0, 0, M+1);
            if (now > a) {
                add(idx, idx+1, a-now);
            }
        }

        public int min(int l, int r) {
            return min(l, r, 0, 0, M+1);
        }

        public int min(int l, int r, int idx, int fr, int to) {
            if (to <= l || r <= fr) {
                return Integer.MAX_VALUE;
            }
            if (l <= fr && to <= r) {
                return segMin[idx] + segAdd[idx];
            }

            int med = (fr+to) / 2;
            int ret = Integer.MAX_VALUE;
            ret = Math.min(ret, min(l, r, idx*2+1, fr, med));
            ret = Math.min(ret, min(l, r, idx*2+2, med, to));
            return ret + segAdd[idx];
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