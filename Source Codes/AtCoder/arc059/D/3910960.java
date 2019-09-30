import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		String s=sc.next();
		int m=s.length();
		long mod=1000000007;
		
		long[] dp=new long[m+n+5];
		long[] ndp=new long[m+n+5];
		for(int i=0;i<=n;i++){
			if(i==0){
				ndp[0]=1;
			}else{
				ndp[0]=dp[0]+dp[1];
				for(int j=1;j<m+n+5-i;j++){
					ndp[j]=dp[j-1]*2%mod+dp[j+1];
					ndp[j]%=mod;
				}
			}
			long[] nndp=dp;
			dp=ndp;
			ndp=nndp;
		}
		System.out.println(dp[m]*modPow(inv(2,mod),m,mod)%mod);
	}
	static long modPow(long a,long b,long mod){
		long res=1;
		long c=a;
		while(b>0){
			if(b%2==1) res=(res*c)%mod;
			c=(c*c)%mod;
			b/=2;
		}
		return res;
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
		return p<0?p+mod:p;
	}
}