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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            TaskF.Vertex[] vs = new TaskF.Vertex[n];
            for (int i = 0; i < n; ++i) vs[i] = new TaskF.Vertex(in.nextInt());
            for (int i = 0; i < n - 1; ++i) {
                TaskF.Vertex a = vs[in.nextInt() - 1];
                TaskF.Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            boolean first = true;
            for (int i = 0; i < n; ++i)
                if (vs[i].solve() == 1) {
                    if (first) first = false;
                    else out.print(" ");
                    out.print(i + 1);
                }
            out.println();
        }

        static class Vertex {
            int stones;
            List<TaskF.Vertex> adj = new ArrayList<>();
            int answer = 0;

            public Vertex(int stones) {
                this.stones = stones;
            }

            public int solve() {
                if (answer == -1) throw new RuntimeException();
                if (answer > 0) return answer;
                answer = -1;
                for (TaskF.Vertex v : adj)
                    if (v.stones < stones) {
                        int got = v.solve();
                        if (got == 2) {
                            answer = 1;
                            return answer;
                        }
                    }
                answer = 2;
                return answer;
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