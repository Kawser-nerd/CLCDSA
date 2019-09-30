using System.Collections.Generic;
using System.Linq;
using static System.Console;
class K
{
	static int[] G => ReadLine().Split().Select(i => int.Parse(i) - 1).ToArray();
	static int N;
	static void Main()
	{
		var I = G;
		N = I[0] + 1;
		WriteLine(ToString(Calc(G, G, I[1])));
	}
	static string ToString(int[] p) => string.Join(" ", p.Select(i => i + 1));
	static int[] Calc(int[] p, int[] q, int K)
	{
		int[] P = Inv(p), Q = Inv(q), x = Pow(Mult(q, P, Q, p), K / 6), y = Inv(x);
		switch (K % 6)
		{
			case 0: return Mult(x, p, y);
			case 1: return Mult(x, q, y);
			case 2: return Mult(x, q, P, y);
			case 3: return Mult(x, q, P, Q, y);
			case 4: return Mult(x, q, P, Q, p, Q, y);
			default: return Mult(x, q, P, Q, p, p, Q, y);
		}
	}
	static int[] Inv(int[] a)
	{
		var c = new int[N];
		for (var i = 0; i < N; i++) c[a[i]] = i;
		return c;
	}
	static int[] Mult(int[] a, int[] b) { var p = new int[N]; for (var i = 0; i < N; i++) p[i] = a[b[i]]; return p; }
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