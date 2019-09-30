using System;
using System.IO;
using System.Linq;
class E { static void Main() => new _K(); }
class _K
{
	int[] G => Console.ReadLine().Split().Select(_ => int.Parse(_)).ToArray();
	public const long Mod = 924844033;
	int N, K;
	long ans, s = 1;
	long[,] comb;
	public _K()
	{
		var I = G;
		N = I[0]; K = I[1];
		var M = N / K + 10;
		comb = new long[M, M];
		for (var i = 0; i < M; i++) comb[i, 0] = 1;
		for (var i = 1; i < M; i++) for (var j = 1; j <= i; j++) comb[i, j] = (comb[i - 1, j] + comb[i - 1, j - 1]) % Mod;
		var p = Convolution(Pow(Chain(N / K), 2 * (K - N % K)), Pow(Chain(N / K + 1), 2 * (N % K)));
		var fact = new long[N + 1];
		fact[0] = 1;
		for (var i = 1; i <= N; i++) fact[i] = (i * fact[i - 1]) % Mod;
		for (var i = 0; i <= N; i++)
		{
			ans = (ans + s * fact[N - i] * p[i] % Mod) % Mod;
			s *= -1;
		}
		if (ans < 0) ans += Mod;
		Console.WriteLine(ans);
	}
	long[] Chain(int n)
	{
		var p = new long[n / 2 + 1];
		for (var k = 0; k <= n / 2; k++) p[k] = comb[n - k, k];
		return p;
	}
	long[] Pow(long[] a, int n)
	{
		var p = new long[] { 1 };
		var x = a;
		while (n > 0)
		{
			if ((n & 1) == 1) p = Convolution(p, x);
			n >>= 1;
			x = Convolution(x, x);
		}
		return p;
	}
	long[] Convolution(long[] a, long[] b)
	{
		var c = new long[a.Length + b.Length];
		for (var i = 0; i < a.Length; i++)
			for (var j = 0; j < b.Length; j++)
				c[i + j] = (c[i + j] + a[i] * b[j] % Mod) % Mod;
		return c;
	}
}