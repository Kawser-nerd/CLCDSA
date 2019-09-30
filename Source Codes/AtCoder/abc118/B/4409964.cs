using System;
using System.Linq;

namespace ConsoleApplication1
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
			var n = line[0];
			var m = line[1];

			var counter = new int[m];
			for (var i = 0; i < n; i++)
			{
				line = Console.ReadLine().Split().Select(int.Parse).ToArray();
				var upper = line.Length;
				for (var j = 1; j < upper; j++) { counter[line[j] - 1]++; }
			}

			Console.WriteLine(counter.Count(c => c == n));
		}
	}
}