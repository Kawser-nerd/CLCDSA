using System;

namespace ABC099_A_ABD
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());

			if (n <= 999)
			{
				Console.WriteLine("ABC");
			}
			else
			{
				Console.WriteLine("ABD");
			}
		}
	}
}