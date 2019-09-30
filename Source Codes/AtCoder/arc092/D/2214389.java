import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Deque;
import java.util.InputMismatchException;
import java.util.Collections;
import java.io.PrintWriter;

public class Main {
    static class E {
        int to, id;
        boolean res;
        E(int to, int id, boolean res) {
            this.to = to;
            this.id = id;
            this.res = res;
        }
    }

    static boolean[] vis;
    static void mark(ArrayList<E>[] g, int p, int r) {
        vis[p] = true;
        for (E e: g[p]) {
            int d = e.to;
            if (d == r || vis[d]) continue;
            mark(g, d, r);
        }
    }
    static void solve(ArrayList<E>[] g) {
        int n = g.length;
        for (int i = 0; i < n; i++) {
            vis = new boolean[n];
            for (E e: g[i]) {
                int d = e.to;
                if (vis[d]) e.res = true;
                mark(g, d, i);
            }
        }
    }
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
    	PrintWriter out = new PrintWriter(System.out);

    	int n = in.nextInt();
        int m = in.nextInt();

        boolean[][] scc = new boolean[n][n];

        ArrayList<E>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<E>();
        }
        for (int i = 0; i < m; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            a--; b--;
            scc[a][b] = true;
            g[a].add(new E(b, i, false));
        }

        for (int i = 0; i < n; i++) {
            scc[i][i] = true;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    scc[i][j] |= scc[i][k] && scc[k][j];
                }
            }
        }

        solve(g);
        for (int i = 0; i < n; i++) {
            Collections.reverse(g[i]);
        }
        solve(g);

        boolean[] res = new boolean[m];
        for (int i = 0; i < n; i++) {
            for (E e: g[i]) {
                res[e.id] = e.res ^ scc[e.to][i];
            }
        }

        for (int i = 0; i < m; i++) {
            if (res[i]) {
                out.println("diff");
            } else {
                out.println("same");
            }
        }
        out.flush();
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

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.