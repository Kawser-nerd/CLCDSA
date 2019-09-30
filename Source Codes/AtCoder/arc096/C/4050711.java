import java.util.*;

public class Main{
	static long[] fact,ifact;
	static int fs=10000;
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long mod=sc.nextLong();
		
		fact=new long[fs];
		ifact=new long[fs];
		fact[0]=1;
		for(int i=1;i<fs;i++) fact[i]=i*fact[i-1]%mod;
		ifact[fs-1]=inv(fact[fs-1],mod);
		for(int i=fs-1;i>0;i--) ifact[i-1]=i*ifact[i]%mod;
		
		long[][] dp=new long[n+1][n+1];
		dp[1][1]=1;
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			dp[i][0]=1;
			for(int j=1;j<=n;j++)
				dp[i][j]=(dp[i-1][j]*(j+1)%mod+dp[i-1][j-1])%mod;
			//System.out.println(Arrays.toString(dp[i]));
		}
		
		long[] dp2=new long[n+1];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=i;j++){
				dp2[i]=(dp2[i]+dp[i][j]*modPow(2,(n-i)*j,mod)%mod);
				if(dp2[i]>mod)dp2[i]-=mod;
			}
			dp2[i]=(dp2[i]*modPow(2,modPow(2,n-i,mod-1),mod)%mod);
		}
		//System.out.println(Arrays.toString(dp2));
		long res=0;
		long sign=1;
		for(int i=0;i<=n;i++){
			res+=binom(n,i,mod)*sign*dp2[i]%mod;
			sign*=-1;
			res=(res%mod+mod)%mod;
		}
		System.out.println(res);
	}
	static HashMap<Long,Long> map=new HashMap<>();
	static long modPow(long a,long b,long mod){
		long res=1,c=a;
		while(b>0){
			if(b%2==1) res=(res*c)%mod;
			c=(c*c)%mod;
			b/=2;
		}
		return res;
	}
	static long binom(int a,int b,long mod){
		if(a<b)return 0;
		return fact[a]*ifact[a-b]%mod*ifact[b]%mod;
	}
	static long inv(long a,long mod){
		long b=mod;
		long p=1,q=0;
		while(b>0){
			long c=a/b;
			long d=a;
			a=b;
			b=d%b;
			d=p;
			p=q;
			q=d-c*q;
		}
		return (p+mod)%mod;
	}
}