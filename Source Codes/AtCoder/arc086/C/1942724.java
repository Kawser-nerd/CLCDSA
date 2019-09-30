// package arc.arc086;

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
        parent = new int[n+1];
        parent[0] = -1;

        int[][] edges = new int[n][2];
        for (int i = 0; i < n  ; i++) {
            parent[i+1] = in.nextInt();
            edges[i][0] = i+1;
            edges[i][1] = parent[i+1];
        }
        graph = buildGraph(n+1, edges);
        n++;

        levelDeg = new int[n];
        dfs(0, 0);

        long[] pow2 = new long[n+10];
        pow2[0] = 1;
        for (int i = 1 ; i < pow2.length; i++) {
            pow2[i] = (pow2[i-1] * 2) % MOD;
        }

        Stack<long[]>[] dp = new Stack[n];
        Stack<long[]> tmpstk = new Stack<>();
        List<long[]> ord = new ArrayList<>();
        for (int i = n-1 ; i >= 0 ; i--) {
            int maxTo = -1;
            int maxDepth = -1;
            int cn = 0;
            for (int to : graph[i]) {
                if (to == parent[i]) {
                    continue;
                }
                cn++;
                if (maxDepth < dp[to].size()) {
                    maxDepth = dp[to].size();
                    maxTo = to;
                }
            }
            if (maxTo == -1) {
                dp[i] = new Stack<>();
                dp[i].push(new long[]{1, 1});
            } else if (cn == 1) {
                dp[i] = dp[maxTo];
                dp[i].push(new long[]{1, 1});
            } else {
                while (true) {
                    ord.clear();
                    for (int to : graph[i]) {
                        if (to == parent[i]) {
                            continue;
                        }
                        if (dp[to].size() >= 1) {
                            ord.add(dp[to].pop());
                        }
                    }
                    if (ord.size() == 0) {
                        break;
                    } else {
                        tmpstk.push(compute(ord));
                        if (ord.size() == 1) {
                            break;
                        }
                    }
                }

                dp[i] = dp[maxTo];
                while (tmpstk.size() >= 1) {
                    dp[i].push(tmpstk.pop());
                }
                dp[i].push(new long[]{1, 1});

            }
        }

        long total = 0;
        int lv = 0;
        while (dp[0].size() >= 1) {
            long one = dp[0].pop()[1];
            total += one * pow2[n-levelDeg[lv]] % MOD;
            total %= MOD;
            lv++;
        }

        out.println(total);
        out.flush();
    }

    static int[] levelDeg;

    static void dfs(int now, int level) {
        levelDeg[level]++;
        for (int to : graph[now]) {
            if (parent[now] == to) {
                continue;
            }
            dfs(to, level+1);
        }
    }

    private static long[] compute(List<long[]> ord) {
        long one = 0;
        long total = 1;
        long allZero = 1;
        for (long[] o : ord) {
            total *= (o[0]+o[1])%MOD;
            total %= MOD;
            one += o[1] * inv(o[0]) % MOD;
            one %= MOD;
            allZero *= o[0];
            allZero %= MOD;
        }
        one *= allZero;
        one %= MOD;
        return new long[]{(total-one+MOD)%MOD, one};
    }

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

    static int[] count;
    static int[][] graph;
    static int[] parent;

    static int[][] buildGraph(int n, int[][] edges) {
        int m = edges.length;
        int[][] graph = new int[n][];
        int[] deg = new int[n];
        for (int i = 0 ; i < m ; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            deg[a]++;
            deg[b]++;
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