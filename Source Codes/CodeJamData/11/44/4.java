import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;
import java.util.TreeSet;

public class D_as implements Runnable {
    class Pair implements Comparable<Pair> {
        int x;
        int y;
        int w;

        Pair(int x, int y, int w) {
            this.x = x;
            this.y = y;
            this.w = w;
        }

        public int compareTo(Pair o) {
            return o.w - w;
        }
    }

    public void solve() throws IOException {
        Scanner in = new Scanner(new File("D-large.in"));
        in.useDelimiter("[ ,\r\n]+");
        PrintWriter out = new PrintWriter(new File("D-large.out"));

        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            int n = in.nextInt();
            int m = in.nextInt();
        	System.err.println(test + " of " + testNo + " (" + n + " " + m + ")");
            boolean[][] a = new boolean[n][n];
            int[] deg = new int[n];
            for (int i = 0; i < m; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                a[x][y] = a[y][x] = true;
                deg[x]++;
                deg[y]++;
            }
            int[][] nei = new int[n][];
            for (int i = 0; i < n; i++) {
                nei[i] = new int[deg[i]];
                int k = 0;
                for (int j = 0; j < n; j++) {
                    if (a[i][j]) {
                        nei[i][k++] = j;
                    }
                }
            }

            int[] q = new int[n];
            boolean[] v = new boolean[n];
            v[0] = true;
            int[] d = new int[n];
            int head = 0;
            int tail = 1;
            q[head] = 0;
            while (head < tail) {
                int x = q[head++];
                for (int y = 0; y < n; y++) {
                    if (a[x][y] && !v[y]) {
                        d[y] = d[x] + 1;
                        v[y] = true;
                        q[tail++] = y;
                    }
                }
            }
            int[][] w = new int[n][n];

            if (d[1] == 1) {
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (a[0][i]) {
                        cnt++;
                    }
                }
                out.println("Case #" + test + ": " + 0 + " " + cnt);
            } else {
                int[][] ans = new int[n][n];
                int[][] qq = new int[n * n][];
                head = 0;
                tail = 0;
                boolean[][] vv = new boolean[n][n];
                for (int i = 0; i < n; i++) {
                    if (d[i] == 1) {
                        for (int j = 0; j < n; j++) {
                            if ((a[0][j] || a[i][j]) && 0 != j && i != j) {
                                ans[0][i]++;
                            }
                        }
                        vv[0][i] = true;
                        qq[tail++] = new int[]{0, i};
                    }
                }
                int best = 0;
                while (head < tail) {
                    int x = qq[head][0];
                    int y = qq[head][1];
                    head++;
                    for (int zi = 0; zi < nei[y].length; zi++) {
                        int val = ans[x][y];
                        int z = nei[y][zi];
                        if (d[z] == d[y] + 1) {
                            if (z == 1) {
                                best = Math.max(best, val);
                            }
                            val--;

                            for (int ui = 0; ui < nei[z].length; ui++) {
                                int u = nei[z][ui];
                                if (!a[x][u] && !a[y][u]) {
                                    val = val + 1;
                                }
                            }
                            ans[y][z] = Math.max(ans[y][z], val);
                            if (!vv[y][z]) {
                                vv[y][z] = true;
                                qq[tail++] = new int[]{y, z};
                            }
                        }
                    }
                }
                out.println("Case #" + test + ": " + (d[1] - 1) + " " + best);
            }
        }

        in.close();
        out.close();

    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            System.exit(1);
        }
    }

    public static void main(String[] s) {
        Locale.setDefault(Locale.US);
        new Thread(new D_as()).start();
    }
}