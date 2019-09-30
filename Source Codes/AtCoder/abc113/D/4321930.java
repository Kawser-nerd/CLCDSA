import java.util.Scanner;

public class Main {
    private static final long MOD = 1_000_000_007;
    private int sum = 0;

    public void main(Scanner sc) {
        int h = sc.nextInt();
        int w = sc.nextInt();
        int k = sc.nextInt();

        int cnt[] = new int[w + 1];
        init(w, cnt);

        long dp[][] = new long[h + 1][w];
        dp[0][0] = 1;
        for (int i = 1; i <= h; i++) {
            for (int j = 0; j < w; j++) {
                // ?
                if (j > 0) {
                    dp[i][j - 1] += cnt[j] * dp[i - 1][j];
                    dp[i][j - 1] %= MOD;
                }

                // ?
                dp[i][j] += (sum - cnt[j] - cnt[j + 1]) * dp[i - 1][j];
                dp[i][j] %= MOD;

                // ?
                if (j + 1 < w) {
                    dp[i][j + 1] += cnt[j + 1] * dp[i - 1][j];
                    dp[i][j + 1] %= MOD;
                }
            }
        }

        System.out.println(dp[h][k - 1]);
    }

    private void init(int w, int cnt[]) {
        for (int n = 0; n < (1 << (w - 1)); n++) {
            int tmp = n;
            int bi[] = new int[w];
            boolean ok = true;
            for (int i = 0; i < w - 1; i++) {
                bi[i + 1] = tmp % 2;
                if (bi[i] * bi[i + 1] == 1) {
                    ok = false;
                    break;
                }
                tmp /= 2;
            }

            if (ok) {
                sum++;
                for (int i = 1; i < w; i++) {
                    cnt[i] += bi[i];
                }
            }
        }
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().main(sc);
        } catch (Exception e) {
            throw e;
        }
    }
}