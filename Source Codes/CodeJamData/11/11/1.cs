using System;
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
		string[] s = Console.ReadLine().Split(' ');
		long n = long.Parse(s[0]);
		long p = long.Parse(s[1]);
		long pg = long.Parse(s[2]);
		
		if (pg == 100 && p < 100)
			return "Broken";
		if (pg == 0 && p > 0)
			return "Broken";
		if (p == 0)
			return "Possible";
		
		int q = 100;
		
		for (int i = 2; i <= p; ++i)
			while (p % i == 0 && q % i == 0)
		{
			p /= i;
			q /= i;
		}
		
		if (n >= q)
			return "Possible";
		else
			return "Broken";
	}
}