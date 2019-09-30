import java.util.*;

public class Main {
	static final long MOD = 1000000007;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		final int MAX = 2000;
		
		int[] A = new int[N];
		int[] B = new int[N];
		for(int i=0; i<N; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
		}
		
		int[][] dp = new int[MAX*2+1][MAX*2+1];
		for(int i=0; i<N; i++)
			dp[MAX-A[i]][MAX-B[i]]++;
		for(int i=0; i<=MAX*2; i++) {
			for(int j=0; j<=MAX*2; j++) {
				if(i<MAX*2)
					dp[i+1][j] = (int)((dp[i+1][j] + dp[i][j])%MOD);
				if(j<MAX*2)
					dp[i][j+1] = (int)((dp[i][j+1] + dp[i][j])%MOD);
			}
		}
		long sum = 0;
		for(int i=0; i<N; i++)
			sum = (sum + dp[MAX+A[i]][MAX+B[i]])%MOD;
		
		init(MAX*4);
		for(int i=0; i<N; i++)
			sum = (sum - comb(A[i]*2+B[i]*2, A[i]*2) + MOD)%MOD;
		
		System.out.println(sum*rev[2]%MOD);
		
		sc.close();
	}
	
	static long fac[],rev[],revfac[];
	
	static void init(int N) {
		fac = new long[N+1];
		rev = new long[N+1];
		revfac = new long[N+1];
		fac[0] = 1;
		rev[0] = 0;
		revfac[0] = 1;
		for(int i=1; i<=N; i++) {
			fac[i] = fac[i-1]*i%MOD;
			rev[i] = pow(i, MOD-2);
			revfac[i] = pow(fac[i], MOD-2);
		}
	}
	static int pow(long a, long b) {
		long ans = 1;
		while(b>0) {
			if((b&1)!=0)
				ans = (ans * a)%MOD;
			a = (a * a)%MOD;
			b>>=1;
		}
		return (int)ans;
	}
	static long comb(int a, int b) {
		if(a<0 || b<0 || a<b)
			return 0;
		return (((fac[a]*revfac[a-b])%MOD)*revfac[b])%MOD;
	}
	
}