using System;
using System.Collections.Generic;


public class C
{
	public static void Main()
	{
		string[] args;
		args = Console.ReadLine().Split(' ');
		int N = Int32.Parse(args[0]);
		int M = Int32.Parse(args[1]);
		
		List<int> X = new List<int>(M);
		args = Console.ReadLine().Split(' ');
		for(int i = 0; i < M; i++)
			X.Add(Int32.Parse(args[i]));
		
		X.Sort();
		
		List<int> L = new List<int>(M);
		for(int i = 0; i < M - 1; i++)
			L.Add(X[i + 1] - X[i]);
		
		L.Sort((a,b) => b-a);
		
		int result = 0;
		if(N < M)
		{
			result = X[M-1] - X[0];
			for(int i = 0; i < N-1; i++)
				result -= L[i];			
		}
		Console.WriteLine(result);
	}
}