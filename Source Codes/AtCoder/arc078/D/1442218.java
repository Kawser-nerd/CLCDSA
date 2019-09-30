import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		int[][] dp=new int [1<<20][20];
		Scanner sc=new Scanner(System.in);
		int n=(int) sc.nextLong();
		int m=sc.nextInt();
		int sum=0;
		int distance[][]=new int[n][n];
		for (int i = 0; i < m; i++) {
			int u=sc.nextInt();
			int v=sc.nextInt();
			int c=sc.nextInt();
			u--;v--;
			distance[u][v]=c;
			distance[v][u]=c;
			sum+=c;
		}
		int [] s=new int[1<<n];
		for (int i = 1; i <=1<<n; i++) {
			for (int j = 0; j <n; j++) {
				for (int k = j+1; k <n; k++) {
					if((i>>j)%2==1&&(i>>k)%2==1)
					{
						s[i]+=distance[j][k];
					}
				}
			}
			
		}
		//System.out.println(Arrays.toString(s));
		for (int i = 0; i <= 1<<n; i++) {
			Arrays.fill(dp[i], -1);
		}
		dp[1][0]=0;
		for (int i = 0; i <(1<<n); i++) {
			for (int j = 0; j <n; j++) {
				if(dp[i][j]==-1)
					continue;
				for (int k = 0; k < n; k++) {					
					if((i>>k)%2==1||distance[j][k]==0)
						continue;
					dp[i|(1<<k)][k]=Math.max(dp[i|(1<<k)][k], dp[i][j]+distance[j][k]);
						
				}
				int x=(1<<n)-1-i;
				for (int y=x;y>=1;y=(y-1)&x)
					dp[i|y][j]=Math.max(dp[i|y][j],dp[i][j]+s[y|(1<<j)]);
			}
		}
		System.out.println(sum-dp[(1<<n)-1][n-1]);
	
	}

}