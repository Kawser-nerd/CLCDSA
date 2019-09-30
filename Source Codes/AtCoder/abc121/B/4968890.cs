using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;


public class B
{
	public static void Main()
	{
		string[] args;

		args = Console.ReadLine().Split(' ');
		int N = Int32.Parse(args[0]);
		int M = Int32.Parse(args[1]);
		int C = Int32.Parse(args[2]);
		
		int[] B = new int[M];
		args = Console.ReadLine().Split(' ');
		for(int i = 0; i < M; i++)
			B[i] = Int32.Parse(args[i]);
		
		int[,] A = new int[N,M];
		for(int i = 0; i < N; i++)
		{
			args = Console.ReadLine().Split(' ');
			for(int j = 0; j < M; j++)
				A[i,j] = Int32.Parse(args[j]);			
		}
		
		int ans = 0;
		for(int i = 0; i < N; i++)
		{
			int sum = 0;
			for(int j = 0; j < M; j++)
				sum += A[i,j] * B[j];
			sum += C;
			if(sum > 0)
				ans++;
		}
		
		Console.WriteLine(ans);
	}	
}