// package atcoder.agc.agc018;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        graph = buildWeightedGraph(in, n, n-1);
        cn = new int[n];
        pp = new int[n];
        pw = new int[n];

        dfs(0, -1);

        out.println(solve());
        out.flush();
    }

    static long solve() {
        int n = graph.length;
        long ans = 0;
        for (int v = 1 ; v < n ; v++) {
            long min = Math.min(cn[v], n-cn[v]);
            ans += min * 2 * pw[v];
        }


        if (n % 2 == 0) {
            for (int i = 1 ; i < n ; i++) {
                if (cn[i] == n / 2) {
                    ans -= pw[i];
                    return ans;
                }
            }
        }

        for (int i = 0 ; i < n ; i++) {
            int maxW = n - cn[i];
            for (int[] e : graph[i]) {
                if (e[0] == pp[i]) {
                    continue;
                }
                maxW = Math.max(maxW, cn[e[0]]);
            }
            if (maxW <= n / 2) {
                long minW = Long.MAX_VALUE;
                for (int[] e : graph[i]) {
                    minW = Math.min(minW, e[1]);
                }
                ans -= minW;
                return ans;
            }
        }
        throw new RuntimeException();
    }

    static void dfs(int now, int par) {
        pp[now] = par;
        cn[now]++;
        for (int[] e : graph[now]) {
            if (e[0] == par) {
                continue;
            }
            dfs(e[0], now);
            pw[e[0]] = e[1];
            cn[now] += cn[e[0]];
        }
    }

    static int[][][] graph;
    static int[] cn;
    static int[] pp;
    static int[] pw;

    public static int[][] parentCountOrder(int[][] graph, int root) {
        int n = graph.length;
        int[] que = new int[2*n];
        int[] parent = new int[n];
        int[] bfsOrd = new int[n];
        int[] cnt = new int[n];
        int qh = 0, qt = 0;
        que[qh++] = root;
        que[qh++] = -1;
        int vi = 0;
        while (qt < qh) {
            int now = que[qt++];
            int par = que[qt++];
            parent[now] = par;
            bfsOrd[vi++] = now;
            for (int to : graph[now]) {
                if (to == par) {
                    continue;
                }
                que[qh++] = to;
                que[qh++] = now;
            }
        }
        for (int i = n-1 ; i >= 0 ; i--) {
            int now = bfsOrd[i];
            cnt[now]++;
            if (parent[now] != -1) {
                cnt[parent[now]] += cnt[now];
            }
        }
        return new int[][]{ parent, cnt, bfsOrd };
    }


    static int[][][] buildWeightedGraph(InputReader in, int n, int m) {
        int[][] edges = new int[m][];
        int[][][] graph = new int[n][][];
        int[] deg = new int[n];
        for (int i = 0 ; i < m ; i++) {
            int a = in.nextInt()-1;
            int b = in.nextInt()-1;
            int w = in.nextInt();
            deg[a]++;
            deg[b]++;
            edges[i] = new int[]{a, b, w};
        }
        for (int i = 0 ; i < n ; i++) {
            graph[i] = new int[deg[i]][2];
        }
        for (int i = 0 ; i < m ; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];
            graph[a][--deg[a]][0] = b;
            graph[b][--deg[b]][0] = a;
            graph[a][deg[a]][1] = w;
            graph[b][deg[b]][1] = w;
        }
        return graph;
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