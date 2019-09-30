using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
class Z { static void Main() => new K(); }
class K
{
	int[] G => ReadLine().Split().Select(int.Parse).ToArray();
	const long MOD = 1000000007;
	int N;
	long ans, D;
	long[] ds, cs, ct;
	bool[] done;
	List<E>[] g;
	public K()
	{
		var I = G;
		N = I[0];
		var M = I[1];
		I = G;
		var s = I[0] - 1;
		var t = I[1] - 1;
		g = new List<E>[N];
		for (var i = 0; i < N; i++) g[i] = new List<E>();
		for (var i = 0; i < M; i++)
		{
			I = G;
			int a = I[0] - 1, b = I[1] - 1, c = I[2];
			g[a].Add(new E(b, c));
			g[b].Add(new E(a, c));
		}
		ds = DijkstraFrom(s);
		cs = Count(s, ds);
		ct = Count(t, DijkstraFrom(t));
		done = new bool[N];
		ans = cs[t] * cs[t] % MOD;
		D = ds[t];
		DFS(t);
		WriteLine((ans %= MOD) < 0 ? ans + MOD : ans);
	}
	long Sq(long x) => x * x % MOD;
	void DFS(int u)
	{
		if (done[u]) return;
		done[u] = true;
		if (2 * ds[u] == D) ans -= Sq(cs[u] * ct[u] % MOD);
		foreach (var e in g[u]) if (ds[e.To] + e.D == ds[u])
			{
				if (2 * ds[u] > D && 2 * ds[e.To] < D) ans -= Sq(ct[u] * cs[e.To] % MOD);
				DFS(e.To);
			}
	}
	long[] Count(int u, long[] d)
	{
		var t = new List<E>();
		for (var i = 0; i < N; i++) t.Add(new E(i, d[i]));
		t.Sort();
		var c = new long[N];
		c[u] = 1;
		foreach (var v in t.Select(hoge => hoge.To)) foreach (var e in g[v]) if (d[e.To] + e.D == d[v]) c[v] = (c[v] + c[e.To]) % MOD;
		return c;
	}
	long[] DijkstraFrom(int u)
	{
		var d = new long[N];
		for (var v = 0; v < N; v++) d[v] = 4011686018427387913L;
		var queue = new PriorityQueue();
		d[u] = 0;
		queue.Enqueue(new E(u, 0));
		while (queue.Count > 0)
		{
			var p = queue.Dequeue();
			var v = p.To;
			if (d[v] < p.D) continue;
			foreach (var e in g[v])
			{
				var t = d[v] + e.D;
				if (d[e.To] > t) queue.Enqueue(new E(e.To, d[e.To] = t));
			}
		}
		return d;
	}
}
struct E : IComparable<E>
{
	public readonly int To;
	public readonly long D;
	public E(int t, long d) { To = t; D = d; }
	public int CompareTo(E e) => D.CompareTo(e.D);
}
class PriorityQueue
{
	readonly List<E> a = new List<E>();
	public int Count { get; private set; } = 0;
	public void Enqueue(E x)
	{
		var i = Count++;
		a.Add(x);
		while (i > 0)
		{
			var p = (i - 1) / 2;
			if (a[p].CompareTo(x) <= 0) break;
			a[i] = a[p];
			i = p;
		}
		a[i] = x;
	}
	public E Dequeue()
	{
		var v = a[0];
		var x = a[--Count];
		a.RemoveAt(Count);
		if (Count == 0) return v;
		var i = 0;
		while (i * 2 + 1 < Count)
		{
			var l = 2 * i + 1;
			var r = 2 * i + 2;
			if (r < Count && a[r].CompareTo(a[l]) < 0) l = r;
			if (a[l].CompareTo(x) >= 0) break;
			a[i] = a[l];
			i = l;
		}
		a[i] = x;
		return v;
	}
	public E Peek() => a[0];
}