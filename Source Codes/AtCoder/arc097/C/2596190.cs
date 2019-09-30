using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Math;
class Z { static void Main() => new K(); }
class K
{
	int F => int.Parse(Str);
	long FL => long.Parse(Str);
	int[] G => Strs.Select(int.Parse).ToArray();
	long[] GL => Strs.Select(long.Parse).ToArray();
	string Str => ReadLine();
	string[] Strs => Str.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
	const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var N = F;
		var x = new int[2 * N];
		var c = new int[2 * N];
		var rev = new int[2, N];
		for (var i = 0; i < 2 * N; i++)
		{
			var s = Strs;
			c[i] = s[0] == "W" ? 0 : 1;
			x[i] = int.Parse(s[1]) - 1;
			rev[c[i], x[i]] = i;
		}
		var cost = new int[2, 2 * N, N + 1];
		for (var i = 0; i < 2; i++)
			for (var v = 0; v <= N; v++)
			{
				for (var k = 0; k < 2 * N; k++) if (c[k] == i && x[k] < v) cost[i, k, v] = 1;
				for (var k = 2 * N - 2; k >= 0; k--) cost[i, k, v] += cost[i, k + 1, v];
			}
		var dp = new int[N + 1, N + 1];
		for (var i = 0; i < N; i++) dp[i + 1, 0] = dp[i, 0] + cost[0, rev[0, i], i];
		for (var j = 0; j < N; j++) dp[0, j + 1] = dp[0, j] + cost[1, rev[1, j], j];
		for (var i = 0; i < N; i++)
			for (var j = 0; j < N; j++)
			{
				dp[i + 1, j + 1] = Min(dp[i + 1, j] + cost[1, rev[1, j], j] + cost[0, rev[1, j], i + 1],
				dp[i, j + 1] + cost[0, rev[0, i], i] + cost[1, rev[0, i], j + 1]);
			}
		WriteLine(dp[N, N]);
	}
}