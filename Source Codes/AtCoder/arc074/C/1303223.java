import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		final long MOD = 1000000007;
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] l = new int[M];
		int[] r = new int[M];
		int[] x = new int[M];
		for(int i=0; i<M; i++) {
			l[i] = sc.nextInt()-1;
			r[i] = sc.nextInt();
			x[i] = sc.nextInt();
		}
		
		long[][][] dp = new long[2][N+1][N+1];
		dp[0][0][0] = 1;

		for(int i=0; i<N; i++) {
			for(int j=0; j<N+1; j++)
				Arrays.fill(dp[(i+1)%2][j], 0);
			int[] lenmin = new int[3];
			int[] lenmax = new int[3];
			Arrays.fill(lenmax, 10000);
			for(int j=0; j<M; j++) {
				if(l[j]<=i && i+1==r[j]) {
					if(x[j]<3)
						lenmin[x[j]] = Math.max(lenmin[x[j]], i+1-l[j]);
					if(x[j]>1)
						lenmax[x[j]-1] = Math.min(lenmax[x[j]-1], i+1-l[j]);
				}
			}
			
			for(int j=0; j<=i; j++) {
				for(int k=j==i ? j : j+1; k<=i; k++) {
					if(lenmin[1]<=j+1 && j+1<lenmax[1] && lenmin[2]<=k+1 && k+1<lenmax[2])
						dp[(i+1)%2][j+1][k+1] = (dp[(i+1)%2][j+1][k+1] + dp[i%2][j][k])%MOD;
					if(0<i && lenmin[1]<=1 && 1<lenmax[1] && lenmin[2]<=k+1 && k+1<lenmax[2])
						dp[(i+1)%2][1][k+1] = (dp[(i+1)%2][1][k+1] + dp[i%2][j][k])%MOD;
					if(j<i && lenmin[1]<=1 && 1<lenmax[1] && lenmin[2]<=j+1 && j+1<lenmax[2])
						dp[(i+1)%2][1][j+1] = (dp[(i+1)%2][1][j+1] + dp[i%2][j][k])%MOD;
				}
			}
		}
		
		long ans = 0;
		for(int i=0; i<=N; i++) {
			for(int j=i+1; j<=N; j++) {
				ans = (ans + dp[N%2][i][j]*6)%MOD;
			}
		}
		ans = (ans + dp[N%2][N][N]*3)%MOD;
		System.out.println(ans);
		sc.close();
	}
}