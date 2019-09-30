using System;
class Program{
	static long[] a;
	const int mod=1000000007;
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int k=int.Parse(Console.ReadLine());
		a=new long[n+k];
		a[0]=1;
		for(int i=1;i<n+k;i++){a[i]=a[i-1]*i%mod;}
		Console.WriteLine((a[n+k-1]*rk(a[n-1]*a[(n+k-1)-(n-1)]%mod,mod-2))%mod);
	}
	public static long rk(long a,long b){
		long sum=1;
		while(b>0){
			if((b&1)==1){sum*=a;sum%=mod;}
			a*=a;a%=mod;
			b>>=1;
		}
		return sum%mod;
	}
}