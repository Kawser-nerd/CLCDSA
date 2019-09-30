using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Reflection.Emit;
using System.Text;
using static System.Console;
using static System.Math;

//using CS_Contest.Graph;
using CS_Contest.Loop;
using CS_Contest.Utils;
using static Nakov.IO.Cin;
using static CS_Contest.IO.IO;
using static CS_Contest.Utils.MyMath;


namespace CS_Contest {
    using bint=BigInteger;
	using Li = List<int>;
	using LLi = List<List<int>>;
	using Ll = List<long>;
	using ti3 = Tuple<int, int, int>;
	using ti2 = Tuple<int, int>;
    using tl3=Tuple<long,long,long>;
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
	            var t0 = 0;
	            var x0 = 0;
	            var y0 = 0;

	            var flag = true;

                N.REP(i => {
                    int ti = NextInt(), xi = NextInt(), yi = NextInt();
                    var diff = ti - t0;
                    var distance = ManhattanDistance(x0, y0, xi, yi);
                    if (diff < distance) flag = false;
                    if (diff.IsOdd() && !distance.IsOdd()) flag = false;
                    if (!diff.IsOdd() && distance.IsOdd()) flag = false;
                });

                (flag?"Yes":"No").WL();
	        }
	        public static int ManhattanDistance(int x1, int y1, int x2, int y2) => Abs(x2 - x1) + Abs(y2 - y1);

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
	    public static IEnumerable<int> Seq(int e) => Seq(0, e, 1);
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

	    public static T[,] GetBox<T>(int h, int w, Func<int, int, T> getFunc) {
	        var rt = new T[h, w];
	        for (int i = 0; i < h; i++) {
	            for (int j = 0; j < w; j++) {
	                rt[i, j] = getFunc(i, j);
	            }
	        }

	        return rt;
	    }

	}


}

namespace CS_Contest.Utils {
	using Li = List<int>;
	using Ll = List<long>;
    using bint = BigInteger;

    [DebuggerStepThrough]
    public static class Utils {
        public static bool AnyOf<T>(this T @this, params T[] these) where T : IComparable {
            return these.Contains(@this);
        }

        public static bool Within(int x, int y, int lx, int ly) => !(x < 0 || x >= lx || y < 0 || y >= ly);

        public static void Add<T1, T2>(this List<Tuple<T1, T2>> list, T1 t1, T2 t2) =>
            list.Add(new Tuple<T1, T2>(t1, t2));

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

        public static List<Tuple<TKey, TValue>> ToTupleList<TKey, TValue>(this Map<TKey, TValue> @this) =>
            @this.Select(x => Tuple.Create(x.Key, x.Value)).ToList();


        public static Map<TKey, int> CountUp<TKey>(this IEnumerable<TKey> l) {
            var dic = new Map<TKey, int>();
            foreach (var item in l) {
                dic[item]++;
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

        public static int LowerBound<T>(this List<T> @this, T x) where T : IComparable {
            int lb = -1, ub = @this.Count;
            while (ub - lb > 1) {
                int mid = (ub + lb) >> 1;
                if (@this[mid].CompareTo(x) >= 0) ub = mid;
                else lb = mid;
            }

            return ub;
        }

        public static int UpperBound<T>(this List<T> @this, T x) where T : IComparable {
            int lb = -1, ub = @this.Count;
            while (ub - lb > 1) {
                int mid = (ub + lb) >> 1;
                if (@this[mid].CompareTo(x) > 0) ub = mid;
                else lb = mid;
            }

            return ub;
        }

        public static List<int> Imos(this IEnumerable<int> @this) {
            var rt = @this.ToList();
            for (var i = 0; i < rt.Count-1; i++) rt[i + 1] += rt[i];
            return rt;
        }

        public static bool IsOdd(this long @this) => @this % 2 == 1;
        public static bool IsOdd(this int @this) => @this % 2 == 1;
        public static bool IsOdd(this bint @this) => @this % 2 == 1;

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