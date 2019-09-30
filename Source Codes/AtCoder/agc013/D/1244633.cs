using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
using System.Numerics;
using static System.Math;
using static System.Console;

class E { static void Main() => new J(); }
class J
{
	int F() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	int MOD = 1000000007;
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var I = G();
		var N = I[0];
		var M = I[1];
		var dp = new long[M + 1, N + 1, 2];
		dp[0, 0, 0] = 1;
		for (var a = 0; a <= N; a++) dp[0, a, 1] = 1;
		for (var m = 1; m <= M; m++)
		{
			dp[m, 0, 1] = (dp[m - 1, 0, 1] + dp[m - 1, 1, 1]) % MOD;
			for (var a = 1; a < N; a++) dp[m, a, 1] = (dp[m - 1, a - 1, 1] + 2 * dp[m - 1, a, 1] + dp[m - 1, a + 1, 1]) % MOD;
			dp[m, N, 1] = (dp[m - 1, N, 1] + dp[m - 1, N - 1, 1]) % MOD;
			dp[m, 0, 0] = (dp[m - 1, 0, 1] + dp[m - 1, 1, 1]) % MOD;
			if (N == 1) dp[m, N, 0] = (dp[m - 1, 0, 1] + dp[m - 1, 1, 1]) % MOD;
			else
			{
				dp[m, 1, 0] = (dp[m - 1, 0, 1] + dp[m - 1, 1, 1] + dp[m - 1, 1, 0] + dp[m - 1, 2, 0]) % MOD;
				dp[m, N, 0] = (dp[m - 1, N, 0] + dp[m - 1, N - 1, 0]) % MOD;
			}
			for (var a = 2; a < N; a++) dp[m, a, 0] = (dp[m - 1, a - 1, 0] + 2 * dp[m - 1, a, 0] + dp[m - 1, a + 1, 0]) % MOD;
		}
		var ans = 0L;
		for (var a = 0; a <= N; a++) ans += dp[M, a, 0];
		Console.WriteLine(ans % MOD);
	}
}