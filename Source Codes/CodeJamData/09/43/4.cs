// made by diver_ru, made with love
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

public class Solver
{
	TextWriter Out;
	TextReader In;

	int readInt()
	{
		return int.Parse(In.ReadLine());
	}

	List<int[]> points;
	int[] tab;

	int[,] tabCan;

	bool can(int x, int y)
	{
		if (tabCan[x, y] != 0)
			return tabCan[x, y] == 2;
		tabCan[x, y] = 1;
		int[] a = points[x], b = points[y];

		int order = Math.Sign(a[0] - b[0]);
		if (order == 0)
			return false;
		for (int i = 1; i < a.Length; ++i)
		{
			if (order != Math.Sign(a[i] - b[i]))
				return false;
		}
		tabCan[x, y] = 2;
		return true;
	}



	int getMinCount(int mask)
	{
		int res = tab[mask];
		if (res != 0)
			return res - 1;
		bool ok = true;
		for (int i = 0; i < points.Count; ++i)
		{
			if (((mask >> i) & 1) == 0)
				continue;
			for (int j = i + 1; j < points.Count; ++j)
			{
				if (((mask >> j) & 1) != 0)
				{
					ok &= can(i, j);
				}
			}
		}
		
		res = 1;

		if (!ok)
		{
			res = int.MaxValue;
			for (int z = mask & (mask - 1); z != 0; z = (z - 1) & mask)
			{
				res = Math.Min(res, getMinCount(z) + getMinCount(z ^ mask));
			}
		}

		tab[mask] = res + 1;

		return res;
	}

	private void Solve()
	{
		In = new StreamReader("../../input.txt");
		Out = new StreamWriter("../../output.txt");

		int cntCases = readInt();
		for (int k = 1; k <= cntCases; ++k)
		{
			
			int N, K;
			string[] parts = In.ReadLine().Split();
			N = int.Parse(parts[0]);
			K = int.Parse(parts[1]);
			points = new List<int[]>();
			for (int i = 0; i < N; ++i)
			{
				points.Add(Array.ConvertAll<String, int>(In.ReadLine().Split(), int.Parse)); 
			}
			tab = new int[1 << N];
			tabCan = new int[N, N];

			Out.WriteLine("Case #{0}: {1}", k, getMinCount((1 << N) - 1));
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
