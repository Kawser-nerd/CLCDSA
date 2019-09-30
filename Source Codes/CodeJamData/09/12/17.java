import java.util.*;
import java.util.concurrent.BlockingQueue;
import java.math.*;
import java.io.*;

public class Main implements Runnable{
    public static void main(String[] args) {
        new Thread(new Main()).start();
    }
    StringTokenizer st;
    PrintWriter out;
    BufferedReader br;
    boolean eof = false, in_out = false;
    private String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken();
    }
    private String nextLine() {
        String ret = "";
        try {
            ret = br.readLine();
        } catch (Exception e) {
            ret = "";
        }
        if (ret == null) {
            eof = true;
            return "$";
        }
        return ret;
    }
    private String nextString() {
        return nextToken();
    }
    private int nextInt() {
        return Integer.parseInt(nextToken());
    }
    private long nextLong() {
        return Long.parseLong(nextToken());
    }
    private double nextDouble() {
        return Double.parseDouble(nextToken());
    }
    private BigInteger nextBigInteger() {
        return new BigInteger(nextToken());
    }
    private String to_precision(double x, int kol) {
        if (kol == 0) {
            return Long.toString((long)Math.floor(x));
        }
        String ret = Long.toString((long)Math.floor(x));
        x -= Math.floor(x);
        for (int i=0; i<kol; i++) {
            x *= 10;
        }
        ret += "." + Long.toString((long)Math.floor(x));
        if ((long)Math.floor(x) == 0) {
            ret += "0";
        }
        return ret;
    }
    private static double EPS = 1e-9;
    String INFILE = "bear.in", OUTFILE = "bear.out";
    private boolean is_happy(int x, int k) {
        TreeSet<Integer> w = new TreeSet<Integer>();
        w.add(x);
        while (true) {
            int sum = 0;
            for (;x > 0; x /= k) sum += (x % k) * (x % k);
            if (w.contains(sum)) return false;
            x = sum;
            if (x == 1) return true;
            w.add(x);
        }
    }
    long[][] C;
    private void gen() {
        C[0][0] = 1;
        for (int i = 1; i <= 40; ++i) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    class comp implements Comparator<Integer> {
        public int compare(Integer i1, Integer i2) {
            int x1 = i1 / 100, y1 = i1 % 100, x2 = i2 / 100, y2 = i2 % 100;
            if (d[x1][y1] < d[x2][y2]) return -1;
            if (d[x1][y1] > d[x2][y2]) return 1;
            if (x1 < x2) return -1;
            if (x1 > x2) return 1;
            if (y1 < y2) return -1;
            if (y1 > y2) return 1;
            return 0;
        }
    }
    long[][] d;
    int[] dx = {1, 0, -1, 0};
    int[] dy = {0, 1, 0, -1};
    private void solve() {
        int T = nextInt();
        for (int www = 1; www <= T; ++www) {
            int n = nextInt(), m = nextInt();
            int[][] S = new int[n][m], W = new int[n][m], t = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    S[i][j] = nextInt();
                    W[i][j] = nextInt();
                    t[i][j] = nextInt();
                    t[i][j] %= S[i][j] + W[i][j];
                    t[i][j] -= S[i][j] + W[i][j];
                }
            }
            d = new long[2 * n][2 * m];
            boolean[][] was = new boolean[2 * n][2 * m];
            for (int i = 0; i < 2 * n; i++) Arrays.fill(d[i], 1 << 30);
            d[2 * n - 1][0] = 0;
            while (true) {
                long tt = (long)1 << 60;
                int got = -1;
                for (int i = 0; i < 2 * n; i++)
                for (int j = 0; j < 2 * m; j++) if (!was[i][j]) {
                    if (tt > d[i][j]) {
                        tt = d[i][j];
                        got = i * 100 + j;
                    }
                }
                if (got == -1) break;
                int xx = got / 100, yy = got % 100;
                long dd = d[xx][yy];
                was[xx][yy] = true;
                for (int dir = 0; dir < 4; ++dir) {
                    int x = xx + dx[dir], y = yy + dy[dir];
                    if (x < 0 || x >= 2 * n || y < 0 || y >= 2 * m || was[x][y]) continue;                    
                    int idx = Math.min(x, xx) / 2, idy = Math.min(y, yy) / 2;
                    if (x != xx && Math.min(x, xx) % 2 == 0) {
                        long gottime, needed;
                        gottime = dd - t[idx][idy];
                        if (gottime % (S[idx][idy] + W[idx][idy]) <= S[idx][idy] - 1) {
                            needed = dd + 1;
                        } else {
                            needed = (gottime / (S[idx][idy] + W[idx][idy]) + 1) * (S[idx][idy] + W[idx][idy]) + t[idx][idy] + 1;
                        }
                        if (d[x][y] > needed) {
                            d[x][y] = needed;
//                            w.add(x * 100 + y);
                        }
                    } else if (x != xx) {
                        if (d[x][y] > dd + 2) {
                            d[x][y] = dd + 2;
//                            w.add(x * 100 + y);
                        }
                    } else if (y != yy && Math.min(y, yy) % 2 == 0) {
                        long gottime = dd - t[idx][idy], needed;
                        if (gottime % (S[idx][idy] + W[idx][idy]) >= S[idx][idy]) {
                            needed = dd + 1;
                        } else needed = (gottime / (S[idx][idy] + W[idx][idy])) * (S[idx][idy] + W[idx][idy]) + S[idx][idy] + t[idx][idy] + 1;
                        if (d[x][y] > needed) {
                            d[x][y] = needed;
//                            w.add(x * 100 + y);
                        }
                    } else {
                        if (d[x][y] > dd + 2) {
                            d[x][y] = dd + 2;
//                            w.add(x * 100 + y);
                        }
                    }
                }
            }
            out.println("Case #" + www + ": " + d[0][2 * m - 1]);
        }
    }
    public void run() {
        try {
            br = new BufferedReader(new FileReader(new File((in_out) ?  INFILE  : "input.txt")));
            out = new PrintWriter(new File((in_out) ? OUTFILE : "output.txt"));
            //br = new BufferedReader(new FileReader(new File("input.txt")));
            //out = new PrintWriter(new File("output.txt"));
        } catch (Exception e) {
            System.exit(111);
        }
        solve();
        out.close();
    }
}
