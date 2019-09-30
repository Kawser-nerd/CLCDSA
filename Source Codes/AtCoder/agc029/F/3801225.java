import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        static final int INF = (int) 1e9;

        void addEdge(TaskF.Vertex a, TaskF.Vertex b, int cap) {
            TaskF.Edge ab = new TaskF.Edge();
            TaskF.Edge ba = new TaskF.Edge();
            ab.rev = ba;
            ab.dest = b;
            ab.cap = cap;
            ba.dest = a;
            ba.rev = ab;
            a.outgo.add(ab);
            b.outgo.add(ba);
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            List<TaskF.Vertex> all = new ArrayList<>();
            TaskF.Vertex s = new TaskF.Vertex();
            TaskF.Vertex t = new TaskF.Vertex();
            all.add(s);
            all.add(t);
            TaskF.Vertex[] left = new TaskF.Vertex[n];
            for (int i = 0; i < n; ++i) {
                left[i] = new TaskF.Vertex();
                left[i].tag = i + 1;
                all.add(left[i]);
                addEdge(s, left[i], 1);
            }
            for (int i = 0; i < n - 1; ++i) {
                TaskF.Vertex cur = new TaskF.Vertex();
                all.add(cur);
                cur.tag = i;
                int count = in.nextInt();
                addEdge(cur, t, 1);
                for (int j = 0; j < count; ++j) {
                    addEdge(left[in.nextInt() - 1], cur, 1);
                }
            }
            int flow = maxFlowDfs(s, t);
            if (flow != n - 1) {
                out.println(-1);
                return;
            }
            for (TaskF.Vertex v : all) {
                v.generation = 0;
                v.nextEdge = 0;
            }
            flow = maxFlowDfs(s, t);
            if (flow != 0) {
                throw new RuntimeException();
            }
            for (TaskF.Vertex v : left) {
                if (v.generation != 1) {
                    out.println(-1);
                    return;
                }
            }
            String[] res = new String[n - 1];
            for (TaskF.Vertex v : left) {
                if (v.prevInDfs == s) continue;
                TaskF.Vertex u = v.prevInDfs.prevInDfs;
                res[v.prevInDfs.tag] = v.tag + " " + u.tag;
            }
            for (String x : res) {
                out.println(x);
            }
        }

        private int maxFlowDfs(TaskF.Vertex s, TaskF.Vertex t) {
            int curGen = 0;
            int res = 0;
            while (true) {
                ++curGen;
                int by = s.dfs(t, curGen, INF);
                if (by == 0) break;
                res += by;
            }
            return res;
        }

        static class Edge {
            TaskF.Vertex dest;
            TaskF.Edge rev;
            int cap = 0;
            int flow = 0;

        }

        static class Vertex {
            int tag = -1;
            int generation = 0;
            int nextEdge = 0;
            TaskF.Vertex prevInDfs;
            List<TaskF.Edge> outgo = new ArrayList<>();

            public int dfs(TaskF.Vertex t, int curGen, int max) {
                if (this == t) return max;
                generation = curGen;
                for (int i = 0; i < outgo.size(); ++i) {
                    TaskF.Edge e = outgo.get(nextEdge);
                    if (e.flow < e.cap && e.dest.generation < curGen) {
                        int nmax = Math.min(max, e.cap - e.flow);
                        if (nmax > 0) {
                            e.dest.prevInDfs = this;
                            nmax = e.dest.dfs(t, curGen, nmax);
                            if (nmax > 0) {
                                e.flow += nmax;
                                e.rev.flow -= nmax;
                                return nmax;
                            }
                        }
                    }
                    ++nextEdge;
                    if (nextEdge == outgo.size()) nextEdge = 0;
                }
                return 0;
            }

        }

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

    }
}