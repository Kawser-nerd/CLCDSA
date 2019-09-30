// package arc.arc093;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    private static final long MOD = 1000000007;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        long X = in.nextLong();
        if (m <= 1) {
            out.println(0);
            out.flush();
            return;
        }

        int[][] edges = new int[m][3];
        for (int i = 0; i < m ; i++) {
            edges[i][0] = in.nextInt()-1;
            edges[i][1] = in.nextInt()-1;
            edges[i][2] = in.nextInt();
        }
        Arrays.sort(edges, Comparator.comparingInt(u -> u[2]));


        UnionFind uf = new UnionFind(n);
        int[][] unionEdges = new int[n-1][3];
        boolean[] used = new boolean[m];
        long baseCost = 0;

        int ni = 0;
        for (int i = 0; i < m ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (uf.issame(u, v)) {
                continue;
            }
            used[i] = true;
            baseCost += edges[i][2];
            uf.unite(u, v);
            unionEdges[ni++] = edges[i].clone();
        }

        if (baseCost > X) {
            // muri
            out.println(0);
            out.flush();
            return;
        }

        tree = buildWeightedGraph(n, unionEdges);
        parent = new int[n];
        plength = new int[n];
        depth = new int[n];
        dfs(0, -1);

        long[] pow2mod = new long[m+10];
        pow2mod[0] = 1;
        for (int i = 1 ; i < m+10 ; i++) {
            pow2mod[i] = pow2mod[i-1] * 2 % MOD;
        }

        long[] costDiff = new long[m];
        for (int i = 0; i < m ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (!used[i]) {
                costDiff[i] = edges[i][2] - largestCost(u, v);
            }
        }

        long ans = 0;
        if (baseCost == X) {
            ans += ((pow2mod[n-1] + MOD - 2) % MOD) * pow2mod[m-n+1] % MOD;
        }

        int match = 0;
        int free = 0;
        for (int i = 0; i < m ; i++) {
            if (!used[i]) {
                if (baseCost + costDiff[i] == X) {
                    match++;
                } else if (baseCost + costDiff[i] > X) {
                    free++;
                }
            }
        }
        ans += (pow2mod[free] * ((pow2mod[match] + MOD - 1) % MOD) % MOD) * 2 % MOD;

        out.println(ans % MOD);
        out.flush();
    }

    static int[][][] tree;
    static int[] parent;
    static int[] plength;
    static int[] depth;

    static int largestCost(int u, int v) {
        if (depth[u] == depth[v]) {
            if (u == v) {
                return 0;
            } else {
                int p = largestCost(parent[u], parent[v]);
                return Math.max(plength[u], Math.max(plength[v], p));
            }
        } else if (depth[u] < depth[v]) {
            int p = largestCost(u, parent[v]);
            return Math.max(plength[v], p);
        } else {
            int p = largestCost(parent[u], v);
            return Math.max(plength[u], p);
        }
    }


    static void dfs(int now, int par) {
        for (int[] e : tree[now]) {
            int to = e[0];
            int w = e[1];
            if (to == par) {
                continue;
            }
            parent[to] = now;
            plength[to] = w;
            depth[to] = depth[now] + 1;
            dfs(to, now);
        }
    }


    static int[][][] buildWeightedGraph(int n, int[][] edges) {
        int m = edges.length;
        int[][][] graph = new int[n][][];
        int[] deg = new int[n];
        for (int i = 0 ; i < m ; i++) {
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
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