using System;
using System.Collections.Generic;

namespace ABC064_B_Traveling_AtCoDeer_Problem
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			string[] input = Console.ReadLine().Split(' ');
			List<int> aList = new List<int>(n);
			for (int i = 0; i < n; i++)
				aList.Add(int.Parse(input[i]));
			
			aList.Sort();
			int length = 0;
			for (int i = 0; i < n - 1; i++)
				length += aList[i + 1] - aList[i];
			
			Console.Write(length);
		}
	}
}