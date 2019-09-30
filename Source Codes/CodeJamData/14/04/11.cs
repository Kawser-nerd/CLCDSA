using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace ProblemD
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
					reader.ReadLine();
					var weigts1 = reader.ReadLine().Split(' ').Select(x => double.Parse(x, CultureInfo.InvariantCulture)).ToList();
					var weigts2 = reader.ReadLine().Split(' ').Select(x => double.Parse(x, CultureInfo.InvariantCulture)).ToList();

					int deceitFulWarPoints;
					int warPoints;
					Solve(weigts1, weigts2, out deceitFulWarPoints, out warPoints);

					writer.WriteLine("Case #{0}: {1} {2}", i, deceitFulWarPoints, warPoints);
				}
			}
		}

		private static void Solve(List<double> weights1, List<double> weights2, out int deceitFulWarPoints, out int warPoints)
		{
			deceitFulWarPoints = 0;
			warPoints = 0;

			var n = weights1.Count;
			weights1.Sort();
			weights2.Sort();

			var w1 = new List<double>(weights1);
			var w2 = new List<double>(weights2);
			for (int i = 0; i < n; i++)
			{
				if (w1[0] < w2[0])
				{
					w1.RemoveAt(0);
					w2.RemoveAt(w2.Count-1);
				}
				else
				{
					w1.RemoveAt(0);
					w2.RemoveAt(0);
					deceitFulWarPoints++;
				}
			}

			w1 = new List<double>(weights1);
			w2 = new List<double>(weights2);
			for (int i = 0; i < n; i++)
			{
				if (w1[0] < w2[0])
				{
					w1.RemoveAt(0);
					w2.RemoveAt(0);
				}
				else
				{
					var vIdx = w2.Select((v, idx) => new { v, idx }).FirstOrDefault(w => w.v > w1[0]);
					w1.RemoveAt(0);
					if (vIdx != null)
					{
						w2.RemoveAt(vIdx.idx);
					}
					else
					{
						w2.RemoveAt(0);
						warPoints++;
					}
				}
			}
		}
	}
}
