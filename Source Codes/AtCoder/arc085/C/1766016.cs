using System.Linq;
using System.Collections.Generic;
using static System.Math;
using static System.Console;
class Z
{
	static void Main()
	{
		var N = int.Parse(ReadLine());
		var b = ReadLine().Split().Select(t => -int.Parse(t)).ToArray();
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
		WriteLine(s - g.MaxFlow(0, N + 1));
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