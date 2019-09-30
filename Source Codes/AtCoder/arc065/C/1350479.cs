//#pragma warning disable
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
	readonly SortedSet<int> s = new SortedSet<int>();
	readonly Tree p = new Tree(), q = new Tree();
	readonly Stack<int> st = new Stack<int>();
	Point[] z, w;
	long D, n;
	void Solve()
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
	int FirstBinary(int min, int max, Predicate<int> pred)
	{
		while (min < max)
		{
			var mid = (min + max) / 2;
			if (pred(mid)) max = mid;
			else min = mid + 1;
		}
		return min;
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
	void Adjust(bool isInsertMode, Node node)
	{
		while (node.Parent != Null)
		{
			var parent = node.Parent;
			var height = parent.Height;
			if ((parent.Left == node) == isInsertMode)
			if (parent.Bias == 2)
			if (parent.Left.Bias >= 0) parent = RotateR(parent);
			else parent = RotateLR(parent);
			else parent.Adjust();
			else
				if (parent.Bias == -2)
				if (parent.Right.Bias <= 0) parent = RotateL(parent);
				else parent = RotateRL(parent);
				else parent.Adjust();
			if (height == parent.Height) break;
			node = parent;
		}
	}
	public Node Add(Point item)
	{
		var parent = Null;
		var pos = Null.Left;
		var isLeft = true;
		while (pos != Null)
			if (item.CompareTo(pos.Item) < 0) { parent = pos; pos = pos.Left; isLeft = true; }
			else { parent = pos; pos = pos.Right; isLeft = false; }
		var ret = new Node(item, parent, this);
		if (isLeft)
		{
			parent.Left = ret;
			Adjust(true, parent.Left);
		}
		else
		{
			parent.Right = ret;
			Adjust(true, parent.Right);
		}
		return ret;
	}
	public bool Remove(Point item, Node start) => Remove(Find(item, start));
	public bool Remove(Point item) => Remove(item, Null.Left);
	public bool Remove(Node pos)
	{
		if (pos == null) return false;
		if (pos.Left == Null)
		{
			Replace(pos, pos.Right);
			Adjust(false, pos.Right);
		}
		else
		{
			var max = Max(pos.Left);
			pos.Item = max.Item;
			Replace(max, max.Left);
			Adjust(false, max.Left);
		}
		return true;
	}
	Node Max(Node node)
	{
		while (node.Right != Null) node = node.Right;
		return node;
	}
	public Node Find(Point item, Node start)
	{
		var pos = start;
		while (pos != Null)
		{
			if (item.CompareTo(pos.Item) < 0) pos = pos.Left;
			else if (item.CompareTo(pos.Item) > 0) pos = pos.Right;
			else return pos;
		}
		return null;
	}
	public Node LowerBound(Predicate<Point> pred) { Node node; LowerBound(pred, Null.Left, out node); return node; }
	public Node LowerBound(Point item) => LowerBound(x => x.CompareTo(item) >= 0);
	bool LowerBound(Predicate<Point> pred, Node node, out Node res)
	{
		if (node == Null) { res = null; return false; }
		if (pred(node.Item)) { if (!LowerBound(pred, node.Left, out res)) res = node; return true; }
		return LowerBound(pred, node.Right, out res);
	}
}