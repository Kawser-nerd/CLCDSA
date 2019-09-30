import java.util.*;

public class Main {
	final static long MOD = 1000000007;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.next().length();

		long[][] dp = new long[2][N+1];
		dp[0][0] = 1;
		long[] zero = new long[N+1];
		zero[0] = 1;
		for(int i=0; i<N; i++) {
			Arrays.fill(dp[(i+1)%2], 0);
			for(int j=0; j<=i; j++) {
				dp[(i+1)%2][j+1] = (dp[(i+1)%2][j+1] + dp[i%2][j]*2)%MOD;
				dp[(i+1)%2][Math.max(0, j-1)] = (dp[(i+1)%2][Math.max(0, j-1)] + dp[i%2][j])%MOD;
			}
			zero[i+1] = dp[(i+1)%2][0];
		}
		for(int i=0; i<=N; i++)
			for(int j=0; j<(N-i-M)/2; j++)
				zero[i] = (zero[i]*2)%MOD;
		
		for(int i=0; i<N; i++) {
			Arrays.fill(dp[(i+1)%2], 0);
			dp[i%2][0] = zero[i];
			for(int j=0; j<=i; j++) {
				dp[(i+1)%2][j+1] = (dp[(i+1)%2][j+1] + dp[i%2][j])%MOD;
				if(j-1>0)
					dp[(i+1)%2][j-1] = (dp[(i+1)%2][j-1] + dp[i%2][j])%MOD;
			}
		}
		
		System.out.println(dp[N%2][M]);
		
		sc.close();
	}
	
}