using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using static System.Console;
using static System.Math;
using System.Numerics;
using CS_Contest.Graph;
using CS_Contest.Loop;
using CS_Contest.Utils;
using static Nakov.IO.Cin;
using static CS_Contest.IO.IO;

namespace CS_Contest {
	using Li = List<int>;
	using LLi = List<List<int>>;
	using Ll = List<long>;
	using ti3=Tuple<int,int,int>;
	using II=Tuple<int,int>;
	using LL=Tuple<long,long>;
	internal class Program {
		private static void Main(string[] args) {
			var sw = new StreamWriter(OpenStandardOutput()) { AutoFlush = false };
			SetOut(sw);
			new Calc().Solve();
			Out.Flush();
		}

		public class Calc {
			public void Solve() {
				int N = NextInt(), M = NextInt();
				var box = new bool[N];
				box[0] = true;
				var count = Enumerable.Repeat(1, N).ToArray();

				M.REP(i =>
				{
					int xi = NextInt(), yi = NextInt();
					xi--;
					yi--;

					count[xi]--;
					count[yi]++;
					if (box[xi]) {
						box[yi] = true;
						box[xi] = count[xi] != 0;
					}

				});
				box.Count(x=>x).WL();
			}
		}
	}



	

}
namespace Nakov.IO {
	using System;
	using System.Text;
	using System.Globalization;

	public static class Cin {
		public static string NextToken() {
			StringBuilder tokenChars = new StringBuilder();
			bool tokenFinished = false;
			bool skipWhiteSpaceMode = true;
			while (!tokenFinished) {
				int nextChar = Console.Read();
				if (nextChar == -1) {
					tokenFinished = true;
				} else {
					char ch = (char)nextChar;
					if (char.IsWhiteSpace(ch)) {
						if (!skipWhiteSpaceMode) {
							tokenFinished = true;
							if (ch == '\r' && (Environment.NewLine == "\r\n")) {
								Console.Read();
							}
						}
					} else {
						skipWhiteSpaceMode = false;
						tokenChars.Append(ch);
					}
				}
			}

			string token = tokenChars.ToString();
			return token;
		}

		public static int NextInt() {
			string token = Cin.NextToken();
			return int.Parse(token);
		}
		public static long NextLong() {
			string token = Cin.NextToken();
			return long.Parse(token);
		}
		public static double NextDouble(bool acceptAnyDecimalSeparator = true) {
			string token = Cin.NextToken();
			if (acceptAnyDecimalSeparator) {
				token = token.Replace(',', '.');
				double result = double.Parse(token, CultureInfo.InvariantCulture);
				return result;
			} else {
				double result = double.Parse(token);
				return result;
			}
		}
		public static decimal NextDecimal(bool acceptAnyDecimalSeparator = true) {
			string token = Cin.NextToken();
			if (acceptAnyDecimalSeparator) {
				token = token.Replace(',', '.');
				decimal result = decimal.Parse(token, CultureInfo.InvariantCulture);
				return result;
			} else {
				decimal result = decimal.Parse(token);
				return result;
			}
		}

	}
}

namespace CS_Contest.Graph
{
	using Ll=List<long>;
	using Li=List<int>;

	public struct WeightedUnionFind
	{
		private readonly int N;
		public int[] Parent { get; private set; }
		public long[] Cost { get; private set; }
		public int[] Rank { get; private set; }

		public WeightedUnionFind(int n) {
			N = n;
			Parent = Enumerable.Range(0, N).ToArray();
			Cost = new long[N];
			Rank = new int[N];
		}

		public int Root(int u, out long cost) {
			if (Parent[u] == u) {
				cost = Cost[u];
				return u;
			}

			var v = Root(Parent[u], out cost);
			cost += Cost[u];
			Parent[u] = v;
			Cost[u] = cost;
			return v;
		}

		public void Unite(int lv, int rv, long cost) {
			long lc, rc;
			lv = Root(lv, out lc);
			rv = Root(rv, out rc);
			cost = -rc + cost + lc;

			if (Rank[lv] < Rank[rv]) {
				Unite(rv, lv, -cost);
				return;
			}

			Parent[rv] = lv;
			Cost[rv] = cost;
			Rank[lv] += Rank[rv] + 1;
		}

