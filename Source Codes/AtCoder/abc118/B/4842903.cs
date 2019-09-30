using System;
using System.Collections.Generic;


public class B
{	
	public static void Main()
	{	
		string[] args = Console.ReadLine().Split(' ');
		long N = Int64.Parse(args[0]);
		long M = Int64.Parse(args[1]);
		
		bool[,] flag = new bool[M,N];  // all false
		
		for(int i = 0; i < N; i++)
		{
			args = Console.ReadLine().Split(' ');
			long K = Int64.Parse(args[0]);
			for(int j = 1; j <= K; j++)
				flag[Int64.Parse(args[j]) - 1, i] = true;
		}
		
		long result = 0;
		for(int i = 0; i < M; i++)
		{
			bool like = true;
			for(int j = 0; j < N; j++)
				like &= flag[i,j];
			
			if(like)
				result++;
		}
			
		Console.WriteLine(result);
	}
}