import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by zzt on 17-1-26.
 */
public class Main {

    private static int n, m;
    private static char[] chars;
    private static int[] l, r, newR, sum;
    private static long[][] dp;
    private static final int MOD = (int) (1e9 + 7);

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        chars = scanner.next().toCharArray();

        l = new int[m];
        r = new int[m];

        for (int i = 0; i < m; i++) {
            l[i] = scanner.nextInt() - 1;
            r[i] = scanner.nextInt() - 1;
        }
        newR = new int[n + 1];
        for (int i = 0; i < n; i++) {
            newR[i] = i;
        }
        for (int i = 0; i < m; i++) {
            newR[l[i]] = Math.max(newR[l[i]], r[i]);
        }
        for (int i = 1; i < n; i++) {
            newR[i] = Math.max(newR[i], newR[i - 1]);
        }
        sum = new int[n];
        for (int i = 0; i < n; i++) {
            sum[i] = chars[i] - '0';
        }
        for (int i = 0; i < n - 1; i++) {
            sum[i + 1] += sum[i];
        }
        dp = new long[n + 1][n + 1];
        for (int i = 0; i < n + 1; i++) {
            Arrays.fill(dp[i], -1);
        }
        System.out.println(dfs(0, newR[0], sum[newR[0]]));
    }

    static long dfs(int L, int R, int c) {
        if (L == n)
            return 1;
        if (dp[L][c] != -1)
            return dp[L][c];
        long ret = 0;
        int add = 0;
        if (R < newR[L + 1])
            add = sum[newR[L + 1]] - sum[R];
        if (c > 0)
            ret += dfs(L + 1, newR[L + 1], c - 1 + add) % MOD;
        if (c < R - L + 1) {
            ret += dfs(L + 1, newR[L + 1], c + add) % MOD;
        }
        ret %= MOD;
        return dp[L][c] = ret;
    }
}