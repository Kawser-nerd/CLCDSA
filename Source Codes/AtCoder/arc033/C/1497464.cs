using System.Collections;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System;

class Z
{
	static void Main()
	{
		new K();
	}

}
class K
{
	static int[] G()
	{
		return Console.ReadLine().Split().Select(int.Parse).ToArray();
	}
	public K()
	{
		Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
		var Q = G()[0];
		Tree<int> t = null;
		for (int i = 0; i < Q; i++)
		{
			var I = G();
			if (I[0] == 1) t = t.Add(I[1]);
			else
			{
				var x = t.Element(I[1] - 1).V;
				Console.WriteLine(x);
				t = t.Remove(x);
			}
		}
		Console.Out.Flush();
	}
}
class Tree<T> : IEnumerable<T> where T: IComparable<T>
{
	public readonly Tree<T> L, R;
	public readonly T V;
	public readonly int H, C;
	// l < v < r and |l.h - l.r| <= 2
	public Tree(Tree<T> l, T v, Tree<T> r)
	{
		C = 1 + l.Count() + r.Count();
		var lh = l.Height();
		var rh = r.Height();
		if (lh > rh + 1)
		{
			if (l.L.Height() >= l.R.Height())
			{
				V = l.V;
				L = l.L;
				R = new Tree<T>(l.R, v, r);
			}
			else
			{
				V = l.R.V;
				L = new Tree<T>(l.L, l.V, l.R.L);
				R = new Tree<T>(l.R.R, v, r);
			}
		}
		else if (rh > lh + 1)
		{
			if (r.R.Height() >= r.L.Height())
			{
				V = r.V;
				L = new Tree<T>(l, v, r.L);
				R = r.R;
			}
			else
			{
				V = r.L.V;
				L = new Tree<T>(l, v, r.L.L);
				R = new Tree<T>(r.L.R, r.V, r.R);
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
	public override string ToString()
	{
		return Func.ToString(this);
	}
	public IEnumerator<T> GetEnumerator()
	{
		return (IEnumerator<T>)this.InOrder();
	}
	IEnumerator IEnumerable.GetEnumerator()
	{
		return GetEnumerator();
	}
}
class P<T> : IComparable<P<T>> where T: IComparable<T>
{
	public int I;
	public T V;
	public P(int i, T v)
	{
		I = i;
		V = v;
	}
	public int CompareTo(P<T> p)
	{
		return V.CompareTo(p.V);
	}
}
static class Func
{
	public static Tree<T> ConstructTree<T>(this IList<T> list) where T: IComparable<T>
	{
		return list.ConstructTree(0, list.Count);
	}
	static Tree<T> ConstructTree<T>(this IList<T> list, int l, int r) where T: IComparable<T>
	{
		if (l >= r) return null;
		var n = (l + r) / 2;
		return Join(list.ConstructTree(l, n), list[n], list.ConstructTree(n + 1, r));
	}
	public static List<T> Merge<T>(params List<T>[] ls)where T: IComparable<T>
	{
		var N = ls.Length;
		var ns = new int[N];
		var l = new List<T>(ls.Sum(x => x.Count));
		var pq = new PriorityQueue<P<T>>();
		for (int i = 0; i < N; i++) if (ls[i].Count > 0) pq.Enqueue(new P<T>(i, ls[i][ns[i] = 0]));
		while (pq.Count > 0)
		{
			var x = pq.Dequeue();
			l.Add(x.V);
			var i = x.I;
			if (++ns[i] < ls[i].Count) pq.Enqueue(new P<T>(i, ls[i][ns[i]]));
		}
		return l;
	}
	public static Tree<T> Merge<T>(this Tree<T> t1, Tree<T> t2) where T: IComparable<T>
	{
		if (t1 == null) return t2;
		if (t2 == null) return t1;
		return Merge(t1.ToList(), t2.ToList()).ConstructTree();
	}
	public static string ToString<T>(this Tree<T> t) where T: IComparable<T>
	{
		return t == null ? "[Empty]\n" : ToString(t, 0);
	}
	static string ToString<T>(this Tree<T> t, int depth) where T: IComparable<T>
	{
		if (t == null) return "";
		var sb = new StringBuilder();
		sb.Append(t.L.ToString(depth + 1));
		sb.Append(' ', 2 * depth);
		sb.AppendFormat("{0} - {1} - {2}\n", t.V, t.H, t.C);
		sb.Append(t.R.ToString(depth + 1));
		return sb.ToString();
	}
	public static int Count<T>(this Tree<T> t) where T: IComparable<T>
	{
		return t?.C ?? 0;
	}
	public static int Height<T>(this Tree<T> t) where T: IComparable<T>
	{
		return t?.H ?? 0;
	}
	public static bool Contains<T>(this Tree<T> t, T x) where T: IComparable<T>
	{
		if (t == null) return false;
		switch (t.V.CompareTo(x))
		{
		case 1:
			return t.L.Contains(x);
		case -1:
			return t.R.Contains(x);
		default:
			return true;
		}
	}
	public static Tree<T> Find<T>(this Tree<T> t, T x) where T: IComparable<T>
	{
		if (t == null) return null;
		switch (t.V.CompareTo(x))
		{
		case 1:
			return t.L.Find(x);
		case -1:
			return t.R.Find(x);
		default:
			return t;
		}
	}
	public static Tree<T> Add<T>(this Tree<T> t, T x) where T: IComparable<T>
	{
		if (t == null) return new Tree<T>(null, x, null);
		switch (t.V.CompareTo(x))
		{
		case 1:
			return new Tree<T>(t.L.Add(x), t.V, t.R);
		case 0:
			return t;
		default:
			return new Tree<T>(t.L, t.V, t.R.Add(x));
		}
	}
	public static T Min<T>(this Tree<T> t) where T: IComparable<T>
	{
		if (t == null) return default(T);
		return t.L == null ? t.V : t.L.Min();
	}
	public static T Max<T>(this Tree<T> t) where T: IComparable<T>
	{
		if (t == null) return default(T);
		return t.R == null ? t.V : t.R.Max();
	}
	public static Tree<T> RemoveMin<T>(this Tree<T> t) where T: IComparable<T>
	{
		if (t == null) return null;
		return t.L == null ? t.R : new Tree<T>(t.L.RemoveMin(), t.V, t.R);
	}
	public static Tree<T> RemoveMax<T>(this Tree<T> t) where T: IComparable<T>
	{
		if (t == null) return null;
		return t.R == null ? t.L : new Tree<T>(t.L, t.V, t.R.RemoveMax());
	}
	// t1 < t2
	public static Tree<T> Join<T>(Tree<T> t1, Tree<T> t2) where T: IComparable<T>
	{
		return t1 == null ? t2 : Join(t1.RemoveMax(), t1.Max(), t2);
	}
	// t1 < x < t2
	public static Tree<T> Join<T>(Tree<T> t1, T x, Tree<T> t2) where T: IComparable<T>
	{
		var h1 = t1.Height();
		var h2 = t2.Height();
		if (Math.Abs(h1 - h2) <= 1) return new Tree<T>(t1, x, t2);
		return h1 > h2 ? new Tree<T>(t1.L, t1.V, Join(t1.R, x, t2)) : new Tree<T>(Join(t1, x, t2.L), t2.V, t2.R);
	}
	public static Tree<T> Remove<T>(this Tree<T> t, T x) where T: IComparable<T>
	{
		if (t == null) return t;
		switch (t.V.CompareTo(x))
		{
		case 1:
			return new Tree<T>(t.L.Remove(x), t.V, t.R);
		case 0:
			return Join(t.L, t.R);
		default:
			return new Tree<T>(t.L, t.V, t.R.Remove(x));
		}
	}
	// return { y in t | y < x}
	public static Tree<T> Less<T>(this Tree<T> t, T x) where T: IComparable<T>
	{
		if (t == null) return t;
		switch (t.V.CompareTo(x))
		{
		case 1:
			return t.L.Less(x);
		case 0:
			return t.L;
		default:
			return Join(t.L, t.V, t.R.Less(x));
		}
	}
	// return { y in t | y > x}
	public static Tree<T> Greater<T>(this Tree<T> t, T x) where T: IComparable<T>
	{
		if (t == null) return t;
		switch (t.V.CompareTo(x))
		{
		case 1:
			return Join(t.L.Greater(x), t.V, t.R);
		case 0:
			return t.R;
		default:
			return t.R.Greater(x);
		}
	}
	// return { y in t | y <= x}
	public static Tree<T> LessEq<T>(this Tree<T> t, T x) where T: IComparable<T>
	{
		if (t == null) return t;
		switch (t.V.CompareTo(x))
		{
		case 1:
			return t.L.LessEq(x);
		case 0:
			return t.L.Add(x);
		default:
			return Join(t.L, t.V, t.R.LessEq(x));
		}
	}
	// return { y in t | y >= x}
	public static Tree<T> GreaterEq<T>(this Tree<T> t, T x) where T: IComparable<T>
	{
		if (t == null) return t;
		switch (t.V.CompareTo(x))
		{
		case 1:
			return Join(t.L.GreaterEq(x), t.V, t.R);
		case 0:
			return t.R.Add(x);
		default:
			return t.R.GreaterEq(x);
		}
	}
	public static Tree<T> Span<T>(this Tree<T> t, int l, int r) where T: IComparable<T>
	{
		return t.Left(r).Right(l);
	}
	// [0, r)
	public static Tree<T> Left<T>(this Tree<T> t, int r) where T: IComparable<T>
	{
		if (t == null || 0 >= r) return null;
		var lc = t.L.Count();
		if (r <= lc) return t.L.Left(r);
		return Join(t.L, t.V, t.R.Left(r - lc - 1));
	}
	// [l, c)
	public static Tree<T> Right<T>(this Tree<T> t, int l) where T: IComparable<T>
	{
		if (t == null) return null;
		var lc = t.L.Count();
		if (lc < l) return t.R.Right(l - lc - 1);
		return Join(t.L.Right(l), t.V, t.R);
	}
	public static Tree<T> Element<T>(this Tree<T> t, int n) where T: IComparable<T>
	{
		if (t == null) return null;
		var c = t.L.Count();
		if (n < c) return t.L.Element(n);
		return n == c ? t : t.R.Element(n - c - 1);
	}
	// x ?????
	public static int Rank<T>(this Tree<T> t, T x) where T: IComparable<T>
	{
		if (t == null) return 0;
		switch (t.V.CompareTo(x))
		{
		case 1:
			return t.L.Rank(x);
		case 0:
			return t.L.Count();
		default:
			return 1 + t.L.Count() + t.R.Rank(x);
		}
	}
	public static IEnumerable<T> PreOrder<T>(this Tree<T> t) where T: IComparable<T>
	{
		if (t == null) yield break;
		yield return t.V;
		foreach (var x in PreOrder(t.L)) yield return x;
		foreach (var x in PreOrder(t.R)) yield return x;
	}
	public static IEnumerable<T> InOrder<T>(this Tree<T> t) where T: IComparable<T>
	{
		if (t != null)
		{
			foreach (var x in InOrder(t.L)) yield return x;
			yield return t.V;
			foreach (var x in InOrder(t.R)) yield return x;
		}
	}
	public static IEnumerable<T> PostOrder<T>(this Tree<T> t) where T: IComparable<T>
	{
		if (t == null) yield break;
		foreach (var x in PostOrder(t.L)) yield return x;
		foreach (var x in PostOrder(t.R)) yield return x;
		yield return t.V;
	}
	public static bool Balanced<T>(this Tree<T> t) where T: IComparable<T>
	{
		return t == null || (Math.Abs(t.L.Height() - t.R.Height()) <= 1 && t.L.Balanced() && t.R.Balanced());
	}
	public static bool ValidTree<T>(this Tree<T> t) where T: IComparable<T>
	{
		return t == null || (t.L.InRangeR(t.V) && t.R.InRangeL(t.V));
	}
	// l < t < r ?
	public static bool InRange<T>(this Tree<T> t, T l, T r) where T:IComparable<T>
	{
		return t == null || (t.V.CompareTo(l) > 0 && t.V.CompareTo(r) < 0 && t.L.InRange(l, t.V) && t.R.InRange(t.V, r));
	}
	public static bool InRangeL<T>(this Tree<T> t, T l) where T:IComparable<T>
	{
		return t == null || (t.V.CompareTo(l) > 0 && t.L.InRange(l, t.V) && t.R.InRangeL(t.V));
	}
	public static bool InRangeR<T>(this Tree<T> t, T r) where T:IComparable<T>
	{
		return t == null || (t.V.CompareTo(r) < 0 && t.L.InRangeR(t.V) && t.R.InRange(t.V, r));
	}
	static int BadHeight<T>(this Tree<T> t) where T:IComparable<T>
	{
		return t == null ? 0 : 1 + Math.Max(t.L.BadHeight(), t.R.BadHeight());
	}
	static int BadCount<T>(this Tree<T> t) where T:IComparable<T>
	{
		return t == null ? 0 : 1 + t.L.BadCount() + t.R.BadCount();
	}
	public static bool CheckCH<T>(this Tree<T> t) where T:IComparable<T>
	{
		return t == null || (t.Count() == t.BadCount() && t.Height() == t.BadHeight() && t.L.CheckCH() && t.R.CheckCH());
	}
	public static bool CheckAll<T>(this Tree<T> t) where T:IComparable<T>
	{
		return t.Balanced() && t.ValidTree() && t.CheckCH();
	}
}
class PriorityQueue<T> where T:IComparable<T>
{
	readonly List<T> list = new List<T>();
	public int Count { get; private set; }
	public void Enqueue(T x)
	{
		var pos = Count++;
		list.Add(x);
		while (pos > 0)
		{
			var p = (pos - 1) / 2;
			if (list[p].CompareTo(x) <= 0) break;
			list[pos] = list[p];
			pos = p;
		}
		list[pos] = x;
	}
	public T Dequeue()
	{
		var value = list[0];
		var x = list[--Count];
		list.RemoveAt(Count);
		if (Count == 0) return value;
		var pos = 0;
		while (pos * 2 + 1 < Count)
		{
			var a = 2 * pos + 1;
			var b = 2 * pos + 2;
			if (b < Count && list[b].CompareTo(list[a]) < 0) a = b;
			if (list[a].CompareTo(x) >= 0) break;
			list[pos] = list[a];
			pos = a;
		}
		list[pos] = x;
		return value;
	}
}