import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int w = sc.nextInt();
        int n = sc.nextInt();
        int limit = sc.nextInt();
        int a[] = new int[n];
        int b[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }

        int dp[][][] = new int[n + 1][limit + 1][w + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= limit; j++) {
                for (int k = 0; k <= w; k++) {
                    if (k < a[i]) {
                        dp[i + 1][j][k] = Math.max(dp[i][j][k], dp[i + 1][j][k]);
                    } else {
                        dp[i + 1][j][k] =
                            Math.max(Math.max(dp[i][j][k], dp[i][j - 1][k - a[i]] + b[i]),
                                dp[i + 1][j][k]);
                    }
                }
            }
        }

        System.out.println(dp[n][limit][w]);
    }

    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().main(sc);
        } catch (Exception e) {
            throw e;
        }
    }
}