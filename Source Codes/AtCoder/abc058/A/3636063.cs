using System;

namespace A
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var input = Console.ReadLine().Split();
			var heights = new int[3];
			for (var i = 0; i < 3; i++) { heights[i] = int.Parse(input[i]); }

			Console.WriteLine(heights[1] - heights[0] == heights[2] - heights[1] ? "YES" : "NO");
		}
	}
}