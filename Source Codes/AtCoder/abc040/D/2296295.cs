using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
namespace ConsoleApplication {
    class MainClass {
        ////////////////////////////////////////////////////////////////////////////////        
        int N, M, Q;
        int[] a, b, y, v, w;
        void Solve() {
            io.i(out N, out M);
            io.ini(out a, out b, out y, M);
            io.i(out Q);
            io.ini(out v, out w, Q);

            var uf  = new UnionFind(N);
            var aby = new Tuple<int, int, int>[M];
            var vwi = new Tuple<int, int,int>[Q];
            var abyQueue = new Queue<Tuple<int,int,int>>();
            var vwiQueue = new Queue<Tuple<int, int, int>>();

            M.REP(i => aby[i] = Tuple.Create(a[i], b[i], y[i]));
            Q.REP(i => vwi[i] = Tuple.Create(v[i], w[i], i));

            foreach (var v in aby.OrderByDescending(t => t.Item3).ToArray())
                abyQueue.Enqueue(v);
            foreach (var v in vwi.OrderByDescending(t => t.Item2).ToArray())
                vwiQueue.Enqueue(v);

            var ans = new int[Q];

            while (vwiQueue.Any()) {
                var cur = vwiQueue.Dequeue();
                var city = cur.Item1;
                var year = cur.Item2;
                var idx = cur.Item3;
                while (abyQueue.Any() && abyQueue.First().Item3>year) {
                    var cur2 = abyQueue.Dequeue();
                    var a = cur2.Item1;
                    var b = cur2.Item2;
                    uf.Unite(a, b);
                }
                ans[idx] = uf.Size(city);
            }

            io.o(ans);

        }

