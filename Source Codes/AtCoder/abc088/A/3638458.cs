using System;

namespace ABC088_A_Infinite_Coins
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			int a = int.Parse(Console.ReadLine());

			int amari = n % 500;
			if (amari <= a)
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