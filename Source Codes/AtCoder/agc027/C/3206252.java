import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Queue;

public class Main {
    InputStream is;

    int __t__ = 1;
    int __f__ = 0;
    int __FILE_DEBUG_FLAG__ = __f__;
    String __DEBUG_FILE_NAME__ = "src/C2";

    FastScanner in;
    PrintWriter out;

    public void solve() {
        int n = in.nextInt(), m = in.nextInt();
        String s = in.next();
        int[] a = new int[m];
        int[] b = new int[m];
        int selfLoop = 0;
        int[] self = new int[n];
        Arrays.fill(self, -1);
        StringBuilder sb = new StringBuilder(s);

        for (int i = 0; i < m; i++) {
            a[i] = in.nextInt() - 1;
            b[i] = in.nextInt() - 1;
            if (a[i] == b[i]) {
                self[a[i]] = n + selfLoop;
                selfLoop++;
                sb.append(s.charAt(a[i]));
            }
        }

        s = sb.toString();
        int all = n + selfLoop;
        Collection<Integer>[] g = new HashSet[all];
        for (int i = 0; i < all; i++) {
            g[i] = new HashSet<>();
        }
        for (int i = 0; i < m; i++) {
            if (self[a[i]] == -1) {
                if (self[b[i]] == -1) {
                    addBidirectionalEdge(g, a[i], b[i]);
                } else {
                    addBidirectionalEdge(g, a[i], b[i]);
                    addBidirectionalEdge(g, b[i], self[b[i]]);
                    addBidirectionalEdge(g, a[i], self[b[i]]);
                }
            } else {
                if (self[b[i]] == -1) {
                    addBidirectionalEdge(g, a[i], b[i]);
                    addBidirectionalEdge(g, self[a[i]], a[i]);
                    addBidirectionalEdge(g, self[a[i]], b[i]);
                } else {
                    addBidirectionalEdge(g, a[i], b[i]);
                    addBidirectionalEdge(g, a[i], self[b[i]]);
                    addBidirectionalEdge(g, b[i], self[b[i]]);
                    addBidirectionalEdge(g, self[a[i]], a[i]);
                    addBidirectionalEdge(g, self[a[i]], b[i]);
                    addBidirectionalEdge(g, self[a[i]], self[b[i]]);
                }
            }
        }
        boolean[] removed = new boolean[all];
        Queue<Integer> delQ = new ArrayDeque<>();
        for (int u = 0; u < all; u++) {
            if (shouldDelete(g, u, s, removed)) {
                removed[u] = true;
                delQ.add(u);
            }
        }

        while (!delQ.isEmpty()) {
            int next = delQ.poll();

            for (int v : g[next]) {
                if (!removed[v] && shouldDelete(g, v, s, removed)) {
                    removed[v] = true;
                    delQ.add(v);
                }
            }
        }
        boolean res = true;
        for (boolean r : removed) {
            res &= r;
        }
        System.out.println(res ? "No" : "Yes");
    }

    private boolean shouldDelete(Collection<Integer>[] g, int u, String s, boolean[] removed) {
        int acnt = 0, bcnt = 0;
        for (int v : g[u]) {
            if (removed[v]) continue;
            if (s.charAt(v) == 'A') {
                acnt++;
            } else if (s.charAt(v) == 'B') {
                bcnt++;
            } else {
                throw new RuntimeException();
            }
        }
        return acnt == 0 || bcnt == 0;
    }

    private void addBidirectionalEdge(Collection<Integer>[] g, int a, int b) {
        if (a != b) {
            g[a].add(b);
            g[b].add(a);
        }
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