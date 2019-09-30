// package atcoder.agc.agc014;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();

        graph = new Set[2][n];
        for (int i = 0; i < 2 ; i++) {
            for (int j = 0; j < n ; j++) {
                graph[i][j] = new HashSet<>();
            }
        }
        que = new int[2000000];

        int[][] blueEdges = in.nextIntTable(n-1, 2);
        int[][] redEdges = in.nextIntTable(n-1, 2);
        for (int i = 0; i < n-1 ; i++) {
            addEge(0, blueEdges[i][0]-1, blueEdges[i][1]-1);
            addEge(1, redEdges[i][0]-1, redEdges[i][1]-1);
        }

        int groupCnt = n;
        while (qt < qh) {
            int l = que[qt++];
            int r = que[qt++];
            if (mergeVertex(l, r)) {
                groupCnt--;
            }
        }

        out.println(groupCnt == 1 ? "YES" : "NO");
        out.flush();
    }

    static void addEge(int color, int l, int r) {
        if (l == r || graph[color][l].contains(r) || graph[color][r].contains(l)) {
            return;
        }
        graph[color][l].add(r);
        graph[color][r].add(l);
        if (graph[1-color][l].contains(r)) {
            que[qh++] = l;
            que[qh++] = r;
        }
    }

    static boolean mergeVertex(int l, int r) {
        if (l == r) {
            return false;
        }
        int el = countEdge(l);
        int er = countEdge(r);
        if (el == 0 || er == 0) {
            return false;
        }
        if (el > er) {
            return mergeVertex(r, l);
        }

        // merge l into r
        for (int k = 0 ; k <= 1 ; k++) {
            for (int to : graph[k][l]) {
                graph[k][to].remove(l);
                addEge(k, to, r);
            }
            graph[k][l].clear();
        }
        return true;
    }

    static int countEdge(int v) {
        return graph[0][v].size() + graph[1][v].size();
    }

    static int qh, qt;
    static int[] que;

    static Set<Integer>[][] graph;

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
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
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
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.