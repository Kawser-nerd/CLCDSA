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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            TaskD.Vertex[] vs = new TaskD.Vertex[n];
            for (int i = 0; i < n; ++i) vs[i] = new TaskD.Vertex();
            for (int i = 0; i < n - 1; ++i) {
                TaskD.Vertex x = vs[in.nextInt() - 1];
                TaskD.Vertex y = vs[in.nextInt() - 1];
                x.adj.add(y);
                y.adj.add(x);
            }
            int z = vs[0].solve(null);
            if (z == 0) {
                out.println("Bob");
            } else {
                out.println("Alice");
            }
        }

        static class Vertex {
            List<TaskD.Vertex> adj = new ArrayList<>();

            public int solve(TaskD.Vertex parent) {
                int res = 0;
                for (TaskD.Vertex v : adj)
                    if (v != parent) {
                        res ^= 1 + v.solve(this);
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