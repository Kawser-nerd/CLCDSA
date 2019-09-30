using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;
using System.Numerics;
using static System.Math;
using static System.Console;

class E { static void Main() => new K(); }
class K
{
	IEnumerable<int> Hoge()
	{
		while (true) yield return 1;
	}
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
	int N, K;
	int[] A, D;
	void Solve()
	{
		K = F();
		N = F();
		//if (N >= 100000) throw new Exception();
		A = new int[N];
		D = new int[N];
		var M = 100L;
		for (var i = 0; i < N; i++)
		{
			var I = G();
			A[i] = I[0];
			D[i] = I[1];
			M = Max(M, A[i] + D[i] * (K - 1L) + 1);
			if (K % 2 == 0) ans = Min(ans, (K / 2) * (2L * A[i] + (K - 1L) * D[i]));
			else ans = Min(ans, K * (A[i] + (K - 1L) / 2 * D[i]));
		}
		//for (var i = 0; i < M; i++) IsOK(i)
		FirstBinary(0, M, IsOK);
		Console.WriteLine(ans);
	}
	long ans = long.MaxValue;
	bool IsOK(long Z)
	{
		var c = 0L;
		var e = 0;
		var k = new int[N];
		for (var i = 0; i < N; i++)
			if (Z >= A[i])
			{
				c += k[i] = (int)Min(K, (Z - A[i] + D[i] - 1) / D[i]);
				if (c > K) c = K + N + 1;
				if ((Z - A[i]) % D[i] == 0) e++;
			}
		if (c < K && K <= c + e)
		{
			var s = Z * (K - c);
			checked
			{
				for (var i = 0; i < N; i++)
				{
					if (s <= ans)
					{
						if (k[i] % 2 == 0) s += (2 * A[i] + D[i] * (k[i] - 1L)) * (k[i] / 2);
						else s += (A[i] + D[i] * ((k[i] - 1L) / 2)) * k[i];
					}
					if (s > ans) break;
				}
			}
			if (s <= ans) ans = Min(ans, s);
		}
		return K <= c + e;
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
	long Pow(long a, long b, long mod)
	{
		var p = 1L;
		var x = a;
		while (b > 0)
		{
			if ((b & 1) == 1) p = (p * x) % mod;
			b >>= 1;
			x = (x * x) % mod;
		}
		return p;
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