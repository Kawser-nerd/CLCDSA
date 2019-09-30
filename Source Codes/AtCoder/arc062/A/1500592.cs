using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
namespace AtCoder {
    class MainClass {
        //C#7.0/////////////////////////////////////////////////////
        int N;
        int[] T, A;
        void Solve() {
            io.i(out N);
            io.ini(out T, out A, N);

            long ca = 1, cb = 1;
            REP(N, i => {
                long n = Math.Max((ca-1)/T[i]+1, (cb-1)/A[i]+1);
                ca = n * T[i];
                cb = n * A[i];
            });

            io.ol(ca+cb);

        }
        
        ////////////////////////////////////////////////////////////
        public static void Main(string[] args) { new MainClass().Stream(); }
        IO io = new IO();
        void Stream() { Solve(); io.writeFlush(); }
        //void Stream() { Test(); io.writeFlush(); }
        void Test() {        }
        #region MockMacro
        //Hack Update
        void FOR(int a, int b, Action<int> act) { for (int i = a; i < b; i++) act(i); }
        void FOR(int a, int b, Action<int> act, Func<int, bool> con) { for (int i = a; i < b && con(i); i++) act(i); }
        void REP(int n, Action<int> act, Func<int, bool> con) { for (int i = 0; i < n && con(i); i++) act(i); }
        void REP(int n, Action<int> act) { for (int i = 0; i < n; i++) act(i); }
        void RREP(int n, Action<int> act) { for (int i = n - 1; i >= 0; i--) act(i); }
        void RREP(int n, Action<int> act, Func<int, bool> con) { for (int i = n - 1; i >= 0 && con(i); i--) act(i); }
        #endregion
    }
    #region default
    class IO {
        string[] nextBuffer; int BufferCnt; char[] cs = new char[] { ' ' };
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
        public IO() { nextBuffer = new string[0]; BufferCnt = 0; Console.SetOut(sw); }
        public string next() {
            if (BufferCnt < nextBuffer.Length) return nextBuffer[BufferCnt++];
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            BufferCnt = 0;
            return nextBuffer[BufferCnt++];
        }
        public char nextChar() { return char.Parse(next()); }
        public int nextInt() { return int.Parse(next()); }
        public long nextLong() { return long.Parse(next()); }
        public double nextDouble() { return double.Parse(next()); }
        public string[] arr() { return Console.ReadLine().Split(' '); }
        public char[] arrayChar() { return Array.ConvertAll(arr(), char.Parse); }
        public int[] arrayInt() { return Array.ConvertAll(arr(), int.Parse); }
        public long[] arrayLong() { return Array.ConvertAll(arr(), long.Parse); }
        public double[] arrayDouble() { return Array.ConvertAll(arr(), double.Parse); }
        private bool typeEQ<T, U>() { return typeof(T).Equals(typeof(U)); }
        private T convertType<T, U>(U v) { return (T)Convert.ChangeType(v, typeof(T)); }
        private T suitType<T>(string s) {
            if (typeEQ<T, int>()) return convertType<T, int>(int.Parse(s));
            if (typeEQ<T, long>()) return convertType<T, long>(long.Parse(s));
            if (typeEQ<T, double>()) return convertType<T, double>(double.Parse(s));
            if (typeEQ<T, char>()) return convertType<T, char>(char.Parse(s));
            return convertType<T, string>(s);
        }
        public void i<T>(out T v) { v = suitType<T>(next()); }
        public void i<T, U>(out T v1, out U v2) { i(out v1); i(out v2); }
        public void i<T, U, V>(out T v1, out U v2, out V v3) {
            i(out v1); i(out v2); i(out v3);
        }
        public void i<T, U, V, W>(out T v1, out U v2, out V v3, out W v4) {
            i(out v1); i(out v2); i(out v3); i(out v4);
        }
        public void i<T, U, V, W, X>(out T v1, out U v2, out V v3, out W v4, out X v5) {
            i(out v1); i(out v2); i(out v3); i(out v4); i(out v5);
        }
        public void ini(out int[] a, int size) {
            a = new int[size]; for (int i = 0; i < size; i++) a[i] = nextInt();
        }
        public void ini(out long[] a, int size) {
            a = new long[size]; for (int i = 0; i < size; i++) a[i] = nextLong();
        }
        public void ini(out int[] a1, out int[] a2, int size) {
            a1 = new int[size]; a2 = new int[size];
            for (int i = 0; i < size; i++) { a1[i] = nextInt(); a2[i] = nextInt(); }
        }
        public void ini(out long[] a1, out long[] a2, int size) {
            a1 = new long[size]; a2 = new long[size];
            for (int i = 0; i < size; i++) { a1[i] = nextLong(); a2[i] = nextLong(); }
        }
        public void ini(out int[,] g, int h, int w) {
            g = new int[h, w]; for (int i = 0; i < h; i++)
                for (int j = 0; j < w; j++) g[i, j] = nextInt();
        }
        public void ini(out string[] a, int size) {
            a = new string[size]; for (int i = 0; i < size; i++) a[i] = next();
        }
        public void inii(out int[] a, int size) {
            a = new int[size]; for (int i = 0; i < size; i++) a[i] = nextInt() - 1;
        }
        public void inii(out int[] a1, out int[] a2, int size) {
            a1 = new int[size]; a2 = new int[size];
            for (int i = 0; i < size; i++) { a1[i] = nextInt() - 1; a2[i] = nextInt() - 1; }
        }
        public void inii(out int[,] a, int size) {
            a = new int[size, size]; for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++) a[i, j] = nextInt() - 1;
        }
        public void o<T>(T v) { Console.WriteLine(v); }
        public void ol<T>(T v) { Console.Write(v + " "); }
        public void o<T>(params T[] a) { foreach (T v in a) o(v); }
        public void o<T>(List<T> l) { o(l.ToArray()); }
        public void ol<T>(params T[] a) { foreach (T v in a) { ol(v); } br(); }
        public void ol<T>(List<T> l) { ol(l.ToArray()); }
        public void YN(bool f) { o(f ? "YES" : "NO"); }
        public void Yn(bool f) { o(f ? "Yes" : "No"); }
        public void yn(bool f) { o(f ? "yes" : "no"); }
        public void br() { o(""); }
        public void writeFlush() { Console.Out.Flush(); }
    }
    #endregion
    #region other
    class Mat {
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
        public long Sum(params long[] a) {
            return a.Aggregate((v, next) => (v % mod + next) % mod);
        }
        public int GCD(int a, int b) {
            if (a < b) Swap(ref a, ref b); return b == 0 ? a : GCD(b, a % b);
        }
        public int GCD(int[] array) { return array.Aggregate((v, next) => GCD(v, next)); }
        public bool isPrime(long n) {
            if (n == 2) return true; if (n < 2 || n % 2 == 0) return false;
            for (long v = 3; v <= (long)Math.Sqrt(n); v += 2) if (n % v == 0) return false;
            return true;
        }
        public void Swap<T>(ref T a, ref T b) { T tmp = a; a = b; b = tmp; }
        public T Max<T>(params T[] v) { return v.Max(); }
        public T Min<T>(params T[] v) { return v.Min(); }
        public double Dis(int x1, int y1, int x2, int y2) { return Math.Sqrt(Math.Pow((x2 - x1), 2) + Math.Pow((y2 - y1), 2)); }
        public int mDis(int x1, int y1, int x2, int y2) { return Math.Abs(x1 - x2) + Math.Abs(y1 - y2); }
        public int Digit(long n) { return (n == 0) ? 1 : (int)Math.Log10(n) + 1; }
        //test
        public int DigitValue(int n, int dig) { return (n % (int)Pow(10, dig)) / (int)Pow(10, dig - 1); }
        /*
        public int[] DigVal(int n) {//????...
            int[] ret = new int[Digit(n)];
            return ret;
        }
        */
        //
        public int Clamp(int n, int a, int b) { return (n < a) ? a : (b < n) ? b : n; }
        public long Clamp(long n, long a, long b) { return (n < a) ? a : (b < n) ? b : n; }
        public double Clamp(double n, double a, double b) { return (n < a) ? a : (b < n) ? b : n; }
        public long Tousa(long a, long d, int n) { return a + (n - 1) * d; }
        public long TousaSum(long a, long d, int n) { return n * (2 * a + (n - 1) * d) / 2; }
    }
    class AssociativeArray<T> {
        public Dictionary<T, int> dic;
        public AssociativeArray() { dic = new Dictionary<T, int>(); }
        public AssociativeArray(params T[] a) { dic = new Dictionary<T, int>(); Add(a); }
        public void Add(params T[] a) {
            for (int i = 0; i < a.Length; i++) {
                if (!dic.ContainsKey(a[i])) dic[a[i]] = 0; dic[a[i]]++;
            }
        }
        public T[] Keys() { return dic.Keys.ToArray<T>(); }
        public int Val(T k) { return (dic.ContainsKey(k)) ? dic[k] : 0; }
        public int ValueSum() { return dic.Values.Sum(); }
        public int KeyNum() { return dic.Keys.Count; }
        public int MaxVal() { return dic.Values.Max(); }
        public int MinVal() { return dic.Values.Min(); }
        public T MaxKey() { return dic.First(d => d.Value == MaxVal()).Key; }
        public T MinKey() { return dic.First(d => d.Value == MinVal()).Key; }
        public bool isContainsK(T k) { return dic.ContainsKey(k); }
        public bool anyContainsK(params T[] k) { return k.Any(key => isContainsK(key)); }
        public bool allContainsK(params T[] k) { return k.All(key => isContainsK(key)); }
        public void Show() { foreach (var v in dic) { Console.WriteLine(v.Key + " : " + v.Value); } }
        //:sort->array
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
    class Time {
        public bool isLeapYear(int y) { return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)); }
    }
    class BucketSort {
        public int[] bucket;
        public void Init(int[] a) {
            bucket = new int[a.Max() + 1];
            for (int i = 0; i < a.Length; ++i) ++bucket[a[i]];
            for (int i = 0, j = 0; j < bucket.Length; ++j)
                for (int k = bucket[j]; k != 0; --k, ++i) a[i] = j;

        }
    }
    #endregion
    #region Ex
    static class StringEX {//??
        public static string Reversed(this string s) { return string.Join("", s.Reverse()); }
        public static string Repeat(this string s, int n) { return string.Concat(Enumerable.Repeat(s, n).ToArray()); }
        public static int toInt(this string s) { int n; return (int.TryParse(s.TrimStart('0'), out n)) ? n : 0; }
        public static int toInt(this char c) { return toInt(c.ToString()); }
        public static int toInt(this char[] c) { return toInt(new string(c)); }
    }
    static class NumericEx {//??
        public static string pad0<T>(this T v, int n) { return v.ToString().PadLeft(n, '0'); }
        public static int RoundUp(this double n) { return (int)Math.Ceiling(n); }
    }
    static class ArrayEX {
        public static T[] Sort<T>(this T[] a) { Array.Sort(a); return a; }
        public static void Set<T>(this T[] a, T v) {
            for (int i = 0; i < a.Length; i++) { a[i] = v; }
        }
        public static void Set<T>(this T[,] a, T v) {
            for (int i = 0; i < a.GetLength(0); i++)
                for (int j = 0; j < a.GetLength(1); j++)
                    a[i, j] = v;
        }
    }
    #endregion
}