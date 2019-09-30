import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		long mod=1000000007;
		long[][] dp=new long[n+1][n+1];
		dp[0][0]=1;
		String str=sc.next()+'1';
		int ind=0,ri=0;
		int zs=0;
		for(int i=0;i<=m;i++){
			int l=(i==m)?n:sc.nextInt()-1,r=(i==m)?n:sc.nextInt()-1;
			while(ind<l){
				for(int j=0;j<=ind;j++){
					if((ind==ri) && str.charAt(ri++)=='0') zs++;
					if((j+1)<=zs)dp[ind+1][j+1]=dp[ind][j];
					if((ind+1-j)<=(ri-zs))dp[ind+1][j]=(dp[ind+1][j]+dp[ind][j])%mod;
				}
				ind++;
			}
			while(ri<=r) if(str.charAt(ri++)=='0') zs++;
		}
		System.out.println(dp[n][zs]);
	}
}