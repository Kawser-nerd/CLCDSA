using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		int N = int.Parse(Console.ReadLine());
		string[] str = Console.ReadLine().Split();
		int D = int.Parse(str[0]);
		int X = int.Parse(str[1]);
		int[] A = new int[N];
		int sum = 0;
		for(var i=0;i<N;i++){
			A[i] = int.Parse(Console.ReadLine());
			sum += 1 + (D-1) / A[i];
		}
		sum += X;
		Console.WriteLine(sum);
	}
}