import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int ma = sc.nextInt();
        int mb = sc.nextInt();

        int[][][] dp = new int[n + 1][10 * n + 1][10 * n + 1];
        int INF = 50 * 100;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 10 * n; j++) {
                Arrays.fill(dp[i][j], INF);
            }
        }
        dp[0][0][0] = 0;

        for (int i = 1; i <= n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            for (int j = 0; j <= 10 * n; j++) {
                for (int k = 0; k <= 10 * n; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j - a >= 0 && k - b >= 0) {
                        dp[i][j][k] = Math.min(dp[i][j][k], dp[i - 1][j - a][k - b] + c);
                    }
                }
            }
        }

        int i = 1;
        int ans = INF;
        while (i * ma <= 10 * n && i * mb <= 10 * n) {
            ans = Math.min(ans, dp[n][i * ma][i * mb]);
            i++;
        }
        System.out.println(ans == INF ? -1 : ans);
    }
}