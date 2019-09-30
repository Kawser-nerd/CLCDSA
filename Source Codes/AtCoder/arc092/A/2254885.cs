using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using static System.Console;
using static System.Math;

//using CS_Contest.Graph;
using CS_Contest.Loop;
using CS_Contest.Utils;
using static Nakov.IO.Cin;
using static CS_Contest.IO.IO;
using static CS_Contest.Utils.MyMath;


namespace CS_Contest {
	using Li = List<int>;
	using LLi = List<List<int>>;
	using Ll = List<long>;
	using ti3 = Tuple<int, int, int>;
	using ti2 = Tuple<int, int>;
	internal class Program {
		private static void Main(string[] args) {
			var sw = new StreamWriter(OpenStandardOutput()) { AutoFlush = false };
			SetOut(sw);
			new Calc().Solve();
			Out.Flush();
		}

		public class Calc
		{
			public void Solve() {
				int N = NextInt();
				var s = 0;
				var t = 2 * N + 1;
				var mf = new MaxFlow(t + 1);

				var A = new List<ti2>();
				var B = new List<ti2>();

				N.REP(i => {
					A.Add(NextInt(), NextInt());
					mf.Add(s,i+1,1);
				});
				N.REP(i => {
					B.Add(NextInt(), NextInt());
					mf.Add(i+N+1,t,1);
				});

				for (int i = 0; i < N; i++) {
					var ax = A[i].Item1;
					var ay = A[i].Item2;

					for (int j = 0; j < N; j++) {
						var bx = B[j].Item1;
						var by = B[j].Item2;

						if (ax < bx && ay < by) {
							mf.Add(i + 1, j + N + 1, 1);
						}
					}
				}

				mf.Run(s,t).WL();

				return;
			}
		}
		public class MaxFlow {
			private class Edge {
				public int To, Reverse, Capacity;
			}

			private int V { get; set; }
			private List<Edge>[] graph { get; set; }
			private int[] leveList, itr;
			public MaxFlow(int v) {
				V = v;
				graph = Enumerable.Repeat(1, V).Select(x => new List<Edge>()).ToArray();
			}

			public void Add(int from, int to, int capa, bool dir = true) {
				graph[from].Add(new Edge { Capacity = capa, Reverse = graph[to].Count, To = to });
				graph[to].Add(new Edge { To = from, Capacity = dir ? 0 : capa, Reverse = graph[from].Count - 1 });
			}

			private void Bfs(int s) {
				leveList = Enumerable.Repeat(-1, V).ToArray();
				var queue = new Queue<int>();
				leveList[s] = 0;
				queue.Enqueue(s);
				while (queue.Any()) {
					var src = queue.Dequeue();
					foreach (var edge in graph[src]) {
						if (edge.Capacity <= 0 || leveList[edge.To] >= 0) continue;
						leveList[edge.To] = leveList[src] + 1;
						queue.Enqueue(edge.To);
					}
				}
			}

			private int Dfs(int v, int t, int f) {
				if (v == t) return f;
				for (; itr[v] < graph[v].Count; itr[v]++) {
					var edge = graph[v][itr[v]];
					if (edge.Capacity <= 0 || leveList[v] >= leveList[edge.To]) continue;
					var d = Dfs(edge.To, t, Min(f, edge.Capacity));
					if (d <= 0) continue;
					edge.Capacity -= d;
					graph[edge.To][edge.Reverse].Capacity += d;
					return d;
				}

				return 0;
			}

			public int Run(int s, int t) {
				int rt = 0;
				Bfs(s);
				while (leveList[t] >= 0) {
					itr = new int[V];
					int f;
					while ((f = Dfs(s, t, int.MaxValue)) > 0) rt += f;
					Bfs(s);
				}

				return rt;
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

namespace CS_Contest.Loop {
	[DebuggerStepThrough]
	public static class Loop {
		public static void REP(this int n, Action<int> act) {
			for (var i = 0; i < n; i++) {
				act(i);
			}
		}

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

		
	}

	public class Generate
	{
		public static IEnumerable<int> Seq(int s, int e) => Seq(s, e, 1);
		public static IEnumerable<int> Seq(int s, int e, int a) {
			while (s != e) {
				yield return s;
				s += a;
			}
		}
		public static List<T> Repeat<T>(Func<int, T> result, int range) =>
			Enumerable.Range(0, range).Select(result).ToList();
	}
}

namespace CS_Contest.IO {
	using Li = List<int>;
	using Ll = List<long>;

	public static class IO {
		public static void WL(this object obj) => WriteLine(obj);
		public static void WL(this string obj) => WriteLine(obj);
		public static void WL<T>(this IEnumerable<T> list) => list.ToList().ForEach(x => x.WL());

		public static Li NextIntList() => ReadLine().Split().Select(int.Parse).ToList();
		public static Li NextIntList(int n) => Enumerable.Repeat(0, n).Select(x => ReadLine()).Select(int.Parse).ToList();
		public static Ll NextLongList() => ReadLine().Split().Select(long.Parse).ToList();

		public static T Tee<T>(this T t, Func<T, string> formatter = null) {
			if (formatter == null) formatter = arg => arg.ToString();
			formatter(t).WL();
			return t;
		}
		public static void JoinWL<T>(this IEnumerable<T> @this, string sp = " ") => @this.StringJoin(sp).WL();
		public static void W(this object @this) => Write(@this);
	}


}

namespace CS_Contest.Utils {
	using Li = List<int>;
	using Ll = List<long>;
	[DebuggerStepThrough]
	public static class Utils {
		

		public static bool Within(int x, int y, int lx, int ly) => !(x < 0 || x >= lx || y < 0 || y >= ly);

		public static void Add<T1, T2>(this List<Tuple<T1, T2>> list, T1 t1, T2 t2) => list.Add(new Tuple<T1, T2>(t1, t2));

		public static string StringJoin<T>(this IEnumerable<T> l, string separator = "") => string.Join(separator, l);

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
		public static Map<TKey, int> CountUp<TKey>(this IEnumerable<TKey> l) {
			var dic = new Map<TKey, int>();
			foreach (var item in l) {
				if (dic.ContainsKey(item)) dic[item]++;
				else dic.Add(item, 1);
			}
			return dic;
		}
		public static int Count<T>(this IEnumerable<T> l, T target) => l.Count(x => x.Equals(target));

		public static IEnumerable<T> SkipAt<T>(this IEnumerable<T> @this, int at) {
			var enumerable = @this as T[] ?? @this.ToArray();
			for (var i = 0; i < enumerable.Count(); i++) {
				if (i == at) continue;
				yield return enumerable.ElementAt(i);
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

	public static class MyMath {
		
		public static T EMin<T>(params T[] a) where T : IComparable<T> => a.Min();
		public static T EMax<T>(params T[] a) where T : IComparable<T> => a.Max();

	}


}