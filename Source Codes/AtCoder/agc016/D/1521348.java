// package atcoder.agc.agc016;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    private static final int SPECIAL = -1000000000;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] a = in.nextInts(n);
        int[] b = in.nextInts(n);
        
        out.println(solve(a, b));
        out.flush();
    }

    private static int solve(int[] a, int[] b) {
        int n = a.length;
        int f = 0;
        for (int i = 0; i < a.length; i++) {
            if (a[i] == b[i]) {
                f++;
            }
        }
        if (f == n) {
            return 0;
        }

        Map<Integer,Integer> mp = new HashMap<>();
        int xa = 0;
        for (int i = 0 ; i < n ; i++) {
            xa ^= a[i];
            if (a[i] != b[i]) {
                mp.put(a[i], mp.getOrDefault(a[i], 0)+1);
                mp.put(b[i], mp.getOrDefault(b[i], 0)-1);
            }
        }

        int pl = -1;
        int mi = -1;
        for (int k : mp.keySet()) {
            int v = mp.get(k);
            if (v == 0) {
                continue;
            }
            if (Math.abs(v) >= 2) {
                return -1;
            }
            if (v == 1) {
                if (pl != -1) {
                    return -1;
                }
                pl = k;
            } else {
                if (mi != -1) {
                    return -1;
                }
                mi = k;
            }
        }
        if (mi != -1 && xa != mi) {
            return -1;
        }

        boolean bonus = false;
        for (int i = 0 ; i < n ; i++) {
            if (b[i] == xa) {
                bonus = true;
                if (pl != -1) {
                    b[i] = SPECIAL;
                }
                break;
            }
        }
        return solve2(a, b, pl) + (bonus ? -1 : 0);
    }

    private static int solve2(int[] a, int[] b, int pl) {
        int n = a.length;
        int[] wa = new int[n];
        int[] wb = new int[n];
        int idx = 0;
        for (int i = 0; i < a.length; i++) {
            if (a[i] == b[i]) {
                continue;
            }
            wa[idx] = a[i];
            wb[idx] = b[i];
            idx++;
        }
        return solve3(Arrays.copyOf(wa, idx), Arrays.copyOf(wb, idx), pl);
    }


    private static int solve3(int[] a, int[] b, int pl) {
        int n = a.length;
        int[][] ap = new int[n][2];
        for (int i = 0; i < n ; i++) {
            ap[i][0] = a[i];
            ap[i][1] = i;
        }

        Arrays.sort(ap, (u, v) -> u[0] - v[0]);
        Map<Integer,Integer> valueToIndex = new HashMap<>();
        UnionFind uf = new UnionFind(n);
        for (int f = 0 ; f < n ; ) {
            int t = f;
            while (t < n && ap[f][0] == ap[t][0]) {
                uf.unite(ap[f][1], ap[t][1]);
                t++;
            }
            valueToIndex.put(ap[f][0], ap[f][1]);
            f = t;
        }
        for (int ci = 0; ci < n ; ci++) {
            if (a[ci] == b[ci]) {
                continue;
            }
            int to = b[ci] == SPECIAL ? pl : b[ci];
            int idx = valueToIndex.get(to);
            uf.unite(ci, idx);
        }
        return n + uf.gn;
    }

    static class UnionFind {
        int[] rank;
        int[] parent;
        int[] cnt;
        int gn;

        public UnionFind(int n) {
            gn = n;
            rank = new int[n];
            parent = new int[n];
            cnt = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                cnt[i] = 1;
            }
        }

        public int find(int a) {
            if (parent[a] == a) {
                return a;
            }
            parent[a] = find(parent[a]);
            return parent[a];
        }

        public void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return;
            }
            gn--;
            if (rank[a] < rank[b]) {
                parent[a] = b;
                cnt[b] += cnt[a];
                cnt[a] = cnt[b];
            } else {
                parent[b] = a;
                cnt[a] += cnt[b];
                cnt[b] = cnt[a];
                if (rank[a] == rank[b]) {
                    rank[a]++;
                }
            }
        }

        public int groupCount(int a) {
            return cnt[find(a)];
        }

        private boolean issame(int a, int b) {
            return find(a) == find(b);
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