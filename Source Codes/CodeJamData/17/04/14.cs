using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "D-small-attempt1";

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
			var n = cin.NextInt();
			var m = cin.NextInt();
			var grid = new char[n + 1, n + 1];
			for (var i = 0; i < m; i++)
			{
				var ch = cin.NextString()[0];
				var r = cin.NextInt();
				var c = cin.NextInt();
				grid[r, c] = ch;
			}

			// +
			var orig = grid.Clone() as char[,];
			for (var i = 1; i <= n; i++)
			{
				if (grid[1, i] == 0)
				{
					grid[1, i] = '+';
				}
				if (grid[n, i] == 0)
				{
					grid[n, i] = '+';
				}
			}
			if (grid[1, 1] != 'x' && grid[n, n] != 'x')
			{
				if (orig[1, 1] == 0)
				{
					grid[1, 1] = (char) 0;
				}
				else
				{
					grid[n, n] = (char)0;
				}
				
			}
			if (grid[1, n] != 'x' && grid[n, 1] != 'x')
			{
				if (orig[1, n] == 0)
				{
					grid[1, n] = (char) 0;
				}
				else
				{
					grid[n, 1] = (char)0;
				}
				
			}
			for (var i = 2; i < n; i++)
			{
				for (var j = 1; j <= n; j++)
				{
					if (grid[i, j] == '+' || grid[i, j] == 'o')
					{
						var x = j - (i - 1);
						if (x >= 1 && x <= n && grid[1, x] == '+')
						{
							grid[1, x] = (char) 0;
						}
						x = j + (i - 1);
						if (x >= 1 && x <= n && grid[1, x] == '+')
						{
							grid[1, x] = (char)0;
						}
						x = j - (n - i);
						if (x >= 1 && x <= n && grid[n, x] == '+')
						{
							grid[n, x] = (char)0;
						}
						x = j + (n - i);
						if (x >= 1 && x <= n && grid[n, x] == '+')
						{
							grid[n, x] = (char)0;
						}
					}
				}
			}

			// x
			var rows = new bool[n + 1];
			var cols = new bool[n + 1];
			for (var y = 1; y <= n; y++)
			{
				for (var x = 1; x <= n; x++)
				{
					if (grid[y, x] == 'o' || grid[y, x] == 'x')
					{
						rows[y] = true;
						cols[x] = true;
					}
				}
			}
			for (var i = 1; i <= n; i++)
			{
				if (!rows[i])
				{
					for (var j = 1; j <= n; j++)
					{
						if (!cols[j] && grid[i, j] != '+')
						{
							grid[i, j] = 'x';
							rows[i] = true;
							cols[j] = true;
							break;
						}
					}
				}
			}

			// o
			var dx = new[] {-1, 1, -1, 1};
			var dy = new[] {-1, -1, 1, 1};

			for (var y = 1; y <= n; y++)
			{
				for (var x = 1; x <= n; x++)
				{
					if (grid[y, x] == '+' || grid[y, x] == 'x')
					{
						var isOk = true;
						for (var i = 1; i <= n && isOk; i++)
						{
							if (i != x)
							{
								if (grid[y, i] == 'x' || grid[y, i] == 'o')
								{
									isOk = false;
								}
							}
						}
						for (var i = 1; i <= n && isOk; i++)
						{
							if (i != y)
							{
								if (grid[i, x] == 'x' || grid[i, x] == 'o')
								{
									isOk = false;
								}
							}
						}
						for (var i = 0; i < dx.Length && isOk; i++)
						{
							var xx = x + dx[i];
							var yy = y + dy[i];
							while (xx >= 1 && xx <= n && yy >= 1 && yy <= n && isOk)
							{
								if (grid[yy, xx] == '+' || grid[yy, xx] == 'o')
								{
									isOk = false;
								}
								xx += dx[i];
								yy += dy[i];
							}
						}
						if (isOk)
						{
							grid[y, x] = 'o';
						}
					}
				}
			}
			var points = 0;
			var changes = new List<Tuple<char, int, int>>();
			for (var y = 1; y <= n; y++)
			{
				for (var x = 1; x <= n; x++)
				{
					if (grid[y, x] == 'x' || grid[y, x] == '+')
					{
						points++;
					}
					else if (grid[y, x] == 'o')
					{
						points += 2;
					}
					if (grid[y, x] != orig[y, x])
					{
						changes.Add(Tuple.Create(grid[y, x], y, x));
					}
				}
			}
			Console.WriteLine(points + " " + changes.Count);
			foreach (var change in changes)
			{
				Console.WriteLine(change.Item1 + " " + change.Item2 + " " + change.Item3);
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