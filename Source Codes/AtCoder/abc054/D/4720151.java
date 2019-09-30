import java.util.Scanner;
import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		int ma = sc.nextInt();
		int mb = sc.nextInt();
		int[][] dp=new int[401][401];
		for(int i = 0; i<401; i++){
			Arrays.fill(dp[i],Integer.MAX_VALUE);
		}
		dp[0][0]=0;
		for(int i = 0; i<n; i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			for(int j=400; j>=a; j--){
				for(int k =400; k>=b; k--){
					if(dp[j-a][k-b]!=Integer.MAX_VALUE){
						dp[j][k]=Math.min(dp[j][k],c+dp[j-a][k-b]);
					}
				}
			}
		}
		int ans=Integer.MAX_VALUE;
		for(int i = 1; 401>Math.max(ma,mb)*i; i++){
			if(dp[ma*i][mb*i]!=Integer.MAX_VALUE){
				ans=Math.min(ans,dp[ma*i][mb*i]);
			}
		}
		if(ans==Integer.MAX_VALUE){
			System.out.println(-1);
		}else{
			System.out.println(ans);
		}
	}
}