using System;
using System.Collections.Generic;
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
				var N = NextInt();
				var kruskal=new Kruskal(N);

				var xlist = new List<ti2>();
				var ylist = new List<ti2>();


				for (int i = 0; i < N; i++) {
					xlist.Add(NextInt(), i);
					ylist.Add(NextInt(), i);
				}

				xlist = xlist.OrderBy(x => x.Item1).ToList();
				ylist = ylist.OrderBy(x => x.Item1).ToList();

				var list = new List<ti3>();

				for (int i = 0; i < N-1; i++) {
					{
						var s = xlist[i];
						var t = xlist[i + 1];
						kruskal.Add(s.Item2, t.Item2, t.Item1 - s.Item1);
					}
					{
						var s = ylist[i];
						var t = ylist[i + 1];
						kruskal.Add(s.Item2, t.Item2, t.Item1 - s.Item1);
					}
				}

				kruskal.Run().WL();
				return;
			}
		}

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

		public class Kruskal
		{
			private List<Tuple<int, int, long>> edgeList;
			private int N { get; set; }
			public Kruskal(int n) {
				N = n;
				edgeList=new List<Tuple<int, int, long>>();
			}

			public void Add(int s, int t, long cost) => edgeList.Add(new Tuple<int, int, long>(s, t, cost));

			public long Run() {
				edgeList.Sort((a, b) => a.Item3.CompareTo(b.Item3));
				var rt = 0L;
				var uf=new UnionFind(N);
				foreach (var tuple in edgeList) {
					var s = tuple.Item1;
					var t = tuple.Item2;
					var cost = tuple.Item3;
					if(uf.IsSameGroup(s,t)) continue;
					uf.Unite(s, t);
					rt += cost;
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
}

namespace CS_Contest.IO {
	using Li = List<int>;
	using Ll = List<long>;

	public static class IO {
		public static void WL(this object obj) => WriteLine(obj);
		public static void WL(this string obj) => WriteLine(obj);
		public static void WL<T>(this IEnumerable<T> list) => list.ToList().ForEach(x => x.WL());

		public static Li NextIntList() => ReadLine().Split().Select(int.Parse).ToList();
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
	public static class Utils {
		public static List<T> Repeat<T>(Func<int, T> result, int range) =>
			Enumerable.Range(0, range).Select(result).ToList();

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