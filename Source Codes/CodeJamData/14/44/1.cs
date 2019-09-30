using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class D
{
	static int worst, nworst, M;
	static string[] S;

	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);
			string[] parts = Console.ReadLine().Split();
			M = int.Parse(parts[0]);
			int N = int.Parse(parts[1]);
			S = new string[M];
			for (int i = 0; i < M; i++)
				S[i] = Console.ReadLine();

			worst = 0;
			nworst = 0;
			rec(0, N, 0);

			Console.WriteLine("Case #" + CASE + ": " + worst + " " + nworst);
		}
	}

	static void rec(int mask, int n, int sum)
	{
		if (n == 1)
		{
			int r = ((1 << M) - 1) ^ mask;
			if (r == 0) return;
			int n4 = count(r, S);

			int cur = sum + n4;
			if (cur > worst)
			{
				worst = cur;
				nworst = 1;
			}
			else if (cur == worst)
				nworst++;
		}
		else
		{
			for (int i = 1; i < (1 << M); i++)
			{
				if ((i & mask) > 0) continue;
				rec(mask | i, n - 1, sum + count(i, S));
			}
		}
	}

	public static int count(int mask, string[] S)
	{
		HashSet<string> prefs = new HashSet<string>();
		for (int i = 0; i < S.Length; i++)
		{
			if ((mask & (1 << i)) == 0) continue;
			for (int j = 0; j <= S[i].Length; j++)
			{
				prefs.Add(S[i].Substring(0, j));
			}
		}
		return prefs.Count;
	}
}
