using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		long n=sc.L;
		int m=50;
		long[] a=new long[m];
		for(int i = 0;i<m;i++){
			a[i]=m-1+(n/m);
			if(i<n%m){a[i]+=m+1-(n%m);}
			else{a[i]-=n%m;}
		}
		Console.WriteLine(m);
		Console.WriteLine(String.Join(" ",a));
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