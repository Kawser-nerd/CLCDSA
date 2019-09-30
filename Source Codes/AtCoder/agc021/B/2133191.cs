using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using static System.Console;
using static System.Math;
class Z { static void Main() => new K(); }
class K
{
	int F => int.Parse(Str);
	long[] GL => Strs.Select(long.Parse).ToArray();
	string Str => ReadLine();
	string[] Strs => Str.Split();
	public K()
	{
		var N = F;
		var ps = new List<Point>(N);
		for (var i = 0; i < N; i++) ps.Add(new Point(GL));
		var hull = ps.ToList().ConvexHull();
		foreach (var p in ps)
		{
			var ok = false;
			for (var j = 0; j < hull.Count; j++)
			{
				if (hull[j].CompareTo(p) == 0)
				{
					ok = true;
					if (hull.Count == 2) { WriteLine(0.5); break; }
					var prev = j > 0 ? hull[j - 1] : hull[hull.Count - 1];
					var next = j + 1 < hull.Count ? hull[j + 1] : hull[0];
					var z = (hull[j] - prev) / (next - hull[j]);
					WriteLine(Abs(z.Phase) / (2 * PI));
					break;
				}
			}
			if (!ok) WriteLine(0);
		}
	}
}
static class Geometry
{
	public static bool CCW(Point a, Point b, Point c)
	{
		var p = b - a;
		var q = c - a;
		var cross = p % q;
		return cross <= 0 && (cross != 0 || p * q >= 0);
	}
	public static List<Point> ConvexHull(this List<Point> points)
	{
		int n = points.Count, k = 0;
		points.Sort();
		var convex = new Point[2 * n];
		for (var i = 0; i < n; convex[k++] = points[i++]) while (k >= 2 && CCW(convex[k - 2], convex[k - 1], points[i])) --k;
		for (int i = n - 2, t = k + 1; i >= 0; convex[k++] = points[i--]) while (k >= t && CCW(convex[k - 2], convex[k - 1], points[i])) --k;
		return convex.Take(k - 1).ToList();
	}
}
class Point : IComparable<Point>
{
	public readonly long X, Y;
	public Point(long x, long y) { X = x; Y = y; }
	public Point(long[] I) : this(I[0], I[1]) { }
	public static Point operator -(Point p, Point q) => new Point(p.X - q.X, p.Y - q.Y);
	public static long operator *(Point p, Point q) => p.X * q.X + p.Y * q.Y;
	public static long operator %(Point p, Point q) => p.X * q.Y - p.Y * q.X;
	public static explicit operator Complex(Point p) => new Complex(p.X, p.Y);
	public static Complex operator /(Point p, Point q) => (Complex)p / (Complex)q;
	public int CompareTo(Point other) => X == other.X ? Y.CompareTo(other.Y) : X.CompareTo(other.X);
}