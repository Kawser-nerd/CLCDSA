using System;

namespace ABC053_A_ABC_ARC
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int x = int.Parse(Console.ReadLine());

			if (x < 1200) Console.WriteLine("ABC");
			else Console.WriteLine("ARC");
		}
	}
}