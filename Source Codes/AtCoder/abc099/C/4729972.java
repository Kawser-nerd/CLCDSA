// ??????????????????

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] dp = new int[n+10];
        dp[0] = 0;
        for (int i = 1; i < dp.length; i++) {
            dp[i] = Integer.MAX_VALUE;

            int tmp = 1;
            while (tmp <= i) {
                dp[i] = Math.min(dp[i], dp[i - tmp] + 1);
                tmp *= 6;
            }

            tmp = 1;
            while (tmp <= i) {
                dp[i] = Math.min(dp[i], dp[i - tmp] + 1);
                tmp *= 9;
            }
        }

        System.out.println(dp[n]);
    }
}