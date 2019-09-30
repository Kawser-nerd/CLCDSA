using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using Problem = Tmp.Problem;
namespace Tmp
{
	//using GeometryLong;
	class Problem : IDisposable
	{
		bool IsGCJ;
		int Repeat;
		Scanner sc;
		Printer pr;
		public Problem(bool isGCJ, Scanner scanner, Printer printer)
		{
			sc = scanner;
			pr = printer;
			IsGCJ = isGCJ;
			if (isGCJ) Repeat = sc.Get<int>();
			else Read();
		}
		public Problem(bool isGCJ) : this(isGCJ, new Scanner(), new Printer()) { }
		public Problem(bool isGCJ, Scanner scanner) : this(isGCJ, scanner, new Printer()) { }
		public Problem(bool isGCJ, Printer printer) : this(isGCJ, new Scanner(), printer) { }
		public void Solve()
		{
			if (IsGCJ) for (var i = 0; i < Repeat; i++) { Read(); pr.Write("Case #" + (i + 1) + ": "); SolveOne(); }
			else SolveOne();
		}
		public void Dispose()
		{
			sc.Dispose();
			pr.Dispose();
		}
		public int Size { get { return 1; } }
		public const uint Mod = 1000000007;
		RandomSFMT rand = Program.rand;
		int N;
		Tuple<int,int>[] boxes;
		void Read()
		{
			N=sc.Int;
			boxes=sc.ReadManyLines<int,int>(N);
		}
		void SolveOne()
		{
			Array.Sort(boxes, (x,y)=>{var t = x.Item1.CompareTo(y.Item1); return t == 0 ? y.Item2.CompareTo(x.Item2) : t; });
			var list = new List<List<Tuple<int, int>>>();
			for (var i = 0; i < N; )
			{
				var j = i + 1;
				while (j < N && boxes[j].Item1 == boxes[i].Item1) j++;
				var tmp = new List<Tuple<int, int>>();
				for (var k = i; k < j; k++) tmp.Add(boxes[k]);
				list.Add(tmp);
				i = j;
			}
			var rmq = new RMQ(100001);
			foreach (var tmp in list)
			{
				foreach	(var b in tmp)
				{
					rmq.Update(b.Item2, Math.Min(rmq.Min(0, b.Item2) - 1, rmq.Min(b.Item2, b.Item2 + 1)));
				}
			}
			pr.WriteLine(-rmq.Min(0, 100001));
			//var M = list.Count;
			//var memo = new Tuple<int, int>[M];
			//for (var i = 0; i < M; i++) memo[i] = new Tuple<int, int>(Func.Inf, Func.Inf);
			//for (var i = 0; i < M; i++)
			//{
			//	var k = Func.FirstBinary(0, M, x => list[i][0].Item1 <= memo[x].Item1);
			//	var l = Func.FirstBinary(0, list[i].Count, x => list[i][x].Item
			//	memo[k] = list[i][0];
			//}
			//pr.WriteLine(Func.FirstBinary(0, M, x => memo[x].Item1 == Func.Inf));
			//var list = new List<Tuple<int,int>>();
			//var last = new Tuple<int, int>(1000000,1000000);
			//foreach(var b in boxes) if (b.Item1 < last.Item1 && b.Item2 < last.Item2) { last = b; list.Add(last); }
			//var ans = LongestIncreasingSubsequence(list.Select(_=>-_.Item2).ToArray());
			//var i = list.Count - 1;
			//for (; i >= 0; i--) if (list[i].Item2 < -ans.Item2) break;
			//pr.WriteLine(ans.Item1 + (list[i].Item1 > boxes[N-1].Item1 && list[i].Item2 > boxes[N-1].Item2 ? 1 : 0));
			//pr.WriteLine(LongestIncreasingSubsequence(boxes.Select(_=>-_.Item2).ToArray()).Item1);
		}
	}
}
/*class MultiSortedSet<T> : IEnumerable<T>, ICollection<T>
{
	public IComparer<T> Comparer { get; private set; }
	private SortedSet<T> keys;
	private Dictionary<T, int> mult;
	public int Multiplicity(T item) { return mult[item]; }
	public int Count { get; private set; }
	public MultiSortedSet(IComparer<T> comp)
	{
		keys = new SortedSet<T>(Comparer = comp);
		mult = new Dictionary<T, int>();
	}
	public MultiSortedSet(Comparison<T> comp) : this(Comparer<T>.Create(comp)) { }
	public MultiSortedSet() : this(Func.DefaultComparison<T>()) { }
	public void Add(T item) { Add(item, 1); }
	private void Add(T item, int num)
	{
		Count += num;
		if (!keys.Contains(item)) { keys.Add(item); mult.Add(item, num); }
		else mult[item] += num;
	}
	public void AddRange(IEnumerable<T> list) { foreach (var x in list) Add(x); }
	public bool Remove(T item)
	{
		if (!keys.Contains(item)) return false;
		Count--;
		if (mult[item] == 1) { keys.Remove(item); mult.Remove(item); }
		else mult[item]--;
		return true;
	}
	public bool Overlaps(IEnumerable<T> other) { return keys.Overlaps(other); }
	public bool IsSupersetOf(IEnumerable<T> other) { return keys.IsSupersetOf(other); }
	public bool IsSubsetOf(IEnumerable<T> other) { return keys.IsSubsetOf(other); }
	public bool IsProperSubsetOf(IEnumerable<T> other) { return keys.IsProperSubsetOf(other); }
	public bool IsProperSupersetOf(IEnumerable<T> other) { return keys.IsProperSupersetOf(other); }
	public void ExceptWith(IEnumerable<T> other) { foreach (var x in other) if (Contains(x)) Remove(x); }
	public void IntersectWith(IEnumerable<T> other)
	{
		var next = new MultiSortedSet<T>(Comparer);
		foreach (var x in other) if (Contains(x) && !next.Contains(x)) next.Add(x, mult[x]);
		keys = next.keys; mult = next.mult;
	}
	public void CopyTo(T[] array) { CopyTo(array, 0); }
	public void CopyTo(T[] array, int index) { foreach (var item in array) array[index++] = item; }
	public void CopyTo(T[] array, int index, int count) { var i = 0; foreach (var item in array) { if (i++ >= count) return; array[index++] = item; } }
	public bool Contains(T item) { return keys.Contains(item); }
	public void Clear() { keys.Clear(); mult.Clear(); Count = 0; }
	public IEnumerator<T> Reverse() { foreach (var x in keys.Reverse()) for (var i = 0; i < mult[x]; i++) yield return x; }
	public IEnumerator<T> GetEnumerator() { foreach (var x in keys) for (var i = 0; i < mult[x]; i++) yield return x; }
	IEnumerator IEnumerable.GetEnumerator() { return GetEnumerator(); }
	public T Max { get { return keys.Max; } }
	public T Min { get { return keys.Min; } }
	public bool IsReadOnly { get { return false; } }
}*/
class SkewHeap<T> : IEnumerable<T>
{
	class Node : IEnumerable<T>
	{
		public Node l, r;
		public T val;
		public Node(T x) { l = r = null; val = x; }
		public IEnumerator<T> GetEnumerator()
		{
			if (l != null) foreach (var x in l) yield return x;
			yield return val;
			if (r != null) foreach (var x in r) yield return x;
		}
		IEnumerator IEnumerable.GetEnumerator() { return (IEnumerator)GetEnumerator(); }
	}
	public int Count { get; private set; }
	Node head;
	Comparison<T> comp;
	public bool IsEmpty { get { return head != null; } }
	public SkewHeap(Comparison<T> c) { comp = c; Count = 0; }
	public SkewHeap() : this(Func.DefaultComparison<T>()) { }
	public SkewHeap(IComparer<T> c) : this(Func.ToComparison(c)) { }
	private SkewHeap(Comparison<T> c, Node h) : this(c) { head = h; }
	public void Push(T x) { var n = new Node(x); head = Meld(head, n); Count++; }
	public T Peek() { return head.val; }
	public T Pop() { var x = head.val; head = Meld(head.l, head.r); Count--; return x; }
	// a.comp must be equivalent to b.comp
	// a, b will be destroyed
	public static SkewHeap<T> Meld(SkewHeap<T> a, SkewHeap<T> b) { return new SkewHeap<T>(a.comp, a.Meld(a.head, b.head)); }
	public void MeldWith(SkewHeap<T> a) { head = Meld(head, a.head); }
	Node Meld(Node a, Node b)
	{
		if (a == null) return b;
		else if (b == null) return a;
		if (comp(a.val, b.val) > 0) Func.Swap(ref a, ref b);
		a.r = Meld(a.r, b);
		Func.Swap(ref a.l, ref a.r);
		return a;
	}
	public IEnumerator<T> GetEnumerator() { return head.GetEnumerator(); }
	IEnumerator IEnumerable.GetEnumerator() { return (IEnumerator)GetEnumerator(); }
}
// [0, Size) ?????????
class BITSet : BinaryIndexedTree
{
	public BITSet(int size) : base(size) { }
	public void Add(int item) { Add(item, 1); }
	public bool Contains(int item) { return Sum(item, item + 1) > 0; }
	public int Count(int item) { return Sum(item, item + 1); }
	// ?? = item ???????????(0-indexed)
	public int GetRank(int item) { return Sum(0, item); }
	public void Remove(int item) { Add(item, -1); }
	public void RemoveAll(int item) { Add(item, -Count(item)); }
	// 0-indexed ???? rank ???????
	// ????? Size ???
	public int GetValue(int rank) { return Func.FirstBinary(0, Size, t => Sum(0, t + 1) >= rank + 1); }
}
class RangeBIT
{
	public int N { get; private set; }
	long[,] bit;
	public RangeBIT(int N) { bit = new long[2, this.N = N + 1]; }
	public RangeBIT(int[] array) : this(array.Length)
	{
		for (var i = 1; i < N; i++) bit[0, i] = array[i - 1];
		for (var i = 1; i < N - 1; i++) if (i + (i & (-i)) < N) bit[0, i + (i & (-i))] += bit[0, i];
	}
	public RangeBIT(long[] array) : this(array.Length)
	{
		for (var i = 1; i < N; i++) bit[0, i] = array[i - 1];
		for (var i = 1; i < N - 1; i++) if (i + (i & (-i)) < N) bit[0, i + (i & (-i))] += bit[0, i];
	}
	public void Add(int from, int to, long value)
	{
		Add2(0, from + 1, -value * from);
		Add2(1, from + 1, value);
		Add2(0, to + 1, value * to);
		Add2(1, to + 1, -value);
	}
	void Add2(int which, int i, long value) { while (i < N) { bit[which, i] += value; i += i & (-i); } }
	long Sum(int to) { return Sum2(0, to) + Sum2(1, to) * to; }
	public long Sum(int from, int to) { return Sum(to) - Sum(from); }
	long Sum2(int which, int i) { var sum = 0L; while (i > 0) { sum += bit[which, i]; i -= i & (-i); } return sum; }
}
class RMQ
{
	int N2;
	int[] segtree;
	public RMQ(int N) : this(new int[N]) { }
	public RMQ(int[] array)
	{
		N2 = 1;
		while (N2 < array.Length) N2 <<= 1;
		segtree = new int[2 * N2 - 1];
		for (var i = 0; i < 2 * N2 - 1; i++) segtree[i] = Func.Inf;
		for (var i = 0; i < array.Length; i++) segtree[i + N2 - 1] = array[i];
		for (var i = N2 - 2; i >= 0; i--) segtree[i] = Math.Min(segtree[2 * i + 1], segtree[2 * i + 2]);
	}
	public void Update(int index, int value)
	{
		index += N2 - 1;
		segtree[index] = value;
		while (index > 0)
		{
			index = (index - 1) / 2;
			segtree[index] = Math.Min(segtree[index * 2 + 1], segtree[index * 2 + 2]);
		}
	}
	public int this[int n] { get { return Min(n, n + 1); } set { Update(n, value); } }
	public int Min(int from, int to) { return Min(from, to, 0, 0, N2); }
	int Min(int from, int to, int node, int l, int r)
	{
		if (to <= l || r <= from) return Func.Inf;
		else if (from <= l && r <= to) return segtree[node];
		else return Math.Min(Min(from, to, 2 * node + 1, l, (l + r) >> 1), Min(from, to, 2 * node + 2, (l + r) >> 1, r));
	}
}
class Program
{
	public static RandomSFMT rand = new RandomSFMT();
	public static bool IsJudgeMode = true;
	public static bool IsGCJMode = false;
	public static bool IsSolveCreated = true;
	static void Main()
	{
		if (IsJudgeMode)
			if (IsGCJMode) using (var problem = new Problem(true, new Scanner("C-large-practice.in.txt"), new Printer("output.txt"))) problem.Solve();
			else using (var problem = new Problem(false, new Printer())) problem.Solve();
		else
		{
			var num = 1;
			int size = 0;
			decimal time = 0;
			for (var tmp = 0; tmp < num; tmp++)
			{
				using (var P = IsSolveCreated ? new Problem(false, new Scanner("input.txt"), new Printer()) : new Problem(false))
				{
					size = P.Size;
					time += Func.MeasureTime(() => P.Solve());
				}
			}
			Console.WriteLine("{0}, {1}ms", size, time / num);
		}
	}
}
class BinaryIndexedTree3D
{
	public int X { get; private set; }
	public int Y { get; private set; }
	public int Z { get; private set; }
	int[,,] bit;
	public BinaryIndexedTree3D(int X, int Y, int Z)
	{
		this.X = X; this.Y = Y; this.Z = Z;
		bit = new int[X + 1, Y + 1, Z + 1];
	}
	public BinaryIndexedTree3D(int[,,] array)
		: this(array.GetLength(0), array.GetLength(1), array.GetLength(2))
	{
		for (var x = 0; x < X; x++) for (var y = 0; y < Y; y++) for (var z = 0; z < Z; z++) Add(x, y, z, array[x, y, z]);
	}
	public void Add(int x, int y, int z, int value)
	{
		for (var i = x + 1; i <= X; i += i & (-i)) for (var j = y + 1; j <= Y; j += j & (-j)) for (var k = z + 1; k <= Z; k += k & (-k)) bit[i, j, k] += value;
	}
	public int Sum(int x0, int y0, int z0, int x1, int y1, int z1)
	{
		return Sum(x1, y1, z1) - Sum(x0, y1, z1) - Sum(x1, y0, z1) - Sum(x1, y1, z0) + Sum(x1, y0, z0) + Sum(x0, y1, z0) + Sum(x0, y0, z1) - Sum(x0, y0, z0);
	}
	int Sum(int x, int y, int z)
	{
		var sum = 0;
		for (var i = x; i > 0; i -= i & (-i)) for (var j = y; j > 0; j -= j & (-j)) for (var k = y; k > 0; k -= k & (-k)) sum += bit[i, j, k];
		return sum;
	}
}
class BinaryIndexedTree2D
{
	public int X { get; private set; }
	public int Y { get; private set; }
	int[,] bit;
	public BinaryIndexedTree2D(int X, int Y)
	{
		this.X = X; this.Y = Y;
		bit = new int[X + 1, Y + 1];
	}
	public BinaryIndexedTree2D(int[,] array)
		: this(array.GetLength(0), array.GetLength(1))
	{
		for (var x = 0; x < X; x++) for (var y = 0; y < Y; y++) Add(x, y, array[x, y]);
	}
	public void Add(int x, int y, int value) { for (var i = x + 1; i <= X; i += i & (-i)) for (var j = y + 1; j <= Y; j += j & (-j)) bit[i, j] += value; }
	public int Sum(int x0, int y0, int x1, int y1) { return Sum(x0, y0) + Sum(x1, y1) - Sum(x0, y1) - Sum(x1, y0); }
	int Sum(int x, int y) { var sum = 0; for (var i = x; i > 0; i -= i & (-i)) for (var j = y; j > 0; j -= j & (-j)) sum += bit[i, j]; return sum; }
}
class BinaryIndexedTree
{
	public int Size { get; private set; }
	int[] bit;
	public BinaryIndexedTree(int size)
	{
		Size = size;
		bit = new int[size + 1];
	}
	public BinaryIndexedTree(int[] array) : this(array.Length)
	{
		for (var i = 0; i < Size; i++) bit[i + 1] = array[i];
		for (var i = 1; i < Size; i++) if (i + (i & (-i)) <= Size) bit[i + (i & (-i))] += bit[i];
	}
	// index is 0-indexed
	public void Add(int index, int value) { for (var i = index + 1; i <= Size; i += i & (-i)) bit[i] += value; }
	// from, to is 0-indexed
	// from is inclusive, to is exclusive
	public int Sum(int from, int to) { return Sum(to) - Sum(from); }
	int Sum(int to) { var sum = 0; for (var i = to; i > 0; i -= i & (-i)) sum += bit[i]; return sum; }
}
class Amoeba
{
	public const int Dimension = 2;
	public const double Alpha = 1;  // reflection
	public const double Beta = 1 + 2.0 / Dimension; // expansion
	public const double Gamma = 0.75 - 0.5 / Dimension; // contraction
	public const double Delta = 1 - 1.0 / Dimension;    // shrink
	public Pair<AmoebaState, double>[] a;
	public AmoebaState m;
	public void Initiate()
	{
		Array.Sort(a, (x, y) => x.Second.CompareTo(y.Second));
		m = new AmoebaState();
		for (var i = 0; i < Dimension; i++) m.Add(a[i].First);
		m.Multiply(1.0 / Dimension);
	}
	void PartialSort(int i, int j) { if (a[i].Second > a[j].Second) a.Swap(i, j); }
	void Accept(AmoebaState point, double value)
	{
		var tmp = Func.FirstBinary(0, Dimension, x => a[x].Second >= value);
		if (tmp != Dimension) m.Add((point - a[Dimension - 1].First) / Dimension);
		for (var i = Dimension; i > tmp; i--) a[i] = a[i - 1];
		a[tmp].First = point;
		a[tmp].Second = value;
	}
	public void Search()
	{
		var r = m + Alpha * (m - a[Dimension].First);
		var fr = r.Func();
		if (a[0].Second <= fr && fr < a[Dimension - 1].Second) { Accept(r, fr); return; }
		var diff = r - m;
		if (fr < a[0].Second)
		{
			var e = m + Beta * diff;
			var fe = e.Func();
			if (fe < fr) Accept(e, fe);
			else Accept(r, fr);
		}
		else
		{
			var tmp = Gamma * diff;
			var o = m + tmp;
			var fo = o.Func();
			var i = m - tmp;
			var fi = i.Func();
			if (fi < fo) { o = i; fo = fi; }
			if (fo < a[Dimension - 1].Second) Accept(o, fo);
			else Shrink();
		}
	}
	void Shrink()
	{
		var tmp = (1 - Delta) * a[0].First;
		for (var i = 1; i <= Dimension; i++) { a[i].First.Multiply(Delta); a[i].First.Add(tmp); a[i].Second = a[i].First.Func(); }
		Initiate();
	}
}
class AmoebaState
{
	public static int Dimension = 2;
	public double[] vec;
	public AmoebaState() { vec = new double[Dimension]; }
	public AmoebaState(params double[] elements) : this() { elements.CopyTo(vec, 0); }
	public double this[int n] { get { return vec[n]; } set { vec[n] = value; } }
	public void Multiply(double r) { for (var i = 0; i < Dimension; i++) vec[i] *= r; }
	public void Add(AmoebaState v) { for (var i = 0; i < Dimension; i++) vec[i] += v.vec[i]; }
	public static AmoebaState operator +(AmoebaState p) { return new AmoebaState(p.vec); }
	public static AmoebaState operator -(AmoebaState p) { var tmp = new AmoebaState(p.vec); tmp.Multiply(-1); return tmp; }
	public static AmoebaState operator /(AmoebaState p, double r) { var tmp = new AmoebaState(p.vec); tmp.Multiply(1 / r); return tmp; }
	public static AmoebaState operator *(double r, AmoebaState p) { var tmp = new AmoebaState(p.vec); tmp.Multiply(r); return tmp; }
	public static AmoebaState operator *(AmoebaState p, double r) { return r * p; }
	public static AmoebaState operator +(AmoebaState p, AmoebaState q) { var tmp = +p; tmp.Add(q); return tmp; }
	public static AmoebaState operator -(AmoebaState p, AmoebaState q) { var tmp = -q; tmp.Add(p); return tmp; }
	public double Func()
	{
		return 0;//P.Func(vec[0], vec[1]);
	}
	public static Problem P;
}
class BucketList<T> : ICollection<T>, IEnumerable<T>, ICollection, IEnumerable
{
	public Comparison<T> comp { get; protected set; }
	public int BucketSize = 20;
	public int Count { get { var sum = 0; var bucket = Head; while (bucket != null) { sum += bucket.Count; bucket = bucket.Next; } return sum; } }
	public int NumOfBucket { get; protected set; }
	public Bucket<T> Head { get; protected set; }
	public Bucket<T> Tail { get; protected set; }
	public BucketList(IComparer<T> comp) : this(comp.ToComparison()) { }
	public BucketList(Comparison<T> comp = null) { Head = null; Tail = null; NumOfBucket = 0; this.comp = comp == null ? Func.DefaultComparison<T>() : comp; }
	protected void AddAfter(Bucket<T> pos, Bucket<T> bucket)
	{
		Debug.Assert(bucket != null && bucket.Count > 0 && pos != null && pos.Parent == this && comp(pos.Tail.Value, bucket.Head.Value) <= 0
					&& (pos.Next == null || comp(pos.Next.Head.Value, bucket.Tail.Value) >= 0));
		bucket.Parent = this;
		bucket.Prev = pos;
		bucket.Next = pos.Next;
		if (pos != Tail) pos.Next.Prev = bucket;
		else Tail = bucket;
		pos.Next = bucket;
		NumOfBucket++;
	}
	protected void AddBefore(Bucket<T> pos, Bucket<T> bucket)
	{
		Debug.Assert(bucket != null && bucket.Count > 0 && pos != null && pos.Parent == this && comp(pos.Head.Value, bucket.Tail.Value) >= 0
					&& (pos.Prev == null || comp(pos.Prev.Tail.Value, bucket.Head.Value) <= 0));
		bucket.Parent = this;
		bucket.Prev = pos.Prev;
		bucket.Next = pos;
		if (pos != Head) pos.Prev.Next = bucket;
		else Head = bucket;
		pos.Prev = bucket;
		NumOfBucket++;
	}
	protected void AddAfter(Bucket<T> bucket, BucketNode<T> node)
	{
		Debug.Assert(node != null && bucket != null && bucket.Parent == this && node.Parent.Parent == this && comp(bucket.Tail.Value, node.Value) <= 0
					&& (bucket.Next == null || comp(bucket.Next.Head.Value, node.Value) >= 0));
		var tmp = new Bucket<T>(this, bucket, bucket.Next);
		tmp.InitiateWith(node);
		if (bucket != Tail) bucket.Next.Prev = tmp;
		else Tail = tmp;
		bucket.Next = tmp;
		NumOfBucket++;
	}
	protected void AddBefore(Bucket<T> bucket, BucketNode<T> node)
	{
		Debug.Assert(node != null && bucket != null && bucket.Parent == this && node.Parent.Parent == this && comp(bucket.Head.Value, node.Value) >= 0
					&& (bucket.Prev == null || comp(bucket.Prev.Tail.Value, node.Value) <= 0));
		var tmp = new Bucket<T>(this, bucket.Prev, bucket);
		tmp.InitiateWith(node);
		if (bucket != Head) bucket.Prev.Next = tmp;
		else Head = tmp;
		bucket.Prev = tmp;
		NumOfBucket++;
	}
	public void AddAfter(BucketNode<T> node, T item)
	{
		Debug.Assert(node != null && node.Parent.Parent == this && comp(node.Value, item) <= 0
					&& ((node.Next == null && (node.Parent.Next == null || comp(node.Parent.Next.Head.Value, item) >= 0))
						|| comp(node.Next.Value, item) >= 0));
		var bucket = node.Parent;
		var tmp = new BucketNode<T>(item, bucket, node, node.Next);
		if (!bucket.AddAfter(node, tmp))
		{
			if (node.Next == null && (bucket.Next == null || bucket.Next.Count >= BucketSize)) AddAfter(bucket, tmp);
			else if (node.Next == null) AddBefore(bucket.Next.Head, item);
			else
			{
				node.Next.Prev = tmp;
				node.Next = tmp;
				while (node.Next.Next != null) node = node.Next;
				item = node.Next.Value;
				bucket.Tail = node;
				node.Next = null;
				AddAfter(node, item);
			}
		}
	}
	public void AddBefore(BucketNode<T> node, T item)
	{
		Debug.Assert(node != null && node.Parent.Parent == this && comp(node.Value, item) >= 0
					&& ((node.Prev == null && (node.Parent.Prev == null || comp(node.Parent.Prev.Tail.Value, item) <= 0))
						|| comp(node.Prev.Value, item) <= 0));
		var bucket = node.Parent;
		var tmp = new BucketNode<T>(item, bucket, node.Prev, node);
		if (!bucket.AddBefore(node, tmp))
		{
			if (node.Prev == null && (bucket.Prev == null || bucket.Prev.Count >= BucketSize)) AddBefore(bucket, tmp);
			else if (node.Prev == null) AddAfter(bucket.Prev.Tail, item);
			else
			{
				node.Prev.Next = tmp;
				node.Prev = tmp;
				while (node.Prev.Prev != null) node = node.Prev;
				item = node.Prev.Value;
				bucket.Head = node;
				node.Prev = null;
				AddBefore(node, item);
			}
		}
	}
	// (node, index)
	// index is the position of node in node.Parent
	public Tuple<BucketNode<T>, int> UpperBound(Predicate<T> pred)
	{
		if (NumOfBucket == 0) return null;
		if (pred(Tail.Tail.Value)) return new Tuple<BucketNode<T>, int>(Tail.Tail, Tail.Count - 1);
		var bucket = Tail;
		while (bucket.Prev != null && !pred(bucket.Prev.Tail.Value)) bucket = bucket.Prev;
		var node = bucket.Tail;
		var index = bucket.Count - 1;
		while (node.Prev != null && !pred(node.Prev.Value)) { node = node.Prev; index--; }
		if (node.Prev == null) return bucket.Prev == null ? null : new Tuple<BucketNode<T>, int>(bucket.Prev.Tail, bucket.Prev.Count - 1);
		else return new Tuple<BucketNode<T>, int>(node.Prev, index - 1);
	}
	public Tuple<BucketNode<T>, int> UpperBound(T item) { return LowerBound(x => comp(x, item) <= 0); }
	// (node, index)
	// index is the position of node in node.Parent
	public Tuple<BucketNode<T>, int> LowerBound(Predicate<T> pred)
	{
		if (NumOfBucket == 0) return null;
		if (pred(Head.Head.Value)) return new Tuple<BucketNode<T>, int>(Head.Head, 0);
		var bucket = Head;
		while (bucket.Next != null && !pred(bucket.Next.Head.Value)) bucket = bucket.Next;
		var node = bucket.Head;
		var index = 0;
		while (node.Next != null && !pred(node.Next.Value)) { node = node.Next; index++; }
		if (node.Next == null) return bucket.Next == null ? null : new Tuple<BucketNode<T>, int>(bucket.Next.Head, 0);
		else return new Tuple<BucketNode<T>, int>(node.Next, index + 1);
	}
	public Tuple<BucketNode<T>, int> LowerBound(T item) { return LowerBound(x => comp(x, item) >= 0); }
	public void InitiateWith(Bucket<T> bucket)
	{
		Debug.Assert(bucket != null && bucket.Count > 0);
		RemoveAll();
		Head = Tail = bucket;
		bucket.Parent = this;
		NumOfBucket++;
	}
	public void InitiateWith(T item)
	{
		RemoveAll();
		Head = Tail = new Bucket<T>(this, null, null);
		Head.Head = Head.Tail = new BucketNode<T>(item, Head, null, null);
		Head.Count++;
		NumOfBucket++;
	}
	public void AddFirst(Bucket<T> bucket) { if (NumOfBucket == 0) InitiateWith(bucket); else AddBefore(Head, bucket); }
	public void AddLast(Bucket<T> bucket) { if (NumOfBucket == 0) InitiateWith(bucket); else AddAfter(Tail, bucket); }
	public void AddFirst(T item) { if (NumOfBucket == 0) InitiateWith(item); else AddBefore(Head.Head, item); }
	public void AddLast(T item) { if (NumOfBucket == 0) InitiateWith(item); else AddAfter(Tail.Tail, item); }
	public void Clear() { RemoveAll(); }
	public void RemoveAll() { Head = Tail = null; NumOfBucket = 0; }
	public void RemoveFirst() { if (NumOfBucket == 0) throw new InvalidOperationException(); else Remove(Head.Head); }
	public void RemoveLast() { if (NumOfBucket == 0) throw new InvalidOperationException(); else Remove(Tail.Tail); }
	// remove item and return whether item was removed or not
	public bool Remove(T item) { var node = Find(item); if (node != null) Remove(node); return node != null; }
	public void Remove(Bucket<T> bucket)
	{
		Debug.Assert(bucket != null && bucket.Parent == this);
		NumOfBucket--;
		if (bucket == Head && bucket == Tail) { Head = Tail = null; }
		else if (bucket == Head) { Head.Next.Prev = null; Head = Head.Next; }
		else if (bucket == Tail) { Tail.Prev.Next = null; Tail = Tail.Prev; }
		else { bucket.Prev.Next = bucket.Next; bucket.Next.Prev = bucket.Prev; }
	}
	public void Remove(BucketNode<T> node) { Debug.Assert(node != null && node.Parent.Parent == this); if (!node.Parent.Remove(node)) Remove(node.Parent); }
	protected void RemoveRange(Bucket<T> from, Bucket<T> to, int indexFrom = -1, int indexTo = -1)
	{
		Debug.Assert(from != null && to != null && from.Parent == this && to.Parent == this);
		if (indexFrom < 0) indexFrom = from.Index;
		if (indexTo < 0) indexTo = to.Index;
		if (indexFrom == 0 && indexTo == NumOfBucket - 1) { Clear(); return; }
		else if (indexFrom == 0) { Head = to.Next; Head.Prev = null; }
		else if (indexTo == NumOfBucket - 1) { Tail = from.Prev; Tail.Next = null; }
		else { from.Prev.Next = to.Next; to.Next.Prev = from.Prev; }
		NumOfBucket -= indexTo - indexFrom + 1;
	}
	public void RemoveRange(BucketNode<T> from, BucketNode<T> to, int indexFrom = -1, int indexTo = -1)
	{
		Debug.Assert(from != null && to != null && from.Parent.Parent == this && to.Parent.Parent == this);
		if (indexFrom < 0) indexFrom = from.Index;
		if (indexTo < 0) indexTo = to.Index;
		var bucketFrom = from.Parent;
		var bucketTo = to.Parent;
		if (bucketFrom == bucketTo)
		{
			var bucket = bucketFrom;
			if (indexFrom == 0 && indexTo == bucket.Count - 1) Remove(bucket);
			else bucket.RemoveRange(from, to, indexFrom, indexTo);
		}
		else
		{
			var bf = bucketFrom.Index;
			var bt = bucketTo.Index;
			Debug.Assert(bf < bt);
			if (bt > bf + 1) RemoveRange(bucketFrom.Next, bucketTo.Prev, bf + 1, bt - 1);
			if (indexFrom == 0) { Remove(bucketFrom); RemoveRange(bucketTo.Head, to, 0, indexTo); }
			else if (indexTo == bucketTo.Count - 1) { Remove(bucketTo); RemoveRange(from, bucketFrom.Tail, indexFrom, bucketFrom.Count - 1); }
			else
			{
				bucketFrom.RemoveRange(from, bucketFrom.Tail, indexFrom, bucketFrom.Count - 1);
				bucketTo.RemoveRange(bucketTo.Head, to, 0, indexTo);
				if (bucketFrom.Count + bucketTo.Count < BucketSize) Adjust();
			}
		}
	}
	public void Adjust()
	{
		var array = this.ToArray();
		Clear();
		var length = array.Length;
		BucketSize = (int)Math.Sqrt(length + 1);
		var count = (length + BucketSize - 1) / BucketSize;
		for (var i = 0; i < count; i++)
		{
			var bucket = new Bucket<T>(this, null, null);
			var lim = Math.Min(BucketSize * (i + 1), length);
			for (var j = BucketSize * i; j < lim; j++) bucket.AddLast(array[j]);
			AddLast(bucket);
		}
	}
	public BucketNode<T> Find(T item) { var node = LowerBound(item); if (node == null || comp(node.Item1.Value, item) != 0) return null; else return node.Item1; }
	public BucketNode<T> FindLast(T item) { var node = UpperBound(item); if (node == null || comp(node.Item1.Value, item) != 0) return null; else return node.Item1; }
	public IEnumerator<T> GetEnumerator()
	{
		var bucket = Head;
		while (bucket != null)
		{
			var node = bucket.Head;
			while (node != null) { yield return node.Value; node = node.Next; }
			bucket = bucket.Next;
		}
	}
	public void Add(T item) { var ub = LowerBound(item); if (ub != null) AddBefore(ub.Item1, item); else AddLast(item); }
	IEnumerator IEnumerable.GetEnumerator() { return GetEnumerator(); }
	public void CopyTo(Array array, int index) { foreach (var item in this) array.SetValue(item, index++); }
	public bool IsSynchronized { get { return false; } }
	public object SyncRoot { get { return this; } }
	public bool IsReadOnly { get { return false; } }
	public bool Contains(T item) { return Find(item) != null; }
	public void CopyTo(T[] array, int index) { foreach (var item in this) array[index++] = item; }
	public override string ToString()
	{
		var sb = new StringBuilder();
		sb.Append("<Start>\n");
		var node = Head;
		while (node != null) { sb.Append(node.ToString() + "\n"); node = node.Next; }
		sb.Append("<end>");
		return sb.ToString();
	}
	public bool Check()
	{
		if (NumOfBucket == 0) return Head == null && Tail == null;
		if (Head.Prev != null || Tail.Next != null) return false;
		var bucket = Head;
		var c = 1;
		while (bucket.Next != null)
		{
			if (!CheckConnection(bucket) || !CheckBucket(bucket)) return false;
			bucket = bucket.Next;
			c++;
		}
		return bucket == Tail && CheckBucket(Tail) && c == NumOfBucket;
	}
	bool CheckConnection(Bucket<T> bucket)
	{
		if (bucket.Next == null) return bucket == Tail;
		else return bucket.Next.Prev == bucket && comp(bucket.Tail.Value, bucket.Next.Head.Value) <= 0;
	}
	bool CheckBucket(Bucket<T> bucket) { return bucket.Count > 0 && bucket.Count <= BucketSize && bucket.Parent == this; }
	public void Start(Func<string, T> parser, Func<T> random)
	{
		BucketNode<T> x = null, y = null;
		var help = true;
		while (true)
		{
			Console.Clear();
			Console.WriteLine("{0} items, {1} buckets(size : {2})", Count, NumOfBucket, BucketSize);
			Console.WriteLine(this);
			Console.WriteLine(Check() ? "OK!" : "NG!");
			if (help)
			{
				Console.WriteLine("when val is omitted, random value will be used.");
				Console.WriteLine("a val : add val");
				Console.WriteLine("r val : remove val");
				Console.WriteLine("j : adjust");
				Console.WriteLine("c : clear");
				Console.WriteLine("h : disable/enable help message");
				Console.WriteLine("x : set x");
				Console.WriteLine("x h : set x to head");
				Console.WriteLine("x t : set x to tail");
				Console.WriteLine("x n : set x to x.next");
				Console.WriteLine("x p : set x to x.prev");
				Console.WriteLine("x f val : set x to lower bound of val");
				Console.WriteLine("y : set y");
				Console.WriteLine("x : exchange x and y");
				Console.WriteLine("d : remove from x to y");
				Console.WriteLine("q : quit");
			}
			if (x != null) Console.WriteLine("x = {0} <- {1}", x.Value, x.Parent);
			if (y != null) Console.WriteLine("y = {0} <- {1}", y.Value, y.Parent);
			Console.Write("enter command > ");
			var command = Console.ReadLine().Split();
			if (command[0].Length > 1 && command[0][1] == 'd')
				Console.WriteLine("debug...");
			if (command[0].StartsWith("a")) { if (command.Length > 1) Add(parser(command[1])); else Add(random()); }
			else if (command[0].StartsWith("r")) { if (command.Length > 1) Remove(parser(command[1])); else Remove(random()); }
			else if (command[0].StartsWith("c")) Clear();
			else if (command[0].StartsWith("j")) Adjust();
			else if (command[0].StartsWith("h")) help = !help;
			else if (command[0].StartsWith("x")) SetVariable(command, ref x, parser, random);
			else if (command[0].StartsWith("y")) SetVariable(command, ref y, parser, random);
			else if (command[0].StartsWith("e")) { var tmp = x; x = y; y = tmp; }
			else if (command[0].StartsWith("d")) { RemoveRange(x, y, x.Index, y.Index); x = null; y = null; }
			else if (command[0].StartsWith("q")) break;
		}
	}
	void SetVariable(string[] command, ref BucketNode<T> x, Func<string, T> parser, Func<T> random)
	{
		if (command[1].StartsWith("h")) x = Head.Head;
		else if (command[1].StartsWith("t")) x = Tail.Tail;
		else if (command[1].StartsWith("n"))
		{
			if (x.Next != null) x = x.Next;
			else if (x.Parent.Next != null) x = x.Parent.Next.Head;
			else { Console.WriteLine("x is the last element..."); Console.ReadKey(true); }
		}
		else if (command[1].StartsWith("p"))
		{
			if (x.Prev != null) x = x.Prev;
			else if (x.Parent.Prev != null) x = x.Parent.Prev.Tail;
			else { Console.WriteLine("x is the first element..."); Console.ReadKey(true); }
		}
		else if (command[1].StartsWith("f")) { if (command.Length > 2) x = LowerBound(parser(command[2])).Item1; else x = LowerBound(random()).Item1; }
	}
}
// bucket cannot be empty
class Bucket<T>
{
	public BucketList<T> Parent;
	public int Count;
	public Bucket<T> Prev;
	public Bucket<T> Next;
	public BucketNode<T> Head;
	public BucketNode<T> Tail;
	public Bucket(BucketList<T> parent, Bucket<T> prev, Bucket<T> next) { Parent = parent; Prev = prev; Next = next; Head = null; Tail = null; }
	public int Index
	{
		get
		{
			var count = 0;
			var node = Parent.Head;
			while (node != this) { node = node.Next; count++; }
			return count;
		}
	}
	public bool AddAfter(BucketNode<T> node, BucketNode<T> item) { return AddAfter(node, item.Value); }
	public bool AddBefore(BucketNode<T> node, BucketNode<T> item) { return AddBefore(node, item.Value); }
	public bool AddAfter(BucketNode<T> node, T item)
	{
		Debug.Assert(node != null && node.Parent == this && Parent.comp(node.Value, item) <= 0
					&& ((node.Next == null && (Next == null || Parent.comp(Next.Head.Value, item) >= 0))
						|| Parent.comp(node.Next.Value, item) >= 0));
		if (Count < Parent.BucketSize)
		{
			var tmp = new BucketNode<T>(item, this, node, node.Next);
			if (node.Next != null) node.Next.Prev = tmp;
			else Tail = tmp;
			node.Next = tmp;
			Count++;
			return true;
		}
		return false;
	}
	public bool AddBefore(BucketNode<T> node, T item)
	{
		Debug.Assert(node != null && node.Parent == this && Parent.comp(node.Value, item) >= 0
					&& ((node.Prev == null && (Prev == null || Parent.comp(Prev.Tail.Value, item) <= 0))
						|| Parent.comp(node.Prev.Value, item) <= 0));
		if (Count < Parent.BucketSize)
		{
			var tmp = new BucketNode<T>(item, this, node.Prev, node);
			if (node.Prev != null) node.Prev.Next = tmp;
			else Head = tmp;
			node.Prev = tmp;
			Count++;
			return true;
		}
		else return false;
	}
	public bool InitiateWith(BucketNode<T> node)
	{
		Head = Tail = node;
		node.Parent = this;
		node.Prev = node.Next = null;
		Count++;
		return true;
	}
	public bool InitiateWith(T item) { return InitiateWith(new BucketNode<T>(item, this, null, null)); }
	public void RemoveAll() { Head = Tail = null; Count = 0; }
	public bool AddFirst(T item) { if (Count == 0) return InitiateWith(item); else return AddBefore(Head, item); }
	public bool AddLast(T item) { if (Count == 0) return InitiateWith(item); else return AddAfter(Tail, item); }
	public bool Remove(BucketNode<T> node)
	{
		Debug.Assert(node != null && node.Parent == this);
		if (Count > 1)
		{
			Count--;
			if (node == Head) { Head.Next.Prev = null; Head = Head.Next; }
			else if (node == Tail) { Tail.Prev.Next = null; Tail = Tail.Prev; }
			else { node.Prev.Next = node.Next; node.Next.Prev = node.Prev; }
			return true;
		}
		else return false;
	}
	public bool RemoveRange(BucketNode<T> from, BucketNode<T> to, int indexFrom = -1, int indexTo = -1)
	{
		Debug.Assert(from != null && to != null && from.Parent == this && to.Parent == this);
		if (indexFrom < 0) indexFrom = from.Index;
		if (indexTo < 0) indexTo = to.Index;
		if (indexTo == 0 && indexFrom == Count - 1) return false;
		else if (indexFrom == 0) { Head = to.Next; Head.Prev = null; }
		else if (indexTo == Count - 1) { Tail = from.Prev; Tail.Next = null; }
		else { from.Prev.Next = to.Next; to.Next.Prev = from.Prev; }
		Count -= indexTo - indexFrom + 1;
		return true;
	}
	public override string ToString()
	{
		var sb = new StringBuilder();
		sb.Append("[");
		var node = Head;
		while (node != null) { sb.Append(node.ToString() + ", "); node = node.Next; }
		if (sb.Length > 1) sb.Remove(sb.Length - 2, 2);
		sb.Append("]");
		return sb.ToString();
	}
	public bool Check()
	{
		if (Count == 0) return Head == null && Tail == null;
		if (Head.Prev != null || Tail.Next != null) return false;
		var node = Head;
		var c = 1;
		while (node.Next != null)
		{
			if (!CheckConnection(node) || !CheckNode(node)) return false;
			node = node.Next;
			c++;
		}
		return node == Tail && CheckNode(Tail) && c == Count;
	}
	bool CheckConnection(BucketNode<T> node)
	{
		if (node.Next == null) return node == Tail;
		else return node.Next.Prev == node && Parent.comp(node.Value, node.Next.Value) <= 0;
	}
	bool CheckNode(BucketNode<T> node) { return node.Parent == this; }
}
class BucketNode<T>
{
	public T Value;
	public Bucket<T> Parent;
	public BucketNode<T> Prev;
	public BucketNode<T> Next;
	public BucketNode(T item, Bucket<T> parent, BucketNode<T> prev, BucketNode<T> next) { Value = item; Parent = parent; Prev = prev; Next = next; }
	public int Index
	{
		get
		{
			var count = 0;
			var node = Parent.Head;
			while (node != this) { node = node.Next; count++; }
			return count;
		}
	}
	public override string ToString() { return Value.ToString(); }
}
class UndirectedGraph<V, E> : DirectedGraph<V, E>
{
	public UndirectedGraph(int V) : base(V) { }
	public UndirectedGraph(int V, IEnumerable<EdgeInfo<E>> edges) : base(V, edges) { }
	public override void AddEdge(EdgeInfo<E> edge)
	{
		edges.Add(edge);
		edges.Add(edge.Reverse());
		edgesFrom[edge.From].Add(new HalfEdgeInfo<E>(edge.To, edge.Information));
		edgesFrom[edge.To].Add(new HalfEdgeInfo<E>(edge.From, edge.Information));
		edgesTo[edge.To].Add(new HalfEdgeInfo<E>(edge.From, edge.Information));
		edgesTo[edge.From].Add(new HalfEdgeInfo<E>(edge.To, edge.Information));
	}
	public bool IsConnected
	{
		get
		{
			if (numberOfNodes == 0) return true;
			var used = new bool[numberOfNodes];
			var queue = new Queue<int>();
			queue.Enqueue(0);
			while (queue.Count > 0)
			{
				var v = queue.Dequeue();
				if (used[v]) continue;
				used[v] = true;
				foreach (var e in EdgesFrom(v)) queue.Enqueue(e.End);
			}
			return used.All(x => x);
		}
	}
	public bool IsTree
	{
		get
		{
			if (numberOfNodes == 0) return true;
			var used = new bool[numberOfNodes];
			var queue = new Queue<int>();
			queue.Enqueue(0);
			while (queue.Count > 0)
			{
				var v = queue.Dequeue();
				if (used[v]) return false;
				used[v] = true;
				foreach (var e in EdgesFrom(v)) queue.Enqueue(e.End);
			}
			return used.All(x => x);
		}
	}
	public UndirectedGraph<V, E> MinimumSpanningTreePrim(int start, Func<E, int> cost)
	{
		var graph = new UndirectedGraph<V, E>(numberOfNodes);
		nodes.CopyTo(graph.nodes, 0);
		var d = Enumerable.Repeat(Func.Inf, numberOfNodes).ToArray();
		var used = new bool[numberOfNodes];
		var queue = new PriorityQueue<Pair<EdgeInfo<E>, int>>((x, y) => x.Second.CompareTo(y.Second), numberOfNodes);
		d[start] = 0;
		queue.Enqueue(new Pair<EdgeInfo<E>, int>(new EdgeInfo<E>(-1, 0, default(E)), 0));
		while (queue.Count > 0)
		{
			var p = queue.Dequeue();
			var v = p.First.To;
			if (d[v] < p.Second) continue;
			used[v] = true;
			if (p.First.From >= 0) graph.AddEdge(v, p.First.From, p.First.Information);
			foreach (var w in EdgesFrom(v))
			{
				if (!used[w.End] && cost(w.Information) < d[w.End])
				{
					d[w.End] = cost(w.Information);
					queue.Enqueue(new Pair<EdgeInfo<E>, int>(new EdgeInfo<E>(v, w.End, w.Information), cost(w.Information)));
				}
			}
		}
		return graph;
	}
	public UndirectedGraph<V, E> MinimumSpanningTreeKruskal(Func<E, int> cost)
	{
		var graph = new UndirectedGraph<V, E>(numberOfNodes);
		nodes.CopyTo(graph.nodes, 0);
		var tree = new UnionFindTree(numberOfNodes);
		edges.Sort((x, y) => cost(x.Information).CompareTo(cost(y.Information)));
		foreach (var e in edges)
		{
			if (!tree.IsSameCategory(e.From, e.To))
			{
				tree.UniteCategory(e.From, e.To);
				graph.AddEdge(e);
			}
		}
		return graph;
	}
	public bool IsBipartite
	{
		get
		{
			var color = new int[numberOfNodes];
			foreach (var v in nodes)
			{
				if (color[v.Code] == 0)
				{
					var queue = new Queue<Pair<int, int>>();
					queue.Enqueue(new Pair<int, int>(v.Code, 1));
					while (queue.Count > 0)
					{
						var w = queue.Dequeue();
						if (color[w.First] != 0)
						{
							if (color[w.First] != w.Second)
								return false;
							continue;
						}
						color[w.First] = w.Second;
						foreach (var e in EdgesFrom(w.First)) queue.Enqueue(new Pair<int, int>(e.End, -w.Second));
					}
				}
			}
			return true;
		}
	}
	public IEnumerable<NodeInfo<V>> GetArticulationPoints()
	{
		var visited = new bool[numberOfNodes];
		var parent = new int[numberOfNodes];
		var children = Enumerable.Range(0, numberOfNodes).Select(_ => new SortedSet<int>()).ToArray();
		var order = new int[numberOfNodes];
		var lowest = new int[numberOfNodes];
		var isroot = new bool[numberOfNodes];
		var count = 1;
		var isarticulation = new bool[numberOfNodes];
		Action<int, int> dfs = null;
		dfs = (u, prev) =>
		{
			order[u] = count;
			lowest[u] = count;
			count++;
			visited[u] = true;
			foreach (var e in edgesFrom[u])
			{
				var v = e.End;
				if (visited[v]) { if (v != prev) lowest[u] = Math.Min(lowest[u], order[v]); }
				else
				{
					parent[v] = u;
					if (isroot[u]) children[u].Add(v);
					dfs(v, u);
					lowest[u] = Math.Min(lowest[u], lowest[v]);
					if (order[u] <= lowest[v]) isarticulation[u] = true;
				}
			}
		};
		for (var v = 0; v < numberOfNodes; v++)
		{
			if (visited[v]) continue;
			count = 1; dfs(v, -1);
			isroot[v] = true;
		}
		for (var v = 0; v < numberOfNodes; v++)
		{
			if (isroot[v]) { if (children[v].Count > 1) yield return nodes[v]; }
			else { if (isarticulation[v]) yield return nodes[v]; }
		}
	}
	public string ToString(Func<NodeInfo<V>, string> vertex, Func<EdgeInfo<E>, string> edge)
	{
		var sb = new StringBuilder();
		sb.Append("graph G {\n");
		foreach (var v in nodes) sb.Append("\tv" + v.Code + " [label = \"" + vertex(v) + "\"];\n");
		foreach (var e in edges) sb.Append("\tv" + e.From + " -- v" + e.To + " [label=\"" + edge(e) + "\"];\n");
		sb.Append("}");
		return sb.ToString();
	}
	public override string ToString() { return ToString(v => v.ToString(), e => e.ToString()); }
}
class NodeInfo<V> : Pair<int, V>
{
	public int Code { get { return First; } set { First = value; } }
	public V Information { get { return Second; } set { Second = value; } }
	public NodeInfo() : base() { }
	public NodeInfo(int code, V info) : base(code, info) { }
}
class HalfEdgeInfo<E> : Pair<int, E>
{
	public int End { get { return First; } set { First = value; } }
	public E Information { get { return Second; } set { Second = value; } }
	public HalfEdgeInfo() : base() { }
	public HalfEdgeInfo(int end, E info) : base(end, info) { }
}
class EdgeInfo<E> : Pair<Pair<int, int>, E>
{
	public int From { get { return First.First; } set { First.First = value; } }
	public int To { get { return First.Second; } set { First.Second = value; } }
	public E Information { get { return Second; } set { Second = value; } }
	public EdgeInfo() : base() { }
	public EdgeInfo(int from, int to, E info) : base(new Pair<int, int>(from, to), info) { }
	public EdgeInfo<E> Reverse() { return new EdgeInfo<E>(To, From, Information); }
}
class DirectedGraph<V, E> : IEnumerable<NodeInfo<V>>
{
	protected int numberOfNodes;
	public int NumberOfNodes { get { return numberOfNodes; } }
	protected NodeInfo<V>[] nodes;
	protected List<EdgeInfo<E>> edges;
	protected List<HalfEdgeInfo<E>>[] edgesFrom;
	protected List<HalfEdgeInfo<E>>[] edgesTo;
	public IEnumerable<HalfEdgeInfo<E>> EdgesFrom(int node) { return edgesFrom[node]; }
	public int InDegree(int node) { return edgesTo[node].Count; }
	public int OutDegree(int node) { return edgesFrom[node].Count; }
	public IEnumerable<HalfEdgeInfo<E>> EdgesTo(int node) { return edgesTo[node]; }
	public V this[int node] { get { return nodes[node].Second; } set { nodes[node].Second = value; } }
	public IEnumerable<EdgeInfo<E>> Edges { get { return edges; } }
	public DirectedGraph(int V)
	{
		numberOfNodes = V;
		nodes = Enumerable.Range(0, V).Select(x => new NodeInfo<V>(x, default(V))).ToArray();
		edges = new List<EdgeInfo<E>>();
		edgesFrom = Enumerable.Range(0, V).Select(_ => new List<HalfEdgeInfo<E>>()).ToArray();
		edgesTo = Enumerable.Range(0, V).Select(_ => new List<HalfEdgeInfo<E>>()).ToArray();
	}
	public DirectedGraph(int V, IEnumerable<EdgeInfo<E>> edges) : this(V) { foreach (var e in edges) AddEdge(e.From, e.To, e.Information); }
	public virtual void AddEdge(EdgeInfo<E> edge)
	{
		edges.Add(edge);
		edgesFrom[edge.From].Add(new HalfEdgeInfo<E>(edge.To, edge.Information));
		edgesTo[edge.To].Add(new HalfEdgeInfo<E>(edge.From, edge.Information));
	}
	public void AddEdge(int from, int to, E information) { AddEdge(new EdgeInfo<E>(from, to, information)); }
	public void AddEdge(V from, V to, E information) { AddEdge(new EdgeInfo<E>(SearchNode(from).Code, SearchNode(to).Code, information)); }
	public NodeInfo<V> SearchNode(V node) { return nodes.FirstOrDefault(e => e.Information.Equals(node)); }
	public EdgeInfo<E> SearchEdge(E edge) { return edges.Find(e => e.Information.Equals(edge)); }
	public IEnumerator<NodeInfo<V>> GetEnumerator() { foreach (var v in nodes) yield return v; }
	IEnumerator IEnumerable.GetEnumerator() { return GetEnumerator(); }
	public int[] ShortestPathLengthFrom(int from, Func<E, int> cost)
	{
		var d = Enumerable.Repeat(Func.Inf, numberOfNodes).ToArray();
		d[from] = 0;
		var update = true;
		while (update)
		{
			update = false;
			foreach (var e in edges)
			{
				var tmp = d[e.From] + cost(e.Information);
				if (d[e.From] < Func.Inf && d[e.To] > tmp)
				{
					d[e.To] = tmp;
					update = true;
				}
			}
		}
		return d;
	}
	public int[] DijkstraFrom(int from, Func<E, int> cost)
	{
		var d = Enumerable.Repeat(Func.Inf, numberOfNodes).ToArray();
		var queue = new PriorityQueue<Pair<int, int>>((x, y) => x.Second.CompareTo(y.Second));
		d[from] = 0;
		queue.Enqueue(new Pair<int, int>(from, 0));
		while (!queue.IsEmpty)
		{
			var p = queue.Dequeue();
			var v = p.First;
			if (d[v] < p.Second) continue;
			foreach (var e in EdgesFrom(v))
			{
				var tmp = d[v] + cost(e.Information);
				if (d[e.End] > tmp) queue.Enqueue(new Pair<int, int>(e.End, d[e.End] = tmp));
			}
		}
		return d;
	}
	// cost(e)>=0
	public long[] DijkstraFromL(int from, Func<E, long> cost)
	{
		var d = Enumerable.Repeat(Func.InfL, numberOfNodes).ToArray();
		var queue = new PriorityQueue<Pair<int, long>>((x, y) => x.Second.CompareTo(y.Second));
		d[from] = 0;
		queue.Enqueue(new Pair<int, long>(from, 0));
		while (!queue.IsEmpty)
		{
			var p = queue.Dequeue();
			var v = p.First;
			if (d[v] < p.Second) continue;
			foreach (var e in EdgesFrom(v))
			{
				var tmp = d[v] + cost(e.Information);
				if (d[e.End] > tmp) queue.Enqueue(new Pair<int, long>(e.End, d[e.End] = tmp));
			}
		}
		return d;
	}
	public int[,] ShortestPathLengthEachOther(Func<E, int> cost)
	{
		var d = new int[numberOfNodes, numberOfNodes];
		for (var v = 0; v < numberOfNodes; v++) for (var w = 0; w < numberOfNodes; w++) d[v, w] = Func.Inf;
		for (var v = 0; v < numberOfNodes; v++) d[v, v] = 0;
		foreach (var e in edges) if (e.From != e.To) d[e.From, e.To] = cost(e.Information);
		for (var k = 0; k < numberOfNodes; k++)
			for (var v = 0; v < numberOfNodes; v++)
				for (var w = 0; w < numberOfNodes; w++)
					d[v, w] = Math.Min(d[v, w], d[v, k] + d[k, w]);
		return d;
	}
	public bool ContainsNegativeLoopWF(Func<E, int> cost)
	{
		var d = ShortestPathLengthEachOther(cost);
		for (var v = 0; v < numberOfNodes; v++) if (d[v, v] < 0) return true;
		return false;
	}
	public bool ContainsNegativeLoop(Func<E, int> cost)
	{
		var d = Enumerable.Repeat(0, numberOfNodes).ToArray();
		for (var v = 0; v < numberOfNodes; v++)
		{
			foreach (var e in edges)
			{
				var tmp = d[e.From] + cost(e.Information);
				if (d[e.To] > tmp)
				{
					d[e.To] = tmp;
					if (v == numberOfNodes - 1) return true;
				}
			}
		}
		return false;
	}
	public IEnumerable<int> ReachableFrom(int from)
	{
		var used = new bool[numberOfNodes];
		var queue = new Queue<int>();
		queue.Enqueue(from);
		while (queue.Count > 0)
		{
			var v = queue.Dequeue();
			if (used[v]) continue;
			used[v] = true;
			foreach (var e in EdgesFrom(v)) queue.Enqueue(e.End);
		}
		for (var v = 0; v < numberOfNodes; v++) if (used[v]) yield return v;
	}
	public bool IsReachable(int from, int to)
	{
		var used = new bool[numberOfNodes];
		var queue = new Queue<int>();
		queue.Enqueue(from);
		while (queue.Count > 0)
		{
			var v = queue.Dequeue();
			if (v == to) return true;
			if (used[v]) continue;
			used[v] = true;
			foreach (var e in EdgesFrom(v)) queue.Enqueue(e.End);
		}
		return false;
	}
	public Pair<DirectedGraph<HashSet<NodeInfo<V>>, object>, int[]> StronglyConnectedComponents()
	{
		var mark = new bool[numberOfNodes];
		var stack = new Stack<int>();
		Action<int> dfs = null;
		dfs = v =>
		{
			mark[v] = true;
			foreach (var w in edgesFrom[v]) if (!mark[w.End]) dfs(w.End);
			stack.Push(v);
		};
		for (var v = 0; v < numberOfNodes; v++) if (!mark[v]) dfs(v);
		var scc = new List<HashSet<NodeInfo<V>>>();
		mark = new bool[numberOfNodes];
		var which = new int[numberOfNodes];
		Action<int, HashSet<NodeInfo<V>>> rdfs = null;
		rdfs = (v, set) =>
		{
			set.Add(new NodeInfo<V>(v, nodes[v].Information));
			mark[v] = true;
			foreach (var w in edgesFrom[v]) if (!mark[w.End]) rdfs(w.End, set);
		};
		var M = 0;
		while (stack.Count > 0)
		{
			var v = stack.Pop();
			if (mark[v]) continue;
			var set = new HashSet<NodeInfo<V>>();
			rdfs(v, set);
			scc.Add(set);
			foreach (var w in set) which[w.Code] = M;
			M++;
		}
		var graph = new UndirectedGraph<HashSet<NodeInfo<V>>, object>(M);
		for (var v = 0; v < M; v++) graph[v] = scc[v];
		foreach (var e in edges) if (which[e.From] != which[e.To]) graph.AddEdge(which[e.From], which[e.To], null);
		return new Pair<DirectedGraph<HashSet<NodeInfo<V>>, object>, int[]>(graph, which);
	}
	public string ToString(Func<V, string> vertex, Func<E, string> edge)
	{
		var sb = new StringBuilder();
		sb.Append("digraph G {\n");
		foreach (var v in nodes) sb.Append("\tv" + v.Code + " [label = \"" + vertex(v.Information) + "\"];\n");
		foreach (var e in edges) sb.Append("\tv" + e.From + " -> v" + e.To + " [label=\"" + edge(e.Information) + "\"];\n");
		sb.Append("}");
		return sb.ToString();
	}
	public override string ToString() { return ToString(v => v.ToString(), e => e.ToString()); }
}
class UnionFindTree
{
	int N;
	int[] parent, rank, size;
	public UnionFindTree(int capacity)
	{
		N = capacity;
		parent = new int[N];
		rank = new int[N];
		size = new int[N];
		for (var i = 0; i < N; i++) { parent[i] = i; size[i] = 1; }
	}
	public int GetSize(int x) { return size[GetRootOf(x)]; }
	public int GetRootOf(int x) { return parent[x] == x ? x : parent[x] = GetRootOf(parent[x]); }
	public void UniteCategory(int x, int y)
	{
		if ((x = GetRootOf(x)) == (y = GetRootOf(y))) return;
		if (rank[x] < rank[y]) { parent[x] = y; size[y] += size[x]; }
		else
		{
			parent[y] = x; size[x] += size[y];
			if (rank[x] == rank[y]) rank[x]++;
		}
	}
	public bool IsSameCategory(int x, int y) { return GetRootOf(x) == GetRootOf(y); }
}
class AVLTree<T> : IEnumerable<T>, ICollection<T>, ICollection, IEnumerable
{
	public class AVLNode : IEnumerable<T>
	{
		AVLTree<T> tree;
		int height;
		public int Height { get { return height; } }
		public int Bias { get { return Left.height - Right.height; } }
		public T Item;
		public AVLNode Parent;
		public AVLNode Left;
		public AVLNode Right;
		AVLNode(T x, AVLTree<T> tree) { this.tree = tree; Item = x; Left = tree.sentinel; Right = tree.sentinel; }
		public AVLNode(AVLTree<T> tree) : this(default(T), tree) { height = 0; Parent = null; }
		public AVLNode(T x, AVLNode parent, AVLTree<T> tree) : this(x, tree) { this.height = 1; this.Parent = parent; }
		public void Adjust() { height = 1 + Math.Max(Left.height, Right.height); }
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
		IEnumerator IEnumerable.GetEnumerator() { return GetEnumerator(); }
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
		this.comp = comp == null ? Func.DefaultComparison<T>() : comp;
		if (typeof(T).IsValueType) equals = (x, y) => x.Equals(y);
		else equals = (x, y) => ReferenceEquals(x, y);
		count = 0;
	}
	public AVLTree(IComparer<T> comp = null) : this(comp.ToComparison()) { }
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
	public bool Remove(T item) { return Remove(item, sentinel.Left); }
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
	public AVLNode LowerBound(T item) { return LowerBound(x => comp(x, item) >= 0); }
	public AVLNode UpperBound(T item) { return UpperBound(x => comp(x, item) <= 0); }
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
	public T Min() { return Min(sentinel.Left).Item; }
	public AVLNode MinNode() { return Min(sentinel.Left); }
	public T Max() { return Max(sentinel.Left).Item; }
	public AVLNode MaxNode() { return Max(sentinel.Left); }
	public bool IsEmpty { get { return sentinel.Left == sentinel; } }
	public void Clear() { sentinel.Left = sentinel; count = 0; sentinel.ResetAsSentinel(); }
	public IEnumerator<T> GetEnumerator() { return sentinel.Left.GetEnumerator(); }
	IEnumerator IEnumerable.GetEnumerator() { return GetEnumerator(); }
	public void CopyTo(T[] array, int arrayIndex) { foreach (var x in this) array[arrayIndex++] = x; }
	public int Count { get { return count; } }
	public bool IsReadOnly { get { return true; } }
	public void CopyTo(Array array, int index) { foreach (var x in this) array.SetValue(x, index++); }
	public bool IsSynchronized { get { return false; } }
	public object SyncRoot { get { return this; } }
	public override string ToString()
	{
		var nodes = new StringBuilder();
		var edges = new StringBuilder();
		ConcatSubTree(nodes, edges, sentinel.Left, "L");
		return "digraph G {\n" + nodes.ToString() + edges.ToString() + "}";
	}
	void ConcatSubTree(StringBuilder nodes, StringBuilder edges, AVLNode node, string code)
	{
		if (node == sentinel) return;
		nodes.Append("\tv" + code + " [label = \"" + node.Height + ":" + node.Item + "\"];\n");
		if (node.Left != sentinel) edges.Append("\tv" + code + " -> v" + code + "L;\n");
		if (node.Right != sentinel) edges.Append("\tv" + code + " -> v" + code + "R;\n");
		ConcatSubTree(nodes, edges, node.Left, code + "L");
		ConcatSubTree(nodes, edges, node.Right, code + "R");
	}
	public bool IsBalanced() { return IsBalanced(sentinel.Left); }
	public bool IsValidBinarySearchTree() { return IsValidBinarySearchTree(sentinel.Left); }
	bool IsBalanced(AVLNode node) { return node == sentinel || (Math.Abs(node.Bias) < 2 && IsBalanced(node.Left) && IsBalanced(node.Right)); }
	bool IsValidBinarySearchTree(AVLNode node)
	{
		return node == sentinel || (Small(node.Item, node.Left) && Large(node.Item, node.Right)
			&& IsValidBinarySearchTree(node.Left) && IsValidBinarySearchTree(node.Right));
	}
	bool Small(T item, AVLNode node) { return node == sentinel || (comp(item, node.Item) >= 0 && Small(item, node.Left) && Small(item, node.Right)); }
	bool Large(T item, AVLNode node) { return node == sentinel || (comp(item, node.Item) <= 0 && Large(item, node.Left) && Large(item, node.Right)); }
	public static void CheckAVL(Random rand, int N)
	{
		Comparison<double> comp = (x, y) => x.CompareTo(y);
		var avl = new AVLTree<double>(comp);
		var toBeLeft = new double[N];
		var toBeRemoved = new double[N];
		for (var i = 0; i < N; i++) avl.Add(toBeRemoved[i] = rand.NextDouble());
		for (var i = 0; i < N; i++) avl.Add(toBeLeft[i] = rand.NextDouble());
		for (var i = 0; i < N; i++) Console.Write(avl.Remove(toBeRemoved[i]) ? "" : "!!!NOT REMOVED!!! => " + toBeRemoved[i] + "\n");
		var insertErrors = toBeLeft.All(x => avl.Contains(x));
		var deleteErrors = avl.Count == N;
		//Console.WriteLine("?AVL?????");
		//Console.WriteLine(avl);
		if (insertErrors && deleteErrors) Console.WriteLine("?\t??, ???????????????.");
		else if (insertErrors) Console.WriteLine("×\t??(?????)??????????.");
		else Console.WriteLine("×\t??(?????)??????????.");
		if (avl.IsBalanced()) Console.WriteLine("?\tAVL?????????????.");
		else Console.WriteLine("×\tAVL?????????????.");
		if (avl.IsValidBinarySearchTree()) Console.WriteLine("?\tAVL??????????????.");
		else Console.WriteLine("×\tAVL???????????????.");
		Array.Sort(toBeLeft, comp);
		Console.WriteLine("??? : " + avl.Min() + " ? " + toBeLeft.First());
		Console.WriteLine("??? : " + avl.Max() + " ? " + toBeLeft.Last());
		Console.WriteLine("??? : " + avl.Count + "?");
	}
}
class PriorityQueue<T> : IEnumerable<T>, ICollection, IEnumerable, ICloneable
{
	Comparison<T> comp;
	List<T> list;
	public int Count { get; private set; }
	public bool IsEmpty { get { return Count == 0; } }
	public PriorityQueue(IEnumerable<T> source) : this((Comparison<T>)null, 0, source) { }
	public PriorityQueue(int capacity = 0, IEnumerable<T> source = null) : this((Comparison<T>)null, capacity, source) { }
	public PriorityQueue(IComparer<T> comp, IEnumerable<T> source) : this(comp.ToComparison(), source) { }
	public PriorityQueue(IComparer<T> comp, int capacity = 0, IEnumerable<T> source = null) : this(comp.ToComparison(), source) { list.Capacity = capacity; }
	public PriorityQueue(Comparison<T> comp, IEnumerable<T> source) : this(comp, 0, source) { }
	public PriorityQueue(Comparison<T> comp, int capacity = 0, IEnumerable<T> source = null) { this.comp = comp == null ? Func.DefaultComparison<T>() : comp; list = new List<T>(capacity); if (source != null) foreach (var x in source) Enqueue(x); }
	/// <summary>
	/// add an item
	/// this is an O(log n) operation
	/// </summary>
	/// <param name="x">item</param>
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
	/// <summary>
	/// return the minimum element and remove it
	/// this is an O(log n) operation
	/// </summary>
	/// <returns>the minimum</returns>
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
	/// <summary>
	/// look at the minimum element
	/// this is an O(1) operation
	/// </summary>
	/// <returns>the minimum</returns>
	public T Peek() { return list[0]; }
	public IEnumerator<T> GetEnumerator() { var x = (PriorityQueue<T>)Clone(); while (x.Count > 0) yield return x.Dequeue(); }
	void CopyTo(Array array, int index) { foreach (var x in this) array.SetValue(x, index++); }
	public object Clone() { var x = new PriorityQueue<T>(comp, Count); x.list.AddRange(list); return x; }
	public void Clear() { list = new List<T>(); Count = 0; }
	public void TrimExcess() { list.TrimExcess(); }
	/// <summary>
	/// check whether item is in this queue
	/// this is an O(n) operation
	/// </summary>
	public bool Contains(T item) { return list.Contains(item); }
	IEnumerator IEnumerable.GetEnumerator() { return GetEnumerator(); }
	void ICollection.CopyTo(Array array, int index) { CopyTo(array, index); }
	bool ICollection.IsSynchronized { get { return false; } }
	object ICollection.SyncRoot { get { return this; } }
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
	public T PeekFront() { return array[offset]; }
	public T PeekBack() { return array[GetIndex(Count - 1)]; }
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
	public T PopBack() { return array[GetIndex(--Count)]; }
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
class PairComparer<S, T> : IComparer<Pair<S, T>>
	where S : IComparable<S>
	where T : IComparable<T>
{
	public PairComparer() { }
	public int Compare(Pair<S, T> x, Pair<S, T> y)
	{
		var p = x.First.CompareTo(y.First);
		if (p != 0) return p;
		else return x.Second.CompareTo(y.Second);
	}
}
class Pair<S, T>
{
	public S First;
	public T Second;
	public Pair() { First = default(S); Second = default(T); }
	public Pair(S s, T t) { First = s; Second = t; }
	public override string ToString() { return "(" + First + ", " + Second + ")"; }
	public override int GetHashCode() { return First.GetHashCode() ^ Second.GetHashCode(); }
	public override bool Equals(object obj)
	{
		if (ReferenceEquals(this, obj)) return true;
		else if (obj == null) return false;
		var tmp = obj as Pair<S, T>;
		return (object)tmp != null && First.Equals(tmp.First) && Second.Equals(tmp.Second);
	}
}
class Point : Pair<int, int>
{
	public int X { get { return First; } set { First = value; } }
	public int Y { get { return Second; } set { Second = value; } }
	public Point() : base(0, 0) { }
	public Point(int x, int y) : base(x, y) { }
	public IEnumerable<Point> Neighbors4()
	{
		yield return new Point(X - 1, Y);
		yield return new Point(X, Y - 1);
		yield return new Point(X, Y + 1);
		yield return new Point(X + 1, Y);
	}
	public IEnumerable<Point> Neighbors8()
	{
		yield return new Point(X - 1, Y - 1);
		yield return new Point(X - 1, Y);
		yield return new Point(X - 1, Y + 1);
		yield return new Point(X, Y - 1);
		yield return new Point(X, Y + 1);
		yield return new Point(X + 1, Y - 1);
		yield return new Point(X + 1, Y);
		yield return new Point(X + 1, Y + 1);
	}
	public static Point operator +(Point p) { return new Point(p.X, p.Y); }
	public static Point operator -(Point p) { return new Point(-p.X, -p.Y); }
	public static Point operator /(Point p, int r) { return new Point(p.X / r, p.Y / r); }
	public static Point operator *(int r, Point p) { return new Point(p.X * r, p.Y * r); }
	public static Point operator *(Point p, int r) { return new Point(p.X * r, p.Y * r); }
	public static Point operator +(Point p, Point q) { return new Point(p.X + q.X, p.Y + q.Y); }
	public static Point operator -(Point p, Point q) { return new Point(p.X - q.X, p.Y - q.Y); }
}
class Printer : IDisposable
{
	bool isConsole;
	TextWriter file;
	public Printer() { file = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false }; isConsole = true; }
	public Printer(string path) { file = new StreamWriter(path, false) { AutoFlush = false }; isConsole = false; }
	public void Write<T>(T value) { file.Write(value); }
	public void Write(bool b) { file.Write(b ? "YES" : "NO"); }
	public void Write(string str, params object[] args) { file.Write(str, args); }
	public void WriteLine() { file.WriteLine(); }
	public void WriteLine<T>(T value) { file.WriteLine(value); }
	public void WriteLine(bool b) { file.WriteLine(b ? "YES" : "NO"); }
	public void WriteLine<T>(IEnumerable<T> list) { foreach (var x in list) file.WriteLine(x); }
	public void WriteLine<T>(List<T> list) { foreach (var x in list) file.WriteLine(x); }
	public void WriteLine<T>(T[] list) { foreach (var x in list) file.WriteLine(x); }
	public void WriteLine(string str, params object[] args) { file.WriteLine(str, args); }
	public void Dispose() { file.Flush(); if (!isConsole) file.Dispose(); }
}
class Scanner : IDisposable
{
	bool isConsole;
	TextReader file;
	public Scanner() { file = Console.In; }
	public Scanner(string path) { file = new StreamReader(path); isConsole = false; }
	public void Dispose() { if (!isConsole) file.Dispose(); }
	public T Get<T>() { return (T)Convert(file.ReadLine(), Type.GetTypeCode(typeof(T))); }
	public int Int { get { return Get<int>(); } }
	public uint UInt { get { return Get<uint>(); } }
	public long Long { get { return Get<long>(); } }
	public ulong ULong { get { return Get<ulong>(); } }
	public double Double { get { return Get<double>(); } }
	public decimal Decimal { get { return Get<decimal>(); } }
	public char Char { get { return Get<char>(); } }
	public string String { get { return Get<string>(); } }
	public Tuple<S, T> Get<S, T>() { S s; T t; Read(out s, out t); return new Tuple<S, T>(s, t); }
	public Tuple<S, T, U> Get<S, T, U>() { S s; T t; U u; Read(out s, out t, out u); return new Tuple<S, T, U>(s, t, u); }
	public Tuple<S, T, U, V> Get<S, T, U, V>() { S s; T t; U u; V v; Read(out s, out t, out u, out v); return new Tuple<S, T, U, V>(s, t, u, v); }
	public Tuple<S, T, U, V, W> Get<S, T, U, V, W>() { S s; T t; U u; V v; W w; Read(out s, out t, out u, out v, out w); return new Tuple<S, T, U, V, W>(s, t, u, v, w); }
	public Tuple<S, T, U, V, W, X> Get<S, T, U, V, W, X>() { S s; T t; U u; V v; W w; X x; Read(out s, out t, out u, out v, out w, out x); return new Tuple<S, T, U, V, W, X>(s, t, u, v, w, x); }
	public Tuple<S, T, U, V, W, X, Y> Get<S, T, U, V, W, X, Y>() { S s; T t; U u; V v; W w; X x; Y y; Read(out s, out t, out u, out v, out w, out x, out y); return new Tuple<S, T, U, V, W, X, Y>(s, t, u, v, w, x, y); }
	public Tuple<S, T, U, V, W, X, Y, Z> Get<S, T, U, V, W, X, Y, Z>() { S s; T t; U u; V v; W w; X x; Y y; Z z; Read(out s, out t, out u, out v, out w, out x, out y, out z); return new Tuple<S, T, U, V, W, X, Y, Z>(s, t, u, v, w, x, y, z); }
	public Pair<S, T> Pair<S, T>() { S s; T t; Read(out s, out t); return new Pair<S, T>(s, t); }
	object Convert(string str, TypeCode type)
	{
		if (type == TypeCode.Int32) return int.Parse(str);
		else if (type == TypeCode.UInt32) return uint.Parse(str);
		else if (type == TypeCode.Int64) return long.Parse(str);
		else if (type == TypeCode.UInt64) return ulong.Parse(str);
		else if (type == TypeCode.Double) return double.Parse(str);
		else if (type == TypeCode.Decimal) return decimal.Parse(str);
		else if (type == TypeCode.Char) return str[0];
		else if (type == TypeCode.String) return str;
		else if (type == Type.GetTypeCode(typeof(Point))) { int s, t; Read(out s, out t); return new Point(s, t); }
		else throw new Exception();
	}
	public T[] ReadMany<T>() { var type = Type.GetTypeCode(typeof(T)); return file.ReadLine().Split(sep, StringSplitOptions.RemoveEmptyEntries).Select(str => (T)Convert(str, type)).ToArray(); }
	public T[] ReadMany<T>(int n) { var type = Type.GetTypeCode(typeof(T)); return file.ReadLine().Split(sep, StringSplitOptions.RemoveEmptyEntries).Take(n).Select(str => (T)Convert(str, type)).ToArray(); }
	public T[] ReadManyLines<T>(int n, Func<T> selector) { return Enumerable.Range(0, n).Select(_ => selector()).ToArray(); }
	public T[] ReadManyLines<T>(int n) { return Enumerable.Range(0, n).Select(_ => Get<T>()).ToArray(); }
	public Tuple<S, T>[] ReadManyLines<S, T>(int n) { return Enumerable.Range(0, n).Select(_ => Get<S, T>()).ToArray(); }
	public Tuple<S, T, U>[] ReadManyLines<S, T, U>(int n) { return Enumerable.Range(0, n).Select(_ => Get<S, T, U>()).ToArray(); }
	public Tuple<S, T, U, V>[] ReadManyLines<S, T, U, V>(int n) { return Enumerable.Range(0, n).Select(_ => Get<S, T, U, V>()).ToArray(); }
	public Tuple<S, T, U, V, W>[] ReadManyLines<S, T, U, V, W>(int n) { return Enumerable.Range(0, n).Select(_ => Get<S, T, U, V, W>()).ToArray(); }
	public Tuple<S, T, U, V, W, X>[] ReadManyLines<S, T, U, V, W, X>(int n) { return Enumerable.Range(0, n).Select(_ => Get<S, T, U, V, W, X>()).ToArray(); }
	public Tuple<S, T, U, V, W, X, Y>[] ReadManyLines<S, T, U, V, W, X, Y>(int n) { return Enumerable.Range(0, n).Select(_ => Get<S, T, U, V, W, X, Y>()).ToArray(); }
	public Tuple<S, T, U, V, W, X, Y, Z>[] ReadManyLines<S, T, U, V, W, X, Y, Z>(int n) { return Enumerable.Range(0, n).Select(_ => Get<S, T, U, V, W, X, Y, Z>()).ToArray(); }
	public T[,] ReadManyManyLines<T>(int X, int Y)
	{
		var array = new T[X, Y];
		for (var y = 0; y < Y; y++) { var tmp = ReadMany<T>(X); for (var x = 0; x < X; x++) array[x, y] = tmp[x]; }
		return array;
	}
	public void Read<S>(out S s)
	{
		var read = ReadMulti(Type.GetTypeCode(typeof(S))).ToArray();
		s = (S)read[0];
	}
	public void Read<S, T>(out S s, out T t)
	{
		var read = ReadMulti(Type.GetTypeCode(typeof(S)), Type.GetTypeCode(typeof(T))).ToArray();
		s = (S)read[0];
		t = (T)read[1];
	}
	public void Read<S, T, U>(out S s, out T t, out U u)
	{
		var read = ReadMulti(Type.GetTypeCode(typeof(S)), Type.GetTypeCode(typeof(T)), Type.GetTypeCode(typeof(U))).ToArray();
		s = (S)read[0];
		t = (T)read[1];
		u = (U)read[2];
	}
	public void Read<S, T, U, V>(out S s, out T t, out U u, out V v)
	{
		var read = ReadMulti(Type.GetTypeCode(typeof(S)), Type.GetTypeCode(typeof(T)), Type.GetTypeCode(typeof(U)), Type.GetTypeCode(typeof(V))).ToArray();
		s = (S)read[0];
		t = (T)read[1];
		u = (U)read[2];
		v = (V)read[3];
	}
	public void Read<S, T, U, V, W>(out S s, out T t, out U u, out V v, out W w)
	{
		var read = ReadMulti(Type.GetTypeCode(typeof(S)), Type.GetTypeCode(typeof(T)),
			Type.GetTypeCode(typeof(U)), Type.GetTypeCode(typeof(V)), Type.GetTypeCode(typeof(W))).ToArray();
		s = (S)read[0];
		t = (T)read[1];
		u = (U)read[2];
		v = (V)read[3];
		w = (W)read[4];
	}
	public void Read<S, T, U, V, W, X>(out S s, out T t, out U u, out V v, out W w, out X x)
	{
		var read = ReadMulti(Type.GetTypeCode(typeof(S)), Type.GetTypeCode(typeof(T)),
			Type.GetTypeCode(typeof(U)), Type.GetTypeCode(typeof(V)), Type.GetTypeCode(typeof(W)), Type.GetTypeCode(typeof(X))).ToArray();
		s = (S)read[0];
		t = (T)read[1];
		u = (U)read[2];
		v = (V)read[3];
		w = (W)read[4];
		x = (X)read[5];
	}
	public void Read<S, T, U, V, W, X, Y>(out S s, out T t, out U u, out V v, out W w, out X x, out Y y)
	{
		var read = ReadMulti(Type.GetTypeCode(typeof(S)), Type.GetTypeCode(typeof(T)),
			Type.GetTypeCode(typeof(U)), Type.GetTypeCode(typeof(V)), Type.GetTypeCode(typeof(W)), Type.GetTypeCode(typeof(X)), Type.GetTypeCode(typeof(Y))).ToArray();
		s = (S)read[0];
		t = (T)read[1];
		u = (U)read[2];
		v = (V)read[3];
		w = (W)read[4];
		x = (X)read[5];
		y = (Y)read[6];
	}
	public void Read<S, T, U, V, W, X, Y, Z>(out S s, out T t, out U u, out V v, out W w, out X x, out Y y, out Z z)
	{
		var read = ReadMulti(Type.GetTypeCode(typeof(S)), Type.GetTypeCode(typeof(T)),
			Type.GetTypeCode(typeof(U)), Type.GetTypeCode(typeof(V)), Type.GetTypeCode(typeof(W)),
			Type.GetTypeCode(typeof(X)), Type.GetTypeCode(typeof(Y)), Type.GetTypeCode(typeof(Z))).ToArray();
		s = (S)read[0];
		t = (T)read[1];
		u = (U)read[2];
		v = (V)read[3];
		w = (W)read[4];
		x = (X)read[5];
		y = (Y)read[6];
		z = (Z)read[7];
	}
	static char[] sep = new char[] { ' ' };
	IEnumerable<object> ReadMulti(params TypeCode[] types)
	{
		var input = file.ReadLine().Split(sep, StringSplitOptions.RemoveEmptyEntries);
		for (var i = 0; i < types.Length; i++) yield return Convert(input[i], types[i]);
	}
	public T[,] Board<T>(int X, int Y, Func<char, int, int, T> selector)
	{
		var array = new T[X, Y];
		for (var y = 0; y < Y; y++)
		{
			var str = Get<string>();
			for (var x = 0; x < X; x++) array[x, y] = selector(str[x], x, y);
		}
		return array;
	}
}
static class Func
{
	public const int Inf = 1073741789;  // 2 * Inf < int.MaxValue, and Inf is a prime number
	public const long InfL = 4011686018427387913L;  // 2 * InfL < long.MaxValue, and InfL is a prime number
	public static Comparison<T> DefaultComparison<T>() { return (x, y) => Comparer<T>.Default.Compare(x, y); }
	public static Comparison<T> ToComparison<T>(this IComparer<T> comp) { return comp == null ? DefaultComparison<T>() : (x, y) => comp.Compare(x, y); }
	/// <summary>
	/// Find the first number x such that pred(x) is true
	/// if pred(x) is false for all min&lt;=x&lt;max, then return max
	/// in other words, pred(max) is assumed to be true
	/// </summary>
	/// <param name="min">inclusive lower limit</param>
	/// <param name="max">exclusive upper limit</param>
	/// <param name="pred">monotonous predicate, i.e. if pred(a) and a&lt;b, then pred(b)</param>
	/// <returns>first number such that satisfy pred</returns>
	public static long FirstBinary(long min, long max, Predicate<long> pred)
	{
		while (min < max)
		{
			var mid = (min + max) / 2;
			if (pred(mid)) max = mid;
			else min = mid + 1;
		}
		return min;
	}
	/// <summary>
	/// Find the first number x such that pred(x) is true
	/// if pred(x) is false for all min&lt;=x&lt;max, then return max
	/// in other words, pred(max) is assumed to be true
	/// </summary>
	/// <param name="min">inclusive lower limit</param>
	/// <param name="max">exclusive upper limit</param>
	/// <param name="pred">monotonous predicate, i.e. if pred(a) and a&lt;b, then pred(b)</param>
	/// <returns>first number such that satisfy pred</returns>
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
	public static Dictionary<T, S> Reverse<S, T>(this IDictionary<S, T> dict)
	{
		var r = new Dictionary<T, S>();
		foreach (var t in dict) r.Add(t.Value, t.Key);
		return r;
	}
	public static void Swap<T>(this IList<T> array, int i, int j) { var tmp = array[i]; array[i] = array[j]; array[j] = tmp; }
	public static void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
	public static T IndexAt<T>(this T[,] array, Pair<int, int> index) { return array[index.First, index.Second]; }
	public static bool InRegion(this Pair<int, int> p, int X, int Y) { return p.InRegion(0, X, 0, Y); }
	public static bool InRegion(this Pair<int, int> p, int x, int X, int y, int Y) { return p.First >= x && p.Second >= y && p.First < X && p.Second < Y; }
	/// <summary>
	/// get all permutation of 0, 1, ..., n - 1
	/// </summary>
	/// <param name="n">length of array</param>
	/// <param name="func">if you want to change the elements of the array, you must take a copy</param>
	public static void Permutation(int n, Action<int[]> func)
	{
		var array = new int[n];
		var unused = new bool[n];
		for (var i = 0; i < n; i++) unused[i] = true;
		Permutation(n, 0, array, unused, func);
	}
	static void Permutation(int n, int i, int[] array, bool[] unused, Action<int[]> func)
	{
		if (i == n) func(array);
		else
			for (var x = 0; x < n; x++)
				if (unused[x])
				{
					array[i] = x;
					unused[x] = false;
					Permutation(n, i + 1, array, unused, func);
					unused[x] = true;
				}
	}
	public static long Fact(int n)
	{
		var fact = 1L;
		for (var i = 2; i <= n; i++) fact *= i;
		return fact;
	}
	public static Dictionary<long, int> Factorize(this long n)
	{
		var d = new Dictionary<long, int>();
		for (var i = 2L; i * i <= n; i++)
			if (n % i == 0)
			{
				d.Add(i, 0);
				while (n % i == 0) { n /= i; d[i]++; }
			}
		if (n > 1) d.Add(n, 1);
		return d;
	}
	public static long LCM(long n, long m) { return Math.Abs((n / GCD(n, m)) * m); }
	public static long Divide(long n, long m) { return (n - Remainder(n, m)) / m; }
	public static long Remainder(long n, long m)
	{
		if (m == 0) throw new DivideByZeroException();
		else if (m < 0) return Remainder(n, -m);
		else
		{
			var r = n % m;
			return r < 0 ? r + m : r;
		}
	}
	public static long Recurrence(long[] coeff, long[] init, long N, long mod)
	{
		var K = init.Length;
		if (N < 0)
		{
			var inv = Inverse(coeff[0], mod);
			var rc = new long[K];
			for (var i = 1; i < K; i++) rc[K - i] = -coeff[i] * inv % mod;
			rc[0] = inv;
			var ri = new long[K];
			for (var i = 0; i < K; i++) ri[K - 1 - i] = init[i];
			return Recurrence(rc, ri, K - 1 - N, mod);
		}
		var tmp = new long[K];
		Recurrence(coeff, init, tmp, N, mod);
		var sum = 0L;
		for (var i = 0; i < K; i++) sum += init[i] * tmp[i] % mod;
		sum %= mod;
		if (sum < 0) sum += mod;
		return sum;
	}
	public static void Recurrence(long[] coeff, long[] init, long[] state, long N, long mod)
	{
		var K = init.Length;
		if (N < K) state[N] = init[N];
		else if ((N & 1) == 0)
		{
			var tmp = new long[K][];
			for (var i = 0; i < K; i++) tmp[i] = new long[K];
			Recurrence(coeff, init, tmp[0], N / 2, mod);
			for (var i = 1; i < K; i++) tmp[i] = Next(coeff, tmp[i - 1], mod);
			for (var i = 0; i < K; i++)
			{
				state[i] = 0;
				for (var j = 0; j < K; j++) state[i] += tmp[0][j] * tmp[j][i] % mod;
				state[i] %= mod;
			}
		}
		else if (N < 2 * K || (N & 2) == 0)
		{
			var tmp = new long[K];
			Recurrence(coeff, init, tmp, N - 1, mod);
			tmp = Next(coeff, tmp, mod);
			for (var i = 0; i < K; i++) state[i] = tmp[i];
		}
		else
		{
			var tmp = new long[K];
			Recurrence(coeff, init, tmp, N + 1, mod);
			tmp = Prev(coeff, tmp, mod);
			for (var i = 0; i < K; i++) state[i] = tmp[i];
		}
	}
	static long[] Next(long[] coeff, long[] state, long mod)
	{
		var K = coeff.Length;
		var tmp = new long[K];
		for (var i = 0; i < K; i++) tmp[i] = coeff[i] * state[K - 1] % mod;
		for (var i = 1; i < K; i++) tmp[i] = (tmp[i] + state[i - 1]) % mod;
		return tmp;
	}
	static long[] Prev(long[] coeff, long[] state, long mod)
	{
		var K = coeff.Length;
		var tmp = new long[K];
		var inv = Inverse(coeff[0], mod);
		tmp[K - 1] = state[0] * inv % mod;
		for (var i = 1; i < K; i++) tmp[i - 1] = (state[i] - coeff[i] * tmp[K - 1] % mod) % mod;
		return tmp;
	}
	// get all primes less than or equal to n
	public static List<int> GetPrimes(int n)
	{
		if (n < 3) n = 3;
		var m = (n - 1) >> 1;
		var primes = new List<int>((int)(n / Math.Log(n)));
		primes.Add(2);
		var composites = new bool[m];
		composites[0] = false;
		for (var p = 0; p < m; p++)
		{
			if (!composites[p])
			{
				var pnum = 2 * p + 3;
				primes.Add(pnum);
				for (var k = 3 * p + 3; k < m; k += pnum) composites[k] = true;
			}
		}
		return primes;
	}
	/// <summary>
	/// solve nx+my=1 and returns (x,y)
	/// </summary>
	/// <param name="n">assumed to be with m</param>
	/// <param name="m">assumed to be with n</param>
	/// <returns>(x,y) where nx+my=1</returns>
	public static Tuple<long, long> SolveLinear(long n, long m)
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
	public static int GCD(int n, int m)
	{
		var a = Math.Abs(n);
		var b = Math.Abs(m);
		if (a < b) { var c = a; a = b; b = c; }
		while (b > 0)
		{
			var c = a % b;
			a = b;
			b = c;
		}
		return a;
	}
	/*public static long GCD(long n, long m)
	{
		var a = Math.Abs(n);
		var b = Math.Abs(m);
		if (a < b) { var c = a; a = b; b = c; }
		while (b > 0)
		{
			var c = a % b;
			a = b;
			b = c;
		}
		return a;
	}*/
	public static long GCD(long a, long b)
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
	public static BigInteger GCD(BigInteger a, BigInteger b) { return BigInteger.GreatestCommonDivisor(a, b); }
	public static long Inverse(long a, long mod)
	{
		if (a < 0) { a %= mod; if (a < 0) a += mod; }
		var t = SolveLinear(a, mod);
		return t.Item1 > 0 ? t.Item1 : t.Item1 + mod;
	}
	public static ulong Pow(ulong a, ulong b, ulong mod)
	{
		var p = 1uL;
		var x = a;
		while (b > 0)
		{
			if ((b & 1) == 1) p = (p * x) % mod;
			b >>= 1;
			x = (x * x) % mod;
		}
		return p;
	}
	public static long Pow(long a, long b, long mod)
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
	public static long Pow(long a, long b)
	{
		if (a == 1) return 1;
		else if (a == 0) { if (b >= 0) return 0; else throw new DivideByZeroException(); }
		else if (b < 0) return 0;
		var p = 1L;
		var x = a;
		while (b > 0)
		{
			if ((b & 1) == 1) p *= x;
			b >>= 1;
			x *= x;
		}
		return p;
	}
	public static ulong Pow(ulong a, ulong b)
	{
		var p = 1ul;
		var x = a;
		while (b > 0)
		{
			if ((b & 1) == 1) p *= x;
			b >>= 1;
			x *= x;
		}
		return p;
	}
	public static long ChineseRemainder(Tuple<long, long> modRemainder1, Tuple<long, long> modRemainder2)
	{
		var m1 = modRemainder1.Item1;
		var m2 = modRemainder2.Item1;
		var a1 = modRemainder1.Item2;
		var a2 = modRemainder2.Item2;
		var t = SolveLinear(m1, m2);
		var n1 = t.Item1;
		var n2 = t.Item2;
		return (m1 * n1 * a2 + m2 * n2 * a1) % (m1 * m2);
	}
	public static long ChineseRemainder(params Tuple<long, long>[] modRemainder)
	{
		if (modRemainder.Length == 0) throw new DivideByZeroException();
		else if (modRemainder.Length == 1) return modRemainder[0].Item2;
		else if (modRemainder.Length == 2) return ChineseRemainder(modRemainder[0], modRemainder[1]);
		else
		{
			var tuple = new Tuple<long, long>(1, 0);
			for (var i = 0; i < modRemainder.Length; i++)
			{
				var tmp = ChineseRemainder(tuple, modRemainder[i]);
				tuple = new Tuple<long, long>(tuple.Item1 * modRemainder[i].Item1, tmp);
			}
			return tuple.Item2;
		}
	}
	// forward transform -> theta= 2*PI/n
	// reverse transform -> theta=-2*PI/n, and use a[i]/n instead of a
	// O(n*log(n))
	public static void FastFourierTransform(int n, double theta, Complex[] a)
	{
		for (var m = n; m >= 2; m >>= 1)
		{
			var mh = m >> 1;
			for (var i = 0; i < mh; i++)
			{
				var w = Complex.Exp(i * theta * Complex.ImaginaryOne);
				for (var j = i; j < n; j += m)
				{
					var k = j + mh;
					var x = a[j] - a[k];
					a[j] += a[k];
					a[k] = w * x;
				}
			}
			theta *= 2;
		}
		var s = 0;
		for (var j = 1; j < n - 1; j++)
		{
			for (var k = n >> 1; k > (s ^= k); k >>= 1) ;
			if (j < s) a.Swap(s, j);
		}
	}
	// get table of Euler function
	// let return value f, f[i]=phi(i) for 0<=i<=n
	// nearly O(n)
	public static long[] EulerFunctionTable(long n)
	{
		if (n < 2) n = 2;
		var f = new long[n + 1];
		for (var i = 0L; i <= n; i++) f[i] = i;
		for (var i = 2L; i <= n; i++) if (f[i] == i) for (var j = i; j <= n; j += i) f[j] = f[j] / i * (i - 1);
		return f;
	}
	// O(sqrt(n))
	public static long EulerFunction(long n)
	{
		var res = n;
		for (var i = 2L; i * i <= n; i++)
			if (n % i == 0)
			{
				res = res / i * (i - 1);
				do n /= i; while (n % i == 0);
			}
		if (n != 1) res = res / n * (n - 1);
		return res;
	}
	// get moebius function of d s.t. 0<=d<=n
	// O(n)
	public static int[] MoebiusFunctionTable(long n)
	{
		if (n < 2) n = 2;
		var f = new int[n + 1];
		var p = new bool[n + 1];
		for (var i = 0L; i <= n; i++) f[i] = 1;
		for (var i = 2L; i <= n; i++) if (!p[i])
			{
				for (var j = i; j <= n; j += i) { f[j] *= -1; p[j] = true; }
				for (var j = i * i; j <= n; j += i * i) f[j] = 0;
			}
		return f;
	}
	// get moebius function of d s.t. d|n
	// if dict.ContainsKey(d), dict[d]!=0, otherwise moebius function of d is 0
	// O(sqrt(n))
	public static Dictionary<long, int> MoebiusFunctionOfDivisors(long n)
	{
		var ps = new List<long>();
		for (var i = 2L; i * i <= n; i++)
			if (n % i == 0)
			{
				ps.Add(i);
				do n /= i; while (n % i == 0);
			}
		if (n != 1) ps.Add(n);
		var dict = new Dictionary<long, int>();
		var m = ps.Count;
		for (var i = 0; i < (1 << m); i++)
		{
			var mu = 1;
			var k = 1L;
			for (var j = 0; j < m; j++) if ((i & (1 << j)) != 0) { mu *= -1; k *= ps[j]; }
			dict.Add(k, mu);
		}
		return dict;
	}
	// O(sqrt(n))
	public static int MoebiusFunction(long n)
	{
		var mu = 1;
		for (var i = 2L; i * i <= n; i++)
			if (n % i == 0)
			{
				mu *= -1;
				if ((n /= i) % i == 0) return 0;
			}
		return n == 1 ? mu : -mu;
	}
	// O(sqrt(n))
	public static long CarmichaelFunction(long n)
	{
		var lambda = 1L;
		var c = 0;
		while (n % 2 == 0) { n /= 2; c++; }
		if (c == 2) lambda = 2; else if (c > 2) lambda = 1 << (c - 2);
		for (var i = 3L; i * i <= n; i++)
			if (n % i == 0)
			{
				var tmp = i - 1;
				n /= i;
				while (n % i == 0) { n /= i; tmp *= i; }
				lambda = LCM(lambda, tmp);
			}
		if (n != 1) lambda = LCM(lambda, n - 1);
		return lambda;
	}
	// a+bi is Gaussian prime or not
	public static bool IsGaussianPrime(ulong a, ulong b)
	{
		if (a == 0) return b % 4 == 3 && IsPrime(b);
		else if (b == 0) return a % 4 == 3 && IsPrime(a);
		else return IsPrime(a * a + b * b);
	}
	// nearly O(200)
	public static bool IsPrime(ulong n)
	{
		if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
		var test = new uint[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 111 };
		var d = n - 1;
		int s = 0;
		while (d % 2 == 0) { ++s; d /= 2; }
		Predicate<ulong> f = t =>
		{
			var x = Pow(t, d, n);
			if (x == 1) return true;
			for (var r = 0L; r < s; r++)
			{
				if (x == n - 1) return true;
				x = (x * x) % n;
			}
			return false;
		};
		for (var i = 0; test[i] < n && test[i] != 111; i++) if (!f(test[i])) return false;
		return true;
	}
	public static decimal MeasureTime(Action action)
	{
		var sw = new System.Diagnostics.Stopwatch();
		sw.Restart();
		action();
		sw.Stop();
		return sw.ElapsedTicks * 1000m / System.Diagnostics.Stopwatch.Frequency;
	}
	static readonly double GoldenRatio = 2 / (3 + Math.Sqrt(5));
	// assume f is ?
	// find c s.t. a<=c<=b and for all a<=x<=b, f(c)<=f(x)
	public static double GoldenSectionSearch(double a, double b, Func<double, double> f)
	{
		double c = a + GoldenRatio * (b - a), d = b - GoldenRatio * (b - a);
		double fc = f(c), fd = f(d);
		while (d - c > 1e-9)
		{
			if (fc > fd)
			{
				a = c; c = d; d = b - GoldenRatio * (b - a);
				fc = fd; fd = f(d);
			}
			else
			{
				b = d; d = c; c = a + GoldenRatio * (b - a);
				fd = fc; fc = f(c);
			}
		}
		return c;
	}
	// O(NW)
	public static int KnapsackW(int[] w, int[] v, int W)
	{
		var N = w.Length;
		var dp = new int[W + 1];
		for (var i = 0; i < N; i++) for (var j = W; j >= w[i]; j--)
				dp[j] = Math.Max(dp[j], v[i] + dp[j - w[i]]);
		return dp[W];
	}
	// O(NV)
	public static int KnapsackV(int[] w, int[] v, int W)
	{
		var N = w.Length;
		var V = v.Sum();
		var dp = new int[V + 1];
		for (var i = 1; i <= V; i++) dp[i] = Inf;
		for (var i = 0; i < N; i++) for (var j = V; j >= v[i]; j--)
				dp[j] = Math.Min(dp[j], w[i] + dp[j - v[i]]);
		for (var j = V; j >= 0; j--) if (dp[j] <= W) return j;
		return 0;
	}
	// O(N*2^(N/2))
	public static long KnapsackN(long[] w, long[] v, int W)
	{
		var N = w.Length;
		var half = N / 2;
		var items = new Tuple<long, long>[N];
		for (var i = 0; i < N; i++) items[i] = new Tuple<long, long>(w[i], v[i]);
		Array.Sort(items, (x, y) => x.Item1.CompareTo(y.Item1));
		Func<int, int, List<Pair<long, long>>> gen = (start, end) =>
		{
			if (start >= end) return new List<Pair<long, long>>();
			var lim = 1 << (end - start);
			var list = new List<Pair<long, long>>();
			for (var i = 0; i < lim; i++)
			{
				var weight = 0L;
				var value = 0L;
				var tmp = i;
				for (var j = start; j < end; j++)
				{
					if ((tmp & 1) == 1) { weight += items[j].Item1; value += items[j].Item2; }
					tmp >>= 1;
				}
				if (weight <= W) list.Add(new Pair<long, long>(weight, value));
			}
			list.Sort((x, y) => { var c = x.First.CompareTo(y.First); return c == 0 ? x.Second.CompareTo(y.Second) : c; });
			var n = list.Count;
			if (n == 0) return list;
			for (var i = list.Count - 2; i >= 0; i--) if (list[i].First == list[i + 1].First) list[i].Second = Math.Max(list[i].Second, list[i + 1].Second);
			var small = new List<Pair<long, long>>();
			var last = -1;
			while (last + 1 < n)
			{
				var tmp = list[last + 1].First;
				last = Func.FirstBinary(last + 1, n, x => list[x].First > tmp) - 1;
				if (small.Count == 0 || list[last].Second > small[small.Count - 1].Second) small.Add(list[last]);
			}
			return small;
		};
		var first = gen(0, half);
		var second = gen(half, N);
		var max = 0L;
		var last2 = second.Count;
		foreach (var item in first)
		{
			last2 = Func.FirstBinary(0, last2, x => second[x].First > W - item.First) - 1;
			if (last2 < 0) break;
			if (second[last2].First <= W - item.First) Func.SetToMax(ref max, item.Second + second[last2].Second);
			last2++;
		}
		return max;
	}
	// nums[i] ? counts[i] ?
	// K is partial sum?
	// O(NK)
	public static bool PartialSum(int[] nums, int[] counts, int K)
	{
		var N = nums.Length;
		var memo = new int[K + 1];
		for (var s = 1; s <= K; s++) memo[s] = -1;
		for (var n = 0; n < N; n++) for (var s = 0; s <= K; s++) memo[s] = memo[s] >= 0 ? counts[n] : s < nums[n] ? -1 : memo[s - nums[n]] - 1;
		return memo[K] >= 0;
	}
	// O(N log(N))
	public static int LongestIncreasingSubsequence(int[] a)
	{
		var N = a.Length;
		var memo = new int[N];
		for (var n = 0; n < N; n++) memo[n] = Inf;
		for (var n = 0; n < N; n++)
		{
			var k = Func.FirstBinary(0, N, x => a[n] <= memo[x]);
			memo[k] = a[n];
		}
		return Func.FirstBinary(0, N, x => memo[x] == Inf);
	}
	// O(nm)
	public static int LongestCommonSubsequence(string s, string t)
	{
		var n = s.Length;
		var m = t.Length;
		var memo = new int[n + 1, m + 1];
		for (int i = n - 1; i >= 0; i--)
			for (int j = m - 1; j >= 0; j--)
				if (s[i] == t[j]) memo[i, j] = memo[i + 1, j + 1] + 1;
				else memo[i, j] = Math.Max(memo[i + 1, j], memo[i, j + 1]);
		return memo[0, 0];
	}
	// the number of ways of dividing N to M numbers
	// O(NM)
	public static int Partition(int N, int M, int Mod)
	{
		var memo = new long[N + 1, M + 1];
		for (var m = 0; m <= M; m++) memo[0, m] = 1;
		for (var n = 1; n <= N; n++)
		{
			memo[n, 0] = 0;
			for (var m = 1; m <= M; m++) memo[n, m] = (memo[n, m - 1] + (n - m >= 0 ? memo[n - m, m] : 0)) % Mod;
		}
		return (int)memo[N, M];
	}
	// max{f(a)+...+f(b-1) | from<=a<b<=to}
	// O(to-from)
	public static long MaxIntervalSum(int from, int to, Func<long, long> f)
	{
		long max, dp;
		max = dp = f(from);
		for (var i = from + 1; i < to; i++)
		{
			var tmp = f(i);
			dp = tmp + Math.Max(0, dp);
			max = Math.Max(max, dp);
		}
		return max;
	}
	public static int MaxElement<T>(this IEnumerable<T> source, Comparison<T> comp)
	{
		var p = source.GetEnumerator();
		if (!p.MoveNext()) return -1;
		var max = p.Current;
		var mi = 0;
		var i = 0;
		while (p.MoveNext())
		{
			i++;
			if (comp(max, p.Current) < 0)
			{
				max = p.Current;
				mi = i;
			}
		}
		return mi;
	}
	public static int MaxElement<T>(this IEnumerable<T> source) where T : IComparable<T> { return source.MaxElement((x, y) => x.CompareTo(y)); }
	public static int MinElement<T>(IEnumerable<T> source, Comparison<T> comp) { return source.MaxElement((x, y) => comp(y, x)); }
	public static int MinElement<T>(IEnumerable<T> source) where T : IComparable<T> { return source.MaxElement((x, y) => y.CompareTo(x)); }
	public static void Shuffle<T>(IList<T> source, Random rand) { for (var i = source.Count - 1; i >= 0; --i) source.Swap(i, rand.Next(0, i + 1)); }
	public static void Shuffle<T>(IList<T> source, RandomSFMT rand) { for (var i = source.Count - 1; i >= 0; --i) source.Swap(i, rand.Next(0, i + 1)); }
	public static char NextChar(this Random rand) { return (char)(rand.Next(0, 'z' - 'a' + 1) + 'a'); }
	public static char NextChar(this RandomSFMT rand) { return (char)(rand.Next(0, 'z' - 'a' + 1) + 'a'); }
	public static string NextString(this Random rand, int length) { return new string(Enumerable.Range(0, length).Select(_ => rand.NextChar()).ToArray()); }
	public static string NextString(this RandomSFMT rand, int length) { return new string(Enumerable.Range(0, length).Select(_ => rand.NextChar()).ToArray()); }
	public static IEnumerable<T> Rotate<T>(this IEnumerable<T> source)
	{
		var e = source.GetEnumerator();
		if (e.MoveNext())
		{
			var f = e.Current;
			while (e.MoveNext()) yield return e.Current;
			yield return f;
		}
	}
	public static T Apply<T>(this Func<T, T> func, T x, int n)
	{
		var a = x;
		for (var i = 0; i < n; i++) a = func(a);
		return a;
	}
	public static void MemberSet<T>(this T[] array, T value)
	{
		var X = array.Length;
		for (var x = 0; x < X; x++) array[x] = value;
	}
	public static void MemberSet<T>(this T[,] array, T value)
	{
		var X = array.GetLength(0); var Y = array.GetLength(1);
		for (var x = 0; x < X; x++) for (var y = 0; y < Y; y++) array[x, y] = value;
	}
	public static void MemberSet<T>(this T[,,] array, T value)
	{
		var X = array.GetLength(0); var Y = array.GetLength(1); var Z = array.GetLength(2);
		for (var x = 0; x < X; x++) for (var y = 0; y < Y; y++) for (var z = 0; z < Z; z++) array[x, y, z] = value;
	}
	public static void MemberSet<T>(this T[,,,] array, T value)
	{
		var X = array.GetLength(0); var Y = array.GetLength(1); var Z = array.GetLength(2); var W = array.GetLength(3);
		for (var x = 0; x < X; x++) for (var y = 0; y < Y; y++) for (var z = 0; z < Z; z++) for (var w = 0; w < W; w++) array[x, y, z, w] = value;
	}
	public static string ToYesNo(this bool flag) { return flag ? "YES" : "NO"; }
	public static int SetToMin(ref int min, int other) { return min = Math.Min(min, other); }
	public static int SetToMax(ref int max, int other) { return max = Math.Max(max, other); }
	public static long SetToMin(ref long min, long other) { return min = Math.Min(min, other); }
	public static long SetToMax(ref long max, long other) { return max = Math.Max(max, other); }
	public static Tuple<SortedDictionary<int, int>, SortedDictionary<int, int>> Compress(IEnumerable<int> coord, int width, int X)
	{
		var tmp = new SortedSet<int>();
		foreach (var x in coord)
		{
			for (var w = -width; w <= width; w++)
				if (x + w < 0 || x + w >= X) continue;
				else if (tmp.Contains(x + w)) continue;
				else tmp.Add(x + w);
		}
		var index = 0;
		var inverse = new SortedDictionary<int, int>();
		var dict = new SortedDictionary<int, int>();
		foreach (var pair in tmp)
		{
			dict.Add(pair, index);
			inverse.Add(index++, pair);
		}
		return new Tuple<SortedDictionary<int, int>, SortedDictionary<int, int>>(dict, inverse);
	}
	public static int MSB(uint n)
	{
		n |= (n >> 1);
		n |= (n >> 2);
		n |= (n >> 4);
		n |= (n >> 8);
		n |= (n >> 16);
		return BitCount(n) - 1;
	}
	public static int BitCount(uint n)
	{
		n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
		n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
		n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
		n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
		return (int)((n & 0x0000ffff) + ((n >> 16) & 0x0000ffff));
	}
	public static int LSB(uint n)
	{
		n |= (n << 1);
		n |= (n << 2);
		n |= (n << 4);
		n |= (n << 8);
		n |= (n << 16);
		return 32 - BitCount(n);
	}
	public static int MSB(ulong n)
	{
		n |= (n >> 1);
		n |= (n >> 2);
		n |= (n >> 4);
		n |= (n >> 8);
		n |= (n >> 16);
		n |= (n >> 32);
		return BitCount(n) - 1;
	}
	public static int BitCount(ulong n)
	{
		n = (n & 0x5555555555555555) + ((n >> 1) & 0x5555555555555555);
		n = (n & 0x3333333333333333) + ((n >> 2) & 0x3333333333333333);
		n = (n & 0x0f0f0f0f0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f0f0f0f0f);
		n = (n & 0x00ff00ff00ff00ff) + ((n >> 8) & 0x00ff00ff00ff00ff);
		n = (n & 0x0000ffff0000ffff) + ((n >> 16) & 0x0000ffff0000ffff);
		return (int)((n & 0x00000000ffffffff) + ((n >> 32) & 0x00000000ffffffff));
	}
	public static int LSB(ulong n)
	{
		n |= (n << 1);
		n |= (n << 2);
		n |= (n << 4);
		n |= (n << 8);
		n |= (n << 16);
		n |= (n << 32);
		return 64 - BitCount(n);
	}
	public static int Abs(this int n) { return Math.Abs(n); }
	public static long Abs(this long n) { return Math.Abs(n); }
	public static double Abs(this double n) { return Math.Abs(n); }
	public static float Abs(this float n) { return Math.Abs(n); }
	public static decimal Abs(this decimal n) { return Math.Abs(n); }
	public static short Abs(this short n) { return Math.Abs(n); }
	public static sbyte Abs(this sbyte n) { return Math.Abs(n); }
	public static int Min(params int[] nums) { var min = int.MaxValue; foreach (var n in nums) min = Math.Min(min, n); return min; }
	public static long Min(params long[] nums) { var min = long.MaxValue; foreach (var n in nums) min = Math.Min(min, n); return min; }
	public static uint Min(params uint[] nums) { var min = uint.MaxValue; foreach (var n in nums) min = Math.Min(min, n); return min; }
	public static ulong Min(params ulong[] nums) { var min = ulong.MaxValue; foreach (var n in nums) min = Math.Min(min, n); return min; }
	public static double Min(params double[] nums) { var min = double.MaxValue; foreach (var n in nums) min = Math.Min(min, n); return min; }
	public static decimal Min(params decimal[] nums) { var min = decimal.MaxValue; foreach (var n in nums) min = Math.Min(min, n); return min; }
	public static int Max(params int[] nums) { var min = int.MinValue; foreach (var n in nums) min = Math.Max(min, n); return min; }
	public static long Max(params long[] nums) { var min = long.MinValue; foreach (var n in nums) min = Math.Max(min, n); return min; }
	public static uint Max(params uint[] nums) { var min = uint.MinValue; foreach (var n in nums) min = Math.Max(min, n); return min; }
	public static ulong Max(params ulong[] nums) { var min = ulong.MinValue; foreach (var n in nums) min = Math.Max(min, n); return min; }
	public static double Max(params double[] nums) { var min = double.MinValue; foreach (var n in nums) min = Math.Max(min, n); return min; }
	public static decimal Max(params decimal[] nums) { var min = decimal.MinValue; foreach (var n in nums) min = Math.Max(min, n); return min; }
}
class RandomSFMT : Random
{
	int index, coin_bits, byte_pos, range, shift;
	uint coin_save, byte_save, bse;
	protected uint[] x = new uint[40];
	static uint[] ParityData = { 0x00000001U, 0x00000000U, 0x00000000U, 0x20000000U };
	public virtual void gen_rand_all()
	{
		int a = 0, b = 28, c = 32, d = 36; uint y; uint[] p = x;
		do
		{
			y = p[a + 3] ^ (p[a + 3] << 24) ^ (p[a + 2] >> 8) ^ ((p[b + 3] >> 5) & 0xb5ffff7fU);
			p[a + 3] = y ^ (p[c + 3] >> 8) ^ (p[d + 3] << 14);
			y = p[a + 2] ^ (p[a + 2] << 24) ^ (p[a + 1] >> 8) ^ ((p[b + 2] >> 5) & 0xaff3ef3fU);
			p[a + 2] = y ^ ((p[c + 2] >> 8) | (p[c + 3] << 24)) ^ (p[d + 2] << 14);
			y = p[a + 1] ^ (p[a + 1] << 24) ^ (p[a] >> 8) ^ ((p[b + 1] >> 5) & 0x7fefcfffU);
			p[a + 1] = y ^ ((p[c + 1] >> 8) | (p[c + 2] << 24)) ^ (p[d + 1] << 14);
			y = p[a] ^ (p[a] << 24) ^ ((p[b] >> 5) & 0xf7fefffdU);
			p[a] = y ^ ((p[c] >> 8) | (p[c + 1] << 24)) ^ (p[d] << 14);
			c = d; d = a; a += 4; b += 4;
			if (b == 40) b = 0;
		} while (a != 40);
	}
	void period_certification()
	{
		uint work, inner = 0; int i, j;
		index = 40; range = 0; coin_bits = 0; byte_pos = 0;
		for (i = 0; i < 4; i++) inner ^= x[i] & ParityData[i];
		for (i = 16; i > 0; i >>= 1) inner ^= inner >> i;
		inner &= 1;
		if (inner == 1) return;
		for (i = 0; i < 4; i++) for (j = 0, work = 1; j < 32; j++, work <<= 1) if ((work & ParityData[i]) != 0) { x[i] ^= work; return; }
	}
	public void InitMt(uint s)
	{
		unchecked
		{
			x[0] = s;
			for (uint p = 1; p < 40; p++) x[p] = s = 1812433253 * (s ^ (s >> 30)) + p;
			period_certification();
		}
	}
	public RandomSFMT(uint s) { InitMt(s); }
	public void InitMtEx(uint[] init_key)
	{
		uint r, i, j, c, key_len = (uint)init_key.Length;
		unchecked
		{
			for (i = 0; i < 40; i++) x[i] = 0x8b8b8b8b;
			if (key_len + 1 > 40) c = key_len + 1; else c = 40;
			r = x[0] ^ x[17] ^ x[39]; r = (r ^ (r >> 27)) * 1664525;
			x[17] += r; r += key_len; x[22] += r; x[0] = r; c--;
			for (i = 1, j = 0; j < c && j < key_len; j++)
			{
				r = x[i] ^ x[(i + 17) % 40] ^ x[(i + 39) % 40];
				r = (r ^ (r >> 27)) * 1664525; x[(i + 17) % 40] += r;
				r += init_key[j] + i; x[(i + 22) % 40] += r;
				x[i] = r; i = (i + 1) % 40;
			}
			for (; j < c; j++)
			{
				r = x[i] ^ x[(i + 17) % 40] ^ x[(i + 39) % 40];
				r = (r ^ (r >> 27)) * 1664525; x[(i + 17) % 40] += r; r += i;
				x[(i + 22) % 40] += r; x[i] = r; i = (i + 1) % 40;
			}
			for (j = 0; j < 40; j++)
			{
				r = x[i] + x[(i + 17) % 40] + x[(i + 39) % 40];
				r = (r ^ (r >> 27)) * 1566083941; x[(i + 17) % 40] ^= r;
				r -= i; x[(i + 22) % 40] ^= r; x[i] = r; i = (i + 1) % 40;
			}
			period_certification();
		}
	}
	public RandomSFMT(uint[] init_key) { InitMtEx(init_key); }
	public RandomSFMT() : this((uint)(DateTime.Now.Ticks & 0xffffffff)) { }
	public uint NextMt() { if (index == 40) { gen_rand_all(); index = 0; } return x[index++]; }
	public int NextInt(int n) { return (int)(n * (1.0 / 4294967296.0) * NextMt()); }
	public double NextUnif() { uint z = NextMt() >> 11, y = NextMt(); return (y * 2097152.0 + z) * (1.0 / 9007199254740992.0); }
	public int NextBit() { if (--coin_bits == -1) { coin_bits = 31; return (int)(coin_save = NextMt()) & 1; } else return (int)(coin_save >>= 1) & 1; }
	public int NextByte() { if (--byte_pos == -1) { byte_pos = 3; return (int)(byte_save = NextMt()) & 255; } else return (int)(byte_save >>= 8) & 255; }
	public override int Next(int maxValue) { return Next(0, maxValue); }
	protected override double Sample() { return NextUnif(); }
	public override double NextDouble() { return NextUnif(); }
	public override int Next() { return 1 + NextIntEx(int.MaxValue); }
	public override void NextBytes(byte[] buffer) { for (var i = 0; i < buffer.Length; i++) buffer[i] = (byte)NextByte(); }
	public override int Next(int min, int max) { return min + NextIntEx(max - min); }
	public int NextIntEx(int range_)
	{
		uint y_, base_, remain_; int shift_;
		if (range_ <= 0) return 0;
		if (range_ != range)
		{
			bse = (uint)(range = range_);
			for (shift = 0; bse <= (1UL << 30); shift++) bse <<= 1;
		}
		while (true)
		{
			y_ = NextMt() >> 1;
			if (y_ < bse) return (int)(y_ >> shift);
			base_ = bse; shift_ = shift; y_ -= base_;
			remain_ = (1U << 31) - base_;
			for (; remain_ >= (uint)range_; remain_ -= base_)
			{
				for (; base_ > remain_; base_ >>= 1) shift_--;
				if (y_ < base_) return (int)(y_ >> shift_);
				else y_ -= base_;
			}
		}
	}
}