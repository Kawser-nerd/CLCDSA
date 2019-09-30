import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] a = new int[N];
		int[] b = new int[N+1];
		for(int i=0; i<N; i++) {
			a[i] = sc.nextInt();
			b[i+1] = b[i]+a[i];
		}
		
		if(b[N]==K) {
			System.out.println(1);
			sc.close();
			return;
		}
		
		int[][] dp = new int[N+1][N+1];
		for(int i=0; i<N+1; i++)
			Arrays.fill(dp[i], Integer.MAX_VALUE);
		
		dp[0][0] = 0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<=i; j++) {
				dp[i+1][j] = Math.min(dp[i+1][j], dp[i][j]);
				long x = i==0 ? 1 : (long)dp[i][j]*a[i]/b[i]+1;
				if(x<=a[i])
					dp[i+1][j+1] = Math.min(dp[i+1][j+1], dp[i][j]+(int)x);
			}
		}
		
		int ans = 0;
		for(int i=1; i<=N; i++)
			if(dp[N][i]<=K)
				ans = i;
		
		System.out.println(ans);
		sc.close();
	}
}