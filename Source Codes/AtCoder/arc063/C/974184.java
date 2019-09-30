import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Queue;
import java.io.BufferedReader;
import java.util.LinkedList;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        List<Integer>[] adj;
        int[] assigned;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt();
            adj = (List<Integer>[]) new LinkedList[N];

            for (int i = 0; i < N; i++) adj[i] = new LinkedList<>();

            for (int i = 0; i < N - 1; i++) {
                int v = in.nextInt() - 1;
                int w = in.nextInt() - 1;
                adj[v].add(w);
                adj[w].add(v);
            }

            assigned = new int[N];
            Arrays.fill(assigned, -1);

            Queue<TaskE.Node> pq = new PriorityQueue<>();

            long K = in.nextLong();

            for (int i = 0; i < K; i++) {
                int vertex = in.nextInt() - 1;
                int price = in.nextInt();
                assigned[vertex] = price;
                pq.add(new TaskE.Node(vertex, price));
            }

            while (!pq.isEmpty()) {
                TaskE.Node node = pq.poll();
                for (int w : adj[node.vertex]) {
                    if (assigned[w] == -1) {
                        assigned[w] = assigned[node.vertex] + 1;
                        pq.add(new TaskE.Node(w, assigned[w]));
                    } else if (Math.abs(assigned[w] - assigned[node.vertex]) != 1) {
                        out.println("No");
                        return;
                    }
                }
            }

            out.println("Yes");
            for (int i = 0; i < N; i++) {
                out.println(assigned[i]);
            }
        }

        private static class Node implements Comparable<TaskE.Node> {
            private int vertex;
            private int price;

            public Node(int vertex, int price) {
                this.vertex = vertex;
                this.price = price;
            }

            public int compareTo(TaskE.Node that) {
                return this.price - that.price;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.