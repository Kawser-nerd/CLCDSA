using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	const long o=1;
	static int ans=0,m,l,q=0;
	static int[] a,b,ar;
	static Dictionary<int,int> hs=new Dictionary<int,int>();
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		m=s[0]/2;
		l=s[0]-m;
		a=new int[m];
		b=new int[s[0]-m];
		for(int i = 0;i<m;i++) {a[i]=sc.I;}
		for(int i = m;i<s[0];i++) {b[i-m]=sc.I;}
		ar=new int[o<<m];
		Fu1(-1,0);
		Fu2(-1,0);
		for(int i = 0;i<q;i++) {
			if(hs.ContainsKey(s[1]-ar[i])){ans+=hs[s[1]-ar[i]];}
		}
		Console.WriteLine("{0}",ans);
	}
	static void Fu1(int n,int p){
		for(int i = n+1;i<m;i++) {Fu1(i,p+a[i]);}
		ar[q]=p;
		q++;
	}
	static void Fu2(int n,int p){
		for(int i = n+1;i<l;i++) {Fu2(i,p+b[i]);}
		if(hs.ContainsKey(p)){hs[p]++;}
		else{hs.Add(p,1);}
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