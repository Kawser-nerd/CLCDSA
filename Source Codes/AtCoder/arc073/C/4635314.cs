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
		long[][] a=new long[n][];
		long c=int.MaxValue,d=0,e=0;
		for(int i = 0;i<n;i++) {
			a[i]=sc.La;
			if(a[i][0]>a[i][1]){a[i][0]^=a[i][1];a[i][1]^=a[i][0];a[i][0]^=a[i][1];}
			c=Math.Min(c,a[i][1]);
			e=Math.Max(e,a[i][1]);
		}
		Array.Sort(a,Ca);
		long ans=(a[n-1][0]-a[0][0])*(e-c);
		c=a[0][1];
		d=a[0][1];
		for(int i = 1;i<n;i++) {
			ans=Math.Min(ans,(e-a[0][0])*(Math.Max(d,a[n-1][0])-Math.Min(c,a[i][0])));
			c=Math.Min(c,a[i][1]);
			d=Math.Max(d,a[i][1]);
		}
		Console.WriteLine(ans);
	}
	static int Ca(long[] a,long[] b){
		if(a[0]>b[0]){return 1;}
		else if(a[0]<b[0]){return -1;}
		else if(a[1]>b[1]){return 1;}
		else if(a[1]<b[1]){return -1;}
		else{return 0;}
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