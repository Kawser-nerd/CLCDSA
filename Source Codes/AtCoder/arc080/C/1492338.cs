using System.Collections.Generic;
using System.Linq;
using System;
using static System.Console;
class E { static void Main() => new J(); }
class J
{
	public const int Inf = 1073741789;
	int[] G() => ReadLine().Split().Select(int.Parse).ToArray();
	public J() { WriteLine(string.Join(" ", Calc())); }
	IEnumerable<int> Calc()
	{
		var N = G()[0];
		var a = G();
		var rev = new int[N];
		var par = new[] { new RMQ(N), new RMQ(N) };
		for (var i = 0; i < N; i++)
		{
			rev[--a[i]] = i;
			par[i & 1][i] = a[i];
			par[1 - (i & 1)][i] = Inf;
		}
		var que = new PriorityQueue();
		var dict = new Dictionary<int, P>();
		Action<P> add = p =>
		{
			var z = par[p.l & 1].Min(p);
			if (z < Inf) { dict[z] = p; que.Enqueue(z); }
		};
		add(new P(0, N));
		while (que.Count > 0)
		{
			int x = que.Dequeue(), i = rev[x];
			var p = dict[x];
			int f = p.l & 1, y = par[1 - f].Min(i + 1, p.r), j = rev[y];
			yield return x + 1;
			yield return y + 1;
			add(new P(p.l, i));
			add(new P(i + 1, j));
			add(new P(j + 1, p.r));
		}
	}
}
struct P
{
	public int l, r;
	public P(int x, int y) { l = x; r = y; }
}
class RMQ
{
	int N2;
	int[] seg;
	public RMQ(int N)
	{
		N2 = 1;
		while (N2 < N) N2 <<= 1;
		seg = new int[2 * N2 - 1];
		for (var i = 0; i < 2 * N2 - 1; i++) seg[i] = J.Inf;
	}
	public void Update(int i, int v)
	{
		i += N2 - 1;
		seg[i] = v;
		while (i > 0)
		{
			i = (i - 1) / 2;
			seg[i] = Math.Min(seg[i * 2 + 1], seg[i * 2 + 2]);
		}
	}
	public int this[int n] { set { Update(n, value); } }
	public int Min(P p) => Min(p.l, p.r);
	public int Min(int from, int to) => Min(from, to, 0, 0, N2);
	int Min(int from, int to, int node, int l, int r)
	{
		if (to <= l || r <= from) return J.Inf;
		else if (from <= l && r <= to) return seg[node];
		else return Math.Min(Min(from, to, 2 * node + 1, l, (l + r) >> 1), Min(from, to, 2 * node + 2, (l + r) >> 1, r));
	}
}
class PriorityQueue
{
	List<int> list = new List<int>();
	public int Count { get; private set; } = 0;
	public void Enqueue(int x)
	{
		var pos = Count++;
		list.Add(x);
		while (pos > 0)
		{
			var p = (pos - 1) / 2;
			if (list[p] <= x) break;
			list[pos] = list[p];
			pos = p;
		}
		list[pos] = x;
	}
	public int Dequeue()
	{
		var value = list[0];
		var x = list[--Count];
		list.RemoveAt(Count);
		if (Count == 0) return value;
		var pos = 0;
		while (pos * 2 + 1 < Count)
		{
			var a = 2 * pos + 1;
			var b = 2 * pos + 2;
			if (b < Count && list[b] < list[a]) a = b;
			if (list[a] >= x) break;
			list[pos] = list[a];
			pos = a;
		}
		list[pos] = x;
		return value;
	}
}