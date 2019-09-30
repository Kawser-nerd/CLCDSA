import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();

        long[][] dp = new long[S.length() + 1][4];
        long prime = 1000000007;
        dp[0][0] = 1;
        for (int i = 1; i <= S.length(); i++) {
            for (int j = 0; j < 4; j++) {
                dp[i][j] = dp[i - 1][j];
                dp[i][j] %= prime;
            }
            if (S.charAt(i - 1) == 'A') {
                dp[i][1] += dp[i - 1][0];
                dp[i][1] %= prime;
            } else if (S.charAt(i - 1) == 'B') {
                dp[i][2] += dp[i - 1][1];
                dp[i][2] %= prime;
            } else if (S.charAt(i - 1) == 'C') {
                dp[i][3] += dp[i - 1][2];
                dp[i][3] %= prime;
            } else {
                for (int j = 0; j < 4; j++) {
                    dp[i][j] += 2 * dp[i - 1][j];
                    dp[i][j] %= prime;
                }
                dp[i][1] += dp[i - 1][0];
                dp[i][2] += dp[i - 1][1];
                dp[i][3] += dp[i - 1][2];
                dp[i][1] %= prime;
                dp[i][2] %= prime;
                dp[i][3] %= prime;
            }
        }

        out.println(dp[S.length()][3]);
    }
}