using System;

namespace ABC084_A_New_Year
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int m = int.Parse(Console.ReadLine());

			int time = 24 - m + 24;
			Console.WriteLine(time);
		}
	}
}