using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static List<int>[] li;
	static bool[] b;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		li=new List<int>[s[0]+1];
		b=new bool[s[0]+1];
		int ans=0;
		for(int i=1;i<=s[0];i++){li[i]=new List<int>();}
		for(int i=0;i<s[1];i++){
			int[] q=sc.Ia;
			li[q[0]].Add(q[1]);
			li[q[1]].Add(q[0]);
		}
		for(int i=1;i<=s[0];i++){
			if(!b[i]){ans+=Fu(i,1,0);}
		}
		Console.WriteLine("{0}",ans);
	}
	static int Fu(int a,int p,int m){
		if(b[a]){return 0;}
		b[a]=true;
		for(int i=0;i<li[a].Count;i++){
			if(li[a][i]!=m){p=Fu(li[a][i],p,a);}
		}
		return p;
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