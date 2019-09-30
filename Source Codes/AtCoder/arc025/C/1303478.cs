using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;
using System.Numerics;
using static System.Math;
using static System.Console;
struct Pair
{
	public int u, d;
	public Pair(int u, int d = 0)
	{
		this.u = u;
		this.d = d;
	}
}
class E { static void Main() => new J(); }
class J
{
	const int INF = 1000000007;
	int V, R, T;
	List<Pair>[] es;
	long s;
	public J()
	{
		var I = G();
		V = I[0];
		int E = I[1]; R = I[2]; T = I[3];
		es = new List<Pair>[V];
		for (var i = 0; i < V; i++) es[i] = new List<Pair>();
		for (var e = 0; e < E; e++)
		{
			I = G();
			int a = I[0] - 1, b = I[1] - 1, c = I[2];
			es[a].Add(new Pair(b, c));
			es[b].Add(new Pair(a, c));
		}
		var hoge = new List<int>(V);
		for (var i = 0; i < V; i++) hoge.Add(i);
		hoge.Sort((x, y) => es[x].Count.CompareTo(es[y].Count));
		lands = hoge.Take(4).ToArray();
		island = new HashSet<int>(lands);
		foreach (var x in lands.Take(1))
		{
			var d = DijkstraFrom0(x);
			Estimate0(d);
			Calc(d);
		}
		foreach (var x in lands.Skip(1))
		{
			var d = DijkstraFrom(x);
			Estimate(d);
			Calc(d);
		}
		for (var u = 0; u < V; u++) if (!island.Contains(u)) Calc(DijkstraFrom(u));
		WriteLine(s);
		//for (var u = 0; u < V; u++) for (var v = 0; v < V; v++) Console.WriteLine("d[{0}, {1}] = {2}", u, v, est[u, v]);
	}
	void Estimate0(int[] d)
	{
		est = new int[V, V];
		for (var u = 0; u < V; u++) for (var v = 0; v < V; v++) est[u, v] = d[u] + d[v];
	}
	void Estimate(int[] d)
	{
		for (var u = 0; u < V; u++) for (var v = 0; v < V; v++) est[u, v] = Min(est[u, v], d[u] + d[v]);
	}
	void Calc(int[] d)
	{
		Array.Sort(d);
		var i = 1;
		for (var x = 1; x < V; x++)
		{
			var t = R * d[x] / T;
			while (i < V && t >= d[i]) i++;
			s += V - i;
			if (i <= x) s--;
		}
	}
	PriorityQueue q = new PriorityQueue();
	int[] lands;
	HashSet<int> island;
	int[,] est;
	int[] DijkstraFrom0(int u)
	{
		var d = new int[V];
		for (var i = 0; i < V; i++) d[i] = INF;
		q.Enqueue(new Pair(u, d[u] = 0));
		while (q.Count > 0)
		{
			var p = q.Dequeue();
			var v = p.u;
			if (d[v] < p.d) continue;
			foreach (var e in es[v])
			{
				var tmp = d[v] + e.d;
				if (d[e.u] > tmp) q.Enqueue(new Pair(e.u, d[e.u] = tmp));
			}
		}
		return d;
	}
	int[] DijkstraFrom(int u)
	{
		var d = new int[V];
		for (var i = 0; i < V; i++) d[i] = INF;
		q.Enqueue(new Pair(u, d[u] = 0));
		while (q.Count > 0)
		{
			var p = q.Dequeue();
			var v = p.u;
			if (d[v] < p.d) continue;
			foreach (var e in es[v])
			{
				var tmp = d[v] + e.d;
				if (d[e.u] > tmp && est[u, e.u] >= tmp) q.Enqueue(new Pair(e.u, d[e.u] = tmp));
			}
		}
		for (var i = u + 1; i < V; i++) est[i, u] = d[i];
		return d;
	}
	int[] G() => ReadLine().Split().Select(int.Parse).ToArray();
}
class PriorityQueue
{
	List<Pair> list = new List<Pair>(10000);
	public int Count;
	public void Enqueue(Pair x)
	{
		var pos = Count++;
		list.Add(x);
		while (pos > 0)
		{
			var p = (pos - 1) / 2;
			if (list[p].d <= x.d) break;
			list[pos] = list[p];
			pos = p;
		}
		list[pos] = x;
	}
	public Pair Dequeue()
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
			if (b < Count && list[b].d < list[a].d) a = b;
			if (list[a].d >= x.d) break;
			list[pos] = list[a];
			pos = a;
		}
		list[pos] = x;
		return value;
	}
}