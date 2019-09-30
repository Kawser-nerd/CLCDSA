using System;

namespace ABC052_B_Increment_Decrement
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int x = 0;
			int n = int.Parse(Console.ReadLine());
			string s = Console.ReadLine();

			int maxValue = x;
			for (int i = 0; i < n; i++)
			{
				if (s.Substring(i, 1) == "I") x++;
				else x--;

				if (maxValue < x) maxValue = x;
			}
			
			Console.WriteLine(maxValue);
		}
	}
}