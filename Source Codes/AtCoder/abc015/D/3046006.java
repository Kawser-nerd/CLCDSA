import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        int n;
        int[][][] dp;
        int[] a;
        int[] b;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int w = in.nextInt();
            n = in.nextInt();
            int k = in.nextInt();
            dp = new int[n][n + 1][w + 1]; // [????][????][???]
            a = new int[n];
            b = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                b[i] = in.nextInt();
                for (int j = 0; j <= n; j++) {
                    Arrays.fill(dp[i][j], -1);
                }
            }
            out.println(calc(0, w, k));
        }

        private int calc(int i, int w, int k) {
            if (i >= n || w <= 0 || k <= 0) {
                return 0;
            } else if (dp[i][k][w] >= 0) {
                return dp[i][k][w];
            }
            int ans = calc(i + 1, w, k);
            if (w >= a[i]) {
                ans = Math.max(ans, calc(i + 1, w - a[i], k - 1) + b[i]);
            }
            return dp[i][k][w] = ans;
        }

    }
}