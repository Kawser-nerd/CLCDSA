using System;
using System.Collections.Generic;
using System.Linq;

namespace abc110_d
{
	class Program
	{
		const int mod = 1000000007;
		static long Calc_pow(long x, long pow)
		{
			if (pow == 0) return 1;
			long a = Calc_pow(x, pow / 2);
			a = a * a % mod;
			if (pow % 2 == 1) a *= x;
			return a % mod;
		}
		static long[] fact;
		static void Init_fact(int n)
		{
			fact = new long[n]; fact[0] = 1;
			for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i % mod;
		}
		static long Combination(long n, long r)
		{
			return fact[n] * Calc_pow(fact[r] * fact[n - r] % mod, mod - 2) % mod;
		}
		static void Main(string[] args)
		{
			int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			List<int> primes = new List<int>();
			double sq = Math.Sqrt(x[1]);
			for (int i = 2; i < sq + 1; i++)
			{
				int a = 0;
				while (x[1] % i == 0)
				{
					x[1] /= i; a++;
				}
				if (a > 0) primes.Add(a);
			}
			if (x[1] > 1) primes.Add(1);
			long ret = 1;
			Init_fact(1000000);
			foreach (var num in primes)
			{
				ret *= Combination(x[0] + num - 1, num);
				ret %= mod;
			}
			Console.WriteLine(ret);
		}
	}
}