using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static List<int>[] li;
	static int[] h,ans;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		li=new List<int>[s[0]+1];
		h=Enumerable.Repeat(-1,s[0]+1).ToArray();
		ans=new int[s[0]];
		for(int i=1;i<=s[0];i++){li[i]=new List<int>();}
		for(int i=0;i<s[1];i++){
			int[] e=sc.Ia;
			li[e[0]].Add(e[1]);
			li[e[1]].Add(e[0]);
		}
		int q=sc.I;
		int[][] a=new int[q][];
		for(int i = 0;i<q;i++) {a[i]=sc.Ia;}
		for(int i = q-1;i>=0;i--) {Fu(a[i][0],a[i][1],a[i][2]);}
		Console.WriteLine(String.Join("\n",ans));
	}
	static void Fu(int a,int g,int c){
		if(h[a]<g){h[a]=g;}
		if(ans[a-1]==0){ans[a-1]=c;}
		if(g==0){return;}
		for(int i=0;i<li[a].Count;i++){
			if(h[li[a][i]]<g-1){Fu(li[a][i],g-1,c);}
		}
	}
}
public class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public int[] Ia2{get{return Array.ConvertAll(("0 "+Console.ReadLine()+" 0").Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}