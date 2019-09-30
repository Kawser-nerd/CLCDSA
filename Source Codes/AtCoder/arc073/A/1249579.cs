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

		private void Solve()
		{
			var n = cin.NextLong();
			var t = cin.NextLong();
			var lastTo = 0L;
			var res = 0L;
			for (var i = 0; i < n; i++)
			{
				var from = cin.NextLong();
				var to = from + t;
				if (from < lastTo)
				{
					from = lastTo;
				}
				res += to - from;
				lastTo = to;
			}
			Console.WriteLine(res);
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