import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		
		long mod=1000000007;
		
		long[] dp=new long[2*n+2];
		dp[0]=1;
		dp[1]=1;
		long sum=2;
		for(int i=2;i<dp.length;i++){
			dp[i]=(sum-dp[i-2]+mod)%mod;
			sum=(sum+dp[i])%mod;
		}
		
		long res=0;
		for(int i=0;i<n-1;i++){
			res=(res+dp[i]*(n-1)%mod*(n-1)%mod)%mod;
		}
		res=(res+dp[n-1]*(n-1)%mod)%mod;
		
		for(int i=0;i<n-1;i++){
			long coef=i+2;
			if(i==n-2) coef--;
			res=(res+dp[i]*coef%mod)%mod;
		}
		res=(res+dp[n-1])%mod;
		
		System.out.println(res);
	}
}