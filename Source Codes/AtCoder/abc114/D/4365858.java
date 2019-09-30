import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

    void run() {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] ps = new int[50];
        List<Integer> primes = primes();

        for (int i = 2; i <= n; i++) {
            int tmp = i;
            for (int p: primes) if (p != 0 && p <= n) {
                int cnt = 0;
                while (tmp % p == 0) {
                    cnt++;
                    tmp /= p;
                }
                ps[p] += cnt;
            }
        }

        // 0: 0, 3: 1, 5: 2, 15: 3, 25: 4, 75: 5
        int[][] dp = new int[16][6];
        // 0 -> 3, 0 -> 5, 0 -> 15, 0 -> 25, 0 -> 75
        // 3 -> 15, 3 -> 75
        // 5 -> 15, 5 -> 25, 5 -> 75
        // 15 -> 75
        // 25 -> 75
        dp[0][0] = 1;
        for (int i = 1; i < 16; i++) {
            for (int j = 0; j < 6; j++) dp[i][j] += dp[i - 1][j];
            if (ps[primes.get(i)] >= 2) {
                dp[i][1] += dp[i - 1][0];
                dp[i][3] += dp[i - 1][2];
                dp[i][5] += dp[i - 1][4];
            }
            if (ps[primes.get(i)] >= 4) {
                dp[i][2] += dp[i - 1][0];
                dp[i][3] += dp[i - 1][1];
                dp[i][4] += dp[i - 1][2];
                dp[i][5] += dp[i - 1][3];
            }
            if (ps[primes.get(i)] >= 14) {
                dp[i][3] += dp[i - 1][0];
                dp[i][5] += dp[i - 1][2];
            }
            if (ps[primes.get(i)] >= 24) {
                dp[i][4] += dp[i - 1][0];
                dp[i][5] += dp[i - 1][1];
            }
            if (ps[primes.get(i)] >= 74) {
                dp[i][5] += dp[i - 1][0];
            }
            debug(dp[i]);
        }

        debug(ps);
        debug(dp[15][5]);
        System.out.println(dp[15][5]);
    }

    List<Integer> primes() {
        boolean[] used = new boolean[50];
        List<Integer> ret = new ArrayList<>();
        // sentinel
        ret.add(0);
        for (int i = 2; i < 50; i++) if (!used[i]) {
            used[i] = true;
            ret.add(i);
            for (int j = i * 2; j < 50; j+=i) used[j] = true;
        }
        return ret;
    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        new Main().run();
    }
}