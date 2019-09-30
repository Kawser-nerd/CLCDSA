using System;
using System.Collections.Generic;

class ARC035B
{
	const long M = 1000000007;

	static public void Main(string[] args)
	{
		int N = int.Parse(Console.ReadLine());
		int[] T = new int[N];
		Dictionary<int,int> dic = new Dictionary<int,int>();

		for(int i=0; i < N; i++)
		{
			T[i] = int.Parse(Console.ReadLine());
			if(dic.ContainsKey(T[i]))
			{
				dic[T[i]]++;
			}
			else
			{
				dic[T[i]] = 1;
			}
		}
		Array.Sort(T);

		long penalty = 0;
		long elapsed = 0;
		foreach(var t in T)
		{
			elapsed += t;
			penalty += elapsed;
		}
		Console.WriteLine(penalty);

		long p = 1;
		foreach(var v in dic.Values)
		{
			p = p * factorial(v) % M;
		}
		Console.WriteLine(p);
	}
	
	static long factorial(long n)
	{
		if(n == 1 || n == 0)
			return 1;
		else
			return n * factorial(n-1) % M;
	}
}