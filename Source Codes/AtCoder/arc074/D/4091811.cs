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
	int Y, X;
	List<GraphEdge> es;
	void Solve()
	{
		var I = G;
		Y = I[0]; X = I[1];
		var map = new bool[X, Y];
		int sx = 0, sy = 0, tx = 0, ty = 0;
		for (var y = 0; y < Y; y++)
		{
			var s = Str;
			for (var x = 0; x < X; x++)
			{
				switch (s[x])
				{
					case 'S': sx = x; sy = y; break;
					case 'T': tx = x; ty = y; break;
				}
				map[x, y] = s[x] == 'o';
			}
		}
		var V = X + Y + 2;
		es = new List<GraphEdge>();
		Add(S, vX(sx), Func.InfL);
		Add(S, vY(sy), Func.InfL);
		Add(vX(tx), T, Func.InfL);
		Add(vY(ty), T, Func.InfL);
		for (var x = 0; x < X; x++) for (var y = 0; y < Y; y++) if (map[x, y]) Add2(vX(x), vY(y), 1);
		var max = Func.CalcMaxFlow(V, S, T, es);
		WriteLine(max >= Func.InfL ? -1 : max);
	}
	void Add(int f, int t, long c) { es.Add(new GraphEdge(f, t, c)); }
	void Add2(int f, int t, long c) { Add(f, t, c); Add(t, f, c); }
	int S => 0;
	int T => X + Y + 1;
	int vX(int x) => x + 1;
	int vY(int y) => X + y + 1;
}
struct GraphEdge
{
	public readonly int From, To;
	public readonly long Capacity;
	public GraphEdge(int f, int t, long c)
	{
		From = f;
		To = t;
		Capacity = c;
	}
}
class MFEdge
{
	public int To;
	public long Capacity;
	public MFEdge Reverse;
	public MFEdge(int to, long cap, MFEdge rev)
	{
		To = to;
		Capacity = cap;
		Reverse = rev;
	}
}
static class Func
{
	public const int Inf = 1073741789;
	// 2 * Inf < int.MaxValue, and Inf is a prime number
	public const long InfL = 4011686018427387913L;
	// 2 * InfL < long.MaxValue, and InfL is a prime number
	public static long CalcMaxFlow(int V, int source, int sink, List<GraphEdge> es)
	{
		var mes = new List<MFEdge>[V];
		for (var u = 0; u < V; u++) mes[u] = new List<MFEdge>();
		foreach (var e in es)
		{
			var e1 = new MFEdge(e.To, e.Capacity, null);
			var e2 = new MFEdge(e.From, 0, e1);
			e1.Reverse = e2;
			mes[e.From].Add(e1);
			mes[e.To].Add(e2);
		}
		return MaxFlow(source, sink, mes);
	}
	static long MaxFlow(int s, int t, List<MFEdge>[] es)
	{
		var V = es.Length;
		var level = new int[V];
		var flow = 0L;
		while (true)
		{
			MFBFS(s, level, es);
			if (level[t] < 0) return flow;
			var iter = new int[V];
			while (true)
			{
				var f = MFDFS(s, t, InfL, level, iter, es);
				if (f <= 0) break;
				else flow += f;
			}
		}
	}
	static long MFDFS(int v, int t, long f, int[] level, int[] iter, List<MFEdge>[] es)
	{
		if (v == t) return f;
		for (; iter[v] < es[v].Count; iter[v]++)
		{
			var e = es[v][iter[v]];
			if (level[v] >= level[e.To] || e.Capacity <= 0) continue;
			var g = MFDFS(e.To, t, Min(e.Capacity, f), level, iter, es);
			if (g > 0)
			{
				e.Capacity -= g;
				e.Reverse.Capacity += g;
				return g;
			}
		}
		return 0;
	}
	static void MFBFS(int s, int[] level, List<MFEdge>[] es)
	{
		var V = es.Length;
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
}