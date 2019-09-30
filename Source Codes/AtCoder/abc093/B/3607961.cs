using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC093_B_Small_and_Large_Integers
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int a = int.Parse(input[0]);
			int b = int.Parse(input[1]);
			int k = int.Parse(input[2]);
			
			List<int> numbers = new List<int>();

			for (int i = a; i < a + k; i++) {
				numbers.Add(i);
				if (i <= b)
				{
					Console.WriteLine(i);
				}
			}
			
			for (int i = b - k + 1; i <= b; i++) {
				if (i >= a && !numbers.Any(x => x == i))
				{
					Console.WriteLine(i);
				}
			}
		}
	}
}