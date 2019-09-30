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
		WriteLine(string.Join(" ", C(G, G, I[1]).Select(i => i + 1)));
	}
	static int[] C(int[] p, int[] q, int K)
	{
		int[] P = I(p), Q = I(q), x = E(M(q, P, Q, p), K / 6), y = I(x);
		switch (K % 6)
		{
			case 0: return M(x, p, y);
			case 1: return M(x, q, y);
			case 2: return M(x, q, P, y);
			case 3: return M(x, q, P, Q, y);
			case 4: return M(x, q, P, Q, p, Q, y);
			default: return M(x, q, P, Q, p, p, Q, y);
		}
	}
	static int[] I(int[] a)
	{
		var c = new int[N];
		for (var i = 0; i < N; i++) c[a[i]] = i;
		return c;
	}
	static int[] M(int[] a, int[] b) { var p = new int[N]; for (var i = 0; i < N; i++) p[i] = a[b[i]]; return p; }
	static int[] M(params int[][] a) => a.Aggregate(M);
	static int[] E(int[] a, int b)
	{
		if (b < 0) return I(E(a, -b));
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