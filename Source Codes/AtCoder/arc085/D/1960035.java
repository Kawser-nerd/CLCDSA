// package arc.arc085;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    private static final int INF = 10000000;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] b = new int[n];
        for (int i = 0; i < n ; i++) {
            b[i] = in.nextInt();
        }
        int q = in.nextInt();

        int[] cost = new int[q];
        Arrays.fill(cost, INF);

        List<Event>[] ev = new List[n+1];
        for (int i = 0; i <= n ; i++) {
            ev[i] = new ArrayList<>();
        }
        int[][] ranges = new int[q][2];
        for (int i = 0; i < q ; i++) {
            int l = in.nextInt();
            int r = in.nextInt();
            ranges[i][0] = l;
            ranges[i][1] = r;
            ev[l].add(new Event(0, i));
            ev[r].add(new Event(1, i));
        }

        int[] onecost = new int[n+1];
        for (int i = n ; i >= 1 ; i--) {
            onecost[i-1] = onecost[i] + b[i-1];
        }

        int[] init = new int[n+10];
        Arrays.fill(init, INF);
        init[0] = 0;
        SegmentTreeRARMQ rmqA = new SegmentTreeRARMQ(init);
        SegmentTreeRARMQ rmqB = new SegmentTreeRARMQ(init.clone());

        for (int i = 1 ; i <= n ; i++) {
            for (Event e : ev[i]) {
                int L = ranges[e.id][0];
                int R = ranges[e.id][1];
                int D = R - L + 1;
                if (e.type == 0) {
                    // min of [0, l) of A + cost of [l, r)
                    int c = rmqA.min(0, L) + D - (onecost[L-1] - onecost[R]);
                    int c2 = rmqB.min(L, R) - ((n - R) - onecost[R]);

                    cost[e.id] = Math.min(c, c2);

                    int am = rmqA.min(R, R+1);
                    if (cost[e.id] < am) {
                        rmqA.add(R, R+1, cost[e.id]-am);
                        // debug("upd", R, rmqA.min(L, L+1));
                    }

                    int d = Math.min(c, c2) + (n - R) - onecost[R];
                    int bm = rmqB.min(R, R+1);
                    if (d < bm) {
                        rmqB.add(R, R+1, d-bm);
                    }

                    // debug(e.id, c, c2, cost[e.id], d, rmqA.min(R, R+1), rmqB.min(R, R+1));
                }
            }

            // process 0-1
            if (b[i-1] == 1) {
                // add 1 to [0, i) of A
                rmqA.add(0, i, 1);
            }
        }

        // debug(cost);

        int best = onecost[0];
        for (int i = 0; i < q ; i++) {
            best = Math.min(best, cost[i] + onecost[ranges[i][1]]);
        }
        out.println(best);
        out.flush();
    }

    public static class SegmentTreeRARMQ {
        int N;
        int M;
        int[] segMin;
        int[] lazy;

        public SegmentTreeRARMQ(int[] data) {
            N = Integer.highestOneBit(data.length-1)<<2;
            M = (N >> 1) - 1;

            segMin = new int[N];
            lazy = new int[N];
            Arrays.fill(segMin, INF);
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

        private int compute(int i) {
            return Math.min(segMin[i*2+1], segMin[i*2+2]);
        }

        public void add(int l, int r, int k) {
            add(l, r, k, 0, 0, M+1);
        }

        public void add(int l, int r, int x, int idx, int fr, int to) {
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

        public int min(int l, int r) {
            return min(l, r, 0, 0, M+1);
        }

        public int min(int l, int r, int idx, int fr, int to) {
            propagate(idx);

            if (to <= l || r <= fr) {
                return INF;
            }
            if (l <= fr && to <= r) {
                return segMin[idx];
            }

            int med = (fr+to) / 2;
            int ret = INF;
            ret = Math.min(ret, min(l, r, idx*2+1, fr, med));
            ret = Math.min(ret, min(l, r, idx*2+2, med, to));
            return ret;
        }
    }

    public static class Event {
        int type;
        int id;

        Event(int a, int b) {
            type = a;
            id = b;
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.