using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using static System.Console;
using static System.Math;
using System.Numerics;
using System.Runtime.InteropServices.WindowsRuntime;
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

		public class Calc {
			public void Solve() {
				int N = NextInt(), K = NextInt(), L = NextInt();
				var kuf = new UnionFind(N);
				var luf=new UnionFind(N);

				K.REP(i =>
				{
					int pi = NextInt()-1, qi = NextInt()-1;
					kuf.Unite(pi, qi);
				});

				L.REP(i =>
				{
					int ri = NextInt()-1, si = NextInt() - 1;
					luf.Unite(ri, si);
				});

				var dic = new Map<ti2, int>();
				var pattern = new ti2[N];
				N.REP(i =>
				{
					var comb = new ti2(kuf.Root(i), luf.Root(i));
					dic[comb]++;
					pattern[i] = comb;
				});

				Enumerable.Range(0,N).Select(i=>dic[pattern[i]]).JoinWL();


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

		public static void RREP(this int @n, Action<int> act) {
			for (var i = n - 1; i >= 0; i--) act(i);
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
		public static long GCD(long m, long n) {
			long tmp;
			if (m < n) { tmp = n; n = m; m = tmp; }
			while (m % n != 0) {
				tmp = n;
				n = m % n;
				m = tmp;
			}
			return n;
		}

		public static long LCM(long m, long n) => m * (n / GCD(m, n));

		public static long ModValue = (long)1e9 + 7;
		public static long INF = long.MaxValue;

		public static long Mod(long x) => x % ModValue;
		public static long DivMod(long x, long y) => Mod(x * ModPow(y, (long)(1e9 + 5)));
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
		public static long ModPow(long x, long n) {
			long tmp = 1; while (n != 0) { if (n % 2 == 1) { tmp = Mod(tmp * x); } x = Mod(x * x); n /= 2; }
			return tmp;
		}
		public static bool IsPrime(long n) {
			if (n == 2) return true;
			if (n < 2 || n % 2 == 0) return false;
			var i = 3;
			var sq = (long)Sqrt(n);
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
		public static int ManhattanDistance(int x1, int y1, int x2, int y2) => Abs(x2 - x1) + Abs(y2 - y1);
		public static T EMin<T>(params T[] a) where T : IComparable<T> => a.Min();
		public static T EMax<T>(params T[] a) where T : IComparable<T> => a.Max();

	}


}