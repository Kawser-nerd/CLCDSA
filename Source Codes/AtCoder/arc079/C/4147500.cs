using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		long[] a=sc.La;
		long ans=0;
		bool b=true;
		while(b){
			long p=0;
			for(int i = 0;i<n;i++) {
				long q=Math.Max((a[i]-(n-1)),0)/n+(Math.Max((a[i]-(n-1)),0)%n==0?0:1);
				a[i]-=q*n+q;
				p+=q;
			}
			b=false;
			for(int i = 0;i<n;i++) {
				a[i]+=p;
				if(a[i]>=n){b=true;}
			}
			ans+=p;
		}
		Console.WriteLine(ans);
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