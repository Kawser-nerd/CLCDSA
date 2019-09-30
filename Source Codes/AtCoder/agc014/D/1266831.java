// package atcoder.agc.agc014;

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
        tree = buildGraph(in, n, n-1);
        canWin = false;

        boolean[] ptr = new boolean[n];
        for (int i = 0 ; i < n ; i++) {
            if (tree[i].length >= 2) {
                int cn = 0;
                for (int to : tree[i]) {
                    if (tree[to].length == 1) {
                        cn++;
                    }
                }
                if (cn >= 2) {
                    canWin = true;
                } else if (cn == 1) {
                    ptr[i] = true;
                }
            }
        }

//        for (int i = 0 ; i < n ; i++) {
//            if (tree[i].length >= 2) {
//                boolean canDominate = true;
//                for (int to : tree[i]) {
//                    if (!ptr[to]) {
//                        canDominate = false;
//                    }
//                }
//                if (canDominate) {
//                    canWin = true;
//                }
//            }
//        }

        isBlack = new boolean[n];
        isWhiteDominate = new boolean[n];

        dfs(0, -1);

        boolean all = true;
        for (int to : tree[0]) {
            if (!isWhiteDominate[to]) {
                all = false;
            }
        }
        canWin |= all;


//        debug(isBlack);
//        debug(isWhiteDominate);


//        int one = tree[0][0];
//        isBlack = new boolean[n];
//        isWhiteDominate = new boolean[n];
//
//        dfs(one, -1);
//
//        all = true;
//        for (int to : tree[one]) {
//            if (!isWhiteDominate[to]) {
//                all = false;
//            }
//        }
//        canWin |= all;

        out.println(canWin ? "First" : "Second");
        out.flush();
    }


    static boolean canWin;
    static int[][] tree;
    static boolean[] isBlack;
    static boolean[] isWhiteDominate;

    static void dfs(int now, int par) {
        int cn = tree[now].length;
        if (par != -1) {
            cn--;
        }
        if (cn == 0) {
            isBlack[now] = true;
            return;
        }

        int bn = 0;
        int wn = 0;
        boolean childCanBlack = false;
        for (int to : tree[now]) {
            if (to == par) {
                continue;
            }
            dfs(to, now);

            if (isBlack[to]) {
                childCanBlack = true;
                bn++;
            } else if (isWhiteDominate[to]) {
                wn++;
            }
        }
        if (bn >= 2) {
            canWin = true;
        }
        if (childCanBlack) {
            isWhiteDominate[now] = true;
        } else if (cn == wn) {
            isBlack[now] = true;
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