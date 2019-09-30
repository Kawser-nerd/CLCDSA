using System;
using System.Collections.Generic;

namespace ABC089_C_March
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			long mCount = 0;
			long aCount = 0;
			long rCount = 0;
			long cCount = 0;
			long hCount = 0;

			int[] P = new[] {0, 0, 0, 0, 0, 0, 1, 1, 1, 2};
			int[] Q = new[] {1, 1, 1, 2, 2, 3, 2, 2, 3, 3};
			int[] R = new[] {2, 3, 4, 3, 4, 4, 3, 4, 4, 4};

			for (int i = 0; i < n; i++)
			{
				string firstName = Console.ReadLine().Substring(0, 1);

				if (firstName == "M") mCount++;
				if (firstName == "A") aCount++;
				if (firstName == "R") rCount++;
				if (firstName == "C") cCount++;
				if (firstName == "H") hCount++;
			}
			
			List<long> numbers = new List<long>();
			numbers.Add(mCount);
			numbers.Add(aCount);
			numbers.Add(rCount);
			numbers.Add(cCount);
			numbers.Add(hCount);
			
			long result = 0;
			
			for (int i = 0; i < 10; i++)
			{
				result += numbers[P[i]] * numbers[Q[i]] * numbers[R[i]];
			}
			
			Console.WriteLine(result);

			/*numbers.Sort();
			for (int i = 0; i < 3; i++)
			{
				long minNumber = numbers[i];
				result += minNumber;
				for (int j = i + 1; j < 5; j++)
				{
					numbers[j] -= minNumber;
				}
			}
			
			Console.WriteLine(result);*/
		}
	}
}