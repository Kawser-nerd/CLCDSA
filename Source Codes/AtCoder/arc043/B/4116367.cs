using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		long[] a=new long[n+1];
		long[,] dp=new long[n+1,4];
		for(int i=1;i<=n;i++){a[i]=sc.I;}
		Array.Sort(a);
		for(int i=1;i<=n;i++){
			int lb=0,ub=i,mid=0;
			while(ub-lb>1){
				mid=(ub+lb)/2;
				if(a[mid]*2>a[i]){ub=mid;}
				else{lb=mid;}
			}
			dp[i,0]=i;
			dp[i,1]=(dp[i-1,1]+dp[ub-1,0])%mod;
			dp[i,2]=(dp[i-1,2]+dp[ub-1,1])%mod;
			dp[i,3]=(dp[i-1,3]+dp[ub-1,2])%mod;
		}
		Console.WriteLine(dp[n,3]);
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