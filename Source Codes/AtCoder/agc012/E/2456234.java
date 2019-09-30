// package agc.agc012;

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
        int V = in.nextInt();
        int[] x = new int[n];
        for (int i = 0; i < n ; i++) {
            x[i] = in.nextInt();
        }
        int[] revx = x.clone();
        for (int i = 0; i < x.length; i++) {
            revx[i] = -x[n-1-i];
        }

        int[] left = doit(V, x);
        int[] right = doit(V, revx);
        int[] top = stepV(V, x);

        UnionFind uf = new UnionFind(n);
        for (int i = 0; i < n ; ) {
            int j = i;
            while (j < n && top[i] == top[j]) {
                uf.unite(i, j);
                j++;
            }
            i = j;
        }

        boolean[] isOK = new boolean[n];
        int full = (1<<REDUCE)-1;
        for (int leftp = 0 ; leftp <= full ; leftp++) {
            if (left[leftp] + right[full-leftp] >= n) {
                Arrays.fill(isOK, true);
                continue;
            }

            int tc = top[left[leftp]];
            int rp = right[full-leftp];
            if (tc + rp >= n) {
                //debug(leftp, left[leftp], top[left[leftp]]);
                int id = uf.find(left[leftp]);
                isOK[id] = true;
                // ok!
            }
        }

        for (int i = 0; i < n ; i++) {
            out.println(isOK[uf.find(i)] ? "Possible" : "Impossible");
        }
        out.flush();
    }

    static int REDUCE = 19;

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


    static int[] stepV(int V, int[] x) {
        int[] next = new int[x.length+1];
        if (V == -1) {
            return next;
        }
        for (int i = 0; i < x.length ; ) {
            int j = i;
            while (j+1 < x.length && x[j+1] - x[j] <= V) {
                j++;
            }
            for (int k = i ; k <= j; k++) {
                next[k] = j+1;
            }
            i = j+1;
        }
        next[x.length] = x.length;
        return next;
    }

    static int[] doit(int V, int[] x) {
        int[] vs = new int[REDUCE];
        Arrays.fill(vs, -1);
        vs[0] = V/2;
        for (int i = 1 ; i < vs.length; i++) {
            vs[i] = vs[i-1] / 2;
            if (vs[i] == 0) {
                break;
            }
        }
        int[][] next = new int[REDUCE][];
        for (int gi = 0 ; gi < next.length ; gi++) {
            int v = vs[gi];
            next[gi] = stepV(v, x);
        }

        int[] dp = new int[1<<REDUCE];
        for (int set = 0; set < dp.length ; set++) {
            for (int i = 0; i < REDUCE ; i++) {
                if ((set & (1<<i)) >= 1) {
                    continue;
                }
                int now = dp[set];
                int ti = set | (1<<i);
                dp[ti] = Math.max(dp[ti], Math.max(now, next[i][now]));
            }
        }
        return dp;
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