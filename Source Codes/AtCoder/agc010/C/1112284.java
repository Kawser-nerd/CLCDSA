import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    void solve() throws IOException {
        int n = ni();
        int[] a = nia(n);

        Graph g = new Graph(n, a);
        for (int i = 0; i < n - 1; i++) {
            int from = ni() - 1, to = ni() - 1;
            g.addEdge(from, to);
        }

        int e = g.dfs(0);
        if (e == 0) {
            out.println("YES");
        } else {
            out.println("NO");
        }
    }

    class Graph {
        int n;
        ArrayList<Integer>[] graph;
        int[] a;
        boolean[] visited;

        Graph(int n, int[] a) {
            this.n = n;
            graph = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                graph[i] = new ArrayList<>();
            }
            this.a = a;
            visited = new boolean[n];
        }

        void addEdge(int from, int to) {
            graph[from].add(to);
            graph[to].add(from);
        }

        int dfs(int x) {
            visited[x] = true;

            if (x == 0 && graph[x].size() == 1) {
                return a[x] - dfs(graph[x].get(0));
            }

            if (graph[x].size() == 1) {
                return a[x];
            }

            int sum = 0;
            int max = 0;
            for (int y : graph[x]) {
                if (visited[y]) continue;

                int t = dfs(y);

                if (t == -1) return -1;

                sum += t;
                max = Math.max(max, t);
            }

            int e = 2 * a[x] - sum;
            if (e < 0 || e < max - (sum - max) || e > sum) return -1;

            return e;
        }
    }

    String ns() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine(), " ");
        }
        return tok.nextToken();
    }

    int ni() throws IOException {
        return Integer.parseInt(ns());
    }

    long nl() throws IOException {
        return Long.parseLong(ns());
    }

    double nd() throws IOException {
        return Double.parseDouble(ns());
    }

    String[] nsa(int n) throws IOException {
        String[] res = new String[n];
        for (int i = 0; i < n; i++) {
            res[i] = ns();
        }
        return res;
    }

    int[] nia(int n) throws IOException {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = ni();
        }
        return res;
    }

    long[] nla(int n) throws IOException {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = nl();
        }
        return res;
    }

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        tok = new StringTokenizer("");
        Main main = new Main();
        main.solve();
        out.close();
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.