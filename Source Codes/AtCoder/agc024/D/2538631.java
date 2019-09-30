// package agc.agc024;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.util.concurrent.ArrayBlockingQueue;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);


        int n = in.nextInt();
        graph = buildGraph(in, n, n-1);

        List<long[]> rs = new ArrayList<>();
        for (int i = 0; i < n ; i++) {
            rs.add(solveFrom(i, -1));
            for (int t : graph[i]) {
                if (i < t) {
                    rs.add(solveFrom(i, t));
                }
            }
        }
        long[] best = new long[]{n+10, n+10};
        for (long[] r : rs) {
            if (r[0] < best[0] || (r[0] == best[0] && r[1] < best[1])) {
                best = r.clone();
            }
        }
        out.println(String.format("%d %d", best[0], best[1]));
        out.flush();
    }

    private static long[] solveFrom(int L, int R) {
        int n = graph.length;
        Queue<int[]> q = new ArrayBlockingQueue<>(n);
        Queue<int[]> nq = new ArrayBlockingQueue<>(n);
        if (R == -1) {
            q.add(new int[]{L, R, 0});
        } else {
            q.add(new int[]{L, R, 0});
            q.add(new int[]{R, L, 0});
        }


        long mul = 1;
        int level = 0;
        while (true) {
            level++;

            nq.clear();
            int maxDeg = 0;
            while (q.size() >= 1) {
                int[] f = q.poll();
                int de = 0;
                for (int t : graph[f[0]]) {
                    if (t != f[1]) {
                        de++;
                        nq.add(new int[]{t, f[0]});
                    }
                }
                maxDeg = Math.max(maxDeg, de);
            }
            if (maxDeg == 0) {
                break;
            }
            mul *= maxDeg;
            q.addAll(nq);
        }
        if (R != -1) {
            mul *= 2;
        }
        return new long[]{level, mul};
    }

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