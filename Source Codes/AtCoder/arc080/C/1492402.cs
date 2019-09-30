using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
using static System.Console;
class E { static void Main() => new J(); }
class J
{
	public const int Inf = 1073741789;
	int[] G() => ReadLine().Split().Select(int.Parse).ToArray();
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve() => WriteLine(string.Join(" ", Calc()));
	List<int> Calc()
	{
		var N = G()[0];
		var a = G();
		var r = new int[N];
		for (var i = 0; i < N; i++) r[--a[i]] = i;
		var par = new[] { new RMQ(a, 0), new RMQ(a, 1) };
		var q = new PQ();
		var d = new Dictionary<int, P>();
		Action<P> add = p => { if (p.r - p.l > 1) { var z = par[p.l & 1].Min(p); d[z] = p; q.Enqueue(z); } };
		add(new P(0, N));
		var L = new List<int>();
		while (q.N > 0)
		{
			int x = q.Dequeue(), i = r[x];
			var p = d[x];
			int f = p.l & 1, y = par[1 - f].Min(i + 1, p.r), j = r[y];
			L.Add(x + 1);
			L.Add(y + 1);
			add(new P(p.l, i));
			add(new P(i + 1, j));
			add(new P(j + 1, p.r));
		}
		return L;
	}
}
struct P
{
	public readonly int l, r;
	public P(int x, int y) { l = x; r = y; }
}
class RMQ
{
	readonly int M;
	readonly int[] s;
	public RMQ(int[] a, int f)
	{
		var N = a.Length;
		M = 1;
		while (M < N) M <<= 1;
		s = new int[2 * M - 1];
		for (var i = 0; i < 2 * M - 1; i++) s[i] = J.Inf;
		for (var i = f; i < N; i += 2) s[i + M - 1] = a[i];
		for (var i = M - 2; i >= 0; i--) s[i] = Math.Min(s[2 * i + 1], s[2 * i + 2]);
	}
	public int Min(P p) => Min(p.l, p.r);
	public int Min(int f, int t) => Min(f, t, 0, 0, M);
	int Min(int f, int t, int n, int l, int r)
	{
		if (t <= l || r <= f) return J.Inf;
		else if (f <= l && r <= t) return s[n];
		else return Math.Min(Min(f, t, 2 * n + 1, l, (l + r) >> 1), Min(f, t, 2 * n + 2, (l + r) >> 1, r));
	}
}
class PQ
{
	readonly List<int> l = new List<int>();
	public int N { get; private set; } = 0;
	public void Enqueue(int x)
	{
		var i = N++;
		l.Add(x);
		while (i > 0)
		{
			var p = (i - 1) / 2;
			if (l[p] <= x) break;
			l[i] = l[p];
			i = p;
		}
		l[i] = x;
	}
	public int Dequeue()
	{
		var v = l[0];
		var x = l[--N];
		l.RemoveAt(N);
		if (N == 0) return v;
		var i = 0;
		while (i * 2 + 1 < N)
		{
			var a = 2 * i + 1;
			var b = 2 * i + 2;
			if (b < N && l[b] < l[a]) a = b;
			if (l[a] >= x) break;
			l[i] = l[a];
			i = a;
		}
		l[i] = x;
		return v;
	}
}