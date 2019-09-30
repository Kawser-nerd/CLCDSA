using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemA
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
					var answer1 = int.Parse(reader.ReadLine());
					List<int> line1 = new List<int>();

					for (int j = 1; j <= 4; j++)
					{
						var line = reader.ReadLine().Split(' ').Select(int.Parse).ToList();
						if (j == answer1) line1 = new List<int>(line);
					}

					var answer2 = int.Parse(reader.ReadLine());
					List<int> line2 = new List<int>();

					for (int j = 1; j <= 4; j++)
					{
						var line = reader.ReadLine().Split(' ').Select(int.Parse).ToList();
						if (j == answer2) line2 = new List<int>(line);
					}

					var intersect = line1.Intersect(line2);

					var res = "";
					if (!intersect.Any()) res = "Volunteer cheated!";
					else if (intersect.Count() > 1) res = "Bad magician!";
					else res = intersect.First().ToString();
						
					writer.WriteLine("Case #{0}: {1}", i, res);
				}
			}
		}
	}
}
