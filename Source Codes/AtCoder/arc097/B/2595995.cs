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
	void Solve()
	{
		var I = G;
		int N = I[0], M = I[1];
		var p = G.Select(i => i - 1).ToArray();
		var uf = new UnionFindTree(N);
		for (var i = 0; i < M; i++)
		{
			I = G;
			uf.UniteCategory(I[0] - 1, I[1] - 1);
		}
		var ans = 0;
		var cmps = new Dictionary<int, HashSet<int>>();
		for (var i = 0; i < N; i++)
		{
			var r = uf.GetRootOf(i);
			if (!cmps.ContainsKey(r)) cmps[r] = new HashSet<int>{ i };
			cmps[r].Add(i);
		}
		foreach (var s in cmps.Values) foreach (var i in s) if (s.Contains(p[i])) ans++;
		WriteLine(ans);
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