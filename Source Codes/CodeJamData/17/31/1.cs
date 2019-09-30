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

		private List<Cake> cakes;
		private int kk;
		private double[,] dp = new double[1010,1010];
		private bool[,] has = new bool[1010,1010];

		private void Solve()
		{
			var n = cin.NextInt();
			var k = cin.NextInt();
			kk = k;
			cakes = new List<Cake>();
			for (var i = 0; i < n; i++)
			{
				cakes.Add(new Cake(cin.NextInt(), cin.NextInt()));
			}
			cakes = cakes.OrderBy(x => x.R).ToList();
			for (var i = 0; i < 1010; i++)
			{
				for (var j = 0; j < 1010; j++)
				{
					dp[i, j] = -1;
					has[i, j] = false;
				}
			}
			var res = Calc(k, cakes.Count - 1);
			Console.WriteLine(res);
		}

		private double Calc(int k, int idx)
		{
			if (k == 0 || idx < 0)
			{
				return 0;
			}
			if (has[k, idx])
			{
				return dp[k, idx];
			}
			var max = Calc(k, idx - 1);
			var h = 2* Math.PI*cakes[idx].R*cakes[idx].H;
			if (kk == k)
			{
				var a = Math.PI*cakes[idx].R*cakes[idx].R;
				h += a;
			}
			max = Math.Max(max, Calc(k - 1, idx - 1) + h);
			has[k, idx] = true;
			dp[k, idx] = max;
			return max;
		}
	}

	public class Cake
	{
		public int R, H;

		public Cake(int r, int h)
		{
			R = r;
			H = h;
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