using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace CodeJam1A
{
	class ProblemC
	{
		void Solve()
		{
			var testCount = Int32.Parse(input[0]);

			var differences = new int[testCount];
			for (int test = 0; test < testCount; ++test)
			{
				var nums = input[2 + test * 2].Split(' ');
				var c1 = 0;
				var c2 = 0;
				for (var i = 0; i < 1000; ++i)
					if (Int32.Parse(nums[i]) > i && Math.Abs(Int32.Parse(nums[i]) - i) < 1000)
						++c1;
					else
						++c2;
				differences[test] = Math.Abs(c1 - c2);
			}

			var averageDifference = differences.Sum() / testCount;
			for (int test = 0; test < testCount; ++test)
			{
				output.Add(String.Format("Case #{0}: {1}", test + 1, (differences[test] < averageDifference ? "GOOD" : "BAD")));
			}
		}

		string inFile = "C://Users//luke//Desktop//C-small-attempt3.in";
		string outFile = "C://Users//luke//Desktop//out.txt";
		string[] input;
		List<String> output;

		static void Main(string[] args)
		{
			new ProblemC();
		}

		ProblemC()
		{
			input = File.ReadAllLines(inFile);
			output = new List<string>();
			Solve();
			File.WriteAllLines(outFile, output);
		}
	}
}
