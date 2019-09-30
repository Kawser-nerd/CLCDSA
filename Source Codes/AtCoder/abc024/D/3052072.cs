using System;
class Program{
	const int mod=1000000007;
	static void Main(){
		long a=long.Parse(Console.ReadLine());
		long b=long.Parse(Console.ReadLine());
		long c=long.Parse(Console.ReadLine());
		
		Console.WriteLine("{0} {1}",((((((b*c)%mod)-((a*c)%mod))+mod)%mod)*mi((((((a*b)%mod)-((b*c)%mod))+mod)%mod)+((a*c)%mod))%mod)%mod,((((((b*c)%mod)-((a*b)%mod))+mod)%mod)*mi((((((a*c)%mod)-((b*c)%mod))+mod)%mod)+((a*b)%mod))%mod)%mod);
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