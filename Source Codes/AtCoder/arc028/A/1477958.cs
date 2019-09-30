using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
namespace AtCoder {
    class MainClass {
        //C#7.0////////////////////
        int N, A, B;
        void Solve() {
            io.i(out N, out A, out B);

            N %= (A + B);

            bool antWin = (N == 0) ? false :(N <= A) ? true : false;

            io.o(antWin ? "Ant" : "Bug");

        }

        ////////////////////////////////////////////////////////////
        public static void Main(string[] args) { new MainClass().Stream(); }
        IO io = new IO();
        void Stream() { Solve(); io.writeFlush(); }
        ////////////////////////////////////////////////////////////
    }
    class IO {
        string[] nextBuffer; int BufferCnt; char[] cs = new char[] { ' ' };
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()) {
            AutoFlush = false
        };
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
        public void ini(out int[] a, int size) {
            a = new int[size]; for (int i = 0; i < size; i++) a[i] = nextInt();
        }
        public void ini(out long[] a, int size) {
            a = new long[size]; for (int i = 0; i < size; i++) a[i] = nextInt();
        }
        public void ini(out int[] a1, out int[] a2, int size) {
            a1 = new int[size]; a2 = new int[size];
            for (int i = 0; i < size; i++) { a1[i] = nextInt(); a2[i] = nextInt(); }
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
        public void o<T>(params T[] a) { foreach (T v in a) Console.WriteLine(v); }
        public void o<T>(List<T> l) { foreach (T v in l) sw.WriteLine(v); }
        public void ol<T>(T v) { Console.Write(v + " "); }
        public void ol<T>(params T[] a) { foreach (T v in a) { ol(v); } br(); }
        public void YN(bool f) { Console.WriteLine(f ? "YES" : "NO"); }
        public void Yn(bool f) { Console.WriteLine(f ? "Yes" : "No"); }
        public void yn(bool f) { Console.WriteLine(f ? "yes" : "no"); }
        public void br() { Console.WriteLine(""); }
        public void writeFlush() { Console.Out.Flush(); }
        public string pad0<T>(T v, int n) { return v.ToString().PadLeft(n, '0'); }
    }
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
            else return (Fact(n) % mod * Pow
                         ((Fact(n - r) % mod * Fact(r) % mod) % mod, mod - 2) % mod) % mod;
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
        public double Dis(int x1, int y1, int x2, int y2) {
            return Math.Sqrt(Math.Pow((x2 - x1), 2) + Math.Pow((y2 - y1), 2));
        }
        public int Digit(long n) { return (n == 0) ? 1 : (int)Math.Log10(n) + 1; }
        public int Clamp(int n, int a, int b) { return (n < a) ? a : (b < n) ? b : n; }
        public long Clamp(long n, long a, long b) { return (n < a) ? a : (b < n) ? b : n; }
        public double Clamp(double n, double a, double b) {
            return (n < a) ? a : (b < n) ? b : n;
        }
        public long Tousa(long a, long d, int n) { return a + (n - 1) * d; }
        public long TousaSum(long a, long d, int n) { return n * (2 * a + (n - 1) * d) / 2; }
    }
    class AssociativeArray<T> {
        public Dictionary<T, int> dic;
        public AssociativeArray() { }
        public AssociativeArray(T[] a) { init(a); }
        public void init(T[] a) {
            dic = new Dictionary<T, int>();
            for (int i = 0; i < a.Length; i++) {
                if (!dic.ContainsKey(a[i])) dic[a[i]] = 0; dic[a[i]]++;
            }
        }
        public T[] Keys() { return dic.Keys.ToArray<T>(); }
        public int Val(T k) { return dic[k]; }
        public int ValueSum() { int s = 0; foreach (var i in dic) s += i.Value; return s; }
        public int KeyNum() { return dic.Keys.Count; }
        public int Max() { return dic.Values.Max(); }
        public int Min() { return dic.Values.Min(); }
        public T MaxKey() { return dic.First(d => d.Value == Max()).Key; }
        public T MinKey() { return dic.First(d => d.Value == Min()).Key; }
        public bool isContainsK(T k) { return dic.ContainsKey(k); }
        public bool anyContainsK(params T[] k) {
            bool f = false;
            foreach (T v in k) f |= isContainsK(v); return f;
        }
        public bool allContainsK(params T[] k) {
            bool f = true;
            foreach (T v in k) f &= isContainsK(v); return f;
        }
        public void Show() { foreach (var v in dic) { Console.WriteLine(v.Key + " : " + v.Value); } }
        //:sort->array
    }
    class Time {
        public bool isLeapYear(int y) {
            return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
        }
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
    //Ex////////////////////////////////////////////////////////////
    static class StringEX {
        public static string Reversed(this string s) {
            return string.Join("", s.Reverse());
        }
        public static string Repeat(this string s, int n) {
            return string.Concat(Enumerable.Repeat(s, n).ToArray());
        }
    }
    static class CharEX {
        public static int toInt(this char c) { return int.Parse(c.ToString()); }
    }
    static class ArrayEX {
        public static T[] Sort<T>(this T[] a) { Array.Sort(a); return a; }
        public static void Set<T>(this T[] a, T v) {
            for (int i = 0; i < a.Length; i++) { a[i] = v; }
        }
    }
    ////////////////////////////////////////////////////////////////
}