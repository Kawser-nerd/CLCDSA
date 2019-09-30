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
	int Y,X,sx,sy,gx,gy;
	bool[,] map;
	void Solve()
	{
		var I = G();
		Y = I[0];
		X = I[1];
		map = new bool[X, Y];
		for (var y = 0; y < Y; y++)
		{
			var l = ReadLine();
			for (var x = 0; x < X; x++)
			{
				if (l[x] == 's')
				{
					sx = x;
					sy = y;
				}
				else if (l[x] == 'g')
				{
					gx = x;
					gy = y;
				}
				map[x, y] = l[x] != '#';
			}
		}
		var dx = new []{ 1, 0, -1, 0, 1 };
		var d = new int[X, Y];
		for (var x = 0; x < X; x++) for (var y = 0; y < Y; y++) d[x, y] = 3;
		d[sx, sy] = 0;
		var deq = new Deque<Tuple<int,int>>();
		deq.PushFront(new Tuple<int, int>(sx, sy));
		while (deq.Count > 0)
		{
			var p = deq.PopFront();
			int x = p.Item1, y = p.Item2;
			for (var i = 0; i < 4; i++)
			{
				int u = x + dx[i], v = y + dx[i + 1];
				if ((uint)u >= (uint)X || (uint)v >= (uint)Y) continue;
				int cost = map[u, v] ? 0 : 1, tmp = d[x, y] + cost;
				if (d[u, v] > tmp)
				{
					d[u, v] = tmp;
					if (cost == 1) deq.PushBack(new Tuple<int, int>(u, v));
					else deq.PushFront(new Tuple<int, int>(u, v));
				}
			}
		}
		WriteLine(d[gx, gy] <= 2 ? "YES" : "NO");
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