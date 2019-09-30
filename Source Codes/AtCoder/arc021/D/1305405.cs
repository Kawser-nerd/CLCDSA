using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;
using System.Numerics;
using static System.Math;
using static System.Console;
struct Edge : IComparable<Edge>
{
	public int From, To;
	public double Cost;
	public Edge(int f, int t, double c)
	{
		From = f;
		To = t;
		Cost = c;
	}
	public int CompareTo(Edge other) => Cost.CompareTo(other.Cost);
}
struct Bits
{
	// 64 * 4 = 256 bits
	public ulong[] b;
	public Bits(params ulong[] c)
	{
		b = new ulong[4];
		for (var i = 0; i < Min(c.Length, 4); i++) b[i] = c[i];
	}
	public void Add(int n)
	{
		if (n < 256) b[n / 64] |= 1uL << (n % 64);
	}
	public int Count {
		get
		{
			var s = 0;
			foreach (var n in b) s += BitCount(n);
			return s;
		}
	}
	public int Distance(Bits x)
	{
		var s = 0;
		for (var i = 0; i < 4; i++) s += BitCount(b[i] ^ x.b[i]);
		return s;
	}
	public static Bits operator^(Bits a, Bits b)
	{
		var c = new Bits();
		c.b = new ulong[4];
		for (var i = 0; i < 4; i++) c.b[i] = a.b[i] ^ b.b[i];
		return c;
	}
	static Bits[] ones;
	static Bits()
	{
		ones = new Bits[256];
		for (var i = 0; i < 4; i++) for (var j = 0; j < 64; j++)
			{
				var k = 64 * i + j;
				ones[k] = new Bits();
				ones[k].b = new ulong[4];
				ones[k].b[i] = 1uL << j;
			}
	}
	static int BitCount(ulong n)
	{
		n = (n & 0x5555555555555555) + ((n >> 1) & 0x5555555555555555);
		n = (n & 0x3333333333333333) + ((n >> 2) & 0x3333333333333333);
		n = (n & 0x0f0f0f0f0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f0f0f0f0f);
		n = (n & 0x00ff00ff00ff00ff) + ((n >> 8) & 0x00ff00ff00ff00ff);
		n = (n & 0x0000ffff0000ffff) + ((n >> 16) & 0x0000ffff0000ffff);
		return (int)((n & 0x00000000ffffffff) + ((n >> 32) & 0x00000000ffffffff));
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
	int N = 5000;
	int D = 200;
	double[,] ps;
	Bits[] hash;
	void Solve()
	{
		var x = F();
		ps = new double[N, D];
		hash = new Bits[N];
		//var start = DateTime.Now;
		Generate((uint)x);
		var es = new List<Edge>();
		for (var i = 0; i < N; i++) for (var j = i + 1; j < N; j++) if (hash[i].Distance(hash[j]) < 94) es.Add(new Edge(i, j, Cost(i, j)));
		es.Sort();
		var uf = new UnionFindTree(5000);
		var cost = 0.0;
		var k = 0;
		foreach (var e in es)
		{
			if (!uf.IsSameCategory(e.From, e.To))
			{
				cost += e.Cost;
				uf.UniteCategory(e.From, e.To);
				Console.WriteLine("{0} {1}", e.From + 1, e.To + 1);
				if (++k == N - 1) break;
			}
		}
		//for (var i = 1; i < N; i++) if (!uf.IsSameCategory(0, i)) throw new Exception();
		//Console.WriteLine(cost);
		//var end = DateTime.Now;
		//Console.WriteLine("{0}", (end - start).TotalSeconds);
	}
	double Cost(int i, int j)
	{
		var s = 0.0;
		for (var d = 0; d < D; d++) s += ps[i, d] * ps[j, d];
		return 1 - s;
	}
	void Generate(uint seed)
	{
		uint x = 123456789, y = 362436069, z = 521288629, w = seed;
		for (var i = 0; i < N; i++)
		{
			hash[i] = new Bits(0);
			var len = 0.0;
			for (var j = 0; j < D; j++)
			{
				var t = x ^ (x << 11);
				x = y;
				y = z;
				z = w;
				w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
				var v = (int)(w % 100000) - 50000;
				if (v >= 0)
				{
					v = v + 1;
					hash[i].Add(j);
				}
				ps[i, j] = v;
				len += Pow(v, 2);
			}
			len = Sqrt(len);
			for (var j = 0; j < D; j++) ps[i, j] /= len;
		}
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