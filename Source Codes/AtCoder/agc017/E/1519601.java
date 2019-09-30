// package atcoder.agc.agc017;

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
        int h = in.nextInt();
        int[][] abcd = in.nextIntTable(n, 4);

        if (solve(h, abcd)) {
            out.println("YES");
        } else {
            out.println("NO");
        }
        out.flush();
    }

    static boolean solve(int h, int[][] abcd) {
        int n = abcd.length;

        int[][] graph = new int[410][410];
        int[] gin = new int[410];
        int[] gout = new int[410];
        for (int i = 0 ; i < n ; i++) {
            int l = abcd[i][2] == 0 ? h - abcd[i][0] : h + abcd[i][2];
            int r = abcd[i][3] == 0 ? h + abcd[i][1] : h - abcd[i][3];
            graph[l][r]++;
            gin[l]++;
            gout[r]++;
        }

        for (int i = 0 ; i < h ; i++) {
            if (gin[i] < gout[i]) {
                return false;
            }
            if (gin[i] > gout[i]) {
                graph[409][i] = 1;
            }
        }
        for (int i = h+1 ; i < 2*h+1 ; i++) {
            if (gin[i] > gout[i]) {
                return false;
            }
            if (gin[i] < gout[i]) {
                graph[i][409] = 1;
            }
        }

        boolean[] v = new boolean[graph.length];
        dfs(409, graph, v);

        for (int i = 0; i < graph.length ; i++) {
            if (!v[i] && gin[i] + gout[i] >= 1) {
                return false;
            }
        }

        return true;
    }

    static void dfs(int now, int[][] graph, boolean[] v) {
        if (v[now]) {
            return;
        }
        v[now] = true;
        for (int i = 0; i < graph.length ; i++) {
            if (graph[now][i] >= 1) {
                dfs(i, graph, v);
            }
        }
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