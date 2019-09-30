import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		sc.close();
		int n = S.length();
		long mod = (long)Math.pow(10, 9) + 7;
		long[][] dp = new long[n + 1][4];
		dp[0][0] = 1;
		for(int i = 1; i <= n; i++) {
			char c = S.charAt(i - 1);
			for(int j = 0; j < 4; j++) {
				dp[i][j] = dp[i - 1][j];
				dp[i][j] %= mod;
				if(c == '?') {
					dp[i][j] *= 3;
				}
			}
			if(c == '?') {
				for(int j = 1; j < 4; j++) {
					dp[i][j] += dp[i - 1][j - 1];
				}
			}else {
				dp[i][(int)(c - 'A') + 1] += dp[i - 1][(int)(c - 'A')];
			}
		}
		System.out.println(dp[n][3] % mod);
	}
}