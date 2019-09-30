using System;

namespace ABC090_A_Diagonal_String
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string input1 = Console.ReadLine();
			string input2 = Console.ReadLine();
			string input3 = Console.ReadLine();
			
			Console.WriteLine(input1.Substring(0, 1) + input2.Substring(1, 1) + input3.Substring(2, 1));
		}
	}
}