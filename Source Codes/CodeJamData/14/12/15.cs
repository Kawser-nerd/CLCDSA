using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "B-large (1)";

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

		private const int MAX = 1050;

		private static int[][] mem;
		private static int[][] l;

		private static void Solve()
		{
			mem = new int[MAX][];
			for (var i = 0; i < MAX; i++)
			{
				mem[i] = new int[MAX];
				for (var j = 0; j < MAX; j++)
				{
					mem[i][j] = -1;
				}
			}
			l = new int[MAX][];
			for (var i = 0; i < MAX; i++)
			{
				l[i] = new int[MAX];
				for (var j = 0; j < MAX; j++)
				{
					l[i][j] = -1;
				}
			}
			var n = cin.NextInt();
			var nodeMap = new Node[MAX];
			for (var i = 0; i < n - 1; i++)
			{
				var x = cin.NextInt();
				var y = cin.NextInt();
				if (nodeMap[x] == null)
				{
					nodeMap[x] = new Node { Name = x };
				}
				if (nodeMap[y] == null)
				{
					nodeMap[y] = new Node { Name = y };
				}
				nodeMap[x].Children.Add(nodeMap[y]);
				nodeMap[y].Children.Add(nodeMap[x]);
			}
			var best = int.MaxValue;
			foreach (var node in nodeMap)
			{
				if (node == null)
				{
					continue;
				}
				node.Parent = MAX-1;
				best = Math.Min(best, Calc(node));
			}
			Console.WriteLine(best);
		}

		private static int Calc(Node node)
		{
			if (mem[node.Name][node.Parent] != -1)
			{
				return mem[node.Name][node.Parent];
			}
			var children = node.Children.Where(x => x.Name != node.Parent).ToList();
			foreach (var c in children)
			{
				c.Parent = node.Name;
			}
			if (children.Count == 0)
			{
				return 0;
			}
			if (children.Count == 1)
			{
				foreach (var c in children)
				{
					if (c.Name != node.Parent)
					{
						return Len(c);
					}
				}
			}
			if (children.Count == 2)
			{
				var sum = 0;
				foreach (var c in children)
				{
					if (c.Name != node.Parent)
					{
						sum += Calc(c);
					}
				}
			}
			var best = int.MaxValue;
			for (var i = 0; i < children.Count; i++)
			{
				if (children[i].Name == node.Parent)
				{
					continue;
				}
				for (var j = i + 1; j < children.Count; j++)
				{
					if (children[j].Name == node.Parent)
					{
						continue;
					}
					var len = 0;
					for (var k = 0; k < children.Count; k++)
					{
						if (children[k].Name == node.Parent)
						{
							continue;
						}
						if (k != i && k != j)
						{
							len += Len(children[k]);
						}
					}
					best = Math.Min(best, Calc(children[i]) + Calc(children[j]) + len);
				}
			}
			mem[node.Name][node.Parent] = best;
			return best;
		}

		public static int Len(Node node)
		{
			if (l[node.Name][node.Parent] != -1)
			{
				return l[node.Name][node.Parent];
			}
			//Debug.WriteLine(node.Name);
			var len = 1;
			var children = node.Children;//.Where(x => x.Name != node.Parent).ToList();
			foreach (var c in children)
			{
				if (c.Name == node.Parent)
				{
					continue;
				}
				c.Parent = node.Name;
				len += Len(c);
			}
			l[node.Name][node.Parent] = len;
			return len;
		}

		public class Node
		{
			public int Parent { get; set; }
			public int Name { get; set; }
			public List<Node> Children { get; set; }

			public Node()
			{
				Children = new List<Node>();
			}
		}
	}

	internal class Scanner
	{
		private string[] s = new string[0];
		private int i;
		private readonly char[] cs = { ' ' };

		public string Next()
		{
			if (i < s.Length) return s[i++];
			var line = Console.ReadLine() ?? string.Empty;
			if (line == string.Empty)
			{
				return Next();
			}
			s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
			i = 1;
			return s.First();
		}

		public double NextDouble()
		{
			return double.Parse(Next());
		}

		public int NextInt()
		{
			return int.Parse(Next());
		}

		public long NextLong()
		{
			return long.Parse(Next());
		}
	}
}