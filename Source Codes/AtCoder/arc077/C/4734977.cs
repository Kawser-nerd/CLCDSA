using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		int[] a=sc.Ia;
		long ans=0,m=0;
		long[] h1=new long[s[1]+2];
		long[] h2=new long[s[1]+2];
		for(int i = 1;i<s[0];i++) {
			ans+=(s[1]+a[i]-a[i-1])%s[1];
			if((s[1]+a[i]-a[i-1])%s[1]<2){continue;}
			int q=((a[i-1]+1)%s[1])+1;
			h1[q]++;
			h1[a[i]+1]--;
			h2[a[i]+1]-=(s[1]+a[i]-a[i-1]-1)%s[1];
			if(q>a[i]){
				h1[1]++;
				h2[1]+=s[1]-a[i-1]-1;
			}
		}
		for(int i = 1;i<=s[1];i++) {
			h1[i]+=h1[i-1];
			h2[i]+=h1[i]+h2[i-1];
			m=Math.Max(m,h2[i]);
		}
		Console.WriteLine(ans-m);
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