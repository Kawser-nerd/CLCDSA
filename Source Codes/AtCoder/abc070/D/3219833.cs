using System;
using System.Collections.Generic;
class Program{
	static List<long[]>[] li;
	static long[] h;
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		h=new long[n+1];
		li=new List<long[]>[n+1];
		for(int i=1;i<=n;i++){
			li[i]=new List<long[]>();
			h[i]=-1;
		}
		for(int i=0;i<n-1;i++){
			long[] q=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
			li[q[0]].Add(new long[]{q[1],q[2]});
			li[q[1]].Add(new long[]{q[0],q[2]});
		}
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		fu(s[1],0);
		for(int i=0;i<s[0];i++){
			long[] q=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
			Console.WriteLine("{0}",h[q[0]]+h[q[1]]);
		}
	}
	static void fu(long n,long k){
		h[n]=k;
		for(int i=0;i<li[n].Count;i++){
			if(h[li[n][i][0]]==-1){
				fu(li[n][i][0],k+li[n][i][1]);
			}
		}
	}
}