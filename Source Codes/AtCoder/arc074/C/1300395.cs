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
	long[,] next;
	void Add(int x, int y, long z) { next[x, y] = (next[x, y] + z) % Mod; }
	void Add(ref long x, long z) { x = (x + z) % Mod; }
	bool IsOK(int[] q, int x, int y) => q[0] > x && x >= q[1] && q[2] > y && y >= q[3];
	long Calc()
	{
		var I = G();
		int N = I[0], M = I[1];
		var qs = new int[N][];
		for (var i = 0; i < N; i++) qs[i] = new int[] { N + 10, -10, N + 10, -10 };
		for (var i = 0; i < M; i++)
		{
			I = G();
			if (I[0] != I[1])
			{
				int l = I[0] - 1, r = I[1] - 1;
				switch (I[2])
				{
					case 1: qs[r][0] = Min(qs[r][0], l); break;
					case 2: qs[r][1] = Max(qs[r][1], l); qs[r][2] = Min(qs[r][2], l); break;
					case 3: qs[r][3] = Max(qs[r][3], l); break;
					default: break;
				}
			}
			else if (I[2] != 1) return 0;
		}
		var dp = new long[N, N];
		dp[N - 1, N - 1] = 3;
		if (qs[0][1] >= 0 || qs[0][2] <= N || qs[0][3] >= 0) return 0;
		for (var n = 0; n < N - 1; n++)
		{
			next = new long[N, N];
			for (var x = 0; x < n; x++)
				for (var y = 0; y < x; y++)
				{
					Add(x, y, dp[x, y]);
					Add(n, y, dp[x, y]);
					Add(n, x, dp[x, y]);
				}
			Add(N - 1, N - 1, dp[N - 1, N - 1]);
			Add(n, N - 1, 2 * dp[N - 1, N - 1]);
			for (var x = 0; x < n; x++)
			{
				Add(x, N - 1, dp[x, N - 1]);
				Add(n, N - 1, dp[x, N - 1]);
				Add(n, x, dp[x, N - 1]);
			}
			for (var x = 0; x <= n; x++) for (var y = 0; y < x; y++) if (!IsOK(qs[n + 1], x, y)) next[x, y] = 0;
			for (var x = 0; x <= n; x++) if (!IsOK(qs[n + 1], x, -1)) next[x, N - 1] = 0;
			if (!IsOK(qs[n + 1], -1, -2)) next[N - 1, N - 1] = 0;
			dp = next;
		}
		var ans = 0L;
		for (var x = 0; x < N; x++) for (var y = 0; y < N; y++) Add(ref ans, dp[x, y]);
		return ans;
	}
}