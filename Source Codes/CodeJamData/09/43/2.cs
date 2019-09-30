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

	bool[,] g;
	bool[] used;
	int?[] r;
	int n;

	bool find (int x)
	{
		if (used[x])
			return false;
		used[x] = true;

		for (int i = 0; i < n; ++i)
			if (g[x, i] && !r[i].HasValue)
		{
			r[i] = x;
			return true;
		}

		for (int i = 0; i < n; ++i)
			if (g[x, i])
		{
			int bak = r[i].Value;
			r[i] = x;

			if (find (bak))
				return true;

			r[i] = bak;
		}

		return false;
	}

	public string Solve ()
	{
		string[] ss = Console.ReadLine ().Split (' ');

		n = int.Parse (ss[0]);
		int k = int.Parse (ss[1]);

		int[][] q = new int[n][];

		for (int i = 0; i < n; ++i)
		{
			q[i] = new int[k];

			ss = Console.ReadLine ().Split (' ');

			for (int j = 0; j < k; ++j)
				q[i][j] = int.Parse (ss[j]);
		}

		g = new bool[n, n];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
		{
			g[i, j] = true;
			for (int kk = 0; kk < k; ++kk)
				if (q[i][kk] >= q[j][kk])
					g[i, j] = false;
		}

		int res = n;
		r = new int?[n];

		for (int i = 0; i < n; ++i)
		{
			used = new bool[n];
			if (find (i))
				--res;
		}

		return res.ToString ();
	}
}
