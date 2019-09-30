import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long answer = 0;
		long[][] dp = new long[n+1][4];
		dp[1] = new long[]{1, 1, 1, 1};
		dp[2] = new long[]{4, 4, 4, 4};
		dp[3] = new long[]{16, 14, 15, 16};
		if(n >= 4) {
			for(int i = 4; i <= n; i++) {
				long sum = 0;
				for(int j = 0; j < 4; j++) {
					sum += dp[i-1][j];
				}
				sum %= 1000000007;
				//A and T
				dp[i][0] = sum;
				dp[i][3] = sum;
				//C
				dp[i][1] = sum - dp[i-2][0] -dp[i-2][2] - dp[i-3][0]*3;
				//G
				dp[i][2] = sum - dp[i-2][0] + dp[i-3][2];
				sum = 0;
			}
		}
		for(int j = 0; j < 4; j++) {
			answer += dp[n][j];
		}
		answer %= 1000000007;
		System.out.println(answer);
	}

}