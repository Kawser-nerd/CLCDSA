using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I,m=0;
		long ans=1;
		int[] a=sc.Ia;
		int[] h=new int[n+1];
		long[] r2=new long[n+1];
		long[] c=new long[n+1];
		h[a[0]]++;
		for(int i=1;i<n;i++){
			h[a[i]]++;
			m=Math.Max(m,a[i]);
		}
		r2[0]=1;
		long b=1;
		for(int i=1;i<n;i++){
			r2[i]=(r2[i-1]*b)%mod;
			b=(b+b)%mod;
			c[i]=(mod+b-1)%mod;
		}
		r2[0]=0;
		for(int i=1;i<=m;i++){
			ans=(ans*r2[h[i]])%mod;
			for(int j=0;j<h[i];j++){ans=(ans*c[h[i-1]])%mod;}
		}
		Console.WriteLine((h[0]==1&&a[0]==0)?ans:0);
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