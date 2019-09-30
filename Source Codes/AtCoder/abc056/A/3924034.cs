using System;

namespace ABC056_A_HonestOrDishonest
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			string a = input[0];
			string b = input[1];

			if (a == "H")
			{
				if (b == "H")
				{
					Console.WriteLine("H");
					return;
				}
			}
			else
			{
				if (b == "D")
				{
					Console.WriteLine("H");
					return;
				}
			}
			
			Console.WriteLine("D");
		}
	}
}