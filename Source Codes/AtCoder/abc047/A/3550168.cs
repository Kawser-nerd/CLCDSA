using System;
using System.Collections.Generic;

namespace ABC047_A_Fighting_over_Candys
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			List<int> numbers = new List<int>();
			numbers.Add(int.Parse(input[0]));
			numbers.Add(int.Parse(input[1]));
			numbers.Add(int.Parse(input[2]));
			
			numbers.Sort();

			if (numbers[0] + numbers[1] == numbers[2])
			{
				Console.WriteLine("Yes");
			}
			else
			{
				Console.WriteLine("No");
			}
		}
	}
}