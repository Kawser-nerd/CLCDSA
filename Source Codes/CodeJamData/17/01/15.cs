using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "A-large";

		private static void Main()
		{
			Console.SetIn(new StreamReader(string.Format(@"D:\Contests\GoogleCodeJam\{0}.in", fileName)));
			Console.SetOut(new StreamWriter(string.Format(@"D:\Contests\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
			var t = cin.NextInt();
			for (var c = 1; c <= t; c++)
			{
				Console.Write("Case #{0}: ", c);
				Solve();
			}
		}

		private static void Solve()
		{
			var s = cin.NextString();
			var a = s.ToCharArray();
			var k = cin.NextInt();
			var count = 0;
			for (var i = 0; i <= a.Length - k; i++)
			{
				if (a[i] == '-')
				{
					count++;
					for (var j = 0; j < k; j++)
					{
						if (a[i + j] == '-')
						{
							a[i + j] = '+';
						}
						else
						{
							a[i + j] = '-';
						}
					}
				}
			}
			if (a.All(x => x == '+'))
			{
				Console.WriteLine(count);
			}
			else
			{
				Console.WriteLine("IMPOSSIBLE");
			}
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