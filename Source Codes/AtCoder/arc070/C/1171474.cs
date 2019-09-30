#pragma warning disable
using System.Collections.Generic;
using System.Linq;
using System;
using System.Collections;
using static System.Math;

class E { static void Main() => new J(); }
class J
{
	int F() => int.Parse(Console.ReadLine());
	int[] G() => Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	public J()
	{
		var N = F();
		var l = new int[N];
		var d = new int[N];
		for (var i = 0; i <N;i++)
		{
			var I = G();
			l[i] = I[0];
			d[i] = I[1] - I[0];
		}
		var left = new AVLTree<long> { l[0] };
		var right = new AVLTree<long> { l[0] };
		var tl = 0L;
		var tr = 0L;
		var h = 0L;
		for (var i = 1; i < N; i++)
		{
			tl -= d[i];
			tr += d[i - 1];
			var lm = left.MaxNode();
			var rm = right.MinNode();
			if (l[i] <= lm.Item + tl)
			{
				h += Abs(lm.Item + tl - l[i]);
				left.Add(l[i] - tl);
				left.Add(l[i] - tl);
				right.Add(lm.Item + tl - tr);
				left.Remove(lm.Item, lm);
			}
			else if (l[i] >= rm.Item + tr)
			{
				h += Abs(rm.Item + tr - l[i]);
				right.Add(l[i] - tr);
				right.Add(l[i] - tr);
				left.Add(rm.Item + tr - tl);
				right.Remove(rm.Item, rm);
			}
			else
			{
				left.Add(l[i] - tl);
				right.Add(l[i] - tr);
			}
		}
		Console.WriteLine(h);
	}
}
class AVLTree<T> : IEnumerable<T>, ICollection<T>, ICollection, IEnumerable
{
	public static Comparison<T> DefaultComparison<T>() => (x, y) => Comparer<T>.Default.Compare(x, y);
	public static Comparison<T> ToComparison<T>(IComparer<T> comp) => comp == null ? DefaultComparison<T>() : (x, y) => comp.Compare(x, y);
	public class AVLNode : IEnumerable<T>
	{
		AVLTree<T> tree;
		int height;
		public int Height => height;
		public int Bias => Left.height - Right.height;
		public T Item;
		public AVLNode Parent;
		public AVLNode Left;
		public AVLNode Right;
		AVLNode(T x, AVLTree<T> tree) { this.tree = tree; Item = x; Left = tree.sentinel; Right = tree.sentinel; }
		public AVLNode(AVLTree<T> tree) : this(default(T), tree) { height = 0; Parent = null; }
		public AVLNode(T x, AVLNode parent, AVLTree<T> tree) : this(x, tree) { height = 1; Parent = parent; }
		public void Adjust() => height = 1 + Math.Max(Left.height, Right.height);
		public void ResetAsSentinel() { height = 0; Left = tree.sentinel; Right = tree.sentinel; }
		public IEnumerator<T> GetEnumerator()
		{
			if (this != tree.sentinel)
			{
				foreach (var x in Left) yield return x;
				yield return Item;
				foreach (var x in Right) yield return x;
			}
		}
		IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
	}
	AVLNode sentinel;
	Comparison<T> comp;
	Func<T, T, bool> equals;
	int count;
	// assumed to be comparer
	// i.e. comp(x,x)=0, and comp(x,y)>0 then comp(y,x)<0, and comp(x,y)>0 & comp(y,z)>0 then comp(x,z)>0
	public AVLTree(Comparison<T> comp)
	{
		sentinel = new AVLNode(this);
		sentinel.ResetAsSentinel();
		this.comp = comp ?? DefaultComparison<T>();
		if (typeof(T).IsValueType) equals = (x, y) => x.Equals(y);
		else equals = (x, y) => ReferenceEquals(x, y);
		count = 0;
	}
	public AVLTree(IComparer<T> comp = null) : this(ToComparison(comp)) { }
	void Replace(AVLNode u, AVLNode v)
	{
		var parent = u.Parent;
		if (parent.Left == u) parent.Left = v;
		else parent.Right = v;
		v.Parent = parent;
	}
	AVLNode RotateL(AVLNode v)
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
	AVLNode RotateR(AVLNode u)
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
	AVLNode RotateLR(AVLNode t) { RotateL(t.Left); return RotateR(t); }
	AVLNode RotateRL(AVLNode t) { RotateR(t.Right); return RotateL(t); }
	void Adjust(bool isInsertMode, AVLNode node)
	{
		while (node.Parent != sentinel)
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
	public void Add(T item)
	{
		var parent = sentinel;
		var pos = sentinel.Left;
		var isLeft = true;
		count++;
		while (pos != sentinel)
			if (comp(item, pos.Item) < 0) { parent = pos; pos = pos.Left; isLeft = true; }
			else { parent = pos; pos = pos.Right; isLeft = false; }
		if (isLeft)
		{
			parent.Left = new AVLNode(item, parent, this);
			Adjust(true, parent.Left);
		}
		else
		{
			parent.Right = new AVLNode(item, parent, this);
			Adjust(true, parent.Right);
		}
	}
	// if equals(x,y) holds then !(comp(x,y)<0) and !(comp(x,y)>0) must hold
	// i.e. equals(x,y) -> comp(x,y)=0
	public bool Remove(T item, AVLNode start)
	{
		var pos = start;
		while (pos != sentinel)
		{
			if (comp(item, pos.Item) < 0) pos = pos.Left;
			else if (comp(item, pos.Item) > 0) pos = pos.Right;
			else if (equals(pos.Item, item))
			{
				if (pos.Left == sentinel)
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
			else return Remove(item, pos.Left) || Remove(item, pos.Right);
		}
		return false;
	}
	public bool Remove(T item) => Remove(item, sentinel.Left);
	AVLNode Max(AVLNode node)
	{
		while (node.Right != sentinel) node = node.Right;
		return node;
	}
	AVLNode Min(AVLNode node)
	{
		while (node.Left != sentinel) node = node.Left;
		return node;
	}
	public bool Contains(T item)
	{
		var pos = sentinel.Left;
		while (pos != sentinel)
		{
			if (comp(item, pos.Item) < 0) pos = pos.Left;
			else if (comp(item, pos.Item) > 0) pos = pos.Right;
			else return true;
		}
		return false;
	}
	public T Find(T item)
	{
		var pos = sentinel.Left;
		while (pos != sentinel)
		{
			if (comp(item, pos.Item) < 0) pos = pos.Left;
			else if (comp(item, pos.Item) > 0) pos = pos.Right;
			else return pos.Item;
		}
		return default(T);
	}
	public AVLNode LowerBound(Predicate<T> pred) { AVLNode node; LowerBound(pred, sentinel.Left, out node); return node; }
	public AVLNode UpperBound(Predicate<T> pred) { AVLNode node; UpperBound(pred, sentinel.Left, out node); return node; }
	public AVLNode LowerBound(T item) => LowerBound(x => comp(x, item) >= 0);
	public AVLNode UpperBound(T item) => UpperBound(x => comp(x, item) <= 0);
	bool UpperBound(Predicate<T> pred, AVLNode node, out AVLNode res)
	{
		if (node == sentinel) { res = null; return false; }
		if (pred(node.Item)) { if (!UpperBound(pred, node.Right, out res)) res = node; return true; }
		else return UpperBound(pred, node.Left, out res);
	}
	bool LowerBound(Predicate<T> pred, AVLNode node, out AVLNode res)
	{
		if (node == sentinel) { res = null; return false; }
		if (pred(node.Item)) { if (!LowerBound(pred, node.Left, out res)) res = node; return true; }
		else return LowerBound(pred, node.Right, out res);
	}
	public T Min() => Min(sentinel.Left).Item;
	public AVLNode MinNode() => Min(sentinel.Left);
	public T Max() => Max(sentinel.Left).Item;
	public AVLNode MaxNode() => Max(sentinel.Left);
	public bool IsEmpty => sentinel.Left == sentinel;
	public void Clear() { sentinel.Left = sentinel; count = 0; sentinel.ResetAsSentinel(); }
	public IEnumerator<T> GetEnumerator() => sentinel.Left.GetEnumerator();
	IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
	public void CopyTo(T[] array, int arrayIndex) { foreach (var x in this) array[arrayIndex++] = x; }
	public int Count => count;
	public bool IsReadOnly => true;
	public void CopyTo(Array array, int index) { foreach (var x in this) array.SetValue(x, index++); }
	public bool IsSynchronized => false;
	public object SyncRoot => this;
}