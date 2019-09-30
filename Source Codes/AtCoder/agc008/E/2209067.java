// package agc.agc008;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    static final long MOD = 1000000007;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] a = new int[n];
        int[] indeg = new int[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextInt()-1;
            indeg[a[i]]++;
        }

        // doit(a);
        // 10
        // 2 3 4 5 1 1 6 7 8 9

        for (int i = 0; i < n ; i++) {
            if (indeg[i] >= 3) {
                out.println(0);
                out.flush();
                return;
            }
        }

        UnionFind f = new UnionFind(n);
        for (int i = 0; i < n ; i++) {
            f.unite(i, a[i]);
        }

        int[] wcnt = new int[n+1];
        long ans = 1;

        List<Integer>[] list = new List[n];
        for (int i = 0; i < n ; i++) {
            int id = f.find(i);
            if (list[id] == null) {
                list[id] = new ArrayList<>();
            }
            list[id].add(i);
        }


        boolean[] visitedG = new boolean[n];
        boolean[] inloop = new boolean[n];
        for (int i = 0; i < n ; i++) {
            int id = f.find(i);
            if (visitedG[id]) {
                continue;
            }
            visitedG[id] = true;

            int gcount = f.groupCount(id);
            int cnt = 0;
            int ptr = i;
            for (int j = 0; j < gcount ; j++) {
                ptr = a[ptr];
            }
            while (!inloop[ptr]) {
                inloop[ptr] = true;
                cnt++;
                ptr = a[ptr];
            }
            if (cnt == f.groupCount(id)) {
                wcnt[cnt]++;
            } else {
                ans *= solveLeggedRing(a, list[id], inloop, indeg, cnt);
                ans %= MOD;
            }
        }

        for (int i = 1 ; i <= n; i++) {
            if (wcnt[i] >= 1) {
                ans *= solveRing(i, wcnt[i]);
                ans %= MOD;
            }
        }

        out.println(ans);
        out.flush();
    }

    private static long solveRing(int size, int count) {
        long[] dp = new long[count+1];
        long ptn = (size >= 3 && size % 2 == 1) ? 2 : 1;
        dp[0] = 1;
        dp[1] = ptn;
        for (int i = 2 ; i <= count ; i++) {
            dp[i] = (dp[i-1] * ptn) + (dp[i-2] * size % MOD * (i-1) % MOD);
            dp[i] %= MOD;
        }
        return dp[count];
    }

    private static long solveLeggedRing(int[] a, List<Integer> group, boolean[] inloop, int[] indeg, int loopSize) {
        List<Integer> lp = new ArrayList<>();
        Map<Integer,Integer> lpmap = new HashMap<>();
        for (int v : group) {
            if (!inloop[v] && indeg[v] >= 2) {
                return 0;
            }
        }

        for (int v : group) {
            if (inloop[v]) {
                int ptr = v;
                for (int i = 0; i < loopSize; i++) {
                    lp.add(ptr);
                    ptr = a[ptr];
                }
                Collections.reverse(lp);
                for (int i = 0 ; i < lp.size() ; i++) {
                    lpmap.put(lp.get(i), i);
                }
                break;
            }
        }

        List<int[]> legs = new ArrayList<>();
        boolean[] isRootOfLeg = new boolean[lp.size()];
        for (int v : group) {
            if (indeg[v] == 0) {
                int lcnt = 0;
                int ptr = v;
                while (!inloop[ptr]) {
                    lcnt++;
                    ptr = a[ptr];
                }
                int lidx = lpmap.get(ptr);
                legs.add(new int[]{lidx, lcnt});
                isRootOfLeg[lidx] = true;
            }
        }
        legs.sort(Comparator.comparingInt(u -> u[0]));

        if (legs.size() == 0) {
            throw new RuntimeException("arien");
        }

        long ptn = 1;
        for (int[] leg : legs) {
            int now = leg[0];

            int last = 2;
            for (int i = 0 ; i < leg[1] ; i++) {
                now = (now + 1) % lp.size();
                if (isRootOfLeg[now]) {
                    if (i == leg[1]-1) {
                        last = 1;
                    } else {
                        return 0;
                    }
                }
            }
            ptn *= last;
            ptn %= MOD;
        }
        return ptn;
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


    public static void doit(int[] a) {
        int n = a.length;
        int[] p = new int[n];
        for (int i = 0; i < n ; i++) {
            p[i] = i;
        }

        // 10
        // 1 0 3 2 5 4 7 6 9 8

        int cnt = 0;
        do {
            if (isOK(p, a)) {
                debug(p);
                cnt++;
            }
        } while (next_permutation(p));

        debug(cnt, "ways");
    }


    public static int reverseDoit(int[] p, int[] a, int idx) {
        int n = a.length;
        if (idx == n) {
            if (isOK(p, a)) {
                debug(a);
                return 1;
            }
            return 0;
        }
        int sum = 0;
        for (int i = 0; i < n ; i++) {
            a[idx] = i;
            sum += reverseDoit(p, a, idx+1);
        }
        return sum;
    }


    public static boolean next_permutation(int[] a) {
        int len = a.length;
        int x = len - 2;
        while (x >= 0 && a[x] >= a[x + 1]) {
            x--;
        }
        if (x == -1) {
            return false;
        }

        int y = len - 1;
        while (y > x && a[y] <= a[x]) {
            y--;
        }
        int tmp = a[x];
        a[x] = a[y];
        a[y] = tmp;
        Arrays.sort(a, x + 1, len);
        return true;
    }


    public static boolean isOK(int[] p, int[] a) {
        for (int i = 0; i < a.length ; i++) {
            if (!(p[i] == a[i] || p[p[i]] == a[i])) {
                return false;
            }
        }
        return true;
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