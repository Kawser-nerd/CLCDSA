import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A = sc.nextInt();
        int[] x = new int[N];
        for (int i = 0; i < N; i++) {
            x[i] = sc.nextInt();
        }
        System.out.println(solve3(N, A, x));
    }

    private static long solve(int n, int a, int[] x) {
        int[] y = Arrays.stream(x).map(i -> i - a).toArray();
        return brute(n - 1, 0, y);
    }

    private static long brute(final int i, final int n, final int[] y) {
        if (i < 0) return 0;
        return (n + y[i] == 0 ? 1 : 0) + brute(i - 1, n, y) + brute(i - 1, n + y[i], y);
    }

    private static long solve2(int n, int a, int[] x) {
        // dp[i][j][k] := {x_1 ... x_i} ?? j ??????? k ?????????? O(n^3X)
        int X = Math.max(a, Arrays.stream(x).max().getAsInt());
        long[][][] dp = new long[n + 1][n + 1][n * X + 1];
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= n * X; k++) {
                    if (k - x[i - 1] >= 0 && j - 1 >= 0) {
                        dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - x[i - 1]];
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += dp[n][i][i * a];
        }
        return ans;
    }

    private static long solve3(int n, int a, int[] x) {
        // ?? 0 ???????????O(n^2X)
        int[] y = Arrays.stream(x).map(v -> v - a).toArray();
        int X = Math.max(a, Arrays.stream(x).max().getAsInt());
        long[][] dp = new long[n + 1][2 * n * X + 1];
        dp[0][n * X] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 2 * n * X; j++) {
                if (0 <= j - y[i - 1] && j - y[i - 1] <= 2 * n * X ) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - y[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][n * X] - 1;
    }

}