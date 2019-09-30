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
		//SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		//Out.Flush();
	}
	int V, E, k, M;
	char[] c;
	int[] which;
	List<int>[] es, res, fs;
	string[] s;
	void Solve()
	{
		var I = G();
		V = I[0];
		E = I[1];
		k = I[2];
		c = Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(s => s[0]).ToArray();
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
			//Console.WriteLine("len[{0}] = {1}", u, ls[u]);
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
						//var tmp = best == null ? null : s[u].Substring(0, m) + best;
						var tmp = s[u].Substring(0, m) + best;
						if (Compare(dp[u, n], tmp) > 0) dp[u, n] = tmp;
					}
				}
				if (dp[u, n] != null && dp[u, n].Length != n) dp[u, n] = null;
				//Console.WriteLine("dp[{0}, {1}] = {2}", u, n, dp[u, n]);
			}
		}
		//Console.WriteLine("M = {0}", M);
		//for (var i = 0; i < V; i++) Console.WriteLine("f[{0}] = {1}", i, which[i]);
		//for (var i = 0; i < M; i++) foreach (var w in fs[i]) Console.WriteLine("{0} -> {1}", i, w);
		//for (var i = 0; i < M; i++) Console.WriteLine("S[{0}] = {1}", i, s[i]);
		string min = null;
		for (var i = 0; i < M; i++) if (Compare(min, dp[i, k]) > 0) min = dp[i, k];
		Console.WriteLine(min ?? "-1");
	}
	// null is max
	int Compare(string a, string b)
	{
		if (a == b) return 0;
		if (a == null) return 1;
		if (b == null) return -1;
		return a.CompareTo(b);
	}
	public void StronglyConnectedComponents()
	{
		var mark = new bool[V];
		var stack = new Stack<int>();
		Action<int> dfs = null;
		dfs = v =>
		{
			mark[v] = true;
			foreach (var w in es[v]) if (!mark[w]) dfs(w);
			stack.Push(v);
		};
		for (var v = 0; v < V; v++) if (!mark[v]) dfs(v);
		var scc = new List<HashSet<int>>();
		mark = new bool[V];
		which = new int[V];
		Action<int, HashSet<int>> rdfs = null;
		rdfs = (v, set) =>
		{
			set.Add(v);
			mark[v] = true;
			foreach (var w in res[v]) if (!mark[w]) rdfs(w, set);
		};
		while (stack.Count > 0)
		{
			var v = stack.Pop();
			if (mark[v]) continue;
			var set = new HashSet<int>();
			rdfs(v, set);
			scc.Add(set);
			foreach (var w in set) which[w] = M;
			M++;
		}
		fs = new List<int>[M];
		var tmp = new List<char>[M];
		for (var v = 0; v < M; v++) fs[v] = new List<int>();
		for (var v = 0; v < M; v++) tmp[v] = new List<char>();
		for (var v = 0; v < V; v++) tmp[which[v]].Add(c[v]);
		s = new string[M];
		for (var v = 0; v < M; v++)
		{
			tmp[v].Sort();
			s[v] = new string(tmp[v].ToArray());
		}
		for (var v = 0; v < V; v++) foreach (var w in es[v])
			{
				int a = which[v], b = which[w];
				if (a != b) fs[a].Add(b);
			}
	}
}