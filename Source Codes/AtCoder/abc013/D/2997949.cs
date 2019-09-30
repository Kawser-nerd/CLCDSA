using System;
using System.Linq;

namespace abc013_4
{
	class Program
	{
		static void Main(string[] args)
		{
			int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			int[] a = new int[x[1]];
			if (x[1] > 0) a = Console.ReadLine().Split().Select(int.Parse).ToArray();
			int[,] memo = new int[30, x[0]];
			for (int i = 0; i < x[0]; i++) memo[0, i] = i;
			for (int i = x[1] - 1; i >= 0; i--)
			{
				memo[0, a[i]] ^= memo[0, a[i] - 1]; memo[0, a[i] - 1] ^= memo[0, a[i]]; memo[0, a[i]] ^= memo[0, a[i] - 1];
			}
			for (int i = 1; i < 30; i++)
			{
				for (int j = 0; j < x[0]; j++)
				{
					memo[i, j] = memo[i - 1, memo[i - 1, j]];
				}
			}
			for (int i = 0; i < x[0]; i++)
			{
				int ret = i;
				for (int j = 0; j < 30; j++)
				{
					if ((x[2] & (1 << j)) > 0) ret = memo[j, ret];
				}
				Console.WriteLine(ret + 1);
			}
		}
	}
}