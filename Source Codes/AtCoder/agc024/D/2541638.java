import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    InputStream is;

    int __t__ = 1;
    int __f__ = 0;
    int __FILE_DEBUG_FLAG__ = __f__;
    String __DEBUG_FILE_NAME__ = "src/D4";

    FastScanner in;
    PrintWriter out;

    public void solve() {
        int N = in.nextInt();
        int[] a = new int[N - 1];
        int[] b = new int[N - 1];
        for (int i = 0; i < N - 1; i++) {
            a[i] = in.nextInt() - 1;
            b[i] = in.nextInt() - 1;
        }
        ArrayList<Integer>[] g = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            g[a[i]].add(b[i]);
            g[b[i]].add(a[i]);
        }
        int[] depth = new int[N];
        dfs(0, -1, 0, depth, g);
        int l1 = 0;
        for (int u = 0; u < N; u++) {
            if (depth[u] > depth[l1]) l1 = u;
        }
        dfs(l1, -1, 0, depth, g);
        int l2 = 0;
        for (int u = 0; u < N; u++) {
            if (depth[u] > depth[l2]) l2 = u;
        }

        int[] depthL1 = new int[N];
        int[] depthL2 = new int[N];
        dfs(l1, -1, 0, depthL1, g);
        dfs(l2, -1, 0, depthL2, g);

        int diam = depthL1[l2];
        if (diam % 2 != 0) {
            int c1 = -1, c2 = -1;
            for (int u = 0; u < N; u++) {
                if ((diam / 2 == depthL1[u] && (diam + 1) / 2 == depthL2[u]) ||
                        (diam / 2 == depthL2[u] && (diam + 1) / 2 == depthL1[u])) {
                    if (c1 == -1)
                        c1 = u;
                    else if (c2 == -1)
                        c2 = u;
                    else
                        throw new RuntimeException();
                }
            }
            if (c1 == -1 || c2 == -1) {
                throw new RuntimeException();
            }
            System.out.println(((diam + 1) / 2) + " " + calc(c1, c2, g));
        } else {
            int c1 = -1;
            for (int u = 0; u < N; u++) {
                if (depthL1[u] == depthL2[u] && diam / 2 == depthL1[u]) {
                    if (c1 == -1)
                        c1 = u;
                    else
                        throw new RuntimeException();
                }
            }
            if (c1 == -1)
                throw new RuntimeException();

            long res = calc(c1, c1, g);
            for (int c2 : g[c1]) {
                res = Math.min(res, calc(c1, c2, g));
            }
            System.out.println((diam / 2 + 1) + " " + res);
        }
    }

    private long calc(int c1, int c2, ArrayList<Integer>[] g) {
        int N = g.length;
        int[] depthC1 = new int[N];
        int[] depthC2 = new int[N];
        dfs(c1, -1, 0, depthC1, g);
        dfs(c2, -1, 0, depthC2, g);
        int[] deg = new int[N];
        Arrays.fill(deg, 1);
        if (c1 == c2) {
            deg[0] = Math.max(1, g[c1].size());
        } else {
            deg[0] = Math.max(1, Math.max(g[c1].size(), g[c2].size()) - 1);
        }
        for (int u = 0; u < N; u++) {
            if (c1 == u || c2 == u) continue;
            int d = Math.min(depthC1[u], depthC2[u]);
            deg[d] = Math.max(deg[d], g[u].size());
        }
        long res = deg[0];
        for (int u = 1; u < N; u++) {
            res *= Math.max(deg[u] - 1, 1);
        }
        if (c1 != c2) res *= 2;
        return res;
    }

    void dfs(int u, int pre, int d, int[] depth, ArrayList<Integer>[] g) {
        depth[u] = d;
        for (int v : g[u]) {
            if (v == pre) continue;
            dfs(v, u, d + 1, depth, g);
        }
    }

    public void run() {
        if (__FILE_DEBUG_FLAG__ == __t__) {
            try {
                is = new FileInputStream(__DEBUG_FILE_NAME__);
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
            System.out.println("FILE_INPUT!");
        } else {
            is = System.in;
        }
        in = new FastScanner(is);
        out = new PrintWriter(System.out);

        solve();
    }

    public static void main(String[] args) {
        new Main().run();
    }

    public void mapDebug(int[][] a) {
        System.out.println("--------map display---------");

        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                System.out.printf("%3d ", a[i][j]);
            }
            System.out.println();
        }

        System.out.println("----------------------------");
        System.out.println();
    }

    public void debug(Object... obj) {
        System.out.println(Arrays.deepToString(obj));
    }

    class FastScanner {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public FastScanner(InputStream stream) {
            this.stream = stream;
            //stream = new FileInputStream(new File("dec.in"));

        }

        int read() {
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

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        boolean isEndline(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; i++)
                array[i] = nextInt();

            return array;
        }

        int[][] nextIntMap(int n, int m) {
            int[][] map = new int[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextIntArray(m);
            }
            return map;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        long[] nextLongArray(int n) {
            long[] array = new long[n];
            for (int i = 0; i < n; i++)
                array[i] = nextLong();

            return array;
        }

        long[][] nextLongMap(int n, int m) {
            long[][] map = new long[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextLongArray(m);
            }
            return map;
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        double[] nextDoubleArray(int n) {
            double[] array = new double[n];
            for (int i = 0; i < n; i++)
                array[i] = nextDouble();

            return array;
        }

        double[][] nextDoubleMap(int n, int m) {
            double[][] map = new double[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextDoubleArray(m);
            }
            return map;
        }

        String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        String[] nextStringArray(int n) {
            String[] array = new String[n];
            for (int i = 0; i < n; i++)
                array[i] = next();

            return array;
        }

        String nextLine() {
            int c = read();
            while (isEndline(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndline(c));
            return res.toString();
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.