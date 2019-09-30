using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		long N = long.Parse(Console.ReadLine());
		long[]A = new long[N];
		for(var i=0;i<N;i++){
			A[i] = long.Parse(Console.ReadLine());
		}
		long[]B = new long[200001];
		long[]D = new long[200001];
		long[]C = new long[200001];
		C[0] = 1;
		long mod = 1000000007;
		for(var i=1;i<=N;i++){
			if(i==1 || A[i-1]!=A[i-2]){
				D[i] = B[A[i-1]];
				C[i] = (C[i-1] + D[i]) % mod;
				B[A[i-1]] = C[i];
			} else {
				C[i] = C[i-1];
			}
		}
		long ans = 1;
		for(var i=1;i<=N;i++){
			ans = (ans + D[i]) % mod;
		}
		//for(var i=0;i<=N;i++){
		//	Console.WriteLine(D[i]+" "+C[i]);
		//}
		Console.WriteLine(ans);
	}
}