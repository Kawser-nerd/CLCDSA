using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace CodeJam.Round1C
{
	public class ProblemC
	{
		public static void Main(string[] args)
		{
			using (var input = new StreamReader(File.OpenRead("../../Input.txt")))
			{
				using (var output = new StreamWriter(File.OpenWrite("../../Output.txt")))
				{
					long cases = long.Parse(input.ReadLine());

					for (long i = 0; i < cases; i++)
					{
						var result = GetResult(input);

						Console.WriteLine("Case #" + (i + 1) + ": " + result);
						output.WriteLine("Case #" + (i + 1) + ": " + result);
					}
				}
			}
		}

		public static string GetResult(StreamReader input)
		{
			string line = input.ReadLine();

			var splits = line.Split(' ');

			int C = int.Parse(splits[0]);
			int D = int.Parse(splits[1]);
			long V = long.Parse(splits[2]);

			line = input.ReadLine();

			splits = line.Split(' ');

			var denoms = new List<long>();

			for (int i = 0; i < D; i++)
			{
				denoms.Add(long.Parse(splits[i]));
			}

			long maxValue = 0;

			return BruteForce(denoms, 1, V).ToString();

			//return (denoms.Count - D).ToString();

		}
		public static int BruteForce(List<long> denoms, long t, long V)
		{
			if (!CanMakeChange(denoms, t))
			{				
				int minimum = 100;
				for (long i = 1; i <= t; i++)
				{
					if (denoms.IndexOf(i) == -1)
					{
						var clone = new List<long>(denoms);
						clone.Add(i);
						clone.Sort();

						minimum = Math.Min(BruteForce(clone, t, V), minimum);
					}
				}
				return 1 + minimum;
			}
			else if (t == V)
			{
				return 0;
			}
			else
			{
				return BruteForce(denoms, t + 1, V);
			}
		}

		public static bool CanMakeChange(List<long> denoms, long t)
		{
			List<bool> used = new List<bool>();
			for (int i = 0; i < denoms.Count; i++)
			{
				used.Add(false);
			}

			return CanMakeChange(denoms, t, used, 0);
		}


		public static bool CanMakeChange(List<long> denoms, long t, List<bool> used, long c)
		{
			if (t == c)
			{
				return true;
			}

			for (int i = 0; i < denoms.Count; i++)
			{
				if (denoms[i] <= t - c && !used[i])
				{
					var clone = new List<bool>(used);
					clone[i] = true;
					if (CanMakeChange(denoms, t, clone, c + denoms[i]))
					{
						return true;
					}
				}
			}
			return false;
		}
	}

}

