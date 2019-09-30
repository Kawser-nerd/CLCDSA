using System;
using System.Collections.Generic;
using System.Text;

public class B
{
	public static void Main ()
	{
		int n = int.Parse (Console.ReadLine ());
		B task = new B ();

		for (int i = 1; i <= n; ++i)
			Console.WriteLine ("Case #{0}: {1}", i, task.Solve ());
	}

	int n;
	int[,] w;
	string[] exp;

	const int mod = 10009;

	int calc (int[] q, int ss)
	{
		int res = 0;

		if (ss == 0)
		{
			foreach (string s in exp)
			{
				int now = 1;

				foreach (char c in s)
				{
					now *= q[(int) (c - 'a')];
					now %= mod;
				}

				res += now;
			}

			return res;
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 26; ++j)
				q[j] += w[i, j];

			res += calc (q, ss - 1);
			res %= mod;

			for (int j = 0; j < 26; ++j)
				q[j] -= w[i, j];
		}

		return res;
	}

	public string Solve ()
	{
		string[] ss = Console.ReadLine ().Split (' ');
		n = int.Parse (Console.ReadLine ());
		w = new int[n, 26];

		for (int i = 0; i < n; ++i)
		{
			string s = Console.ReadLine ();
			foreach (char c in s)
				++w[i, (int) (c - 'a')];
		}

		exp = ss[0].Split ('+');
		int q = int.Parse (ss[1]);

		string[] res = new string[q];

		for (int i = 1; i <= q; ++i)
			res[i - 1] = "" + calc (new int[26], i);

		return string.Join (" ", res);
	}
}
