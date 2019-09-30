import java.util.*;
import java.awt.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            d[i] = sc.nextInt();
        }
        long m = 1000000007;

        Arrays.sort(d);

        int[] two = new int[n];
        for (int i = n-1; i > 0; i--) {
            int j = i-1;
            while (true) {
                if (j < 0) {
                    two[i] = -1;
                    break;
                }
                if (d[j] * 2 <= d[i]) {
                    two[i] = j;
                    break;
                } else {
                    j--;
                }
            }
        }

        long[][] dp = new long[n][4];
        dp[0][0] = 1;

        for (int i = 1; i < n; i++) {
            dp[i][0] = (dp[i-1][0] + 1) % m;
            if (two[i] != -1) {
                dp[i][1] = (dp[i-1][1] + dp[two[i]][0]) % m;
                dp[i][2] = (dp[i-1][2] + dp[two[i]][1]) % m;
                dp[i][3] = (dp[i-1][3] + dp[two[i]][2]) % m;
            }
        }

        System.out.println(dp[n-1][3]);
    }
}