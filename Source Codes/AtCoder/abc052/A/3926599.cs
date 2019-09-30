using System;

namespace ABC052_A_Two_Rectangles
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int a = int.Parse(input[0]);
			int b = int.Parse(input[1]);
			int c = int.Parse(input[2]);
			int d = int.Parse(input[3]);
			
			if(a * b > c * d) Console.WriteLine(a * b);
			else if(a * b < c * d) Console.WriteLine(c * d);
			else Console.WriteLine(a * b);
		}
	}
}