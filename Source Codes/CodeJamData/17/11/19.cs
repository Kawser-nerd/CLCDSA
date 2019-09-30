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
				Console.Title = string.Format("{0} of {1}", c, t);
				Console.Write("Case #{0}: ", c);
				new Template().Solve();
			}
		}

		private void Solve()
		{
			var r = cin.NextInt();
			var c = cin.NextInt();
			var cake = new char[r][];
			for (var i = 0; i < r; i++)
			{
				cake[i] = cin.NextString().ToCharArray();
				if (cake[i].Any(x => x != '?'))
				{
					var first = cake[i].First(x => x != '?');
					for (var j = 0; j < cake[i].Length; j++)
					{
						if (cake[i][j] == '?')
						{
							cake[i][j] = first;
						}
						else
						{
							first = cake[i][j];
						}
					}
				}
			}
			for (var y = 0; y < r; y++)
			{
				if (cake[y][0] == '?')
				{
					for (var i = y + 1; i < r; i++)
					{
						if (cake[i][0] != '?')
						{
							cake[y] = cake[i];
							break;
						}
					}
				}
				break;
			}
			for (var y = 1; y < r; y++)
			{
				if (cake[y][0] == '?')
				{
					cake[y] = cake[y - 1];
				}
			}
			Console.WriteLine();
			for (var i = 0; i < r; i++)
			{
				Console.WriteLine(new string(cake[i]));
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