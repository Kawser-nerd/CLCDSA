using System;
using System.Collections.Generic;

namespace ABC042_B_Iroha_Loves_Strings
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int n = int.Parse(input[0]);
			int l = int.Parse(input[1]);
			
			List<string> Strs = new List<string>();

			for (int i = 0; i < n; i++) {
				Strs.Add(Console.ReadLine());
			}
			
			Strs.Sort();

			for (int i = 0; i < n; i++) {
				Console.Write(Strs[i]);
			}
		}
	}
}