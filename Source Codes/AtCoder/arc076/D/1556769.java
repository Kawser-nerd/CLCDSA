// package arc.arc076;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        int[][] takahashi = new int[n][2];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < 2 ; j++) {
                takahashi[i][j] = in.nextInt();
            }
        }

        Arrays.sort(takahashi, Comparator.comparingInt(u -> u[0]));

        int ans = n < m ? 0 : n - m;
        int[] vec = new int[m+10];
        Arrays.fill(vec, SegmentTreeRARMQ.INF);
        for (int i = 1 ; i <= m ; i++) {
            vec[i] = -(m+1-i);
        }
        vec[0] = -m;
        vec[m+1] = 0;

        SegmentTreeRARMQ seg = new SegmentTreeRARMQ(vec);
        int head = 0;
        for (int l = 0 ; l <= m-1 ; l++) {
            while (head < n && takahashi[head][0] == l) {
                seg.add(0, takahashi[head][1]+1, 1);
                head++;
            }
            ans = Math.max(ans, seg.max(l+2, m+2) - l);
        }

        out.println(ans);
        out.flush();
    }

    public static class SegmentTreeRARMQ {
        static final int INF = -100000000;

        int N;
        int M;
        int[] segMax;
        int[] segAdd;

        public SegmentTreeRARMQ(int[] data) {
            N = Integer.highestOneBit(data.length-1)<<2;
            M = (N >> 1) - 1;

            segMax = new int[N];
            segAdd = new int[N];
            Arrays.fill(segMax, INF);
            for (int i = 0 ; i < data.length ; i++) {
                segMax[M+i] = data[i];
            }
            for (int i = M-1 ; i >= 0 ; i--) {
                segMax[i] = compute(i);
            }
        }

        public int compute(int i) {
            return Math.max(segMax[i*2+1], segMax[i*2+2]) + segAdd[i];
        }

        public void add(int l, int r, int k) {
            add(l, r, k, 0, 0, M+1);
        }

        public void add(int l, int r, int x, int idx, int fr, int to) {
            if (to <= l || r <= fr) {
                return;
            }
            if (l <= fr && to <= r) {
                segAdd[idx] += x;
                while (idx >= 1) {
                    idx = (idx - 1) / 2;
                    segMax[idx] = Math.max(segMax[idx*2+1] + segAdd[idx*2+1], segMax[idx*2+2] + segAdd[idx*2+2]);
                }
                return;
            }

            int med = (fr + to) / 2;
            add(l, r, x, idx*2+1, fr, med);
            add(l, r, x, idx*2+2, med, to);
        }

        public int max(int l, int r) {
            return max(l, r, 0, 0, M+1);
        }

        public int max(int l, int r, int idx, int fr, int to) {
            if (to <= l || r <= fr) {
                return INF;
            }
            if (l <= fr && to <= r) {
                return segMax[idx] + segAdd[idx];
            }

            int med = (fr+to) / 2;
            int ret = INF;
            ret = Math.max(ret, max(l, r, idx*2+1, fr, med));
            ret = Math.max(ret, max(l, r, idx*2+2, med, to));
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