// package atcoder.arc.arc061;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by hama_du on 2016/09/11.
 */
public class Main {
    private static final int INF = 100000000;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        int[][] edges = new int[m][3];
        for (int i = 0; i < m ; i++) {
            for (int j = 0; j < 3 ; j++) {
                edges[i][j] = in.nextInt()-1;
            }
        }
        Arrays.sort(edges, (a, b) -> a[2] - b[2]);

        int V = 0;
        int[][] newEdges = new int[m][3];
        for (int i = 0; i < m ;) {
            int j = i;
            while (j < m && edges[i][2] == edges[j][2]) {
                j++;
            }
            Map<Integer,Integer> localMap = new HashMap<>();
            for (int k = i ; k < j ; k++) {
                for (int l = 0; l <= 1; l++) {
                    if (!localMap.containsKey(edges[k][l])) {
                        localMap.put(edges[k][l], V++);
                    }
                    newEdges[k][l] = localMap.get(edges[k][l]);
                }
            }
            i = j;
        }

        List<int[]>[] graph = new List[V+n];
        for (int i = 0; i < graph.length ; i++) {
            graph[i] = new ArrayList<>();
        }

        Set<Integer> touched = new HashSet<>();
        for (int i = 0; i < m ; i++) {
            for (int j = 0; j <= 1; j++) {
                if (!touched.contains(newEdges[i][j])) {
                    touched.add(newEdges[i][j]);
                    int centerV = V+edges[i][j];
                    graph[centerV].add(new int[]{newEdges[i][j], 1});
                    graph[newEdges[i][j]].add(new int[]{centerV, 0});
                }
            }
            graph[newEdges[i][0]].add(new int[]{newEdges[i][1], 0});
            graph[newEdges[i][1]].add(new int[]{newEdges[i][0], 0});
        }

        int[] dp = new int[V+n];
        Arrays.fill(dp, INF);
        dp[V] = 0;
        Deque<Integer> deq = new ArrayDeque<>((V+n)*2);
        deq.push(V);
        while (deq.size() >= 1) {
            int now = deq.pollFirst();

            for (int[] e : graph[now]) {
                int to = dp[now] + e[1];
                if (dp[e[0]] > to) {
                    dp[e[0]] = to;
                    if (e[1] == 0) {
                        deq.addFirst(e[0]);
                    } else {
                        deq.addLast(e[0]);
                    }
                }
            }
        }
        out.println(dp[V+n-1] == INF ? -1 : dp[V+n-1]);
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
            for (int i = 0; i < n ; i++) {
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


    static class State implements Comparable<State> {
        int eid;
        int cost;

        public State(int e, int c) {
            eid = e;
            cost = c;
        }

        @Override
        public int compareTo(State o) {
            return cost - o.cost;
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.