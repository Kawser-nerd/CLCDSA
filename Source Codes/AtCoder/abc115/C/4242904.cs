using System;
using System.Collections.Generic;
using System.Linq;

namespace C
{
	class Program
	{
		static void Main(string[] args)
		{
			var line1 = Console.ReadLine();
			var line1Splited = line1.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);
			var N = int.Parse(line1Splited[0]);
			var K = int.Parse(line1Splited[1]);

			var H = new List<long>();
			for (int i = 0; i < N; i++) {
				H.Add(long.Parse(Console.ReadLine()));
			}

			H.Sort();
			H.Reverse();

			long min = long.MaxValue, diff = 0;
			for (int i = 0; i < N - K + 1; i++) {
				diff = H[i] - H[i + K - 1];
				if (min > diff)
					min = diff;
			}

			Console.WriteLine(min);
		}
	}
}