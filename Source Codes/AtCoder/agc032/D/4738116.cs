using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		int N = int.Parse(str[0]);
		long A = long.Parse(str[1]);
		long B = long.Parse(str[2]);
		long[]P = new long[N];
		long[]P1 = new long[N];
		string[] str2 = Console.ReadLine().Split();
		for(var i=0;i<N;i++){
			P[i] = long.Parse(str2[i]);
			P1[P[i]-1] = i;
		}
		long[,]D = new long[N+1,N*2+1];
		for(var i=1;i<=N;i++){
			long min = D[i-1,0];
			D[i,0] = D[i-1,0]+B;
			for(var j=1;j<N*2+1;j++){
				min = Math.Min(min,D[i-1,j]);
				if(j==P1[i-1]*2+1){
					D[i,j] = min;
				} else if(j%2==1){
					D[i,j] = 99999999999999999;
				} else if(j<P1[i-1]*2+1){
					D[i,j] = min+B;
				} else {
					D[i,j] = min+A;
				}
			}
		}
		long ans = 99999999999999999;
		for(var j=0;j<N*2+1;j++){
			ans = Math.Min(ans,D[N,j]);
		}
		Console.WriteLine(ans);
	}
}