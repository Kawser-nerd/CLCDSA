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
class Z { static void Main() => new K(); }
class K
{
	int F() => int.Parse(ReadLine());
	long FL() => long.Parse(ReadLine());
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
		var K = F();
		var es = new List<E>[K];
		for (var i = 0; i < K; i++) es[i] = new List<E>{ new E((i + 1) % K, true), new E((i * 10) % K, false) };
		var d = new int[K];
		for (var i = 0; i < K; i++) d[i] = MOD;
		d[1] = 0;
		var deq = new Deque<int>();
		deq.PushFront(1);
		while (deq.Count > 0)
		{
			var u = deq.PopFront();
			foreach (var t in es[u])
			{
				int v = t.T, cost = t.IsHeavy ? 1 : 0, tmp = d[u] + cost;
				if (d[v] > tmp)
				{
					d[v] = tmp;
					if (t.IsHeavy) deq.PushBack(v);
					else deq.PushFront(v);
				}
			}
		}
		Console.WriteLine(d[0] + 1);
	}
}
struct E
{
	public readonly int T;
	public readonly bool IsHeavy;
	public E(int t, bool h) { T = t; IsHeavy = h; }
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