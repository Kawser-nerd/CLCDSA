import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int w = sc.nextInt();
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[][] dp=new int[k+1][w+1];
		int max=0;
		for(int i = 1; i<=n; i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			for(int j = Math.min(i,k); j>=1; j--){
				for(int l = 1; l<=w; l++){
					if(l>=a){
						if(j>=2 && dp[j-1][l-a]!=0){
							dp[j][l]=Math.max(dp[j][l],dp[j-1][l-a]+b);
							max=Math.max(max,dp[j][l]);
						}
						if(j==1){
							dp[j][l]=Math.max(dp[j][l],dp[j-1][l-a]+b);
							max=Math.max(max,dp[j][l]);
						}
					}
				}
			}
		}
		System.out.println(Math.max(dp[k][w],max));
	}
}