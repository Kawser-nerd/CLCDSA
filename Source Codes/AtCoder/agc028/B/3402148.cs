using System;
class Program{
	const int mod=1000000007;
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long ans=0,h=1;
		long[] d=new long[n];
		for(int i=1;i<n;i++){
			d[i]=(d[i-1]+1*mi(i+1))%mod;
			h=((i+1)*h)%mod;
		}
		for(int i=0;i<n;i++){ans+=((((d[n-i-1]+d[i]+1)*h)%mod)*s[i])%mod;}
		Console.WriteLine(ans%mod);
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