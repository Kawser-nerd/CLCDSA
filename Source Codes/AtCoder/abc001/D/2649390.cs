using System;
using System.Collections.Generic;

namespace D001
{
	internal static class Program
	{
		public static void Main(string[] args)
		{
			// input N
			var n = int.Parse(Console.ReadLine());
			var list = new List<List<int>>(2 * n);

			// input time
			for (var i = 0; i < n; i++)
			{
				var line = Console.ReadLine().Split('-');
				list.Add(new List<int> {int.Parse(line[0]), int.Parse(line[1])});

				var r = list[i][0] % 5;
				list[i][0] -= r;
				r = list[i][1] % 5;
				list[i][1] += (10 - r) % 5;
				if (list[i][1] % 100 == 60)
				{
					list[i][1] += 40;
				}
			}

			list.Sort((l1, l2) => l1[0] - l2[0]);

			for (var i = 0; i < list.Count - 1; i++)
			{
				if (list[i][1] >= list[i + 1][0])
				{
					if (list[i][1] >= list[i + 1][1])
					{
						list.RemoveAt(i + 1);
					}
					else
					{
						list[i][1] = list[i + 1][1];
						list.RemoveAt(i + 1);
					}

					i--;
				}
			}

			foreach (var l in list)
			{
				Console.WriteLine($"{l[0]:d4}-{l[1]:d4}");
			}
		}
	}
}