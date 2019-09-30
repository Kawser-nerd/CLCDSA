using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace GCJ1B_3
{

	class Problem
	{

		public Problem()
		{
		}


		public int CardCount { get; set; }

		public int CardIndex { get; set; }


		public int Solve()
		{
			int queryPosition = CardIndex;
			for (int card = 1; card <= CardCount; card++)
			{
				int cardsLeft = CardCount - card + 1;
				int removalIndex = (card - 1) % cardsLeft + 1;
				if (removalIndex < queryPosition)
				{
					queryPosition = queryPosition - removalIndex;
				}
				else if (removalIndex > queryPosition)
				{
					queryPosition = queryPosition + cardsLeft - removalIndex;
				}
				else
				{
					return card;
				}
			}

			throw new InvalidOperationException("bug");
		}

	}

	class Program
	{
		static void Main(string[] args)
		{
			int testCaseCount = ReadInt32();
			for (int testCaseNumber = 1; testCaseNumber <= testCaseCount; testCaseNumber++)
			{
				var formattedResult = ProcessTestCase();
				Console.WriteLine(string.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}",
					testCaseNumber, formattedResult));
			}
		}

		static string ProcessTestCase()
		{
			int cardCount = ReadInt32();

			var query = ReadInt32List();

			var resultText = new StringBuilder();

			for (int queryIndex = 1; queryIndex < query.Length; queryIndex++)
			{
				if (resultText.Length > 0)
					resultText.Append(' ');

				var problem = new Problem();
				problem.CardCount = cardCount;
				problem.CardIndex = query[queryIndex];
				var result = problem.Solve();
				resultText.Append(result.ToString(CultureInfo.InvariantCulture));
			}

			return resultText.ToString();
		}

		static int ParseInt32(string value)
		{
			return int.Parse(value, CultureInfo.InvariantCulture);
		}

		static int ReadInt32()
		{
			return ParseInt32(Console.ReadLine());
		}

		static int[] ReadInt32List()
		{
			var items = Console.ReadLine().Split(' ');
			return items.Select(item => ParseInt32(item)).ToArray();
		}

	}

}
