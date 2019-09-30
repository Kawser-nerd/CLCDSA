using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
class Z { static void Main() => new K(); }
class K
{
	int[] G => ReadLine().Split().Select(int.Parse).ToArray();
	const long MOD = 1000000007;
	const long InfL = 4011686018427387913L;
	int N;
	List<Edge>[] g;
	public K()
	{
		var I = G;
		N = I[0];
		var M = I[1];
		I = G;
		var s = I[0] - 1;
		var t = I[1] - 1;
		g = new List<Edge>[N];
		for (var i = 0; i < N; i++) g[i] = new List<Edge>();
		for (var i = 0; i < M; i++)
		{
			I = G;
			int a = I[0] - 1, b = I[1] - 1, c = I[2];
			g[a].Add(new Edge(b, c));
			g[b].Add(new Edge(a, c));
		}
		var ds = DijkstraFrom(s);
		var cs = Count(s, ds);
		var ct = Count(t, DijkstraFrom(t));
		done = new bool[N];
		DFS(t, ds);
		var ans = cs[t] * cs[t] % MOD;
		var D = ds[t];
		for (var u = 0; u < N; u++) if (done[u])
			{
				if (2 * ds[u] == D) ans = (ans - cs[u] * cs[u] % MOD * ct[u] % MOD * ct[u] % MOD) % MOD;
				else if (2 * ds[u] < D)
					foreach (var e in g[u]) if (done[e.To] && 2 * ds[e.To] > D && ds[u] + e.D == ds[e.To]) ans = (ans - cs[u] * cs[u] % MOD * ct[e.To] % MOD * ct[e.To] % MOD) % MOD;
			}
		if (ans < 0) ans += MOD;
		WriteLine(ans);
	}
	bool[] done;
	void DFS(int u, long[] d)
	{
		if (done[u]) return;
		done[u] = true;
		foreach (var e in g[u]) if (!done[e.To] && d[e.To] + e.D == d[u]) DFS(e.To, d);
	}
	long[] Count(int u, long[] d)
	{
		var t = new List<Edge>();
		for (var i = 0; i < N; i++) t.Add(new Edge(i, d[i]));
		t.Sort();
		var c = new long[N];
		c[u] = 1;
		foreach (var v in t.Select(hoge => hoge.To)) foreach (var e in g[v]) if (d[e.To] + e.D == d[v]) c[v] = (c[v] + c[e.To]) % MOD;
		return c;
	}
	long[] DijkstraFrom(int u)
	{
		var d = new long[N];
		for (var v = 0; v < N; v++) d[v] = InfL;
		var queue = new PriorityQueue();
		d[u] = 0;
		queue.Enqueue(new Edge(u, 0));
		while (queue.Count > 0)
		{
			var p = queue.Dequeue();
			var v = p.To;
			if (d[v] < p.D) continue;
			foreach (var e in g[v])
			{
				var t = d[v] + e.D;
				if (d[e.To] > t) queue.Enqueue(new Edge(e.To, d[e.To] = t));
			}
		}
		return d;
	}
}
struct Edge : IComparable<Edge>
{
	public readonly int To;
	public readonly long D;
	public Edge(int t, long d) { To = t; D = d; }
	public int CompareTo(Edge e) => D.CompareTo(e.D);
}
class PriorityQueue
{
	readonly List<Edge> list = new List<Edge>();
	public int Count { get; private set; } = 0;
	public void Enqueue(Edge x)
	{
		var i = Count++;
		list.Add(x);
		while (i > 0)
		{
			var p = (i - 1) / 2;
			if (list[p].CompareTo(x) <= 0) break;
			list[i] = list[p];
			i = p;
		}
		list[i] = x;
	}
	public Edge Dequeue()
	{
		var v = list[0];
		var x = list[--Count];
		list.RemoveAt(Count);
		if (Count == 0) return v;
		var i = 0;
		while (i * 2 + 1 < Count)
		{
			var l = 2 * i + 1;
			var r = 2 * i + 2;
			if (r < Count && list[r].CompareTo(list[l]) < 0) l = r;
			if (list[l].CompareTo(x) >= 0) break;
			list[i] = list[l];
			i = l;
		}
		list[i] = x;
		return v;
	}
	public Edge Peek() => list[0];
}