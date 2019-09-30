using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "B-small-attempt2";

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
			var n = cin.NextLong();
			var p = cin.NextLong();
			var s = new long[n];
			for (var i = 0; i < n; i++)
			{
				s[i] = cin.NextLong();
			}
			var w = new long[n][];
			for (var i = 0; i < n; i++)
			{
				w[i] = new long[p];
				for (var j = 0; j < p; j++)
				{
					w[i][j] = cin.NextLong();
				}
			}
			if (n == 1)
			{
				var count = 0;
				var low = s[0]*90;
				var hi = s[0]*110;
				var ww = w[0].Select(x => x*100).OrderBy(x => x).ToArray();
				for (var i = 0; i < ww.Length; i++)
				{
					if (CanMake(low, hi, ww[i]).Item1 != long.MaxValue)
					{
						count++;
					}
				}
				
				Console.WriteLine(count);
				return;
			}
			var low1 = s[0]*90;
			var hi1 = s[0]*110;
			var low2 = s[1]*90;
			var hi2 = s[1]*110;
			var w1 = w[0].Select(x => x * 100).OrderBy(x => x).ToArray();
			var w2 = w[1].Select(x => x * 100).OrderBy(x => x).ToArray();
			var best = 0;

			var w2Ranges = new List<Tuple<long, long>>();
			for (var i = 0; i < w2.Length; i++)
			{
				w2Ranges.Add(CanMake(low2, hi2, w2[i]));
			}
			var w1Ranges = new List<Tuple<long, long>>();
			for (var i = 0; i < w1.Length; i++)
			{
				w1Ranges.Add(CanMake(low1, hi1, w1[i]));
			}
			var ww1 = w1Ranges.ToArray();

			do
			{
				var cnt = 0;
				for (var i = 0; i < p; i++)
				{
					if (w2Ranges[i].Item1 != long.MaxValue && ww1[i].Item1 != long.MaxValue)
					{
						if (w2Ranges[i].Item1 > ww1[i].Item2 || ww1[i].Item1 > w2Ranges[i].Item2)
						{

						}
						else
						{
							cnt++;
						}
					}
				}
				best = Math.Max(best, cnt);

			} while (NextPermutation(ww1));
			Console.WriteLine(best);
		}

		private Tuple<long, long> CanMake(long low, long hi, long val)
		{
			if (val < low)
			{
				return new Tuple<long, long>(long.MaxValue, long.MaxValue);
			}
			long? min = null;
			long max = 0;
			for (var i = 1; i < 1000010; i++)
			{
				if (low*i <= val && val <= hi*i)
				{
					if (min == null)
					{
						min = i;
					}
					max = i;
				}
				else if (min != null)
				{
					break;
				}
			}
			if (min == null) return new Tuple<long, long>(long.MaxValue, long.MaxValue);
			return Tuple.Create(min.Value, max);
		}

		public static bool NextPermutation<T>(T[] items) where T : IComparable
		{
			var i = -1;
			for (var x = items.Length - 2; x >= 0; x--)
			{
				if (items[x].CompareTo(items[x + 1]) < 0)
				{
					i = x;
					break;
				}
			}

			if (i == -1)
			{
				return false;
			}
			var j = 0;
			for (var x = items.Length - 1; x > i; x--)
			{
				if (items[x].CompareTo(items[i]) > 0)
				{
					j = x;
					break;
				}
			}
			var temp = items[i];
			items[i] = items[j];
			items[j] = temp;
			Array.Reverse(items, i + 1, items.Length - (i + 1));
			//var index = i + 1;
			//var endIndex = index + items.Length - (i + 1) - 1;
			//while (index < endIndex)
			//{
			//    temp = items[index];
			//    items[index] = items[endIndex];
			//    items[endIndex] = temp;
			//    index++;
			//    endIndex--;
			//}
			return true;
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