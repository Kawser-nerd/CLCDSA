using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;
using System.Numerics;
using static System.Math;
using static System.Console;

class E { static void Main() => new J(); }
class J
{
	int F() => int.Parse(ReadLine());
	long FL() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	long[] GL() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
	public const int MOD = 1000000007;
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	int N;
	string S;
	void Solve()
	{
		N = F();
		S = ReadLine();
		var m = N;
		var c = new[]{ 'A', 'B', 'X', 'Y' };
		foreach (var l1 in c) foreach (var l2 in c) foreach (var r1 in c) foreach (var r2 in c) m = Min(m, Calc(l1, l2, r1, r2));
		WriteLine(m);
	}
	int Calc(char l1, char l2, char r1, char r2)
	{
		var dp = new int[N + 1];
		dp[1] = 1;
		for (var i = 2; i <= N; i++)
		{
			dp[i] = dp[i - 1] + 1;
			if (S[i - 1] == l2 && S[i - 2] == l1) dp[i] = Min(dp[i], dp[i - 2] + 1);
			if (S[i - 1] == r2 && S[i - 2] == r1) dp[i] = Min(dp[i], dp[i - 2] + 1);
		}
		return dp[N];
	}
}
class PriorityQueue
{
	List<Tuple<int, int>> list = new List<Tuple<int, int>>();
	public int Count;
	public PriorityQueue() { }
	public void Enqueue(Tuple<int, int> x)
	{
		var pos = Count++;
		list.Add(x);
		while (pos > 0)
		{
			var p = (pos - 1) / 2;
			if (list[p].Item2 <= x.Item2) break;
			list[pos] = list[p];
			pos = p;
		}
		list[pos] = x;
	}
	public Tuple<int, int> Dequeue()
	{
		var value = list[0];
		var x = list[--Count];
		list.RemoveAt(Count);
		if (Count == 0) return value;
		var pos = 0;
		while (pos * 2 + 1 < Count)
		{
			var a = 2 * pos + 1;
			var b = 2 * pos + 2;
			if (b < Count && list[b].Item2 < list[a].Item2) a = b;
			if (list[a].Item2 >= x.Item2) break;
			list[pos] = list[a];
			pos = a;
		}
		list[pos] = x;
		return value;
	}
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