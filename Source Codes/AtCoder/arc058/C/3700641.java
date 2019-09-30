import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int x=sc.nextInt(),y=sc.nextInt(),z=sc.nextInt();
		
		long mod=1000000007;
		
		long res=0;
		
		long[][] dp=new long[n][1<<17];
		for(int i=1;i<=10;i++){
			dp[0][1<<(i-1)]=1;
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=10;j++){
				for(int k=1;k<1<<17;k++){
					int bit=((k<<j)+(1<<(j-1)))%(1<<17);
					if(((bit & (1<<(x-1)))>0) && ((bit & (1<<((x+y)-1)))>0) && ((bit & (1<<((x+y+z)-1)))>0)) continue;
					dp[i][bit]=(dp[i][bit]+dp[i-1][k])%mod;
				}
			}
		}
		res=modPow(10,n,mod);
		for(int i=1;i<1<<17;i++) res=(res-dp[n-1][i]+mod)%mod;
		pl(res);
	}
	static void pl(Object o){System.out.println(o);}
	static long modPow(long a,long b,long mod){
		long res=1;
		long c=a;
		while(b>0){
			if(b%2==1)res=(res*c)%mod;
			c=(c*c)%mod;
			b/=2;
		}
		return res;
	}
}