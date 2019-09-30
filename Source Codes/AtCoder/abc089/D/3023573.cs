using System;
using System.Linq;

namespace abc089_d
{
	class Program
	{
		static void Main(string[] args)
		{
			int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			Tuple<int, int>[] where = new Tuple<int, int>[x[0] * x[1] + 1];
			for (int i = 0; i < x[0]; i++)
			{
				int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
				for (int j = 0; j < x[1]; j++)
				{
					where[a[j]] = new Tuple<int, int>(i, j);
				}
			}
			int[] sum = new int[x[0] * x[1] + 1];
			for (int i = x[2] + 1; i <= x[0] * x[1]; i++)//search num
			{
				sum[i] = sum[i - x[2]] +
					Math.Abs(where[i].Item1 - where[i - x[2]].Item1) +
					Math.Abs(where[i].Item2 - where[i - x[2]].Item2);
			}
			int n = int.Parse(Console.ReadLine());
			for (int i = 0; i < n; i++)
			{
				int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
				Console.WriteLine(sum[a[1]] - sum[a[0]]);
			}
		}
	}
}