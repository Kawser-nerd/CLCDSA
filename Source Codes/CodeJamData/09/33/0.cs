using System;
using System.Collections.Generic;
using System.Text;

public class C
{
	public static void Main ()
	{
		int n = int.Parse (Console.ReadLine ());
		C task = new C ();
		
		for (int i = 1; i <= n; ++i)
			Console.WriteLine ("Case #{0}: {1}", i, task.Solve ());
	}

	int p, q;
	int[] w;
	int?[,] cc;

	int solve (int a, int b)
	{
		if (a > b)
			return 0;

		if (cc[a, b].HasValue)
			return cc[a, b].Value;

		int min = int.MaxValue;

		for (int i = a; i <= b; ++i)
			min = Math.Min (min, solve (a, i - 1) + solve (i + 1, b) + w[b + 1] - w[a - 1] - 2);

		cc[a, b] = min;
		return min;
	}

	public string Solve ()
	{
		string[] ss = Console.ReadLine ().Split (' ');
		p = int.Parse (ss[0]);
		q = int.Parse (ss[1]);
		w = new int[q + 2];
		cc = new int?[q + 2, q + 2];

		w[0] = 0;
		w[q + 1] = p + 1;

		ss = Console.ReadLine ().Split (' ');
		for (int i = 0; i < q; ++i)
			w[i + 1] = int.Parse (ss[i]);

		return solve (1, q).ToString ();
	}
}
