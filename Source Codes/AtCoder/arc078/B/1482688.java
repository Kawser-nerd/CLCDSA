import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
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

            Graph graph = new Graph(n);
            for (int i = 0; i < n - 1; i++) {
                int from = in.nextInt() - 1;
                int to = in.nextInt() - 1;

                graph.addUndirectedEdge(from, to);
            }

            int[] d1 = new int[n];
            rec(graph, d1, 0, -1);

            int[] d2 = new int[n];
            rec(graph, d2, n - 1, -1);

            int cnt1 = 0;
            int cnt2 = 0;
            for (int i = 0; i < n; i++) {
                if (d1[i] <= d2[i]) cnt1++;
                else cnt2++;
            }

            out.println(cnt1 > cnt2 ? "Fennec" : "Snuke");
        }

        private void rec(Graph graph, int[] d1, int from, int parent) {
            for (int to : graph.get(from)) {
                if (to != parent) {
                    d1[to] = d1[from] + 1;
                    rec(graph, d1, to, from);
                }
            }
        }

    }

    static class Graph {
        int n;
        ArrayList<Integer>[] G;

        public Graph(int n) {
            this.n = n;
            G = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                G[i] = new ArrayList<>();
            }
        }

        public void addUndirectedEdge(int from, int to) {
            G[from].add(to);
            G[to].add(from);
        }

        public ArrayList<Integer> get(int from) {
            return G[from];
        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tok;

        public String nextString() {
            while (!tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(in.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return tok.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.