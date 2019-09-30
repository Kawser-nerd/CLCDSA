using System;

namespace ABC055_A_Restaurant
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			int x = 800 * n;
			int y = 200 * (n / 15);
			
			Console.WriteLine(x - y);
		}
	}
}