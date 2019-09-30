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
	void Solve()
	{
		var I = G();
		int V = I[0], E = I[1];
		var d = new int[V, V];
		for (var u = 0; u < V; u++) for (var v = 0; v < V; v++) d[u, v] = MOD;
		for (var u = 0; u < V; u++) d[u, u] = 0;
		for (var e = 0; e < E; e++)
		{
			I = G();
			int a = I[0] - 1, b = I[1] - 1, c = I[2];
			d[a, b] = d[b, a] = c;
		}
		for (var k = 0; k < V; k++) for (var u = 0; u < V; u++) for (var v = 0; v < V; v++) d[u, v] = Min(d[u, v], d[u, k] + d[k, v]);
		var q = F();
		for (var i = 0; i < q; i++)
		{
			I = G();
			int a = I[0] - 1, b = I[1] - 1, c = I[2];
			var s = 0L;
			for (var u = 0; u < V; u++) for (var v = 0; v < V; v++) s += d[u, v] = Min(d[u, v], Min(d[u, a] + c + d[b, v], d[u, b] + c + d[a, v]));
			Console.WriteLine(s / 2);
		}
	}
}