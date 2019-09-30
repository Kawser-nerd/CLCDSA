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
	int N;
	int[] P, X, Y;
	List<int>[] child;
	void Solve()
	{
		N = F();
		P = new int[N];
		P[0] = -1;
		X = G();
		child = new List<int>[N];
		for (var i = 0; i < N; i++) child[i] = new List<int>();
		for (var i = 0; i < N - 1; i++)
		{
			P[i + 1] = X[i] - 1;
			child[i + 1].Add(P[i + 1]);
			child[P[i + 1]].Add(i + 1);
		}
		X = G();
		Y = new int[N];
		WriteLine(DFS(0, -1) >= 0 ? "POSSIBLE" : "IMPOSSIBLE");
	}
	int DFS(int v, int p)
	{
		var x = new List<int>();
		var y = new List<int>();
		foreach (var c in child[v])
			if (c != p)
			{
				x.Add(X[c]);
				var t = DFS(c, v);
				if (t < 0) return Y[v] = -1;
				y.Add(t);
			}
		var d = x.Count;
		if (d == 0) return Y[v] = 0;
		var s = 0;
		for (var i = 0; i < d; i++) s += Min(x[i], y[i]);
		if (s > X[v]) return Y[v] = -1;
		var m = new int[X[v] + 1];
		for (var i = 1; i <= X[v]; i++) m[i] = MOD;
		for (var i = 0; i < d; i++)
		{
			var n = new int[X[v] + 1];
			for (var k = X[v]; k >= 0; k--)
			{
				n[k] = MOD;
				if (k >= x[i]) n[k] = Min(n[k], m[k - x[i]] + y[i]);
				if (k >= y[i]) n[k] = Min(n[k], m[k - y[i]] + x[i]);
			}
			m = n;
		}
		return Y[v] = m.Min();
	}
}