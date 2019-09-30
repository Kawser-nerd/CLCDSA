using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;


public class D
{	
	public static void Main()
	{
		string[] args;
		args = Console.ReadLine().Split(' ');
		int N = Int32.Parse(args[0]);
		int M = Int32.Parse(args[1]);
		
		List<int> A = new List<int>(M);
		args = Console.ReadLine().Split(' ');
		for(int i = 0; i < M; i++)
			A.Add(Int32.Parse(args[i]));
		A.Sort((x,y) => y - x);
		
		int[] num = {-1,2,5,5,4,5,6,3,7,6};
		
		int[] dp = new int[N + 1];		
		dp[0] = 0;		
		for(int i = 1; i <= N; i++)
			dp[i] = -1000000000;
		
		for(int i = 1; i <= N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				if(i < num[A[j]])
					continue;
				dp[i] = Math.Max(dp[i], dp[i - num[A[j]]] + 1);
			}				
		}
		
		StringBuilder sb = new StringBuilder();
		int rest = N;
		for(int i = 0; i < dp[N]; i++)
		{
			for(int j = 0; j < M; j++)
			{
				if(rest < num[A[j]])
					continue;
				if(dp[rest - num[A[j]]] != dp[rest] - 1)
					continue;
				sb.Append(A[j].ToString());
				rest -= num[A[j]];
				break;
			}			
		}
		
		Console.WriteLine(sb);		
	}
}