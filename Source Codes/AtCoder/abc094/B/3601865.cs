using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC094_B_Toll_Gates
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int n = int.Parse(input[0]);
			int m = int.Parse(input[1]);
			int x = int.Parse(input[2]);
			input = Console.ReadLine().Split(' ');
			List<int> aArr = new List<int>();
			
			for (int i = 0; i < m; i++) {
				aArr.Add(int.Parse(input[i]));
			}

			int zeroCost = 0;
			int nCost = 0;

			for (int i = x; i > 0; i--) {
				if (aArr.Any(j => j == i))
				{
					zeroCost++;
					//Console.WriteLine(zeroCost);
				}
			}

			for (int i = x; i < n; i++) {
				if (aArr.Any(j => j == i))
				{
					nCost++;
					//Console.WriteLine(nCost);
				}
			}

			if (zeroCost >= nCost)
			{
				Console.WriteLine(nCost);
			}
			else
			{
				Console.WriteLine(zeroCost);
			}
		}
	}
}