using System;

namespace ABC050_A_Addition_and_Subtraction_Easy
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			String[] input = Console.ReadLine().Split(' ');
			int a = int.Parse(input[0]);
			int b = int.Parse(input[2]);

			if (input[1] == "+")
			{
				Console.WriteLine(a + b);
			}
			else
			{
				Console.WriteLine(a - b);
			}
		}
	}
}