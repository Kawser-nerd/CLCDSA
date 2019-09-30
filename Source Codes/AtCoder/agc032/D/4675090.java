import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            long A = in.nextLong();
            long B = in.nextLong();
            int[] pos = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt() - 1;
                pos[a[i]] = i;
            }

            long[][] dp = new long[n + 1][n + 1];
            for (long[] z : dp) {
                Arrays.fill(z, Long.MAX_VALUE / 2);
            }
            dp[0][0] = 0;
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i < n && a[i] == j) {
                        dp[i + 1][j + 1] = Math.min(dp[i + 1][j + 1], dp[i][j]);
                    }
                    if (i < n && a[i] > j) {
                        dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j] + A);
                    }
                    if (i < n && a[i] < j) {
                        dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j]);
                    }
                    if (j < n && pos[j] < i) {
                        dp[i][j + 1] = Math.min(dp[i][j + 1], dp[i][j]);
                    }
                    if (j < n && pos[j] > i) {
                        dp[i][j + 1] = Math.min(dp[i][j + 1], dp[i][j] + B);
                    }
                }
            }

//        System.out.println(Arrays.deepToString(dp));
            out.println(dp[n][n]);
        }

    }
}