import java.util.Scanner;

public class Main {
    static double dp[][][];
    static int n, k;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        dp = new double[n + 1][k + 2][2];
        for (int i = 0; i < k + 1; i++) {
            dp[n][i][1] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < k + 1; j++) {
                for (int l = 0; l < 2; l++) {
                    double p = 1.0 / (i + 1);
                    double r = (1.0 - p) * dp[i + 1][j][l]
                            + p * Math.max(dp[i + 1][j + 1][1], dp[i + 1][j][0]);
                    dp[i][j][l] = r;
                }
            }
        }
        System.out.println(dp[0][0][0]);
    }

    // public static double dp(int i, int j, int isEated) {
    //     if (j > k) {
    //         return 0;
    //     }
    //     if (i == n) {
    //         return isEated;
    //     }
    //     if (memo[i][j][isEated] > 0) {
    //         return memo[i][j][isEated];
    //     }
    //     double p = 1.0 / (i + 1);
    //     double r = (1.0 - p) * dp(i + 1, j, isEated)
    //             + p * Math.max(dp(i + 1, j + 1, 1), dp(i + 1, j, 0));
    //     return memo[i][j][isEated] = r;
    // }
}