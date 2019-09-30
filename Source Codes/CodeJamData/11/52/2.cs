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
		string[] ss = Console.ReadLine().Split(' ');
		
		if (ss.Length == 1)
			return "0";
		
		int[] cnts = new int[10002];
		int rem = 0;
		for (int i = 1; i < ss.Length; ++i)
		{
			++cnts[int.Parse(ss[i])];
			++rem;
		}
		
		int max = 10001;
		
		while(rem > 0)
		{
			int start = 0;
			while (cnts[start] == 0)
				++start;
			
			int stop = start;
			while (cnts[stop + 1] >= cnts[stop])
				++stop;
			
			for (int i = start; i <= stop; ++i)
				--cnts[i];
			
			rem -= stop - start + 1;
			max = Math.Min(max, stop - start + 1);
		}
		
		return max.ToString();
	}
}
