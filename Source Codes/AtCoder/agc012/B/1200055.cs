using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
using static System.Math;
using static System.Console;

class E { static void Main() => new J(); }
class J
{
	int F() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		var I = G();
		int V = I[0], E = I[1], D = 10;
		var es = new List<int>[V];
		for (var u = 0; u < V; u++) es[u] = new List<int> { u };
		for (var e = 0; e < E; e++)
		{
			I = G();
			int a = I[0] - 1, b = I[1] - 1;
			es[a].Add(b);
			es[b].Add(a);
		}
		var Q = F();
		var col = new int[Q + 1];
		var dp = new int[V, D + 1];
		for (var q = 0; q < Q; q++)
		{
			I = G();
			col[q + 1] = I[2];
			int u = I[0] - 1, d = I[1];
			dp[u, d] = Max(dp[u, d], q + 1);
		}
		for (var d = D; d > 0; d--) for (var u = 0; u < V; u++) foreach (var v in es[u]) dp[v, d - 1] = Max(dp[v, d - 1], dp[u, d]);
		for (var u = 0; u < V; u++) WriteLine(col[dp[u, 0]]);
		Out.Flush();
	}
}