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
using static Func;
class Z { static void Main() => new K(); }
class K
{
	int F => int.Parse(Str);
	long FL => long.Parse(Str);
	int[] G => Strs.Select(int.Parse).ToArray();
	long[] GL => Strs.Select(long.Parse).ToArray();
	string Str => ReadLine();
	string[] Strs => Str.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
	const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	long[] inv, fact, ifact;
	void Solve()
	{
		var I = G;
		int N = I[0], M = I[1];
		var LIM = N + 100;
		inv = new long[LIM];
		fact = new long[LIM];
		ifact = new long[LIM];
		fact[0] = ifact[0] = 1;
		for (var i = 1; i < LIM; i++)
		{
			inv[i] = Func.Inverse(i, MOD);
			fact[i] = fact[i - 1] * i % MOD;
			ifact[i] = ifact[i - 1] * inv[i] % MOD;
		}
		var f = Func.Factorize(M);
		var ans = 1L;
		foreach (var t in f.Values) ans = ans * Comb(t + N - 1, t) % MOD;
		WriteLine(ans);
	}
	long Comb(int n, int m) => fact[n] * ifact[m] % MOD * ifact[n - m] % MOD;
}
static class Func
{
	public static Dictionary<long, int> Factorize(this long n)
	{
		var d = new Dictionary<long, int>();
		for (var i = 2L; i * i <= n; i++)
			if (n % i == 0)
			{
				d.Add(i, 0);
				while (n % i == 0) { n /= i; d[i]++; }
			}
		if (n > 1) d.Add(n, 1);
		return d;
	}
	public static long Inverse(this long a, long mod)
	{
		if (a < 0) { a %= mod; if (a < 0) a += mod; }
		var t = SolveLinear(a, mod);
		return t.Item1 > 0 ? t.Item1 : t.Item1 + mod;
	}
	public static Tuple<long, long> SolveLinear(long n, long m)
	{
		if (n < 0) { var p = SolveLinear(-n, m); return p == null ? p : new Tuple<long, long>(-p.Item1, p.Item2); }
		if (m < 0) { var p = SolveLinear(n, -m); return p == null ? p : new Tuple<long, long>(p.Item1, -p.Item2); }
		if (n < m) { var p = SolveLinear(m, n); return p == null ? p : new Tuple<long, long>(p.Item2, p.Item1); }
		long a = 1, b = 0, c = 0, d = 1;
		while (m > 0)
		{
			var r = n % m;
			var q = n / m;
			n = m;
			m = r;
			var tmp = a;
			a = -a * q + b;
			b = tmp;
			tmp = c;
			c = -c * q + d;
			d = tmp;
		}
		return n != 1 ? null : new Tuple<long, long>(d, b);
	}
}