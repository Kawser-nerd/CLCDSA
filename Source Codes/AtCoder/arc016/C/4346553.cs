using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
static class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		int[][][] a=new int[s[1]][][];
		int[] g=new int[s[1]];
		for(int i = 0;i<s[1];i++) {
			int[] q=sc.Ia;
			a[i]=new int[q[0]][];
			g[i]=q[1];
			for(int j = 0;j<q[0];j++) {a[i][j]=sc.Ia;a[i][j][0]=1<<(a[i][j][0]-1);}
		}
		int m=1<<s[0];
		double[] dp=new double[m];
		for(int i = m-2;i>=0;i--) {
			dp[i]=double.MaxValue;
			for(int j = 0;j<s[1];j++) {
				double d=100*g[j];
				int q=0;
				for(int k = 0;k<a[j].Length;k++) {
					if((i&a[j][k][0])==0){
						d+=dp[i|a[j][k][0]]*a[j][k][1];
						q+=a[j][k][1];
					}
				}
				if(q==0){continue;}
				dp[i]=Math.Min(dp[i],d/q);
			}
		}
		Console.WriteLine("{0}",dp[0]);
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