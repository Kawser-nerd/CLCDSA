using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using static System.Console;
// using System.Collections.Immutable;
class Z { static void Main() => new K(); }
class K
{
	int F => int.Parse(Str);
	int[] G => Strs.Select(int.Parse).ToArray();
	string Str => ReadLine();
	string[] Strs => Str.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
	const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	int N, M, Q;
	Tuple<int, int>[] es;
	Tuple<int, int, int>[] qs;
	void Solve()
	{
		var I = G;
		N = I[0];
		M = I[1];
		es = new Tuple<int, int>[M];
		for (var i = 0; i < M; i++)
		{
			I = G;
			es[i] = new Tuple<int, int>(I[0], I[1]);
		}
		Q = F;
		qs = new Tuple<int, int, int>[Q];
		for (var i = 0; i < Q; i++)
		{
			I = G;
			qs[i] = new Tuple<int, int, int>(I[0], I[1], I[2]);
		}
		{
			var i = 1;
			while (i < M) i <<= 1;
			var tmp = new Tuple<int, int>[i];
			for (var j = 0; j < M; j++) tmp[j] = new Tuple<int, int>(es[j].Item1 - 1, es[j].Item2 - 1);
			for (var j = M; j < i; j++) tmp[j] = new Tuple<int, int>(0, 0);
			es = tmp; M = i;
			for (var j = 0; j < Q; j++) qs[j] = new Tuple<int, int, int>(qs[j].Item1 - 1, qs[j].Item2 - 1, qs[j].Item3);
		}
		var log = MSB((uint)M);
		var seg = new List<int>[2 * M - 1];
		for (var i = 0; i < 2 * M - 1; i++) seg[i] = new List<int>();
		var node = 0;
		for (var i = 0; i < Q; i++) seg[node].Add(i);
		for (var i = 0; i < log; i++)
		{
			var uf = new UnionFindTree(N);
			var mod = 1 << (log - i);
			var e = 0;
			for (var j = mod >> 1; j < M; j += mod)
			{
				for (; e < j; e++) uf.UniteCategory(es[e].Item1, es[e].Item2);
				foreach (var q in seg[node])
				{
					int x = qs[q].Item1, y = qs[q].Item2, z = qs[q].Item3, w = 0;
					if (uf.IsSameCategory(x, y)) w = uf.GetSize(x);
					else w = uf.GetSize(x) + uf.GetSize(y);
					if (w >= z) seg[2 * node + 1].Add(q);
					else seg[2 * node + 2].Add(q);
				}
				seg[node].Clear();
				node++;
			}
		}
		var ans = new int[Q];
		for (var i = M - 1; i < 2 * M - 1; i++) foreach (var x in seg[i]) ans[x] = i - M + 1;
		for (var i = 0; i < Q; i++) WriteLine(ans[i] + 1);
	}
	public static int MSB(uint n)
	{
		n |= (n >> 1);
		n |= (n >> 2);
		n |= (n >> 4);
		n |= (n >> 8);
		n |= (n >> 16);
		return BitCount(n) - 1;
	}
	public static int BitCount(uint n)
	{
		n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
		n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
		n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
		n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
		return (int)((n & 0x0000ffff) + ((n >> 16) & 0x0000ffff));
	}
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
/*
struct UnionFindTree
{
	public static UnionFindTree Create(int N)
	{
		ImmutableList<int> p, r, s;
		r = p = s = ImmutableList.CreateRange(new int[N]);
		for (var i = 1; i < N; i++) p = p.SetItem(i, i);
		for (var i = 0; i < N; i++) s = s.SetItem(i, 1);
		return new UnionFindTree(p, r, s);
	}
	readonly ImmutableList<int> parent, rank, size;
	UnionFindTree(ImmutableList<int> p, ImmutableList<int> r, ImmutableList<int> s) { parent = p; rank = r; size = s; }
	public int GetSize(int x) => size[GetRootOf(x)];
	public int GetRootOf(int x) => parent[x] == x ? x : GetRootOf(parent[x]);
	public UnionFindTree UniteCategory(int x, int y)
	{
		if ((x = GetRootOf(x)) == (y = GetRootOf(y))) return this;
		ImmutableList<int> p = parent, s = size, r = rank;
		if (r[x] < r[y]) { p = p.SetItem(x, y); s = s.SetItem(y, s[y] + s[x]); }
		else
		{
			p = p.SetItem(y, x); s = s.SetItem(x, s[x] + s[y]);
			if (r[x] == r[y]) r = r.SetItem(x, r[x] + 1);
		}
		return new UnionFindTree(p, r, s);
	}
	public bool IsSameCategory(int x, int y) => GetRootOf(x) == GetRootOf(y);
}
*/