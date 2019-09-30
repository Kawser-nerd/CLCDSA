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
	static int[] G => ReadLine().Split().Select(int.Parse).ToArray();
	static T[] MakeArray<T>(int n, Func<int, T> f) { var a = new T[n]; for (var i = 0; i < n; i++) a[i] = f(i); return a; }
	static int N;
	public K()
	{
		var I = G;
		N = I[0];
		WriteLine(ToString(Calc(Get(), Get(), I[1] - 1)));
	}
	static int[] Get() => G.Select(i => i - 1).ToArray();
	static string ToString(int[] p) => string.Join(" ", p.Select(i => i + 1));
	static int[] Calc(int[] p, int[] q, int K)
	{
		int[] P = Inv(p), Q = Inv(q), x = Mult(q, P, Q, p), y = Mult(P, q, p, Q);
		switch (K % 6)
		{
			case 0: return Mult(Pow(x, K / 6), q, p, Q, Pow(y, K / 6 - 1));
			case 1: return Mult(Pow(x, K / 6), q, Pow(y, K / 6));
			case 2: return Mult(Pow(x, K / 6), q, P, Pow(y, K / 6));
			case 3: return Mult(Pow(x, K / 6), q, P, Q, Pow(y, K / 6));
			case 4: return Mult(Pow(x, K / 6), q, P, Q, p, Q, Pow(y, K / 6));
			default: return Mult(Pow(x, K / 6), q, P, Q, p, p, Q, Pow(y, K / 6));
		}
	}
	static int[] Inv(int[] a)
	{
		var c = new int[N];
		for (var i = 0; i < N; i++) c[a[i]] = i;
		return c;
	}
	static int[] Mult(int[] a, int[] b) => MakeArray(N, i => a[b[i]]);
	static int[] Mult(params int[][] a) => a.Aggregate(Mult);
	static int[] Pow(int[] a, int b)
	{
		if (b < 0) return Inv(Pow(a, -b));
		var p = new int[N];
		var f = new bool[N];
		for (var i = 0; i < N; i++)
			if (!f[i])
			{
				var l = new List<int>();
				var x = i;
				while (!f[x]) { l.Add(x); f[x] = true; x = a[x]; }
				var C = l.Count;
				for (var j = 0; j < C; j++) p[l[j]] = l[(j + b) % C];
			}
		return p;
	}
}