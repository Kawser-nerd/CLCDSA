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
	void Solve()
	{
		var N = F;
		var x = new long[N];
		var y = new long[N];
		var ps = new List<Point>();
		for (var i = 0; i < N; i++)
		{
			var I = G;
			x[i] = I[0];
			y[i] = I[1];
			ps.Add(new Point(x[i], y[i]));
		}
		var hull = ps.ToList().ConvexHull();
		for (var i = 0; i < N; i++)
		{
			var ok = false;
			for (var j = 0; j < hull.Count; j++)
			{
				if (hull[j].CompareTo(ps[i]) == 0)
				{
					ok = true;
					if (hull.Count == 2) { WriteLine(0.5); break; }
					var prev = j > 0 ? hull[j - 1] : hull[hull.Count - 1];
					var next = j + 1 < hull.Count ? hull[j + 1] : hull[0];
					var u = hull[j] - prev;
					var v = next - hull[j];
					var zu = new Complex(u.X, u.Y);
					var zv = new Complex(v.X, v.Y);
					var z = zu / zv;
					WriteLine(Abs(z.Phase) / (2 * PI));
					break;
				}
			}
			if (!ok) WriteLine(0);
		}
		// 2(x[i]-x[j])x+2(y[i]-y[j])y=x[i]^2-x[j]^2+y[i]^2-y[j]^2
		// var p = 2 * (x[i] - x[j]);
		// var q = 2 * (y[i] - y[j]);
		// var r = x[i] * x[i] + y[i] * y[i] - x[j] * x[j] - y[j] * y[j];
		// if (p * x[i] + q * y[i] > r) { p *= -1; q *= -1; r *= -1; }
	}
}
// U * x + V * y < R
/*struct Region : IComparable<Region>
{
	public long U, V, R;
	public Region(long u, long v, long r) { U = u; V = v; R = r; }
	public void Flip() { U *= -1; V *= -1; R *= -1; }
	public bool Contains(long x, long y) => U * x + V * y < R;
	public int CompareTo(Region r) => (U * r.V).CompareTo(V * r.U);
}*/
static class Geometry
{
	public static int CCW(Point a, Point b, Point c)
	{
		var p = b - a;
		var q = c - a;
		var cross = p % q;
		if (cross > 0) return +1;       // counter clockwise
		if (cross < 0) return -1;       // clockwise
		if (p * q < 0) return +2;       // c--a--b on line
		if (b * b < c * c) return -2;   // a--b--c on line (or a=b)
		return 0;                       // a--c--b on line (or b=c)
	}
	public static List<Point> ConvexHull(this List<Point> points)
	{
		int n = points.Count, k = 0;
		points.Sort();
		var convex = new List<Point>(2 * n);
		for (var i = 0; i < 2 * n; i++) convex.Add(null);
		for (var i = 0; i < n; convex[k++] = points[i++]) while (k >= 2 && CCW(convex[k - 2], convex[k - 1], points[i]) <= 0) --k;
		for (int i = n - 2, t = k + 1; i >= 0; convex[k++] = points[i--]) while (k >= t && CCW(convex[k - 2], convex[k - 1], points[i]) <= 0) --k;
		convex.RemoveRange(k - 1, convex.Count - k + 1);
		return convex;
	}
}
class Point : IComparable<Point>
{
	public long X, Y;
	public Point(long x, long y) { X = x; Y = y; }
	public double Norm => Sqrt(this * this);
	public static Point operator -(Point p, Point q) => new Point(p.X - q.X, p.Y - q.Y);
	public static Point operator +(Point p, Point q) => new Point(p.X + q.X, p.Y + q.Y);
	public static Point operator *(Point p, long r) => new Point(p.X * r, p.Y * r);
	public static Point operator *(long r, Point p) => p * r;
	public static long operator *(Point p, Point q) => p.X * q.X + p.Y * q.Y;
	// cross product ('%' was chosen because it has a good priority as operator)
	public static long operator %(Point p, Point q) => p.X * q.Y - p.Y * q.X;
	public int CompareTo(Point other) => X == other.X ? Y.CompareTo(other.Y) : X.CompareTo(other.X);
}