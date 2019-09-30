// package agc.agc010;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        gcd = new int[n][n];
        graph = new List[n+1];
        visited = new boolean[n];
        for (int i = 0; i <= n ; i++) {
            graph[i] = new ArrayList<>();
        }
        uf = new UnionFind(n);

        a = new int[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);

        for (int i = 0; i < n ; i++) {
            for (int j = i+1; j < n; j++) {
                gcd[i][j] = gcd[j][i] = (int)gcd(a[i], a[j]);
                if (gcd[i][j] >= 2) {
                    uf.unite(i, j);
                }
            }
        }

        List<Integer> roots = new ArrayList<>();
        for (int i = 0; i < n ; i++) {
            if (!visited[i]) {
                roots.add(i);
                makeTree(i);
                graph[n].add(i);
            }
        }

        int[] ans = dfs(n);
        StringBuilder line = new StringBuilder();
        for (int i = 1 ; i < ans.length ; i++) {
            line.append(' ').append(ans[i]);
        }
        out.println(line.substring(1));
        out.flush();
    }

    static int[] a;
    static int[][] gcd;
    static UnionFind uf;
    static List<Integer>[] graph;
    static boolean[] visited;

    static int[] dfs(int now) {
        int cn = graph[now].size();

        int[][] ln = new int[cn][];
        for (int i = 0; i < cn ; i++) {
            ln[i] = dfs(graph[now].get(i));
        }
        return merge(now >= a.length ? 0 : a[now], ln);
    }

    static int[] merge(int x, int[][] cn) {
        int l = 1;
        int gn = cn.length;
        for (int i = 0; i < gn ; i++) {
            l += cn[i].length;
        }
        int[] d = new int[l];
        d[0] = x;

        int[] gi = new int[gn];
        for (int i = 1 ; i < l ; i++) {
            int ma = 0;
            int max = 0;
            for (int j = 0; j < gn ; j++) {
                if (gi[j] < cn[j].length && max < cn[j][gi[j]]) {
                    max = cn[j][gi[j]];
                    ma = j;
                }
            }
            d[i] = max;
            gi[ma]++;
        }
        return d;
    }

    static void makeTree(int idx) {
        visited[idx] = true;
        for (int i = 0 ; i < a.length ; i++) {
            if (!visited[i] && gcd[idx][i] >= 2) {
                graph[idx].add(i);
                makeTree(i);
            }
        }
    }

    public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a%b);
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.