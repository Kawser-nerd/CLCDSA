import java.util.Scanner;

/**
 * http://abc017.contest.atcoder.jp/tasks/abc017_4
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int INF = 1000000007;
		final int N = sc.nextInt();
		final int M = sc.nextInt();
		int[] f = new int[N];
		for(int i=0; i<N; i++) f[i] = sc.nextInt();
		sc.close();
		
		int[] dp = new int[N+1];
		int[] sum = new int[N+1];
		int[] last = new int[M+1];
		dp[0] = 1;
		sum[0] = 1;
		int min=0;
		for(int i=1;i<=N;i++){
			min=Math.max(min, last[f[i-1]]);
			if(min>0){
				dp[i]=(sum[i-1]-sum[min-1]+INF)%INF;
			}else{
				dp[i]=sum[i-1];
			}
			sum[i]=(sum[i-1]+dp[i])%INF;
			last[f[i-1]]=i;
		}
		
		System.out.println(dp[N]);

	}

}