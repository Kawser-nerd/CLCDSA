import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Main {
    private static InputStream is;
    private static PrintWriter out;
    private static String INPUT = "";

    class MaxFlow {
        class Edge {
            public final int to, rev;
            public long cap;

            public Edge(int to, int rev, long cap) {
                this.to = to;
                this.rev = rev;
                this.cap = cap;
            }
        }

        int v;
        List<Edge> G[];
        boolean used[];

        public MaxFlow(int v) {
            this.v = v;
            G = new List[v];
            for (int i = 0; i < v; ++i) {
                G[i] = new ArrayList<>();
            }
            used = new boolean[v];
        }

        public void add_edge(int from, int to, long cap) {
            G[from].add(new Edge(to, G[to].size(), cap));
            G[to].add(new Edge(from, G[from].size() - 1, 0));
        }

        long dfs(int v, int t, long f) {
            if (v == t) return f;
            used[v] = true;
            for (Edge e : G[v]) {
                if (!used[e.to] && e.cap > 0) {
                    long d = dfs(e.to, t, Math.min(f, e.cap));
                    if (d > 0) {
                        e.cap -= d;
                        G[e.to].get(e.rev).cap += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        public long max_flow(int s, int t) {
            long flow = 0;
            while (true) {
                Arrays.fill(used, false);
                long f = dfs(s, t, Long.MAX_VALUE);
                if (f == 0) return flow;
                flow += f;
            }
        }
    }

    void solve() {
        int n = ni(), a[] = na(n), s = n, t = n + 1;
        MaxFlow flow = new MaxFlow(n + 2);
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) {
                flow.add_edge(i, t, a[i]);
            } else {
                flow.add_edge(s, i, -a[i]);
            }
            for (int j = (i + 1) * 2; j <= n; j += i + 1) {
                flow.add_edge(i, j - 1, Long.MAX_VALUE / 2);
            }
        }
        long x = 0;
        for (int i : a) if (i > 0) x += i;
        out.println(x - flow.max_flow(s, t));
    }

    public static void main(String[] args) throws Exception {
        long S = System.currentTimeMillis();
        is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        out = new PrintWriter(System.out);

        new Main().solve();
        out.flush();
        long G = System.currentTimeMillis();
        tr(G - S + " ms");
    }

    private static boolean eof() {
        if (lenbuf == -1) return true;
        int lptr = ptrbuf;
        while (lptr < lenbuf)
            if (!isSpaceChar(inbuf[lptr++])) return false;

        try {
            is.mark(1000);
            while (true) {
                int b = is.read();
                if (b == -1) {
                    is.reset();
                    return true;
                } else if (!isSpaceChar(b)) {
                    is.reset();
                    return false;
                }
            }
        } catch (IOException e) {
            return true;
        }
    }

    private static byte[] inbuf = new byte[1024];
    static int lenbuf = 0, ptrbuf = 0;

    private static int readByte() {
        if (lenbuf == -1) throw new InputMismatchException();
        if (ptrbuf >= lenbuf) {
            ptrbuf = 0;
            try {
                lenbuf = is.read(inbuf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (lenbuf <= 0) return -1;
        }
        return inbuf[ptrbuf++];
    }

    private static boolean isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }

    private static int skip() {
        int b;
        while ((b = readByte()) != -1 && isSpaceChar(b))
            ;
        return b;
    }

    private static double nd() {
        return Double.parseDouble(ns());
    }

    private static char nc() {
        return (char) skip();
    }

    private static String ns() {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private static char[] ns(int n) {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while (p < n && !(isSpaceChar(b))) {
            buf[p++] = (char) b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }

    private static char[][] nm(int n, int m) {
        char[][] map = new char[n][];
        for (int i = 0; i < n; i++)
            map[i] = ns(m);
        return map;
    }

    private static int[] na(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = ni();
        return a;
    }

    private static long[] nal(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = ni();
        return a;
    }

    private static int ni() {
        int num = 0, b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
            ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }

        while (true) {
            if (b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    private static long nl() {
        long num = 0;
        int b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
            ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }

        while (true) {
            if (b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    private static void tr(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.