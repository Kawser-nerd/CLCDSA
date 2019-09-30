using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		int[] a=sc.Ia;
		var hs=new SortedDictionary<int,int[]>{[0]=new int[]{-1,0}};
		for(int i = 0;i<n;i++) {
			if(!hs.ContainsKey(a[i])){hs.Add(a[i],new int[]{i,1});}
			else{hs[a[i]][1]++;}
		}
		long k=0,m=int.MaxValue,p=0;
		long[] ans=new long[n];
		foreach(KeyValuePair<int,int[]> e in hs.Reverse()){
			if(k!=0){ans[m]+=(k-e.Key)*p;}
			k=e.Key;
			m=Math.Min(m,e.Value[0]);
			p+=e.Value[1];
		}
		Console.WriteLine(String.Join("\n",ans));
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