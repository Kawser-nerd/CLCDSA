using Combinatorics.Collections;
using ConsoleApplication1.Helpers;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1.OtherTasks.CodeJam2017
{
	public class PancakeFlipper
	{
		public void Go(string[] args)
		{
			//			Solve(@"3
			//---+-++- 3
			//+++++ 4
			//-+-+- 4".SplitToLines());

			//Console.WriteLine(SolveBrute("---+-++-", 3));

			SolveArgs(args);
			//Performance();
		}

		public void SolveArgs(string[] args)
		{
			Solve(File.ReadAllLines(args[0]));
		}

		public void FixWrong(string[] args)
		{
			var task = File.ReadAllLines(args[0]);
			var T = int.Parse(task[0]);
			for (var t = 0; t < T; t++)
			{
				var splits = task[t + 1].Split();
				var s = splits[0];
				var k = int.Parse(splits[1]);

				var brute = SolveBrute(s, k);
				var sol = SolveLeftToRight(s, k);

				if (brute != sol)
				{
					Console.WriteLine($"{s} brute={brute} sol={sol}");
					throw new InvalidOperationException();
				}

				Console.WriteLine("Case #{0}: {1}", t + 1, sol);
			}
		}

		public void Performance()
		{
			var rnd = new Random(123);

			for (var t = 0; t < 100; t++)
			{
				var s = RandomGenerator.RandomString(rnd, "-+", 1000);

				Console.WriteLine(t);
				foreach (var k in new[] { 1, 10, 100, 300, 500, 800, 900, 990, 999 })
					Console.WriteLine(new { k, sol = SolveLeftToRight(s, k) });
			}
		}

		public void Compare()
		{
			var rnd = new Random(123);
			for (var t = 0; t < 1000; t++)
			{
				var s = RandomGenerator.RandomString(rnd, "-+", rnd.Next(2, 20));
				var k = rnd.Next(2, s.Length);
				var brute = SolveBrute(s, k);
				var sol = SolveLeftToRight(s, k);

				if (brute != sol)
				{
					Console.WriteLine($"{s} brute={brute} sol={sol}");
					throw new InvalidOperationException();
				}
			}
		}

		public void Solve(string[] task)
		{
			var T = int.Parse(task[0]);
			for (var t = 0; t < T; t++)
			{
				var splits = task[t + 1].Split();
				var s = splits[0];
				var k = int.Parse(splits[1]);
				Console.WriteLine("Case #{0}: {1}", t + 1, SolveLeftToRight(s, k));
			}
		}

		public string SolveBrute(string s, int k)
		{
			var best = int.MaxValue;
			IList<int> bestComb = null;

			foreach (var comb in new Variations<int>(new[] { 0, 1 }, s.Length - k + 1, GenerateOption.WithRepetition))
			{
				var result = s.ToCharArray();
				for (var start = 0; start < comb.Count; start++)
					if (comb[start] == 1)
					{
						for (var i = 0; i < k; i++)
							result[start + i] = result[start + i] == '-' ? '+' : '-';
					}

				if (result.All(i => i == '+'))
				{
					var size = comb.Count(i => i == 1);
					if (size < best)
					{
						best = size;
						bestComb = comb;
					}
				}
			}

			return bestComb == null ? "IMPOSSIBLE" : best.ToString();
		}

		public string SolveLeftToRight(string S, int k)
		{
			var s = S.ToCharArray();
			var size = 0;
			for (var start = 0; start <= S.Length - k; start++)
			{
				if (s[start] == '-')
				{
					for (var i = 0; i < k; i++)
						s[start + i] = s[start + i] == '-' ? '+' : '-';
					size++;
				}
			}

			if (s.Any(c => c == '-'))
				return "IMPOSSIBLE";

			return size.ToString();
		}
	}
}
