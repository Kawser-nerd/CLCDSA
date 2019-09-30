import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.StringTokenizer;
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
        int[] val;
        List<Integer>[] priceToVertex;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt();
            adj = (List<Integer>[]) new LinkedList[N];
            int MAX = 1000000 * 2 + 1;
            priceToVertex = (List<Integer>[]) new LinkedList[MAX];
            for (int i = 0; i < MAX; i++) priceToVertex[i] = new LinkedList<>();
            for (int i = 0; i < N; i++) adj[i] = new LinkedList<>();
            for (int i = 0; i < N - 1; i++) {
                int v = in.nextInt() - 1;
                int w = in.nextInt() - 1;
                adj[v].add(w);
                adj[w].add(v);
            }

            val = new int[N];
            Arrays.fill(val, -1);
            long K = in.nextLong();

            int min = Integer.MAX_VALUE;

            for (int i = 0; i < K; i++) {
                int vertex = in.nextInt() - 1;
                int price = in.nextInt();
                if (min > price) {
                    min = price;
                }

                val[vertex] = price;
                priceToVertex[price].add(vertex);
            }

            for (int p = 0; p < MAX; p++) {
                for (int v : priceToVertex[p]) {
                    for (int w : adj[v]) {
                        if (val[w] == -1) {
                            val[w] = val[v] + 1;
                            priceToVertex[p + 1].add(w);
                        } else if (Math.abs(val[w] - val[v]) != 1) {
                            out.println("No");
                            return;
                        }
                    }
                }
            }

            out.println("Yes");
            for (int i = 0; i < N; i++) {
                out.println(val[i]);
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