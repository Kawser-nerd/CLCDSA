import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

    long MOD = 924844033L;

    long[] pns;
    int n, k;

    void run() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); k = sc.nextInt();
        int len = 2 * (n - k);
        long[][][] dp = new long[2][len + 1][2];

        long[] ss = new long[2000];
        int idx = 0;

        for (int i = 1; i <= k; i++) {
            int size = 0;
            for (int j = i; j <= n; j += k) size++;
            if (size == 1) continue;
            ss[idx++] = size - 1;
            ss[idx++] = size - 1;
        }

        calc();

        for (int i = 0; i <= len; i++) dp[0][i][0] = 1;

        int x = 1;

        long ans = pns[n];

        for (int i = 1; i <= n; i++) {
            int l = 1;
            for (int j = 0; ss[j] != 0; j++) {
                dp[x][l][0] = (dp[x][l - 1][0] + dp[x][l - 1][1]) % MOD;
                dp[x][l][1] = (dp[1 - x][l - 1][0] + dp[1 - x][l - 1][1]) % MOD;
                for (int k = 1; k < ss[j]; k++) {
                    dp[x][l + k][0] = (dp[x][l + k - 1][0] + dp[x][l + k - 1][1]) % MOD;
                    dp[x][l + k][1] = (dp[1 - x][l + k - 1][0]) % MOD;
                }
                l += ss[j];
            }
            long f = i % 2 == 0 ? 1 : -1;
            long sum = (dp[x][len][0] + dp[x][len][1]) % MOD;
            sum = (sum * pns[n - i]) % MOD;
            ans = (ans + MOD + f * sum) % MOD;
            x = 1 - x;
            dp[x][0][0] = dp[x][0][1] = dp[1 - x][0][0] = dp[1 - x][0][1] = 0;
        }

        System.out.println(ans);
    }

    void calc() {
        pns = new long[n + 1];
        pns[0] = 1;
        for (int i = 1; i <= n; i++) {
            pns[i] = (pns[i - 1] * i) % MOD;
        }
    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        new Main().run();
    }
}