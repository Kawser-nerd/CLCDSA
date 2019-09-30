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
	int N;
	HashSet<int>[] es;
	void Solve()
	{
		N = F();
		es = new HashSet<int>[N];
		for (var i = 0; i < N; i++) es[i] = new HashSet<int>();
		for (var i = 1; i < N; i++)
		{
			var j = F();
			es[i].Add(j);
			es[j].Add(i);
		}
		p = new int[N];
		c = new int[N];
		DFS(0, -1);
		for (var i = 0; i < N; i++)
		{
			var ans = 0;
			foreach (var v in es[i]) ans = Max(ans, c[v]);
			Console.WriteLine(Max(ans, N - c[i]));
		}
	}
	int[] p, c;
	int DFS(int u, int q)
	{
		es[u].Remove(p[u] = q);
		c[u] = 1;
		foreach (var v in es[u]) c[u] += DFS(v, u);
		return c[u];
	}
}