using System;
using System.Collections.Generic;
class Program{
	static bool[] h;
	static List<int>[] a;
	const int mod=1000000007;
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		a=new List<int>[n+1];
		for(int i=1;i<=n;i++){a[i]=new List<int>();}
		for(int i=0;i<n-1;i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			a[q[0]].Add(q[1]);
			a[q[1]].Add(q[0]);
		}
		h=new bool[n+1];
		Console.WriteLine("{0}",fu(1)[0]);
	}
	static long[] fu(int b){
		h[b]=true;
		long f=1,g=1;
		for(int i=0;i<a[b].Count;i++){
			if(!h[a[b][i]]){
				long[] q=fu(a[b][i]);
				g=(g*q[0])%mod;
				f=(f*q[1])%mod;
			}
		}
		return new long[]{(f+g)%mod,g};
	}
}