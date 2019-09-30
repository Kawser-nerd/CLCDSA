using System;

namespace ABC054_A_One_Card_Poker
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int a = int.Parse(input[0]);
			int b = int.Parse(input[1]);

			if (a == 1)
			{
				if(b == 1) Console.WriteLine("Draw");
				else Console.WriteLine("Alice");
			}else if (b == 1)
			{
				if(a == 1) Console.WriteLine("Draw");
				else Console.WriteLine("Bob");
			}
			else
			{
				if(a == b) Console.WriteLine("Draw");
				else if(a > b) Console.WriteLine("Alice");
				else Console.WriteLine("Bob");
			}

		}
	}
}