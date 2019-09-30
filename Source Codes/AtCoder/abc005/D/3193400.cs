using System;
using System.Linq;

namespace abc005_4
{
	class Program
	{
		static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			int[,] m = new int[n + 1, n + 1];
			for (int i = 1; i <= n; i++)
			{
				int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
				int sum = 0;
				for (int j = 1; j <= n; j++)
				{
					sum += x[j - 1];
					m[i, j] = m[i - 1, j] + sum;
				}
			}
			int[] max = new int[n * n + 1];
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					for (int k = i + 1; k <= n; k++)
					{
						for (int l = j + 1; l <= n; l++)
						{
							max[(k - i) * (l - j)] = Math.Max(max[(k - i) * (l - j)], m[i, j] - m[i, l] - m[k, j] + m[k, l]);
						}
					}
				}
			}
			int q = int.Parse(Console.ReadLine());
			for (int z = 0; z < q; z++)
			{
				int limit = int.Parse(Console.ReadLine());
				int ret = 0;
				for (int i = limit; i >= 0; i--) ret = Math.Max(ret, max[i]);
				Console.WriteLine(ret);
			}
		}
	}
}