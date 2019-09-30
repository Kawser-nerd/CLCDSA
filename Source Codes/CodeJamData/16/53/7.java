import java.io.*;
import java.util.*;

public class Jumps {

    class Point {
        int x, y, z;

        public Point(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        double dist(Point other) {
            double dx = x - other.x, dy = y - other.y, dz = z - other.z;
            return Math.sqrt(dx * dx + dy * dy + dz * dz);
        }
    }

    public void solve() {
        int n = in.nextInt();
        in.nextDouble();
        Point[] pts = new Point[n];
        for (int i = 0; i < n; i++) {
            pts[i] = new Point(in.nextInt(), in.nextInt(), in.nextInt());
            in.nextDouble();
            in.nextDouble();
            in.nextDouble();
        }
        double[][] dist = new double[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++ ){
                dist[i][j] = dist[j][i] = pts[i].dist(pts[j]);
            }
        }

        double l = 0, r = 5000;
        for (int IT = 0; IT < 200; IT++) {
            double mid = (l + r) / 2;
            boolean[] vis = new boolean[n];
            int[] queue = new int[n];
            int head = 0, tail = 0;
            vis[0] = true;
            queue[tail++] = 0;
            while (head < tail) {
                int cur = queue[head++];
                for (int i = 0; i < n; i++) {
                    if (!vis[i] && dist[cur][i] < mid) {
                        vis[i] = true;
                        queue[tail++] = i;
                    }
                }
            }
            if (vis[1]) {
                r = mid;
            } else {
                l = mid;
            }
        }
        out.println(r);
    }

    public void run() {
        try {
            in = new FastScanner("input.txt");
            out = new PrintWriter("output.txt");
            int tests = in.nextInt();
            for (int i = 1; i <= tests; i++) {
                long time = System.currentTimeMillis();
                out.printf("Case #%d: ", i);
                solve();
                System.err.printf("Solved case #%d in %d ms\n", i, System.currentTimeMillis() - time);
            }
            out.close();
        } catch (FileNotFoundException e) {
        }
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new Jumps().run();
    }
}
