using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
	static void Main()
	{
		var T = int.Parse(Console.ReadLine());
		for (var i = 0; i < T; )
			Console.WriteLine("Case #{0}: {1}", ++i, Case());
	}

	static double Case()
	{
		var data = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
		var C = data[0];
		var D = data[1];

		var chunks = new List<Tuple<double, double, double>>();
		for (var i = 0; i < C; i++)
		{
			data = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
			var P = data[0];
			var V = data[1];

			var move = (D / 2d) * V;
			var cost =  (D / 2d) * (V - 1);
			chunks.Add(new Tuple<double, double, double>(P - move, P + move, cost));

			while (chunks.Count > 1)
			{
				var l1 = chunks[chunks.Count - 2];
				var l2 = chunks[chunks.Count - 1];
				if (l1.Item2 < l2.Item1) break;
				chunks.RemoveRange(chunks.Count - 2, 2);
				move = l1.Item2 - l2.Item1;

				cost = l1.Item3 - l2.Item3;
				if (l1.Item3 > l2.Item3)
				{
					move = Math.Min(move, cost);
					l2 = new Tuple<double, double, double>(
						l2.Item1 + move, l2.Item2 + move, l2.Item3 + move);
				}
				else
				{
					move = Math.Min(move, -cost);
					l1 = new Tuple<double, double, double>(
						l1.Item1 - move, l1.Item2 - move, l1.Item3 + move);
				}

				move = (l1.Item2 - l2.Item1) / 2;
				chunks.Add(new Tuple<double, double, double>(
					l1.Item1 - move, l2.Item2 + move, Math.Max(l1.Item3, l2.Item3) + move));
			}
		}

		var max = 0d;
		foreach (var chunk in chunks)
			max = Math.Max(max, chunk.Item3);
		return max;
	}
}