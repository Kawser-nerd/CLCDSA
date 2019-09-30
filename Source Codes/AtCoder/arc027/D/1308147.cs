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
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	const Matrix One = null;
	int X, Y;
	int N;
	int[] h;
	Matrix[] r, jump = new Matrix[10];
	int[,] m;
	void Solve()
	{
		N = F();
		h = G();
		jump[0] = new Matrix();
		for (var i = 1; i < 10; i++) jump[0].a[i, i - 1] = 1;
		jump[0].a[0, 0] = 1;
		for (var i = 1; i < 10; i++)
		{
			jump[i] = +jump[i - 1];
			jump[i].a[0, i] = 1;
		}
		Func<int,int,int> ans;
		X = (int)Sqrt(N / 2);
		if (X < 20) ans = Ans1;
		else
		{
			Y = (X + N - 1) / X;
			m = new int[Y, X];
			r = new Matrix[Y];
			for (var i = 0; i < N; i++) m[i / X, i % X] = h[i];
			Parallel.For(0, Y, i => {
				r[i] = new Matrix();
				for (var k = 0; k < 10; k++)
				{
					var v = new int[10];
					v[k] = 1;
					for (var j = X - 1; j >= 0; j--)
					{
						var s = 0L;
						for (var x = 0; x < m[i, j]; x++) s += v[x];
						for (var x = 9; x >= 1; x--) v[x] = v[x - 1];
						v[0] = (int)(s % MOD);
					}
					for (var x = 0; x < 10; x++) r[i][x, k] = v[x];
				}
			});
			ans = Ans2;
		}
		var Q = F();
		for (var i = 0; i < Q; i++)
		{
			var I = G();
			Console.WriteLine(ans(I[0] - 1, I[1] - 1));
		}
	}
	int Ans1(int s, int t) => Calc(s, t)[0];
	int Ans2(int s, int t) => t - s < 10 ? Ans1(s, t) : Product(s, t-9, Calc(t - 9, t))[0];
	int[] Product(int from, int to, int[] v)
	{
		to--;
		int fi = from / X, fj = from % X, ti = to / X, tj = to % X;
		if (ti == fi) for (var i = to; i >= from; i--) v = jump[m[i / X, i % X] - 1] * v;
		else
		{
			for (var j = tj; j >= 0; j--) v = jump[m[ti, j] - 1] * v;
			for (var i = ti - 1; i > fi; i--) v = r[i] * v;
			for (var j = X - 1; j >= fj; j--) v = jump[m[fi, j] - 1] * v;
		}
		return v;
	}
	int[] Calc(int s, int t)
	{
		var d = t - s;
		var dp = new int[d + 1];
		dp[d] = 1;
		for (var j = d - 1; j >= 0; j--)
		{
			var ub = Min(h[s + j], d - j);
			var sum = 0L;
			for (var k = 1; k <= ub; k++) sum += dp[j + k];
			dp[j] = (int)(sum % MOD);
		}
		return dp;
	}
}
class Matrix
{
	const int MOD = K.MOD;
	public int[,] a = new int[10, 10];
	public int this[int r, int c] { get { return a[r, c]; } set { a[r, c] = value % MOD; } }
	public static Matrix operator +(Matrix p)
	{
		if (p == null) return null;
		var x = new Matrix();
		for (var i = 0; i < 10; i++) for (var j = 0; j < 10; j++) x.a[i, j] = p.a[i, j];
		return x;
	}
	public static Matrix operator *(Matrix p, Matrix q)
	{
		if (p == null) return q;
		if (q == null) return p;
		var x = new Matrix();
		for (var i = 0; i < 10; i++) for (var j = 0; j < 10; j++)
		{
			var sum = 0L;
			for (var k = 0; k < 10; k++) sum += p.a[i, k] * (long)q.a[k, j] % MOD;
			x.a[i, j] = (int)(sum % MOD);
		}
		return x;
	}
	public static int[] operator *(Matrix p, int[] v)
	{
		if (p == null) return v;
		var w = new int[10];
		for (var i = 0; i < 10; i++)
		{
			var sum = 0L;
			for (var j = 0; j < 10; j++) sum +=  p.a[i, j] * (long)v[j] % MOD;
			w[i] = (int)(sum % MOD);
		}
		return w;
	}
	public static Matrix One()
	{
		var m = new Matrix();
		for (var i = 0; i < 10; i++) m.a[i, i] = 1;
		return m;
	}
}