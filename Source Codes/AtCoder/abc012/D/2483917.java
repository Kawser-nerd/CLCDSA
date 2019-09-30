import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int n, m;
    long[][] distances;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        m = sc.nextInt();
        distances = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    distances[i][j] = 1 << 60;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int from = sc.nextInt() - 1;
            int to = sc.nextInt() - 1;
            int cost = sc.nextInt();
            distances[from][to] = cost;
            distances[to][from] = cost;
        }
        solve();
    }

    void solve() {
        WarshallFloyd wf = new WarshallFloyd(distances);
        wf.shortestPath();
        long minMax = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            long max = 0;
            for (int j = 0; j < n; j++) {
                if (wf.distances[i][j] > max) {
                    max = wf.distances[i][j];
                }
            }
            if (max < minMax) {
                minMax = max;
            }
        }
        System.out.println(minMax);
    }

    public class WarshallFloyd {
        long[][] distances;
        int numVertexes;

        WarshallFloyd(long[][] distances) {
            this.distances = distances;
            numVertexes = distances.length;
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