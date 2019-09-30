import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    int n, m;
    List<List<Pair>> graph;
    SortedMap<Long, Integer> idMap = new TreeMap<>();

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        m = sc.nextInt();
        graph = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int p = sc.nextInt();
            int q = sc.nextInt();
            int c = sc.nextInt();

            int p0 = getId(p, 0);
            int q0 = getId(q, 0);
            int pc = getId(p, c);
            int qc = getId(q, c);
            List<Pair> p0List = graph.get(p0);
            List<Pair> q0List = graph.get(q0);
            List<Pair> pcList = graph.get(pc);
            List<Pair> qcList = graph.get(qc);

            if (pcList.isEmpty()) {
                p0List.add(new Pair(pc, 1));
                pcList.add(new Pair(p0, 0));
            }
            pcList.add(new Pair(qc, 0));
            if (qcList.isEmpty()) {
                q0List.add(new Pair(qc, 1));
                qcList.add(new Pair(q0, 0));
            }
            qcList.add(new Pair(pc, 0));
        }
        solve();
    }

    void solve() {
        int start = getId(1, 0);
        int goal = getId(n, 0);

        Dijkstra d = new Dijkstra(graph);
        d.shortestPath(start);
        if (d.distances[goal] == 1L << 60) {
            System.out.println(-1);
        } else {
            System.out.println(d.distances[goal]);
        }
    }

    int getId(int to, int company) {
        long id = ((long)to << 32) + company;
        Integer i = idMap.get(id);
        if (i == null) {
            idMap.put(id, i = idMap.size());
            graph.add(new ArrayList<>());
        }
        return i;
    }

    class Dijkstra {
        List<List<Pair>> graph;
        long[] distances;
        long INF = 1L << 60;

        Dijkstra(List<List<Pair>> graph) {
            this.graph = graph;
            distances = new long[graph.size()];
        }

        void shortestPath(int start) {
            Arrays.fill(distances, INF);
            distances[start] = 0;
            PriorityQueue<Pair> queue = new PriorityQueue<>();
            queue.offer(new Pair(start, 0));
            while (!queue.isEmpty()) {
                Pair node = queue.poll();
                for (Pair neighbor : graph.get(node.vertex)) {
                    long newCost = distances[node.vertex] + neighbor.cost;
                    if (distances[neighbor.vertex] > newCost) {
                        distances[neighbor.vertex] = newCost;
                        queue.offer(new Pair(neighbor.vertex, newCost));
                    }
                }
            }
        }

    }

    class Pair implements Comparable<Pair>{
        int vertex;
        long cost;

        Pair(int vertex, long cost) {
            this.vertex = vertex;
            this.cost = cost;
        }

        public int compareTo(Pair p) {
            if (cost == p.cost) {
                return 0;
            } else {
                return cost < p.cost ? -1 : 1;
            }
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