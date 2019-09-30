using System;
using System.Collections.Generic;

namespace ABC092_B_Chocolate
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			string[] input = Console.ReadLine().Split(' ');
			int d = int.Parse(input[0]);
			int x = int.Parse(input[1]);

			List<int> aArr = new List<int>();
			for (int i = 0; i < n; i++) {
				aArr.Add(int.Parse(Console.ReadLine()));
			}
			
			int resultNumberOfChoco = x;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; ; j++) {
					int day = j * aArr[i] + 1;

					if (day > d)
					{
						break;
					}

					resultNumberOfChoco += 1;
				}
			}
			
			Console.WriteLine(resultNumberOfChoco);
		}
	}
}