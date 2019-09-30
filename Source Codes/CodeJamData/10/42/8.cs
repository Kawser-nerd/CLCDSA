using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemB
{
	static void Main(string[] args)
	{
		//TextReader sr = new StreamReader(@"c:\temp\b.in.txt");
		//TextReader sr = new StreamReader(@"c:\temp\b-small-attempt0.in");
		TextReader sr = new StreamReader(@"c:\temp\b-large.in");
		//		TextReader sr = Console.In;
				TextWriter sw = new StreamWriter(@"c:\temp\b.out");
		//TextWriter sw = Console.Out;	

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		}
		sw.Close();
	}

	static int P;
	static int[] M;
	static int[][] Prices;

	static int[,,] Memo;
	static bool[, ,] Vis;

	static int Go(int round, int skipped, int match)
	{
		if (round < 0)
		{
			if (skipped > M[match])
				return -1;
			return 0;
		}
		if (Vis[round, skipped, match]) return Memo[round, skipped, match];

		int best = int.MaxValue;
		int next1 = match * 2, next2 = match * 2 + 1;
		int v1 = Go(round - 1, skipped, next1), v2 = Go(round - 1, skipped, next2);
		if (v1 >= 0 && v2 >= 0)
		{
			best = v1 + v2 + Prices[round][match];
		}
		int w1 = Go(round - 1, skipped + 1, next1), w2 = Go(round - 1, skipped + 1, next2);
		if (w1 >= 0 && w2 >= 0 && w1 + w2 < best)
		{
			best = w1 + w2;
		}
		if (best == int.MaxValue)
			best = -1;

		Vis[round, skipped, match] = true;
		Memo[round, skipped, match] = best;

		return best;
	}

	private static void Solve(TextReader sr, TextWriter sw)
	{
		P = int.Parse(sr.ReadLine());
		M = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
		Prices = new int[P][];
		for (int i = 0; i < P; i++)
		{
			Prices[i] = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
		}
		Memo = new int[P, P + 1, 1 << P];
		Vis = new bool[P, P + 1, 1 << P];
		int ans = Go(P - 1, 0, 0);
		sw.WriteLine(ans);
	}
}
