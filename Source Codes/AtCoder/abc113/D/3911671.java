import java.util.Scanner;

public class Main {
    static final long MOD = 1_000_000_007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt(), w = sc.nextInt(), k = sc.nextInt();
        long[][] dp = new long[h + 1][w + 2];
        dp[0][1] = 1;
        for (int i = 0; i < h; i++) {
            for (int j = 1; j <= w; j++) {
                long left = j - 2;
                long right = w - j - 1;
                long Straight = myPow(left) * myPow(right);
                long Left = myPow(left - 1) * myPow(right);
                long Right = myPow(left) * myPow(right - 1);
                dp[i + 1][j] = dp[i][j] * Straight + dp[i][j - 1] * Left + dp[i][j + 1] * Right;
                dp[i + 1][j] %= MOD;
            }
        }
        System.out.println(dp[h][k]);
    }

    static long myPow(long weight) {
        if (weight <= 0) return 1;

        long retV = 0;
        loop:
        for (int j = 0; j < (1L << weight); j++) {
            verify:
            for (int k = 0; k < weight; k++) {
                if (k == 0) continue verify;
                if (((j >> k) & 1) == 1 && ((j >> k - 1) & 1) == 1) continue loop;
            }
            retV++;
        }
        return retV;
    }
}