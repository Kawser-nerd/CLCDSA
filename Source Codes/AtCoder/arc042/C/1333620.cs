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
	struct Snack : IComparable<Snack>
	{
		public int w, v;
		public Snack(int[] a) { w = a[0]; v = a[1]; }
		public int CompareTo(Snack x) => x.w.CompareTo(w);
	}
	void Solve()
	{
		var I = G();
		int N = I[0], W = I[1];
		var s = new Snack[N];
		for (var i = 0; i < N; i++) s[i] = new Snack(G());
		Array.Sort(s);
		int M = W + s[0].w, ans = 0;
		var dp = new int[M + 1];
		foreach (var x in s)
		{
			for (var w = M; w >= x.w; w--) dp[w] = Max(dp[w], dp[w - x.w] + x.v);
			ans = Max(ans, dp[W + x.w]);
		}
		WriteLine(ans);
	}
}