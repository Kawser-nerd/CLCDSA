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
	long FL() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	long[] GL() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
	public const int MOD = 1000000007;
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var x = G().ToList();
		int N = x[0], Q = x[1], A = x[2] - 1, B = x[3] - 1;
		x = G().Select(a => a - 1).ToList();
		x.Insert(0, A);
		var l = new SegmentTree(N);
		var r = new SegmentTree(N);
		l[B] = -B;
		r[B] = B;
		for (var i = 1; i <= Q; i++)
		{
			var tmp = Min(l.Min(0, x[i]) + x[i], r.Min(x[i], N) - x[i]);
			var d = Abs(x[i] - x[i - 1]);
			l.Shift(d);
			r.Shift(d);
			l[x[i - 1]] = -x[i - 1] + tmp;
			r[x[i - 1]] = x[i - 1] + tmp;
		}
		var ans = l[0];
		for (var i = 1; i < N; i++) ans = Min(ans, l[i] + i);
		WriteLine(ans);
	}
	long Inverse(long a, long mod)
	{
		if (a < 0) { a %= mod; if (a < 0) a += mod; }
		var t = SolveLinear(a, mod);
		return t.Item1 > 0 ? t.Item1 : t.Item1 + mod;
	}
	Tuple<long, long> SolveLinear(long n, long m)
	{
		if (n < 0) { var p = SolveLinear(-n, m); return p == null ? p : new Tuple<long, long>(-p.Item1, p.Item2); }
		if (m < 0) { var p = SolveLinear(n, -m); return p == null ? p : new Tuple<long, long>(p.Item1, -p.Item2); }
		if (n < m) { var p = SolveLinear(m, n); return p == null ? p : new Tuple<long, long>(p.Item2, p.Item1); }
		long a = 1, b = 0, c = 0, d = 1;
		while (m > 0)
		{
			var r = n % m;
			var q = n / m;
			n = m;
			m = r;
			var tmp = a;
			a = -a * q + b;
			b = tmp;
			tmp = c;
			c = -c * q + d;
			d = tmp;
		}
		return n != 1 ? null : new Tuple<long, long>(d, b);
	}
	long GCD(long a, long b)
	{
		var n = (ulong)Math.Abs(a); var m = (ulong)Math.Abs(b);
		if (n == 0) return (long)m; if (m == 0) return (long)n;
		int zm = 0, zn = 0;
		while ((n & 1) == 0) { n >>= 1; zn++; }
		while ((m & 1) == 0) { m >>= 1; zm++; }
		while (m != n)
		{
			if (m > n) { m -= n; while ((m & 1) == 0) m >>= 1; }
			else { n -= m; while ((n & 1) == 0) n >>= 1; }
		}
		return (long)n << Math.Min(zm, zn);
	}
}
class SegmentTree
{
	const long Inf = 2000686018427387989L;
	int N;
	long unif;
	long[] seg;
	public SegmentTree(int n)
	{
		N = 1;
		while (N < n) N <<= 1;
		seg = new long[2 * N - 1];
		for (var i = 0; i < 2 * N - 1; i++) seg[i] = Inf;
		for (var i = N - 2; i >= 0; i--) seg[i] = Math.Min(seg[2 * i + 1], seg[2 * i + 2]);
	}
	public void Shift(long v)
	{
		unif += v;
	}
	public void Update(int i, long v)
	{
		i += N - 1;
		seg[i] = v - unif;
		while (i > 0)
		{
			i = (i - 1) / 2;
			seg[i] = Math.Min(seg[i * 2 + 1], seg[i * 2 + 2]);
		}
	}
	public long this[int n] { get { return Min(n, n + 1); } set { Update(n, value); } }
	public long Min(int from, int to) => Min(from, to, 0, 0, N);
	long Min(int from, int to, int node, int l, int r)
	{
		if (to <= l || r <= from) return Inf;
		if (from <= l && r <= to) return seg[node] + unif;
		return Math.Min(Min(from, to, 2 * node + 1, l, (l + r) >> 1), Min(from, to, 2 * node + 2, (l + r) >> 1, r));
	}
}