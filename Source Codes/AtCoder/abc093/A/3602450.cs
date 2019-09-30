using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC093_A_abc_of_ABC
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string s = Console.ReadLine();
			List<string> sArr = new List<string>();
			for (int i = 0; i < 3; i++)
			{
				sArr.Add(s.Substring(i, 1));
			}

			if (sArr.Any(x => x == "a") && sArr.Any(x => x == "b") && sArr.Any(x => x == "c"))
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