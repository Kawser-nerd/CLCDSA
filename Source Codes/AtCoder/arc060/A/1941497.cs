using System;
using System.Collections;
using System.Collections.Generic;
//using System.Data.Odbc;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Reflection.Emit;
using System.Runtime.CompilerServices;
using System.Runtime.Remoting.Proxies;
using System.Security.Cryptography;
using System.Text;
using System.Xml.Schema;
namespace ConsoleApplication {
    class MainClass {
        ////////////////////////////////////////////////////////////////////////////////
        private int N, A;
        private int[] x;
        private long[,,] dp;
        void Solve() {
            io.i(out N, out A);
            io.ini(out x, N);
            dp = new long[N + 1, N + 1, N * 50 + 1];
            //FOR(0, N + 1, i => dp[i, 0, 0] = 1);
            dp[0, 0, 0] = 1;
            FOR(1, N + 1, i => FOR(0, N + 1, j => FOR(0, 50 * N + 1, k => {
                dp[i, j, k] = dp[i - 1, j, k];
                if(1 <= j && x[i - 1] <= k) 
                    dp[i, j, k] += dp[i - 1, j - 1, k - x[i - 1]];
            })));
            var ans = 0L;
            FOR(1, N + 1, i => ans += dp[N, i, A * i]);
            io.o(ans);
        }

