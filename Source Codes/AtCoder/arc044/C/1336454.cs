using System.Linq;
using System.Collections.Generic;
using static System.Math;
using static System.Console;
class E { static void Main() => new K(); }
class K
{
	int[] G() => ReadLine().Split().Select(int.Parse).ToArray();
	const long INF = 4011686018427387913L;
	public K()
	{
		var I = G();
		int X = I[0], Y = I[1], Q = I[2];
		var xs = new SortedDictionary<int, List<int>>();
		var ys = new SortedDictionary<int, List<int>>();
		for (var i = 0; i < Q; i++)
		{
			I = G();
			var z = I[1] == 0 ? xs : ys;
			int t = I[0], p = I[2] - 1;
			if (!z.ContainsKey(t)) z[t] = new List<int>();
			z[t].Add(p);
		}
		var ans = Calc(X, xs.Values) + Calc(Y, ys.Values);
		WriteLine(ans < INF ? ans : -1);
	}
	long Calc(int n, IEnumerable<List<int>> bs)
	{
		var dp = new long[n];
		foreach (var b in bs)
		{
			if (b.Count == n) return INF;
			b.Sort();
			var i = 0;
			while (i < b.Count)
			{
				var j = i + 1;
				while (j < b.Count && b[j] == b[j - 1] + 1) j++;
				var l = b[i] - 1 >= 0 ? dp[b[i] - 1] - b[i] + 1 : INF;
				var r = b[j - 1] + 1 < n ? dp[b[j - 1] + 1] + b[j - 1] + 1 : INF;
				for (var k = i; k < j; k++) dp[b[k]] = Min(l + b[k], r - b[k]);
				i = j;
			}
		}
		return dp.Min();
	}
}