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
	void Solve()
	{
		var I = G();
		int V = I[0], E = I[1];
		var a = new bool[V];
		var b = new bool[V];
		for (var i = 0; i < E; i++)
		{
			I = G();
			if (I[0] == 1) a[I[1] - 1] = true;
			if (I[1] == V) b[I[0] - 1] = true;
		}
		var flag = false;
		for (var i = 0; i < V; i++) flag |= a[i] & b[i];
		Console.WriteLine(flag ? "POSSIBLE" : "IMPOSSIBLE");
	}
}