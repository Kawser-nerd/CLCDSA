using System;

namespace ABC057_A_Remaining_Time
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int a = int.Parse(input[0]);
			int b = int.Parse(input[1]);

			if (a + b >= 24) Console.WriteLine(a + b - 24);
			else Console.WriteLine(a + b); 
		}
	}
}