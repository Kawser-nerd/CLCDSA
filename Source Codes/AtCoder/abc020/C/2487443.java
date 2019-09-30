import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    int h, w, t, sx, sy, gx, gy;
    char[][] board;
    int INF = 1 << 60;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        h = sc.nextInt();
        w = sc.nextInt();
        t = sc.nextInt();
        board = new char[h][w];
        for (int i = 0; i < h; i++) {
            board[i] = sc.next().toCharArray();
            for (int j = 0; j < w; j++) {
                if (board[i][j] == 'S') {
                    sx = j;
                    sy = i;
                } else if (board[i][j] == 'G') {
                    gx = j;
                    gy = i;
                }
            }
        }
        solve();
    }

    void solve() {
        long low = 0;
        long high = Long.MAX_VALUE >> 2;
        int[] froms = new int[4 * w * h - 2 * h - 2 * w];
        int[] tos = new int[4 * w * h - 2 * h - 2 * w];
        long[] costs = new long[4 * w * h - 2 * h - 2 * w];
        long[][] dp = new long[h][w];
        while (high - low > 1) {
            long mid = (low + high) / 2;
            int count = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    int index = i * w + j;
                    long moveCost = board[i][j] == '#' ? mid : 1;
                    if (i > 0) {
                        froms[count] = index - w;
                        tos[count] = index;
                        costs[count] = moveCost;
                        count++;
                    }
                    if (i < h - 1) {
                        froms[count] = index + w;
                        tos[count] = index;
                        costs[count] = moveCost;
                        count++;
                    }
                    if (j > 0) {
                        froms[count] = index - 1;
                        tos[count] = index;
                        costs[count] = moveCost;
                        count++;
                    }
                    if (j < w - 1) {
                        froms[count] = index + 1;
                        tos[count] = index;
                        costs[count] = moveCost;
                        count++;
                    }
                }
            }
            BellmanFord bf = new BellmanFord(froms, tos, costs, h * w);
            bf.shortestPath(sy * w + sx);
            //System.out.println(Arrays.toString(bf.distances));
            if (bf.distances[gy * w + gx] > t) {
                high = mid;
            } else {
                low = mid;
            }

            /*
            for (int i = 0; i < h; i++) {
                Arrays.fill(dp[i], INF);
            }
            dp[sx][sy] = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    long min = INF;
                    long moveCost = board[i][j] == '#' ? mid : 1;
                    if (i > 0) {
                        min = Math.min(min, dp[i - 1][j] + moveCost);
                    }
                    if (j > 0) {
                        min = Math.min(min, dp[i][j - 1] + moveCost);
                    }
                    if (i < h - 1) {
                        min = Math.min(min, dp[i + 1][j] + moveCost);
                    }
                    if (j < w - 1) {
                        min = Math.min(min, dp[i][j + 1] + moveCost);
                    }
                    dp[i][j] = Math.min(dp[i][j], min);
                }
            }
            for (int i = 0; i < h; i++) {
                System.out.println(Arrays.toString(dp[i]));
            }
            if (dp[gx][gy] > t) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            */
        }
        System.out.println(low);
    }

    public class BellmanFord {
        Edge[] edges;
        long[] distances;
        long INF = Long.MAX_VALUE >> 2;

        BellmanFord(int[] froms, int[] tos, long[] costs, int numVertex) {
            edges = new Edge[froms.length];
            for (int i = 0; i < froms.length; i++) {
                edges[i] = new Edge(froms[i], tos[i], costs[i]);
            }
            this.distances = new long[numVertex];
            Arrays.fill(this.distances, INF);
        }

        void shortestPath(int start) {
            distances[start] = 0;
            while(true) {
                boolean update = false;
                for (Edge e : edges) {
                    if (distances[e.from] < INF) {
                        long newCost = distances[e.from] + e.cost;
                        if (distances[e.to] > newCost) {
                            distances[e.to] = newCost;
                            update = true;
                        }
                    }
                }
                if (!update) {
                    break;
                }
            }
        }

        class Edge {
            int from;
            int to;
            long cost;

            Edge(int from, int to, long cost) {
                this.from = from;
                this.to = to;
                this.cost = cost;
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