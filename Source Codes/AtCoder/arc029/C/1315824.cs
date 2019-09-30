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
class E { static void Main() => new K(); }
class K
{
	int F() => int.Parse(ReadLine());
	long FL() => int.Parse(ReadLine());
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
		var I = G();
		int N = I[0], M = I[1];
		var es = new Edge[M + N];
		for (var i = 0; i < N; i++) es[i] = new Edge(i, N, F());
		for (var i = 0; i < M; i++)
		{
			I = G();
			es[N + i] = new Edge(I[0] - 1, I[1] - 1, I[2]);
		}
		Array.Sort(es);
		var uf = new UnionFindTree(N + 1);
		var sum = 0L;
		var c = 0;
		foreach (var e in es)
		{
			if (!uf.IsSameCategory(e.From, e.To))
			{
				uf.UniteCategory(e.From, e.To);
				sum += e.Cost;
				if (++c == N) break;
			}
		}
		WriteLine(sum);
	}
}
struct Edge : IComparable<Edge>
{
	public int From, To, Cost;
	public Edge(int f, int t, int c = 0)
	{
		From = f;
		To = t;
		Cost = c;
	}
	public int CompareTo(Edge e) => Cost.CompareTo(e.Cost);
}
class UnionFindTree
{
	int N;
	int[] parent, rank;
	public UnionFindTree(int capacity)
	{
		N = capacity;
		parent = new int[N];
		rank = new int[N];
		for (var i = 0; i < N; i++) parent[i] = i;
	}
	public int GetRootOf(int x) => parent[x] == x ? x : parent[x] = GetRootOf(parent[x]);
	public bool UniteCategory(int x, int y)
	{
		if ((x = GetRootOf(x)) == (y = GetRootOf(y))) return false;
		if (rank[x] < rank[y]) parent[x] = y;
		else
		{
			parent[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
		return true;
	}
	public bool IsSameCategory(int x, int y) => GetRootOf(x) == GetRootOf(y);
}