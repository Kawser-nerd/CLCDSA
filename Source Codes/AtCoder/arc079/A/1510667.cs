using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
namespace AtCoder {
    class MainClass {
        //C#7.0/////////////////////////////////////////////////////
        int N, M;
        int[] a, b;
        void Solve() {
            io.i(out N, out M);
            io.ini(out a, out b, M);
            REP(M, i => { a[i]--; b[i]--; });

            //List<int> from1, toN;
            HashSet<int> from1, toN;
            from1 = new HashSet<int>();
            REP(M, i => {
                if (a[i] == 0) from1.Add(b[i]);
                if (b[i] == 0) from1.Add(a[i]);
            });
            toN = new HashSet<int>();
            REP(M, i => {
                if (a[i] == N-1) toN.Add(b[i]);
                if (b[i] == N-1) toN.Add(a[i]);
            });

            bool f = from1.Any(v => toN.Contains(v));

            io.o(f?"POSSIBLE":"IMPOSSIBLE");

        }

        ////////////////////////////////////////////////////////////
        public static void Main(string[] args) { new MainClass().Stream(); }
        IO io = new IO();
        void Stream() { Solve(); io.writeFlush(); }
        //void Stream() { Test(); io.writeFlush(); }
        void Test() { }
        #region MockMacro
        //Hack Update
        //cannot use break,continue,goto
        void FOR(int a, int b, Action<int> act, int c = 1) { for (int i = a; i < b; i += c) act(i); }
        void FOR(int a, int b, Action<int> act, Func<int, bool> con, int c = 1) { for (int i = a; i < b && con(i); i += c) act(i); }
        void RFOR(int a, int b, Action<int> act, int c = 1) { for (int i = a; i >= b; i -= c) act(i); }
        void RFOR(int a, int b, Action<int> act, Func<int, bool> con, int c = 1) { for (int i = a; i >= b && con(i); i -= c) act(i); }
        void REP(int n, Action<int> act, Func<int, bool> con, int c = 1) { for (int i = 0; i < n && con(i); i += c) act(i); }
        void REP(int n, Action<int> act, int c = 1) { for (int i = 0; i < n; i += c) act(i); }
        void RREP(int n, Action<int> act, int c = 1) { for (int i = n - 1; i >= 0; i -= c) act(i); }
        void RREP(int n, Action<int> act, Func<int, bool> con) { for (int i = n - 1; i >= 0 && con(i); i--) act(i); }
        #endregion
    }
    #region default
    class IO {
        TYPE tp;
        string[] nextBuffer; int BufferCnt; char[] cs = new char[] { ' ' };
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
        public IO() { nextBuffer = new string[0]; BufferCnt = 0; Console.SetOut(sw); tp = new TYPE(); }
        public string Next() {
            if (BufferCnt < nextBuffer.Length) return nextBuffer[BufferCnt++];
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            BufferCnt = 0;
            return nextBuffer[BufferCnt++];
        }
        public string String => Next();
        public char Char => char.Parse(String);
        public int Int => int.Parse(String);
        public long Long => long.Parse(String);
        public double Double => double.Parse(String);
        public string[] arr => Console.ReadLine().Split(' ');
        public char[] arrChar => Array.ConvertAll(arr, char.Parse);
        public int[] arrInt => Array.ConvertAll(arr, int.Parse);
        public long[] arrLong => Array.ConvertAll(arr, long.Parse);
        public double[] arrDouble => Array.ConvertAll(arr, double.Parse);
        public T i<T>() { return tp.suitType<T>(String); }
        public void i<T>(out T v) { v = tp.suitType<T>(String); }
        public void i<T, U>(out T v1, out U v2) { i(out v1); i(out v2); }
        public void i<T, U, V>(out T v1, out U v2, out V v3) { i(out v1); i(out v2); i(out v3); }
        public void i<T, U, V, W>(out T v1, out U v2, out V v3, out W v4) { i(out v1); i(out v2); i(out v3); i(out v4); }
        public void i<T, U, V, W, X>(out T v1, out U v2, out V v3, out W v4, out X v5) { i(out v1); i(out v2); i(out v3); i(out v4); i(out v5); }
        public void ini<T>(out T[] a, int n) { a = new T[n]; for (int i = 0; i < n; i++) a[i] = tp.suitType<T>(String); }
        public void ini<T>(out T[] a, out T[] b, int n) { a = new T[n]; b = new T[n]; for (int i = 0; i < n; i++) { a[i] = i<T>(); b[i] = i<T>(); } }
        public void ini<T>(out T[,] a, int h, int w) { a = new T[h, w]; for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) a[i, j] = i<T>(); }
        public void o<T>(T v) { Console.WriteLine(v); }
        public void o<T>(params T[] a) { Array.ForEach(a, n => o(n)); }
        public void o<T>(List<T> l) { o(l.ToArray()); }
        public void ol<T>(T v) { Console.Write(v + " "); }
        public void ol<T>(params T[] a) { Array.ForEach(a, n => ol(n)); br(); }
        public void ol<T>(List<T> l) { ol(l.ToArray()); }
        public void br() { o(""); }
        public void writeFlush() { Console.Out.Flush(); }
    }
    class Operation<T> {
        public Operation() {
            var availableT = new Type[] { typeof(int), typeof(long), typeof(double) };
            if (!availableT.Contains(typeof(T))) throw new NotSupportedException();
            var p1 = Expression.Parameter(typeof(T));
            var p2 = Expression.Parameter(typeof(T));
            Add = Expression.Lambda<Func<T, T, T>>(Expression.Add(p1, p2), p1, p2).Compile();
            Sub = Expression.Lambda<Func<T, T, T>>(Expression.Subtract(p1, p2), p1, p2).Compile();
            Mul = Expression.Lambda<Func<T, T, T>>(Expression.Multiply(p1, p2), p1, p2).Compile();
            Div = Expression.Lambda<Func<T, T, T>>(Expression.Divide(p1, p2), p1, p2).Compile();
            Mod = Expression.Lambda<Func<T, T, T>>(Expression.Modulo(p1, p2), p1, p2).Compile();
            EQ = Expression.Lambda<Func<T, T, bool>>(Expression.Equal(p1, p2), p1, p2).Compile();
            GT = Expression.Lambda<Func<T, T, bool>>(Expression.GreaterThan(p1, p2), p1, p2).Compile();
            GE = Expression.Lambda<Func<T, T, bool>>(Expression.GreaterThanOrEqual(p1, p2), p1, p2).Compile();
            LT = Expression.Lambda<Func<T, T, bool>>(Expression.LessThan(p1, p2), p1, p2).Compile();
            LE = Expression.Lambda<Func<T, T, bool>>(Expression.LessThanOrEqual(p1, p2), p1, p2).Compile();
        }
        public Func<T, T, T> Add { get; private set; }
        public Func<T, T, T> Sub { get; private set; }
        public Func<T, T, T> Mul { get; private set; }
        public Func<T, T, T> Div { get; private set; }
        public Func<T, T, T> Mod { get; private set; }
        public Func<T, T, bool> EQ { get; private set; }
        public Func<T, T, bool> GT { get; private set; }
        public Func<T, T, bool> GE { get; private set; }
        public Func<T, T, bool> LT { get; private set; }
        public Func<T, T, bool> LE { get; private set; }
    }
    class OP {
        //Mat????...
        public T Add<T>(T a, T b) { var op = new Operation<T>(); return op.Add(a, b); }
        public T Sub<T>(T a, T b) { var op = new Operation<T>(); return op.Sub(a, b); }
        public T Mul<T>(T a, T b) { var op = new Operation<T>(); return op.Mul(a, b); }
        public T Div<T>(T a, T b) { var op = new Operation<T>(); return op.Div(a, b); }
        public T Mod<T>(T a, T b) { var op = new Operation<T>(); return op.Mod(a, b); }
        public bool EQ<T>(T a, T b) { var op = new Operation<T>(); return op.EQ(a, b); }
        public bool GT<T>(T a, T b) { var op = new Operation<T>(); return op.GT(a, b); }
        public bool GE<T>(T a, T b) { var op = new Operation<T>(); return op.GE(a, b); }
        public bool LT<T>(T a, T b) { var op = new Operation<T>(); return op.LT(a, b); }
        public bool LE<T>(T a, T b) { var op = new Operation<T>(); return op.LE(a, b); }
    }
    class TYPE {
        public bool typeEQ<T, U>() { return typeof(T).Equals(typeof(U)); }
        public T convertType<T, U>(U v) { return (T)Convert.ChangeType(v, typeof(T)); }
        public T suitType<T>(string s) {
            if (typeEQ<T, int>()) return convertType<T, int>(int.Parse(s));
            if (typeEQ<T, long>()) return convertType<T, long>(long.Parse(s));
            if (typeEQ<T, double>()) return convertType<T, double>(double.Parse(s));
            if (typeEQ<T, char>()) return convertType<T, char>(char.Parse(s));
            return convertType<T, string>(s);
        }
    }
    #endregion
    #region other
    class Mat {
        OP op;
        public Mat() { op = new OP(); }
        public int mod = 1000000007;//10^9+7
        public long Pow(long a, long b) {
            if (b == 0) return 1;
            if (b % 2 == 1) return (a % mod * Pow(a % mod, b - 1) % mod) % mod;
            else return Pow(a * a % mod, b / 2) % mod;
        }
        public long Fact(long n) {
            return (n != 0) ? (n % mod * (Fact(n - 1) % mod) % mod) : 1;
        }
        public long C(long n, long r) {
            if (r == 0 || n == r) return 1;
            else return (Fact(n) % mod * Pow((Fact(n - r) % mod * Fact(r) % mod) % mod, mod - 2) % mod) % mod;
        }
        public bool isPrime(long n) {
            if (n == 2) return true; if (n < 2 || n % 2 == 0) return false;
            for (long v = 3; v <= (long)Math.Sqrt(n); v += 2) if (n % v == 0) return false;
            return true;
        }
        public long LCM(long a, long b) { return a * (b / GCD(a, b)); }
        public long LCM(params long[] a) { return a.Aggregate((v, n) => LCM(v, n)); }
        public long GCD(long a, long b) { if (a < b) Swap(ref a, ref b); return b == 0 ? a : GCD(b, a % b); }
        public long GCD(params long[] array) { return array.Aggregate((v, next) => GCD(v, next)); }
        public void Swap<T>(ref T a, ref T b) { T tmp = a; a = b; b = tmp; }
        public T Max<T>(params T[] v) { return v.Max(); }
        public T Min<T>(params T[] v) { return v.Min(); }
        public double Dis(int x1, int y1, int x2, int y2) { return Math.Sqrt(Math.Pow((x2 - x1), 2) + Math.Pow((y2 - y1), 2)); }
        public int mDis(int x1, int y1, int x2, int y2) { return Math.Abs(x1 - x2) + Math.Abs(y1 - y2); }
        public int Digit(long n) { return (n == 0) ? 1 : (int)Math.Log10(n) + 1; }
        public int DigVal(int n, int dig) { return (n % (int)Pow(10, dig)) / (int)Pow(10, dig - 1); }
        public int[] DigValArr(int n) { int[] ret = new int[Digit(n)]; M.REP(ret.Length, i => ret[i] = DigVal(n, i + 1)); return ret; }
        public int Clamp(int n, int a, int b) { return (n < a) ? a : (b < n) ? b : n; }
        public long Clamp(long n, long a, long b) { return (n < a) ? a : (b < n) ? b : n; }
        public double Clamp(double n, double a, double b) { return (n < a) ? a : (b < n) ? b : n; }
        public long Tousa(long a, long d, int n) { return a + (n - 1) * d; }
        public long TousaSum(long a, long d, int n) { return n * (2 * a + (n - 1) * d) / 2; }
    }
    class AssociativeArray<T> {//hack:???????
        public Dictionary<T, int> dic;
        public AssociativeArray() { dic = new Dictionary<T, int>(); }
        public AssociativeArray(params T[] a) { dic = new Dictionary<T, int>(); Add(a); }
        public void Add(params T[] a) { M.REP(a.Length, i => { if (!conK(a[i])) dic[a[i]] = 0; dic[a[i]]++; }); }
        public void Set(T k, int v) { if (!dic.ContainsKey(k)) dic[k] = 0; dic[k] = v; }
        public void Remove(params T[] a) { M.REP(a.Length, i => { if (conK(a[i])) dic.Remove(a[i]); }); }
        public T[] Keys() { return dic.Keys.ToArray<T>(); }
        public int Val(T k) { return (dic.ContainsKey(k)) ? dic[k] : 0; }
        public int ValSum => dic.Values.Sum();
        public int KeyNum => dic.Keys.Count;
        public int MaxVal => dic.Values.Max();
        public int MinVal => dic.Values.Min();
        public T MaxKey => dic.First(d => d.Value == MaxVal).Key;
        public T MinKey => dic.First(d => d.Value == MinVal).Key;
        public bool conK(T k) { return dic.ContainsKey(k); }
        public bool anyK(params T[] k) { return k.Any(key => conK(key)); }
        public bool allK(params T[] k) { return k.All(key => conK(key)); }
        public void Show() { foreach (var v in dic) { Console.WriteLine(v.Key + " : " + v.Value); } }
        //:sort->array
    }
    class wTree {//test
        public List<Tuple<long, long>>[] g;
        public long[] a2other;
        public void init(long n) { g = new List<Tuple<long, long>>[n + 1]; M.REP(g.Length, i => g[i] = new List<Tuple<long, long>>()); }
        public void Run(long[] a, long[] b, long[] w) { M.REP(a.Length, i => { g[a[i]].Add(Tuple.Create(b[i], w[i])); g[b[i]].Add(Tuple.Create(a[i], w[i])); }); }
        public void Cal(long a) {
            a2other = new long[g.Count()]; var q = new Queue<Tuple<long, long>>(); q.Enqueue(Tuple.Create(a, (long)-1));
            while (q.Count > 0) {
                var c = q.Dequeue();
                foreach (var v in g[c.Item1]) {
                    if (v.Item1 == c.Item2) continue;
                    a2other[v.Item1] = a2other[c.Item1] + v.Item2; q.Enqueue(Tuple.Create(v.Item1, c.Item1));
                }
            }
        }
    }
    class WarshallFloyd {
        int INF;
        public WarshallFloyd() { INF = (int)(1e8); }
        public WarshallFloyd(int INF) { this.INF = INF; }
        public int[,] Run(int[,] m) {
            int edgeLength = m.GetLength(0);
            for (int i = 0; i < edgeLength; i++)
                for (int j = 0; j < edgeLength; j++)
                    for (int k = 0; k < edgeLength; k++)
                        m[j, k] = Math.Min(m[j, k], m[j, i] + m[i, k]);
            return m;
        }
        public int[,] Init(int n) {
            int[,] m = new int[n, n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    m[i, j] = INF;
            for (int i = 0; i < n; i++)
                m[i, i] = 0;
            return m;
        }
    }
    class Time { public bool isLeapYear(int y) { return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)); } }

    #endregion
    #region Ex
    static class StringEX {//??
        public static string Reversed(this string s) { return string.Join("", s.Reverse()); }
        public static string Repeat(this string s, int n) { return string.Concat(Enumerable.Repeat(s, n).ToArray()); }
        public static int toInt(this string s) { int n; return (int.TryParse(s.TrimStart('0'), out n)) ? n : 0; }
        public static int toInt(this char c) { return toInt(c.ToString()); }
        public static int toInt(this char[] c) { return toInt(new string(c)); }
        public static string toString(this char[] c) { return new string(c); }
    }
    static class NumericEx {//??
        public static string pad0<T>(this T v, int n) { return v.ToString().PadLeft(n, '0'); }
    }
    static class ArrayEX {
        public static T[] Sort<T>(this T[] a) { Array.Sort(a); return a; }
        public static void Set<T>(this T[] a, T v) { M.REP(a.Length, i => a[i] = v); }
        public static void Set<T>(this T[,] a, T v) { M.REP(a.GetLength(0), i => M.REP(a.GetLength(1), j => a[i, j] = v)); }
    }
    static class BitEx {
        public static bool Any(this BitArray b) { foreach (bool f in b) if (f) return true; return false; }
        public static bool All(this BitArray b) { foreach (bool f in b) if (!f) return false; return true; }
        public static bool None(this BitArray b) { return !Any(b); }
        public static void Flip(this BitArray b, int index) { b.Set(index, !b.Get(index)); }
    }
    static class M {
        public static void REP(long n, Action<int> a) { for (int i = 0; i < n; i++) a(i); }
    }
    #endregion
}