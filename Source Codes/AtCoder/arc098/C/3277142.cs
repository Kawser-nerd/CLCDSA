using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		int N = int.Parse(str[0]);
		int K = int.Parse(str[1]);
		int Q = int.Parse(str[2]);
		int[] A = new int[N];
		int[] B = new int[N];
		string[] str2 = Console.ReadLine().Split();
		for(var i=0;i<N;i++){
			A[i] = int.Parse(str2[i]);
			B[i] = A[i];
		}
		Array.Sort(B);
		var list = new List<int>();
		var listm = new List<int>();
		long ans = 999999999999;
		for(var k=0;k<N;k++){
			for(var i=0;i<N;i++){
				if(A[i] >= B[k]){
					list.Add(A[i]);
				}
				if(A[i] < B[k] || i == N-1){
					list.Sort();
					for(var j=0;j<list.Count-K+1;j++){
						listm.Add(list[j]);
					}
					list.Clear();
				}
			}
			listm.Sort();
			if(listm.Count >= Q){
				ans = Math.Min(listm[Q-1]-B[k],ans);
			}
			listm.Clear();
		}
		Console.WriteLine(ans);
	}
}