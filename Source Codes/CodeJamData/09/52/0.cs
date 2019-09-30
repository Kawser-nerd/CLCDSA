// made by diver_ru, made with love
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

public class Solver
{
	const int MOD = 10009;
	TextWriter Out;
	TextReader In;

	int[][] words;

	int readInt()
	{
		return int.Parse(In.ReadLine().Trim());
	}

	Dictionary<long, int>[] tab;
	long[] w;
	int exprLen;

	int getMult(long st)
	{
		int res = 1;
		for (int i = 0; i < exprLen; ++i, st >>= 9)
		{
			res = (res * (int)(st & 511)) % MOD;
		}
		return res;
	}

	int getSum(string expr, int K)
	{
		exprLen = expr.Length;
		w = new long[words.Length];
		for (int i = 0; i < words.Length; ++i)
		{
			for (int j = 0; j < expr.Length; ++j)
				w[i] += ((long)words[i][expr[j] - 'a']) << (9 * j);
		}

		tab = new Dictionary<long, int>[K + 1];
		for (int i = 0; i <= K; ++i)
			tab[i] = new Dictionary<long, int>();

		return getCount(K, 0) % MOD;
	}

	private int getCount(int K, long st)
	{
		if (K == 0)
			return getMult(st);
		int res;
		if (tab[K].TryGetValue(st, out res))
			return res;

		for (int i = 0; i < w.Length; ++i)
		{
			res += getCount(K - 1, st + w[i]);
		}
		res %= MOD;

		tab[K][st] = res;
		return res;
	}

	private void Solve()
	{
		In = new StreamReader("../../input.txt");
		Out = new StreamWriter("../../output.txt");

		int cntCases = readInt();
		for (int k = 1; k <= cntCases; ++k)
		{
			Console.WriteLine(k);
			String[] parts = In.ReadLine().Split();
			string[] expr = parts[0].Split('+');
			int K = int.Parse(parts[1]);
			
			int D = readInt();
			words = new int[D][];
			for (int i = 0; i < D; ++i)
			{
				words[i] = new int[26];
				string cur = In.ReadLine();
				foreach (char c in cur)
					++words[i][c - 'a'];
			}
			Out.Write("Case #{0}:", k);

			for (int deg = 1; deg <= K; ++deg)
			{
				int res = 0;
				for (int i = 0; i < expr.Length; ++i)
					res = (res + getSum(expr[i], deg)) % MOD;
				Out.Write(" " + res);
			}

			Out.WriteLine();
		}

		In.Close();
		Out.Close();
	}

	// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		new Solver().Solve();
	}
	// END CUT HERE
}
