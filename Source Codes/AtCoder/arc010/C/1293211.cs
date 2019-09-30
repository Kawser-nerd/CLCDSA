using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;
using System.Numerics;
using static System.Math;
using static System.Console;

class E { static void Main() => new J(); }
class J
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
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var I = G();
		int n = I[0], m = I[1], Y = I[2], Z = I[3];
		var point = new int[26];
		var colors = new int[m];
		var rev = new Dictionary<int,int>();
		for (var i = 0; i < m; i++)
		{
			var tmp = Console.ReadLine().Split();
			var c = tmp[0][0] - 'A';
			point[c] = int.Parse(tmp[1]);
			colors[i] = c;
			rev[c] = i;
		}
		var S = Console.ReadLine().Select(x => x - 'A');
		var all = (1 << m) - 1;
		var dp = new int[m + 1, all + 1];
		for (var c = 0; c <= m; c++) for (var i = 0; i <= all; i++) dp[c, i] = -MOD;
		dp[m, 0] = 0;
		foreach (var c1 in S)
		{
			var c = rev[c1];
			var s = 1 << c;
			var next = new int[m + 1, all + 1];
			for (var d = 0; d <= m; d++) for (var i = 0; i <= all; i++) next[d, i] = dp[d, i];
			for (var i = 0; i < all; i++)
				if ((i & s) > 0)
				{
					next[c, i] = Max(next[c, i], dp[c, i] + point[c1] + Y);
					for (var d = 0; d <= m; d++) if (d != c)
						{
							next[c, i] = Max(next[c, i], dp[d, i - s] + point[c1]);
							next[c, i] = Max(next[c, i], dp[d, i] + point[c1]);
						}
				}
			next[c, all] = Max(next[c, all], dp[c, all] + point[c1] + Y);
			for (var d = 0; d <= m; d++) if (d != c)
				{
					next[c, all] = Max(next[c, all], dp[d, all - s] + point[c1] + Z);
					next[c, all] = Max(next[c, all], dp[d, all] + point[c1]);
				}
			dp = next;
			/*for (var d = 0; d <= m; d++)
			{
				Console.WriteLine("[Last color = {0}]", d < m ? ((char)(colors[d] + 'A')).ToString() : "null");
				for (var i = 0; i <= all; i++)
				{
					var used = new List<char>();
					for (var j = 0; j < m; j++) if ((i & (1 << j)) > 0) used.Add((char)(colors[j] + 'A'));
					Console.WriteLine("Used colors = {0} => {1}", string.Join("", used), dp[d, i] == -MOD ? "-?" : dp[d, i].ToString());
				}
			}
			Console.WriteLine();*/
		}
		var ans = -MOD;
		for (var c = 0; c <= m; c++) for (var i = 0; i <= all; i++) ans = Max(ans, dp[c, i]);
		Console.WriteLine(ans);
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