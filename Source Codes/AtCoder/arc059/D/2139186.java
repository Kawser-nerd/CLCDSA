import java.util.*;
 
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int len = sc.next().length();
		long MOD = 1000000007;
		long[][] dp = new long[N+1][N+1];
		dp[0][0] = 1;
		
		for(int i=1;i<=N;i++){
			dp[i][0] = dp[i-1][0];
			if(i>=2) dp[i][0] += dp[i-1][1];
			dp[i][0] %= MOD;
			for(int j=1;j<=N;j++){
				dp[i][j] = dp[i-1][j-1]*2;
				if(j+2<=i) dp[i][j] += dp[i-1][j+1];
				while(dp[i][j]>=MOD) dp[i][j] -= MOD;
			}
		}
		
		long ans = dp[N][len];
		for(int i=0;i<len;++i){
			ans = (ans*500000004)%MOD;
		}
		System.out.println(ans);
		return;
	}
}