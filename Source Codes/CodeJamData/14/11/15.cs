using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "A-small-attempt0 (1)";

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
			var n = cin.NextInt();
			var l = cin.NextInt();
			var flow = new List<long>();
			var req = new List<long>();
			for (var i = 0; i < n; i++)
			{
				var str = cin.Next();
				flow.Add(Parse(str));
				
			}

			for (var i = 0; i < n; i++)
			{
				var str = cin.Next();
				req.Add(Parse(str));
			}

			flow.Sort();
			req.Sort();

			var visited = new List<List<long>>();
			var queue = new Queue<State>();
			queue.Enqueue(new State { Count = 0, Flow = new List<long>(flow) });
			visited.Add(new List<long>(flow));
			while (queue.Any())
			{
				var state = queue.Dequeue();
				if (AreEqual(state.Flow, req))
				{
					Console.WriteLine(state.Count);
					return;
				}
				var sw = 1L;
				for (var i = 0; i < l; i++)
				{
					var newFlow = new List<long>();
					foreach (var item in state.Flow)
					{
						newFlow.Add(item ^ sw);
					}
					newFlow.Sort();
					var exist = false;
					foreach (var v in visited)
					{
						if (AreEqual(newFlow, v))
						{
							exist = true;
							break;
						}
					}
					if (!exist)
					{
						visited.Add(new List<long>(newFlow));
						queue.Enqueue(new State { Count = state.Count + 1, Flow = newFlow });
					}
					sw *= 2;
				}
			}
			Console.WriteLine("NOT POSSIBLE");
		}

		private static bool AreEqual(List<long> a, List<long> b)
		{
			for (var i = 0; i < a.Count; i++)
			{
				if (a[i] != b[i])
				{
					return false;
				}
			}
			return true;
		}

		public class State
		{
			public int Count { get; set; }
			public List<long> Flow { get; set; }
		}

		private static long Parse(string str)
		{
			var num = 0L;
			var pow = 1L;
			for (var j = str.Length - 1; j >= 0; j--)
			{
				if (str[j] == '1')
				{
					num += pow;
				}
				pow *= 2;
			}
			return num;
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