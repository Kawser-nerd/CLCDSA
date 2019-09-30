using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using static System.Math;
using static Func;
class E { static void Main() => new J(); }
class J
{
	int F => int.Parse(Console.ReadLine());
	int[] G => Console.ReadLine().Split().Select(_ => int.Parse(_)).ToArray();
	HashSet<int>[] es;
	Range[] r;
	int[] z;
	public J()
	{
		Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
		var N = F;
		z = new int[N];
		for (var i = 0; i < N; i++) z[i] = -1;
		r = new Range[N];
		for (var i = 0; i < N; i++) r[i] = new Range();
		es = new HashSet<int>[N];
		for (var i = 0; i < N; i++) es[i] = new HashSet<int>();
		for (var i = 0; i < N - 1; i++)
		{
			var e = G;
			int a = e[0] - 1, b = e[1] - 1;
			es[a].Add(b); es[b].Add(a);
		}
		var K = F;
		var root = -1;
		for (var i = 0; i < K; i++)
		{
			var q = G;
			z[root = --q[0]] = q[1];
		}
		if (DFS(root, -1, z[root] % 2) == null) Console.WriteLine("No");
		else
		{
			Console.WriteLine("Yes");
			DFS2(root, z[root]);
			for (var i = 0; i < N; i++) Console.WriteLine(z[i]);
		}
		Console.Out.Flush();
	}
	void DFS2(int u, int p)
	{
		z[u] = p;
		foreach (var v in es[u])
		{
			if (z[v] >= 0) DFS2(v, z[v]);
			else if (r[v].Contains(p + 1)) DFS2(v, p + 1);
			else DFS2(v, p - 1);
		}
	}
	Range DFS(int u, int p, int e)
	{
		es[u].Remove(p);
		foreach (var v in es[u])
		{
			var b = DFS(v, u, 1 - e);
			if (b == null) return null;
			r[u].AndWith(b);
		}
		if (!r[u].OK) return null;
		if (z[u] >= 0)
		{
			if (!r[u].Contains(z[u]) || z[u] % 2 != e) return null;
			return new Range(z[u]);
		}
		return r[u];
	}
}
class Range
{
	int l, r;
	public Range() : this(-Inf, Inf) { }
	public Range(int a) : this(a, a) { }
	public Range(int a, int b) { l = a; r = b; }
	public bool OK => l <= r;
	public bool Contains(int x) => l <= x && x <= r;
	public void AndWith(Range x) { l = Max(l, x.l - 1); r = Min(r, x.r + 1); }
}
static class Func
{
	public const int Inf = 1073741789;  // 2 * Inf < int.MaxValue, and Inf is a prime number
}