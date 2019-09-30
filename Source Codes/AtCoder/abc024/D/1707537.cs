using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using static System.Console;
using static System.Math;
using static CS_Contest.Utils;
using System.Numerics;
using System.Linq.Expressions;
using Nakov.IO;

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
				long A = Cin.NextLong(), B = Cin.NextLong(), C = Cin.NextLong();
				A = Mod(A);B = Mod(B);C = Mod(C);
				long AC = Mod(A * C);
				long AB = Mod(A * B);
				long BC = Mod(B * C);

				Func<long, long, long> search = null;
				search = (x, m) => {
					if (m == 0) return 1;
					else if (m % 2 == 0) return search(Mod(x * x), m / 2);
					else return Mod(search(Mod(x * x), m >> 1) * x);
				};

				long c = Mod(BC - AB + ModValue) * Mod(search(AC - BC + AB + ModValue, ModValue - 2));
				long r = Mod(BC - AC + ModValue) * Mod(search(AC - BC + AB + ModValue, ModValue - 2));

				(Mod(r) + " " + Mod(c)).WL();
			}


		}
	}

	public static class Utils {
		public static long ModValue = (long)1e9 + 7;
		public static long INF = long.MaxValue;

		public static long Mod(long x) => x % ModValue;

		public static long ModPow(long x, long n) {
			long tmp = 1; while (n != 0) { if (n % 2 == 1) { tmp = Mod(tmp * x); } x = Mod(x * x); n /= 2; }
			return tmp;
		}

		public static long DivMod(long x, long y) => Mod(x * ModPow(y, (long)(1e9 + 5)));

		public static void WL(this object obj) => WriteLine(obj);

		public static void WL(this string obj) => WriteLine(obj);

		public static void WL<T>(this IEnumerable<T> list) => list.ToList().ForEach(x => x.WL());

		public static Li ReadInt() => ReadLine().Split().Select(int.Parse).ToList();

		public static string StringJoin<T>(this IEnumerable<T> l, string separator = "") => string.Join(separator, l);

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

		public static void REP(int n, Action<int> act) {
			for (var i = 0; i < n; i++) {
				act(i);
			}
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


		public static T[] Range<T>(int range,Func<int,T> func) {
			var rt = new T[range];
			for (var i = 0; i < range; i++) rt[i] = func(i);
			return rt;
		}
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