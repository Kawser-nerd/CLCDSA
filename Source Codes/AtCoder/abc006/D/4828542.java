import java.util.*;

import static java.lang.Math.max;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] x = new int[n];

        for(int i=0; i<n; i++) {
            x[i] = sc.nextInt();
        }

        System.out.println(n - getLIS(n, x));
    }

    public static int getLIS(int n, int a[]) {

        int[] dp = new int[n+1];
        Arrays.fill(dp, 0);

        int ans = 1;

        for(int i=0; i<n; i++) {
            dp[i] = 1;
            for(int j=0; j<i; j++) {
                if (a[j] < a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
}