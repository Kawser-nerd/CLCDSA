#pragma warning disable
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
using System.Collections;
using static System.Math;
using static System.Console;

class E { static void Main() => new J(); }
class J
{
	const int Mod = 1000000007;
	int F() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var N = F();
		var tofus = new Tofu[N];
		var xor = 0;
		for (var i = 0; i < N; i++)
		{
			tofus[i] = new Tofu(G());
			var M = F();
			for (var j = 0; j < M; j++) tofus[i].Add(G());
			foreach (var h in tofus[i].Count()) xor ^= h;
		}
		WriteLine(xor != 0 ? "WIN" : "LOSE");
	}
	long GCD(long a, long b)
	{
		var n = (ulong)Abs(a); var m = (ulong)Abs(b);
		if (n == 0) return (long)m; if (m == 0) return (long)n;
		int zm = 0, zn = 0;
		while ((n & 1) == 0) { n >>= 1; zn++; }
		while ((m & 1) == 0) { m >>= 1; zm++; }
		while (m != n)
		{
			if (m > n) { m -= n; while ((m & 1) == 0) m >>= 1; }
			else { n -= m; while ((n & 1) == 0) n >>= 1; }
		}
		return (long)n << Min(zm, zn);
	}
}
class Tofu
{
	int X, Y, Z;
	int x1, x2, y1, y2, z1, z2;
	bool empty = true;
	public Tofu(int[] C) : this(C[0], C[1], C[2]) { }
	public Tofu(int x, int y, int z) { X = x; Y = y; Z = z; }
	void Add(int x, int y, int z)
	{
		if (empty)
		{
			x1 = x; x2 = x + 1;
			y1 = y; y2 = y + 1;
			z1 = z; z2 = z + 1;
			empty = false;
		}
		else
		{
			x1 = Min(x1, x);
			y1 = Min(y1, y);
			z1 = Min(z1, z);
			x2 = Max(x2, x + 1);
			y2 = Max(y2, y + 1);
			z2 = Max(z2, z + 1);
		}
	}
	public void Add(int[] c) => Add(c[0], c[1], c[2]);
	public IEnumerable<int> Count()
	{
		if (x1 != 0) yield return x1;
		if (x2 != X) yield return X - x2;
		if (y1 != 0) yield return y1;
		if (y2 != Y) yield return Y - y2;
		if (z1 != 0) yield return z1;
		if (z2 != Z) yield return Z - z2;
	}
}