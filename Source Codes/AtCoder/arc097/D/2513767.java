import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        graph = buildGraph(in, n, n-1);
        char[] s = in.nextToken().toCharArray();
        color = new int[n];
        for (int i = 0; i < n ; i++) {
            color[i] = s[i] == 'W' ? 0 : 1;
        }

        out.println(solve());
        out.flush();
    }

    static void cutBlackLeaf() {
        int n = graph.length;
        available = new boolean[n];
        Arrays.fill(available, true);

        int[] deg = new int[n];
        int[] que = new int[n];
        int qh = 0;
        for (int i = 0; i < n ; i++) {
            deg[i] = graph[i].length;
            if (deg[i] == 1) {
                if (color[i] == 1) {
                    que[qh++] = i;
                }
            }
        }
        int qt = 0;
        while (qt < qh) {
            int now = que[qt++];
            available[now] = false;
            for (int to : graph[now]) {
                deg[to]--;
                if (deg[to] == 1 && color[to] == 1 && available[to]) {
                    que[qh++] = to;
                }
            }
        }

        for (int i = 0; i < n ; i++) {
            if (available[i]) {
                int de = 0;
                int[] cp = graph[i].clone();
                for (int to : cp) {
                    if (available[to]) {
                        de++;
                    }
                }
                graph[i] = new int[de];
                for (int to : cp) {
                    if (available[to]) {
                        graph[i][--de] = to;
                    }
                }
            } else {
                graph[i] = null;
            }
        }

    }

    static int solve() {
        int n = graph.length;


        if (n == 1) {
            return color[0]^1;
        }

        available = new boolean[n];
        cutBlackLeaf();

        int root = -1;
        int vc = 0;
        for (int i = 0; i < n ; i++) {
            if (available[i]) {
                vc++;
                if (graph[i].length >= 2) {
                    root = i;
                }
            }
        }
        if (vc <= 1) {
            // W or nothing
            return vc;
        }
        if (root == -1) {
            // W-W
            return 2;
        }

        int total = 0;
        for (int i = 0; i < n ; i++) {
            if (available[i]) {
                int gd = graph[i].length;
                color[i] ^= gd % 2;
                total += color[i] ^ 1;
            }
        }
        return (vc - 1) * 2 + total - find(root) * 2;
    }

    static int find(int rt) {
        int[] x = dfs0(rt, -1);
        int[] y = dfs0(x[1], -1);
        return y[0];
    }

    static int[] dfs0(int now, int par) {
        int[] best = new int[]{-1, -1};
        for (int to : graph[now]) {
            if (to == par || !available[to]) {
                continue;
            }
            int[] t = dfs0(to, now);
            if (best[0] < t[0]) {
                best = t.clone();
            }
        }
        if (best[0] == -1) {
            return new int[]{0, now};
        }
        best[0] += color[now] ^ 1;
        return best;
    }

    static boolean[] available;

    static int[] color;
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