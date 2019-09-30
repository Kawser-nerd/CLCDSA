using System;
using System.Collections;
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
			var hd = cin.NextInt();
			var ad = cin.NextInt();
			var hk = cin.NextInt();
			var ak = cin.NextInt();
			var b = cin.NextInt();
			var d = cin.NextInt();
			Queue<Tuple<State, int>> queue = new Queue<Tuple<State, int>>();
			var visited = new HashSet<State>();
			var start = new State(hd, ad, hk, ak);
			visited.Add(start);
			queue.Enqueue(Tuple.Create(start, 1));
			var best = int.MaxValue;
			while (queue.Any())
			{
				if (visited.Count > 1000000)
				{
					break;
				}
				var front = queue.Dequeue();
				var turn = front.Item2;
				var state = front.Item1;
				// attack;
				var temp = new State(state.Hd, state.Ad, state.Hk, state.Ak);
				temp.Hk -= temp.Ad;
				if (temp.Hk <= 0)
				{
					best = Math.Min(best, turn);
				}
				else
				{
					temp.Hd -= temp.Ak;
					if (temp.Hd > 0)
					{
						if (!visited.Contains(temp))
						{
							visited.Add(temp);
							queue.Enqueue(Tuple.Create(temp, turn + 1));
						}
					}
				}
				// buff
				temp = new State(state.Hd, state.Ad, state.Hk, state.Ak);
				temp.Ad += b;
				temp.Hd -= temp.Ak;
				if (temp.Hd > 0 && temp.Ad < temp.Hk + 200)
				{
					if (!visited.Contains(temp))
					{
						visited.Add(temp);
						queue.Enqueue(Tuple.Create(temp, turn + 1));
					}
				}
				// cure
				temp = new State(state.Hd, state.Ad, state.Hk, state.Ak);
				temp.Hd = hd;
				temp.Hd -= temp.Ak;
				if (temp.Hd > 0)
				{
					if (!visited.Contains(temp))
					{
						visited.Add(temp);
						queue.Enqueue(Tuple.Create(temp, turn + 1));
					}
				}
				// debuff
				temp = new State(state.Hd, state.Ad, state.Hk, state.Ak);
				temp.Ak = Math.Max(0, temp.Ak - d);
				temp.Hd -= temp.Ak;
				if (temp.Hd > 0)
				{
					if (!visited.Contains(temp))
					{
						visited.Add(temp);
						queue.Enqueue(Tuple.Create(temp, turn + 1));
					}
				}
			}
			if (best == int.MaxValue)
			{
				Console.WriteLine("IMPOSSIBLE");
			}
			else
			{
				Console.WriteLine(best);
			}
		}
	}

	public class State
	{
		public int Hd, Ad, Hk, Ak;

		public State(int hd, int ad, int hk, int ak)
		{
			Hd = hd;
			Ad = ad;
			Hk = hk;
			Ak = ak;
		}

		public override int GetHashCode()
		{
			return (Hd << 10) + (Ad << 8) + (Hk << 6) + (Ak << 4);
		}

		public override bool Equals(object obj)
		{
			var state = (State) obj;
			return Hd == state.Hd && Ad == state.Ad && Hk == state.Hk && Ak == state.Ak;
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