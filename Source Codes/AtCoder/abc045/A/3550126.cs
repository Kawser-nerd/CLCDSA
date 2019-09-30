using System;

namespace ABC045_A_Trapezoids
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int a = int.Parse(Console.ReadLine());
			int b = int.Parse(Console.ReadLine());
			int h = int.Parse(Console.ReadLine());

			int result = 0;

			result = (a + b) * h / 2;
			
			Console.WriteLine(result);
		}
	}
}