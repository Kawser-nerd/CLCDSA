import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Collection;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Deque;
import java.util.LinkedList;
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
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int K = in.nextInt();
            boolean[] marked = new boolean[K];
            Deque<TaskD.State> bfs = new LinkedList<>();
            bfs.add(new TaskD.State(1, 1 % K));
            while (!bfs.isEmpty()) {
                TaskD.State st = bfs.pollFirst();
                if (st.rem == 0) {
                    out.println(st.sum);
                    return;
                }
                marked[st.rem] = true;

                TaskD.State ns = new TaskD.State(st.sum + 1, (st.rem + 1) % K);

                if (!marked[ns.rem]) {
                    bfs.addLast(ns);
                }

                ns = new TaskD.State(st.sum, 10 * st.rem % K);

                if (!marked[ns.rem]) {
                    bfs.addFirst(ns);
                }
            }
        }

        static class State {
            int sum;
            int rem;

            public State(int sum, int rem) {
                this.sum = sum;
                this.rem = rem;
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