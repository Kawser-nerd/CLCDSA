using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I,ans=0;
		int[][] a=new int[n][];
		for(int i = 0;i<n;i++) {
			a[i]=new int[]{sc.I,i};
		}
		Array.Sort(a,(u,v)=>u[0]-v[0]);
		for(int i = 0;i<n;i++) {
			if(i%2!=a[i][1]%2){ans++;}
		}
		Console.WriteLine("{0}",ans/2);
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
	public string[] Sa{get{return Console.ReadLine().Split();}}
}