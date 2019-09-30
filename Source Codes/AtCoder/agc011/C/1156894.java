import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            TaskC.Vertex[] vs = new TaskC.Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new TaskC.Vertex();
            }
            for (int i = 0; i < m; ++i) {
                TaskC.Vertex a = vs[in.nextInt() - 1];
                TaskC.Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            long isolated = 0;
            long bipartite = 0;
            long other = 0;
            for (int i = 0; i < n; ++i) {
                if (vs[i].color > 0) continue;
                if (vs[i].adj.size() == 0) {
                    vs[i].color = 1;
                    ++isolated;
                } else {
                    if (vs[i].dfs(1)) {
                        ++bipartite;
                    } else {
                        ++other;
                    }
                }
            }
            long res = (n * (long) n) - (n - isolated) * (n - isolated);
            res += (bipartite + other) * (bipartite + other);
            res += bipartite * bipartite;
            out.println(res);
        }

        static class Vertex {
            int color = 0;
            List<TaskC.Vertex> adj = new ArrayList<>();

            public boolean dfs(int c) {
                if (color > 0) {
                    return color == c;
                }
                color = c;
                boolean res = true;
                for (TaskC.Vertex a : adj) {
                    if (!a.dfs(3 - c)) {
                        res = false;
                    }
                }
                return res;
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