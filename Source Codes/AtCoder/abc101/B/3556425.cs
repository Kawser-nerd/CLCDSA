using System;
using System.Collections.Generic;

namespace ABC101_B_Digit_Sums
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string n = Console.ReadLine();
			int npuls = 0;

			for (int i = 0; i < n.Length; i++)
			{
				npuls += int.Parse(n.Substring(i, 1));
			}
			//Console.WriteLine(npuls);

			if (int.Parse(n) % npuls == 0)
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