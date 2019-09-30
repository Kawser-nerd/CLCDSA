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
	//int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	int[] G() => ReadLine().Split().Select(int.Parse).ToArray();
	long[] GL() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
	public const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		//var I = G();
		int V = Get(), E = Get();
		var d = new int[V, V];
		for (var u = 0; u < V; u++) for (var v = 0; v < V; v++) d[u, v] = MOD;
		for (var u = 0; u < V; u++) d[u, u] = 0;
		for (var e = 0; e < E; e++)
		{
			//I = G();
			int a = Get() - 1, b = Get() - 1;
			d[a, b] = d[b, a] = Get();
		}
		for (var k = 0; k < V; k++) for (var u = 0; u < V; u++) for (var v = 0; v < V; v++)
				{
					var c = d[u, k] + d[k, v];
					if (d[u, v] > c) d[u, v] = c;
				}
		var q = Get();
		var s = 0L;
		for (var u = 0; u < V; u++) for (var v = 0; v < u; v++) s += d[u, v];
		var ans = new StringBuilder();
		for (var i = 0; i < q; i++)
		{
			//I = G();
			int a = Get() - 1, b = Get() - 1, c = Get();
			if (d[a, b] > c)
			{
				s = 0L;
				for (var u = 0; u < V; u++) for (var v = 0; v < u; v++)
					{
						var p = Min(d[u, a] + c + d[b, v], d[u, b] + c + d[a, v]);
						if (d[u, v] > p) d[v, u] = d[u, v] = p;
						s += d[u, v];
					}
			}
			ans.AppendLine(s.ToString());
		}
		Console.Write(ans);
	}
	int Get()
	{
		var n = 0;
		while (true)
		{
			var c = Console.In.Read() - '0';
			if (0 <= c && c < 10) n = 10 * n + c;
			else return n;
		}
	}
}