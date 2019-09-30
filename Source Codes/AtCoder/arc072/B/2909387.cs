using System;
using System.Linq;

namespace arc072_b
{
	class Program
	{
		static void Main(string[] args)
		{
			long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
			Console.WriteLine(Math.Abs(x[0] - x[1]) <= 1 ? "Brown" : "Alice");
		}
	}
}