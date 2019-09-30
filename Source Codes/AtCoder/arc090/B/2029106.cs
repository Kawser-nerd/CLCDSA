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
		Console.WriteLine(Solve() ? "Yes" : "No");
		Out.Flush();
	}
	int N, Q;
	List<Edge>[] g;
	int[] l, r, d, x;
	bool[] done;
	bool Solve()
	{
		var I = G;
		N = I[0];
		Q = I[1];
		l = new int[Q];
		r = new int[Q];
		d = new int[Q];
		var uf = new UnionFindTree(N);
		x = new int[N];
		done = new bool[N];
		g = new List<Edge>[N];
		for (var i = 0; i < N; i++) g[i] = new List<Edge>();
		for (var i = 0; i < Q; i++)
		{
			I = G;
			l[i] = I[0] - 1;
			r[i] = I[1] - 1;
			d[i] = I[2];
			g[l[i]].Add(new Edge(r[i], -d[i]));
			g[r[i]].Add(new Edge(l[i], +d[i]));
			uf.UniteCategory(l[i], r[i]);
		}
		for (var i = 0; i < N; i++) if (!done[uf.GetRootOf(i)] && !DFS(uf.GetRootOf(i), 0)) return false;
		return true;
	}
	bool DFS(int u, int y)
	{
		if (done[u])
		{
			if (x[u] != y) return false;
			return true;
		}
		x[u] = y;
		done[u] = true;
		foreach (var v in g[u]) if (!DFS(v.To, x[u] - v.D)) return false;
		return true;
	}
}
// x[i] - x[to] = d
struct Edge
{
	public readonly int To, D;
	public Edge(int t, int d) { To = t; D = d; }
}
class UnionFindTree
{
	int N;
	int[] parent, rank, size;
	public UnionFindTree(int capacity)
	{
		N = capacity;
		parent = new int[N];
		rank = new int[N];
		size = new int[N];
		for (var i = 0; i < N; i++) { parent[i] = i; size[i] = 1; }
	}
	public int GetSize(int x) => size[GetRootOf(x)];
	public int GetRootOf(int x) => parent[x] == x ? x : parent[x] = GetRootOf(parent[x]);
	public bool UniteCategory(int x, int y)
	{
		if ((x = GetRootOf(x)) == (y = GetRootOf(y))) return false;
		if (rank[x] < rank[y]) { parent[x] = y; size[y] += size[x]; }
		else
		{
			parent[y] = x; size[x] += size[y];
			if (rank[x] == rank[y]) rank[x]++;
		}
		return true;
	}
	public bool IsSameCategory(int x, int y) => GetRootOf(x) == GetRootOf(y);
}