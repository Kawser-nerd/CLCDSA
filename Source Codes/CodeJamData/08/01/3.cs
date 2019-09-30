using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ
{
	static class Ext
	{

		static char[] emptyChars = "\r\n\t ".ToCharArray();

		public static string[] SplitByWhiteSpaces(this string source)
		{
			return source.Split(emptyChars, StringSplitOptions.RemoveEmptyEntries);
		}
	}

	class Program
	{

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

		Dictionary<string, int> engines;
		List<int> queries;
		int nEngine;
		int nQuery;
		int[,] memo;

		int dp(int eng, int start)
		{
			if (start >= nQuery)
			{
				return 0;
			}
			if (memo[eng, start] >= 0)
			{
				return memo[eng, start];
			}
			int best = Int32.MaxValue;
			if (eng != queries[start])
			{
				best = dp(eng, start + 1);
				for (int i = 0; i < nEngine; ++i)
				{
					best = Math.Min(best, dp(i, start + 1) + 1);
				}
			}
			else
			{
				for (int i = 0; i < eng; ++i)
				{
					best = Math.Min(best, dp(i, start + 1) + 1);
				}
				for (int i = eng + 1; i < nEngine; ++i)
				{
					best = Math.Min(best, dp(i, start + 1) + 1);
				}
			}

			return memo[eng, start] = best;
		}

		public void Solve()
		{
			engines = new Dictionary<string, int>();
			queries = new List<int>();

			nEngine = Int32.Parse(fin.ReadLine());
			for (int i = 0; i < nEngine; ++i)
			{
				engines[fin.ReadLine()] = i;
			}
			nQuery = Int32.Parse(fin.ReadLine());
			for (int i = 0; i < nQuery; ++i)
			{
				queries.Add(engines[fin.ReadLine()]);
			}

			memo = new int[nEngine + 1, nQuery];
			for (int i = 0; i < nEngine; ++i)
			{
				for (int j = 0; j < nQuery; ++j)
				{
					memo[i, j] = -1;
				}
			}

			//int res = 0;
			//var cur = new Dictionary<string, object>(engines);
			//if (cur.Count == nEngine)
			//{
			//    --res;
			//}
			if (nQuery == 0)
			{
				fout.WriteLine(0);
				return;
			}
			int res = Int32.MaxValue;
			for (int i = 0; i < nEngine; ++i)
			{
				res = Math.Min(res, dp(i, 0));
			}
			fout.WriteLine(res);
		}
	}
}