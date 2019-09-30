using System;

namespace ABC092_A_Traveling_Budget
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int a = int.Parse(Console.ReadLine());
			int b = int.Parse(Console.ReadLine());
			int c = int.Parse(Console.ReadLine());
			int d = int.Parse(Console.ReadLine());

			int minBus;
			if (a >= b)
			{
				minBus = b;
			}
			else
			{
				minBus = a;
			}

			int minTrain;
			if (c >= d)
			{
				minTrain = d;
			}
			else
			{
				minTrain = c;
			}
			
			Console.WriteLine(minBus + minTrain);
		}
	}
}