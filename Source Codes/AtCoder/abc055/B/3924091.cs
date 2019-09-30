using System;

namespace ABC055_B_Training_Camp
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			long power = 1;

			for (int i = 1; i <= n; i++)
				power = (i * power) % ((long)Math.Pow(10, 9) + 7);
			
			Console.WriteLine(power);
		}
	}
}