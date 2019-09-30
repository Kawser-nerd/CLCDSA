using System;
using System.Collections.Generic;
using System.Linq;

public class B
{
	public void Run ()
	{
		int N = int.Parse (Console.ReadLine ());
		
		for (int I = 1; I <= N; ++I)
		{
			string[] ss = Console.ReadLine ().Split (' ');
			int a = int.Parse (ss[0]);
			int b = int.Parse (ss[1]);
			int x = int.Parse (ss[2]);
			
			if (x > a * b)
			{
				Console.WriteLine ("Case #{0}: IMPOSSIBLE", I);
				continue;
			}
			
			int d = x / a;
			int c = x - a * d;
			
			b = d + ((c > 0) ? 1 : 0);
			c = a - c;
			d = b - d;
			
			Console.WriteLine ("Case #{0}: {1} {2} {3} {4} {5} {6}", I, 0, 0, a, d, c, b);
		}
	}
}
