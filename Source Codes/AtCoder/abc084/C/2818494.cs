using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string str = Console.ReadLine();
		long N = long.Parse(str);
		long[] C = new long[N-1];
		long[] S = new long[N-1];
		long[] F = new long[N-1];
		long[] A = new long[N];
		long[] B = new long[N];
		for(var i=0;i<N-1;i++){
			string[] str2 = Console.ReadLine().Split();
			C[i] = long.Parse(str2[0]);
			S[i] = long.Parse(str2[1]);
			F[i] = long.Parse(str2[2]);
		}
		for(var i=0;i<N;i++){
			long ct = 0;
			for(var j=i;j<N-1;j++){
				if(ct <= S[j]){
					ct = S[j] + C[j];
				} else if(ct % F[j] == 0){
					ct = ct + C[j];
				} else {
					ct = ct + (F[j] - (ct - S[j]) % F[j]) + C[j];
				}
			}
			Console.WriteLine(ct);
		}
	}
}