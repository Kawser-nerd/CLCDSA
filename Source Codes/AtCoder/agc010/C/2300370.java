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
        a = new long[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextLong();
        }
        graph = buildGraph(in, n, n-1);

        out.println(isOK(n) ? "YES" : "NO");
        out.flush();
    }

    static boolean isOK(int n) {
        isOK = true;
        if (n == 2) {
            return a[0] == a[1];
        }
        for (int i = 0; i < n ; i++) {
            if (graph[i].length >= 2) {
                boolean root = dfs(i, -1) == 0;
                isOK &= root;
                break;
            }
        }
        return isOK;
    }

    static long[] a;
    static int[][] graph;
    static boolean isOK;

    static long dfs(int now, int par) {
        boolean has = false;
        long upsum = 0;
        long max = 0;
        for (int to : graph[now]) {
            if (to == par) {
                continue;
            }
            has = true;
            long l = dfs(to, now);
            max = Math.max(max, l);
            upsum += l;
        }
        if (!has) {
            return a[now];
        }

        isOK &= a[now] <= upsum;
        long pair = upsum - a[now];
        long maxpair = max * 2 <= upsum ? upsum / 2 : (upsum - max);
        isOK &= pair >= 0;
        isOK &= pair <= maxpair;

        long up = a[now] * 2 - upsum;
        isOK &= up >= 0;

        return up;
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