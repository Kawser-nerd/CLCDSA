using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace Codeforces
{
	internal class Template
	{
		private HashSet<int>[] adj = new HashSet<int>[100010];
		private HashSet<int>[] orig = new HashSet<int>[100010];
		private int[] color;

		private void Solve()
		{
			var n = cin.NextInt();
			color = new int[n + 1];
			for (var i = 1; i <= n; i++)
			{
				adj[i] = new HashSet<int>();
			}
			for (var i = 0; i < n - 1; i++)
			{
				var a = cin.NextInt();
				var b = cin.NextInt();
				adj[a].Add(b);
				adj[b].Add(a);
			}
			for (var i = 1; i <= n; i++)
			{
				orig[i] = new HashSet<int>(adj[i]);
			}
			var leaves = new List<int>();
			for (var i = 1; i <= n; i++)
			{
				if (adj[i].Count == 1)
				{
					leaves.Add(i);
				}
			}
			for (var i = 0; i < leaves.Count; i++)
			{
				var idx = leaves[i];
				if (adj[idx].Count == 0)
				{
					if (color[idx] != 0)
					{
						continue;
					}
					Console.WriteLine("First");
					return;
				}
				if(adj[idx].Count != 1) throw new AccessViolationException();
				color[idx] = 2;
				var next = adj[idx].Single();
				color[next] = 1;
				adj[next].Remove(idx);
				foreach (var a in adj[next])
				{
					adj[a].Remove(next);
					if (adj[a].Count == 1)
					{
						leaves.Add(a);
					}
					if (adj[a].Count == 0)
					{
						Console.WriteLine("First");
						return;
					}
				}
				adj[next].Clear();
			}
			Console.WriteLine("Second");
			return;
			var res = Dfs(1, -1);
			var output = res ? "First" : "Second";
			Console.WriteLine(output);
		}

		private bool Dfs(int u, int p)
		{
			if (color[u] == 1)
			{
				var hasBlack = false;
				foreach (var v in orig[u])
				{
					if (color[v] == 2)
					{
						hasBlack = true;
						break;
					}
				}
				if (!hasBlack)
				{
					return true;
				}
			}
			foreach (var v in orig[u])
			{
				if (v != p)
				{
					if (Dfs(v, u))
					{
						return true;
					}
				}
			}
			return false;
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