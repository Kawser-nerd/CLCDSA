using System;
using System.Collections.Generic;
using System.Linq;

public class A
{
	int[] type;
	bool[] chg;
	
	public void Run ()
	{
		int N = int.Parse (Console.ReadLine ());
		
		for (int I = 1; I <= N; ++I)
		{
			string[] ss = Console.ReadLine ().Split (' ');
			int n = int.Parse (ss[0]);
			int r = int.Parse (ss[1]);
			
			type = new int[n + 1];
			chg = new bool[(n + 1)/2];
			
			for (int i = 1; i <= (n - 1) / 2; ++i)
			{
				ss = Console.ReadLine ().Split (' ');
				type[i] = int.Parse (ss[0]);
				chg[i] = int.Parse (ss[1]) == 1;
			}
			
			for (int i = (n + 1) / 2; i <= n; ++i)
				type[i] = int.Parse (Console.ReadLine ());
			
			int[,] need = new int[n + 1, 2];
			
			for (int i = n; i >= (n + 1) / 2; --i)
			{
				need[i, type[i]] = 0;
				need[i, 1 - type[i]] = 1000000;
			}
			
			for (int i = (n - 1) / 2; i >= 1; --i)
			{
				need[i, 0] = 1000000;
				need[i, 1] = 1000000;
				
				int and = type[i] == 1 ? 0 : chg[i] ? 1 : 1000000;
				int or = type[i] == 0 ? 0 : chg[i] ? 1 : 1000000;
				
//				Console.WriteLine ("{0} {1} {2}", i, and, or);
				
				for (int q0 = 0; q0 <= 1; ++q0)
					for (int q1 = 0; q1 <= 1; ++q1)
				{
					need[i, q0 & q1] = Math.Min (need[i, q0 & q1], and + need[2 * i, q0] + need[2 * i + 1, q1]);
					need[i, q0 | q1] = Math.Min (need[i, q0 | q1], or + need[2 * i, q0] + need[2 * i + 1, q1]);
				}
			}
			
			if (need[1, r] >= 1000000)
				Console.WriteLine ("Case #{0}: IMPOSSIBLE", I);
			else
				Console.WriteLine ("Case #{0}: {1}", I, need[1, r]);
		}
	}
}
