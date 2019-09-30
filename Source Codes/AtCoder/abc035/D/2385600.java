import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        new Main().run();
    }

    List<List<Edge>> graph;
    List<List<Edge>> rGraph;

    void run() {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        int m = sc.nextInt();
        long t = sc.nextInt();
        long[] rewards = new long[n];
        for (int i = 0; i < n; i++) {
            rewards[i] = sc.nextInt();
        }
        graph = new ArrayList<>();
        rGraph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new LinkedList<>());
            rGraph.add(new LinkedList<>());
        }
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            int c = sc.nextInt();
            graph.get(a).add(new Edge(b, c));
            rGraph.get(b).add(new Edge(a, c));
        }

        long[] distance = new long[n];
        long[] rDistance = new long[n];
        dijkstra(graph, distance, 0);
        dijkstra(rGraph, rDistance, 0);
        long maxIncome = 0;
        for (int i = 0; i < n; i++) {
            if (distance[i] < 0 || rDistance[i] < 0) continue;
            long income = rewards[i] * (t - distance[i] - rDistance[i]);
            maxIncome = Math.max(maxIncome, income);
        }
        System.out.println(maxIncome);
    }

    void dijkstra(List<List<Edge>> graph, long[] distance, int start) {
        Queue<Integer> pQueue =
                new PriorityQueue<>((a, b) -> distance[a] < distance[b] ? -1 : 1);
        distance[start] = 0;
        pQueue.offer(0);
        for (int i = 1; i < distance.length; i++) {
            distance[i] = -1;
        }
        while (!pQueue.isEmpty()) {
            int node = pQueue.poll();
            for (Edge e : graph.get(node)) {
                long newCost = distance[node] + e.cost;
                if (distance[e.to] < 0 || newCost < distance[e.to]) {
                    distance[e.to] = newCost;
                    pQueue.offer(e.to);
                }
            }
        }
    }

    class Edge {
        int to;
        long cost;

        Edge(int to, long cost){
            this.to = to;
            this.cost = cost;
        }
    }

    class FastReader {
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