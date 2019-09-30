using System;
using System.Linq;
class E { static void Main() { new K(); } }
class K
{
	int[] G() { return Console.ReadLine().Split().Select(_ => int.Parse(_)).ToArray(); }
	long Mod = 1000000007;
	public K()
	{
		var I = G();
		N = I[0]; C = I[1];
		A = G();
		B = G();
		memo = new long[N, C + 1];
		used = new bool[N, C + 1];
		pows = new long[401, C + 1];
		for (var x = 0; x <= 400; x++) pows[x, 0] = 1;
		for (var x = 0; x <= 400; x++) for (var c = 1; c <= C; c++) pows[x, c] = (pows[x, c - 1] * x) % Mod;
		powsum = new long[402, C + 1];
		for (var x = 1; x < 402; x++) for (var c = 0; c <= C; c++) powsum[x, c] = (powsum[x - 1, c] + pows[x - 1, c]) % Mod;
		Console.WriteLine(Calc(0, C));
	}
	int N, C;
	int[] A, B;
	long[,] memo, pows, powsum;
	bool[,] used;
	long Calc(int n, int s)
	{
		if (!used[n, s])
		{
			used[n, s] = true;
			var ans = 0L;
			if (n == N - 1) ans = (powsum[B[n] + 1, s] - powsum[A[n], s]) % Mod;
			else for (var t = 0; t <= s; t++) ans = (ans + ((powsum[B[n] + 1, t] - powsum[A[n], t]) % Mod) * Calc(n + 1, s - t) % Mod) % Mod;
			if (ans < 0) ans += Mod;
			memo[n, s] = ans;
		}
		return memo[n, s];
	}
}