using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] s = Console.ReadLine().Split();
		int N = int.Parse(s[0]);
		int M = int.Parse(s[1]);
		int X = int.Parse(s[2]);
		string[] s2 = Console.ReadLine().Split();
		int[] A = new int[N];
		for(var i=0;i<M;i++){
			int t = int.Parse(s2[i]);
			A[t] = 1;
		}
		int sum = 0;
		for(var i=1;i<X;i++){
			if(A[i] == 1){
				sum += 1;
			}
		}
		int summin = sum;
		sum = 0;
		for(var i=X+1;i<N;i++){
			if(A[i] == 1){
				sum += 1;
			}
		}
		summin = Math.Min(sum,summin);
		Console.WriteLine(summin);
	}
}