using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		int n=sc.I;
		double ans=double.MaxValue;
		int[][] a=new int[n][];
		a[0]=sc.Ia;
		for(int i=1;i<n;i++){
			a[i]=sc.Ia;
			ans=Math.Min(ans,Gp2(a[i-1][0],a[i-1][1],a[i][0],a[i][1],s[0],s[1]));
		}
		ans=Math.Min(ans,Gp2(a[0][0],a[0][1],a[n-1][0],a[n-1][1],s[0],s[1]));
		Console.WriteLine("{0}",ans);
	}
	static double Gp2(double p1x,double p1y,double p2x,double p2y,double p0x,double p0y){
		return Math.Abs((p2y-p1y)*p0x-(p2x-p1x)*p0y+p2x*p1y-p1x*p2y)/Math.Sqrt((p2y-p1y)*(p2y-p1y)+(p2x-p1x)*(p2x-p1x));
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