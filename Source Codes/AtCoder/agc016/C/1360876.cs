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
			var H = cin.NextInt();
			var W = cin.NextInt();
			var h = cin.NextInt();
			var w = cin.NextInt();
			var a = new int[H, W];
			var minus = -h*w;
			for (var i = 0; i < H; i++)
			{
				for (var j = 0; j < W; j++)
				{
					a[i, j] = 1;
					if (j%w == 0 && i%h == 0)
					{
						a[i, j] = 1000;
					}
					if ((j + 1)%w == 0 && (i + 1)%h == 0)
					{
						a[i, j] = minus - 999;
					}
				}
			}
			var sum = 0L;
			var sb = new StringBuilder();
			for (var i = 0; i < H; i++)
			{
				if (i > 0)
				{
					sb.AppendLine();
				}
				for (var j = 0; j < W; j++)
				{
					if (j > 0)
					{
						sb.Append(' ');
					}
					sum += a[i, j];
					sb.Append(a[i, j]);
				}
			}
			if (sum <= 0)
			{
				Console.WriteLine("No");
				return;
			}
			Console.WriteLine("Yes");
			var res = sb.ToString();
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