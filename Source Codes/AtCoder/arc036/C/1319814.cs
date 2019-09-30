using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;
using System.Numerics;
using System.Threading.Tasks;
using static System.Math;
using static System.Console;
class E { static void Main() => new K(); }
class K
{
	int F() => int.Parse(ReadLine());
	long FL() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	long[] GL() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
	public const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var I = G();
		int N = I[0], K = I[1];
		var S = Console.ReadLine();
		// dp[i, j, k] = [0, i) ? ?????? (1 - 0) ? max ? j, min ? -k
		var dp = new long[N + 1, K + 1, K + 1];
		dp[0, 0, 0] = 1;
		for (var i = 1; i <= N; i++)
			for (var j = 0; j <= K; j++)
				for (var k = 0; k <= K; k++)
				{
					if (S[i - 1] != '1' && j != K && k != 0)
					{
						if (j == 0) dp[i, j, k] += dp[i - 1, 0, k - 1];
						dp[i, j, k] += dp[i - 1, j + 1, k - 1];
					}
					if (S[i - 1] != '0' && k != K && j != 0)
					{
						if (k == 0) dp[i, j, k] += dp[i - 1, j - 1, 0];
						dp[i, j, k] += dp[i - 1, j - 1, k + 1];
					}
					dp[i, j, k] %= MOD; //Console.WriteLine("dp[{0}, {1}, {2}] = {3}", i, j, k, dp[i, j, k] %= MOD);
				}
		var ans = 0L;
		for (var j = 0; j <= K; j++) for (var k = 0; k <= K; k++) ans += dp[N, j, k];
		Console.WriteLine(ans % MOD);
	}
}