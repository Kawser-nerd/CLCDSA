using System;

namespace D
{
	internal class Program
	{
		private static int n;
		private static int k;
		private static long[] fac;
		private static long[] fInv;
		private static long[] inv;
		private const int Div = 1000000007;

		public static void Main(string[] args)
		{
			n = int.Parse(Console.ReadLine());
			k = int.Parse(Console.ReadLine());

			Init();

			Console.WriteLine(Binomial(n + k - 1, k));
		}

		private static void Init()
		{
			fac = new long[n + k];
			fInv = new long[n + k];
			inv = new long[n + k];

			fac[0] = fac[1] = fInv[0] = fInv[1] = inv[1] = 1;

			for (var i = 2; i < n + k; i++)
			{
				fac[i] = fac[i - 1] * i % Div;
				inv[i] = Div - inv[Div % i] * (Div / i) % Div;
				fInv[i] = fInv[i - 1] * inv[i] % Div;
			}
		}

		private static long Binomial(int N, int K)
		{
			if (N < K) { return 0; }

			if (N < 0 || K < 0) { return 0; }

			return fac[N] * (fInv[K] * fInv[N - K] % Div) % Div;
		}
	}
}