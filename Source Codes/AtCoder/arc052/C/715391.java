// package atcoder.arc.arc052;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by hama_du on 5/2/16.
 */
public class Main {

    static final int MAXB = 150;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        int[][][] graph = buildWeightedGraph(in, n, m);


        Dijkstra dijk = new Dijkstra(graph);
        int[][] ptnA = dijk.prec(0);
        long[] min = new long[n];
        for (int i = 0; i < n ; i++) {
            min[i] = compute(ptnA[i][0], ptnA[i][1]);
        }

        int[][] ptnB = dijk.doreal(0);
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < ptnB[i].length ; j++) {
                if (ptnB[i][j] == Dijkstra.INF) {
                    continue;
                }
                min[i] = Math.min(min[i], compute(ptnB[i][j], j));
            }
        }

        for (int i = 0; i < n ; i++) {
            out.println(min[i]);
        }
        out.flush();
    }

    static long compute(long usedA, long usedB) {
        return usedA + (usedB + 1) * usedB / 2;
    }

    //

    static class Dijkstra {
        private static final int INF = 114514;
        int n;
        int[][][] graph;

        class State  {
            int now;
            int usedA;
            int usedB;

            State(int n, int a, int b) {
                now = n;
                usedA = a;
                usedB = b;
            }
        }

        public Dijkstra(int[][][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        int[][] prec(int from) {
            int[][] dp = new int[n][2];
            for (int i = 0; i < n ; i++) {
                dp[i][0] = INF;
                dp[i][1] = INF;
            }
            Queue<State> q = new PriorityQueue<>((o1, o2) -> {
                if (o1.usedB != o2.usedB) {
                    return o1.usedB - o2.usedB;
                }
                return o1.usedA - o2.usedA;
            });
            q.add(new State(from, 0, 0));
            dp[from][0] = 0;
            while (q.size() >= 1) {
                State st = q.poll();
                for (int[] e : graph[st.now]) {
                    int ta = e[1] == 0 ? st.usedA + 1 : st.usedA;
                    int tb = e[1] == 1 ? st.usedB + 1 : st.usedB;
                    if (dp[e[0]][1] > tb || (dp[e[0]][1] == tb && dp[e[0]][0] > ta)) {
                        dp[e[0]][0] = ta;
                        dp[e[0]][1] = tb;
                        q.add(new State(e[0], ta, tb));
                    }
                }
            }
            return dp;
        }

        int[][] doreal(int from) {
            int[][] dp = new int[n][MAXB];
            for (int i = 0; i < n ; i++) {
                Arrays.fill(dp[i], INF);
            }
            Queue<State> q = new PriorityQueue<>((o1, o2) -> o1.usedA - o2.usedA);
            q.add(new State(from, 0, 0));
            dp[from][0] = 0;
            while (q.size() >= 1) {
                State st = q.poll();
                if (dp[st.now][st.usedB] < st.usedA) {
                    continue;
                }
                for (int[] e : graph[st.now]) {
                    int ta = e[1] == 0 ? st.usedA + 1 : st.usedA;
                    int tb = e[1] == 1 ? st.usedB + 1 : st.usedB;
                    if (tb >= MAXB) {
                        continue;
                    }
                    if (dp[e[0]][tb] > ta) {
                        dp[e[0]][tb] = ta;
                        q.add(new State(e[0], ta, tb));
                    }
                }
            }
            return dp;
        }
    }

    static int[][][] buildWeightedGraph(InputReader in, int n, int m) {
        int[][] edges = new int[m][];
        int[][][] graph = new int[n][][];
        int[] deg = new int[n];
        for (int i = 0 ; i < m ; i++) {
            int w = in.nextInt();
            int a = in.nextInt();
            int b = in.nextInt();
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

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
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