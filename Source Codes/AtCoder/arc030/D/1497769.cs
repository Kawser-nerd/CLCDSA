using System.Linq;
using System;
class Z
{
	static int[] G() => Console.ReadLine().Split().Select(int.Parse).ToArray();
	static void Main()
	{
		var I = G();
		int N = I[0], Q = I[1];
		var t = G().Y(0, N);
		for (var i = 0; i < Q; i++)
		{
			I = G();
			int a = I[1] - 1, b = I[2];
			if (I[0] == 1) t = t[0, a].J(t[a, b].P(I[3])).J(t[b, N]);
			else if (I[0] == 2) t = t[0, a].J(t[I[3] - 1, I[4]]).J(t[b, N]);
			else Console.WriteLine(t[a, b].S());
		}
	}
}
class T
{
	public T L, R;
	public long V, S, Q;
	public int H, C;
	public T this[int l, int r] => this.L(r).R(l);
	public T(T l, long v, T r, long s, long q, int h, int c)
	{
		L = l;
		V = v;
		R = r;
		S = s;
		Q = q;
		H = h;
		C = c;
	}
	public T(T l, long v, T r)
	{
		C = 1 + l.C() + r.C();
		S = v + l.S() + r.S();
		var a = l.H();
		var b = r.H();
		if (a > b + 1)
		{
			l = l.U();
			if (l.L.H() >= l.R.H())
			{
				V = l.V;
				L = l.L;
				R = new T(l.R, v, r);
			}
			else
			{
				var x = l.R.U();
				V = x.V;
				L = new T(l.L, l.V, x.L);
				R = new T(x.R, v, r);
			}
		}
		else if (b > a + 1)
		{
			r = r.U();
			if (r.R.H() >= r.L.H())
			{
				V = r.V;
				L = new T(l, v, r.L);
				R = r.R;
			}
			else
			{
				var x = r.L.U();
				V = x.V;
				L = new T(l, v, x.L);
				R = new T(x.R, r.V, r.R);
			}
		}
		else
		{
			L = l;
			R = r;
			V = v;
		}
		H = 1 + Math.Max(L.H(), R.H());
	}
}
static class F
{
	public static T Y(this int[] x, int l, int r)
	{
		if (l >= r) return null;
		var n = (l + r) / 2;
		return J(x.Y(l, n), x[n], x.Y(n + 1, r));
	}
	public static long S(this T t) => t == null ? 0 : t.S;
	public static T P(this T t, long q) => t == null || q == 0 ? t : new T(t.L, t.V, t.R, t.S + t.C * q, t.Q + q, t.H, t.C);
	public static T U(this T t) => t == null || t.Q == 0 ? t : new T(t.L.P(t.Q), t.V + t.Q, t.R.P(t.Q), t.S, 0, t.H, t.C);
	public static int C(this T t) => t == null ? 0 : t.C;
	public static int H(this T t) => t == null ? 0 : t.H;
	public static T J(this T t, T s)
	{
		if (t == null) return s;
		if (s == null) return t;
		var c = t.C() - 1;
		return J(t.L(c), t.R(c).V, s);
	}
	static T J(T t, long x, T s)
	{
		var a = t.H();
		var b = s.H();
		if (Math.Abs(a - b) <= 1) return new T(t, x, s);
		if (a > b)
		{
			t = t.U();
			return new T(t.L, t.V, J(t.R, x, s));
		}
		s = s.U();
		return new T(J(t, x, s.L), s.V, s.R);
	}
	public static T L(this T t, int r)
	{
		if (t == null || 0 >= r) return null;
		t = t.U();
		var c = t.L.C();
		return r <= c ? t.L.L(r) : J(t.L, t.V, t.R.L(r - c - 1));
	}
	public static T R(this T t, int l)
	{
		if (t == null || l >= t.C()) return null;
		t = t.U();
		var c = t.L.C();
		return c < l ? t.R.R(l - c - 1) : J(t.L.R(l), t.V, t.R);
	}
}