using System.Collections.Generic;
using System.Linq;
using System;
using static System.Math;
using static System.Console;
class E { static void Main() => new K(); }
class K
{
	int[] G() => ReadLine().Split().Select(int.Parse).ToArray();
	int V, E, k, M;
	char[] c;
	int[] which;
	List<int>[] es, res;
	HashSet<int>[] fs;
	string[] s;
	public K()
	{
		var I = G();
		V = I[0];
		E = I[1];
		k = I[2];
		c = Console.ReadLine().Split().Select(s => s[0]).ToArray();
		es = new List<int>[V];
		res = new List<int>[V];
		for (var i = 0; i < V; i++) es[i] = new List<int>();
		for (var i = 0; i < V; i++) res[i] = new List<int>();
		for (var i = 0; i < E; i++)
		{
			I = G();
			int a = I[0] - 1, b = I[1] - 1;
			es[a].Add(b);
			res[b].Add(a);
		}
		StronglyConnectedComponents();
		var dp = new string[M, k + 1];
		var ls = new int[M];
		for (var u = M - 1; u >= 0; u--)
		{
			foreach (var v in fs[u]) ls[u] = Max(ls[u], ls[v]);
			ls[u] += s[u].Length;
		}
		for (var u = M - 1; u >= 0; u--)
		{
			var len = s[u].Length;
			dp[u, 0] = "";
			for (var n = 1; n <= k && n <= ls[u]; n++)
			{
				if (n <= len) dp[u, n] = s[u].Substring(0, n);
				if (fs[u].Count > 0)
				{
					for (var m = Max(0, n + len - ls[u]); m <= n && m <= len; m++)
					{
						string best = null;
						foreach (var v in fs[u]) if (Compare(best, dp[v, n - m]) > 0) best = dp[v, n - m];
						var tmp = s[u].Substring(0, m) + best;
						if (Compare(dp[u, n], tmp) > 0) dp[u, n] = tmp;
					}
				}
				if (dp[u, n] != null && dp[u, n].Length != n) dp[u, n] = null;
			}
		}
		string min = null;
		for (var i = 0; i < M; i++) if (Compare(min, dp[i, k]) > 0) min = dp[i, k];
		Console.WriteLine(min ?? "-1");
	}
	int Compare(string a, string b)
	{
		if (a == b) return 0;
		if (a == null) return 1;
		if (b == null) return -1;
		return a.CompareTo(b);
	}
	bool[] mark;
	Stack<int> stack;
	void DFS(int v)
	{
		mark[v] = true;
		foreach (var w in es[v]) if (!mark[w]) DFS(w);
		stack.Push(v);
	}
	void RDFS(int v, HashSet<int> set)
	{
		set.Add(v);
		mark[v] = true;
		foreach (var w in res[v]) if (!mark[w]) RDFS(w, set);
	}
	public void StronglyConnectedComponents()
	{
		mark = new bool[V];
		stack = new Stack<int>();
		for (var v = 0; v < V; v++) if (!mark[v]) DFS(v);
		var scc = new List<HashSet<int>>();
		mark = new bool[V];
		which = new int[V];
		while (stack.Count > 0)
		{
			var v = stack.Pop();
			if (mark[v]) continue;
			var set = new HashSet<int>();
			RDFS(v, set);
			scc.Add(set);
			foreach (var w in set) which[w] = M;
			M++;
		}
		fs = new HashSet<int>[M];
		var tmp = new List<char>[M];
		for (var v = 0; v < M; v++) fs[v] = new HashSet<int>();
		for (var v = 0; v < M; v++) tmp[v] = new List<char>();
		for (var v = 0; v < V; v++) tmp[which[v]].Add(c[v]);
		s = new string[M];
		for (var v = 0; v < M; v++)
		{
			tmp[v].Sort();
			s[v] = new string(tmp[v].ToArray());
		}
		for (var v = 0; v < V; v++) foreach (var w in es[v]) fs[which[v]].Add(which[w]);
		for (var v = 0; v < M; v++) fs[v].Remove(v);
	}
}