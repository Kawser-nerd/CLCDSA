using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC096_B_Maximum_Sum
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			/*int a = int.Parse(input[0]);
			int b = int.Parse(input[1]);
			int c = int.Parse(input[2]);*/
			
			List<int> numbers = new List<int>();

			for (int i = 0; i < 3; i++) {
				numbers.Add(int.Parse(input[i]));
			}
			int k = int.Parse(Console.ReadLine());

			int maxNumberIndex = numbers.IndexOf(numbers.Max());
			for (int i = 0; i < k; i++)
			{
				numbers[maxNumberIndex] *= 2;
			}
			
			Console.WriteLine(numbers[0] + numbers[1] + numbers[2]);
		}
	}
}