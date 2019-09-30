using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC095_B_Bitter_Alchemy
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int n = int.Parse(input[0]);
			int x = int.Parse(input[1]);
			
			List<int> mArrs = new List<int>();
			
			for (int i = 0; i < n; i++) {
				mArrs.Add(int.Parse(Console.ReadLine()));
				x -= mArrs[i];
			}

			int count = n;

			while (x >= mArrs.Min())
			{
				x -= mArrs.Min();
				count++;
			}
			
			Console.WriteLine(count);
		}
	}
}