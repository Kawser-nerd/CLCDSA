using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Codeforces
{
	internal class Template
	{
		private void Solve()
		{
			var n = cin.NextInt();
			var a = new int[n];
			for (var i = 0; i < n; i++)
			{
				a[i] = cin.NextInt();
			}
			var groups = a.GroupBy(x => x).ToDictionary(x => x.Key, x => x.Count());
			if (groups.Count > 2)
			{
				Console.WriteLine("No");
			}
			else if (groups.Count == 1)
			{
				var key = groups.Single().Key;
				if (n >= key*2 || key + 1 == n)
				{
					Console.WriteLine("Yes");
				}
				else
				{
					Console.WriteLine("No");
				}
			}
			else
			{
				var keys = groups.Select(x => x.Key).OrderBy(x => x).ToList();
				if (keys[1] - keys[0] > 1)
				{
					Console.WriteLine("No");
				}
				else
				{
					if (keys[1] >= n)
					{
						Console.WriteLine("No");
					}
					else if (groups[keys[0]] > keys[0])
					{
						Console.WriteLine("No");
					}
					else if (groups[keys[1]] < 2 * (keys[0] + 1 - groups[keys[0]]))
					{
						Console.WriteLine("No");
					}
					else
					{
						Console.WriteLine("Yes");
					}
				}
			}
		}

		private static readonly Scanner cin = new Scanner();

		private static void Main()
		{
			new Template().Solve();
			Console.ReadLine();
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