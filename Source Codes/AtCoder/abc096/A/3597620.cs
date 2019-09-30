using System;

namespace ABC096_A_Day_of_Takahashi
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int a = int.Parse(input[0]);
			int b = int.Parse(input[1]);

			if (a <= b)
			{
				Console.WriteLine(a);
			}
			else
			{
				Console.WriteLine(a - 1);
			}
		}
	}
}