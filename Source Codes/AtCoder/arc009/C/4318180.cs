using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
static class Program{
	const int mod=1777777777;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		long[] s=sc.La;
		long[] k=new long[s[1]+1];
		k[2]=1;
		s[0]%=mod;
		for(int i=3;i<=s[1];i++){k[i]=((i-1)*(k[i-1]+k[i-2]))%mod;}
		Console.WriteLine((Cb(s[0],s[1])*k[s[1]])%mod);
	}
	static long Cb(long n,long k){
		long l=1;
		for(int i=1;i<=k;i++){
			l=(l*(n-i+1))%mod;
			l=(l*Mi(i))%mod;
		}
		return l;
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

public class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}