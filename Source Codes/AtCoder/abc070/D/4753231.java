import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        Map<Integer, Map<Integer, Long>> graph = new HashMap<>();
        for (int n = 0; n < N - 1; n++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            long c = sc.nextLong();

            updateGraph(a, b, c, graph);
            updateGraph(b, a, c, graph);
        }

        long[] distances = new long[N + 1];

        int Q = sc.nextInt();
        int K = sc.nextInt();

        dijkstra(N, graph, K, distances);

        int[] x = new int[Q];
        int[] y = new int[Q];
        for (int i = 0; i < Q; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }

        for (int i = 0; i < Q; i++) {
            out.println(distances[x[i]] + distances[y[i]]);
        }
    }

    public static void updateGraph(int a, int b, long c, Map<Integer, Map<Integer, Long>> graph) {
        Map<Integer, Long> to = new HashMap<>();
        if (graph.containsKey(a)) {
            to = graph.get(a);
        }
        to.put(b, c);
        graph.put(a, to);
    }

    // ????????????graph????????Map?????
    // value?map??key: ?????, value: ??????????????
    public static void dijkstra(int n, Map<Integer, Map<Integer, Long>> graph, int start, long[] distances) {
        final long INF = Long.MAX_VALUE;

        // ???
        Arrays.fill(distances, INF);
        distances[start] = 0;
        Queue<Integer> nodesQueue = new PriorityQueue<Integer>();
        nodesQueue.add(start);

        // ??
        while (!nodesQueue.isEmpty()) {
            int node = nodesQueue.poll();

            Map<Integer, Long> toNodeCosts = graph.get(node);
            for (Map.Entry<Integer, Long> e : toNodeCosts.entrySet()) {
                int toNode = e.getKey();
                long moveCost = e.getValue();
                if (moveCost > 0 && distances[node] != INF && distances[toNode] > distances[node] + moveCost) {
                    distances[toNode] = distances[node] + moveCost;
                    nodesQueue.add(toNode);
                }
            }
        }
    }
}