using System;
using System.Collections.Generic;
using System.Linq;

namespace D
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
			var n = line[0];
			var h = line[1];
			var an = new List<int>(n);
			var bn = new List<int>(n);
			for (var i = 0; i < n; i++)
			{
				line = Console.ReadLine().Split().Select(int.Parse).ToArray();
				an.Add(line[0]);
				bn.Add(line[1]);
			}

			var aMax = an.Max();
			var idxList = new List<int>(n);
			for (var i = n - 1; i >= 0; i--)
			{
				if (bn[i] <= aMax) { idxList.Add(i); }
			}

			foreach (var idx in idxList)
			{
				an.RemoveAt(idx);
				bn.RemoveAt(idx);
			}

			bn.Sort();
			bn.Reverse();
			var sumOfThrowPower = 0;
			for (var i = 0; i < bn.Count; i++)
			{
				sumOfThrowPower += bn[i];
				if (sumOfThrowPower >= h)
				{
					Console.WriteLine(i + 1);
					return;
				}
			}

			var hp = h - sumOfThrowPower;
			Console.WriteLine(bn.Count + hp / aMax + (hp % aMax == 0 ? 0 : 1));
		}
	}
}