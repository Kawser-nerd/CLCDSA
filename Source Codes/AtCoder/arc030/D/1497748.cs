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
class Tree
{
	public readonly Tree L, R;
	public readonly long V, S, Lazy;
	public readonly int H, C;
	public Tree(Tree l, long v, Tree r, long s, long lz, int h, int c)
	{
		L = l;
		V = v;
		R = r;
		S = s;
		Lazy = lz;
		H = h;
		C = c;
	}
	public Tree(Tree l, long v, Tree r, int lz = 0)
	{
		C = 1 + l.Count() + r.Count();
		S = v + l.Sum() + r.Sum();
		Lazy = lz;
		var lh = l.Height();
		var rh = r.Height();
		if (lh > rh + 1)
		{
			l = l.Update();
			if (l.L.Height() >= l.R.Height())
			{
				V = l.V;
				L = l.L;
				R = new Tree(l.R, v, r);
			}
			else
			{
				var lr = l.R.Update();
				V = lr.V;
				L = new Tree(l.L, l.V, lr.L);
				R = new Tree(lr.R, v, r);
			}
		}
		else if (rh > lh + 1)
		{
			r = r.Update();
			if (r.R.Height() >= r.L.Height())
			{
				V = r.V;
				L = new Tree(l, v, r.L);
				R = r.R;
			}
			else
			{
				var rl = r.L.Update();
				V = rl.V;
				L = new Tree(l, v, rl.L);
				R = new Tree(rl.R, r.V, r.R);
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
	public static Tree ToTree(this int[] x, int l, int r)
	{
		if (l >= r) return null;
		var n = (l + r) / 2;
		return Join(x.ToTree(l, n), x[n], x.ToTree(n + 1, r));
	}
	public static long Sum(this Tree t) => t == null ? 0 : t.S;
	public static Tree Add(this Tree t, long lz) => t == null || lz == 0 ? t : new Tree(t.L, t.V, t.R, t.S + t.C * lz, t.Lazy + lz, t.H, t.C);
	public static Tree Update(this Tree t) => t == null || t.Lazy == 0 ? t : new Tree(t.L.Add(t.Lazy), t.V + t.Lazy, t.R.Add(t.Lazy), t.S, 0, t.H, t.C);
	public static int Count(this Tree t) => t == null ? 0 : t.C;
	public static int Height(this Tree t) => t == null ? 0 : t.H;
	public static Tree Join(this Tree t1, Tree t2)
	{
		if (t1 == null) return t2;
		if (t2 == null) return t1;
		var c = t1.Count() - 1;
		return Join(t1.Left(c), t1.Right(c).V, t2);
	}
	static Tree Join(Tree t1, long x, Tree t2)
	{
		var h1 = t1.Height();
		var h2 = t2.Height();
		if (Math.Abs(h1 - h2) <= 1) return new Tree(t1, x, t2);
		if (h1 > h2)
		{
			t1 = t1.Update();
			return new Tree(t1.L, t1.V, Join(t1.R, x, t2));
		}
		t2 = t2.Update();
		return new Tree(Join(t1, x, t2.L), t2.V, t2.R);
	}
	public static Tree Span(this Tree t, int l, int r) => t.Left(r).Right(l);
	static Tree Left(this Tree t, int r)
	{
		if (t == null || 0 >= r) return null;
		t = t.Update();
		var lc = t.L.Count();
		return r <= lc ? t.L.Left(r) : Join(t.L, t.V, t.R.Left(r - lc - 1));
	}
	static Tree Right(this Tree t, int l)
	{
		if (t == null || l >= t.Count()) return null;
		t = t.Update();
		var lc = t.L.Count();
		return lc < l ? t.R.Right(l - lc - 1) : Join(t.L.Right(l), t.V, t.R);
	}
}