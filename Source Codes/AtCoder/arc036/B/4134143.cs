using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		int ans=1,b=0,c=0,d=0;
		int[] a=new int[n+1];
		a[1]=sc.I;
		for(int i=2;i<=n;i++){
			a[i]=sc.I;
			if(a[i-1]<a[i]){
				if(d!=1){
					b=0;c=0;
				}
				d=1;
				b++;
			}
			else{
				d=2;
				c++;
			}
			ans=Math.Max(ans,b+c+1);
		}
		Console.WriteLine("{0}",ans);
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