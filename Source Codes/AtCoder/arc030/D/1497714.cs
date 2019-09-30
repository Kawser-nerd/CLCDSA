using System.IO;
using System.Collections.Generic;
using System.Linq;
using System;

class Z
{
	static int[] G()
	{
		return Console.ReadLine().Split().Select(int.Parse).ToArray();
	}
	static void Main()
	{
		Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
		var I = G();
		int N = I[0], Q = I[1];
		var t = G().ConstructTree();
		for (int i = 0; i < Q; i++)
		{
			I = G();
			if (I[0] == 1)
			{
				int a = I[1] - 1, b = I[2], c = I[3];
				var x = t.Span(0, a);
				var y = t.Span(a, b).Add(c);
				var z = t.Span(b, N);
				t = x.Join(y).Join(z);
			}
			else if (I[0] == 2)
			{
				int a = I[1] - 1, b = I[2], c = I[3] - 1, d = I[4];
				var x = t.Span(0, a);
				var y = t.Span(c, d);
				var z = t.Span(b, N);
				t = x.Join(y).Join(z);
			}
			else Console.WriteLine(t.Span(I[1] - 1, I[2]).Sum());
		}
		Console.Out.Flush();
	}
}
class Tree
{
	public readonly Tree L, R;
	public readonly long V, Sum, Lazy;
	public readonly int H, C;
	public Tree(Tree l, long v, Tree r, long s, long lz, int h, int c)
	{
		L = l;
		V = v;
		R = r;
		Sum = s;
		Lazy = lz;
		H = h;
		C = c;
	}
	public Tree(Tree l, long v, Tree r, int lz = 0)
	{
		C = 1 + l.Count() + r.Count();
		Sum = v + l.Sum() + r.Sum();
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
	public static Tree ConstructTree(this IList<int> list)
	{
		return list.ConstructTree(0, list.Count);
	}
	static Tree ConstructTree(this IList<int> list, int l, int r)
	{
		if (l >= r) return null;
		var n = (l + r) / 2;
		return Join(list.ConstructTree(l, n), list[n], list.ConstructTree(n + 1, r));
	}
	public static long Sum(this Tree t)
	{
		return t == null ? 0 : t.Sum;
	}
	public static Tree Add(this Tree t, long lz)
	{
		return t == null || lz == 0 ? t : new Tree(t.L, t.V, t.R, t.Sum + t.C * lz, t.Lazy + lz, t.H, t.C);
	}
	public static Tree Update(this Tree t)
	{
		return t == null || t.Lazy == 0 ? t : new Tree(t.L.Add(t.Lazy), t.V + t.Lazy, t.R.Add(t.Lazy), t.Sum, 0, t.H, t.C);
	}
	public static int Count(this Tree t)
	{
		return t == null ? 0 : t.C;
	}
	public static int Height(this Tree t)
	{
		return t == null ? 0 : t.H;
	}
	public static Tree Join(this Tree t1, Tree t2)
	{
		if (t1 == null) return t2;
		if (t2 == null) return t1;
		var l = t1.Left(t1.Count() - 1);
		var r = t1.Right(t1.Count() - 1).Update();
		return Join(l, r.V, t2);
	}
	public static Tree Join(Tree t1, long x, Tree t2)
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
	public static Tree Span(this Tree t, int l, int r)
	{
		return t.Left(r).Right(l);
	}
	public static Tree Left(this Tree t, int r)
	{
		if (t == null || 0 >= r) return null;
		t = t.Update();
		var lc = t.L.Count();
		return r <= lc ? t.L.Left(r) : Join(t.L, t.V, t.R.Left(r - lc - 1));
	}
	public static Tree Right(this Tree t, int l)
	{
		if (t == null || l >= t.Count()) return null;
		t = t.Update();
		var lc = t.L.Count();
		return lc < l ? t.R.Right(l - lc - 1) : Join(t.L.Right(l), t.V, t.R);
	}
}