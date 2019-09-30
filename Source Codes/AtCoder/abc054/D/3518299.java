import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int ma = sc.nextInt();
        int mb = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];
        int a_sum = 0;
        int b_sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            c[i] = sc.nextInt();
            a_sum += a[i];
            b_sum += b[i];
        }

        int[][] dp = new int[a_sum+1][b_sum+1];
        for (int i = 0; i < n; i++) {

            for (int j = a_sum; j >= 0; j--) {
                for (int k = b_sum; k >= 0; k--) {
                    if (dp[j][k] != 0 && j+a[i] <= a_sum && k+b[i] <= b_sum) {
                        if (dp[j+a[i]][k+b[i]] == 0) {
                            dp[j+a[i]][k+b[i]] = dp[j][k] + c[i];
                        } else {
                            dp[j+a[i]][k+b[i]] = Math.min(dp[j+a[i]][k+b[i]], dp[j][k] + c[i]);
                        }
                    }
                }
            }

            if (dp[a[i]][b[i]] == 0) {
                dp[a[i]][b[i]] = c[i];
            } else {
                dp[a[i]][b[i]] = Math.min(dp[a[i]][b[i]], c[i]);
            }
        }


//        for (int i = 0; i < a_sum; i++) {
//            for (int j = 0; j < b_sum; j++) {
//                System.out.print(dp[i][j]);
//                System.out.print(" ");
//            }
//            System.out.println("\n");
//        }

        int ans = -1;
        int tmp_ma = ma;
        int tmp_mb = mb;
        while (tmp_ma <= a_sum && tmp_mb <= b_sum) {
            if (dp[tmp_ma][tmp_mb] != 0) {
                if (ans == -1) {
                    ans = dp[tmp_ma][tmp_mb];
                } else {
                    ans = Math.min(ans, dp[tmp_ma][tmp_mb]);
                }
            }
            tmp_ma += ma;
            tmp_mb += mb;
        }
        System.out.println(ans);
    }
}