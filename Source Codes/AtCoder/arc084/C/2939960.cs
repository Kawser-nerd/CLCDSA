using System;
using System.Collections.Generic;
using System.Linq;

namespace arc084_c
{
	class Program
	{
		static List<int> Back(List<int> list, int max, int limitlen)
		{
			if (list.Last() == 1)
			{
				list.RemoveAt(list.Count - 1);
			}
			else
			{
				list[list.Count - 1]--;
				while (list.Count != limitlen) list.Add(max);
			}
			return list;
		}
		static void Main(string[] args)
		{
			int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			if (x[0] % 2 == 0)
			{
				Console.Write(x[0] / 2);
				for (int i = 1; i < x[1]; i++) Console.Write(" " + x[0]);
				Console.WriteLine();
			}
			else
			{
				List<int> list = new List<int>();
				for (int i = 0; i < x[1]; i++) list.Add(x[0] / 2 + 1);
				for (int i = 0; i < x[1] / 2; i++)
				{
					list = Back(list, x[0], x[1]);
				}
				Console.WriteLine(string.Join(" ", list));
			}
		}
	}
}