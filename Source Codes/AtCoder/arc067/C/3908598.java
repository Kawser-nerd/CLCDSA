import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a=sc.nextInt(), b=sc.nextInt(),c=sc.nextInt(),d=sc.nextInt();
		long mod=1000000007;
		
		long[] fact=new long[1010];
		fact[0]=1;
		for(int i=1;i<fact.length;i++) fact[i]=(fact[i-1]*i)%mod;
		long[] ifact=new long[1010];
		ifact[1009]=inv(fact[1009],mod);
		for(int i=1009;i>0;i--) ifact[i-1]=(ifact[i]*i)%mod;
		
		long res=0;
		
		long[][] dp=new long[b+1][n+1];
		dp[b][0]=1;
		for(int i=b;i>=a;i--){
			if(i==b){
				for(int j=c;j<=d && j*b<=n;j++){
					dp[b][j*b]=fact[j*b]*modPow(ifact[b],j,mod)%mod*ifact[j]%mod;
				}
			}else{
				for(int j=0;j<=n;j++){
					dp[i][j]=dp[i+1][j];
					for(int k=c;k<=d && (j-i*k)>=0;k++){
						dp[i][j]+=dp[i+1][j-i*k]*fact[j]%mod*modPow(ifact[i],k,mod)%mod*ifact[j-i*k]%mod*ifact[k]%mod;
						dp[i][j]%=mod;
					}
				}
			}
			//System.out.println(Arrays.toString(dp[i]));
		}
		System.out.println(dp[a][n]);
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
	public static long inv(long a,long mod){
		long b=mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d=a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}
}