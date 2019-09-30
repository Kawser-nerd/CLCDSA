using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I,m=0;
		List<int> li=new List<int>(n);
		for(int i = 0;i<n;i++) {
			int q=sc.I;
			m=Math.Max(m,q);
			if(i==0||li[li.Count-1]!=q){li.Add(q);}
		}
		m++;
		n=li.Count;
		int[] h=new int[m];
		int[] b=new int[m];
		int[] r1=new int[n];
		int k=0;
		for(int i = 0;i<n;i++) {
			h[li[i]]++;
			r1[i]=r1[i!=0?i-1:0];
			if(h[li[i]]>=2){
				k++;
				r1[i]=(r1[i]+1+r1[b[li[i]]])%mod;
			}
			b[li[i]]=i;
		}
		Console.WriteLine("{0}",(r1[n-1]+1)%mod);
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