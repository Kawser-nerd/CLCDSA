// package arc.arc087;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    private static final long MOD = 1000000007;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        prec(10000);

        int n = in.nextInt();
        graph = buildGraph(in, n, n-1);
        count = new int[n];
        parent = new int[n];
        dfs(0, -1);

        out.println(solve());
        out.flush();
    }

    private static long solve() {
        int n = graph.length;
        if (n % 2 == 0) {
            boolean found = false;
            for (int i = 0; i < n; i++) {
                if (count[i] == n / 2) {
                    found = true;
                    break;
                }
            }
            if (found) {
                return _fact[n/2] * _fact[n/2] % MOD;
            }
        }

        for (int i = 0; i < n ; i++) {
            List<Integer> arr = new ArrayList<>();
            for (int to : graph[i]) {
                if (to == parent[i]) {
                    continue;
                }
                arr.add(count[to]);
            }
            if (parent[i] != -1) {
                arr.add(n-count[i]);
            }
            Collections.sort(arr);

            int left = n-1-arr.get(arr.size()-1);
            if (left >= arr.get(arr.size()-1)) {
                return solve2(n, arr);
            }
        }

        throw new RuntimeException("arien");
    }

    private static long solve2(int n, List<Integer> arr) {
        int gn = arr.size();

        long[][] dp = new long[2][n];
        dp[0][0] = 1;
        for (int i = 0; i < gn ; i++) {
            int fr = i % 2;
            int to = 1 - fr;
            Arrays.fill(dp[to], 0);
            int S = arr.get(i);
            for (int j = 0 ; j < n ; j++) {
                if (dp[fr][j] == 0) {
                    continue;
                }
                long base = dp[fr][j];
                for (int k = 0 ; k <= S ; k++) {
                    int tj = j+k;
                    if (tj < n) {
                        long add = base * _fact[S] % MOD * _invfact[S-k] % MOD * comb(S, k) % MOD;
                        dp[to][tj] += add;
                        if (dp[to][tj] >= MOD) {
                            dp[to][tj] -= MOD;
                        }
                    }
                }
            }
        }

        long ways = 0;
        for (int i = 0 ; i < n ; i++) {
            long part = dp[gn%2][i] * _fact[n-i] % MOD;
            if (i % 2 == 0) {
                ways += part;
            } else {
                ways += MOD-part;
            }
        }
        return ways % MOD;
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

    static long[] _fact;
    static long[] _invfact;

    static long comb(long ln, long lr) {
        int n = (int) ln;
        int r = (int) lr;
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


    static int dfs(int now, int par) {
        parent[now] = par;
        for (int to : graph[now]) {
            if (to == par) {
                continue;
            }
            count[now] += dfs(to, now);
        }
        count[now] += 1;
        return count[now];
    }


    static int[] parent;
    static int[] count;
    static int[][] graph;

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