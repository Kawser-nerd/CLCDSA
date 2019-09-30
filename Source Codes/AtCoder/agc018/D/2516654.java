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
        graph = buildWeightedGraph(in, n, n-1);
        parent = new int[n];
        weight = new int[n];
        count = new int[n];

        dfs(0, -1);


        boolean isEven = false;
        for (int i = 0; i < n ; i++) {
            if (count[i] == n - count[i]) {
                isEven = true;
            }
        }

        if (isEven) {
            out.println(solveEven());
        } else {
            out.println(solveOdd());
        }
        out.flush();
    }

    private static long solveOdd() {
        int n = graph.length;
        int half = n / 2;
        int center = -1;
        for (int i = 0 ; i < n  ; i++) {
            boolean ok = true;
            for (int[] e : graph[i]) {
                int c = e[0];
                int cnt = count[c];
                if (c == parent[i]) {
                    cnt = n - count[i];
                }
                if (cnt > half) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                center = i;
            }
        }

        int best = (int)1e9;
        for (int[] e : graph[center]) {
            best = Math.min(best, e[1]);
        }
        long w = 0;
        for (int i = 1 ; i < n  ; i++) {
            long tk = Math.min(count[i], n - count[i]);
            w += tk * 2 * weight[i];
        }
        return w - best;
    }

    private static long solveEven() {
        int n = graph.length;
        long w = 0;
        for (int i = 1 ; i < n  ; i++) {
            long tk = Math.min(count[i], n - count[i]);
            if (n / 2 == count[i]) {
                w += (tk * 2 - 1) * weight[i];
            } else {
                w += tk * 2 * weight[i];
            }
        }
        return w;
    }

    static int[] parent;
    static int[] weight;
    static int[] count;
    static long[] inner;
    static long[] outer;

    static void dfs(int now, int par) {
        count[now] = 1;
        for (int[] e : graph[now]) {
            if (e[0] == par) {
                continue;
            }
            parent[e[0]] = now;
            weight[e[0]] = e[1];
            dfs(e[0], now);
            count[now] += count[e[0]];
        }
    }

    static int[][][] graph;

    static int[][][] buildWeightedGraph(InputReader in, int n, int m) {
        int[][] edges = new int[m][];
        int[][][] graph = new int[n][][];
        int[] deg = new int[n];
        for (int i = 0 ; i < m ; i++) {
            int a = in.nextInt()-1;
            int b = in.nextInt()-1;
            int w = in.nextInt();
            deg[a]++;
            deg[b]++;
            edges[i] = new int[]{a, b, w};
        }
        for (int i = 0 ; i < n ; i++) {
            graph[i] = new int[deg[i]][2];
        }
        for (int i = 0 ; i < m ; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];
            graph[a][--deg[a]][0] = b;
            graph[b][--deg[b]][0] = a;
            graph[a][deg[a]][1] = w;
            graph[b][deg[b]][1] = w;
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