using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CoreTraining
{
	class Program
	{
		static void Main(string[] args)
		{
			int testCases = int.Parse(Console.ReadLine());

			for (int i = 0; i < testCases; i++)
			{
				SolveCase(i);
			}
		}

		private static void SolveCase(int caseIndex)
		{
			string[] tokens = Console.ReadLine().Split();
			int n = int.Parse(tokens[0]);
			int k = int.Parse(tokens[1]);

			// read training units
			double u = double.Parse(Console.ReadLine(), System.Globalization.CultureInfo.InvariantCulture);
			// read the cores
			tokens = Console.ReadLine().Split();
			double[] cores = new double[n];
			for (int i = 0; i < n; i++)
				cores[i] = double.Parse(tokens[i], System.Globalization.CultureInfo.InvariantCulture);

			// choose K best cores
			Array.Sort(cores);

			// get the best possible sum
			//double sum = u;
			//for (int i = n-k; i < n; i++)
			//	sum += cores[i];

			//double target = sum / k;
			// distribute training units
			//for (int i = n-k; i < n; i++)
			//{
			//	double diff = target - cores[i];
			//	cores[i] += diff;
			//	u -= diff;
			//}
			for (int i = n-k; i < n-1; i++)
			{
				double diff = cores[i + 1] - cores[i];

				int nCores = i - (n-k) + 1;
				if (diff * nCores > u)
					diff = u / nCores;

				for (int j = n-k; j <= i; j++)
				{
					cores[j] += diff;
					u -= diff;
				}
			}
			double remain = u / k;
			for (int i = n-k; i < n; i++)
				cores[i] += remain;

			// calculate the probability
			double p = 1;
			for (int i = n-k; i < n; i++)
				p *= cores[i];

			Console.WriteLine("Case #" + (caseIndex+1) + ": " + p.ToString(System.Globalization.CultureInfo.InvariantCulture));
		}
	}
}
