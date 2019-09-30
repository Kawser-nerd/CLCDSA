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
			var m = cin.NextInt();
			if (Math.Abs(n - m) > 1)
			{
				Console.WriteLine(0);
				return;
			}
			if (m > n)
			{
				var temp = n;
				n = m;
				m = temp;
			}
			var mod = (int) 1e9 + 7;
			var res = 1L;
			if (m == n)
			{
				res = 2L;
			}
			while (n > 0)
			{
				res *= n;
				res %= mod;
				n--;
				if (m > 0)
				{
					res *= m;
					res %= mod;
					m--;
				}
			}
			Console.WriteLine(res);
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