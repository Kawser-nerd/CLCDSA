import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class HFast implements Runnable {
    public static void main(String[] args) {
        new Thread(new HFast()).run();
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }

        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public class Building {
        int x1, y1, x2, y2;

        public Building(int x1, int y1, int x2, int y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }
    }

    int[] dx = {1, 1, 0, -1, -1, -1, 0, 1};
    int[] dy = {0, 1, 1, 1, 0, -1, -1, -1};

    public int[][] buildGraph(int w, int h, Building[] b) {
        int[][] d = new int[b.length + 2][b.length + 2];
        for (int i = 0; i < d.length; i++) {
            Arrays.fill(d[i], Integer.MAX_VALUE);
        }

        for (int i = 0; i < b.length; i++) {
            for (int k = 0; k < b.length; k++) {
                int dy = Math.min(Math.min(Math.abs(b[i].y1 - b[k].y1), Math.abs(b[i].y1 - b[k].y2)), Math.min(Math.abs(b[i].y2 - b[k].y1), Math.abs(b[i].y2 - b[k].y2)));
                int dx = Math.min(Math.min(Math.abs(b[i].x1 - b[k].x1), Math.abs(b[i].x1 - b[k].x2)), Math.min(Math.abs(b[i].x2 - b[k].x1), Math.abs(b[i].x2 - b[k].x2)));
                if (Math.max(b[i].x1, b[k].x1) <= Math.min(b[i].x2, b[k].x2)) {
                    d[i][k] = dy - 1;
                    continue;
                }

                if (Math.max(b[i].y1, b[k].y1) <= Math.min(b[i].y2, b[k].y2)) {
                    d[i][k] = dx - 1;
                    continue;
                }
                d[i][k] = Math.max(dx - 1, dy - 1);
            }
            d[i][b.length] = b[i].x1;
            d[i][b.length + 1] = w - b[i].x2 - 1;

            d[b.length][i] = d[i][b.length];
            d[b.length + 1][i] = d[i][b.length + 1];
        }
        return d;
    }

    public void solve() throws IOException {
        int w = nextInt();
        int h = nextInt();
        int n = nextInt();

        if (n == 0) {
            out.println(w);
            return;
        }

        Building[] b = new Building[n];

        int[][] d = new int[n + 2][n + 2];

        for (int i = 0; i < n; i++) {
            b[i] = new Building(nextInt(), nextInt(), nextInt(), nextInt());
        }

        d = buildGraph(w, h, b);

        int INF = Integer.MAX_VALUE / 2;
        int[] dist = new int[n + 2];
        Arrays.fill(dist, INF);
        dist[n] = 0;
        boolean[] was = new boolean[n + 2];
        for (int i = 0; i < dist.length; i++) {
            int mi = -1;
            for (int j = 0; j < dist.length; j++) {
                if ((mi == -1 || dist[mi] > dist[j]) && !was[j])
                    mi = j;
            }
            was[mi] = true;
            for (int j = 0; j < dist.length; j++) {
                if (d[mi][j] != Integer.MAX_VALUE && !was[j]) {
                    dist[j] = Math.min(dist[j], dist[mi] + d[mi][j]);
                }
            }
        }

        out.println(dist[n + 1]);
    }

    public void run() {
        try {
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");

            int t = nextInt();
            for (int i = 0; i < t; i++) {
                out.print("Case #" + (i + 1) + ": ");
                solve();
            }

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}
