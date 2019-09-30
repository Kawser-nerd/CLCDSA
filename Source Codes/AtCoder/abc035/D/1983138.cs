using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using static System.Console;
using static System.Math;
using System.Numerics;
using static CS_Contest.Utils;
using static Nakov.IO.Cin;
//using static CS_Contest.Library;

namespace CS_Contest {
	using Li = List<int>;
	using LLi = List<List<int>>;
	using Ll = List<long>;

	internal class Program {
		private static void Main(string[] args) {
			var sw = new StreamWriter(OpenStandardOutput()) { AutoFlush = false };
			SetOut(sw);
			new Calc().Solve();
			Out.Flush();
		}

		public class Calc {
			public void Solve() {
				int N = NextInt(), M = NextInt(), T = NextInt();
				var A = ReadInts();
				var dijkstra=new Dijkstra(false);
				var revdijkstra=new Dijkstra(false);

				dijkstra.Init(N);
				revdijkstra.Init(N);


				REP(M, _ => {
					int ai = NextInt(), bi = NextInt();
					var ti = NextLong();
					dijkstra.AddPath(ai, bi, ti);
					revdijkstra.AddPath(bi, ai, ti);
				});
				long max = 0;
				dijkstra.Run(1);
				revdijkstra.Run(1);

				FOR(0,N, i => {
					if (dijkstra.PathExist(i+1) && revdijkstra.PathExist(i+1)) {
						var tleft = T - dijkstra.cost[i+1] - revdijkstra.cost[i+1];
						max = Max(tleft * A[i], max);
					}
				});
				
				max.WL();
				

				return;
			}


		}
	}

	public static class Utils {

	
		public static void WL(this object obj) => WriteLine(obj);

		public static void WL(this string obj) => WriteLine(obj);

		public static void WL<T>(this IEnumerable<T> list) => list.ToList().ForEach(x => x.WL());

		public static Li ReadInts() => ReadLine().Split().Select(int.Parse).ToList();

		public static string StringJoin<T>(this IEnumerable<T> l, string separator = "") => string.Join(separator, l);

		public static void REP(int n, Action<int> act) {
			for (var i = 0; i < n; i++) {
				act(i);
			}
		}

		public static void FOR(int start, int end, Action<int> act) {
			for (int i = start; i < end; i++) act(i);
		}


		public static int ManhattanDistance(int x1, int y1, int x2, int y2) => Abs(x2 - x1) + Abs(y2 - y1);

		public struct IndexT<T> {
			public T Value { get; set; }
			public int Index { get; set; }

			public IndexT(T v, int i) {
				Value = v; Index = i;
			}
			public override string ToString() {
				return Value + " " + Index;
			}
		}

		public static IEnumerable<IndexT<T>> ToIndexEnumerable<T>(this IEnumerable<T> list) => list.Select((x, i) => new IndexT<T>(x, i));

		public static Queue<T> ToQueue<T>(this IEnumerable<T> iEnumerable) {
			var rt = new Queue<T>();
			foreach (var item in iEnumerable) {
				rt.Enqueue(item);
			}
			return rt;
		}

		public static IndexT<T> IndexOf<T>(this IEnumerable<T> ie, Func<IndexT<T>, IndexT<T>, IndexT<T>> func) =>
			ie.ToIndexEnumerable().Aggregate(func);

		public static void Swap<T>(ref T x,ref T y) {
			var tmp = x;
			x = y;
			y = tmp;
		}
		public static Dictionary<TKey,int> CountUp<TKey>(this IEnumerable<TKey> l) {
			var dic = new Dictionary<TKey, int>();
			foreach (var item in l) {
				if (dic.ContainsKey(item)) dic[item]++;
				else dic.Add(item, 1);
			}
			return dic;
		}
		public static int Count<T>(this IEnumerable<T> l, T target) => l.Count(x => x.Equals(target));
	}

