import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Set;

public class Main {
    InputStream is;

    int __t__ = 1;
    int __f__ = 0;
    int __FILE_DEBUG_FLAG__ = __f__;
    String __DEBUG_FILE_NAME__ = "src/E1";

    FastScanner in;
    PrintWriter out;

    class Pair {
        final int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        Pair add(final Pair p) {
            return new Pair(x + p.x, y + p.y);
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
    }

    public void solve() {
        int N = in.nextInt(), M = in.nextInt();
        int[] A = new int[M];
        int[] B = new int[M];
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < M; i++) {
            A[i] = in.nextInt() - 1;
            B[i] = in.nextInt() - 1;
            set.add(toKey(A[i], B[i]));
            set.add(toKey(B[i], A[i]));
        }

        List<Integer>[] g = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j || set.contains(toKey(i, j))) continue;
                g[i].add(j);
            }
        }

        int[] colors = new int[N];
        Arrays.fill(colors, -1);
        for (int u = 0; u < N; u++) {
            if (colors[u] != -1) continue;
            if (existsOddLoop(u, 0, colors, g)) {
                System.out.println("-1");
                return;
            }
        }

        boolean[] vis = new boolean[N];
        List<Pair> ps = new ArrayList<>();
        for (int u = 0; u < N; u++) {
            if (vis[u]) continue;
            ps.add(dfs(u, 0, vis, g));
        }

        boolean[] prev = new boolean[N+1];
        boolean[] next = new boolean[N+1];
        prev[0] = true;
        for (final Pair p : ps) {
            Arrays.fill(next, false);
            for (int u = N; u >= 0; u--) {
                if (u - p.x >= 0) {
                    next[u] |= prev[u-p.x];
                }
                if (u - p.y >= 0) {
                    next[u] |= prev[u-p.y];
                }
            }
            boolean[] tmp = prev; prev = next; next = tmp;
        }

        long res = 0;
        for (int i = 1; i < N; i++) {
            if (prev[i]) {
                res = Math.max(res, i * (N - i));
            }
        }
        System.out.println((N * (N - 1)) / 2 - res);
    }

    private Pair dfs(int u, int currentColor, boolean[] vis, List<Integer>[] g) {
        vis[u] = true;
        Pair res = currentColor == 0 ? new Pair(1, 0) : new Pair(0, 1);
        int nextColor = currentColor ^ 1;
        for (int v : g[u]) {
            if (vis[v]) continue;
            res = res.add(dfs(v, nextColor, vis, g));
        }
        return res;
    }

    private boolean existsOddLoop(int u, int currentColor, int[] colors, List<Integer>[] g) {
        colors[u] = currentColor;
        int nextColor = currentColor ^ 1;
        for (int v : g[u]) {
            if (colors[v] == -1) {
                if (existsOddLoop(v, nextColor, colors, g)) {
                    return true;
                }
            } else if (colors[v] == currentColor) {
                return true;
            }
        }
        return false;
    }

    private Integer toKey(int u, int v) {
        return u * 1000 + v;
    }

    private long sum(long x) {
        long res = 0;
        while (x > 0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }



    public void run() {
        if (__FILE_DEBUG_FLAG__ == __t__) {
            try {
                is = new FileInputStream(__DEBUG_FILE_NAME__);
            } catch (FileNotFoundException e) {
                // TODO ??????? catch ????
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

    public static void main(final String[] args) {
        new Main().run();
    }

    class FastScanner {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public FastScanner(InputStream stream) {
            this.stream = stream;
            // stream = new FileInputStream(new File("dec.in"));

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