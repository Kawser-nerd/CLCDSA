#pragma warning disable
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
using System.Collections;
using static System.Math;
using static System.Console;
class E { static void Main() => new J(); }
class J
{
	const int Mod = 1000000007;
	int F() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	HashSet<int>[] es;
	void Solve()
	{
		var N = F();
		es = new HashSet<int>[N];
		for (var i = 0; i < N; i++)  es[i] = new HashSet<int>();
		for (var i = 0; i < N - 1; i++) Add(G());
		par = new int[N];
		size = new int[N];
		dep = new int[N];
		DFS(0, -1, 0);
		var w = N - 1;
		var d = dep[w] / 2 + 1;
		while (dep[w] != d) w = par[w];
		WriteLine(N - size[w] > size[w] ? "Fennec" : "Snuke");
	}
	int[] par, size, dep;
	int DFS(int u, int p, int d)
	{
		par[u] = p;
		dep[u] = d;
		es[u].Remove(p);
		foreach (var v in es[u]) size[u] += DFS(v, u, d + 1);
		return ++size[u];
	}
	void Add(int[] a) => Add(a[0] - 1, a[1] - 1);
	void Add(int a, int b)
	{
		es[a].Add(b);
		es[b].Add(a);
	}
	long GCD(long a, long b)
	{
		var n = (ulong)Abs(a); var m = (ulong)Abs(b);
		if (n == 0) return (long)m; if (m == 0) return (long)n;
		int zm = 0, zn = 0;
		while ((n & 1) == 0) { n >>= 1; zn++; }
		while ((m & 1) == 0) { m >>= 1; zm++; }
		while (m != n)
		{
			if (m > n) { m -= n; while ((m & 1) == 0) m >>= 1; }
			else { n -= m; while ((n & 1) == 0) n >>= 1; }
		}
		return (long)n << Min(zm, zn);
	}
}