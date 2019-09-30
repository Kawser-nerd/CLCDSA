using System;

namespace ABC051_A_Haiku
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(',');

			Console.WriteLine(input[0] + " " + input[1] + " " + input[2]);
		}
	}
}