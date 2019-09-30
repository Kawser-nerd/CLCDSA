using System;

namespace ABC056_B_NarrowRectanglesEasy
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int w = int.Parse(input[0]);
			int a = int.Parse(input[1]);
			int b = int.Parse(input[2]);

			if (a + w < b)
				Console.WriteLine(b - a - w);
			else if (b + w < a)
				Console.WriteLine(a - b - w);
			else
				Console.WriteLine(0);
		}
	}
}