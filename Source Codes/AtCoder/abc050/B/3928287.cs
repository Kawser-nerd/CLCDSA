using System;
using System.Collections.Generic;

namespace ABC050_B_Contest_with_Drinks_Easy
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			string[] input = Console.ReadLine().Split(' ');
			List<int> tList = new List<int>(n);
			
			for (int i = 0; i < n; i++)
				tList.Add(int.Parse(input[i]));
			
			int m = int.Parse(Console.ReadLine());
			List<int> pList = new List<int>(m);
			List<int> xList = new List<int>(m);
			
			for (int i = 0; i < m; i++)
			{
				input = Console.ReadLine().Split(' ');
				pList.Add(int.Parse(input[0]));
				xList.Add(int.Parse(input[1]));
			}

			for (int i = 0; i < m; i++)
			{
				//???????1??????????-1
				int value = tList[pList[i] - 1];
				tList[pList[i] - 1] = xList[i];

				int sum = 0;
				for (int j = 0; j < n; j++)
					sum += tList[j];
				
				Console.WriteLine(sum);
				tList[pList[i] - 1] = value;
			}
			
		}
	}
}