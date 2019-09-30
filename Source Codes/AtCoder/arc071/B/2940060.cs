using System;
using System.Linq;

namespace arc071_b
{
	class Program
	{
		static void Main(string[] args)
		{
			long mod = (long)Math.Pow(10, 9) + 7;
			int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();
			long asum = 0;
			for (int i = 1; i < x[0]; i++)
			{
				long now = a[i] - a[i - 1];
				now *= i; now %= mod;
				now *= x[0] - i; now %= mod;
				asum += now; asum %= mod;
			}
			long[] b = Console.ReadLine().Split().Select(long.Parse).ToArray();
			long bsum = 0;
			for (int i = 1; i < x[1]; i++)
			{
				long now = b[i] - b[i - 1];
				now *= i; now %= mod;
				now *= x[1] - i; now %= mod;
				bsum += now; bsum %= mod;
			}
			Console.WriteLine(asum * bsum % mod);
		}
	}
}