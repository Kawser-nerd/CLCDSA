using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long[,] dp=new long[s[0]+1,s[0]+1];
		dp[0,0]=1;
		long[] f=new long[s[0]+1];
		f[0]=1;
		for(int i=1;i<=s[0];i++){f[i]=(f[i-1]*i)%mod;}
		for(int i=1;i<=s[0];i++){
			dp[i,0]=1;
			for(int j=1;j<=s[0];j++){
				dp[j,i]+=dp[j-1,i];
				if(s[1]<=j&&j<=s[2]){
					long q=1;
					for(int x=1;x<=i/j&&x<=s[4];x++){
						q=(((q*((f[i-j*(x-1)]*mi((f[j]*f[i-j*(x-1)-j])%mod))%mod))%mod)*mi(x))%mod;
						if(x>=s[3]){dp[j,i]=(dp[j,i]+((((dp[j-1,i-j*x]*q)%mod))%mod))%mod;}
					}
				}
			}
		}
		Console.WriteLine("{0}",dp[s[0],s[0]]);
	}
	static long mi(long a){
		long b=mod,u=1,v=0;
		while(b>0){
			long t=a/b;
			a-=t*b;a^=b;b^=a;a^=b;
			u-=t*v;u^=v;v^=u;u^=v;
		}
		u%=mod;
		if(u<0){u+=mod;}
		return u%mod;
	}
}