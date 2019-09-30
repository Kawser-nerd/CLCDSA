using System;

namespace ABC048_A_AtCoder_Contest
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			string s = input[1];

			Console.WriteLine("A" + s.Substring(0, 1) + "C"); 
		}
	}
}