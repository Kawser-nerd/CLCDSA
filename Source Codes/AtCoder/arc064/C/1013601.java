// package atcoder.arc.arc064;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
    private static final double INF = 1e18;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int[][] sg = in.nextIntTable(2, 2);
        int n = in.nextInt();
        long[][] points = in.nextLongTable(n, 3);
        points = Arrays.copyOf(points, n+2);
        for (int i = n ; i < n+2; i++) {
            points[i] = new long[]{ sg[i-n][0], sg[i-n][1], 0 };
        }

        // start: n-2, goal: n-1
        n += 2;
        UnionFind uf = new UnionFind(n);

        double[][] d2 = new double[n][n];
        for (int i = 0; i < n ; i++) {
            for (int j = i+1 ; j < n ; j++) {
                long rr = points[i][2] + points[j][2];
                long dx = points[i][0] - points[j][0];
                long dy = points[i][1] - points[j][1];
                d2[i][j] = dx*dx+dy*dy;
                if (d2[i][j] <= rr*rr) {
                    uf.unite(i, j);
                }
            }
        }

        double[][] dist = new double[n][n];
        for (int i = 0; i < n ; i++) {
            Arrays.fill(dist[i], INF);
        }
        for (int i = 0; i < n ; i++) {
            for (int j = i+1; j < n ; j++) {
                int from = uf.find(i);
                int to = uf.find(j);
                if (from != to) {
                    if (from > to) {
                        int tmp = to;
                        to = from;
                        from = tmp;
                    }
                    dist[from][to] = Math.min(dist[from][to], Math.sqrt(d2[i][j]) - (points[i][2] + points[j][2]));
                }
            }
        }
        for (int i = 0; i < n ; i++) {
            for (int j = i+1 ; j < n; j++) {
                dist[j][i] = dist[i][j];
            }
        }

        int start = uf.find(n-2);
        int goal = uf.find(n-1);

        Dijkstra dijk = new Dijkstra(dist);
        double[] ans = dijk.doit(start);

        out.println(String.format("%.12f", ans[goal]));
        out.flush();
    }

    static class Dijkstra {
        int n;
        double[][] graph;

        class State implements Comparable<State> {
            int now;
            double time;

            State(int n, double t) {
                now = n;
                time = t;
            }

            @Override
            public int compareTo(State o) {
                return Double.compare(time, o.time);
            }
        }

        public Dijkstra(double[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        double[] doit(int from) {
            double[] dp = new double[n];
            Arrays.fill(dp, INF);
            Queue<State> q = new PriorityQueue<>();
            q.add(new State(from, 0));
            dp[from] = 0;
            while (q.size() >= 1) {
                State st = q.poll();
                for (int to = 0 ; to < n ; to++) {
                    double time = st.time + graph[st.now][to];
                    if (dp[to] > time) {
                        dp[to] = time;
                        q.add(new State(to, time));
                    }
                }
            }
            return dp;
        }
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