        ////////////////////////////////////////////////////////////////////////////////
        public static void Main() => new MainClass().Stream();
        IO io = new IO();
        void Stream() {
            Solve();
            //Test();
            io.Flush();
        }
        void Test() {

        }
    }
    class UnionFind {
        private int[] data;
        public UnionFind(int n) {
            data = new int[n + 1];
            for (int i = 0; i < n + 1; ++i) data[i] = -1;
        }
        public void Unite(int x, int y) {
            x = Root(x); y = Root(y); if (x == y) return;
            if (data[y] < data[x]) Swap(ref x, ref y);
            data[x] += data[y];
            data[y] = x;
        }
        public bool Find(int x, int y) => Root(x) == Root(y);
        public int Root(int x) => data[x] < 0 ? x : Root(data[x]);
        public int Size(int x) => -data[Root(x)];
        private void Swap(ref int a, ref int b) {
            int tmp = b;
            b = a;
            a = tmp;
        }
    }
    #region Default
    class IO {
        #region INPUT
        int _buffCnt;
        string[] _nextBuff;
        private readonly char[] _splitCharacter = new char[] { ' ' };
        private readonly StreamWriter _sw =
            new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
        public IO() {
            _nextBuff = new string[0];
            _buffCnt = 0;
            Console.SetOut(_sw);
        }
        private string Next() {
            if (_buffCnt < _nextBuff.Length) return _nextBuff[_buffCnt++];
            var str = Scan;
            while (str == "") str = Scan;
            _nextBuff = str.Split(_splitCharacter, StringSplitOptions.RemoveEmptyEntries);
            _buffCnt = 0;
            return _nextBuff[_buffCnt++];
        }
        private string Scan => Console.ReadLine();
        private void Read<T>(out T v) => v = SuitType<T>(Next());
        private T ConvertType<T, TU>(TU v) => (T)Convert.ChangeType(v, typeof(T));
        private bool TypeEqual<T, TU>() => typeof(T) == typeof(TU);
        private T SuitType<T>(string s)
            => TypeEqual<T, int>()
                ? ConvertType<T, int>(int.Parse(s))
                : TypeEqual<T, long>()
                ? ConvertType<T, long>(long.Parse(s))
                : TypeEqual<T, double>()
                ? ConvertType<T, double>(double.Parse(s))
                : TypeEqual<T, char>()
                ? ConvertType<T, char>(char.Parse(s))
                : ConvertType<T, string>(s);
        public string String => Next();
        public char Char => char.Parse(Next());
        public int Int => int.Parse(Next());
        public long Long => long.Parse(Next());
        public double Double => double.Parse(Next());
        public void Flush() => Console.Out.Flush();
        private T i<T>() => SuitType<T>(String);
        public void i<T>(out T v) => Read(out v);
        public void i<T, TU>(out T t, out TU u) {
            i(out t);
            i(out u);
        }
        public void i<T, TU, TV>(out T t, out TU u, out TV v) {
            i(out t, out u);
            i(out v);
        }
        public void i<T, TU, TV, TW>(out T t, out TU u, out TV v, out TW w) {
            i(out t, out u, out v);
            i(out w);
        }
        public void i<T, TU, TV, TW, TX>(out T t, out TU u, out TV v, out TW w, out TX x) {
            i(out t, out u, out v, out w);
            i(out x);
        }
        public void ini<T>(out T[] a, int n) {
            a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = i<T>();
        }
        public void ini<T, TU>(out T[] a, out TU[] b, int n) {
            a = new T[n];
            b = new TU[n];
            for (int i = 0; i < n; ++i) {
                a[i] = i<T>();
                b[i] = i<TU>();
            }
        }
        public void ini<T, TU, TV>(out T[] a, out TU[] b, out TV[] c, int n) {
            a = new T[n];
            b = new TU[n];
            c = new TV[n];
            for (int i = 0; i < n; ++i) {
                a[i] = i<T>();
                b[i] = i<TU>();
                c[i] = i<TV>();
            }
        }
        public void ini<T>(out T[,] a, int h, int w) {
            a = new T[h, w];
            for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) a[i, j] = i<T>();
        }
        public void ini<T, TU>(out Tuple<T, TU>[] t, int n) {
            t = new Tuple<T, TU>[n];
            for (int j = 0; j < n; ++j) {
                T i1;
                TU i2;
                i(out i1, out i2);
                t[j] = Tuple.Create(i1, i2);
            }
        }
        public void ini<T, TU, TV>(out Tuple<T, TU, TV>[] t, int n) {
            t = new Tuple<T, TU, TV>[n];
            for (int j = 0; j < n; ++j) {
                T i1;
                TU i2;
                TV i3;
                i(out i1, out i2, out i3);
                t[j] = Tuple.Create(i1, i2, i3);
            }
        }
        #endregion
        #region OUTPUT
        private void Out<T>(T v) => Console.Write(v);
        private void OutLine<T>(T v) => Console.WriteLine(v);
        public void o() => OutLine("");
        public void o<T>(T v) => OutLine(v);
        public void o<T>(params T[] a) => Array.ForEach(a, OutLine);
        public void o<T>(T[,] a) {
            int a0 = a.GetLength(0), a1 = a.GetLength(1);
            for (int i = 0; i < a0; ++i) {
                for (int j = 0; j < a1 - 1; ++j) Out(a[i, j] + " ");
                OutLine(a[i, a1 - 1]);
            }
        }
        public void ol<T>(params T[] a) => OutLine(string.Join(" ", a));
        public void YN(bool f) => OutLine(f ? "YES" : "NO");
        public void Yn(bool f) => OutLine(f ? "Yes" : "No");
        public void yn(bool f) => OutLine(f ? "yes" : "no");
        #endregion
    }
    #endregion
    #region MyEx
    static class StringEx {
        public static string Reversed(this string s) => string.Join("", s.Reverse());
        public static string Repeated(this string s, int n) => string.Concat(Enumerable.Repeat(s, n).ToArray());
        public static string toString(this char[] a) => new string(a);
        public static int toInt(this string s) {
            int n;
            return (int.TryParse(s.TrimStart('0'), out n)) ? n : 0;
        }
        public static int toInt(this char c) => toInt(c.ToString());
        public static int toInt(this char[] c) => toInt(c.toString());
        public static long toLong(this string s) {
            long n;
            return (long.TryParse(s.TrimStart('0'), out n)) ? n : 0L;
        }
        public static long toLong(this char c) => toLong(c.ToString());
        public static long toLong(this char[] c) => toLong(c.toString());
    }
    static class NumericEx {
        public static string toString(this double d) => d.ToString("R", CultureInfo.InvariantCulture);
        public static string Pad0<T>(this T s, int n) => s.ToString().PadLeft(n, '0');
        public static string RoundUp(this double v) => Math.Ceiling(v).toString();
        public static string RoundDown(this double v) => Math.Floor(v).toString();
        public static string RoundOff(this double v, int n)
            => Math.Round(v, n - 1, MidpointRounding.AwayFromZero).toString();
        public static bool Odd(this int v) => (v & 1) != 0;
        public static bool Odd(this long v) => (v & 1) != 0;
        public static void REP(this int v, Action<int> act) {
            for (int i = 0; i < v; ++i) act(i);
        }
        public static void REPR(this int v, Action<int> act) {
            for (int i = v - 1; i >= 0; --i) act(i);
        }
    }
    static class ArrayEx {
        public static T[] Sort<T>(this T[] a) {
            Array.Sort(a);
            return a;
        }
        public static T[] SortR<T>(this T[] a) {
            Array.Reverse(a.Sort());
            return a;
        }
        public static void Set<T>(this T[] a, T v) => a.Length.REP(i => a[i] = v);
        public static void Set<T>(this T[,] a, T v) => a.GetLength(0).REP(i => a.GetLength(1).REP(j => a[i, j] = v));
        public static void Set<T>(this T[,,] a, T v)
            => a.GetLength(0).REP(i => a.GetLength(1).REP(j => a.GetLength(2).REP(k => a[i, j, k] = v)));
        public static int BinarySearch<T>(this T[] a, int ng, int ok, Func<int, bool> check) {
            while (Math.Abs(ok - ng) > 1) {
                var mid = (ok + ng) >> 1;
                if (check(mid)) ok = mid;
                else ng = mid;
            }
            return ok;
        }
    }
    #endregion
}