using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		int[] a=sc.Ia2;
		long[] r=new long[n+1];
		var hs=new Dictionary<long,int>();
		long ans=0;
		hs.Add(0,1);
		for(int i = 1;i<=n;i++) {
			r[i]=r[i-1]+a[i];
			if(hs.ContainsKey(r[i])){ans+=hs[r[i]];hs[r[i]]++;}
			else{hs.Add(r[i],1);}
		}
		Console.WriteLine("{0}",ans);
	}
}

public class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public int[] Ia2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}