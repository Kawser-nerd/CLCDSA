import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.io.Reader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.util.Optional;
import java.io.BufferedReader;
import java.util.Comparator;
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
            PushRelabelBaseMaxFlow flow = new PushRelabelBaseMaxFlow(T + 1);
//        Dinic flow = new Dinic(T + 1);
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
            int f1 = (int) (flow.relabelToFront(S, T) / 2);
//        int f1 = (int)(flow.MaxFlow(S, T) / 2);
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

    static class PushRelabelBaseMaxFlow {
        int V;
        PushRelabelBaseMaxFlow.Vertex[] vertices;

        public PushRelabelBaseMaxFlow(int V) {
            this.V = V;
            vertices = new PushRelabelBaseMaxFlow.Vertex[V];
            for (int i = 0; i < V; i++) vertices[i] = new PushRelabelBaseMaxFlow.Vertex(i);
        }

        public void addEdge(int s, int t, int cap) {
            PushRelabelBaseMaxFlow.Edge e1 = new PushRelabelBaseMaxFlow.Edge(vertices[s], vertices[t], cap);
            PushRelabelBaseMaxFlow.Edge e2 = new PushRelabelBaseMaxFlow.Edge(vertices[t], vertices[s], 0);
            e1.rev = e2;
            e2.rev = e1;
        }

        private void initializePreflow(PushRelabelBaseMaxFlow.Vertex S) {
            for (PushRelabelBaseMaxFlow.Vertex v : vertices) {
                v.clear();
            }
            S.height = V;
            for (PushRelabelBaseMaxFlow.Edge e : S.edges) {
                e.v.excessFlow += e.capacity;
                e.u.excessFlow -= e.capacity;
                e.rev.capacity += e.capacity;
                e.capacity = 0;
            }
        }

        public long relabelToFront(int s, int t) {
            initializePreflow(vertices[s]);
            PushRelabelBaseMaxFlow.Vertex[] L = new PushRelabelBaseMaxFlow.Vertex[V - 1];
            for (int i = 0, j = 0; i < V; i++) {
                if (i != s && i != t) L[j++] = vertices[i];
            }

            int i = 0;
            PushRelabelBaseMaxFlow.Vertex cur = L[i];
            while (cur != null) {
                int h0 = cur.height;
                cur.discharge();
                if (cur.height > h0) {
                    L[i = 0] = cur;
                }
                PushRelabelBaseMaxFlow.Vertex tmp = L[++i];
                L[i] = cur;
                cur = tmp;
            }

            return vertices[t].excessFlow;
        }

        private static class Edge {
            PushRelabelBaseMaxFlow.Vertex u;
            PushRelabelBaseMaxFlow.Vertex v;
            PushRelabelBaseMaxFlow.Edge rev;
            long capacity;

            public Edge(PushRelabelBaseMaxFlow.Vertex s, PushRelabelBaseMaxFlow.Vertex t, long cap) {
                u = s;
                v = t;
                capacity = cap;
                s.edges.add(this);
            }

            boolean canPush() {
                return capacity > 0 && u.height == v.height + 1 && u.isOverflow();
            }

            void push() {
                final long f = Math.min(u.excessFlow, capacity);
                capacity -= f;
                rev.capacity += f;
                u.excessFlow -= f;
                v.excessFlow += f;
            }


            public String toString() {
                return String.format("[Edge u=%d(%d), v=%d(%d), c=%d]", u.id, u.height, v.id, v.height, capacity);
            }

        }

        static class Vertex {
            final int id;
            int height;
            int excessFlow;
            List<PushRelabelBaseMaxFlow.Edge> edges = new ArrayList<>();

            public Vertex(int id) {
                this.id = id;
            }

            void clear() {
                height = 0;
                excessFlow = 0;
            }

            boolean isOverflow() {
                return excessFlow > 0;
            }

            void relabel() {
                final int h = edges.stream().filter(e -> e.capacity > 0)
                        .map(a -> a.v.height)
                        .min(Comparator.naturalOrder())
                        .get();
                if (!isOverflow() || height > h) {
                    throw new RuntimeException();
                }
                height = h + 1;
            }

            void discharge() {
                while (isOverflow()) {
                    for (PushRelabelBaseMaxFlow.Edge e : edges) {
                        while (e.canPush()) e.push();
                        if (!isOverflow()) return;
                    }
                    relabel();
                }
            }


            public String toString() {
                return String.format("[Vertex id=%d, h=%d, ex=%d, es=%s]", id, height, excessFlow, edges);
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