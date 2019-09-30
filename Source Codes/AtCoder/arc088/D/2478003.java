import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[][] graph = buildGraph(in, n, n-1);

        out.println(solve(graph));
        out.flush();
    }

    private static String solve(int[][] _graph) {
        graph = _graph;
        n = graph.length;

        int a = 1;
        for (int i = 0; i < n ; i++) {
            a += (graph[i].length - 1) / 2;
        }

        for (int i = 0; i < n ; i++) {
            if (graph[i].length == 1) {
                root = i;
            }
        }

        int minB = 0;
        int maxB = n+10;
        while (maxB - minB > 1) {
            int med = (minB + maxB) / 2;
            if (isOK(med)) {
                maxB = med;
            } else {
                minB = med;
            }
        }
        return String.format("%d %d", a, maxB);
    }

    private static boolean isOK(int med) {
        limit = med;
        // debug(root, med, dfs(root, -1));
        return dfs(root, -1) <= limit;
    }

    static int dfs(int now, int par) {
        List<Integer> ln = new ArrayList<>();
        for (int to : graph[now]) {
            if (to == par) {
                continue;
            }
            ln.add(dfs(to, now));
        }
        Collections.sort(ln);
        if (ln.size() == 0) {
            return 1;
        } else if (ln.size() == 1) {
            if (now == root) {
                return ln.get(0);
            }
            return ln.get(0) + 1;
        } else if (ln.get(ln.size()-1) > limit) {
            return limit+100;
        }

        if (ln.size() % 2 == 0) {
            if (canMakePair(ln, -1, limit)) {
                return 1;
            } else {
                ln.remove(ln.size()-1);
            }
        }

        if (!canMakePair(ln, ln.size()-1, limit)) {
            return limit+100;
        }

        int ok = ln.size()-1;
        int ng = -1;
        while (ok - ng > 1) {
            int med = (ok + ng) / 2;
            if (canMakePair(ln, med, limit)) {
                ok = med;
            } else {
                ng = med;
            }
        }
        return ln.get(ok)+1;
    }

    static boolean canMakePair(List<Integer> list, int ignoreIndex, int limit) {
        int n = list.size();
        int l = 0;
        int r = n-1;
        while (l <= r) {
            if (l == ignoreIndex) {
                l++;
                continue;
            }
            if (r == ignoreIndex) {
                r--;
                continue;
            }
            int ls = list.get(l);
            int rs = list.get(r);
            if (l == r) {
                if (ls > limit) {
                    return false;
                }
            } else if (ls + rs > limit) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    static int n;
    static int[][] graph;
    static int limit;
    static int root;

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