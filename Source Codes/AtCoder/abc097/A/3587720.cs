using System;

namespace ABC097_A_Colorful_Transceivers
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

			if (Math.Abs(a - b) <= d && Math.Abs(b - c) <= d)
			{
				Console.WriteLine("Yes");
			}
			else if (Math.Abs(a - c) <= d)
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