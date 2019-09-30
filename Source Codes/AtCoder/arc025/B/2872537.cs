using System;
using System.Linq;

namespace arc025_2
{
	class Program
	{
		static void Main(string[] args)
		{
			int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			int[,] sumsum = new int[x[0] + 1, x[1] + 1];
			for (int i = 0; i < x[0]; i++)
			{
				int sum = 0;
				int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
				for (int j = 0; j < x[1]; j++)
				{
					sum += (i + j) % 2 == 0 ? a[j] : -a[j];
					sumsum[i + 1, j + 1] = sumsum[i, j + 1] + sum;
				}
			}
			int ret = 0;
			for (int i = 0; i <= x[0]; i++)
			{
				for (int j = i + 1; j <= x[0]; j++)
				{
					for (int k = 0; k <= x[1]; k++)
					{
						for (int l = k + 1; l <= x[1]; l++)
						{
							if (sumsum[i, k] + sumsum[j, l]
								- sumsum[i, l] - sumsum[j, k] == 0)
								ret = Math.Max(ret, (j - i) * (l - k));
						}
					}
				}
			}
			Console.WriteLine(ret);
		}
	}
}