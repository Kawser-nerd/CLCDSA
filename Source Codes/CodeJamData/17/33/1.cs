using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "C-small-1-attempt0";

		private static void Main()
		{
			Console.SetIn(new StreamReader(string.Format(@"D:\Contests\GoogleCodeJam\{0}.in", fileName)));
			Console.SetOut(new StreamWriter(string.Format(@"D:\Contests\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
			var t = cin.NextInt();
			for (var c = 1; c <= t; c++)
			{
				Console.Title = string.Format("{0} of {1}", c, t);
				Console.Write("Case #{0}: ", c);
				new Template().Solve();
			}
		}

		private void Solve()
		{
			var n = cin.NextInt();
			var k = cin.NextInt();
			var u = cin.NextDouble();
			var p = new double[n + 1];
			for (var i = 0; i < n; i++)
			{
				p[i] = cin.NextDouble();
			}
			p[p.Length - 1] = 1;
			Array.Sort(p);
			var idx = 1;
			while (Math.Abs(u) > 1e-12)
			{
				if (idx == p.Length)
				{
					break;
				}
				if (p[idx] - p[idx - 1] > 0)
				{
					var diff = p[idx] - p[idx - 1];
					var give = u/idx;
					var newVal = p[idx - 1] + Math.Min(give, diff);
					u -= Math.Min(give, diff)*idx;
					for (var i = 0; i < idx; i++)
					{
						p[i] = newVal;
					}
				}
				idx++;
			}
			var res = 1d;
			for (var i = 0; i < p.Length; i++)
			{
				res *= p[i];
			}
			Console.WriteLine(res);
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
			if (line == string.Empty)
			{
				return NextString();
			}
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