using System.Collections.Generic;
using System.Linq;
using System;
using static System.Math;
using static System.Console;
class Z { static void Main() => new K(); }
class K
{
	int F() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split().Select(int.Parse).ToArray();
	public const int MOD = 1000000007;
	public K() { Solve(); }
	int V, R, T, C;
	List<E>[] es;
	long s;
	void Solve()
	{
		var I = G();
		V = I[0];
		int E = I[1]; R = I[2]; T = I[3];
		es = new List<E>[V];
		var deg = new int[V];
		for (var i = 0; i < V; i++) es[i] = new List<E>();
		for (var e = 0; e < E; e++)
		{
			I = G();
			AddEdge(I[0] - 1, I[1] - 1, I[2]);
		}
		for (var u = 0; u < V; u++) Calc(DijkstraFrom(u));
		Console.WriteLine(s);
	}
	void Calc(int[] d)
	{
		Array.Sort(d);
		var i = 1;
		for (var x = 1; x < V; x++)
		{
			var t = R * d[x] / T;
			while (i < V && t >= d[i]) i++;
			if (i == V) return;
			s += V - i;
			if (i <= x) s--;
		}
	}
	void AddEdge(int f, int t, int c)
	{
		es[f].Add(new E(t, c));
		es[t].Add(new E(f, c));
		C = Max(C, c);
	}
	int[] DijkstraFrom(int from)
	{
		var d = Enumerable.Repeat(MOD, V).ToArray();
		var queue = new DialQueue(C);
		d[from] = 0;
		queue.Add(from, 0);
		while (queue.Any)
		{
			var p = queue.Pop();
			var v = p.To;
			if (d[v] < p.Cost) continue;
			foreach (var e in es[v])
			{
				var tmp = d[v] + e.Cost;
				if (d[e.To] > tmp)
				{
					if (d[e.To] != MOD) queue.Move(e.To, d[e.To], tmp);
					else queue.Add(e.To, tmp);
					d[e.To] = tmp;
				}
			}
		}
		return d;
	}
}
struct E
{
	public int To, Cost;
	public E(int t, int c)
	{
		To = t;
		Cost = c;
	}
}
class DialQueue
{
	public int Count { get; private set; }
	int C, offset;
	HashSet<int>[] buckets;
	HashSet<int> this[int n] { get { return buckets[(n - offset + offset % C) % C]; } }
	public DialQueue(int c)
	{
		C = c + 1;
		buckets = new HashSet<int>[C];
		for (var i = 0; i < C; i++) buckets[i] = new HashSet<int>();
	}
	public void Add(int v, int d)
	{
		Count++;
		this[d].Add(v);
	}
	public void Move(int v, int prev, int now)
	{
		this[prev].Remove(v);
		this[now].Add(v);
	}
	public bool Any { get { return Count > 0; } }
	public E Pop()
	{
		Count--;
		var t = offset;
		while (true)
		{
			var s = this[t];
			if (s.Count > 0)
			{
				var v = s.First();
				s.Remove(v);
				return new E(v, offset = t);
			}
			t++;
		}
	}
}