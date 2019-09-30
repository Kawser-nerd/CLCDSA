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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            TaskE.Turkey[] turkeys = new TaskE.Turkey[n];
            for (int i = 0; i < n; ++i) turkeys[i] = new TaskE.Turkey(i);
            for (int i = 0; i < m; ++i) {
                TaskE.Turkey x = turkeys[in.nextInt() - 1];
                TaskE.Turkey y = turkeys[in.nextInt() - 1];
                x.visits.add(new TaskE.Visit(y, i));
                y.visits.add(new TaskE.Visit(x, i));
            }
            boolean[][] must = new boolean[n][n];
            boolean[] can = new boolean[n];
            for (TaskE.Turkey t : turkeys) {
                can[t.id] = true;
                for (TaskE.Turkey tt : turkeys) tt.must = false;
                if (t.dfs(m)) {
                    can[t.id] = false;
                } else {
                    for (TaskE.Turkey tt : turkeys)
                        if (tt.must) {
                            must[t.id][tt.id] = true;
                        }
                }
            }
            int res = 0;
            for (int i = 0; i < n; ++i)
                if (can[i]) {
                    outer:
                    for (int j = i + 1; j < n; ++j)
                        if (can[j]) {
                            for (int k = 0; k < n; ++k)
                                if (must[i][k] && must[j][k]) {
                                    continue outer;
                                }
                            ++res;
                        }
                }
            out.println(res);
        }

        static class Visit {
            TaskE.Turkey other;
            int time;

            public Visit(TaskE.Turkey other, int time) {
                this.other = other;
                this.time = time;
            }

        }

        static class Turkey {
            int id;
            boolean must;
            List<TaskE.Visit> visits = new ArrayList<>();

            public Turkey(int id) {
                this.id = id;
            }

            public boolean dfs(int before) {
                must = true;
                for (TaskE.Visit v : visits) {
                    if (v.time < before) {
                        if (v.other.must) {
                            return true;
                        }
                        if (v.other.dfs(v.time)) {
                            return true;
                        }
                    }
                }
                return false;
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