        ////////////////////////////////////////////////////////////////////////////////
        public static void Main() => new MainClass().Stream();
        IO io = new IO();
        Mat mat = new Mat();
        void Stream() {
            Solve();
            //Test();
            io.Flush();
        }
        void Test() { }
        void FOR(int a, int b, Action <int> act) {
            for(int i = a; i < b; ++i) act(i);
        }
        void FORR(int a, int b, Action <int> act) {
            for(int i = a - 1; i >= b; --i) act(i);
        }
    }
    #region Default
    class IO {
        #region INPUT
        int _buffCnt;
        string[] _nextBuff;
        private readonly char[] _splitCharacter = new char[] {' '};
        private readonly StreamWriter _sw = new StreamWriter(Console.OpenStandardOutput()) {
            AutoFlush = false
        };
        public IO() {
            _nextBuff = new string[0];
            _buffCnt = 0;
            Console.SetOut(_sw);
        }
        private string Next() {
            if(_buffCnt < _nextBuff.Length) return _nextBuff[_buffCnt++];
            var str = Scan;
            while(str == "") str = Scan;
            _nextBuff = str.Split(_splitCharacter, StringSplitOptions.RemoveEmptyEntries);
            _buffCnt = 0;
            return _nextBuff[_buffCnt++];
        }
        private string Scan => Console.ReadLine();
        private string[] Arr => Scan.Split(' ');
        private void Read <T>(out T v) => v = SuitType <T>(Next());
        private T ConvertType <T, TU>(TU v) => (T)Convert.ChangeType(v, typeof(T));
        private bool TypeEqual <T, TU>() => typeof(T) == typeof(TU);
        private T SuitType <T>(string s)
            =>
                TypeEqual <T, int>()
                    ? ConvertType <T, int>(int.Parse(s))
                    : TypeEqual <T, long>()
                        ? ConvertType <T, long>(long.Parse(s))
                        : TypeEqual <T, double>()
                            ? ConvertType <T, double>(double.Parse(s))
                            : TypeEqual <T, char>() ? ConvertType <T, char>(char.Parse(s)) : ConvertType <T, string>(s);
        public string String => Next();
        public char Char => char.Parse(Next());
        public int Int => int.Parse(Next());
        public long Long => long.Parse(Next());
        public double Double => double.Parse(Next());
        public string[] ArrString => Arr;
        public char[] ArrChar => Array.ConvertAll(Arr, char.Parse);
        public int[] ArrInt => Array.ConvertAll(Arr, int.Parse);
        public long[] ArrLong => Array.ConvertAll(Arr, long.Parse);
        public double[] ArrDouble => Array.ConvertAll(Arr, double.Parse);
        public void Flush() => Console.Out.Flush();
        private T i <T>() { return SuitType <T>(String); }
        public void i <T>(out T v) => Read(out v);
        public void i <T, TU>(out T t, out TU u) {
            i(out t);
            i(out u);
        }
        public void i <T, TU, TV>(out T t, out TU u, out TV v) {
            i(out t, out u);
            i(out v);
        }
        public void i <T, TU, TV, TW>(out T t, out TU u, out TV v, out TW w) {
            i(out t, out u, out v);
            i(out w);
        }
        public void i <T, TU, TV, TW, TX>(out T t, out TU u, out TV v, out TW w, out TX x) {
            i(out t, out u, out v, out w);
            i(out x);
        }
        public void ini <T>(out T[] a, int n) {
            a = new T[n];
            for(int i = 0; i < n; ++i) a[i] = i <T>();
        }
        public void ini <T, TU>(out T[] a, out TU[] b, int n) {
            a = new T[n];
            b = new TU[n];
            for(int i = 0; i < n; ++i) {
                a[i] = i <T>();
                b[i] = i <TU>();
            }
        }
        public void ini <T, TU, TV>(out T[] a, out TU[] b, out TV[] c, int n) {
            a = new T[n];
            b = new TU[n];
            c = new TV[n];
            for(int i = 0; i < n; ++i) {
                a[i] = i <T>();
                b[i] = i <TU>();
                c[i] = i <TV>();
            }
        }
        public void ini <T>(out T[,] a, int h, int w) {
            a = new T[h, w];
            for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) a[i, j] = i <T>();
        }
        public void ini <T, TU>(out Tuple <T, TU>[] t, int n) {
            t = new Tuple <T, TU>[n];
            for(int j = 0; j < n; ++j) {
                T i1;
                TU i2;
                i(out i1, out i2);
                t[j] = Tuple.Create(i1, i2);
            }
        }
        public void ini <T, TU, TV>(out Tuple <T, TU, TV>[] t, int n) {
            t = new Tuple <T, TU, TV>[n];
            for(int j = 0; j < n; ++j) {
                T i1;
                TU i2;
                TV i3;
                i(out i1, out i2, out i3);
                t[j] = Tuple.Create(i1, i2, i3);
            }
        }
        #endregion
        #region OUTPUT
        private void Out <T>(T v) => Console.Write(v);
        private void OutLine <T>(T v) => Console.WriteLine(v);
        public void o <T>(T v) => OutLine(v);
        public void o <T>(params T[] a) => Array.ForEach(a, OutLine);
        public void o <T>(T[,] a) {
            int a0 = a.GetLength(0), a1 = a.GetLength(1);
            for(int i = 0; i < a0; ++i) {
                for(int j = 0; j < a1 - 1; ++j) Out(a[i, j] + " ");
                OutLine(a[i, a1 - 1]);
            }
        }
        public void ol <T>(params T[] a) => OutLine(string.Join(" ", a));
        public void YN(bool f) => OutLine(f ? "YES" : "NO");
        public void Yn(bool f) => OutLine(f ? "Yes" : "No");
        public void yn(bool f) => OutLine(f ? "yes" : "no");
        #endregion
    }
    class Mat {
        public long mod = 1000000007; //10^9+7
        public long Pow(long a, long b) {
            if(b == 0) return 1;
            if(b % 2 == 1) return (a % mod * Pow(a % mod, b - 1) % mod) % mod;
            else return Pow(a * a % mod, b / 2) % mod;
        }
        public long Fact(long n) {
            long ret = 1;
            for(long i = 1; i <= n; i++) ret = (ret * i) % mod;
            return ret;
        }
        public long[,] C(int N) {
            long[,] Co = new long[N + 1, N + 1];
            (N + 1).REP(i => (i + 1).REP(j => Co[i, j] = (j == 0 || j == i) ? 1L : Co[i - 1, j - 1] + Co[i - 1, j]));
            return Co;
        }
        public long C(long n, long r) {
            if(r == 0 || n == r) return 1;
            if(n == 0) return 0;
            if(n < 0 || n < r) throw new ArgumentException("n or r invalid");
            else return (Fact(n) % mod * Pow((Fact(n - r) % mod * Fact(r) % mod) % mod, mod - 2) % mod) % mod;
        }
        public long H(long n, long r) => C(n + r - 1, r);
        public long P(long n, long r) => Fact(n) / Fact(n - r);
        public long Lcm(long a, long b) => a * (b / Gcd(a, b));
        public long Lcm(params long[] a) => a.Aggregate((v, n) => Lcm(v, n));
        public long Gcd(long a, long b) {
            if(a < b) Swap(ref a, ref b);
            return b == 0 ? a : Gcd(b, a % b);
        }
        public long Gcd(params long[] array) => array.Aggregate((v, n) => Gcd(v, n));
        public T Max <T>(params T[] a) => a.Max();
        public T Min <T>(params T[] a) => a.Min();
        public void Swap <T>(ref T a, ref T b) {
            T tmp = a;
            a = b;
            b = tmp;
        }
        public double Dis(int x1, int y1, int x2, int y2) => Math.Sqrt(Math.Pow((x2 - x1), 2) + Math.Pow((y2 - y1), 2));
        public int ManhattanDis(int x1, int y1, int x2, int y2) => Math.Abs(x1 - x2) + Math.Abs(y1 - y2);
        public int[] DigArr(int n) {
            int[] ret = new int[Digit(n)];
            ret.Length.REP(i => ret[i] = DigVal(n, i + 1));
            return ret;
        }
        public long DigArr2Num(IEnumerable <int> enu) { return enu.Aggregate((v, n) => v * 10 + n); }
        public int Digit(long n) { return (n == 0) ? 1 : (int)Math.Log10(n) + 1; }
        public int DigVal(int n, int dig) { return (n % (int)Pow(10, dig)) / (int)Pow(10, dig - 1); }
        public long Tousa(long a, long d, long n) { return a + (n - 1) * d; }
        public long TousaSum(long a, long d, long n) { return n * (2 * a + (n - 1) * d) / 2; }
        public long[] EnuDivsor(long N) {
            var ret = new SortedSet <long>();
            for(long i = 1; i * i <= N; i++)
                if(N % i == 0) {
                    ret.Add(i);
                    ret.Add(N / i);
                }
            return ret.ToArray();
        }
        public Dictionary <long, long> PrimeFactor(long n) {
            var ret = new Dictionary <long, long>();
            for(int i = 2; i * i <= n; ++i) {
                if(!ret.ContainsKey(i)) ret[i] = 0;
                while(n % i == 0) {
                    ++ret[i];
                    n /= i;
                }
            }
            return ret.Where(kp => kp.Value != 0).ToDictionary(kp => kp.Key, kp => kp.Value);
        }
    }
    public struct Edge : IComparable <Edge> {
        public int To;
        public long Cost;
        public Edge(int to, long cost) {
            To = to;
            Cost = cost;
        }
        public int CompareTo(Edge e) => Cost.CompareTo(e.Cost);
    }
    #endregion
    #region MyEx
    static class StringEX {
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
    static class NumericEX {
        public static string toString(this double d) => d.ToString("R", CultureInfo.InvariantCulture);
        public static string Pad0 <T>(this T s, int n) => s.ToString().PadLeft(n, '0');
        public static string RoundOff(this double v, int n)
            => Math.Round(v, n - 1, MidpointRounding.AwayFromZero).toString();
        public static string RoundUp(this double v) => Math.Ceiling(v).toString();
        public static string RoundDown(this double v) => Math.Floor(v).toString();
        public static bool Odd(this int v) => (v & 1) != 0;
        public static bool Odd(this long v) => (v & 1) != 0;
        public static void REP(this int v, Action <int> act) {
            for(int i = 0; i < v; ++i) act(i);
        }
        public static void REPR(this int v, Action <int> act) {
            for(int i = v - 1; i >= 0; --i) act(i);
        }
        public static void EREP(this int v, Action <int> act) => (v + 1).REP(act);
    }
    static class ArrayEX {
        public static T[] Sort <T>(this T[] a) {
            Array.Sort(a);
            return a;
        }
        public static T[] SortR <T>(this T[] a) {
            Array.Reverse(a.Sort());
            return a;
        }
        public static void Set <T>(this T[] a, T v) => a.Length.REP(i => a[i] = v);
        public static void Set <T>(this T[,] a, T v) => a.GetLength(0).REP(i => a.GetLength(1).REP(j => a[i, j] = v));
        public static void Set <T>(this T[,,] a, T v)
            => a.GetLength(0).REP(i => a.GetLength(1).REP(j => a.GetLength(2).REP(k => a[i, j, k] = v)));
        public static int LowerBound <T>(this T[] a, T x) where T : IComparable {
            int lb = -1, ub = a.Length;
            while(ub - lb > 1) {
                int mid = (ub + lb) >> 1;
                if(a[mid].CompareTo(x) >= 0) ub = mid;
                else lb = mid;
            }
            return ub;
        }
        public static int UpperBound <T>(this T[] a, T x) where T : IComparable {
            int lb = -1, ub = a.Length;
            while(ub - lb > 1) {
                int mid = (ub + lb) >> 1;
                if(a[mid].CompareTo(x) > 0) ub = mid;
                else lb = mid;
            }
            return ub;
        }
        public static int Range <T>(this T[] a, T from, T to) where T : IComparable
            => a.UpperBound(to) - a.LowerBound(from);
    }
    #endregion
}