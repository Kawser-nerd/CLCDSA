import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long MOD = 1000000007;
		
		long[] dp = new long[N+1];
		dp[0] = 1;
		dp[1] = MOD-1;
		long cur = 0;
		for(int i=0; i<N; i++) {
			cur = (cur + dp[i])%MOD;
			
			if(i==N-1) {
				dp[N] = (dp[N] + cur*N)%MOD;
			} else {
				dp[i+1] = (dp[i+1] + cur)%MOD;
				dp[i+2] = (dp[i+2] - cur + MOD)%MOD;
				if(i+3<=N) {
					dp[i+3] = (dp[i+3] + cur)%MOD;
					dp[N] = (dp[N] + cur*(i+1))%MOD;
				} else {
					dp[N] = (dp[N] + cur*(N-1))%MOD;
				}
				dp[N] = (dp[N] + cur*((((long)N-1)*(N-1))%MOD))%MOD;
			}
		}
		
		System.out.println((cur + dp[N])%MOD);
		sc.close();
	}
}