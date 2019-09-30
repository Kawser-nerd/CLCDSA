import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt(), w = sc.nextInt(), k = sc.nextInt();
        long[][] dp = new long[h + 1][w + 2];
        long[][] baai = new long[w][3];
        for (int i = 0; i < w; i++) {
            long left = i - 1;
            long right = w - i - 2;
            baai[i] = new long[]{myPow(left) * myPow(right), myPow(left - 1) * myPow(right), myPow(left) * myPow(right - 1)};
        }
        dp[0][1] = 1;
        for (int i = 0; i < h; i++)
            for (int j = 1; j <= w; j++)
                dp[i + 1][j] = (dp[i][j] * baai[j - 1][0] + dp[i][j - 1] * baai[j - 1][1] + dp[i][j + 1] * baai[j - 1][2]) % 1000000007;
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