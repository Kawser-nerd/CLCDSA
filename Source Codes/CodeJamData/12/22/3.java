
import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class B implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new B(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            in = new BufferedReader(new FileReader("src/input.txt"));
            out = new PrintWriter(new FileWriter("src/output.txt"));
            Locale.setDefault(Locale.US);
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    String nextString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }
    int initialWater;
    PriorityQueue<Pair> heap;
    int[][] up;
    int[][] down;
    double[][] res;
    boolean[][] possibleToVisit;

    void solve() throws IOException {
        int testCases = nextInt();
        for (int test = 1; test <= testCases; test++) {
            out.print("Case #" + test + ": ");
            initialWater = nextInt();
            int n = nextInt();
            int m = nextInt();
            up = new int[n][m];
            down = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    up[i][j] = nextInt();
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    down[i][j] = nextInt();
                }
            }

            boolean[][] visited = new boolean[n][m];
            res = new double[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    res[i][j] = Integer.MAX_VALUE / 2;
                }
            }


            possibleToVisit = new boolean[n][m];
            dfs(0, 0);
            heap = new PriorityQueue<Pair>();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (possibleToVisit[i][j]) {
                        res[i][j] = 0;
                        heap.add(new Pair(i, j, 0));
                    }
                }
            }

            while (!heap.isEmpty()) {
                Pair p = heap.poll();
                if (visited[p.x][p.y]) {
                    continue;
                }
                visited[p.x][p.y] = true;
                res[p.x][p.y] = p.time;
                tryToMove(p.x, p.y, p.x - 1, p.y, p.time);
                tryToMove(p.x, p.y, p.x + 1, p.y, p.time);
                tryToMove(p.x, p.y, p.x, p.y - 1, p.time);
                tryToMove(p.x, p.y, p.x, p.y + 1, p.time);
            }

            out.println(res[n - 1][m - 1]);
        }
    }

    void dfs(int x, int y) {
        if (possibleToVisit[x][y]) {
            return;
        }
        possibleToVisit[x][y] = true;

        for (int incx = -1; incx <= 1; incx++) {
            for (int incy = -1; incy <= 1; incy++) {
                int fx = x + incx;
                int fy = y + incy;
                if (Math.abs(incx) + Math.abs(incy) != 1) {
                    continue;
                }
                if (fx < 0 || fy < 0 || fx == up.length || fy == up[0].length) {
                    continue;
                }

                if (possibleToVisit[fx][fy]) {
                    continue;
                }

                if (down[fx][fy] + 50 > up[fx][fy]) {
                    continue;
                }
                if (down[x][y] + 50 > up[fx][fy]) {
                    continue;
                }
                if (initialWater + 50 > up[fx][fy]) {
                    continue;
                }

                if (down[fx][fy] + 50 > up[x][y]) {
                    continue;
                }
                dfs(fx, fy);
            }
        }
    }

    void tryToMove(int sx, int sy, int fx, int fy, double time) {
        if (fx < 0 || fy < 0 || fx >= up.length || fy >= up[0].length) {
            return;
        }

        if (down[fx][fy] + 50 > up[sx][sy]) {
            return;
        }

        double moveTime = calculateTime(sx, sy, fx, fy, max(0, initialWater - 10 * time)) + time;
        //out.println("try to move without " + sx + " " + sy + " to " + fx + " " + fy + " time " + time + " total " + moveTime);
        if (initialWater - moveTime * 10 - down[sx][sy] >= 20) {
            moveTime++;
        } else {
            moveTime += 10;
        }
        // out.println("try to move from " + sx + " " + sy + " to " + fx + " " + fy + " time " + time + " total " + moveTime);
        if (moveTime < Integer.MAX_VALUE / 2 && res[fx][fy] > moveTime) {
            heap.add(new Pair(fx, fy, moveTime));
            res[fx][fy] = moveTime;
        }
    }

    private double calculateTime(int sx, int sy, int fx, int fy, double water) {
        if (down[sx][sy] + 50 > up[fx][fy]) {
            return Integer.MAX_VALUE / 2;
        }
        if (down[fx][fy] + 50 > up[fx][fy]) {
            return Integer.MAX_VALUE / 2;
        }

        if (down[fx][fy] + 50 > up[sx][sy]) {
            return Integer.MAX_VALUE / 2;
        }

        double minimalWater = up[fx][fy] - 50;
        if (minimalWater > water) {
            return 0;
        } else {
            return (water - minimalWater) / 10;
        }
    }

    private class Pair implements Comparable<Pair> {

        int x;
        int y;
        double time;

        Pair(int x, int y, double time) {
            this.x = x;
            this.y = y;
            this.time = time;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            }
            if (getClass() != obj.getClass()) {
                return false;
            }
            final Pair other = (Pair) obj;
            if (this.x != other.x) {
                return false;
            }
            if (this.y != other.y) {
                return false;
            }
            if (this.time != other.time) {
                return false;
            }
            return true;
        }

        @Override
        public int hashCode() {
            int hash = 3;
            hash = 61 * hash + this.x;
            hash = 61 * hash + this.y;
            hash = 61 * hash + (int) this.time;
            return hash;
        }

        @Override
        public int compareTo(Pair t) {
            if (this.time > t.time) {
                return 1;
            }
            if (this.time < t.time) {
                return -1;
            }
            return 0;
        }
    }
}
