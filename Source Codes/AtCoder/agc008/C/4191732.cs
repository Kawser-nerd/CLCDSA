using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		long[] a=sc.La;
		long b=a[1],c=a[1];
		c+=(a[0]&-2)+(a[3]&-2)+(a[4]&-2);
		if(a[0]%2==1&&a[3]%2==1&&a[4]%2==1){c++;}
		if(a[0]>0&&a[3]>0&&a[4]>0){
			a[3]--;
			a[4]--;
			a[0]--;
			b+=3;
		}
		b+=(a[0]&-2)+(a[3]&-2)+(a[4]&-2);
		Console.WriteLine("{0}",Math.Max(c,b));
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