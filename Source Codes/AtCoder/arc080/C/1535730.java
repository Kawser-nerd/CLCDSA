import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    FastScanner in = new FastScanner(System.in);
    PrintWriter out = new PrintWriter(System.out);

    class Pair {
        final int idx;
        final int val;

        public Pair(int idx, int val) {
            this.idx = idx;
            this.val = val;
        }

        @Override
        public String toString() {
            final StringBuilder sb = new StringBuilder("Pair{");
            sb.append("idx=").append(idx);
            sb.append(", val=").append(val);
            sb.append('}');
            return sb.toString();
        }
    }

    class SegmentTree {
        int N;
        int[] dat, idx;

        public SegmentTree(int n) {
            N = Integer.highestOneBit(n) << 1;
            int size = (N << 1) - 1;
            // System.out.println(N + " " + size);
            dat = new int[size];
            idx = new int[size];
            Arrays.fill(dat, Integer.MAX_VALUE);
            for (int i = 0; i < (size + 1) / 2; i++) {
                idx[i + size / 2] = i;
            }
        }

        /**
         * Update the segment tree.
         *
         * @param k the index of tree to update
         * @param a the value of tree to update
         */
        void update(int k, int a) {
            k += N - 1;
            dat[k] = a;
            while (k > 0) {
                k = (k - 1) / 2;
                if (dat[k * 2 + 1] < dat[k * 2 + 2]) {
                    dat[k] = dat[k * 2 + 1];
                    idx[k] = idx[k * 2 + 1];
                } else {
                    dat[k] = dat[k * 2 + 2];
                    idx[k] = idx[k * 2 + 2];
                }
            }
        }

        private Pair query(int a, int b, int k, int l, int r) {
            // System.out.println("query : " + a + " " + b + " " + k + " " + l + " " + r);
            if (r < a || b < l) return new Pair(-1, Integer.MAX_VALUE);

            if (a <= l && r <= b) return new Pair(idx[k], dat[k]);
            else {
                Pair vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
                Pair vr = query(a, b, k * 2 + 2, (l + r) / 2 + 1, r);
                return vl.val < vr.val ? vl : vr;
            }
        }

        Pair getMinQuery(int a, int b) {
            return query(a, b, 0, 0, N - 1);
        }

        void display() {
            System.out.println("-------------Segment Tree-------------");
            for (int i = 1; i < dat.length; i *= 2) {
                for (int j = i; j < 2 * i; j++) {
                    System.out.print(dat[j - 1] + " ");
                }
                System.out.println();
            }
            System.out.println("----------------End------------------");
            System.out.println();
        }
    }

    class State implements Comparable<State> {
        final int l, r;
        final Pair pl, pr;

        public State(int l, int r, Pair pl, Pair pr) {
            this.l = l;
            this.r = r;
            this.pl = pl;
            this.pr = pr;
        }

        @Override
        public int compareTo(State s) {
            return pl.val - s.pl.val;
        }
    }

    List<Integer> find(int n, SegmentTree[] segmentTrees) {
        // System.out.println(l + " " + r);
        List<Integer> res = new ArrayList<>();

        State initialState = findState(0, n - 1, segmentTrees);
        PriorityQueue<State> pq = new PriorityQueue<>();
        pq.add(initialState);

        while (!pq.isEmpty()) {
            State ns = pq.poll();
            Pair pl = ns.pl, pr = ns.pr;
            res.add(pl.val);
            res.add(pr.val);
            if (ns.l < pl.idx - 1) {
                pq.add(findState(ns.l, pl.idx - 1, segmentTrees));
            }
            if (pl.idx + 1 < pr.idx - 1) {
                pq.add(findState(pl.idx + 1, pr.idx - 1, segmentTrees));
            }
            if (pr.idx + 1 < ns.r) {
                pq.add(findState(pr.idx + 1, ns.r, segmentTrees));
            }
        }
        return res;
    }

    private State findState(int l, int r, SegmentTree[] segmentTrees) {
        Pair nl = segmentTrees[l%2].getMinQuery(l, r);
        Pair nr = segmentTrees[(l+1)%2].getMinQuery(nl.idx + 1, r);
        return new State(l, r, nl, nr);
    }

    void run() {
        int N = in.nextInt();
        int[] a = in.nextIntArray(N);

        // 0: even, 1: odd
        SegmentTree[] segmentTrees = {new SegmentTree(N), new SegmentTree(N)};
        for (int i = 0; i < N; i++) {
            segmentTrees[i%2].update(i, a[i]);
        }

        List<Integer> res = find(N, segmentTrees);
        for (int v : res) {
            out.print(v + " ");
        }
        out.println();
        out.close();
    }

    public static void main(String[] args) {
        new Main().run();
    }

    class FastScanner {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public FastScanner(InputStream stream) {
            this.stream = stream;
            //stream = new FileInputStream(new File("dec.in"));

        }

        int read() {
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

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        boolean isEndline(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            return nextIntArray(n, 0);
        }

        int[] nextIntArray(int n, int margin) {
            int[] array = new int[n + margin];
            for (int i = 0; i < n; i++)
                array[i + margin] = nextInt();

            return array;
        }

        int[][] nextIntMap(int n, int m) {
            int[][] map = new int[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextIntArray(m);
            }
            return map;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        long[] nextLongArray(int n) {
            return nextLongArray(n, 0);
        }

        long[] nextLongArray(int n, int margin) {
            long[] array = new long[n + margin];
            for (int i = 0; i < n; i++)
                array[i + margin] = nextLong();

            return array;
        }

        long[][] nextLongMap(int n, int m) {
            long[][] map = new long[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextLongArray(m);
            }
            return map;
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        double[] nextDoubleArray(int n) {
            return nextDoubleArray(n, 0);
        }

        double[] nextDoubleArray(int n, int margin) {
            double[] array = new double[n + margin];
            for (int i = 0; i < n; i++)
                array[i + margin] = nextDouble();

            return array;
        }

        double[][] nextDoubleMap(int n, int m) {
            double[][] map = new double[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextDoubleArray(m);
            }
            return map;
        }

        String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        String[] nextStringArray(int n) {
            String[] array = new String[n];
            for (int i = 0; i < n; i++)
                array[i] = next();

            return array;
        }

        String nextLine() {
            int c = read();
            while (isEndline(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndline(c));
            return res.toString();
        }
    }
}