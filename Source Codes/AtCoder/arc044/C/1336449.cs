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
	const long InfL = 4011686018427387913L;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var I = G();
		int X = I[0], Y = I[1], Q = I[2];
		var xs = new SortedDictionary<int, List<int>>();
		var ys = new SortedDictionary<int, List<int>>();
		for (var i = 0; i < Q; i++)
		{
			I = G();
			var ws = I[1] == 0 ? xs : ys;
			int t = I[0], p = I[2] - 1;
			if (!ws.ContainsKey(t)) ws[t] = new List<int>();
			ws[t].Add(p);
		}
		var ans = Calc(X, xs.Values) + Calc(Y, ys.Values);
		WriteLine(ans < InfL ? ans : -1);
	}
	long[] dp;
	long Calc(int n, IEnumerable<List<int>> beams)
	{
		dp = new long[n];
		foreach (var beam in beams)
		{
			if (beam.Count == n) return InfL;
			beam.Sort();
			var i = 0;
			while (i < beam.Count)
			{
				var j = i + 1;
				while (j < beam.Count && beam[j] == beam[j - 1] + 1) j++;
				var l = beam[i] - 1 >= 0 ? dp[beam[i] - 1] : InfL;
				var r = beam[j - 1] + 1 < n ? dp[beam[j - 1] + 1] : InfL;
				for (var k = i; k < j; k++) dp[beam[k]] = Min(l + (beam[k] - beam[i] + 1), r + (beam[j - 1] + 1 - beam[k]));
				i = j;
			}
		}
		return dp.Min();
	}
}