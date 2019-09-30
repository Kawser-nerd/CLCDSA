using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC084_B_Postal_Code
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int a = int.Parse(input[0]);
			int b = int.Parse(input[1]);
			string s = Console.ReadLine();
			List<string> sList = new List<string>();

			for (int i = 0; i < s.Length; i++)
				sList.Add(s.Substring(i, 1));
			
			int hihunCount = sList.Count(x => x == "-");
			if (hihunCount != 1 || sList.Count != a + b + 1)
			{
				Console.WriteLine("No");
			}
			else if (sList[a] == "-")
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