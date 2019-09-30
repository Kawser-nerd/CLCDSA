import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);
		int N=scan.nextInt();
		int M=scan.nextInt();


		long dp[]=new long[N+1];
		long sum[]=new long[N+1];
		int[] last = new int[M+1];
		final int INF = 1000000007;
		dp[0]=1;
		sum[0]=1;
		int min=0;
		int f;
		for(int i=1;i<=N;i++){
			f=scan.nextInt();
			min=Math.max(min, last[f]);
			if(min>0){
				dp[i]=(sum[i-1]-sum[min-1]+INF)%INF;
			}else{
				dp[i]=sum[i-1];
			}

			sum[i]=(sum[i-1]+dp[i])%INF;
			last[f]=i;
		}
		System.out.println(dp[N]%INF);



	}

}