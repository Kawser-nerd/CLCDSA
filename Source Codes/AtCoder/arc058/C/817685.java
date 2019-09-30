import java.util.*;

public class Main {
	static final long MOD = 1000000007;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();
		int Z = sc.nextInt();
		
		int L = X+Y+Z;
		int match = 1<<(X+Y+Z-1) | 1<<(Y+Z-1) | 1<<(Z-1);
		int mask = (1<<(L-1))-1;
		
		long[][] dp = new long[N+1][1<<(L-1)];
		dp[0][0] = 1;
		for(int i=0; i<N; i++) {
			for(int j=0; j<=mask; j++) {
				for(int k=1; k<=10; k++) {
					int next = j<<k | 1<<(k-1);
					if(((next&((1<<L)-1))&match)!=match) {
						dp[i+1][next&mask] = (dp[i+1][next&mask] + dp[i][j])%MOD;
					}
				}
			}
		}
		
		long ans = 1;
		for(int i=0; i<N; i++)
			ans = (ans * 10)%MOD;
		for(int i=0; i<1<<(L-1); i++)
			ans = (ans + MOD - dp[N][i])%MOD;
		
		System.out.println(ans);
		sc.close();
	}
	
}