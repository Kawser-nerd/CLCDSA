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
	int M;
	int[] a;
	void Solve()
	{
		a = G();
		int N = a[0], Q = a[2];
		M = a[1];
		a = G();
		var rev = new int[M + 1][];
		for (var i = 0; i <= M; i++)
		{
			rev[i] = new int[M + 1];
			if (i == 0)
			{
				rev[0][0] = 1;
				continue;
			}
			for (var j = 0; j <= M; j += i + 1)
			{
				rev[i][j] = 1;
				if (j + 1 <= M) rev[i][j + 1] = MOD - 1;
			}
		}
		var all = new int[M + 1];
		all[0] = 1;
		foreach (var x in a) all = Sum(all, x);
		var ans = new int[Q];
		var qs = new List<Tuple<int, int>>[N];
		for (var i = 0; i < N; i++) qs[i] = new List<Tuple<int, int>>();
		for (var i = 0; i < Q; i++)
		{
			var b = G();
			qs[b[0] - 1].Add(new Tuple<int, int>(i, b[1]));
		}
		for (var i = 0; i < N; i++) if (qs[i].Count > 0)
			{
				var x = SumReverse(all, a[i]);
				foreach (var q in qs[i]) if (q.Item2 <= M) ans[q.Item1] = P(x[M - q.Item2]);
			}
		foreach (var x in ans) Console.WriteLine(x);
	}
	int[] Sum(int[] p, int n)
	{
		var r = new int[M + 1];
		r[0] = p[0];
		for (var i = 1; i <= n; i++) r[i] = (r[i - 1] + p[i]) % MOD;
		for (var i = n + 1; i <= M; i++) r[i] = (int)((r[i - 1] + (long)p[i] - p[i - n - 1]) % MOD);
		return r;
	}
	int[] SumReverse(int[] p, int n)
	{
		var r = new int[M + 1];
		r[0] = p[0];
		for (var i = 1; i <= n; i++) r[i] = (p[i] - p[i - 1]) % MOD;
		for (var i = n + 1; i <= M; i++) r[i] = (int)(((long)p[i] - p[i - 1] + r[i - n - 1]) % MOD);
		return r;
	}
	int[] Convolution(int[] p, int[] q)
	{
		var r = new int[M + 1];
		for (var i = 0; i <= M; i++)
		{
			var sum = 0L;
			for (var j = 0; j <= i; j++) sum += p[j] * (long)q[i - j] % MOD;
			r[i] = (int)(sum % MOD);
		}
		return r;
	}
	int P(int n) => n >= 0 ? n : n + MOD;
}