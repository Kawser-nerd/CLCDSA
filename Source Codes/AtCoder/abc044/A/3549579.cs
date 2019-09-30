using System;

namespace ABC044_A_Tak_and_Hotels
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			int k = int.Parse(Console.ReadLine());
			int x = int.Parse(Console.ReadLine());
			int y = int.Parse(Console.ReadLine());

			int result = 0;
			
			if (n <= k)
			{
				result = x * n;
			}
			else
			{
				result = x * k;
				result += y * (n - k);
			}
			
			Console.WriteLine(result);
		}
	}
}