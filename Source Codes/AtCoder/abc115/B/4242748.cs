using System;
using System.Collections.Generic;
using System.Linq;

namespace B
{
	class Program
	{
		static void Main(string[] args)
		{
			var line = Console.ReadLine();
			var N = int.Parse(line);
			var P = new List<int>();
			for (int i = 0; i < N; i++) {
				P.Add(int.Parse(Console.ReadLine()));
			}

			var sum = P.Sum();
			sum -= P.Max() / 2;
			Console.WriteLine(sum);
		}
	}
}