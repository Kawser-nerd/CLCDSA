using System;

class BeTogether
{
	static void Main(String[] args)
	{
		int N;
		int[] a;
		String[] vals;

		N = int.Parse(Console.ReadLine());
		a = new int[N];
		vals = Console.ReadLine().Split(' ');
		for(int i=0; i<N; i++)
			a[i] = int.Parse(vals[i]);
		int min = 101;
		int max = -101;
		for(int i=0; i<N; i++)
		{
			if(min > a[i])
				min = a[i];
			if(max < a[i])
				max = a[i];
		}
		if(min == max)
		{
			Console.WriteLine(0);
			return;
		}
		int minCost = int.MaxValue;
		int cost;
		for(int v=min; v<=max; v++)
		{
			cost=0;
			for(int i=0; i<N; i++)
				cost += (a[i]-v)*(a[i]-v);
			if(minCost > cost)
				minCost = cost;
		}
		Console.WriteLine(minCost);
	}
}