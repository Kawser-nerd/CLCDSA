// package arc.arc088;

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

        gto = new int[n][];
        tmpto = new int[n][];
        dfs0(0, -1);

        int A = dfsA(0, -1, 0);

        int min = 0;   // NG
        int max = n+1; // OK
        while (max - min > 1) {
            int med = (max + min) / 2;
            if (isOK(med)) {
                max = med;
            } else {
                min = med;
            }
        }
        out.println(String.format("%d %d", A, max));
        out.flush();
    }

    static int[][] graph;
    static int[][] gto;
    static int maxB;

    static void dfs0(int now, int par) {
        int ci = 0;
        gto[now] = new int[graph[now].length - (par == -1 ? 0 : 1)];
        for (int to : graph[now]) {
            if (to == par) {
                continue;
            }
            gto[now][ci++] = to;
            dfs0(to, now);
        }
        tmpto[now] = new int[gto[now].length];
    }

    static int[][] tmpto;
    static boolean ng;

    static boolean isOK(int length) {
        ng = false;
        maxB = length;
        int a = dfsB(0);
        return !ng && a <= maxB;
    }

    static int dfsB(int now) {
        int cn = gto[now].length;
        if (cn == 0) {
            return 1;
        }

        int ci = 0;
        int[] tmp = tmpto[now];
        for (int to : gto[now]) {
            tmp[ci++] = dfsB(to);
        }
        Arrays.sort(tmp);

        if (cn % 2 == 0) {
            boolean ok = true;
            for (int i = 0 ; i < cn / 2 ; i++) {
                ok &= tmp[i] + tmp[cn-1-i] <= maxB;
            }
            if (ok) {
                return 1;
            }
            if (now == 0) {
                ng = true;
                return maxB+10;
            }
            cn--;
        }

        int d = now == 0 ? 0 : 1;
        if (tmp[cn-1]+d > maxB) {
            ng = true;
            return maxB+10;
        }

        int ok = cn;
        int ng = -1;
        int[] tmp2 = new int[cn-1];
        while (ok - ng > 1) {
            int med = (ok + ng) / 2;
            int ti = 0;
            for (int i = 0; i < cn ; i++) {
                if (i == med) {
                    continue;
                }
                tmp2[ti++] = tmp[i];
            }
            boolean isng = false;
            for (int i = 0 ; i < ti / 2 ; i++) {
                if (tmp2[i] + tmp2[ti-1-i] > maxB) {
                    isng = true;
                    break;
                }
            }
            if (isng) {
                ng = med;
            } else {
                ok = med;
            }
        }
        if (ok == cn) {
            return maxB+10;
        }
        return tmp[ok] + (now == 0 ? 0 : 1);
    }

    static int dfsA(int now, int par, int flg) {
        int cn = 0;
        for (int to : graph[now]) {
            if (to == par) {
                continue;
            }
            cn++;
        }
        int A = (cn+(flg^1))/2;
        for (int to : graph[now]) {
            if (to == par) {
                continue;
            }
            A += dfsA(to, now, 1);
        }
        return A;
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