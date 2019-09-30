using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Mousetrap
{
	class Program
	{
		static void Main(string[] args)
		{
			string filename = "C-small-attempt1";

			TextReader reader = new StreamReader(filename + ".in");
			TextWriter writer = new StreamWriter(filename + ".out");

			long numCases = long.Parse(reader.ReadLine());

			for (int i = 0; i < numCases; i++)
			{
				int k = int.Parse(reader.ReadLine());

				string[] splits = reader.ReadLine().Split(' ');
				int numIndices = int.Parse(splits[0]);
				int[] indices = new int[numIndices];
				for (int n = 1; n <= numIndices; n++)
				{
					indices[n - 1] = int.Parse(splits[n]);
				}

				string answer = GetIndices(k, indices);
				writer.WriteLine("Case #" + (i + 1) + ": " + answer);
			}

			reader.Close();
			writer.Close();
		}

		static string GetIndices(int k, int[] indices)
		{
			List<int> indexesToGo = new List<int>();
			foreach (int n in indices)
			{
				indexesToGo.Add(n);
			}

			int[] board = new int[k];
			int currentCount = 1;
			int currentCard = 1;
			int currentIndex = 0;
			while (currentCard <= k)
			{
				currentIndex++;
				if (currentIndex > k)
					currentIndex = 1;

				if (board[currentIndex - 1] != 0)
				{
					continue;
				}
				if (currentCard == currentCount)
				{
					board[currentIndex - 1] = currentCard;
					currentCount = 1;
					currentCard++;
					indexesToGo.Remove(currentIndex);
					if (indexesToGo.Count == 0)
					{
						break;
					}
				}
				else
				{
					currentCount++;
				}
			}

			string answer = "";
			foreach (int i in indices)
			{
				answer += (answer == "" ? "" : " ") + board[i - 1];
			}
			return answer;
		}
	}
}
