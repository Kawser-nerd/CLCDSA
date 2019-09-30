using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Round2ProblemC
{
	class Program
	{
		private const string InputFile = "Input.txt";
		private const string OutputFile = "Output.txt";

		static void Main()
		{
			string[] lines = File.ReadAllLines(InputFile);
			File.WriteAllText(OutputFile, String.Empty);

			int testCount = Int32.Parse(lines[0]);
			int currentLine = 1;
			for (int i = 0; i < testCount; ++i)
			{
				string[] nkSplit = lines[currentLine++].Split();
				int n = Int32.Parse(nkSplit[0]);
                List<long[]> stocks = new List<long[]>();
				for (int j = 0; j < n; ++j)
				{
					string[] stockSplit = lines[currentLine++].Split();
					long[] stock = new long[stockSplit.Length];
					for (int k = 0; k < stockSplit.Length; ++k)
						stock[k] = Int32.Parse(stockSplit[k]);

					stocks.Add(stock);
				}

				bool[,] graph = BuildContradictionMatrix(stocks);
				int answer = Int32.MaxValue;
				ColorGraphDfs(graph, new int[stocks.Count], 0, stocks.Count, 0, ref answer);

				File.AppendAllText(OutputFile, String.Format("Case #{0}: {1}\n", i + 1, answer));
			}
		}

		private static void ColorGraphDfs(bool[,] graph, int[] colors, int currentVertex, int vertexCount, int colorCount, ref int bestAnswer)
		{
			if (colorCount >= bestAnswer)
				return;

			if (currentVertex == vertexCount)
			{
				bestAnswer = colorCount;
				return;
			}

			bool[] colorsUsed = new bool[colorCount + 1];
			for (int i = 0; i < currentVertex; ++i)
				if (graph[currentVertex, i])
					colorsUsed[colors[i]] = true;

			for (int i = 0; i < colorsUsed.Length; ++i)
			{
				if (colorsUsed[i])
					continue;
				{
					colors[currentVertex] = i;
					ColorGraphDfs(graph, colors, currentVertex + 1, vertexCount, i == colorCount ? colorCount + 1 : colorCount, ref bestAnswer);
				}
			}
		}

		private static bool[,] BuildContradictionMatrix(List<long[]> stocks)
		{
			bool[,] result = new bool[stocks.Count, stocks.Count];
			for (int i = 0; i < stocks.Count; ++i)
				for (int j = i + 1; j < stocks.Count; ++j)
					for (int k = 0; k < stocks[i].Length - 1; ++k)
					{
						if ((stocks[i][k] - stocks[j][k]) * (stocks[i][k + 1] - stocks[j][k + 1]) <= 0)
						{
							result[i, j] = result[j, i] = true;
							break;
						}
					}

			return result;
		}
	}
}
