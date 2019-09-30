// package atcoder.arc.arc021;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        long x = 123456789;
        long y = 362436069;
        long z = 521288629;
        long w = in.nextInt();
        int n = 5000;

        table = new long[n][200];
        table2 = new double[n];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < 200; j++) {
                long t = x ^ (x << 11) & ((1L<<32)-1);
                x = y;
                y = z;
                z = w;
                w = (w ^ (w >>> 19)) ^ (t ^ (t >>> 8));

                long v = w % 100000 - 50000;
                if (v >= 0) {
                    v++;
                }
                table[i][j] = v;
            }

            long d2 = 0;
            for (int j = 0; j < 200 ; j++) {
                d2 += table[i][j] * table[i][j];
            }
            table2[i] = Math.sqrt(d2);
        }

        long[][] bs = new long[n][4];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < 200; j++) {
                if (table[i][j] > 0) {
                    int bucket = j / 50;
                    int th = j % 50;
                    bs[i][bucket] |= 1L<<th;
                }
            }
        }

        UnionFind uf = new UnionFind(n);
        List<Edge> edges = new ArrayList<>();



        for (int i = 0 ; i < n ; i++) {
            for (int j = i+1; j < n ; j++) {
                long diff = 0;
                for (int k = 0; k < 4 ; k++) {
                    diff += Long.bitCount(bs[i][k] ^ bs[j][k]);
                }
                if (diff <= 85) {
                    edges.add(new Edge(i, j));
                }
            }
        }
        Collections.sort(edges);

        // double total = 0;
        for (Edge e : edges) {
            if (uf.issame(e.a, e.b)) {
                continue;
            }
            uf.unite(e.a, e.b);
            // total += e.cost;
            out.println(String.format("%d %d", e.a+1, e.b+1));
        }

        // debug(total);


        out.flush();
    }


    static class UnionFind {
        int[] rank;
        int[] parent;
        int[] cnt;

        public UnionFind(int n) {
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

    static class Edge implements Comparable<Edge> {
        int a;
        int b;
        double cost;

        Edge(int aa, int bb) {
            a = aa;
            b = bb;
            cost = compute(a, b);
        }

        @Override
        public int compareTo(Edge o) {
            return Double.compare(cost, o.cost);
        }
    }

    static long[][] table;
    static double[] table2;

    static double compute(int a, int b) {
        long up = 0;
        for (int i = 0; i < 200; i++) {
            up += table[a][i] * table[b][i];
        }
        double bottom = table2[a] * table2[b];
        return 1 - up / bottom;
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