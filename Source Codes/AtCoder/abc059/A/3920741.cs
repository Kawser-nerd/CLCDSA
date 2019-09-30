using System;

namespace ABC059_A_Three_letter_acronym
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			Console.Write(input[0].Substring(0, 1).ToUpper());
			Console.Write(input[1].Substring(0, 1).ToUpper());
			Console.Write(input[2].Substring(0, 1).ToUpper());
		}
	}
}