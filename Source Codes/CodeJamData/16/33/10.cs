using GoogleCodeJam.Common;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FashionPolice
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFile input = new InputFile("C-small-attempt1.in");
			OutputFile output = new OutputFile("output-small.txt");

			int[] values = input.ReadIntArray();
			int TEST_COUNT = values[0];

			for (int i = 0; i < TEST_COUNT; i++)
			{
				TestCase testCase = new TestCase(input);
				output.WriteCase(i + 1, testCase.GetSolution());
			}

			output.Close();
		}
	}

	class TestCase
	{
		private readonly int J;
		private readonly int P;
		private readonly int S;
		private readonly int K;

		public TestCase(InputFile input)
		{
			int[] inputs = input.ReadIntArray();
			J = inputs[0];
			P = inputs[1];
			S = inputs[2];
			K = inputs[3];
		}

		public string GetSolution()
		{
			int totalOutfits = J * P * S;
			int totalCombJP = J * P;
			int totalCombJS = J * S;
			int totalCombPS = P * S;
			
			int[] chances = new int[] { totalOutfits, totalCombJP * K, totalCombJS * K, totalCombPS * K };
			int days = chances.Min();

//			int[,] usedJP = new int[J + 1, P + 1];
//			int[,] usedJS = new int[J + 1, S + 1];
//			int[,] usedPS = new int[P + 1, S + 1];

			bool done = false;
			List<string> outfits = new List<string>();
			int skipNumber = 0;
			BitArray skipPattern = new BitArray((J + 1) * (P + 1) * (S + 1));

			while (!done)
			{
				outfits.Clear();
				int skips = 0;
				int[,] usedJP = new int[J + 1, P + 1];
				int[,] usedJS = new int[J + 1, S + 1];
				int[,] usedPS = new int[P + 1, S + 1];

				int[] outfit = new int[3];
				for (int i = 1; i <= J; i++)
				{
					outfit[0] = i;

					for (int j = 1; j <= P; j++)
					{
						outfit[1] = j;

						for (int k = 1; k <= S; k++)
						{
							outfit[2] = k;

							if (usedJP[i, j] < K && usedJS[i, k] < K && usedPS[j, k] < K)
							{
								if (skipPattern[i * j * k])
								{
									skips++;
								}
								else
								{
									string outfitStr = string.Join(" ", outfit);
									outfits.Add(outfitStr);

									usedJP[i, j]++;
									usedJS[i, k]++;
									usedPS[j, k]++;
								}
							}
						}
					}
				}

				if (outfits.Count != days)
				{
					skipNumber++;
					skipPattern = new BitArray(new int[] { skipNumber });
				}
				else
					done = true;
			}

			StringBuilder result = new StringBuilder();
			result.AppendLine(days.ToString());
			foreach (string outfitStr in outfits)
				result.AppendLine(outfitStr);

			return result.ToString().TrimEnd('\r', '\n');
		}
	}
}

