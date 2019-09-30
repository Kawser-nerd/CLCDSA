import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.Reader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author tanzaku
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyInput in = new MyInput(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, MyInput in, PrintWriter out) {
            int n = in.nextInt();
            List<Integer> ones = new ArrayList<>();
            int[] xs = in.nextIntArray(n);
            for (int i = 0; i < n; i++) {
                if (i == 0 || xs[i] - xs[i - 1] != 1) ones.add(xs[i]);
                if (i == n - 1 || xs[i + 1] - xs[i] != 1) ones.add(xs[i] + 1);
            }

            boolean[] isPrime = eratosthenes(10000000);
            int m = ones.size();
            int S = m * 2, T = S + 1;
//        PushRelabelBaseMaxFlow flow = new PushRelabelBaseMaxFlow(T + 1);
            Dinic flow = new Dinic(T + 1);
            int[] cnt = new int[2];
            for (int i = 0; i < ones.size(); i++) {
                cnt[ones.get(i) % 2]++;
                flow.addEdge(S, i, 1);
                flow.addEdge(i + m, T, 1);
                for (int j = 0; j < i; j++) {
                    final int a = ones.get(i);
                    final int b = ones.get(j);
                    if (a == b) break;
                    if (a - b != 2 && isPrime[a - b]) {
                        flow.addEdge(i, j + m, 1);
                        flow.addEdge(j, i + m, 1);
                    }
                }
            }
//        int f1 = (int)(flow.relabelToFront(S, T) / 2);
            int f1 = (int) (flow.MaxFlow(S, T) / 2);
            cnt[0] -= f1;
            cnt[1] -= f1;
            int f2 = cnt[0] / 2 + cnt[1] / 2;
            int f3 = cnt[0] % 2 != 0 ? 1 : 0;
            out.println(f1 * 1 + f2 * 2 + f3 * 3);
        }

        private static boolean[] eratosthenes(int n) {
            final boolean[] p = new boolean[n + 1];
            Arrays.fill(p, true);
            p[0] = p[1] = false;
            for (int i = 2; i * i <= n; i++) {
                if (p[i]) {
                    for (int j = i * i; j <= n; j += i) {
                        p[j] = false;
                    }
                }
            }
            return p;
        }

    }

    static class Dinic {
        final int INF = 1 << 29;
        Dinic.AdjListGraph g;
        int[] level;
        int[] iter;
        int[] q;
        List<int[]> es = new ArrayList<>();

        void bfs(int s) {
            for (int i = 0; i < level.length; i++) level[i] = -1;
//		Queue<Integer> q = new LinkedList<Integer>();
            int qs = 0, qt = 0;
            level[s] = 0;
            q[qt++] = s;
            while (qs != qt) {
                int v = q[qs++];
                for (int e = g.head[v]; e != -1; e = g.next[e]) {
                    final int t = g.to[e];
                    if (g.cap[e] > 0 && level[t] < 0) {
                        level[t] = level[v] + 1;
                        q[qt++] = t;
                    }
                }
            }
        }

        int dfs(int v, int t, int f) {
            if (v == t) return f;
            for (int i = iter[v]; i != -1; i = iter[v] = g.next[i]) {
                if (g.cap[i] > 0 && level[v] < level[g.to[i]]) {
                    int d = dfs(g.to[i], t, Math.min(f, g.cap[i]));
                    if (d > 0) {
                        g.cap[i] -= d;
                        g.cap[g.rev[i]] += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        public void addEdge(int from, int to, int cap) {
            es.add(new int[]{from, to, cap,});
//		g.addEdge(from, to, cap, g.m + 1);
//		g.addEdge(to, from, 0, g.m - 1);
        }

        private void build() {
            if (g == null) {
                g = new Dinic.AdjListGraph(level.length, 2 * es.size() * 2);
                for (int[] e : es) {
                    g.addEdge(e[0], e[1], e[2], g.m + 1);
                    g.addEdge(e[1], e[0], 0, g.m - 1);
                }
            }
        }

        public int MaxFlow(int s, int t) {
            build();
            int flow = 0;
            for (; ; ) {
                bfs(s);
                if (level[t] < 0) return flow;
                for (int i = 0; i < iter.length; i++) iter[i] = g.head[i];
                for (int f = 0; (f = dfs(s, t, INF)) > 0; )
                    flow += f;
            }
        }

        public Dinic(int size) {
            level = new int[size];
            iter = new int[size];
            q = new int[size];
        }

        static class AdjListGraph {
            int m;
            int[] head;
            int[] next;
            int[] to;
            int[] rev;
            int[] cap;

            public AdjListGraph(int V, int E) {
                head = new int[V];
                next = new int[E];
                to = new int[E];
                cap = new int[E];
                rev = new int[E];
                clear();
            }

            public void clear() {
                m = 0;
                Arrays.fill(head, -1);
            }

            public void addEdge(int s, int t, int c, int r) {
                next[m] = head[s];
                head[s] = m;
                to[m] = t;
                cap[m] = c;
                rev[m++] = r;
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

        public int[] nextIntArray(final int n) {
            final int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
        }

        static class EndOfFileRuntimeException extends RuntimeException {
        }

    }
}