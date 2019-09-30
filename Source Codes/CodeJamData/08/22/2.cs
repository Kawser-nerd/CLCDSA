using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace GCJ1B_2
{

	class Problem
	{
		private const int MaxPrime = 1000001;


		private static int[] _primes;


		static Problem()
		{
			bool[] nonPrimes = new bool[MaxPrime + 1];
			List<int> primes = new List<int>();

			for (int prime = 2; prime <= MaxPrime; prime++)
			{
				if (!nonPrimes[prime])
				{
					primes.Add(prime);

					int index = prime + prime;
					while (index <= MaxPrime)
					{
						nonPrimes[index] = true;
						index += prime;
					}
				}
			}

			_primes = primes.ToArray();
		}


		public Problem()
		{
		}


		public long MinNumber { get; set; }

		public long MaxNumber { get; set; }

		public long MinPrime { get; set; }


		private int NumberCount
		{
			get { return checked((int)(MaxNumber - MinNumber + 1)); }
		}


		public int Solve()
		{
			long[] groupIds = new long[NumberCount];

			int groupCount = 0;

			foreach (var prime in _primes)
			{
				if (prime >= MinPrime)
				{
					var minNumberMod = MinNumber % prime;
					var firstNumber = minNumberMod == 0 ? MinNumber : MinNumber + prime - minNumberMod;
					if (firstNumber <= MaxNumber)
					{
						var groupId = groupIds[GetNumberIndex(firstNumber)];

						long currentNumber = firstNumber + prime;
						while (currentNumber <= MaxNumber)
						{
							if (groupId == 0)
								groupId = groupIds[GetNumberIndex(currentNumber)];
							else if (groupIds[GetNumberIndex(currentNumber)] != 0)
								groupId = Math.Min(groupIds[GetNumberIndex(currentNumber)], groupId);
							currentNumber += prime;
						}

						if (groupId == 0)
							groupId = ++groupCount;

						currentNumber = firstNumber;
						while (currentNumber <= MaxNumber)
						{
							groupIds[GetNumberIndex(currentNumber)] = groupId;
							currentNumber += prime;
						}
					}
				}
			}

			int result = 0;
			for (long number = MinNumber; number <= MaxNumber; number++)
				if (groupIds[GetNumberIndex(number)] == 0)
					result++;

			return result + groupCount;
		}


		private int GetNumberIndex(long number)
		{
			return checked((int)(number - MinNumber));
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
			var parameters = ReadInt32List();

			var problem = new Problem();
			problem.MinNumber = parameters[0];
			problem.MaxNumber = parameters[1];
			problem.MinPrime = parameters[2];
			var result = problem.Solve();

			return result.ToString(CultureInfo.InvariantCulture);
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
