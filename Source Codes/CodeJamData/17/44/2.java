import java.io.*;
import java.util.*;

public class D {
    FastScanner in;
    PrintWriter out;

    class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            out.print("Case #" + (t + 1) + ": ");
            int m = in.nextInt();
            int n = in.nextInt();
            int moves = in.nextInt();
            char[][] a = new char[n][m];
            ArrayList<Point> sold = new ArrayList<>();
            ArrayList<Point> targets = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                a[i] = in.next().toCharArray();
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == 'S') {
                        sold.add(new Point(i, j));
                    } else if (a[i][j] == 'T') {
                        targets.add(new Point(i, j));
                    }
                }
            }
            int[][] dp = new int[1 << sold.size()][1 << targets.size()];
            for (int i = 0; i < dp.length; i++) {
                Arrays.fill(dp[i], -1);
            }
            dp[0][0] = 0;

            int[] dx = new int[]{-1, 0, 0, 1};
            int[] dy = new int[]{0, -1, 1, 0};
            boolean[][] cantWalk = new boolean[n][m];
            int[] xx = new int[n * m];
            int[] yy = new int[n * m];
            int[][] dist = new int[n][m];
            int[][][] prev = new int[2][dp.length][dp[0].length];
            for (int mask = 0; mask < 1 << sold.size(); mask++) {
                for (int mask2 = 0; mask2 < dp[mask].length; mask2++) {
                    int cost = dp[mask][mask2];
                    if (cost == -1) {
                        continue;
                    }
                    for (int i = 0; i < n; i++) {
                        Arrays.fill(cantWalk[i], false);
                    }
                    for (int i = 0; i < targets.size(); i++) {
                        Point p = targets.get(i);
                        if (((1 << i) & mask2) == 0) {
                            for (int iter = 0; iter < dx.length; iter++) {
                                for (int mul = 1; ; mul++) {
                                    int nx = p.x + dx[iter] * mul, ny = p.y + dy[iter] * mul;
                                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                                        break;
                                    }
                                    if (a[nx][ny] == '#') {
                                        break;
                                    }
                                    cantWalk[nx][ny] = true;
                                }
                            }
                        }
                    }
                    for (int iii = 0; iii < sold.size(); iii++) {
                        if (((1 << iii) & mask) == 0) {
                            for (int z = 0; z < n; z++) {
                                Arrays.fill(dist[z], Integer.MAX_VALUE);
                            }
                            int qIt = 0, qSz = 0;
                            xx[qSz] = sold.get(iii).x;
                            yy[qSz++] = sold.get(iii).y;
                            dist[xx[0]][yy[0]] = 0;
                            while (qIt < qSz) {
                                int x = xx[qIt], y = yy[qIt++];
                                if (!cantWalk[x][y]) {
                                    for (int it = 0; it < dx.length; it++) {
                                        int nx = x + dx[it], ny = y + dy[it];
                                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#') {
                                            if (dist[nx][ny] == Integer.MAX_VALUE) {
                                                dist[nx][ny] = dist[x][y] + 1;
                                                xx[qSz] = nx;
                                                yy[qSz++] = ny;
                                            }
                                        }
                                    }
                                }
                            }
                            for (int i = 0; i < targets.size(); i++) {
                                Point p = targets.get(i);
                                if (((1 << i) & mask2) == 0) {
                                    for (int iter = 0; iter < dx.length; iter++) {
                                        for (int mul = 1; ; mul++) {
                                            int nx = p.x + dx[iter] * mul, ny = p.y + dy[iter] * mul;
                                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                                                break;
                                            }
                                            if (a[nx][ny] == '#') {
                                                break;
                                            }
                                            if (dist[nx][ny] != Integer.MAX_VALUE) {
                                                int newDist = dist[nx][ny];
                                                if (newDist <= moves) {
                                                    if (dp[mask | (1 << iii)][mask2 | (1 << i)] == -1 || dp[mask | (1 << iii)][mask2 | (1 << i)] > newDist) {
                                                        dp[mask | (1 << iii)][mask2 | (1 << i)] = newDist;
                                                        prev[0][mask | (1 << iii)][mask2 | (1 << i)] = iii;
                                                        prev[1][mask | (1 << iii)][mask2 | (1 << i)] = i;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                    }

                }
            }

            int bmask1 = 0, bmask2 = 0;
            for (int mask1 = 0; mask1 < dp.length; mask1++) {
                for (int mask2 = 0; mask2 < dp[mask1].length; mask2++) {
                    if (dp[mask1][mask2] != -1 && Integer.bitCount(mask1) > Integer.bitCount(bmask1)) {
                        bmask1 = mask1;
                        bmask2 = mask2;
                    }
                }
            }
            out.println(Integer.bitCount(bmask1));
            ArrayList<Integer> who = new ArrayList<>();
            ArrayList<Integer> what = new ArrayList<>();
            while (bmask1 != 0) {
                int whoo = prev[0][bmask1][bmask2];
                int whatt = prev[1][bmask1][bmask2];
                who.add(whoo);
                what.add(whatt);
                bmask1 ^= (1 << whoo);
                bmask2 ^= (1 << whatt);
            }
            for (int i = who.size() - 1; i >= 0; i--) {
                out.println((who.get(i) + 1) + " " + (what.get(i) + 1));
            }
            System.err.println((t + 1) + "/" + tc + " done");
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("D.in"));
            out = new PrintWriter(new File("D.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new D().run();
    }
}