using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I,i=2,m=30000;
		int[] ans=new int[n];
		for(;i<m/2&&i<=((n-2)&-2);i+=2) {
			ans[i-2]=i;
			ans[i-1]=m-i;
		}
		i-=2;
		if(n%2==1){ans[i]=m;i++;}
		for(int j=3;j<m&&i<n;j+=3){
			if(j%2==1){ans[i]=j;i++;}
		}
		if(n==20000){
			ans[i]=m;
			ans[i+1]=(m/2);
		}
		else if(n==3){
			ans[0]=2;ans[1]=5;ans[2]=63;
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
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}