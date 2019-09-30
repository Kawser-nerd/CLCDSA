using System;

namespace ABC062_B_Picture_Frame
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int h = int.Parse(input[0]);
			int w = int.Parse(input[1]);
			string[] pixel = new string[h];
			for (int row = 0; row < h; row++)
				pixel[row] = Console.ReadLine();
			
			for (int column = 0; column < w + 2; column++)
				Console.Write("#");
			Console.WriteLine();

			for (int row = 0; row < h; row++)
				Console.WriteLine("#" + pixel[row] + "#");
			
			for (int column = 0; column < w + 2; column++)
				Console.Write("#");
			Console.WriteLine();
		}
	}
}