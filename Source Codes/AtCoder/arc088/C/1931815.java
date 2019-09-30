// package arc.arc088;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        char[] s = in.nextToken().toCharArray();
        int[] cnt = new int[26];
        for (int i = 0; i < s.length ; i++) {
            cnt[s[i]-'a']++;
        }
        out.println(solve(s));
        out.flush();
    }

    private static long solve(char[] s) {
        int n = s.length;
        List<Integer>[] cpos = new List[26];
        for (int i = 0; i < 26 ; i++) {
            cpos[i] = new ArrayList<>();
        }
        for (int i = 0; i < n ; i++) {
            int k = s[i]-'a';
            cpos[k].add(i);
        }

        int odd = -1;
        int opos = -1;
        {
            int oc = 0;
            for (int i = 0 ; i < 26 ; i++) {
                if (cpos[i].size() % 2 == 1) {
                    odd = i;
                    oc++;
                }
            }
            if (oc >= 2) {
                return -1;
            }
            if (odd != -1) {
                opos = cpos[odd].get(cpos[odd].size()/2);
            }
        }

        int ri = 0;
        int[][] ranges = new int[n/2][2];
        for (int i = 0; i < 26 ; i++) {
            int size = cpos[i].size();
            for (int k = 0 ; k < size / 2 ; k++) {
                ranges[ri][0] = cpos[i].get(k);
                ranges[ri][1] = cpos[i].get(size-1-k);
                ri++;
            }
        }
        return solveOdd(ranges, opos) + solveEven(ranges);
    }

    private static long solveEven(int[][] ranges) {
        int MAX = 200010;
        FenwickTree headbit = new FenwickTree(MAX);
        FenwickTree lastbit = new FenwickTree(MAX);
        for (int[] r : ranges) {
            headbit.add(r[0]+1, 1);
            lastbit.add(r[1]+1, 1);
        }

        long costTwo = 0;
        for (int[] r : ranges) {
            costTwo += lastbit.range(1, r[0]+1);
            costTwo += headbit.range(r[1]+1, MAX-1);
        }
        costTwo /= 2;


        FenwickTree containbit = new FenwickTree(MAX);
        long costZero = 0;
        int[] events = new int[MAX];
        Arrays.fill(events, -1);
        for (int[] r : ranges) {
            events[r[1]] = r[0];
        }
        for (int i = 0; i < MAX; i++) {
            if (events[i] >= 0) {
                costZero += containbit.range(events[i]+1, i+1);
                containbit.add(events[i]+1, 1);
            }
        }

        long N = ranges.length;
        long costOne = N * (N - 1) / 2 - costTwo - costZero;
        return (costTwo * 2 + costOne);
    }

    private static long solveOdd(int[][] ranges, int opos) {
        if (opos == -1) {
            return 0;
        }
        int badcnt = 0;
        for (int[] r : ranges) {
            if (r[1] < opos || opos < r[0]) {
                badcnt++;
            }
        }
        return badcnt;
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
            Arrays.fill(segMin, 0);
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

        public int min(int l, int r) {
            return min(l, r, 0, 0, M+1);
        }

        public int min(int l, int r, int idx, int fr, int to) {
            if (to <= l || r <= fr) {
                return 0;
            }
            if (l <= fr && to <= r) {
                return segMin[idx] + segAdd[idx];
            }

            int med = (fr+to) / 2;
            int ret = 0;
            ret = Math.min(ret, min(l, r, idx*2+1, fr, med));
            ret = Math.min(ret, min(l, r, idx*2+2, med, to));
            return ret + segAdd[idx];
        }
    }


    public static class FenwickTree {
        long N;
        int[] data;

        public FenwickTree(int n) {
            N = n;
            data = new int[n + 1];
        }

        /**
         * Computes value of [1, i].
         * <p>
         * O(logn)
         *
         * @param i
         * @return
         */
        public int sum(int i) {
            int s = 0;
            while (i > 0) {
                s += data[i];
                i -= i & (-i);
            }
            return s;
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
        public int range(int i, int j) {
            return sum(j) - sum(i - 1);
        }

        /**
         * Sets value x into i-th position.
         * <p>
         * O(logn)
         *
         * @param i
         * @param x
         */
        public void set(int i, int x) {
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
        public void add(int i, int x) {
            while (i <= N) {
                data[i] += x;
                i += i & (-i);
            }
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