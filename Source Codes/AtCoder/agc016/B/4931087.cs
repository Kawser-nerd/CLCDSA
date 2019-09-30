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
		int m1=0,m2=int.MaxValue;
		int[] h=new int[n+1];
		for(int i = 0;i<n;i++) {
			m1=Math.Max(m1,a[i]);
			m2=Math.Min(m2,a[i]);
			h[a[i]]++;
		}
		if(m1==m2){Console.WriteLine("{0}",(m1==n-1||m1*2<=n)?"Yes":"No");}
		else if(m1-m2==1){
			if(m2==h[m2]&&h[m1]>1){Console.WriteLine("Yes");}
			else if(m2>h[m2]&&(m1-h[m2])*2<=h[m1]){Console.WriteLine("Yes");}
			else{Console.WriteLine("No");}
		}
		else{Console.WriteLine("No");}
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