using System;

namespace ABC080_A_Parking
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int n = int.Parse(input[0]);
			int a = int.Parse(input[1]);
			int b = int.Parse(input[2]);

			if (a * n > b)
			{
				Console.WriteLine(b);
			}
			else
			{
				Console.WriteLine(a * n);
			}
		}
	}
}