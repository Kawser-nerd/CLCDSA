using System;

namespace ABC082_A_Round_Up_the_Mean
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int a = int.Parse(input[0]);
			int b = int.Parse(input[1]);

			if ((a + b) % 2 == 0)
			{
				Console.WriteLine((a + b) / 2);
			}
			else
			{
				Console.WriteLine((a + b) / 2 + 1);
			}
		}
	}
}