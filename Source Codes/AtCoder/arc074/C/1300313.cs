#pragma warning disable
using System.Linq;
using System;
using static System.Math;
using static System.Console;

class E { static void Main() => new J(); }
class J
{
	const int Mod = 1000000007;
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	public J()
	{
		WriteLine(Calc());
	}
	long Calc()
	{
		var I = G();
		int N = I[0], M = I[1];
		var qs = new int[N, 4];
		for (var i = 0; i < N; i++)
		{
			qs[i, 0] = N + 10;
			qs[i, 1] = -10;
			qs[i, 2] = N + 10;
			qs[i, 3] = -10;
		}
		for (var i = 0; i < M; i++)
		{
			I = G();
			if (I[0] != I[1])
			{
				int l = I[0] - 1, r = I[1] - 1;
				switch (I[2])
				{
					case 1: qs[r, 0] = Min(qs[r, 0], l); break;
					case 2: qs[r, 1] = Max(qs[r, 1], l); qs[r, 2] = Min(qs[r, 2], l); break;
					case 3: qs[r, 3] = Max(qs[r, 3], l); break;
					default: break;
				}
			}
			else if (I[2] != 1) return 0;
		}
		//for (var i = 0; i < N; i++) for (var j = 0; j < 4; j += 2) if (qs[i, j] == N + 1) qs[i, j] = -1;
		var dp = new long[N, N];
		dp[N - 1, N - 1] = 3;
		if (qs[0, 1] >= 0 || qs[0, 2] <= N || qs[0, 3] >= 0) return 0;
		for (var n = 0; n < N - 1; n++)
		{
			var next = new long[N, N];
			for (var x = 0; x < n; x++)
				for (var y = 0; y < x; y++)
				{
					next[x, y] = (next[x, y] + dp[x, y]) % Mod;
					next[n, y] = (next[n, y] + dp[x, y]) % Mod;
					next[n, x] = (next[n, x] + dp[x, y]) % Mod;
				}
			next[N - 1, N - 1] = (next[N - 1, N - 1] + dp[N - 1, N - 1]) % Mod;
			next[n, N - 1] = (next[n, N - 1] + 2 * dp[N - 1, N - 1]) % Mod;
			for (var x = 0; x < n; x++)
			{
				next[x, N - 1] = (next[x, N - 1] + dp[x, N - 1]) % Mod;
				next[n, N - 1] = (next[n, N - 1] + dp[x, N - 1]) % Mod;
				next[n, x] = (next[n, x] + dp[x, N - 1]) % Mod;
			}
			for (var x = 0; x <= n; x++) for (var y = 0; y < x; y++)
					if (qs[n + 1, 0] <= x || x < qs[n + 1, 1] || qs[n + 1, 2] <= y || y < qs[n + 1, 3]) next[x, y] = 0;
			for (var x = 0; x <= n; x++) if (qs[n + 1, 0] <= x || x < qs[n + 1, 1] || qs[n + 1, 2] <= -1 || -1 < qs[n + 1, 3]) next[x, N - 1] = 0;
			if (qs[n + 1, 0] <= -1 || -1 < qs[n + 1, 1] || qs[n + 1, 2] <= -2 || -2 < qs[n + 1, 3]) next[N - 1, N - 1] = 0;
			dp = next;
		}
		var ans = 0L;
		for (var x = 0; x < N; x++) for (var y = 0; y < N; y++) ans = (ans + dp[x, y]) % Mod;
		return ans;
	}
}