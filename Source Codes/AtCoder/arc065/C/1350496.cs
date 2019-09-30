using System.Collections.Generic;
using System.Linq;
using System;
using static System.Math;
using static System.Console;
class E { static void Main() => new K(); }
class K
{
	int[] G() => ReadLine().Split().Select(int.Parse).ToArray();
	readonly SortedSet<int> s = new SortedSet<int>();
	readonly Tree p = new Tree(), q = new Tree();
	readonly Stack<int> st = new Stack<int>();
	Point[] z, w;
	long D, n;
	public K()
	{
		var I = G();
		int N = I[0], a = I[1] - 1, b = I[2] - 1;
		z = new Point[N];
		w = new Point[N];
		for (var i = 0; i < N; i++)
		{
			I = G();
			int x = I[0] + I[1], y = I[0] - I[1];
			p.Add(z[i] = new Point(x, y, i));
			q.Add(w[i] = new Point(y, x, i));
		}
		D = z[a].Distance(z[b]);
		DFS(a);
		var P = new List<Point>();
		var Q = new List<Point>();
		foreach (var x in s) P.Add(z[x]);
		foreach (var x in s) Q.Add(w[x]);
		P.Sort();
		Q.Sort();
		foreach (var u in P)
		{
			G(new Point(u.X - D, u.Y - D), new Point(u.X - D, u.Y + D + 1), P);
			G(new Point(u.X + D, u.Y - D), new Point(u.X + D, u.Y + D + 1), P);
			G(new Point(u.Y - D, u.X - D + 1), new Point(u.Y - D, u.X + D), Q);
			G(new Point(u.Y + D, u.X - D + 1), new Point(u.Y + D, u.X + D), Q);
		}
		WriteLine(n / 2);
	}
	void G(Point f, Point t, List<Point> p) => n += FirstBinary(0, p.Count, i => p[i].CompareTo(t) >= 0) - FirstBinary(0, p.Count, i => p[i].CompareTo(f) >= 0);
	void F(Point f, Point t, Tree p, Tree q)
	{
		while (true)
		{
			var l = p.LowerBound(f);
			if (l == null || l.Item.CompareTo(t) > 0) break;
			if (!s.Contains(l.Item.I)) st.Push(l.Item.I);
			q.Remove(new Point(l.Item.Y, l.Item.X));
			p.Remove(l);
		}
	}
	void DFS(int a)
	{
		st.Push(a);
		while (st.Count > 0)
		{
			var i = st.Pop();
			if (!s.Add(i)) return;
			var u = z[i];
			p.Remove(u);
			q.Remove(w[i]);
			F(new Point(u.X - D, u.Y - D), new Point(u.X - D, u.Y + D), p, q);
			F(new Point(u.X + D, u.Y - D), new Point(u.X + D, u.Y + D), p, q);
			F(new Point(u.Y - D, u.X - D), new Point(u.Y - D, u.X + D), q, p);
			F(new Point(u.Y + D, u.X - D), new Point(u.Y + D, u.X + D), q, p);
		}
	}
	int FirstBinary(int l, int r, Predicate<int> p)
	{
		while (l < r)
		{
			var m = (l + r) / 2;
			if (p(m)) r = m;
			else l = m + 1;
		}
		return l;
	}
}
struct Point : IComparable<Point>
{
	public int I;
	public long X, Y;
	public Point(long x, long y, int i = -1)
	{
		I = i;
		X = x;
		Y = y;
	}
	public int CompareTo(Point t)
	{
		var c = X.CompareTo(t.X);
		return c == 0 ? Y.CompareTo(t.Y) : c;
	}
	public long Distance(Point t) => Max(Abs(X - t.X), Abs(Y - t.Y));
}
class Tree
{
	public class Node
	{
		readonly Tree tree;
		int h;
		public int Height => h;
		public int Bias => Left.h - Right.h;
		public Point Item;
		public Node Parent, Left, Right;
		Node(Point x, Tree t) { tree = t; Item = x; Left = tree.Null; Right = tree.Null; }
		public Node(Tree t) : this(new Point(0, 0), t) { h = 0; }
		public Node(Point x, Node p, Tree t) : this(x, t) { h = 1; Parent = p; }
		public void Adjust() => h = 1 + Math.Max(Left.h, Right.h);
		public void ResetAsSentinel() { h = 0; Left = tree.Null; Right = tree.Null; }
	}
	public readonly Node Null;
	public Tree()
	{
		Null = new Node(this);
		Null.ResetAsSentinel();
	}
	void Replace(Node u, Node v)
	{
		var parent = u.Parent;
		if (parent.Left == u) parent.Left = v;
		else parent.Right = v;
		v.Parent = parent;
	}
	Node RotateL(Node v)
	{
		var u = v.Right;
		Replace(v, u);
		v.Right = u.Left;
		u.Left.Parent = v;
		u.Left = v;
		v.Parent = u;
		v.Adjust();
		u.Adjust();
		return u;
	}
	Node RotateR(Node u)
	{
		var v = u.Left;
		Replace(u, v);
		u.Left = v.Right;
		v.Right.Parent = u;
		v.Right = u;
		u.Parent = v;
		u.Adjust();
		v.Adjust();
		return v;
	}
	Node RotateLR(Node t) { RotateL(t.Left); return RotateR(t); }
	Node RotateRL(Node t) { RotateR(t.Right); return RotateL(t); }
	void Adjust(bool ins, Node n)
	{
		while (n.Parent != Null)
		{
			var p = n.Parent;
			var h = p.Height;
			if ((p.Left == n) == ins)
				if (p.Bias == 2)
					if (p.Left.Bias >= 0) p = RotateR(p);
					else p = RotateLR(p);
				else p.Adjust();
			else
				if (p.Bias == -2)
					if (p.Right.Bias <= 0) p = RotateL(p);
					else p = RotateRL(p);
				else p.Adjust();
			if (h == p.Height) break;
			n = p;
		}
	}
	public Node Add(Point x)
	{
		var p = Null;
		var n = Null.Left;
		var left = true;
		while (n != Null)
			if (x.CompareTo(n.Item) < 0) { p = n; n = n.Left; left = true; }
			else { p = n; n = n.Right; left = false; }
		var ret = new Node(x, p, this);
		if (left)
		{
			p.Left = ret;
			Adjust(true, p.Left);
		}
		else
		{
			p.Right = ret;
			Adjust(true, p.Right);
		}
		return ret;
	}
	public bool Remove(Point x, Node p) => Remove(Find(x, p));
	public bool Remove(Point x) => Remove(x, Null.Left);
	public bool Remove(Node n)
	{
		if (n == null) return false;
		if (n.Left == Null)
		{
			Replace(n, n.Right);
			Adjust(false, n.Right);
		}
		else
		{
			var m = Max(n.Left);
			n.Item = m.Item;
			Replace(m, m.Left);
			Adjust(false, m.Left);
		}
		return true;
	}
	Node Max(Node n)
	{
		while (n.Right != Null) n = n.Right;
		return n;
	}
	public Node Find(Point x, Node p)
	{
		while (p != Null)
		{
			if (x.CompareTo(p.Item) < 0) p = p.Left;
			else if (x.CompareTo(p.Item) > 0) p = p.Right;
			else return p;
		}
		return null;
	}
	public Node LowerBound(Predicate<Point> p) { Node n; LowerBound(p, Null.Left, out n); return n; }
	public Node LowerBound(Point x) => LowerBound(y => y.CompareTo(x) >= 0);
	bool LowerBound(Predicate<Point> p, Node n, out Node r)
	{
		if (n == Null) { r = null; return false; }
		if (p(n.Item)) { if (!LowerBound(p, n.Left, out r)) r = n; return true; }
		return LowerBound(p, n.Right, out r);
	}
}