using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;

namespace Codeforces
{
	internal class Template
	{

		private long[] weight = new long[110];
		private long[] value = new long[110];

		private Dictionary<Tuple<long, long>, long> dp; 

		private void Solve()
		{
			var n = cin.NextLong();
			var w = cin.NextLong();
			for (var i = 0; i < n; i++)
			{
				weight[i] = cin.NextLong();
				value[i] = cin.NextLong();
			}
			dp = new Dictionary<Tuple<long, long>, long>();
			var res = Calc(n - 1, w);
			Console.WriteLine(res);
		}

		private long Calc(long take, long w)
		{
			if (take < 0)
			{
				return 0;
			}
			var idx = Tuple.Create(take, w);
			if (dp.ContainsKey(idx))
			{
				return dp[idx];
			}
			if (weight[take] > w)
			{
				return Calc(take - 1, w);
			}
			var res = Math.Max(Calc(take - 1, w), Calc(take - 1, w - weight[take]) + value[take]);
			dp[idx] = res;
			return res;
		}

		private static readonly Scanner cin = new Scanner();

		private static void Main()
		{
#if DEBUG
			var inputText = File.ReadAllText(@"..\..\input.txt");
			var testCases = inputText.Split(new[] { "input" }, StringSplitOptions.RemoveEmptyEntries);
			var consoleOut = Console.Out;
			for (var i = 0; i < testCases.Length; i++)
			{
				var parts = testCases[i].Split(new[] { "output" }, StringSplitOptions.RemoveEmptyEntries);
				Console.SetIn(new StringReader(parts[0].Trim()));
				var stringWriter = new StringWriter();
				Console.SetOut(stringWriter);
				var sw = Stopwatch.StartNew();
				new Template().Solve();
				sw.Stop();
				var output = stringWriter.ToString();

				Console.SetOut(consoleOut);
				var color = ConsoleColor.Green;
				var status = "Passed";
				if (parts[1].Trim() != output.Trim())
				{
					color = ConsoleColor.Red;
					status = "Failed";
				}
				Console.ForegroundColor = color;
				Console.WriteLine("Test {0} {1} in {2}ms", i + 1, status, sw.ElapsedMilliseconds);
			}
			Console.ReadLine();
			Console.ReadKey();
#else
			new Template().Solve();
			Console.ReadLine();
#endif
		}
	}

	internal class Scanner
	{
		private string[] s = new string[0];
		private int i;
		private readonly char[] cs = { ' ' };

		public string NextString()
		{
			if (i < s.Length) return s[i++];
			var line = Console.ReadLine() ?? string.Empty;
			s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
			i = 1;
			return s.First();
		}

		public double NextDouble()
		{
			return double.Parse(NextString());
		}

		public int NextInt()
		{
			return int.Parse(NextString());
		}

		public long NextLong()
		{
			return long.Parse(NextString());
		}
	}
}