		public bool IsValid() {
			for (var i = 0; i < N; i++) {
				long _;
				Root(i, out _);
			}

			for (var i = 0; i < N; i++) {
				if (Parent[i] == i && Cost[i] != 0L) {
					return false;
				}
			}

			return true;
		}
	}

	/// <summary>
	/// UnionFind
	/// </summary>
	public struct UnionFind {
		private readonly int[] _data;

		public UnionFind(int size) {
			_data = new int[size];
			for (var i = 0; i < size; i++) _data[i] = -1;
		}

		public bool Unite(int x, int y) {
			x = Root(x);
			y = Root(y);

			if (x == y) return x != y;
			if (_data[y] < _data[x]) {
				var tmp = y;
				y = x;
				x = tmp;
			}
			_data[x] += _data[y];
			_data[y] = x;
			return x != y;
		}

		public bool IsSameGroup(int x, int y) {
			return Root(x) == Root(y);
		}

		public int Root(int x) {
			return _data[x] < 0 ? x : _data[x] = Root(_data[x]);
		}
	}
	public class BellmanFord : CostGraph {
		public BellmanFord(int size) : base(size) {
		}

		public List<long> Distance { get; set; }

		private bool[] _negative;
		public bool HasCycle => _negative[Size - 1];

		public void Run(int s) {
			Distance = new Ll();
			Size.REP(i => Distance.Add(Inf));
			Distance[s] = 0;
			_negative = new bool[Size];

			(Size - 1).REP(i => Size.REP(j => Adjacency[j].Count.REP(k =>
				{
					var src = Adjacency[j][k];
					if (Distance[src.To] > Distance[j] + src.Cost) Distance[src.To] = Distance[j] + src.Cost;
				}
			)));

			for (int i = 0; i < Size; i++) {
				Size.REP(j => {
					Adjacency[j].Count.REP(k => {
						var src = Adjacency[j][k];
						if (Distance[src.To] > Distance[j] + src.Cost) {
							Distance[src.To] = Distance[j] + src.Cost;
							_negative[src.To] = true;
						}
						if (_negative[j]) _negative[src.To] = true;
					});
				});
			}
		}
	}
	public class CostGraph {
		public struct Edge {
			public int To { get; set; }
			public long Cost { get; set; }


			public Edge(int to, long cost) {
				To = to;
				Cost = cost;
			}

		}

		public int Size { get; set; }
		public List<List<Edge>> Adjacency { get; set; }
		public const long Inf = (long)1e15;

		public CostGraph(int size) {
			Size = size;
			Adjacency = new List<List<Edge>>();
			Size.REP(_ => Adjacency.Add(new List<Edge>()));
		}

		public void Add(int s, int t, long c, bool dir = true) {
			Adjacency[s].Add(new Edge(t, c));
			if (!dir) Adjacency[t].Add(new Edge(s, c));
		}

	}

	/// <summary>
	/// ????????
	/// </summary>
	/// <typeparam name="T"></typeparam>
	public class PriorityQueue<T> {
		private readonly List<T> heap;
		private readonly Comparison<T> compare;
		private int size;

		public PriorityQueue() : this(Comparer<T>.Default) {
		}

		public PriorityQueue(IComparer<T> comparer) : this(16, comparer.Compare) {
		}

		public PriorityQueue(Comparison<T> comparison) : this(16, comparison) {
		}

		public PriorityQueue(int capacity, Comparison<T> comparison) {
			this.heap = new List<T>(capacity);
			this.compare = comparison;
		}

		public void Enqueue(T item) {
			this.heap.Add(item);
			var i = size++;
			while (i > 0) {
				var p = (i - 1) >> 1;
				if (compare(this.heap[p], item) <= 0)
					break;
				this.heap[i] = heap[p];
				i = p;
			}
			this.heap[i] = item;
		}

