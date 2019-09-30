using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemC
{
	class Program
	{
		private const string InputFile = "Input.txt";
		private const string OutputFile = "Output.txt";

		static void Main(string[] args)
		{
			string[] lines = File.ReadAllLines(InputFile);
			int caseCount = Int32.Parse(lines[0]);
			int currentLine = 1;
			File.WriteAllText(OutputFile, string.Empty);
			for (int i = 0; i < caseCount; ++i)
			{
				string[] split = lines[currentLine++].Split();
				int prisonSize = Int32.Parse(split[0]);

				List<int> prisoners = new List<int>();
				split = lines[currentLine++].Split();
				foreach (string s in split)
					prisoners.Add(Int32.Parse(s));

				int coins = Solve(prisonSize, prisoners);
				File.AppendAllText(OutputFile, String.Format("Case #{0}: {1}\n", i + 1, coins));
			}
		}

		private static int Solve(int prisonSize, List<int> prisoners)
		{
			Dictionary<KeyValuePair<int, int>, int> cache = new Dictionary<KeyValuePair<int, int>, int>();
			return SolveDfs(prisoners, cache, 1, prisonSize);
		}

		private static int SolveDfs(List<int> prisoners, Dictionary<KeyValuePair<int, int>, int> cache, int left, int right)
		{
			var pair = new KeyValuePair<int, int>(left, right);
			if (cache.ContainsKey(pair))
				return cache[pair];

			int answer;
			if (prisoners.Count == 0)
			{
				answer = 0;
			}
			else
			{
				int bestAnswer = -1;
				for (int i = 0; i < prisoners.Count; ++i)
				{
					int prisoner = prisoners[i];
					List<int> prisonersLeft = prisoners.Take(i).ToList();
					List<int> prisonersRight = prisoners.Skip(i + 1).ToList();
					
					int curAnswer =
						SolveDfs(prisonersLeft, cache, left, prisoner - 1) +
						SolveDfs(prisonersRight, cache, prisoner + 1, right) +
						right - left;
					if (bestAnswer == -1 || curAnswer < bestAnswer)
						bestAnswer = curAnswer;
				}

				answer = bestAnswer;
			}

			cache[pair] = answer;
			return answer;
		}
	}
}
