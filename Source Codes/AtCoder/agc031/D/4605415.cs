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
	int F => int.Parse(Str);
	long FL => long.Parse(Str);
	int[] G => Strs.Select(int.Parse).ToArray();
	decimal[] GD => Strs.Select(decimal.Parse).ToArray();
	long[] GL => Strs.Select(long.Parse).ToArray();
	string Str => ReadLine();
	string[] Strs => Str.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
	static T[] ConstantArray<T>(int n, T val) { var a = new T[n]; for (var i = 0; i < n; i++) a[i] = val; return a; }
	static T[] MakeArray<T>(int n, Func<int, T> f) { var a = new T[n]; for (var i = 0; i < n; i++) a[i] = f(i); return a; }
	const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	int N;
	void Solve()
	{
		var I = G;
		N = I[0];
		var K = I[1];
		var p = G;
		var q = G;
		for (var i = 0; i < N; i++) { p[i]--; q[i]--; }
		WriteLine(string.Join(" ", Calc(p, q, K).Select(i => i + 1)));
	}
	int[] Calc(int[] p, int[] q, int K)
	{
		if (K == 1) return p;
		if (K == 2) return q;
		if (K < 10) return Calc(q, Mult(q, Inv(p)), K - 1);
		K--;
		var ip = Inv(p);
		var iq = Inv(q);
		var x = Mult(q, ip, iq, p);
		var y = Mult(ip, q, p, iq);
		if (K % 6 == 0)
		{
			// 12
			// q.ip.iq.p.q.ip.iq.p.q.p.iq.ip.q.p.iq
			// x        .x        .q.p.iq.y
			// 18
			// q.ip.iq.p.q.ip.iq.p.q.ip.iq.p.q.p.iq.ip.q.p.iq.ip.q.p.iq
			// x      .x          .x        .q.p.iq.y        .y
			return Mult(Pow(x, K / 6), q, p, iq, Pow(y, K / 6 - 1));
		}
		if (K % 6 == 1)
		{
			// q.ip.iq.p.q.ip.iq.p.q.ip.q.p.iq.ip.q.p.iq
			// x        .x        .q.y        .y
			return Mult(Pow(x, K / 6), q, Pow(y, K / 6));
		}
		if (K % 6 == 2)
		{
			// q.ip
			// q.ip
			return Mult(Pow(x, K / 6), q, ip, Pow(y, K / 6));
		}
		if (K % 6 == 3)
		{
			// q.ip.iq
			// q.ip.iq
			return Mult(Pow(x, K / 6), q, ip, iq, Pow(y, K / 6));
		}
		if (K % 6 == 4)
		{
			// iq
			// iq
			return Mult(Pow(x, K / 6 + 1), iq, Pow(y, K / 6));
		}
		else
		{
			// p.iq
			// p.iq
			return Mult(Pow(x, K / 6 + 1), p, iq, Pow(y, K / 6));
		}
	}
	int[] Pow(int[] a, int b)
	{
		var p = MakeArray(N, i => i);
		var x = a;
		while (b > 0)
		{
			if ((b & 1) == 1) p = Mult(p, x);
			b >>= 1;
			x = Mult(x, x);
		}
		return p;
	}
	int[] Inv(int[] a)
	{
		var c = new int[N];
		for (var i = 0; i < N; i++) c[a[i]] = i;
		return c;
	}
	int[] Mult(params int[][] a)
	{
		if (a.Length == 0) return MakeArray(N, i => i);
		var x = a[0];
		for (var i = 1; i < a.Length; i++) x = Mult(x, a[i]);
		return x;
	}
	int[] Mult(int[] a, int[] b)
	{
		var c = new int[N];
		for (var i = 0; i < N; i++) c[i] = a[b[i]];
		return c;
	}
}