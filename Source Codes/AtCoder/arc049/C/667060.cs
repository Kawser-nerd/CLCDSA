using System;
using System.Collections.Generic;
using System.Linq;
class K { static void Main() { new E(); } }
class E
{
	int F() { return int.Parse(Console.ReadLine()); }
	int[] G() { return Console.ReadLine().Split().Select(_ => int.Parse(_)).ToArray(); }
	int N, A, B;
	Tuple<int, int>[] a, b;
	public E()
	{
		N = F(); A = F();
		a = new Tuple<int, int>[A];
		for (var i = 0; i < A; i++)
		{
			var I = G();
			a[i] = new Tuple<int, int>(I[0] - 1, I[1] - 1);
		}
		B = F();
		b = new Tuple<int, int>[B];
		for (var i = 0; i < B; i++)
		{
			var I = G();
			b[i] = new Tuple<int, int>(I[0] - 1, I[1] - 1);
		}
		var max = 0;
		for (var i = 0; i < (1 << B); i++)
		{
			var bit = new bool[B];
			for (var j = 0; j < B; j++) bit[j] = (i & (1 << j)) != 0;
			max = Math.Max(max, Draw(bit));
		}
		Console.WriteLine(max);
	}
	int Draw(bool[] bit)
	{
		var g = new Graph(N);
		var forbidden = new bool[N];
		for (var i = 0; i < A; i++) g.AddEdge(a[i].Item2, a[i].Item1);
		for (var j = 0; j < B; j++)
		{
			if (bit[j]) forbidden[b[j].Item1] = true;
			else g.AddEdge(b[j].Item1, b[j].Item2);
		}
		var count = 0;
		var charge = new int[N];
		var used = new bool[N];
		var queue = new Queue<int>();
		for (var i = 0; i < N; i++) if (g.InDegree(i) == 0 && !forbidden[i]) queue.Enqueue(i);
		while (queue.Count > 0)
		{
			var u = queue.Dequeue();
			if (!used[u]) { used[u] = true; count++; }
			foreach (var v in g.EdgesFrom[u])
			{
				if (forbidden[v] || used[v]) continue;
				if (++charge[v] == g.InDegree(v)) queue.Enqueue(v);
			}
		}
		return count;
	}
}
class Graph
{
	protected int V;
	public List<int>[] EdgesFrom;
	public List<int>[] EdgesTo;
	public int InDegree(int node) { return EdgesTo[node].Count; }
	public int OutDegree(int node) { return EdgesFrom[node].Count; }
	public Graph(int V)
	{
		this.V = V;
		EdgesFrom = Enumerable.Range(0, V).Select(_ => new List<int>()).ToArray();
		EdgesTo = Enumerable.Range(0, V).Select(_ => new List<int>()).ToArray();
	}
	public virtual void AddEdge(int from, int to)
	{
		EdgesFrom[from].Add(to);
		EdgesTo[to].Add(from);
	}
}