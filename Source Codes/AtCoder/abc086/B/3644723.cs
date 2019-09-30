using System;

namespace ABC086_B_1_21
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int number = int.Parse(input[0] + input[1]);

			double sqrtNumber = Math.Sqrt(number);

			if (sqrtNumber % 1 == 0)
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