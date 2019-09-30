import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long[][] dp=new long[n][3];
		long a0=sc.nextLong();
		dp[0][0]=a0;
		dp[0][1]=Long.MIN_VALUE/10;
		dp[0][2]=Long.MIN_VALUE/10;
		for(int i=1;i<n;i++){
			String str=sc.next();
			long v=sc.nextLong();
			if(str.equals("+")){
				dp[i][0]=Math.max(Math.max(dp[i-1][0]+v,dp[i-1][1]+v),dp[i-1][2]+v);
				dp[i][1]=Math.max(dp[i-1][1]-v,dp[i-1][2]+v);
				dp[i][2]=dp[i-1][2]+v;
			}else{
				dp[i][0]=Math.max(Math.max(dp[i-1][0]-v,dp[i-1][1]+v),dp[i-1][2]+v);
				dp[i][1]=Math.max(Math.max(dp[i-1][0]-v,dp[i-1][1]+v),dp[i-1][2]+v);
				dp[i][2]=Math.max(dp[i-1][1]+v,dp[i-1][2]+v);
			}
		}
		System.out.println(dp[n-1][0]);
	}
}