//#pragma warning disable
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;
using System.Numerics;
using System.Threading.Tasks;
using static System.Math;
using static System.Console;
class Z { static void Main() => new K(); }
class K
{
	int F() => int.Parse(ReadLine());
	long FL() => long.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	long[] GL() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
	public const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var N = F();
		var b = G().Select(x => -x).ToList();
		var g = new Dinic(N + 2);
		var s = 0L;
		for (var i = 0; i < N; i++)
			if (b[i] < 0)
			{
				s -= b[i];
				g.AddEdge(0, i + 1, 0);
				g.AddEdge(i + 1, N + 1, -b[i]);
			}
			else
			{
				g.AddEdge(0, i + 1, b[i]);
				g.AddEdge(i + 1, N + 1, 0);
			}
		for (var i = 1; i <= N; i++) for (var j = 2 * i; j <= N; j += i) g.AddEdge(i, j, Dinic.INF);
		Console.WriteLine(s - g.MaxFlow(0, N + 1));
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
		public Edge(int to, long cap, Edge rev)
		{
			To = to;
			Capacity = cap;
			Reverse = rev;
		}
	}
	public Dinic(int v)
	{
		V = v;
		es = new List<Edge>[v];
		for (var i = 0; i < V; i++) es[i] = new List<Edge>();
		level = new int[V];
	}
	readonly int V;
	readonly List<Edge>[] es;
	readonly int[] level;
	int[] iter;
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
			var g = DFS(e.To, t, Math.Min(e.Capacity, f));
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