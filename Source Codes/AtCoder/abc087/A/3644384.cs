using System;

namespace ABC087_A_Buying_Sweets
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int x = int.Parse(Console.ReadLine());
			int a = int.Parse(Console.ReadLine());
			int b = int.Parse(Console.ReadLine());

			int money = x - a;
			
			Console.WriteLine(money % b);
		}
	}
}