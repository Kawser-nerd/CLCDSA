using System;
using System.Collections.Generic;
using System.Linq;

public class MainClass
{
	public static void Main (string[] args)
	{
		MainClass task = new MainClass();
		
		int n = int.Parse(Console.ReadLine());
		for(int i = 1; i <= n; ++i)
			Console.WriteLine("Case #{0}: {1}", i, task.Solve());
	}
	
	public string Solve()
	{
		long n = long.Parse(Console.ReadLine());
		
		if (n == 1)
			return "0";
		
		List<int> p = new List<int>();
		List<int> q = new List<int>();
		for (int i = 2; i <= n; ++i)
		{
			int rem = i;
			for (int j = 0; j < p.Count && p[j] * p[j] <= rem; ++j)
			{
				int cnt = 0;
				while (rem % p[j] == 0)
				{
					rem /= p[j];
					++cnt;
				}
				q[j] = Math.Max(q[j], cnt);
			}
			
			if (rem == i)
			{
				p.Add(rem);
				q.Add(1);
			}
		}
		
		int res = 1;
		
		foreach (int qq in q)
			res += qq - 1;
		
		return res.ToString();
	}
}