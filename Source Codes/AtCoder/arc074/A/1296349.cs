using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace Codeforces
{
	internal class Template
	{
		private void Solve()
		{
			var h = cin.NextLong();
			var w = cin.NextLong();
			var best = long.MaxValue;
			for (var i = 1; i < h; i++)
			{
				var a = i*w;
				var hh = h - i;
				var a2 = hh*(w/2);
				var a3 = hh*(w - w/2);
				best = Math.Min(best, Diff(a, a2, a3));
				a2 = hh/2*w;
				a3 = (hh - hh/2)*w;
				best = Math.Min(best, Diff(a, a2, a3));
			}
			var temp = h;
			h = w;
			w = temp;
			for (var i = 1; i < h; i++)
			{
				var a = i * w;
				var hh = h - i;
				var a2 = hh * (w / 2);
				var a3 = hh * (w - w / 2);
				best = Math.Min(best, Diff(a, a2, a3));
				a2 = hh / 2 * w;
				a3 = (hh - hh / 2) * w;
				best = Math.Min(best, Diff(a, a2, a3));
			}
			Console.WriteLine(best);

			//var a = h*w;
			//var t = a/3;
			//var hh = t / w;
			//var piece1 = hh*w;
			//var piece2 = (h - hh)*(w/2);
			//var piece3 = (h - hh)*(w - w/2);
			//var diff = Math.Max(Math.Max(Math.Abs(piece1 - piece2), Math.Abs(piece1 - piece3)), Math.Abs(piece2 - piece3));
			//piece1 = hh * w;
			//piece2 = (h - hh)/2 * w;
			//piece3 = ((h - hh) - (h - hh)/2) * w;
			//var diff3 = Math.Max(Math.Max(Math.Abs(piece1 - piece2), Math.Abs(piece1 - piece3)), Math.Abs(piece2 - piece3));
			//var temp = h;
			//h = w;
			//w = temp;
			//a = h * w;
			//t = a / 3;
			//hh = t / w;
			//piece1 = hh * w;
			//piece2 = (h - hh) * (w / 2);
			//piece3 = (h - hh) * (w - w / 2);
			//var diff2 = Math.Max(Math.Max(Math.Abs(piece1 - piece2), Math.Abs(piece1 - piece3)), Math.Abs(piece2 - piece3));
			//piece1 = hh * w;
			//piece2 = (h - hh) / 2 * w;
			//piece3 = ((h - hh) - (h - hh) / 2) * w;
			//var diff4 = Math.Max(Math.Max(Math.Abs(piece1 - piece2), Math.Abs(piece1 - piece3)), Math.Abs(piece2 - piece3));
			//var res = Math.Min(Math.Min(diff, diff2), Math.Min(diff3, diff4));
			//Console.WriteLine(res);
		}

		private long Diff(long a, long b, long c)
		{
			return Math.Max(Math.Abs(a - b), Math.Max(Math.Abs(a - c), Math.Abs(b - c)));
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