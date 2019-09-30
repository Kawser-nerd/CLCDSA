using System;
class Program{
	static void Main(){
		const int mod=1000000007;
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long[] x=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long[] y=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long ans=0,w=0,v=0;
		for(int i=1;i<s[0];i++){
			ans=(ans+((x[i]-x[i-1])%mod)*i+w)%mod;
			w=(w+((x[i]-x[i-1])%mod)*i)%mod;
		}
		v=ans;
		ans=(ans*(y[1]-y[0]))%mod;
		w=ans;
		for(int i=2;i<s[1];i++){
			ans=(ans+((((y[i]-y[i-1])%mod)*v)%mod)*i+w)%mod;
			w=(w+((((y[i]-y[i-1])%mod)*v)%mod)*i)%mod;
		}
		Console.WriteLine(ans);
	}
}