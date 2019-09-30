using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemC
{
	static void Main(string[] args)
	{
//		TextReader sr = new StreamReader(@"c:\temp\c.in");
					TextReader sr = new StreamReader(@"c:\temp\c-small-attempt2.in");
		//			TextReader sr = new StreamReader(@"c:\temp\c-large.in");
		//		TextReader sr = Console.In;
							TextWriter sw = new StreamWriter(@"c:\temp\c.out");
//		TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		}
		sw.Close();
	}

	private static int n;
	private static bool[,] m;
	private static bool[] done;

	private static void Solve(TextReader sr, TextWriter sw)
	{
		var strings = sr.ReadLine().Split(' ');
		n = int.Parse(strings[0]);
		int k = int.Parse(strings[1]);

		m = new bool[n,n];
		int[,] price = new int[n,k];
		for (int i = 0; i < n; i++)
		{
			string[] split = sr.ReadLine().Split(' ');
			for (int j = 0; j < k; j++)
			{
				price[i, j] = int.Parse(split[j]);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				bool isAbove = true; // i is above j
				for (int t = 0; t < k && isAbove; t++)
				{
					if (price[i,t] <= price[j,t])
						isAbove = false;
				}
				m[i, j] = isAbove;
			}
		}

		int best = 0;
		for (int mask = 1; mask < 1<<n; mask++)
		{
			bool isClique = true;
			for (int j = 0; j < n; j++)
			{
				if (((1<<j)&mask) > 0)
				for (int i = j + 1; i < n; i++)
				{
					if (((1<<i)&mask) > 0)
					{
						if (m[i,j] || m[j,i]) isClique = false;
					}
				}
			}
			if (isClique)
			{
				int cnt = 0;
				for (int i = 0; i < n; i++)
				{
					if (((1 << i) & mask) > 0) cnt++;
				}
				best = Math.Max(best, cnt);
			}
		}
		
		sw.WriteLine(best);
	}
}
