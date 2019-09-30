import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Math.max;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] x = new int[n];

        for (int i = 0; i < n; i++) {
            x[i] = sc.nextInt();
        }

        System.out.println(n - getLIS_2(n, x));
    }

    public static int getLIS(int n, int a[]) {

        int[] dp = new int[n + 1];
        Arrays.fill(dp, 0);

        int ans = 1;

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    public static int getLIS_2(int n, int a[]) {
        final int INF = Integer.MAX_VALUE;
        int dp[] = new int[n + 2];
        Arrays.fill(dp, INF);
        dp[0] = -INF;

        for (int i = 0; i < n; i++) {
            int x = a[i];
            int lower = 0;
            int upper = n + 1;
            int len = 1;
            while (lower < upper) {
                int mid = (lower + upper) / 2;
                if (dp[mid] > x) {
                    len = mid;
                    upper = mid;
                } else {
                    lower = mid + 1;
                }
            }
            dp[len] = x;
        }

        for (int i = n; i > 0; i--) {
            if (dp[i] != INF) {
                return i;
            }
        }
        return 1;
    }
}