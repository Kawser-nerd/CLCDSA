using System;
using System.Collections.Generic;

class ARC044B
{
	const long M = 1000000007;
	
	static public void Main(string[] args)
	{
		int N = int.Parse(Console.ReadLine());
		List<int> A = new List<int>();
		List<int>[] points = new List<int>[N];
		for(int i = 0; i < N; i++)
		{
			points[i] = new List<int>();
		}
		string[] vals = Console.ReadLine().Split(' ');
		A.Add(-1);
		for(int i = 0; i < N; i++)
		{
			int a = int.Parse(vals[i]);
			A.Add(a);
			points[a].Add(i+1);
		}
		if(!(points[0].Count ==1 && points[0][0] ==1))
		{
			Console.WriteLine(0);
			return;
		}

		long[] pow2N = new long[N+1];
		pow2N[0] = 1;
		for(int i=1; i <= N; i++)
		{
			pow2N[i] = pow2N[i-1]*2 % M;
		}

		long[] cumPow2N = new long[N+1];
		cumPow2N[0] = 1;
		for(int i=1; i <= N; i++)
		{
			cumPow2N[i] = cumPow2N[i-1] * pow2N[i] % M;
		}

		long count = 1;
		long c;
		for(int i=2; i <= N; i++)
		{
			c = pow2N[points[A[i]-1].Count] - 1;	
			count = count * c % M;
		}
		for(int d=1; d <= N-1; d++)
		{
			if(points[d].Count == 0)
				continue;
			c = cumPow2N[points[d].Count-1];
			count = count * c % M;
		}
		Console.WriteLine(count);
	}
}