		public T Dequeue() {
			var ret = this.heap[0];
			var x = this.heap[--size];
			var i = 0;
			while ((i << 1) + 1 < size) {
				var a = (i << 1) + 1;
				var b = (i << 1) + 2;
				if (b < size && compare(heap[b], heap[a]) < 0) a = b;
				if (compare(heap[a], x) >= 0)
					break;
				heap[i] = heap[a];
				i = a;
			}
			heap[i] = x;
			heap.RemoveAt(size);
			return ret;
		}

		public T Peek() {
			return heap[0];
		}

		public int Count => size;

		public bool Any() {
			return size > 0;
		}
	}


	public class Dijkstra : CostGraph {
		public Dijkstra(int size) : base(size) { }
		public int[] PreviousNodeList { get; set; }
		public long[] Distance { get; set; }

		public void Run(int s) {
			PreviousNodeList = new int[Size];
			Distance = new long[Size];
			Size.REP(_ => Distance[_] = Inf);

			var pq = new PriorityQueue<Edge>((x, y) => x.Cost.CompareTo(y.Cost));
			Distance[s] = 0;
			pq.Enqueue(new Edge(s, 0));
			while (pq.Any()) {
				var src = pq.Dequeue();
				if (Distance[src.To] < src.Cost) continue;
				for (var i = 0; i < Adjacency[src.To].Count; i++) {
					var tmp = Adjacency[src.To][i];
					var cost = tmp.Cost + src.Cost;
					if (cost >= Distance[tmp.To]) continue;
					Distance[tmp.To] = cost;
					pq.Enqueue(new Edge(tmp.To, cost));
					PreviousNodeList[tmp.To] = src.To;
				}
			}
		}
	}


	public class WarshallFloyd : CostGraph {
		public WarshallFloyd(int size) : base(size) {
		}

		public List<Ll> Run() {
			var rt = new List<Ll>();
			Size.REP(_ => rt.Add(new Ll()));

			Size.REP(i => Size.REP(k => rt[i].Add(i == k ? 0 : Inf)));

			Adjacency.ForeachWith( (i, item) => {
				foreach (var k in item) {
					rt[i][k.To] = k.Cost;
				}
			});

			Size.REP(i => Size.REP(j => Size.REP(k => {
				rt[j][k] = Min(rt[j][k], rt[j][i] + rt[i][k]);
			})));

			return rt;
		}
	}

}

namespace CS_Contest.Loop
{
	public static class Loop
	{
		public static void REP(this int n, Action<int> act) {
			for (var i = 0; i < n; i++) {
				act(i);
			}
		}

		public static void REP(this long n, Action<long> act) {
			for (var i = 0; i < n; i++) act(i);
		}

		public static void FOR(this Tuple<int, int, int> t, Action<int> action) {
			for (var i = t.Item1; i < t.Item2; i += t.Item3) action(i);
		}

		public static void FOR(this Tuple<int, int> t, Action<int> action) =>
			new Tuple<int, int, int>(t.Item1, t.Item2, 1).FOR(action);

		public static void FOR(this Tuple<long, long, long> t, Action<long> action) {
			for (var i = t.Item1; i < t.Item2; i += t.Item3) action(i);
		}

		public static void FOR(this Tuple<long, long> t, Action<long> act) =>
			new Tuple<long, long, long>(t.Item1, t.Item2, 1).FOR(act);
	}
}

namespace CS_Contest.IO
{
	using Li = List<int>;
	using Ll = List<long>;

	public static class IO
	{
		public static void WL(this object obj) => WriteLine(obj);
		public static void WL(this string obj) => WriteLine(obj);
		public static void WL<T>(this IEnumerable<T> list) => list.ToList().ForEach(x => x.WL());

		public static Li GetIntList() => ReadLine().Split().Select(int.Parse).ToList();
		public static Ll GetLongList() => ReadLine().Split().Select(long.Parse).ToList();

		public static T Tee<T>(this T t, Func<T, string> formatter = null) {
			if (formatter == null) formatter = arg => arg.ToString();
			formatter(t).WL();
			return t;
		}
		public static void JoinWL<T>(this IEnumerable<T> @this, string sp = " ") => @this.StringJoin(sp).WL();
	}


}

namespace CS_Contest.Utils
{
	using Li=List<int>;
	using Ll=List<long>;
	public static class Utils
	{
		public static List<T> Repeat<T>(Func<int, T> result, int range) =>
			Enumerable.Range(0, range).Select(result).ToList();

