using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Runtime.InteropServices;
using System.Text;
using static System.Console;
using static System.Math;
using CS_Contest.Loop;
using CS_Contest.Utils;
using static Nakov.IO.Cin;
using static CS_Contest.IO.IO;


namespace CS_Contest {
    using bint = BigInteger;
    using Li = List<int>;
    using LLi = List<List<int>>;
    using Ll = List<long>;
    using ti3 = Tuple<int, int, int>;
    using ti2 = Tuple<int, int>;
    using tl3 = Tuple<long, long, long>;
    using ti4 = Tuple<int,int,int,int>;
    internal class Program {
        private static void Main(string[] args) {
            var sw = new StreamWriter(OpenStandardOutput()) { AutoFlush = false };
            SetOut(sw);
            new Calc().Solve();
            Out.Flush();
        }

        public class Calc {
            public void Solve() {
                var N = NextBigInteger();
                var M = NextBigInteger();

                var ans = new bint(0);
                foreach (var s in M.DivisorList()) {
                    var t = M / s;
                    if (s * N <= M) ans = Utils.Utils.EMax(ans, s);
                    if (t * N <= M) ans = Utils.Utils.EMax(ans, t);
                }

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
            var tokenChars = new StringBuilder();
            var tokenFinished = false;
            var skipWhiteSpaceMode = true;
            while (!tokenFinished) {
                var nextChar = Read();
                if (nextChar == -1) {
                    tokenFinished = true;
                }
                else {
                    var ch = (char)nextChar;
                    if (char.IsWhiteSpace(ch)) {
                        if (skipWhiteSpaceMode) continue;
                        tokenFinished = true;
                        if (ch == '\r' && (Environment.NewLine == "\r\n")) {
                            Read();
                        }
                    }
                    else {
                        skipWhiteSpaceMode = false;
                        tokenChars.Append(ch);
                    }
                }
            }

            var token = tokenChars.ToString();
            return token;
        }

        public static int NextInt() {
            var token = NextToken();
            return int.Parse(token);
        }
        public static long NextLong() {
            var token = NextToken();
            return long.Parse(token);
        }
        public static double NextDouble(bool acceptAnyDecimalSeparator = true) {
            var token = NextToken();
            if (acceptAnyDecimalSeparator) {
                token = token.Replace(',', '.');
                var result = double.Parse(token, CultureInfo.InvariantCulture);
                return result;
            }
            else {
                var result = double.Parse(token);
                return result;
            }
        }
        public static decimal NextDecimal(bool acceptAnyDecimalSeparator = true) {
            var token = NextToken();
            if (acceptAnyDecimalSeparator) {
                token = token.Replace(',', '.');
                var result = decimal.Parse(token, CultureInfo.InvariantCulture);
                return result;
            }
            else {
                var result = decimal.Parse(token);
                return result;
            }
        }

        public static BigInteger NextBigInteger(bool acceptAnyDecimalSeparator = true) {
            var token = NextToken();
            if (!acceptAnyDecimalSeparator) return BigInteger.Parse(token);
            token = token.Replace(',', '.');
            return BigInteger.Parse(token, CultureInfo.InvariantCulture);
        }

    }
}

namespace CS_Contest.Loop {
    [DebuggerStepThrough]
    public static class Loop {
        public static void Rep(this int n, Action<int> act) {
            for (var i = 0; i < n; i++) {
                act(i);
            }
        }

        public static void Rep(this Tuple<int, int> n, Action<int> act) {
            for (var i = n.Item1; i < n.Item2; i++) act(i);
        }

        public static void Rrep(this int n, Action<int> act) {
            for (var i = n - 1; i >= 0; i--) act(i);
        }

        public static void ForeachWith<T>(this IEnumerable<T> ie, Action<int, T> act) {
            var i = 0;
            foreach (var item in ie) {
                act(i, item);
                i++;
            }
        }

    }

    [DebuggerStepThrough]
    public class Generate {
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

        public static T[,] MakeBox<T>(int H, int W, T def = default(T)) {
            var rt = new T[H, W];
            for (var i = 0; i < H; i++)
            for (var j = 0; j < W; j++)
                rt[i, j] = def;
            return rt;
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
        public static Li NextIntList(int n) => Enumerable.Repeat(0, n).Select(x => ReadLine()).Select(int.Parse).ToList();
        public static Ll NextLongList() => ReadLine().Split().Select(long.Parse).ToList();

        public static string NextLine() => ReadLine();

        public static T Tee<T>(this T t, Func<T, string> formatter = null) {
            if (formatter == null) formatter = arg => arg.ToString();
            formatter(t).WL();
            return t;
        }
        public static void JoinWL<T>(this IEnumerable<T> @this, string sp = " ") => @this.StringJoin(sp).WL();
        public static void W(this object @this) => Write(@this);

        public static T[,] GetBox<T>(int h, int w, Func<int, int, T> getFunc) {
            var rt = new T[h, w];
            for (var i = 0; i < h; i++) {
                for (var j = 0; j < w; j++) {
                    rt[i, j] = getFunc(i, j);
                }
            }

            return rt;
        }

        public static void YesNo(this bool @this) => (@this ? "Yes" : "No").WL();
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

        public static IEnumerable<BigInteger> DivisorList(this BigInteger @this){
            for (BigInteger B = 1; B * B <= @this; B++)
                if (@this % B == 0)
                    yield return B;
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
                var mid = (ub + lb) >> 1;
                if (@this[mid].CompareTo(x) >= 0) ub = mid;
                else lb = mid;
            }

            return ub;
        }

        public static int UpperBound<T>(this List<T> @this, T x) where T : IComparable {
            int lb = -1, ub = @this.Count;
            while (ub - lb > 1) {
                var mid = (ub + lb) >> 1;
                if (@this[mid].CompareTo(x) > 0) ub = mid;
                else lb = mid;
            }

            return ub;
        }

        public static List<int> Imos(this IEnumerable<int> @this) {
            var rt = @this.ToList();
            for (var i = 0; i < rt.Count - 1; i++) rt[i + 1] += rt[i];
            return rt;
        }

        public static List<long> Imos(this IEnumerable<long> @this) {
            var rt = @this.ToList();
            for (var i = 0; i < rt.Count - 1; i++) rt[i + 1] += rt[i];
            return rt;
        }

        public static bool IsOdd(this long @this) => @this % 2 == 1;
        public static bool IsOdd(this int @this) => @this % 2 == 1;
        public static bool IsOdd(this bint @this) => @this % 2 == 1;

        public static void Add<T1, T2, T3, T4>(this List<Tuple<T1, T2, T3, T4>> @this, T1 t1, T2 t2, T3 t3, T4 t4) =>
            @this.Add(Tuple.Create(t1, t2, t3, t4));

        public static bool IsKaibun(string s) => s == s.Reverse().StringJoin();

        public static T EMin<T>(params T[] a) where T : IComparable<T> => a.Min();
        public static T EMax<T>(params T[] a) where T : IComparable<T> => a.Max();
    }

    public class Map<TKey, TValue> : Dictionary<TKey, TValue> {
        private readonly TValue Default = default(TValue);

        public Map(TValue def = default(TValue)) : base() {
            Default = def;
        }

        public new TValue this[TKey index] {
            get {
                TValue v;
                return TryGetValue(index, out v) ? v : base[index] = Default;
            }
            set { base[index] = value; }
        }
    }
}