	public struct edge : IComparable<edge> {
		public int to; public long cost;
		public edge(int to, long cost) { this.to = to; this.cost = cost; }
		public int CompareTo(edge e) { return cost.CompareTo(e.cost); }
	}

	class ShortestPath {
		protected int I = -1;       //??1~N
		protected int V;             //???
		protected int E;             //???
		protected bool isNonDir = true;     //???
		public long INF = (long)1e15;       //???
		public long[] cost;                        //??        
		public List<edge>[] Adj;               //?????
		public void Init(int n) { I = n + 1; V = n; Adj = new List<edge>[I]; for (int i = 0; i < I; ++i) Adj[i] = new List<edge>(); }
		public void AddPath(int f, int t, long c = 1) { E++; Adj[f].Add(new edge(t, c)); if (isNonDir) Adj[t].Add(new edge(f, c)); }
		public void AddPath(int[] f, int[] t, long[] c) { for (int i = 0; i < f.Length; ++i) AddPath(f[i], t[i], c[i]); }
		public void AddPath(int[] f, int[] t) { for (int i = 0; i < f.Length; ++i) AddPath(f[i], t[i]); }
		public bool PathExist(int t) { return cost[t] != INF; }
	}
	class PQueue<T> where T : struct, IComparable<T> {
		public List<T> heap; private Comparison<T> comp; private IComparer<T> comparer;
		private int size; private int type;//type=0->min
		public PQueue(int type = 0) : this(Comparer<T>.Default) { this.type = type; }
		public PQueue(IComparer<T> comparer) : this(16, comparer.Compare) { this.comparer = comparer; }
		public PQueue(Comparison<T> comparison) : this(16, comparison) { }
		public PQueue(int capacity, Comparison<T> comparison) { this.heap = new List<T>(capacity); this.comp = comparison; }
		public void Enqueue(T item) {
			this.heap.Add(item); var i = size++;
			while (i > 0) { var p = (i - 1) >> 1; if (Compare(this.heap[p], item) <= 0) break; this.heap[i] = heap[p]; i = p; }
			this.heap[i] = item;
		}
		public T Dequeue() {
			var ret = this.heap[0]; var x = this.heap[--size]; var i = 0;
			while ((i << 1) + 1 < size) {
				var a = (i << 1) + 1; var b = (i << 1) + 2; if (b < size && Compare(heap[b], heap[a]) < 0) a = b;
				if (Compare(heap[a], x) >= 0) break; heap[i] = heap[a]; i = a;
			}
			heap[i] = x; heap.RemoveAt(size);
			return ret;
		}
		public T Peek() { return heap[0]; }
		public int Count { get { return size; } }
		public bool Any() { return size > 0; }
		public bool Empty() { return !Any(); }
		public bool Contains(T v) { return heap.Contains(v); }
		private int Compare(T x, T y) { return type == 0 ? x.CompareTo(y) : y.CompareTo(x); }
	}
	class Dijkstra : ShortestPath {
		public Dijkstra(bool isNonDir = true) { this.isNonDir = isNonDir; }
		public long MinCost(int f, int t) { Run(f); return cost[t]; }
		public long MinCost(int t) { return cost[t]; }
		public void Run(int f) {
			cost = new long[I]; for (int i = 0; i < I; ++i) cost[i] = INF; cost[f] = 0;
			var pq = new PQueue<edge>(); pq.Enqueue(new edge(f, 0L));
			while (!pq.Empty()) {
				var cur = pq.Dequeue();
				if (cost[cur.to] < cur.cost) continue;
				for (int i = 0; i < Adj[cur.to].Count; ++i) {
					var tmp = Adj[cur.to][i];
					if (cost[tmp.to] > cur.cost + tmp.cost) {
						cost[tmp.to] = cur.cost + tmp.cost;
						pq.Enqueue(new edge(tmp.to, cost[tmp.to]));
					}
				}
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