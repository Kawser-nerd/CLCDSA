using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemB
{
	class Program
	{
		static void Main(string[] args)
		{
			string inputFileName = args.Length > 0 ? args[0] : "A-large-practice.in";
			string outputFileName = inputFileName.Replace(".in", ".out");
			using (var reader = new StreamReader(inputFileName))
			using (var writer = new StreamWriter(outputFileName))
			{
				int t = int.Parse(reader.ReadLine());
				for (int i = 1; i <= t; i++)
				{
					var line = reader.ReadLine().Split(' ').Select(x => double.Parse(x, CultureInfo.InvariantCulture)).ToList();

					var res = Solve(line[0], line[1], line[2]);

					writer.WriteLine("Case #{0}: {1}", i, res.ToString("0.0000000", CultureInfo.InvariantCulture));
				}
			}
		}

		private static double Solve(double c, double f, double x)
		{
			double sec = 0.0;
			double currRate = 2.0;

			while (true)
			{
				if (x <= c) return sec + (x/currRate);
				else
				{
					if ((x - c)/currRate <= x/(currRate + f))
					{
						return sec + (x/currRate);
					}
					else
					{
						sec = sec + c/currRate;
						currRate = currRate + f;
					}
				}
			}
		}
	}
}
