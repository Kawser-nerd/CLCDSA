using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "C-small-attempt0";

		private static void Main()
		{
			Console.SetIn(new StreamReader(string.Format(@"C:\GoogleCodeJam\{0}.in", fileName)));
			Console.SetOut(new StreamWriter(string.Format(@"C:\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
			var t = cin.NextInt();
			for (var c = 1; c <= t; c++)
			{
				Console.Write("Case #{0}: ", c);
				Solve();
			}
		}

		private static void Solve()
		{
			var c = cin.NextInt();
			var d = cin.NextInt();
			var v = cin.NextInt();
			var dems = new List<int>();
			for (var i = 0; i < d; i++)
			{
				dems.Add(cin.NextInt());
			}
			dems.Sort();
			var impossible = new List<int>();
			for (var i = 1; i <= v; i++)
			{
				var can = false;
				var items = dems.ToArray();
				do
				{
					var sum = 0;
					for (var j = 0; j < items.Length; j++)
					{
						sum += items[j];
						if (sum == i)
						{
							can = true;
							break;
						}
					}
				} while (NextPermutation(items) && !can);
				if (!can)
				{
					impossible.Add(i);
					dems.Add(i);
					dems.Sort();
				}
			}
			Console.WriteLine(impossible.Count);
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