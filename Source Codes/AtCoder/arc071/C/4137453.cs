using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		string s=sc.S,t=sc.S;
		int[] sn=new int[s.Length+1];
		int[] tn=new int[t.Length+1];
		for(int i=1;i<=s.Length;i++){sn[i]=s[i-1]=='A'?sn[i-1]+1:sn[i-1];}
		for(int i=1;i<=t.Length;i++){tn[i]=t[i-1]=='A'?tn[i-1]+1:tn[i-1];}
		int n=sc.I;
		string[] ans=new string[n];
		for(int i = 0;i<n;i++) {
			int[] q=sc.Ia;
			ans[i]=((3+((sn[q[1]]-sn[q[0]-1])%3)-((tn[q[3]]-tn[q[2]-1])%3))%3)==((3+(((q[1]-q[0]+1)-(sn[q[1]]-sn[q[0]-1]))%3)-(((q[3]-q[2]+1)-(tn[q[3]]-tn[q[2]-1]))%3))%3)?"YES":"NO";
		}
		Console.WriteLine(String.Join("\n",ans));
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