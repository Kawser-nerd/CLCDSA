using System;
using System.Linq;

namespace abc057_d
{
	class Program
	{
		static long[,] dp = new long[51, 51];
		static long comb(long n, long r)
		{
			if (r == 0) return 1;
			if (n < r) return 0;
			if (dp[n, r] == 0)
			{
				return dp[n, r] = comb(n - 1, r) + comb(n - 1, r - 1);
			}
			return dp[n, r];
		}
		static void Main(string[] args)
		{
			int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();

			Array.Sort(a); Array.Reverse(a);
			long[] front = new long[x[1]];
			Array.Copy(a, front, x[1]);
			Console.WriteLine((double)front.Sum() / x[1]);

			if (front.Min() == front.Max())
			{
				int n = 0;
				foreach (var item in a) if (item == front[x[1] - 1]) n++;
				long ret = 0;
				for (int i = x[1]; i <= x[2]; i++)
				{
					ret += comb(n, i);
				}
				Console.WriteLine(ret);
			}
			else
			{
				int n = 0;
				foreach (var item in a) if (item == front[x[1] - 1]) n++;
				int r = 0;
				foreach (var item in front) if (item == front[x[1] - 1]) r++;
				Console.WriteLine(comb(n, r));
			}
		}
	}
}