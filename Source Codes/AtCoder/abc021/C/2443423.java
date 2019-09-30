import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    int n, a, b, m;
    int[] xs, ys;
    int MOD = 1000000007;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        a = sc.nextInt() - 1;
        b = sc.nextInt() - 1;
        m = sc.nextInt();
        xs = new int[m];
        ys = new int[m];
        for (int i = 0; i < m; i++) {
            xs[i] = sc.nextInt() - 1;
            ys[i] = sc.nextInt() - 1;
        }
        solve();
    }

    void solve() {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new LinkedList<>());
        }
        for (int i = 0; i < m; i++) {
            graph.get(xs[i]).add(ys[i]);
            graph.get(ys[i]).add(xs[i]);
        }
        boolean[] visited = new boolean[n];
        int[] distances = new int[n];
        visited[a] = true;
        distances[a] = 1;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(a);
        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int neighbor : graph.get(node)) {
                if (distances[neighbor] > 0) {
                    continue;
                }
                distances[neighbor] = distances[node] + 1;
                queue.offer(neighbor);
            }
        }
        List<List<Integer>> dag = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            dag.add(new LinkedList<>());
        }
        for (int i = 0; i < m; i++) {
            if (distances[xs[i]] == distances[ys[i]] - 1) {
                dag.get(xs[i]).add(ys[i]);
            } else if (distances[xs[i]] == distances[ys[i]] + 1) {
                dag.get(ys[i]).add(xs[i]);
            }
        }
        Arrays.fill(visited, false);
        Stack<Integer> stack = new Stack<>();
        topSort(a, dag, visited, stack);
        int[] dp = new int[n];
        dp[a] = 1;
        while (!stack.empty()) {
            int node = stack.pop();
            for (int neighbor : dag.get(node)) {
                dp[neighbor] += dp[node];
                dp[neighbor] %= MOD;
            }
        }
        System.out.println(dp[b]);
    }

    void topSort(int node, List<List<Integer>> graph,
                 boolean[] visited, Stack<Integer> stack) {
        visited[node] = true;
        for (int neighbor : graph.get(node)) {
            if (!visited[neighbor]) {
                topSort(neighbor, graph, visited, stack);
            }
        }
        stack.push(node);
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