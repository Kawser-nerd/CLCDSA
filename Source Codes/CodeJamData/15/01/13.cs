using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
	class Program
	{

		static void Main(string[] args)
		{
			var input = @"5
4 11111
1 09
5 110011
0 1
0 001901";
			input = File.ReadAllText("input.txt");

			var outputStr = Solve(input);

			Console.WriteLine(outputStr);
			File.WriteAllText(GetFileName(), outputStr);

			//Console.ReadLine();
		}

		static string Solve(string input)
		{
			var parts = input.Split(new char[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);
			var testCasesStr = long.Parse(parts[0]);
			List<long[]> testCases = new List<long[]>();
			for (var i = 0; i < testCasesStr; i++)
			{
				var testCaseStr = parts[i + 1];
				var testCaseParts = testCaseStr.Split(' ');
				//var maxShine = long.Parse(testCaseParts[0]);
				testCases.Add(testCaseParts[1].Select(c => long.Parse(c.ToString())).ToArray());
			}

			List<string> output = new List<string>();
			for (var i = 0; i < testCases.Count; i++)
			{
				output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(testCases[i])));
			}
			return string.Join(Environment.NewLine, output);
		}

		static long Solve(long[] arr)
		{
			long[] sums = new long[arr.Length];
			sums[0] = 0;
			for (var i = 1; i < arr.Length; i++)
			{
				sums[i] = sums[i - 1] + arr[i - 1];
			}

			long friends = 0;
			for (var i = arr.Length - 1; i >= 0; i--)
			{
				friends += Math.Max(0, i - sums[i] - friends);
			}

			return friends;
		}

		static string GetFileName()
		{
			return DateTime.Now.Ticks.ToString() + ".txt";
		}
	}
}
