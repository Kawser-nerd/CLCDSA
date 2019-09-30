import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sn = new Scanner(System.in);
		int N = sn.nextInt();
		int K = sn.nextInt();
		if(N > K){
			System.out.println(nCr(N+K-1,K));
			return;
		}
		int c = K%N;
		int r = N - c;		
		System.out.println(nCr(N,r));
	}
	public static long nCr(int n, int r){
		long M = 1000000007L;
		long dp[][] = new long[502][502];
		for(int i = 0; i < 502; ++i){		
			for(int j = 0; j < 502; ++j){
				dp[i][j] = 0;
			}
		}
		dp[0][0] = 1;		
		for(int i = 1; i <= n; ++i){
			dp[i][0] = 1;
			for(int j = 1; j <= i+1; ++j){
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%M;
			}
		}
		return dp[n][r];
	}
}