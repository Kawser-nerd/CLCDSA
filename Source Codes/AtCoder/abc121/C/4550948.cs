using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		int N = int.Parse(str[0]);
		int M = int.Parse(str[1]);
		int[][]A = new int[N][];
		for(var i=0;i<N;i++){
			string[] str2 = Console.ReadLine().Split();
			A[i] = new int[2];
			A[i][0] = int.Parse(str2[0]);
			A[i][1] = int.Parse(str2[1]);
		}
		Array.Sort(A,(x,y)=>x[0]-y[0]);
		int ct = 0;
		long ans = 0;
		for(var i=0;i<N;i++){
			if(ct+A[i][1]>=M){
				ans += (M-ct)*(long)A[i][0];
				break;
			} else {
				ct+=A[i][1];
				ans += A[i][1]*(long)A[i][0];
			}
		}
		Console.WriteLine(ans);
	}
}