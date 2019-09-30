using System.IO;
using System.Linq;
using System;
using static System.Console;
class Z
{
	static int[] G() => ReadLine().Split().Select(int.Parse).ToArray();
	static void Main()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		var I = G();
		int N = I[0], Q = I[1];
		var t = G().ToTree(0, N);
		for (var i = 0; i < Q; i++)
		{
			I = G();
			int a = I[1] - 1, b = I[2];
			if (I[0] == 1) t = t.Span(0, a).Join(t.Span(a, b).Add(I[3])).Join(t.Span(b, N));
			else if (I[0] == 2) t = t.Span(0, a).Join(t.Span(I[3] - 1, I[4])).Join(t.Span(b, N));
			else WriteLine(t.Span(a, b).Sum());
		}
		Out.Flush();
	}
}
class T
{
	public readonly T L, R;
	public readonly long V, S, Lz;
	public readonly int H, C;
	public T(T l, long v, T r, long s, long lz, int h, int c)
	{
		L = l;
		V = v;
		R = r;
		S = s;
		Lz = lz;
		H = h;
		C = c;
	}
	public T(T l, long v, T r, int lz = 0)
	{
		C = 1 + l.Count() + r.Count();
		S = v + l.Sum() + r.Sum();
		Lz = lz;
		var lh = l.Height();
		var rh = r.Height();
		if (lh > rh + 1)
		{
			l = l.Update();
			if (l.L.Height() >= l.R.Height())
			{
				V = l.V;
				L = l.L;
				R = new T(l.R, v, r);
			}
			else
			{
				var lr = l.R.Update();
				V = lr.V;
				L = new T(l.L, l.V, lr.L);
				R = new T(lr.R, v, r);
			}
		}
		else if (rh > lh + 1)
		{
			r = r.Update();
			if (r.R.Height() >= r.L.Height())
			{
				V = r.V;
				L = new T(l, v, r.L);
				R = r.R;
			}
			else
			{
				var rl = r.L.Update();
				V = rl.V;
				L = new T(l, v, rl.L);
				R = new T(rl.R, r.V, r.R);
			}
		}
		else
		{
			L = l;
			R = r;
			V = v;
		}
		H = 1 + Math.Max(L.Height(), R.Height());
	}
}
static class Func
{
	public static T ToTree(this int[] x, int l, int r)
	{
		if (l >= r) return null;
		var n = (l + r) / 2;
		return Join(x.ToTree(l, n), x[n], x.ToTree(n + 1, r));
	}
	public static long Sum(this T t) => t == null ? 0 : t.S;
	public static T Add(this T t, long lz) => t == null || lz == 0 ? t : new T(t.L, t.V, t.R, t.S + t.C * lz, t.Lz + lz, t.H, t.C);
	public static T Update(this T t) => t == null || t.Lz == 0 ? t : new T(t.L.Add(t.Lz), t.V + t.Lz, t.R.Add(t.Lz), t.S, 0, t.H, t.C);
	public static int Count(this T t) => t == null ? 0 : t.C;
	public static int Height(this T t) => t == null ? 0 : t.H;
	public static T Join(this T t1, T t2)
	{
		if (t1 == null) return t2;
		if (t2 == null) return t1;
		var c = t1.Count() - 1;
		return Join(t1.Left(c), t1.Right(c).V, t2);
	}
	static T Join(T t1, long x, T t2)
	{
		var h1 = t1.Height();
		var h2 = t2.Height();
		if (Math.Abs(h1 - h2) <= 1) return new T(t1, x, t2);
		if (h1 > h2)
		{
			t1 = t1.Update();
			return new T(t1.L, t1.V, Join(t1.R, x, t2));
		}
		t2 = t2.Update();
		return new T(Join(t1, x, t2.L), t2.V, t2.R);
	}
	public static T Span(this T t, int l, int r) => t.Left(r).Right(l);
	static T Left(this T t, int r)
	{
		if (t == null || 0 >= r) return null;
		t = t.Update();
		var lc = t.L.Count();
		return r <= lc ? t.L.Left(r) : Join(t.L, t.V, t.R.Left(r - lc - 1));
	}
	static T Right(this T t, int l)
	{
		if (t == null || l >= t.Count()) return null;
		t = t.Update();
		var lc = t.L.Count();
		return lc < l ? t.R.Right(l - lc - 1) : Join(t.L.Right(l), t.V, t.R);
	}
}