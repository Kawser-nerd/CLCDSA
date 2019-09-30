// package arc.arc095;

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
        parent = new int[n];
        int[] pair = diameter();
        List<Integer> dline = new ArrayList<>();
        dfs2(pair[0], -1);

        {
            int ctr = pair[1];
            while (ctr != pair[0]) {
                dline.add(ctr);
                ctr = parent[ctr];
            }
            dline.add(pair[0]);
        }

        int[] r1 = solve(dline);
        Collections.reverse(dline);
        int[] r2 = solve(dline);

        if (r1 == null || r2 == null) {
            out.println(-1);
        } else {
            out.println(toLine(smaller(r1, r2)));
        }
        out.flush();
    }

    private static int[] solve(List<Integer> line) {
        int total = line.size();
        for (int i = 1 ; i < line.size()-1 ; i++) {
            int v = line.get(i);
            total += graph[v].length - 2;
        }
        if (total != graph.length) {
            return null;
        }

        int[] wo = new int[graph.length];
        int pidx = 0;
        int vidx = 0;
        for (int i = 0; i < line.size() ; i++) {
            if (i == 0 || i == line.size() - 1) {
                wo[pidx++] = vidx++;
            } else {
                int v = line.get(i);
                int r = graph[v].length - 2;
                for (int j = 0 ; j < r ; j++) {
                    wo[pidx++] = vidx+j+1;
                }
                wo[pidx++] = vidx;
                vidx += r+1;
            }
        }
        return wo;
    }

    static int[] parent;

    static void dfs2(int now, int par) {
        parent[now] = par;
        for (int to : graph[now]) {
            if (to == par) {
                continue;
            }
            dfs2(to, now);
        }
    }

    private static String toLine(int[] smaller) {
        StringBuilder l = new StringBuilder();
        for (int i = 0; i < smaller.length; i++) {
            l.append(' ').append(smaller[i]+1);
        }
        return l.substring(1);
    }

    private static int[] smaller(int[] r1, int[] r2) {
        for (int i = 0; i < r1.length; i++) {
            if (r1[i] < r2[i]) {
                return r1;
            } else if (r1[i] > r2[i]) {
                return r2;
            }
        }
        return r1;
    }

    static int[][] graph;

    static int[] diameter() {
        int[] u = dfs(0, -1);
        int[] v = dfs(u[1], -1);
        return new int[]{u[1], v[1]};
    }

    static int[] dfs(int now, int par) {
        int[] best = new int[]{-1, -1};
        for (int to : graph[now]) {
            if (to == par) {
                continue;
            }
            int[] r = dfs(to, now);
            if (best[0] <= r[0]) {
                best = r.clone();
            }
        }
        if (best[0] == -1) {
            best[0] = 0;
            best[1] = now;
        } else {
            best[0]++;
        }
        return best;
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