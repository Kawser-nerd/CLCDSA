using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "B-large";

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
			var ac = cin.NextInt();
			var aj = cin.NextInt();
			var time = new int[1440];
			var countC = 0;
			for (var i = 0; i < ac; i++)
			{
				var start = cin.NextInt();
				var end = cin.NextInt();
				countC += end - start;
				for (var j = start; j < end; j++)
				{
					time[j] = 1;
				}
			}
			var countJ = 0;
			for (var i = 0; i < aj; i++)
			{
				var start = cin.NextInt();
				var end = cin.NextInt();
				countJ += end - start;
				for (var j = start; j < end; j++)
				{
					time[j] = 2;
				}
			}
			while (countC != 720 || countJ != 720)
			{
				var gap = int.MaxValue;
				var gapIdx = 0;
				var gapType = 0;
				if (time[0] == 0)
				{
					var end = time[time.Length - 1];
					var start = time[time.Length - 1];
					var count = 0;
					var idx = 0;
					for (var i = 0; true; i++)
					{
						if (time[i] == 0)
						{
							count++;
						}
						else
						{
							end = time[i];
							break;
						}
					}
					for (var i = time.Length - 1; true; i--)
					{
						if (time[i] == 0)
						{
							count++;
							idx = i;
						}
						else
						{
							start = time[i];
							break;
						}
					}
					if (end == start && count < gap)
					{
						gap = count;
						gapIdx = idx;
						gapType = end;
					}
				}
				else if (time[time.Length - 1] == 0)
				{
					var end = time[0];
					var start = time[time.Length - 1];
					var count = 0;
					var idx = 0;
					for (var i = time.Length - 1; true; i--)
					{
						if (time[i] == 0)
						{
							count++;
							idx = i;
						}
						else
						{
							start = time[i];
							break;
						}
					}
					if (end == start && count < gap)
					{
						gap = count;
						gapIdx = idx;
						gapType = end;
					}
				}
				var j = 0;
				while (time[j] == 0)
				{
					j++;
				}
				while (j < time.Length)
				{
					var start = time[j];

					while (j < time.Length && time[j] == start)
					{
						j++;
					}
					if (j == time.Length)
					{
						break;
					}
					var count = 0;
					var idx = j;
					while (j < time.Length && time[j] == 0)
					{
						count++;
						j++;
					}
					if (j == time.Length)
					{
						break;
					}
					var end = time[j];
					if (start == end && count < gap)
					{
						gap = count;
						gapIdx = idx;
						gapType = end;
					}
				}
				if (gap == int.MaxValue)
				{
					break;
				}
				if (gapType == 1)
				{
					if (720 - countC >= gap)
					{
						for (var i = 0; i < gap; i++)
						{
							time[(i + gapIdx) % 1440] = 1;
						}
						countC += gap;
					}
					else
					{
						time[gapIdx] = 2;
						countJ++;
					}
				}
				else
				{
					if (720 - countJ >= gap)
					{
						for (var i = 0; i < gap; i++)
						{
							time[(i + gapIdx) % 1440] = 2;
						}
						countJ += gap;
					}
					else
					{
						time[gapIdx] = 1;
						countC++;
					}
				}
			}
			var pat = new List<int>();
			pat.Add(time.First(x => x != 0));
			for (var i = 0; i < time.Length; i++)
			{
				if (time[i] != 0 && time[i] != pat[pat.Count - 1])
				{
					pat.Add(time[i]);
				}
			}
			if (pat[0] == pat[pat.Count - 1])
			{
				pat.RemoveAt(pat.Count - 1);
			}
			var res = pat.Count;
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