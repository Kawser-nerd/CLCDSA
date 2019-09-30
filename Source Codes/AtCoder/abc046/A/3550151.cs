using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC046__AtCoDeer_and_Paint_Cans
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');

			List<string> inputnumbers = new List<string>();
			inputnumbers.Add(input[0]);
			inputnumbers.Add(input[1]);
			inputnumbers.Add(input[2]);
			inputnumbers = inputnumbers.Distinct().ToList();

			int result = inputnumbers.Count();
			
			Console.WriteLine(result);
		}
	}
}