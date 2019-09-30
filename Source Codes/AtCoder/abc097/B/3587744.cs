using System;

namespace ABC097_B_Exponential
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int x = int.Parse(Console.ReadLine());
			int xUnderPowNumber = (int)Math.Pow(2, 2);

			if (x == 1)
			{
				Console.WriteLine(1);
				return;
			}

			for (int i = 2; i < x; i++)
			{
				for (int j = 2; ; j++)
				{
					int pow = (int)Math.Pow(i, j);
					
					if (pow <= x && pow > xUnderPowNumber)
					{
						xUnderPowNumber = pow;
					}

					if (pow > x)
					{
						break;
					}
				}
			}
			
			Console.WriteLine(xUnderPowNumber);
		}
	}
}