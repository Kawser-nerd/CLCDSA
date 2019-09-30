using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		int[] a=sc.Ia;
		if(a[0]<a[1]&&n>a[0]){Console.WriteLine("Aoki");}
		else if(a[0]!=a[1]){Console.WriteLine("Takahashi");}
		else if(n%(a[0]+1)==0){Console.WriteLine("Aoki");}
		else{Console.WriteLine("Takahashi");}
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
}