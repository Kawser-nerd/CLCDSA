using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "B-small-attempt1";

		public static List<string> possible = new List<string>(7777777); 

		private static void Main()
		{
			for (var i = 1; i <= 7777777; i++)
			{
				var str = i.ToString();
				if (str.All(x => x >= '1' && x <= '7'))
				{
					possible.Add(str);
				}
			}

			Console.SetIn(new StreamReader(string.Format(@"C:\GoogleCodeJam\{0}.in", fileName)));
			Console.SetOut(new StreamWriter(string.Format(@"C:\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
			var t = cin.NextInt();
			for (var c = 1; c <= t; c++)
			{
				Console.Write("Case #{0}: ", c);
				Solve();
				Debug.WriteLine(c);
			}
		}

		private static void Solve()
		{
			var k = cin.NextInt();
			var l = cin.NextInt();
			var s = cin.NextInt();
			var keyboard = cin.NextString();
			var target = cin.NextString();

			var maxIdx = (char)(k + '0');
			var combs = possible.Where(x => x.Length == s && x.All(y => y <= maxIdx)).ToList();
			var maximum = 0;
			var total = 0;
			foreach (var comb in combs)
			{
				var str = string.Empty;
				for (var i = 0; i < comb.Length; i++)
				{
					str += keyboard[comb[i] - '1'];
				}
				var cnt = 0;
				for (var i = 0; i < str.Length; i++)
				{
					var match = true;
					for (var j = 0; j < target.Length; j++)
					{
						if (i + j >= str.Length || str[i + j] != target[j])
						{
							match = false;
							break;
						}
					}
					if (match)
					{
						cnt++;
					}
				}
				maximum = Math.Max(maximum, cnt);
				total += cnt;
			}
			var giveAvg = (double) total/combs.Count;
			var leftAvg = maximum - giveAvg;
			Console.WriteLine(leftAvg);
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