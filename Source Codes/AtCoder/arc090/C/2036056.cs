using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
class Z { static void Main() => new K(); }
class K
{
	int[] G => Strs.Select(int.Parse).ToArray();
	string[] Strs => ReadLine().Split();
	const long MOD = 1000000007;
	const long InfL = 4011686018427387913L;
	public K() { WriteLine(Solve()); }
	int N;
	List<Edge>[] g;
	long Solve()
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
		var dt = DijkstraFrom(t);
		var cs = Count(s, ds);
		var ct = Count(t, dt);
		var ans = cs[t] * cs[t] % MOD;
		var D = ds[t];
		// s -> u -e-> e.To -> t
		for (var u = 0; u < N; u++) foreach (var e in g[u])
				//if (2 * ds[u] < D && ds[u] + e.D == ds[e.To] && dt[e.To] + e.D == dt[u] && 2 * ds[e.To] > D && 2 * dt[e.To] < D && 2 * dt[u] > D)
				if (2 * ds[u] < D && ds[u] + e.D + dt[e.To] == D && 2 * dt[e.To] < D && 2 * dt[u] > D && 2 * ds[e.To] > D)
				{
					var k = cs[u] * ct[e.To] % MOD;
					ans = (ans - k * k % MOD) % MOD;
				}
		for (var u = 0; u < N; u++) if (ds[u] == dt[u] && 2 * ds[u] == D)
			{
				var k = cs[u] * ct[u] % MOD;
				ans = (ans - k * k % MOD) % MOD;
			}
		ans %= MOD;
		if (ans < 0) ans += MOD;
		return ans;
	}
	// c[v] = #(u -> v: d[v])
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
		for (var i = 0; i < N; i++) d[i] = InfL;
		var queue = new PriorityQueue();
		d[u] = 0;
		queue.Enqueue(new Edge(u, 0));
		while (!queue.IsEmpty)
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
struct Edge : IEquatable<Edge>, IComparable<Edge>
{
	public readonly int To;
	public readonly long D;
	public Edge(int t, long d) { To = t; D = d; }
	public override int GetHashCode() => To.GetHashCode() ^ D.GetHashCode();
	public bool Equals(Edge e) => e.To == To && e.D == D;
	public override bool Equals(object obj) => Equals((Edge)obj);
	public override string ToString() => $"-> {To}: {D}";
	public int CompareTo(Edge e) => D.CompareTo(e.D);
}
class PriorityQueue
{
	readonly List<Edge> list = new List<Edge>();
	public int Count { get; private set; } = 0;
	public bool IsEmpty => Count == 0;
	public void Enqueue(Edge x)
	{
		var pos = Count++;
		list.Add(x);
		while (pos > 0)
		{
			var p = (pos - 1) / 2;
			if (list[p].CompareTo(x) <= 0) break;
			list[pos] = list[p];
			pos = p;
		}
		list[pos] = x;
	}
	public Edge Dequeue()
	{
		var val = list[0];
		var x = list[--Count];
		list.RemoveAt(Count);
		if (Count == 0) return val;
		var pos = 0;
		while (pos * 2 + 1 < Count)
		{
			var a = 2 * pos + 1;
			var b = 2 * pos + 2;
			if (b < Count && list[b].CompareTo(list[a]) < 0) a = b;
			if (list[a].CompareTo(x) >= 0) break;
			list[pos] = list[a];
			pos = a;
		}
		list[pos] = x;
		return val;
	}
	public Edge Peek() => list[0];
}