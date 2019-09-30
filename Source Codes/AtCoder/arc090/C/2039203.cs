using System.Linq;
using System.Collections.Generic;
using static System.Console;
class Z { static void Main() => new K(); }
class K
{
	const long MOD = 1000000007;
	static int[] G => ReadLine().Split().Select(int.Parse).ToArray();
	int N;
	long ans, D;
	long[] ds, dt, cs, ct;
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
		DijkstraFrom(s, ref ds, ref cs);
		DijkstraFrom(t, ref dt, ref ct);
		/*ds = DijkstraFrom(s);
		cs = Count(s, ds);
		ct = Count(t, DijkstraFrom(t));*/
		done = new bool[N];
		ans = cs[t] * cs[t] % MOD;
		D = ds[t];
		DFS(t);
		WriteLine((ans %= MOD) < 0 ? ans + MOD : ans);
	}
	long S(long x) => x * x % MOD;
	void DFS(int u)
	{
		if (done[u]) return;
		done[u] = true;
		if (2 * ds[u] == D) ans -= S(cs[u] * ct[u] % MOD);
		foreach (var e in g[u]) if (ds[e.V] + e.D == ds[u])
			{
				if (2 * ds[u] > D && 2 * ds[e.V] < D) ans -= S(ct[u] * cs[e.V] % MOD);
				DFS(e.V);
			}
	}
	/*long[] Count(int u, long[] d)
	{
		var t = new PriorityQueue();
		for (var i = 0; i < N; i++) t.Enqueue(new E(i, d[i]));
		t.Dequeue();
		var c = new long[N];
		c[u] = 1;
		while (t.Count > 0)
		{
			var v = t.Dequeue().V;
			foreach (var e in g[v]) if (d[e.V] + e.D == d[v]) c[v] = (c[v] + c[e.V]) % MOD;
		}
		return c;
	}*/
	void DijkstraFrom(int u, ref long[] d, ref long[] c)
	{
		d = new long[N]; c = new long[N];
		for (var v = 0; v < N; v++) d[v] = 4011686018427387913L;
		var queue = new PriorityQueue();
		d[u] = 0; c[u] = 1;
		queue.Enqueue(new E(u, 0));
		while (queue.Count > 0)
		{
			var p = queue.Dequeue();
			var v = p.V;
			if (d[v] < p.D) continue;
			foreach (var e in g[v])
			{
				var t = d[v] + e.D;
				if (d[e.V] > t) { queue.Enqueue(new E(e.V, d[e.V] = t)); c[e.V] = c[v]; }
				else if (d[e.V] == t) c[e.V] = (c[e.V] + c[v]) % MOD;
			}
		}
	}
}
struct E
{
	public readonly int V;
	public readonly long D;
	public E(int v, long d) { V = v; D = d; }
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