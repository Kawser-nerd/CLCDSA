import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    int n, m;
    List<Integer> neighbors;
    List<Integer> neighborCosts;
    long[][] distances;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        m = sc.nextInt();
        neighbors = new ArrayList<>();
        neighborCosts = new ArrayList<>();
        distances = new long[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(distances[i], 1L << 60);
        }
        for (int i = 0; i < m; i++) {
            int from = sc.nextInt() - 1;
            int to = sc.nextInt() - 1;
            int cost = sc.nextInt();
            if (from > to) {
                int temp = from;
                from = to;
                to = temp;
            }
            if (from == 0) {
                neighbors.add(to);
                neighborCosts.add(cost);
            } else {
                distances[from][to] = cost;
                distances[to][from] = cost;
            }
        }
        solve();
    }

    void solve() {
        WarshallFloyd wf = new WarshallFloyd(distances);
        wf.shortestPath();
        long min = 1L << 59;
        for (int i = 0; i < neighbors.size() - 1; i++) {
            for (int j = i + 1; j < neighbors.size(); j++) {
                long cost = neighborCosts.get(i) + neighborCosts.get(j) +
                        wf.distances[neighbors.get(i)][neighbors.get(j)];
                if (cost < min) {
                    min = cost;
                }
            }
        }
        if (min >= 1L << 59) {
            System.out.println(-1);
        } else {
            System.out.println(min);
        }
    }

    class WarshallFloyd {
        long[][] distances;
        int numVertexes;
        int[][] successors;
        long INF = 1L << 60;

        WarshallFloyd(long[][] distances) {
            this.distances = distances;
            numVertexes = distances.length;
        }

        WarshallFloyd(long[][] distances, int[][] successors) {
            this.distances = distances;
            numVertexes = distances.length;
            this.successors = successors;
        }

        void shortestPath() {
            for (int k = 0; k < numVertexes; k++) {
                for (int i = 0; i < numVertexes; i++) {
                    for (int j = 0; j < numVertexes; j++) {
                        distances[i][j] = Math.min(distances[i][j],
                                distances[i][k] + distances[k][j]);
                    }
                }
            }
        }

        void shortestPathWithPath() {
            for (int k = 0; k < numVertexes; k++) {
                for (int i = 0; i < numVertexes; i++) {
                    for (int j = 0; j < numVertexes; j++) {
                        long newDistance = distances[i][k] + distances[k][j];
                        if (distances[i][j] > newDistance) {
                            distances[i][j] = newDistance;
                            successors[i][j] = successors[i][k];
                        }
                    }
                }
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