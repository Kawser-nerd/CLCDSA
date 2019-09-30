import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.Reader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyInput in = new MyInput(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int n;
        int m;
        Edge[] es;
        final int mod = (int) 1e9 + 7;

        public void solve(int testNumber, MyInput in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            long x = in.nextLong();
            es = new Edge[m];

            for (int i = 0; i < es.length; i++) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                int w = in.nextInt();
                es[i] = new Edge(i, u, v, w);
            }

            int low = 0, sat = 0, over = 0;
            for (int i = 0; i < m; i++) {
                long v = mst(i);
                if (v < x) low++;
                else if (v == x) sat++;
                else over++;
            }
            if (over == m) {
                out.println(0);
                return;
            }

            long ans = pow(2, sat) - 1 - (low == 0 ? 1 : 0);
            if (low != 0) {
                ans = ans * 2 % mod;
            }
            ans = ans * pow(2, over) % mod;
            out.println((ans + mod) % mod);
        }

        long mst(int use) {
            UnionFind uf = new UnionFind(n);
            long cost = 0;
            Arrays.sort(es, (a, b) -> {
                if (a.idx == use) return -1;
                if (b.idx == use) return 1;
                return a.compareTo(b);
            });
            for (Edge e : es) {
                if (!uf.same(e.u, e.v)) {
                    uf.union(e.u, e.v);
                    cost += e.w;
                }
            }
            return cost;
        }

        long pow(int x, int y) {
            long res = 1;
            for (int i = 0; i < y; i++) res = res * x % mod;
            return res;
        }

        class Edge implements Comparable<Edge> {
            final int u;
            final int v;
            final int idx;
            final long w;

            Edge(int idx, int u, int v, long w) {
                this.idx = idx;
                this.u = u;
                this.v = v;
                this.w = w;
            }


            public int compareTo(Edge o) {
                return Long.compare(w, o.w);
            }

        }

        class UnionFind {
            private int[] data;

            public UnionFind(int size) {
                data = new int[size];
                clear();
            }

            public void clear() {
                Arrays.fill(data, -1);
            }

            public int root(int x) {
                return data[x] < 0 ? x : (data[x] = root(data[x]));
            }

            public void union(int x, int y) {
                if ((x = root(x)) != (y = root(y))) {
                    if (data[y] < data[x]) {
                        final int t = x;
                        x = y;
                        y = t;
                    }
                    data[x] += data[y];
                    data[y] = x;
                }
            }

            public boolean same(int x, int y) {
                return root(x) == root(y);
            }

        }

    }

    static class MyInput {
        private final BufferedReader in;
        private static int pos;
        private static int readLen;
        private static final char[] buffer = new char[1024 * 8];
        private static char[] str = new char[500 * 8 * 2];
        private static boolean[] isDigit = new boolean[256];
        private static boolean[] isSpace = new boolean[256];
        private static boolean[] isLineSep = new boolean[256];

        static {
            for (int i = 0; i < 10; i++) {
                isDigit['0' + i] = true;
            }
            isDigit['-'] = true;
            isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
            isLineSep['\r'] = isLineSep['\n'] = true;
        }

        public MyInput(InputStream is) {
            in = new BufferedReader(new InputStreamReader(is));
        }

        public int read() {
            if (pos >= readLen) {
                pos = 0;
                try {
                    readLen = in.read(buffer);
                } catch (IOException e) {
                    throw new RuntimeException();
                }
                if (readLen <= 0) {
                    throw new MyInput.EndOfFileRuntimeException();
                }
            }
            return buffer[pos++];
        }

        public int nextInt() {
            int len = 0;
            str[len++] = nextChar();
            len = reads(len, isSpace);
            int i = 0;
            int ret = 0;
            if (str[0] == '-') {
                i = 1;
            }
            for (; i < len; i++) ret = ret * 10 + str[i] - '0';
            if (str[0] == '-') {
                ret = -ret;
            }
            return ret;
        }

        public long nextLong() {
            int len = 0;
            str[len++] = nextChar();
            len = reads(len, isSpace);
            int i = 0;
            long ret = 0;
            if (str[0] == '-') {
                i = 1;
            }
            for (; i < len; i++) ret = ret * 10 + str[i] - '0';
            if (str[0] == '-') {
                ret = -ret;
            }
            return ret;
        }

        public char nextChar() {
            while (true) {
                final int c = read();
                if (!isSpace[c]) {
                    return (char) c;
                }
            }
        }

        int reads(int len, boolean[] accept) {
            try {
                while (true) {
                    final int c = read();
                    if (accept[c]) {
                        break;
                    }
                    if (str.length == len) {
                        char[] rep = new char[str.length * 3 / 2];
                        System.arraycopy(str, 0, rep, 0, str.length);
                        str = rep;
                    }
                    str[len++] = (char) c;
                }
            } catch (MyInput.EndOfFileRuntimeException e) {
            }
            return len;
        }

        static class EndOfFileRuntimeException extends RuntimeException {
        }

    }
}