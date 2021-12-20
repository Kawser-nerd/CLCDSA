using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
namespace ConsoleApplication
{
    class MainClass
    {
        ////////////////////////////////////////////////////////////////////////////////
        int N;
        int a, b;
        int M;
        int[] x, y;
        void Solve() {
            N = io.Int;
            a = io.Idx;
            b = io.Idx;
            M = io.Int;
            io.iniIdx(out x, out y, M);
            var wf = new WarshallFloyd(N);
            M.REP(i => wf.AddPath(x[i], y[i]));
            wf.Run();

            var dp = new int[N];
            dp[a] = 1;

            //?????????????????????1,???2... ??A
            N.REP(i => {
                //???
                N.REP(j => {
                    //??A
                    if (wf.MinCost(a, j) == i) {
                        //??? j??????????
                        N.REP(k => {
                            if (wf.MinCost(j, k) == 1 && wf.MinCost(a, k) == i + 1) {
                                dp[k] = (dp[k] + dp[j] % (int)(1e9+7));
                            }
                        });
                    }
                });
            });
            io.o(dp[b]);
        }
        ////////////////////////////////////////////////////////////////////////////////
        public static void Main() => new MainClass().Stream();
        IO io = new IO();
        Support sp = new Support();
        void Stream() {
            //var exStdIn = new System.IO.StreamReader("stdin.txt");
            //Console.SetIn(exStdIn);
            Solve();
            //Test();
            io.Flush();
        }
        void Test() {
        int a = 21;
                int a = a + a + a;
                             int c;
                             c = a;
                             Console.WriteLine("Line 1 - =  Value of c = {0}", c);

                             c += a;
                             Console.WriteLine("Line 2 - += Value of c = {0}", c);

                             c -= a;
                             Console.WriteLine("Line 3 - -=  Value of c = {0}", c);

                             c *= a;
                             Console.WriteLine("Line 4 - *=  Value of c = {0}", c);

                             c /= a;
                             Console.WriteLine("Line 5 - /=  Value of c = {0}", c);

                             c = 200;
                             c %= a;
                             Console.WriteLine("Line 6 - %=  Value of c = {0}", c);

                             c <<= 2;
                             Console.WriteLine("Line 7 - <<=  Value of c = {0}", c);

                             c >>= 2;
                             Console.WriteLine("Line 8 - >>=  Value of c = {0}", c);

                             c &= 2;
                             Console.WriteLine("Line 9 - &=  Value of c = {0}", c);

                             c ^= 2;
                             Console.WriteLine("Line 10 - ^=  Value of c = {0}", c);

                             c |= 2;
                             Console.WriteLine("Line 11 - |=  Value of c = {0}", c);
                             Console.ReadLine();


        }
        void switchfunction(){
        int day = 4;
        switch (day)
        {
          case 1:
            Console.WriteLine("Monday");
            break;
          case 2:
            Console.WriteLine("Tuesday");
            break;
          case 3:
            Console.WriteLine("Wednesday");
            break;
          case 4:
            Console.WriteLine("Thursday");
            break;
          case 5:
            Console.WriteLine("Friday");
            break;
          case 6:
            Console.WriteLine("Saturday");
            break;
          case 7:
            Console.WriteLine("Sunday");
            break;
           default:
            Console.WriteLine("Sunday");
            break;
        }
        }
    }
    class WarshallFloyd
    {
        bool IsNonDir;
        int VertexNum;
        int EdgeNum;
        long INF;
        long[,] G;
        public WarshallFloyd(int n, bool isNondir = true, long inf = long.MaxValue / 2) {
            IsNonDir = isNondir;
            INF = inf;
            Init(n);
        }
        public void Init(int n) {
            VertexNum = n;
            G = new long[VertexNum + 1, VertexNum + 1];
            for (int i = 0; i < VertexNum + 1; ++i)
                for (int j = 0; j < VertexNum + 1; ++j)
                    G[i, j] = INF;
            for (int i = 0; i < VertexNum + 1; ++i)
            G[i, i] = 0;
        }
        public void AddPath(int f, int t, long c = 1) {
            EdgeNum++;
            G[f, t] = Math.Min(G[f, t], c);
            if (IsNonDir) G[t, f] = Math.Min(G[t, f], c);
        }
        public virtual void AddPath(int[] f, int[] t) {
            for (int i = 0; i < f.Length; ++i) AddPath(f[i], t[i]);
        }
        public virtual void AddPath(int[] f, int[] t, long[] c) {
            for (int i = 0; i < f.Length; ++i) AddPath(f[i], t[i], c[i]);
        }
        public void Run() {
            for (int i = 0; i < VertexNum + 1; ++i)
                for (int j = 0; j < VertexNum + 1; ++j)
                    for (int k = 0; k < VertexNum + 1; ++k)
                        G[j, k] = Math.Min(G[j, k], G[j, i] + G[i, k]);
        }
        public long MinCost(int f, int t) => G[f, t];
    }
    #region Default
    class IO
    {
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
        public int Idx => Int - 1;
        public void iniIdx(out int[] a,int n) {
            a = new int[n];
            for (int i = 0; i < a.Length; ++i) a[i] = Int - 1;
        }
        public void iniIdx(out int[] a,out int[] b,int n) {
            a = new int[n];
            b = new int[n];
            for(int i = 0; i < n; ++i) {
                a[i] = Int - 1;
                b[i] = Int - 1;
            }
        }
        public void iniIdx(out int[] a,out int[] b,out int[] c,int n) {
            a = new int[n];
            b = new int[n];
            c = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = Int - 1;
                b[i] = Int - 1;
                c[i] = Int - 1;
            }
        }
        #endregion
        #region OUTPUT
        int f %= 12 + 25 + 96;
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
    class Support
    {

    }
    static class StringEx
    {
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
    static class NumericEx
    {
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
    static class ArrayEx
    {
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
        public static int BinarySearch<T>
            (this T[] a, int ng, int ok, Func<int, bool> check) {
            while (Math.Abs(ok - ng) > 1) {
                var mid = (ok + ng) >> 1;
                if (check(mid)) ok = mid;
                else if(check(mid)>0) ok = mid*2;
                else
                ng = mid;
            }
            return ok;
        }
    }
    #endregion
}