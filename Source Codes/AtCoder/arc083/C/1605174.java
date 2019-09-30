import java.util.*;

public class Main {
    int n;
    int[] ps;
    int[] xs;
    ArrayList<ArrayList<Integer>> graph;
    PriorityQueue<Node> queue;
    int[] ys;
    private final static int INF = 1 << 29;

    public static void main(String[] args) {
        Main m = new Main();
        m.read();
        m.solve();
    }

    private void read() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        ps = new int[n];
        xs = new int[n];
        graph = new ArrayList<>(n);
        for (int i = 0; i < n; i++)
            graph.add(new ArrayList<>());
        for (int i = 1; i < n; i++)
            ps[i] = sc.nextInt() - 1;
        for (int i = 0; i < n; i++)
            xs[i] = sc.nextInt();
        createGraph();
    }

    private void createGraph() {
        for (int i = 1; i < n; i++) {
            graph.get(ps[i]).add(i);
        }
        queue = new PriorityQueue<>((n1, n2) -> Integer.compare(n2.dist, n1.dist));
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0, 0));
        while (!q.isEmpty()) {
            Node n = q.poll();
            for (int i: graph.get(n.id)) {
                q.add(new Node(i, n.dist+1));
            }
            queue.add(n);
        }
    }

    private void solve() {
        ys = new int[n];
        boolean flg = false;
        while (!queue.isEmpty()) {
            Node n = queue.poll();
            int min = dp(n.id);
            if (min == INF ) {
                flg = true;
                break;
            }
            ys[n.id] = min;
        }
        if (flg) {
            System.out.println("IMPOSSIBLE");
        }
        else {
            System.out.println("POSSIBLE");
        }
    }

    private int dp(int trg) {
        ArrayList<Integer> ls = graph.get(trg);
        if (ls.size() == 0)
            return 0;
        int[][] dp = new int[ls.size()+1][xs[trg]+1];
        for (int i = 0; i < dp.length; i++)
            Arrays.fill(dp[i], INF);
        dp[0][0] = 0;
//        for (int i: ls)
//            dp[0][0] += xs[i];
        for (int i = 1; i < dp.length; i++) {
            int n = ls.get(i-1);
            for (int j = xs[trg]; j >= 0; j--) {
                if (j + xs[n] <= xs[trg]) {
                    dp[i][j+xs[n]] = Math.min(dp[i][j+xs[n]],
                                        dp[i-1][j] + ys[n]);
                }
                if (j + ys[n] <= xs[trg]) {
                    dp[i][j + ys[n]] = Math.min(dp[i][j + ys[n]],
                                            dp[i-1][j] + xs[n]);
                }
            }
        }
        int ret = INF;
        for (int i = 0; i < dp[dp.length-1].length; i++) {
            ret = Math.min(ret, dp[dp.length-1][i]);
        }
        return ret;
    }

    private class Node {
        int id;
        int dist;
        Node(int node, int d) {
            id = node;
            dist = d;
        }

        @Override
        public String toString() {
            return String.format("%d: %d", id, dist);
        }
    }
}