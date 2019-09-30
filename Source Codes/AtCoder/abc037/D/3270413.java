import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        private static final int MOD = (int) 1e9 + 7;
        private static final int[] MVX = {0, 1, 0, -1, 0, 1, 1, -1, -1};
        private static final int[] MVY = {0, 0, 1, 0, -1, 1, -1, -1, 1};
        private static int h;
        private static int w;
        private static int[][] a;
        private static int[][] dp;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            h = in.nextInt();
            w = in.nextInt();
            a = new int[h + 2][w + 2];
            dp = new int[h + 2][w + 2];
            for (int y = 1; y <= h; y++) {
                for (int x = 1; x <= w; x++) {
                    a[y][x] = Integer.parseInt(in.next());
                }
            }

            int ans = 0;
            for (int y = 1; y <= h; y++) {
                for (int x = 1; x <= w; x++) {
                    ans += dfs(x, y);
                    ans %= MOD;
                }
            }
            out.println(ans);
        }

        private static int dfs(int x, int y) {
            if (x <= 0 || w < x || y <= 0 || h < y) {
                return 0;
            } else if (dp[y][x] > 0) {
                return dp[y][x];
            }
            int t = 1;
            for (int i = 1; i <= 4; i++) {
                if (a[y][x] < a[y + MVY[i]][x + MVX[i]]) {
                    t += dfs(x + MVX[i], y + MVY[i]);
                    t %= MOD;
                }
            }
            return dp[y][x] = t;
        }

    }
}