		public static long[,] CombinationTable(int n) {
			var rt = new long[n + 1, n + 1];
			for (var i = 0; i <= n; i++) {
				for (var j = 0; j <= i; j++) {
					if (j == 0 || i == j) rt[i, j] = 1L;
					else rt[i, j] = (rt[i - 1, j - 1] + rt[i - 1, j]);
				}
			}
			return rt;
		}
		public static long ModValue = (long)1e9 + 7;
		public static long INF = long.MaxValue;

		public static long Mod(long x) => x % ModValue;

		public static long ModPow(long x, long n) {
			long tmp = 1; while (n != 0) { if (n % 2 == 1) { tmp = Mod(tmp * x); } x = Mod(x * x); n /= 2; }
			return tmp;
		}

		public static long DivMod(long x, long y) => Mod(x * ModPow(y, (long)(1e9 + 5)));
		public static void Add<T1, T2>(this List<Tuple<T1, T2>> list, T1 t1, T2 t2) => list.Add(new Tuple<T1, T2>(t1, t2));

		public static bool IsPrime(int n) {
			if (n == 2) return true;
			if (n < 2||n%2==0) return false;
			var i = 3;
			int sq = (int)Sqrt(n);
			while (i <= sq) {
				if (n % i == 0) return false;
				i += 2;
			}
			return true;
		}

		public static IEnumerable<int> Primes(int maxnum) {
			yield return 2;
			yield return 3;
			var sieve = new BitArray(maxnum + 1);
			int squareroot = (int)Math.Sqrt(maxnum);
			for (int i = 2; i <= squareroot; i++) {
				if (sieve[i] == false) {
					for (int n = i * 2; n <= maxnum; n += i)
						sieve[n] = true;
				}
				for (var n = i * i + 1; n <= maxnum && n < (i + 1) * (i + 1); n++) {
					if (!sieve[n])
						yield return n;
				}
			}
		}

		public static T Min<T>(params T[] a) where T : IComparable<T> => a.Min();
		public static T Max<T>(params T[] a) where T : IComparable<T> => a.Max();


		public static string StringJoin<T>(this IEnumerable<T> l, string separator = "") => string.Join(separator, l);

		public static void ForeachWith<T>(this IEnumerable<T> ie, Action<int, T> act) {
			var i = 0;
			foreach (var item in ie) {
				act(i, item);
				i++;
			}
		}

		public static void Foreach<T>(this IEnumerable<T> ie, Action<T> act) {
			foreach (var item in ie) {
				act(item);
			}
		}


		public static int ManhattanDistance(int x1, int y1, int x2, int y2) => Abs(x2 - x1) + Abs(y2 - y1);

		public static Queue<T> ToQueue<T>(this IEnumerable<T> iEnumerable) {
			var rt = new Queue<T>();
			foreach (var item in iEnumerable) {
				rt.Enqueue(item);
			}
			return rt;
		}
		public static void Swap<T>(ref T x, ref T y) {
			var tmp = x;
			x = y;
			y = tmp;
		}
		public static Dictionary<TKey, int> CountUp<TKey>(this IEnumerable<TKey> l) {
			var dic = new Dictionary<TKey, int>();
			foreach (var item in l) {
				if (dic.ContainsKey(item)) dic[item]++;
				else dic.Add(item, 1);
			}
			return dic;
		}
		public static int Count<T>(this IEnumerable<T> l, T target) => l.Count(x => x.Equals(target));

		public static IEnumerable<T> SkipAt<T>(this IEnumerable<T> @this, int at) {
			for (var i = 0; i < @this.Count(); i++) {
				if(i==at) continue;
				yield return @this.ElementAt(i);
			}
		}
	}

	public class Map<TKey, TValue> : Dictionary<TKey, TValue> {
		public Map() : base() { }
		public Map(int capacity) : base(capacity) { }

		public new TValue this[TKey index] {
			get {
				TValue v;
				return this.TryGetValue(index, out v) ? v : base[index] = default(TValue);
			}
			set { base[index] = value; }
		}
	}

}