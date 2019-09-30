import java.util.*;

public class Main {
	final static long MOD = 1000000007;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.next().length();

		long[][] dp = new long[2][N+1];
		dp[0][0] = 1;
		for(int i=0; i<N; i++) {
			Arrays.fill(dp[(i+1)%2], 0);
			for(int j=0; j<=i; j++) {
				dp[(i+1)%2][j+1] = (dp[(i+1)%2][j+1] + dp[i%2][j]*2)%MOD;
				dp[(i+1)%2][Math.max(0, j-1)] = (dp[(i+1)%2][Math.max(0, j-1)] + dp[i%2][j])%MOD;
			}
		}
		long ans = dp[N%2][M];
		long div2 = (MOD+1)/2;
		for(int i=0; i<M; i++)
			ans = (ans * div2)%MOD;
		
		System.out.println(ans);
		
		sc.close();
	}
	
}