using System;

namespace ABC091_A_Two_Coins
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int a = int.Parse(input[0]);
			int b = int.Parse(input[1]);
			int c = int.Parse(input[2]);

			if (a + b >= c)
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