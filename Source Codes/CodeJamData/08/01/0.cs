using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace GCJ0_1
{

	class Problem
	{

		public Problem(IEnumerable<string> searchEngines, IEnumerable<string> queries)
		{
			SearchEngines = new List<string>(searchEngines);
			Queries = new List<string>(queries);
		}


		public IList<string> SearchEngines { get; private set; }

		public IList<string> Queries { get; private set; }


		public int Solve()
		{
			int?[] lastResults;
			int?[] currentResults = new int?[SearchEngines.Count];

			for (int searchEngineIndex = 0; searchEngineIndex < SearchEngines.Count; searchEngineIndex++)
				currentResults[searchEngineIndex] = 0;

			foreach (string query in Queries)
			{
				lastResults = currentResults;
				currentResults = new int?[SearchEngines.Count];

				for (int searchEngineIndex = 0; searchEngineIndex < SearchEngines.Count; searchEngineIndex++)
				{
					var searchEngine = SearchEngines[searchEngineIndex];
					if (query != searchEngine)
					{
						int? currentResultWithoutSwitch = lastResults[searchEngineIndex];
						int? currentResultWithSwitch = null;

						for (int searchEngineIndexBeforeSwitch = 0;
							searchEngineIndexBeforeSwitch < SearchEngines.Count;
							searchEngineIndexBeforeSwitch++)
						{
							if ((searchEngineIndexBeforeSwitch == searchEngineIndex) ||
								(lastResults[searchEngineIndexBeforeSwitch] == null))
								continue;

							int candidateResultWithSwitch = lastResults[searchEngineIndexBeforeSwitch].Value + 1;

							if ((currentResultWithSwitch == null) ||
								(currentResultWithSwitch > candidateResultWithSwitch))
								currentResultWithSwitch = candidateResultWithSwitch;
						}

						int currentResult;
						if (currentResultWithoutSwitch == null)
							currentResult = currentResultWithSwitch.Value;
						else if (currentResultWithSwitch == null)
							currentResult = currentResultWithoutSwitch.Value;
						else
							currentResult = Math.Min(currentResultWithSwitch.Value, currentResultWithoutSwitch.Value);

						currentResults[searchEngineIndex] = currentResult;
					}
				}
			}

			return currentResults.Min().Value;
		}

	}


	class Program
	{
		static void Main(string[] args)
		{
			int testCaseCount = int.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);

			for (int testCaseNumber = 1; testCaseNumber <= testCaseCount; testCaseNumber++)
			{
				int searchEngineCount = int.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);
				var searchEngines = new List<string>(searchEngineCount);
				for (int searchEngineIndex = 0; searchEngineIndex < searchEngineCount; searchEngineIndex++)
					searchEngines.Add(Console.ReadLine());
				int queryCount = int.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);
				var queries = new List<string>(queryCount);
				for (int queryIndex = 0; queryIndex < queryCount; queryIndex++)
					queries.Add(Console.ReadLine());

				var problem = new Problem(searchEngines, queries);
				var result = problem.Solve();

				Console.WriteLine(string.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}",
					testCaseNumber, result));
			}
		}
	}
}
