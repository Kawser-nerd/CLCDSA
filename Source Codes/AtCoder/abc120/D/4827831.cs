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
	uint[] GU => Strs.Select(uint.Parse).ToArray();
	decimal[] GD => Strs.Select(decimal.Parse).ToArray();
	long[] GL => Strs.Select(long.Parse).ToArray();
	string Str => ReadLine();
	string[] Strs => Str.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
	static T[] ConstantArray<T>(int n, T val) { var a = new T[n]; for (var i = 0; i < n; i++) a[i] = val; return a; }
	static T[] MakeArray<T>(int n, Func<int, T> f) { var a = new T[n]; for (var i = 0; i < n; i++) a[i] = f(i); return a; }
	static ulong One(int k) => 1ul << k;
	static ulong All(int k) => One(k) - 1;
	static bool Has(ulong s, int k) => (s & One(k)) != 0;
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
		int V = I[0], E = I[1];
		var es = new int[E][];
		for (var i = 0; i < E; i++) es[i] = G;
		var uf = new UnionFindTree(V);
		var ans = new long[E];
		var sum = V * (V - 1L) / 2;
		for (var i = E - 1; i >= 0; i--)
		{
			ans[i] = sum;
			int u = es[i][0] - 1, v = es[i][1] - 1;
			if (!uf.IsSameCategory(u,v))
			{
				sum -= uf.GetSize(u) * (long)uf.GetSize(v);
				uf.UniteCategory(u, v);
			}
		}
		for (var i = 0; i < E; i++) WriteLine(ans[i]);
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