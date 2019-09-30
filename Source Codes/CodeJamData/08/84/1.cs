using System;
using System.Collections.Generic;

public class D
{
	public static void Main ()
	{
		int n = int.Parse (Console.ReadLine ());
		D task = new D ();
		
		for (int i = 1; i <= n; ++i)
			Console.WriteLine ("Case #{0}: {1}", i, task.Solve ());
	}
	
	public string Solve ()
	{
		string[] ss = Console.ReadLine ().Split (' ');

		int n = int.Parse (ss[0]);
		int k = int.Parse (ss[1]);
		int p = int.Parse (ss[2]);

		int pp = 1 << p;
		int pp2 = pp / 2;
		
		int[] now = new int[pp];
		int[] next = new int[pp];
		now[(1 << k) - 1] = 1;

		for (int qq = k; qq < n; ++qq)
		{
			Array.Clear (next, 0, pp);

			for (int i = 0; i < pp2; ++i)
				for (int j = 0; j < p - 1; ++j)
					if ((i & (1 << j)) != 0)
				{
					int q = ((i^(1 << j)) << 1) + 1;
					
					next[q] += now[i];
					next[q] %= 30031;
				}

			for (int i = pp2; i < pp; ++i)
			{
				int q = ((i << 1) ^ pp) + 1;
				
				next[q] += now[i];
				next[q] %= 30031;
			}

			int[] ww = next;
			next = now;
			now = ww;
			
		}
		
		return now[(1 << k) - 1].ToString ();
	}
}
