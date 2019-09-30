using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		long[] r=new long[501];
		r[0]=1;
		for(int i = 1;i<501;i++) {r[i]=(r[i-1]*i)%mod;}
		if(s[0]>s[1]){
			int q=s[0]+s[1]-1;
			Console.WriteLine("{0}",(r[q]*Mi((r[s[1]]*r[q-s[1]])%mod))%mod);
		}
		else{
			int q=s[1]%s[0];
			Console.WriteLine("{0}",(r[s[0]]*Mi((r[q]*r[s[0]-q])%mod))%mod);
		}
	}
	static long Mi(long a){
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

class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
}