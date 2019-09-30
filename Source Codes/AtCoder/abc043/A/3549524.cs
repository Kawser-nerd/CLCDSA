using System;
using System.ComponentModel;

namespace ABC043_A_Children_and_Candies
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());

			int candyCount = 0;

			for (int i = 0; i < n; i++)
			{
				candyCount += i + 1;
			}
			
			Console.WriteLine(candyCount);
		}
	}
}