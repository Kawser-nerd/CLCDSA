// package atcoder.arc.arc062;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        prec(5000);

        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int[][] graph = buildGraph(in, n, m);

        SCC3 scc = new SCC3(graph);
        scc.build();

        long ans = 1;
        for (List<int[]> edges : scc.edgeComponents) {
            int cnt = edges.size();
            if (cnt == 1) {
                ans *= k;
                ans %= MOD;
            } else {
                Set<Integer> vertice = new HashSet<>();
                for (int[] e : edges) {
                    vertice.add(e[0]);
                    vertice.add(e[1]);
                }
                if (vertice.size() == cnt) {
                    long ptn = 0;
                    for (int l = 1 ; l <= cnt ; l++) {
                        ptn += pow(k, gcd(cnt, l));
                    }
                    ans *= ptn % MOD * inv(cnt) % MOD;
                    ans %= MOD;
                } else {
                    ans *= comb(cnt+k-1, k-1);
                    ans %= MOD;
                }
            }
        }

        out.println(ans);
        out.flush();
    }


    public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a%b);
    }


    static final int MOD = 1000000007;

    static long pow(long a, long x) {
        long res = 1;
        while (x > 0) {
            if (x % 2 != 0) {
            res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            x /= 2;
        }
        return res;
    }

    static long inv(long a) {
        return pow(a, MOD - 2) % MOD;
    }

    static long[] _fact;
    static long[] _invfact;
    static long comb(long ln, long lr) {
        int n = (int)ln;
        int r = (int)lr;
        if (n < 0 || r < 0 || r > n) {
            return 0;
        }
        if (r > n / 2) {
            r = n - r;
        }
        return (((_fact[n] * _invfact[n - r]) % MOD) * _invfact[r]) % MOD;
    }

    static void prec(int n) {
        _fact = new long[n + 1];
        _invfact = new long[n + 1];
        _fact[0] = 1;
        _invfact[0] = 1;
        for (int i = 1; i <= n; i++) {
            _fact[i] = _fact[i - 1] * i % MOD;
            _invfact[i] = inv(_fact[i]);
        }
    }




    public static class SCC3 {
        int n;
        int[] ord;
        int[] low;
        int[][] graph;
        boolean[] root;
        int oi = 0;
        Stack<int[]> tmpEdges;

        List<List<int[]>> edgeComponents;

        public SCC3(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
            this.ord = new int[n];
            this.low = new int[n];
            this.root = new boolean[n];
            tmpEdges = new Stack<>();
            edgeComponents = new ArrayList<>();
            Arrays.fill(ord, -1);
            Arrays.fill(low, n);
        }

        public void build() {
            for (int i = 0 ; i < n ; i++) {
                if (ord[i] == -1) {
                    root[i] = true;
                    dfs(i, -1);
                }
            }
        }

        private void dfs(int now, int par) {
            if (ord[now] != -1) {
                return;
            }
            ord[now] = oi;
            low[now] = oi++;
            for (int i = 0 ; i < graph[now].length ; i++) {
                int to = graph[now][i];
                if (to == par) {
                    continue;
                }
                if (ord[to] < ord[now]) {
                    tmpEdges.add(new int[]{now, to});
                }


                if (ord[to] == -1) {
                    dfs(to, now);
                    low[now] = Math.min(low[now], low[to]);
                    if (low[to] >= ord[now]) {
                        List<int[]> edges = new ArrayList<>();
                        while (tmpEdges.size() >= 1) {
                            int[] head = tmpEdges.pop();
                            edges.add(head);
                            if (Math.min(head[0], head[1]) == Math.min(now, to)) {
                                if (Math.max(head[0], head[1]) == Math.max(now, to)) {
                                    break;
                                }
                            }
                        }
                        edgeComponents.add(edges);
                    }
                } else {
                    // that's a back edge!
                    low[now] = Math.min(low[now], ord[to]);
                }
            }
        }
    }



    static int[][] buildGraph(InputReader in, int n, int m) {
        int[][] edges = new int[m][];
        int[][] graph = new int[n][];
        int[] deg = new int[n];
        for (int i = 0 ; i < m ; i++) {
            int a = in.nextInt()-1;
            int b = in.nextInt()-1;
            deg[a]++;
            deg[b]++;
            edges[i] = new int[]{a, b};
        }
        for (int i = 0 ; i < n ; i++) {
            graph[i] = new int[deg[i]];
        }
        for (int i = 0 ; i < m ; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a][--deg[a]] = b;
            graph[b][--deg[b]] = a;
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