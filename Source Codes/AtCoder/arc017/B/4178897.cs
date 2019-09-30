using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		int[] a=new int[s[0]];
		int p=1,ans=0;
		a[0]=sc.I;
		for(int i = 1;i<s[0];i++) {
			a[i]=sc.I;
			if(a[i]>a[i-1]){p++;}
			else{p=1;}
			if(p>=s[1]){ans++;}
		}
		Console.WriteLine("{0}",s[1]==1?s[0]:ans);
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