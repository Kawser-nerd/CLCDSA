using System;
using System.Linq;

namespace ABC062_A_Grouping
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int x = int.Parse(input[0]);
			int y = int.Parse(input[1]);
			int[] groupA = {1, 3, 5, 7, 8, 10, 12};
			int[] groupB = {4, 6, 9, 11};

			

			if (x == 2 && y == 2)
			{
				Console.WriteLine("Yes");
				return;
			}else if (groupA.Any(value => x == value))
			{
				if (groupA.Any(value => y == value))
				{
					Console.WriteLine("Yes");
					return;
				}
			}else if (groupB.Any(value => x == value))
			{
				if (groupB.Any(value => y == value))
				{
					Console.WriteLine("Yes");
					return;
				}
			}
			
			Console.WriteLine("No");
		}
	}
}