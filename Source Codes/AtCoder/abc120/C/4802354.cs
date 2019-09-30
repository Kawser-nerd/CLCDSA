using System;
using System.Linq;

namespace C
{
	class Program
	{
		static void Main()
		{
			var S = Console.ReadLine();

			var counts = new int[] {0, 0};

			foreach (var c in S) {
				counts[int.Parse(c.ToString())]++;
			}

			Console.WriteLine(counts.ToList().Min() * 2);
		}
	}
}