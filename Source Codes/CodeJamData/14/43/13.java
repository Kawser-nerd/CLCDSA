/**
 * Created by rubanenko on 31.05.14.
 */
import java.io.*;
import java.util.*;

public class A implements Runnable {

    int n, m, best, ans;
    String[] s;
    int[] a;

    class Point {
        int x1, y1, x2, y2;
        public Point(int x1, int y1, int x2, int y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }
    }

    int simpleDist(int x1, int y1, int x2, int y2) {
        return Math.max(Math.abs(x1 - x2), Math.abs(y1 - y2));
    }

    int distFromPoint(int x, int y, Point p) {
        int res = 1000000000;
        res = Math.min(res, simpleDist(x, y, p.x1, p.y1));
        res = Math.min(res, simpleDist(x, y, p.x1, p.y2));
        res = Math.min(res, simpleDist(x, y, p.x2, p.y1));
        res = Math.min(res, simpleDist(x, y, p.x2, p.y2));
        if (x >= p.x1 && x <= p.x2) {
            res = Math.min(res, Math.abs(y - p.y1));
            res = Math.min(res, Math.abs(y - p.y2));
        }
        if (y >= p.y1 && y <= p.y2) {
            res = Math.min(res, Math.abs(x - p.x1));
            res = Math.min(res, Math.abs(x - p.x2));
        }
        return res;
    }

    int dist(Point p1, Point p2) {
        int res = 1000000000;
        res = Math.min(distFromPoint(p1.x1, p1.y1, p2), res);
        res = Math.min(distFromPoint(p1.x1, p1.y2, p2), res);
        res = Math.min(distFromPoint(p1.x2, p1.y1, p2), res);
        res = Math.min(distFromPoint(p1.x2, p1.y2, p2), res);
        Point tmp = p1;
        p1 = p2;
        p2 = tmp;
        res = Math.min(distFromPoint(p1.x1, p1.y1, p2), res);
        res = Math.min(distFromPoint(p1.x1, p1.y2, p2), res);
        res = Math.min(distFromPoint(p1.x2, p1.y1, p2), res);
        res = Math.min(distFromPoint(p1.x2, p1.y2, p2), res);
        tmp = p1;
        p1 = p2;
        p2 = tmp;
        return res;
    }

    public void solve() throws IOException {
        int tc = scanner.nextInt();
        for (int tcc = 1; tcc <= tc; tcc++) {
            writer.print("Case #" + tcc + ": ");
            int w = scanner.nextInt();
            int h = scanner.nextInt();
            int n = scanner.nextInt();
            Point[] p = new Point[n + 3];
            p[1] = new Point(-1, 0, -1, h);
            p[2] = new Point(w, 0, w, h);
            for (int i = 1; i <= n; i++) {
                int x1 = scanner.nextInt();
                int y1 = scanner.nextInt();
                int x2 = scanner.nextInt();
                int y2 = scanner.nextInt();
                p[i + 2] = new Point(x1, y1, x2, y2);
            }
//            System.err.println(dist(p[1], p[4]));
//            System.err.println(dist(p[3], p[4]));
//            System.err.println(dist(p[3], p[2]));
            int[][] a = new int[n + 3][n + 3];
            n = n + 2;
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    a[i][j] = dist(p[i], p[j]) - 1;
                    a[j][i] = a[i][j];
                }
            }
            boolean[] used = new boolean[n + 2];
            used[1] = true;
            for (int i = 1; i <= n; i++) {
                int min = 1000000000;
                int num = 1;
                for (int j = 1; j <= n; j++) {
                    if (!used[j] && a[1][j] <= min) {
                        min = a[1][j];
                        num = j;
                    }
                }
                if (used[num]) break;
                used[num] = true;
                for (int j = 1; j <= n; j++) {
                    if (a[1][j] > a[1][num] + a[num][j]) a[1][j] = a[1][num] + a[num][j];
                }
            }
            writer.println(a[1][2]);
        }
    }

    public static void main(String[] args) {
        //	long startTime = System.currentTimeMillis();
        new A().run();
        //	long finishTime = System.currentTimeMillis();
        //	System.err.println(finishTime - startTime + "ms.");
    }

    public Scanner scanner;
    public PrintWriter writer;

    @Override
    public void run() {
        try {
            scanner = new Scanner(new FileInputStream("C-large.in"));
            writer = new PrintWriter(new FileOutputStream("output.txt"));
            solve();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static class Scanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;
        public boolean hasMoreTokens() throws IOException{
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                String s = nextLine();
                if (s == null) return false;
                tokenizer = new StringTokenizer(s);
            }
            return true;
        }
        Scanner(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String nextLine() throws IOException {
            return reader.readLine();
        }

        public String nextToken() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens())
                tokenizer = new StringTokenizer(nextLine());
            return tokenizer.nextToken();
        }

        public int nextInt() throws NumberFormatException, IOException {
            return Integer.parseInt(nextToken());
        }
        public long nextLong() throws NumberFormatException, IOException {
            return Long.parseLong(nextToken());
        }


        public double nextDouble() throws NumberFormatException, IOException {
            return Double.parseDouble(nextToken());
        }

    }
}