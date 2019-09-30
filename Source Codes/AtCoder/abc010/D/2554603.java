import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    int n, g, e;
    ArrayList<ArrayList<Edge>> graph;
    Set<Integer> sinks;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        g = sc.nextInt();
        e = sc.nextInt();
        int[] tempSinks = new int[g];
        for (int i = 0; i < g; i++) {
            tempSinks[i] = sc.nextInt();
        }
        graph = new ArrayList<>();
        for (int i = 0; i <= n + g; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < g; i++) {
            graph.get(tempSinks[i]).add(new Edge(n + i, 1,
                    graph.get(n + i).size()));
            graph.get(n + i).add(new Edge(tempSinks[i], 0,
                    graph.get(tempSinks[i]).size() - 1));
            graph.get(n + i).add(new Edge(n + g, 1,
                    graph.get(n + g).size()));
            graph.get(n + g).add(new Edge(n + i, 1,
                    graph.get(n + i).size() - 1));
        }
        for (int i = 0; i < e; i++) {
            int from = sc.nextInt();
            int to = sc.nextInt();
            graph.get(from).add(new Edge(to, 1, graph.get(to).size()));
            graph.get(to).add(new Edge(from, 1, graph.get(from).size() - 1));
        }
        solve();
    }

    void solve() {
        FordFulkerson ff = new FordFulkerson(graph);
        System.out.println(ff.maximumFlow(0, n + g));
    }

    class FordFulkerson {
        ArrayList<ArrayList<Edge>> graph;
        boolean[] used;

        FordFulkerson(ArrayList<ArrayList<Edge>> graph) {
            this.graph = graph;
            used = new boolean[graph.size()];
        }

        long maximumFlow(int s, int t) {
            long flow = 0;
            while (true) {
                Arrays.fill(used, false);
                long f = dfs(s, t, Long.MAX_VALUE);
                if (f == 0) {
                    return flow;
                }
                flow += f;
            }
        }

        long dfs(int v, int t, long f) {
            if (v == t) {
                return f;
            }
            used[v] = true;
            for (Edge e : graph.get(v)) {
                if (!used[e.to] && e.capacity > 0) {
                    long d = dfs(e.to, t, Math.min(f, e.capacity));
                    if (d > 0) {
                        e.capacity -= d;
                        graph.get(e.to).get(e.reverse).capacity += d;
                        return d;
                    }
                }
            }
            return 0;
        }
    }

    class Edge {
        int to;
        int capacity;
        int reverse;

        Edge(int to, int capacity, int reverse) {
            this.to = to;
            this.capacity = capacity;
            this.reverse = reverse;
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}