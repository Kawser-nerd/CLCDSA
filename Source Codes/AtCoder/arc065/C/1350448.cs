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
	void Solve()
	{
		var I = G();
		int N = I[0], a = I[1] - 1, b = I[2] - 1;
		var all = new Point[N];
		var rev = new Point[N];
		var ps = new Tree();
		var qs = new Tree();
		for (var i = 0; i < N; i++)
		{
			I = G();
			int x = I[0] + I[1], y = I[0] - I[1];
			ps.Add(all[i] = new Point(x, y, i));
			qs.Add(rev[i] = new Point(y, x, i));
		}
		var D = all[a].Distance(all[b]);
		var s = new HashSet<int>();
		var st = new Stack<int>();
		st.Push(a);
		Action<Point, Point, Tree, Tree> f1 = (f, t, p, q) => {
			while (true)
			{
				var l = p.LowerBound(f);
				if (l == null || l.Item.CompareTo(t) > 0) break;
				if (!s.Contains(l.Item.I)) st.Push(l.Item.I);
				q.Remove(new Point(l.Item.Y, l.Item.X));
				p.Remove(l);
			}
		};
		while (st.Count > 0)
		{
			var i = st.Pop();
			if (s.Contains(i)) continue;
			s.Add(i);
			var u = all[i];
			ps.Remove(u);
			qs.Remove(rev[i]);
			f1(new Point(u.X - D, u.Y - D), new Point(u.X - D, u.Y + D), ps, qs);
			f1(new Point(u.X + D, u.Y - D), new Point(u.X + D, u.Y + D), ps, qs);
			f1(new Point(u.Y - D, u.X - D), new Point(u.Y - D, u.X + D), qs, ps);
			f1(new Point(u.Y + D, u.X - D), new Point(u.Y + D, u.X + D), qs, ps);
		}
		var ind = s.ToList();
		ind.Sort();
		var M = ind.Count;
		var px = new List<Point>();
		var qx = new List<Point>();
		foreach (var x in ind) px.Add(all[x]);
		foreach (var x in ind) qx.Add(rev[x]);
		px.Sort();
		qx.Sort();
		var ans = 0L;
		Action<Point, Point, List<Point>> f2 = (f, t, p) => {
			var l = FirstBinary(0, M, i => p[i].CompareTo(f) >= 0);
			var r = FirstBinary(0, M, i => p[i].CompareTo(t) >= 0);
			ans += r - l;
		};
		foreach (var u in px)
		{
			f2(new Point(u.X - D, u.Y - D), new Point(u.X - D, u.Y + D + 1), px);
			f2(new Point(u.X + D, u.Y - D), new Point(u.X + D, u.Y + D + 1), px);
			f2(new Point(u.Y - D, u.X - D + 1), new Point(u.Y - D, u.X + D), qx);
			f2(new Point(u.Y + D, u.X - D + 1), new Point(u.Y + D, u.X + D), qx);
		}
		WriteLine(ans / 2);
	}
	public static int FirstBinary(int min, int max, Predicate<int> pred)
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
	public override string ToString() => $"[{I}]({X}, {Y})";
}
class Tree
{
	public class Node
	{
		readonly Tree tree;
		int height;
		public int Height => height;
		public int Bias => Left.height - Right.height;
		public Point Item;
		public Node Parent, Left, Right;
		Node(Point x, Tree t) { tree = t; Item = x; Left = tree.Sentinel; Right = tree.Sentinel; }
		public Node(Tree t) : this(new Point(-1, -1, -2), t) { height = 0; Parent = null; }
		public Node(Point x, Node p, Tree t) : this(x, t) { height = 1; Parent = p; }
		public void Adjust() => height = 1 + Math.Max(Left.height, Right.height);
		public void ResetAsSentinel() { height = 0; Left = tree.Sentinel; Right = tree.Sentinel; }
		public override string ToString() => Item.ToString();
	}
	public readonly Node Sentinel;
	int count;
	public Tree()
	{
		Sentinel = new Node(this);
		Sentinel.ResetAsSentinel();
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
		while (node.Parent != Sentinel)
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
		var parent = Sentinel;
		var pos = Sentinel.Left;
		var isLeft = true;
		count++;
		while (pos != Sentinel)
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
	public bool Remove(Point item) => Remove(item, Sentinel.Left);
	public bool Remove(Node pos)
	{
		if (pos == null) return false;
		if (pos.Left == Sentinel)
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
		count--;
		return true;
	}
	Node Max(Node node)
	{
		while (node.Right != Sentinel) node = node.Right;
		return node;
	}
	Node Min(Node node)
	{
		while (node.Left != Sentinel) node = node.Left;
		return node;
	}
	public bool Contains(Point item) => Find(item) != null;
	public Node Find(Point item) => Find(item, Sentinel.Left);
	public Node Find(Point item, Node start)
	{
		var pos = start;
		while (pos != Sentinel)
		{
			if (item.CompareTo(pos.Item) < 0) pos = pos.Left;
			else if (item.CompareTo(pos.Item) > 0) pos = pos.Right;
			else return pos;
		}
		return null;
	}
	public Node LowerBound(Predicate<Point> pred) { Node node; LowerBound(pred, Sentinel.Left, out node); return node; }
	public Node UpperBound(Predicate<Point> pred) { Node node; UpperBound(pred, Sentinel.Left, out node); return node; }
	public Node LowerBound(Point item) => LowerBound(x => x.CompareTo(item) >= 0);
	public Node UpperBound(Point item) => UpperBound(x => x.CompareTo(item) <= 0);
	bool UpperBound(Predicate<Point> pred, Node node, out Node res)
	{
		if (node == Sentinel) { res = null; return false; }
		if (pred(node.Item)) { if (!UpperBound(pred, node.Right, out res)) res = node; return true; }
		return UpperBound(pred, node.Left, out res);
	}
	bool LowerBound(Predicate<Point> pred, Node node, out Node res)
	{
		if (node == Sentinel) { res = null; return false; }
		if (pred(node.Item)) { if (!LowerBound(pred, node.Left, out res)) res = node; return true; }
		return LowerBound(pred, node.Right, out res);
	}
	public Node Min() => Min(Sentinel.Left);
	public Node Max() => Max(Sentinel.Left);
}