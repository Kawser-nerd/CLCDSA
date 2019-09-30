using System;
using System.Linq;

namespace C
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var c1n = Console.ReadLine().Split().Select(int.Parse).ToArray();
			var c2n = Console.ReadLine().Split().Select(int.Parse).ToArray();
			var c3n = Console.ReadLine().Split().Select(int.Parse).ToArray();

			Console.WriteLine(check(c1n, c2n) && check(c1n, c3n) ? "Yes" : "No");
		}

		private static bool check(int[] row1, int[] row2)
		{
			return row1[0] - row2[0] == row1[1] - row2[1] && row1[2] - row2[2] == row1[1] - row2[1];
		}
	}
}