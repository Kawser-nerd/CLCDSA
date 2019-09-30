using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static int n;
	static void Main(){
		Sc sc=new Sc();
		n=sc.I;
		int[] a=new int[n];
		for(int i = 0;i<n;i++) {a[i]=sc.I;}
		Array.Sort(a);
		long q=0,p=1,k=1,ans=0,b=1,r=0;
		for(int i = 0;i<n;i++) {
			r+=a[i];
			ans+=r;
			if(q==a[i]){
				p++;
				k=(k*p)%mod;
			}
			else{
				b=(b*k)%mod;
				p=1;
				k=1;
			}
			q=a[i];
		}
		Console.WriteLine("{0}",ans);
		Console.WriteLine("{0}",(b*k)%mod);
	}
}

public class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public int[] Ia2{get{return Array.ConvertAll((Console.ReadLine()+" 0").Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}