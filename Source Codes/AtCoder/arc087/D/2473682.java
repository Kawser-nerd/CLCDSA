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
        graph = buildGraph(in, n, n-1);
        children = new int[n];
        parent = new int[n];

        prec(10000);

        dfs(0, -1);

        debug(children);
        debug(parent);

        long ans = 0;
        for (int i = 0 ; i < n ; i++) {
            int maxC = n-children[i];
            for (int to : graph[i]) {
                if (to == parent[i]) {
                    continue;
                }
                maxC = Math.max(maxC, children[to]);
            }
            if (n % 2 == 0 && maxC == n/2) {
                ans = solveEven(n);
                break;
            } else if (maxC <= n/2) {
                ans = solveAsRoot(i);
                break;
            }
        }
        out.println(ans);
        out.flush();
    }

    private static long solveAsRoot(int rt) {
        int n = graph.length;
        int cn = graph[rt].length;
        int[] childCount = new int[cn];
        int ci = 0;
        if (rt != 0) {
            childCount[ci++] = n - children[rt];
        }
        for (int to : graph[rt]) {
            if (to == parent[rt]) {
                continue;
            }
            childCount[ci++] = children[to];
        }
        Arrays.sort(childCount);

        debug(rt, childCount);

        int[][][][] dp = new int[2][2][2][n+1];
        dp[0][0][0][1] = 1;

        for (int i = 0 ; i < cn ; i++) {
            int fr = i % 2;
            int to = 1 - fr;
            for (int one = 0 ; one <= 1 ; one++) {
                for (int parity = 0; parity <= 1; parity++) {
                    Arrays.fill(dp[to][one][parity], 0);
                }
            }

            int cnt = childCount[i];
            for (int one = 0 ; one <= 0 ; one++) {
                for (int parity = 0 ; parity <= 1 ; parity++) {
                    for (int free = 0 ; free <= n ; free++) {
                        long base = dp[fr][one][parity][free];
                        if (base == 0) {
                            continue;
                        }

                        // all-out
                        add(dp, to, one, parity, free+cnt, base);
                        for (int inner = 1 ; inner <= cnt ; inner++) {
                            long add = base * comb(cnt, inner) % MOD * perm(cnt, inner) % MOD;
                            add(dp, to, one, parity^(inner%2), free+cnt-inner, add);
                        }

                        // pick one of child
//                        if (one == 0) {
//                            base *= cnt;
//                            base %= MOD;
//
//                            // all-out
//                            add(dp, to, 1, parity, free+cnt, base);
//                            for (int inner = 1 ; inner <= cnt-1 ; inner++) {
//                                long add = base * comb(cnt, inner) % MOD * perm(cnt-1, inner) % MOD;
//                                add(dp, to, 1, parity^1, free+cnt-inner, add);
//                            }
//                        }

                    }
                }
            }
        }

        long ways = 0;
        for (int one = 0 ; one <= 0 ; one++) {
            for (int parity = 0 ; parity <= 1 ; parity++) {
                for (int free = 0 ; free <= n ; free++) {
                    long t = dp[cn%2][one][parity][free];
                    t *= _fact[free];
                    t %= MOD;
                    if (parity == 0) {
                        ways += t;
                    } else {
                        ways += MOD-t;
                    }
                    ways %= MOD;
                }
            }
        }
        return ways%MOD;
    }

    static void add(int[][][][] dp, int a, int b, int c, int d, long v) {
        dp[a][b][c][d] += v;
        if (dp[a][b][c][d] >= MOD) {
            dp[a][b][c][d] -= MOD;
        }
    }

    private static long solveEven(int n) {
        return _fact[n/2] * _fact[n/2] % MOD;
    }

    static int[][] graph;
    static int[] parent;
    static int[] children;
    static int dfs(int now, int par) {
        children[now] = 1;
        parent[now] = par;
        for (int to : graph[now]) {
            if (to == par) {
                continue;
            }
            children[now] += dfs(to, now);
        }
        return children[now];
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

    static long perm(long ln, long lr) {
        int n = (int) ln;
        int r = (int) lr;
        if (n < 0 || r < 0 || r > n) {
            return 0;
        }
        return (_fact[n] * _invfact[n - r]) % MOD;
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


    public static void debug(Object... o) {
        //System.err.println(Arrays.deepToString(o));
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