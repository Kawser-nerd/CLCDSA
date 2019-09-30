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
        Graph graph;
        boolean[] used;
        boolean can = false;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            graph = new Graph(n);
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                graph.addUndirectedEdge(a, b);
            }

            used = new boolean[n];
            if (rec(0) == 1) {
                can = true;
            }

            out.println(can ? "First" : "Second");
        }

        int rec(int x) {
            used[x] = true;
            ArrayList<Integer> list = graph.get(x);
            int sum = 0;
            for (int to : list) {
                if (!used[to]) {
                    sum += rec(to);
                }
            }

            if (sum >= 2) {
                can = true;
            }

            return 1 - sum;
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.