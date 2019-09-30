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
			var h = cin.NextInt();
			var w = cin.NextInt();
			var k = cin.NextInt();
			var map = new string[h];
			var start = new Point(0, 0);
			for (var i = 0; i < h; i++)
			{
				map[i] = cin.NextString();
				var idx = map[i].IndexOf("S");
				if (idx >= 0)
				{
					start.Y = i;
					start.X = idx;
				}
			}
			if (start.X == 0 || start.X == w - 1 || start.Y == 0 || start.Y == h - 1)
			{
				Console.WriteLine(0);
				return;
			}
			var visited = new bool[h, w];
			var dx = new[] {-1, 0, 1, 0};
			var dy = new[] {0, -1, 0, 1};
			var queue = new Queue<Tuple<Point, int>>();
			queue.Enqueue(Tuple.Create(start, 0));
			while (queue.Any())
			{
				var front = queue.Dequeue();
				var p = front.Item1;
				var step = front.Item2;
				if (visited[p.Y, p.X])
				{
					continue;;
				}
				visited[p.Y, p.X] = true;
				if (step == k)
				{
					continue;
				}
				for (var i = 0; i < dx.Length; i++)
				{
					var x = p.X + dx[i];
					var y = p.Y + dy[i];
					if (x >= 0 && x < w && y >= 0 && y < h && map[y][x] != '#')
					{
						queue.Enqueue(Tuple.Create(new Point(x, y), step + 1));
					}
				}
			}
			var best = int.MaxValue;
			for (var y = 0; y < h; y++)
			{
				for (var x = 0; x < w; x++)
				{
					if (visited[y, x])
					{
						var xl = (x+(k-1))/k;
						var xr = (((w - 1) - x) + (k - 1))/k;
						var yl = (y + (k - 1)) / k;
						var yr = (((h - 1) - y) + (k - 1)) / k;
						best = Math.Min(best, Math.Min(Math.Min(xl, xr), Math.Min(yl, yr)));
					}
				}
			}
			Console.WriteLine(best + 1);
		}

		public class Point
		{
			public int X, Y;

			public Point(int x, int y)
			{
				X = x;
				Y = y;
			}
		}

		private static readonly Scanner cin = new Scanner();

		private static void Main()
		{
#if DEBUG
			var inputText = File.ReadAllText(@"..\..\input.txt");
			var testCases = inputText.Split(new[] { "input" }, StringSplitOptions.RemoveEmptyEntries);
			var consoleOut = Console.Out;
			for (var i = 0; i < testCases.Length; i++)
			{
				var parts = testCases[i].Split(new[] { "output" }, StringSplitOptions.RemoveEmptyEntries);
				Console.SetIn(new StringReader(parts[0].Trim()));
				var stringWriter = new StringWriter();
				Console.SetOut(stringWriter);
				var sw = Stopwatch.StartNew();
				new Template().Solve();
				sw.Stop();
				var output = stringWriter.ToString();

				Console.SetOut(consoleOut);
				var color = ConsoleColor.Green;
				var status = "Passed";
				if (parts[1].Trim() != output.Trim())
				{
					color = ConsoleColor.Red;
					status = "Failed";
				}
				Console.ForegroundColor = color;
				Console.WriteLine("Test {0} {1} in {2}ms", i + 1, status, sw.ElapsedMilliseconds);
			}
			Console.ReadLine();
			Console.ReadKey();
#else
			new Template().Solve();
			Console.ReadLine();
#endif
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