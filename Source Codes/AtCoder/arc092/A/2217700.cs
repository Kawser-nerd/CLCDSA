using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Math;
class Z { static void Main() => new K(); }
class K
{
	int F => int.Parse(Str);
	long FL => long.Parse(Str);
	int[] G => Strs.Select(int.Parse).ToArray();
	long[] GL => Strs.Select(long.Parse).ToArray();
	string Str => ReadLine();
	string[] Strs => Str.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
	const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	struct Point
	{
		public readonly int x, y;
		public Point(int[] a) : this(a[0], a[1]) { }
		public Point(int a, int b) { x = a; y = b; }
	}
	void Solve()
	{
		var N = F;
		var a = new Point[N];
		var b = new Point[N];
		for (var i = 0; i < N; i++) a[i] = new Point(G);
		for (var i = 0; i < N; i++) b[i] = new Point(G);
		var g = new Dinic(2 * N + 2);
		for (var i = 0; i < N; i++) for (var j = 0; j < N; j++) if (a[i].x < b[j].x && a[i].y < b[j].y) g.AddEdge(i + 1, j + N + 1, 1);
		for (var i = 0; i < N; i++) { g.AddEdge(0, i + 1, 1); g.AddEdge(i + N + 1, 2 * N + 1, 1); }
		Console.WriteLine(g.MaxFlow(0, 2 * N + 1));
	}
}
class Dinic
{
	public const long INF = 4011686018427387913L;
	class Edge
	{
		public readonly int To;
		public long Capacity;
		public Edge Reverse;
		public Edge(int t, long c, Edge r)
		{
			To = t;
			Capacity = c;
			Reverse = r;
		}
	}
	public Dinic(int v)
	{
		V = v;
		level = new int[V];
		es = new List<Edge>[v];
		for (var i = 0; i < V; i++) es[i] = new List<Edge>();
	}
	readonly int V;
	int[] iter;
	readonly int[] level;
	readonly List<Edge>[] es;
	public void AddEdge(int f, int t, long c)
	{
		var e1 = new Edge(t, c, null);
		var e2 = new Edge(f, 0, e1);
		e1.Reverse = e2;
		es[f].Add(e1);
		es[t].Add(e2);
	}
	long DFS(int v, int t, long f)
	{
		if (v == t) return f;
		for (; iter[v] < es[v].Count; iter[v]++)
		{
			var e = es[v][iter[v]];
			if (level[v] >= level[e.To] || e.Capacity <= 0) continue;
			var g = DFS(e.To, t, Min(e.Capacity, f));
			if (g > 0)
			{
				e.Capacity -= g;
				e.Reverse.Capacity += g;
				return g;
			}
		}
		return 0;
	}
	void BFS(int s)
	{
		for (var i = 0; i < V; i++) level[i] = -1;
		var queue = new Queue<int>();
		level[s] = 0;
		queue.Enqueue(s);
		while (queue.Count > 0)
		{
			var v = queue.Dequeue();
			foreach (var e in es[v])
				if (e.Capacity > 0 && level[e.To] < 0)
				{
					level[e.To] = level[v] + 1;
					queue.Enqueue(e.To);
				}
		}
	}
	public long MaxFlow(int s, int t)
	{
		var flow = 0L;
		while (true)
		{
			BFS(s);
			if (level[t] < 0) return flow;
			iter = new int[V];
			while (true)
			{
				var f = DFS(s, t, INF);
				if (f <= 0) break;
				flow += f;
			}
		}
	}
}