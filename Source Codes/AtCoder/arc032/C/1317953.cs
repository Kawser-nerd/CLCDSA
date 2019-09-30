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
struct Work
{
	public int From, To, Index;
	public Work(int f, int t, int i)
	{
		From = f;
		To = t;
		Index = i;
	}
}
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
		var N = F();
		var wks = new Work[N];
		int t0 = MOD, t1 = 0;
		for (var i = 0; i < N; i++)
		{
			var I = G();
			wks[i] = new Work(I[0], I[1], i);
			t0 = Min(t0, I[0]);
			t1 = Max(t1, I[1]);
		}
		var x = new List<Work>[t1 - t0 + 1];
		for (var i = 0; i <= t1 - t0; i++) x[i] = new List<Work>();
		foreach (var w in wks) x[w.From - t0].Add(w);
		var dp = new int[t1 - t0 + 2, 2];
		dp[t1 - t0 + 1, 1] = MOD;
		for (var t = t1; t >= t0; t--)
		{
			dp[t - t0, 0] = dp[t + 1 - t0, 0];
			dp[t - t0, 1] = dp[t + 1 - t0, 1];
			foreach (var w in x[t - t0])
			{
				int n = 1 + dp[w.To - t0, 0], k = w.Index;
				if (n > dp[t - t0, 0] || (n == dp[t - t0, 0] && k < dp[t - t0, 1]))
				{
					dp[t - t0, 0] = n;
					dp[t - t0, 1] = k;
				}
			}
		}
		Console.WriteLine(dp[0, 0]);
		var ans = new List<int>();
		var z = dp[0, 1];
		while (z < MOD)
		{
			ans.Add(z + 1);
			z = dp[wks[z].To - t0, 1];
		}
		Console.WriteLine(string.Join(" ", ans));
	}
}