import java.util.Scanner;
import java.util.*;
public class Main {
    static int INF = Integer.MAX_VALUE;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ma = sc.nextInt();
        int mb = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }

        int[][][] dp = new int[n + 1][1000][1000];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 1000; j++) {
                for (int k = 0; k < 1000; k++) {
                    dp[i][j][k] = INF;
                }
            }
        }

        dp[0][0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 40 * 10; j++) {
                for (int k = 0; k <= 40 * 10; k++) {
                    if (dp[i][j][k] == INF) {
                        continue;
                    }
                    dp[i + 1][j][k] = Math.min(dp[i + 1][j][k], dp[i][j][k]);
                    dp[i + 1][j + a[i]][k + b[i]] =
                        Math.min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
                }
            }
        }
        // System.out.println(Arrays.deepToString(dp));

        int ans = INF;
        for (int j = 1; j <= 40 * 10; j++) {
            for (int k = 1; k <= 40 * 10; k++) {
                if (mb * j == ma * k) {
                    ans = Math.min(ans, dp[n][j][k]);
                }
            }
        }
        if (ans == INF) {
            ans = -1;
        }
        System.out.println(ans);
    }
}