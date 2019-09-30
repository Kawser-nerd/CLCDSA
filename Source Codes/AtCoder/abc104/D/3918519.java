import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char[] s = scanner.next().toCharArray();
        int n = s.length;
        long dp[][] = new long[n + 1][4];
        for (int i = 0; i <= 3; i++) {
            dp[n][i] = i == 3 ? 1 : 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 3; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j] * (s[i] == '?' ? 3L : 1L);
                if (j < 3 && (s[i] == '?' || s[i] == "ABC".toCharArray()[j])) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
                dp[i][j] %= 1_000_000_007L;
            }
        }
        System.out.println(dp[0][0]);
    }
}