using System;

namespace ABC061_A_Between_Two_Integers
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int a = int.Parse(input[0]);
			int b = int.Parse(input[1]);
			int c = int.Parse(input[2]);
			
			if(a <= c && b >= c) Console.WriteLine("Yes");
			else Console.WriteLine("No");
		}
	}
}