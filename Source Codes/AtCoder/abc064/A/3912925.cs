using System;

namespace ABC064_A_RGB_Cards
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			string numberStr = input[0] + input[1] + input[2];
			int number = int.Parse(numberStr);
			
			if(number % 4 == 0) Console.WriteLine("YES");
			else Console.WriteLine("NO");
		}
	}
}