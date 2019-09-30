using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;
using System.Numerics;
using static System.Math;
using static System.Console;
public static class Board
{
	static uint[] line;
	static uint[] mask = new uint[]{ 0x55555555, 0, 0xaaaaaaaa };
	static Board()
	{
		var tmp = new List<uint>{ OneAt(0) | OneAt(4) | OneAt(8), OneAt(2) | OneAt(4) | OneAt(6) };
		var z = new[]{ OneAt(0) | OneAt(1) | OneAt(2), OneAt(0) | OneAt(3) | OneAt(6) };
		for (var i = 0; i < 3; i++) foreach (var x in z) tmp.Add(x << (2 * i));
		line = tmp.ToArray();
	}
	public static uint EmptyBoard() => 0;
	// 1 => ??, 0 => ??, -1 => ??
	static int[] dict = new[]{ 0, 1, -1 };
	public static int At(this uint s, int p) => dict[(s & (3 << (2 * p))) >> (2 * p)];
	public static int At(this uint s, int x, int y) => s.At(3 * x + y);
	public static uint Put(this uint s, int p) => s | OneAt(p);
	public static uint Put(this uint s, int x, int y) => s.Put(3 * x + y);
	static uint OneAt(int x, int y) => OneAt(3 * x + y);
	static uint OneAt(int p) => 1u << (2 * p);
	public static int Count(this uint s, int p) => BitCount(s & mask[1 - p]);
	public static int Win(this uint s)
	{
		var f = 0u;
		foreach (var l in line) f |= s & l;
		var t = 0u;
		foreach (var l in line) t |= s & (l << 1);
		return f != 0 ? 1 : s != 0 ? -1 : 0;
	}
	public static int BitCount(uint n)
	{
		n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
		n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
		n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
		n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
		return (int)((n & 0x0000ffff) + ((n >> 16) & 0x0000ffff));
	}
}
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
		int X = I[0], Y = I[1], N = F();
		var dp = new int[X + 1, X + Y + 1];
		for (var i = 0; i < N; i++)
		{
			I = G();
			int w = I[0], v = I[1];
			for (var n = Min(X, i + 1); n >= 1; n--) for (var t = X + Y; t >= w; t--) dp[n, t] = Max(dp[n, t], dp[n - 1, t - w] + v);
		}
		var ans = 0;
		for (var x = 0; x <= X; x++) for (var y = 0; y <= X + Y; y++) ans = Max(ans, dp[x, y]);
		Console.WriteLine(ans);
	}
	long FirstBinary(long min, long max, Predicate<long> pred)
	{
		while (min < max)
		{
			var mid = min + (max - min) / 2;
			if (pred(mid)) max = mid;
			else min = mid + 1;
		}
		return min;
	}
	long GCD(long a, long b)
	{
		var n = (ulong)Math.Abs(a); var m = (ulong)Math.Abs(b);
		if (n == 0) return (long)m; if (m == 0) return (long)n;
		int zm = 0, zn = 0;
		while ((n & 1) == 0) { n >>= 1; zn++; }
		while ((m & 1) == 0) { m >>= 1; zm++; }
		while (m != n)
		{
			if (m > n) { m -= n; while ((m & 1) == 0) m >>= 1; }
			else { n -= m; while ((n & 1) == 0) n >>= 1; }
		}
		return (long)n << Math.Min(zm, zn);
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
	Tuple<long, long> SolveLinear(long n, long m)
	{
		if (n < 0) { var p = SolveLinear(-n, m); return p == null ? p : new Tuple<long, long>(-p.Item1, p.Item2); }
		if (m < 0) { var p = SolveLinear(n, -m); return p == null ? p : new Tuple<long, long>(p.Item1, -p.Item2); }
		if (n < m) { var p = SolveLinear(m, n); return p == null ? p : new Tuple<long, long>(p.Item2, p.Item1); }
		long a = 1, b = 0, c = 0, d = 1;
		while (m > 0)
		{
			var r = n % m;
			var q = n / m;
			n = m;
			m = r;
			var tmp = a;
			a = -a * q + b;
			b = tmp;
			tmp = c;
			c = -c * q + d;
			d = tmp;
		}
		return n != 1 ? null : new Tuple<long, long>(d, b);
	}
	long Inverse(long a, long mod)
	{
		if (a < 0) { a %= mod; if (a < 0) a += mod; }
		var t = SolveLinear(a, mod);
		return t.Item1 > 0 ? t.Item1 : t.Item1 + mod;
	}
}
class Deque<T>
{
	T[] array;
	int offset, capacity;
	public int Count { get; protected set; }
	public Deque(int capacity) { array = new T[this.capacity = capacity]; Count = 0; offset = 0; }
	public Deque() : this(16) { }
	public T this[int index] { get { return array[GetIndex(index)]; } set { array[GetIndex(index)] = value; } }
	int GetIndex(int index) { var tmp = index + offset; return tmp >= capacity ? tmp - capacity : tmp; }
	public T PeekFront() => array[offset];
	public T PeekBack() => array[GetIndex(Count - 1)];
	public void PushFront(T item)
	{
		if (Count == capacity) Extend();
		if (--offset < 0) offset += array.Length;
		array[offset] = item;
		Count++;
	}
	public T PopFront()
	{
		Count--;
		var tmp = array[offset++];
		if (offset >= capacity) offset -= capacity;
		return tmp;
	}
	public void PushBack(T item)
	{
		if (Count == capacity) Extend();
		var id = (Count++) + offset;
		if (id >= capacity) id -= capacity;
		array[id] = item;
	}
	public T PopBack() => array[GetIndex(--Count)];
	public void Insert(int index, T item)
	{
		PushFront(item);
		for (var i = 0; i < index; i++) this[i] = this[i + 1];
		this[index] = item;
	}
	public T RemoveAt(int index)
	{
		var tmp = this[index];
		for (var i = index; i > 0; i--) this[i] = this[i - 1];
		PopFront();
		return tmp;
	}
	void Extend()
	{
		var newArray = new T[capacity << 1];
		if (offset > capacity - Count)
		{
			var length = array.Length - offset;
			Array.Copy(array, offset, newArray, 0, length);
			Array.Copy(array, 0, newArray, length, Count - length);
		}
		else Array.Copy(array, offset, newArray, 0, Count);
		array = newArray;
		offset = 0;
		capacity <<= 1;
	}
}
class PriorityQueue<T>
{
	Comparison<T> comp;
	List<T> list = new List<T>();
	public int Count;
	public PriorityQueue(Comparison<T> c, IEnumerable<T> source = null)
	{
		comp = c;
		if (source != null) foreach (var x in source) Enqueue(x);
	}
	public void Enqueue(T x)
	{
		var pos = Count++;
		list.Add(x);
		while (pos > 0)
		{
			var p = (pos - 1) / 2;
			if (comp(list[p], x) <= 0) break;
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
			if (b < Count && comp(list[b], list[a]) < 0) a = b;
			if (comp(list[a], x) >= 0) break;
			list[pos] = list[a];
			pos = a;
		}
		list[pos] = x;
		return value;
	}
	public T Peek() => list[0];
	public bool IsEmpty => Count == 0;
}
class UnionFindTree
{
	int N;
	int[] parent, rank;
	public UnionFindTree(int capacity)
	{
		N = capacity;
		parent = new int[N];
		rank = new int[N];
		for (var i = 0; i < N; i++) parent[i] = i;
	}
	public int GetRootOf(int x) => parent[x] == x ? x : parent[x] = GetRootOf(parent[x]);
	public bool UniteCategory(int x, int y)
	{
		if ((x = GetRootOf(x)) == (y = GetRootOf(y))) return false;
		if (rank[x] < rank[y]) parent[x] = y;
		else
		{
			parent[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
		return true;
	}
	public bool IsSameCategory(int x, int y) => GetRootOf(x) == GetRootOf(y);
}
/*struct Edge : IComparable<Edge>
{
	public int To;
	public long Cost;
	public Edge(int t, long c = 0)
	{
		To = t;
		Cost = c;
	}
	public int CompareTo(Edge e) => Cost.CompareTo(e.Cost);
}
class PriorityQueue2
{
	List<Edge> list = new List<Edge>();
	public int Count;
	public void Enqueue(Edge x)
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
	public Edge Dequeue()
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
	public Edge Peek() => list[0];
	public bool IsEmpty => Count == 0;
}*/