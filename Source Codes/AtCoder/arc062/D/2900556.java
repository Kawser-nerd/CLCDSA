import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static long __startTime = System.currentTimeMillis();

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();

        C = new long[300][300];
        for (int i = 0; i < C.length; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1 ; j < i ; j++) {
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
            }
        }


        graph = buildGraph(in, n, m);
        SCC3 scc3 = new SCC3(graph);
        scc3.build();

        long ways = 1;
        for (List<int[]> edges : scc3.edgeComponents) {
            debug(edges.size());
            Set<Integer> vset = new HashSet<>();
            for (int[] e : edges) {
                vset.add(e[0]);
                vset.add(e[1]);
            }
            if (edges.size() == 1) {
                ways *= k;
            } else if (edges.size() == vset.size()) {
                ways *= loop1(k, vset.size());
            } else {
                ways *= loop2(k, edges.size());
            }
            ways %= MOD;
        }

        out.println(ways);
        out.flush();
    }

    static long loop2(int k, int e) {
        return C[e+k-1][k-1];
    }

    static long loop1(int k, int n) {
        // paint n circular balls in k colors
        long total = 0;
        for (int i = 1 ; i <= n ; i++) {
            total += pow(k, gcd(n, i));
            total %= MOD;
        }
        return total * inv(n) % MOD;
    }


    public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a%b);
    }

    static long[][] C;
    static int[][] graph;

    static long MOD = 1000000007;

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



    /**
     * Decompose graph edges into components such that each component doesn't contain an articulation point.
     */
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


    private static void printTime(String label) {
        debug(label, System.currentTimeMillis() - __startTime);
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