using System;
using System.Linq;

namespace abc054_d
{
	class Program
	{
		static void Main(string[] args)
		{
			int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			int[,] dp = new int[500, 500];
			int inf = 100000000;
			for (int i = 0; i < 500; i++)
			{
				for (int j = 0; j < 500; j++) dp[i, j] = inf;
			}
			dp[0, 0] = 0;
			for (int i = 0; i < x[0]; i++)
			{
				int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
				for (int j = 499; j >= a[0]; j--)
				{
					for (int k = 499; k >= a[1]; k--)
					{
						dp[j, k] = Math.Min(dp[j - a[0], k - a[1]] + a[2], dp[j, k]);
					}
				}
			}
			int ret = inf;
			for (int i = 1; i < 500 / Math.Max(x[1], x[2]); i++)
			{
				ret = Math.Min(ret, dp[x[1] * i, x[2] * i]);
			}
			Console.WriteLine(ret != inf ? ret : -1);
		}
	}
}