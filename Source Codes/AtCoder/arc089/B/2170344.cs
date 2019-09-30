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
				int N = NextInt(), K = NextInt();
				int KK = K * 2;

				var imos = new int[KK, KK];

				N.REP(i =>
				{
					int xi = NextInt(), yi = NextInt();
					var ci = (char) Read();

					if (ci == 'W') yi += K;

					xi %= KK;
					yi %= KK;

					imos[yi, xi]++;
				});


				// =>
				for (int i = 0; i < KK; i++) {
					for (int j = 0; j < KK - 1; j++) {
						imos[i, j + 1] += imos[i, j];
					}
				}

				//v
				for (int i = 0; i < KK; i++) {
					for (int j = 0; j < KK - 1; j++) {
						imos[j + 1, i] += imos[j, i];
					}
				}

				Func<int, int, int, int, int> func = (y1, x1, y2, x2) =>
				{
					var a = x1 == 0 ? 0 : imos[y2, x1 - 1];
					var b = y1 == 0 ? 0 : imos[y1 - 1, x2];
					var c = x1 == 0 || y1 == 0 ? 0 : imos[y1 - 1, x1 - 1];
					return imos[y2, x2] - a - b + c;
				};

				var ans = 0;

				K.REP(y =>
				{
					K.REP(x =>
					{
						var sum = func(y, x, y + K - 1, x + K - 1);

						if (0 < y) sum += func(0, x + K, y - 1, KK - 1);
						if (0 < x && 0 < y) sum += func(0, 0, y - 1, x - 1);
						if (0 < x) sum += func(y + K, 0, KK - 1, x - 1);
						sum += func(y + K, x + K, KK - 1, KK - 1);

						ans = Max(ans, N - sum);
						ans = Max(ans, sum);
					});
				});
				ans.WL();
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
	[DebuggerStepThrough]
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