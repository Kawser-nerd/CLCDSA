using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
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
		var N = F();
		var dp = new long[Max(4, N + 1)];
		dp[0] = dp[1] = dp[2] = 1;
		dp[3] = 2;
		for (var i = 4; i <= N; i++) dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 4]) % MOD;
		var ans = 0L;
		var n = N - 1L;
		for (var i = 1; i < n; i++) ans = (ans + dp[i]) % MOD;
		ans = (ans * N % MOD + dp[n]) * n % MOD;
		WriteLine((ans + N + n * n) % MOD);
	}
}