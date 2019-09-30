using System;
using System.Collections.Generic;

class H
{
	public static void Main()
	{
		new K().Solve();
	}
}
class K
{
	const int Inf = 1073741789;
	int N, M, V;
	int[] us, vs, ws;
	List<int>[] es;
	HashSet<int> dead;
	int[] F()
	{
		var t = Console.ReadLine().Split();
		var L = t.Length;
		var I = new int[L];
		for (var i = 0; i < L; i++) I[i] = int.Parse(t[i]);
		return I;
	}
	public void Solve()
	{
		var I = F();
		N = I[0];
		M = I[1];
		us = new int[M];
		vs = new int[M];
		ws = new int[M];
		var cs = new SortedSet<int>[N];
		for (var i = 0; i < N; i++)
		{
			cs[i] = new SortedSet<int>();
			cs[i].Add(-1);
		}
		for (var i = 0; i < M; i++)
		{
			I = F();
			var a = us[i] = I[0] - 1;
			var b = vs[i] = I[1] - 1;
			var c = ws[i] = I[2] - 1;
			cs[a].Add(c);
			cs[b].Add(c);
		}
		var sep = new int[N + 1];
		for (var i = 0; i < N; i++) sep[i + 1] = sep[i] + cs[i].Count;
		dead = new HashSet<int>(sep);
		V = sep[N];
		var index = new Dictionary<int, int>[N];
		for (int i = 0, j = 0; i < N; i++)
		{
			index[i] = new Dictionary<int, int>();
			foreach (var c in cs[i]) index[i].Add(c, j++);
		}
		es = new List<int>[V];
		for (var i = 0; i < V; i++) es[i] = new List<int>();
		for (var i = 0; i < M; i++)
		{
			int a = us[i], b = vs[i], c = ws[i], u = index[a][c], v = index[b][c];
			es[u].Add(v);
			es[v].Add(u);
		}
		for (var i = 0; i < N; i++)
		{
			var l = sep[i];
			var k = sep[i + 1];
			for (var j = l + 1; j < k; j++)
			{
				es[j].Add(l);
				es[l].Add(j);
			}
		}
		var d = DijkstraFrom(0);
		Console.WriteLine(d[sep[N - 1]] == Inf ? -1 : d[sep[N - 1]]);
	}
	int[] DijkstraFrom(int from)
	{
		var d = new int[V];
		for (var i = 0; i < V; i++) d[i] = Inf;
		var queue = new PQ();
		d[from] = 0;
		queue.Enqueue(new P(from, 0));
		while (queue.Count > 0)
		{
			var p = queue.Dequeue();
			int u = p.First, tmp = d[u] + (dead.Contains(u) ? 1 : 0);
			if (d[u] < p.Second) continue;
			var k = es[u].Count;
			for (var i = 0; i < k; i++)
			{
				int v = es[u][i];
				if (d[v] > tmp) queue.Enqueue(new P(v, d[v] = tmp));
			}
		}
		return d;
	}
}
class PQ
{
	List<P> list = new List<P>();
	public int Count = 0;
	public void Enqueue(P x)
	{
		var k = x.Second;
		var pos = Count++;
		list.Add(x);
		while (pos > 0)
		{
			var p = (pos - 1) / 2;
			if (list[p].Second <= k) break;
			list[pos] = list[p];
			pos = p;
		}
		list[pos] = x;
	}
	public P Dequeue()
	{
		var value = list[0];
		var x = list[--Count];
		var k = x.Second;
		list.RemoveAt(Count);
		if (Count == 0) return value;
		var pos = 0;
		while (pos * 2 + 1 < Count)
		{
			var a = 2 * pos + 1;
			var b = 2 * pos + 2;
			if (b < Count && list[b].Second < list[a].Second) a = b;
			if (list[a].Second >= k) break;
			list[pos] = list[a];
			pos = a;
		}
		list[pos] = x;
		return value;
	}
}
class P
{
	public int First;
	public int Second;
	public P(int s = 0, int t = 0)
	{
		First = s;
		Second = t;
	}
}