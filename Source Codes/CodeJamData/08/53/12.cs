using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ
{
	class Program
	{
		long M, N;

		char[][] g;
		int[,] memo;

		int search(int cr, int mask)
		{
			if (cr == M)
			{
				return 0;
			}
			if (memo[cr, mask] >= 0)
			{
				return memo[cr, mask];
			}

			int best = 0;
			for (int i = 0; i < C; ++i)
			{
				bool flag = true;
				int cnt = 0;
				// BRK
				for (int j = 0; j < N && flag; ++j)
				{
					if (((i >> j) & 1) == 1)
					{
						if (g[cr][j] != '.')
						{
							flag = false;
						}
						++cnt;
					}
				}

				// SBL
				for (int j = 1; j < N && flag; ++j)
				{
					if (
						((i >> j) & 1) == 1 &&
						((i >> (j - 1)) & 1) == 1
						)
					{
						flag = false;
					}
				}

				// TOP
				for (int j = 0; j < N && flag; ++j)
				{
					if (
						((i >> j) & 1) == 1 &&
						(
							(j > 0 && ((mask >> (j - 1)) & 1) == 1) ||
							(j < N - 1 && ((mask >> (j + 1)) & 1) == 1)
						)
					)
					{
						flag = false;
					}
				}

				if (flag)
				{
					int cur = search(cr + 1, i) + cnt;
					if (cur > best)
					{
						best = cur;
					}
				}
			}
			return memo[cr, mask] = best;
		}

		int C;

		public void Solve()
		{

			var tmp = GetLine();
			M = Long(tmp[0]);
			N = Long(tmp[1]);
			g = new char[M][];
			for (int i = 0; i < M; ++i)
			{
				g[i] = GetLine()[0].ToCharArray();
			}
			C = 1 << ((int)N);
			memo = new int[M, C];
			for (int i = 0; i < M; ++i)
				for (int j = 0; j < C; ++j)
				{
					memo[i, j] = -1;
				}

			fout.WriteLine(search(0, 0));
		}

		static StreamReader fin;
		static StreamWriter fout;

		static void Main(string[] args)
		{
			DateTime s = DateTime.Now;
			using (fout = new StreamWriter("../../out.txt"))
			{
				using (fin = new StreamReader("../../in.in"))
				{

					int n = Int32.Parse(fin.ReadLine());

					for (int i = 1; i <= n; ++i)
					{
						fout.Write("Case #{0}: ", i);
						new Program().Solve();
					}

				}
			}

			TimeSpan d = DateTime.Now - s;

			Console.WriteLine(d);
			Console.ReadLine();
		}

		string[] GetLine()
		{
			return fin.ReadLine().SplitByWhiteSpaces();
		}
		int Int(string a)
		{
			return Int32.Parse(a);
		}
		long Long(string a)
		{
			return Int64.Parse(a);
		}
	}
	static class Ext
	{

		static char[] emptyChars = "\r\n\t ".ToCharArray();

		public static string[] SplitByWhiteSpaces(this string source)
		{
			return source.Split(emptyChars, StringSplitOptions.RemoveEmptyEntries);
		}
	}
}