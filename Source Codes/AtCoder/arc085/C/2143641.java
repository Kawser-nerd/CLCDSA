import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author palayutm
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long S1 = 0, S2 = 0;
            int n = in.nextInt();
            int[] a = in.nextIntArray(n);
            MaximumFlow mf = new ISAP(n + 2);
            int source = 0, sink = n + 1;
            for (int i = 1; i <= n; i++) {
                S1 += a[i - 1];
                if (a[i - 1] < 0) {
                    S2 += -a[i - 1];
                    mf.addEdge(source, i, -a[i - 1]);
                } else {
                    mf.addEdge(i, sink, a[i - 1]);
                }
                for (int j = i; j <= n; j++) {
                    if (j % i == 0) {
                        mf.addEdge(i, j, Long.MAX_VALUE);
                    }
                }
            }
            out.println(S1 + S2 - mf.maxFlow(source, sink));
        }

    }

    static class ISAP implements MaximumFlow {
        ArrayList<FlowEdge>[] g;
        int[] d;
        int[] vd;

        public ISAP(int vertexNum) {
            g = new ArrayList[vertexNum];
            for (int i = 0; i < vertexNum; i++) g[i] = new ArrayList();
            d = new int[vertexNum];
            vd = new int[vertexNum * 2];
        }


        public void addEdge(int from, int to, long cap) {
            FlowEdge a = new FlowEdge(to, cap);
            FlowEdge b = new FlowEdge(from, 0);
            a.back = b;
            b.back = a;
            g[from].add(a);
            g[to].add(b);
        }

        long sap(int u, int st, int ed, long flow) {
            if (u == ed) return flow;
            long ret = 0;
            for (FlowEdge forward : g[u]) {
                FlowEdge back = forward.back;
                if (d[forward.to] < d[u] && forward.cap > 0) {
                    long f = sap(forward.to, st, ed, Math.min(flow - ret, forward.cap));
                    ret += f;
                    forward.cap -= f;
                    back.cap += f;
                    if (ret == flow) return ret;
                }
            }
            if (--vd[d[u]] == 0) d[st] = g.length;
            vd[++d[u]]++;
            return ret;
        }


        public long maxFlow(int source, int sink) {
            long ret = 0;
            while (d[source] < g.length) ret += sap(source, source, sink, Long.MAX_VALUE);
            return ret;
        }

    }

    static interface MaximumFlow {
        public void addEdge(int from, int to, long cap);

        public long maxFlow(int source, int sink);

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

    }

    static class OutputWriter extends PrintWriter {
        public OutputWriter(OutputStream out) {
            super(out);
        }

        public OutputWriter(Writer out) {
            super(out);
        }

        public void close() {
            super.close();
        }

    }

    static class FlowEdge {
        int to;
        long cap;
        FlowEdge back;

        public FlowEdge() {
        }

        public FlowEdge(int to, long cap) {
            this.to = to;
            this.cap = cap;
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.