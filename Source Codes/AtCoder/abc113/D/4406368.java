import java.util.Arrays;
import java.util.Scanner;

public class Main {

    long MOD = (long)(1e9 + 7);

    boolean ok(int p, int w) {
        if ((p & 1) == 1) return false;
        if (((p >> (w)) & 1) == 1) return false;
        for (int b = 0; b <= w; b++) {
            if (((p >>> b) & 3) == 3) {
                return false;
            }
        }
        return true;
    }

    public void run() {
        Scanner sc = new Scanner(System.in);

        int H = sc.nextInt(), W = sc.nextInt(), K = sc.nextInt();

        long[][] dp = new long[H + 1][W + 2];
        dp[0][1] = 1;

        for (int h = 1; h <= H; h++) {
            for (int i = 0; i < (1 << W + 1); i++) {
                if (ok(i, W)) {
                    for (int j = 1; j <= W; j++) {
                        if (((i >> (j - 1)) & 1) == 1) dp[h][j - 1] = (dp[h][j - 1] + dp[h - 1][j]) % MOD;
                        if (((i >> j) & 1) == 1) dp[h][j + 1] = (dp[h][j + 1] + dp[h - 1][j]) % MOD;
                        if (((i >> (j - 1)) & 3) == 0) dp[h][j] = (dp[h][j] + dp[h - 1][j]) % MOD;
                    }
                }
            }
        }
        System.out.println(dp[H][K]);
    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        new Main().run();
    }
}