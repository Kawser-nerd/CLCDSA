// package atcoder.agc.agc010;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long[] a = in.nextLongs(n);
        int[][] graph = buildGraph(in, n, n-1);

        out.println(solve(a, graph) ? "YES" : "NO");
        out.flush();
    }

    private static boolean solve(long[] ai, int[][] g) {
        a = ai;
        n = a.length;
        graph = g;
        if (n == 2) {
            return a[0] == a[1];
        }

        int root = -1;
        for (int i = 0; i < n ; i++) {
            if (g[i].length >= 2) {
                root = i;
                break;
            }
        }
        cnt = new long[n];
        up = new long[n];
        ok = true;
        dfs(root, -1);

        return ok && up[root] == 0;
    }

    static boolean ok = true;

    static long leafSum = 0;

    static int n;
    static long[] a;
    static int[][] graph;
    static long[] cnt;

    static long[] up;

    // static long[] lnln;

    static void dfs(int now, int par) {
        boolean leaf = true;
        long dup = 0;

        int ln = 0;
        List<Long> lvs = new ArrayList<>();
        for (int to : graph[now]) {
            if (to == par) {
                continue;
            }
            leaf = false;
            dfs(to, now);
            lvs.add(up[to]);
            dup += up[to];
            ln++;
        }

        if (leaf) {
            leafSum += a[now];
            up[now] = a[now];
        } else {
            long inner = dup - a[now];
            if (inner < 0) {
                ok = false;
            }
            up[now] = dup - inner * 2;
            if (up[now] < 0) {
                ok = false;
            }

            if (lvs.size() == 1) {
                ok &= inner == 0;
            } else if (lvs.size() >= 2) {
                Collections.sort(lvs);
                long[] lnln = new long[ln];
                for (int i = 0; i < ln ; i++) {
                    lnln[i] = lvs.get(i);
                }

                long totalDec = 0;
                long max = lnln[ln-1];
                long sum = 0;
                long left = 0;
                for (int i = 0; i < ln-1 ; i++) {
                    sum += lnln[i];
                    left += lnln[i];
                }
                sum += lnln[ln-1];

                if (left <= max) {
                    totalDec = left;
                } else {
                    totalDec = sum / 2;
                }
                ok &= totalDec >= inner;
            }

        }
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

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int[] nextInts(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        private int[][] nextIntTable(int n, int m) {
            int[][] ret = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i][j] = nextInt();
                }
            }
            return ret;
        }

        private long[] nextLongs(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }

        private long[][] nextLongTable(int n, int m) {
            long[][] ret = new long[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i][j] = nextLong();
                }
            }
            return ret;
        }

        private double[] nextDoubles(int n) {
            double[] ret = new double[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextDouble();
            }
            return ret;
        }

        private int next() {
            if (numChars == -1)
                throw new InputMismatchException();
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
            int c = next();
            while (isSpaceChar(c))
                c = next();
            if ('a' <= c && c <= 'z') {
                return (char) c;
            }
            if ('A' <= c && c <= 'Z') {
                return (char) c;
            }
            throw new InputMismatchException();
        }

        public String nextToken() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }

        public long nextLong() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}