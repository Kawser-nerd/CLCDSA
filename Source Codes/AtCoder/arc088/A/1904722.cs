using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Reflection.Emit;
using System.Security.Cryptography;
using System.Text;
namespace Program{
    class MainClass{
        ////////////////////////////////////////////////////////////
        private long X, Y;        
        void Solve(){
            io.i(out X,out Y);
            var mul = 2L;
            var cur = X;
            var ans = 1L;
            while(true){
                cur *= mul;
                if(cur<=Y)
                    ans++;
                else
                    break;                
            }
            io.o(ans);

        }

        ////////////////////////////////////////////////////////////
        public static void Main() { new MainClass().Stream(); }
        IO io = new IO();
        Mat mat = new Mat();
        void Stream(){
            Solve();
            io.writeFlush();
        }
        //void Stream() { Test(); io.writeFlush(); }
        void Test() { }
        #region MockMacro
        //cannot use break,continue,goto
        void FOR(int a, int b, Action<int> act){
            for(int i = a; i < b; ++i) act(i);
        }
        void FORR(int a, int b, Action<int> act){
            for(int i = a - 1; i >= b; --i) act(i);
        }
        #endregion
        ////////////////////////////////////////////////////////////
    }
    #region default
    class IO{
        string[] nextBuffer;
        int BufferCnt;
        char[] cs = new char[]{' '};
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()){AutoFlush = false};
        public IO(){
            nextBuffer = new string[0];
            BufferCnt = 0;
            Console.SetOut(sw);
        }
        public string Next(){
            if(BufferCnt < nextBuffer.Length) return nextBuffer[BufferCnt++];
            string st = Console.ReadLine();
            while(st == "") st = Console.ReadLine();
            nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            BufferCnt = 0;
            return nextBuffer[BufferCnt++];
        }
        public string String => Next();
        public char Char => char.Parse(String);
        //public int Int => int.Parse(String);
        public int Int => String.toInt();
        public long Long => String.toLong();
        public double Double => double.Parse(String);
        public string[] arr => Console.ReadLine().Split(' ');
        public char[] arrChar => Array.ConvertAll(arr, char.Parse);
        //public int[] arrInt => Array.ConvertAll(arr, int.Parse);
        public int[] arrInt => arr.Select(v => v.toInt()).ToArray();
        //public long[] arrLong => Array.ConvertAll(arr, long.Parse);
        public long[] arrLong => arr.Select(v => v.toLong()).ToArray();
        public double[] arrDouble => Array.ConvertAll(arr, double.Parse);
        public T i<T>() { return suitType<T>(String); }
        public void i<T>(out T v) { v = suitType<T>(String); }
        public void i<T, U>(out T v1, out U v2){
            i(out v1);
            i(out v2);
        }
        public void i<T, U, V>(out T v1, out U v2, out V v3){
            i(out v1);
            i(out v2);
            i(out v3);
        }
        public void i<T, U, V, W>(out T v1, out U v2, out V v3, out W v4){
            i(out v1);
            i(out v2);
            i(out v3);
            i(out v4);
        }
        public void i<T, U, V, W, X>(out T v1, out U v2, out V v3, out W v4, out X v5){
            i(out v1);
            i(out v2);
            i(out v3);
            i(out v4);
            i(out v5);
        }
        public void ini<T>(out T[] a, int n){
            a = new T[n];
            for(int i = 0; i < n; ++i) a[i] = suitType<T>(String);
        }
        public void ini<T, U>(out T[] a, out U[] b, int n){
            a = new T[n];
            b = new U[n];
            for(int i = 0; i < n; ++i){
                a[i] = i<T>();
                b[i] = i<U>();
            }
        }
        public void ini<T, U, V>(out T[] a, out U[] b, out V[] c, int n){
            a = new T[n];
            b = new U[n];
            c = new V[n];
            for(int i = 0; i < n; ++i){
                a[i] = i<T>();
                b[i] = i<U>();
                c[i] = i<V>();
            }
        }
        public void ini<T, U>(out Tuple<T, U>[] t, int n){
            t = new Tuple<T, U>[n];
            for(int j = 0; j < n; ++j){
                T i1;
                U i2;
                i(out i1);
                i(out i2);
                t[j] = Tuple.Create(i1, i2);
            }
        }
        public void ini<T, U, V>(out Tuple<T, U, V>[] t, int n){
            t = new Tuple<T, U, V>[n];
            for(int j = 0; j < n; ++j){
                T i1;
                U i2;
                V i3;
                i(out i1);
                i(out i2);
                i(out i3);
                t[j] = Tuple.Create(i1, i2, i3);
            }
        }
        public void ini<T>(out T[,] a, int h, int w){
            a = new T[h, w];
            for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) a[i, j] = i<T>();
        }
        public void o<T>(T v) { Console.WriteLine(v); }
        public void o<T>(params T[] a) { Array.ForEach(a, n => o(n)); }
        public void o<T>(T[,] a){
            int a0 = a.GetLength(0), a1 = a.GetLength(1);
            for(int i = 0; i < a0; ++i){
                for(int j = 0; j < a1 - 1; ++j) Console.Write(a[i, j] + " ");
                Console.WriteLine(a[i, a1 - 1]);
            }
        }
        public void YN(bool f) { o(f ? "YES" : "NO"); }
        public void Yn(bool f) { o(f ? "Yes" : "No"); }
        public void yn(bool f) { o(f ? "yes" : "no"); }
        public void ol<T>(params T[] a) { o(connect<T>(a)); }
        public void or<T>(T a) { Console.Write(a); }
        public void br() { o(""); }
        public void writeFlush() { Console.Out.Flush(); }
        private string connect<T>(params T[] s) { return string.Join(" ", s); }
        private bool typeEQ<T, U>() { return typeof(T).Equals(typeof(U)); }
        private T convertType<T, U>(U v) { return (T) Convert.ChangeType(v, typeof(T)); }
        private T suitType<T>(string s){
            if(typeEQ<T, int>()) return convertType<T, int>(int.Parse(s));
            if(typeEQ<T, long>()) return convertType<T, long>(long.Parse(s));
            if(typeEQ<T, double>()) return convertType<T, double>(double.Parse(s));
            if(typeEQ<T, char>()) return convertType<T, char>(char.Parse(s));
            return convertType<T, string>(s);
        }
    }

    class Mat{
        public long mod = 1000000007;//10^9+7
        public long Pow(long a, long b){
            if(b == 0) return 1;
            if(b % 2 == 1) return (a % mod * Pow(a % mod, b - 1) % mod) % mod;
            else return Pow(a * a % mod, b / 2) % mod;
        }
        public long Fact(long n){
            long ret = 1;
            for(long i = 1; i <= n; i++) ret = (ret * i) % mod;
            return ret;
        }
        public long ModC(long n, long r){
            if(r == 0 || n == r) return 1;
            if(n == 0) return 0;
            if(n < 0 || n < r) throw new ArgumentException("n,r invalid");
            else return (Fact(n) % mod * Pow((Fact(n - r) % mod * Fact(r) % mod) % mod, mod - 2) % mod) % mod;
        }
        public long[,] C(int N){
            long[,] Co = new long[N + 1, N + 1];
            (N + 1).REP(i => (i + 1).REP(j => Co[i, j] = (j == 0 || j == i) ? 1L : Co[i - 1, j - 1] + Co[i - 1, j]));
            return Co;
        }
        public long DupC(long n, long r) { return ModC(n + r - 1, r); }
        public long P(long n, long r) { return Fact(n) / (Fact(n - r)); }//test
        public bool isPrime(long n){
            if(n == 2) return true;
            if(n < 2 || n % 2 == 0) return false;
            for(long v = 3; v <= (long) Math.Sqrt(n); v += 2) if(n % v == 0) return false;
            return true;
        }
        public long LCM(long a, long b) { return a * (b / GCD(a, b)); }
        public long LCM(params long[] a) { return a.Aggregate((v, n) => LCM(v, n)); }
        public long GCD(long a, long b){
            if(a < b) Swap(ref a, ref b);
            return b == 0 ? a : GCD(b, a % b);
        }
        public long GCD(params long[] array) { return array.Aggregate((v, n) => GCD(v, n)); }
        public T Max<T>(params T[] a) { return a.Max(); }
        public T Min<T>(params T[] a) { return a.Min(); }
        public void Swap<T>(ref T a, ref T b){
            T tmp = a;
            a = b;
            b = tmp;
        }
        public double Dis(int x1, int y1, int x2, int y2) { return Math.Sqrt(Math.Pow((x2 - x1), 2) + Math.Pow((y2 - y1), 2)); }
        public int mDis(int x1, int y1, int x2, int y2) { return Math.Abs(x1 - x2) + Math.Abs(y1 - y2); }
        public int[] DigArr(int n){
            int[] ret = new int[Digit(n)];
            ret.Length.REP(i => ret[i] = DigVal(n, i + 1));
            return ret;
        }
        public long DigArr2Num(IEnumerable<int> enu) { return enu.Aggregate((v, n) => v * 10 + n); }
        public int Digit(long n) { return (n == 0) ? 1 : (int) Math.Log10(n) + 1; }
        public int DigVal(int n, int dig) { return (n % (int) Pow(10, dig)) / (int) Pow(10, dig - 1); }
        public long Tousa(long a, long d, long n) { return a + (n - 1) * d; }
        public long TousaSum(long a, long d, long n) { return n * (2 * a + (n - 1) * d) / 2; }
        public long[] EnuDivsor(long N){
            var ret = new SortedSet<long>();
            for(long i = 1; i * i <= N; i++)
                if(N % i == 0){
                    ret.Add(i);
                    ret.Add(N / i);
                }
            return ret.ToArray();
        }
        public Dictionary<long, long> PrimeFactor(long n){
            var ret = new Dictionary<long, long>();
            for(int i = 2; i * i <= n; ++i){
                if(!ret.ContainsKey(i)) ret[i] = 0;
                while(n % i == 0){
                    ++ret[i];
                    n /= i;
                }
            }
            return ret.Where(kp => kp.Value != 0).ToDictionary(kp => kp.Key, kp => kp.Value);
        }
    }
    #endregion
    #region Ex
    static class StringEX{
        public static string Reversed(this string s) { return string.Join("", s.Reverse()); }
        public static string Repeat(this string s, int n) { return string.Concat(Enumerable.Repeat(s, n).ToArray()); }
        public static int toInt(this string s){
            int n;
            return (int.TryParse(s.TrimStart('0'), out n)) ? n : 0;
        }
        public static int toInt(this char c) { return toInt(c.ToString()); }
        public static int toInt(this char[] c) { return toInt(new string(c)); }
        public static long[] toLong(this int[] a) { return a.Select(v => (long) v).ToArray(); }
        public static long[,] toLong(this int[,] m){
            var h = m.GetLength(0);
            var w = m.GetLength(1);
            var ret = new long[h, w];
            for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) ret[i, j] = (long) m[i, j];
            return ret;
        }
        public static long toLong(this string s){
            long n;
            return (long.TryParse(s.TrimStart('0'), out n)) ? n : (long) 0;
        }
        public static long toLong(this char c) { return toLong(c.ToString()); }
        public static long toLong(this char[] c) { return toLong(new string(c)); }
        public static string toString(this char[] c) { return new string(c); }
    }
    static class NumericEx{
        public static string pad0<T>(this T v, int n) { return v.ToString().PadLeft(n, '0'); }
        public static double RoundOff(this double v, int n) { return Math.Round(v, n - 1, MidpointRounding.AwayFromZero); }
        public static double RoundUp(this double v) { return Math.Ceiling(v); }
        public static double RoundDown(this double v) { return Math.Floor(v); }
        public static bool Odd(this int v) { return v % 2 != 0; }
        public static bool Odd(this long v) { return v % 2 != 0; }
        public static void REP(this int v, Action<int> act){
            for(int i = 0; i < v; ++i) act(i);
        }
        public static void REPR(this int v, Action<int> act){
            for(int i = v - 1; i >= 0; --i) act(i);
        }
    }
    static class ArrayEX{
        public static T[] Sort<T>(this T[] a){
            Array.Sort(a);
            return a;
        }
        public static T[] SortR<T>(this T[] a){
            Array.Sort(a);
            Array.Reverse(a);
            return a;
        }
        public static void Set<T>(this T[] a, T v) { a.Length.REP(i => a[i] = v); }
        public static void Set<T>(this T[,] a, T v) { a.GetLength(0).REP(i => a.GetLength(1).REP(j => a[i, j] = v)); }
        public static int[] toIntArr(this string a) { return a.Select(c => c.toInt()).ToArray(); }
        public static int[] toIntArr(this string[] a) { return Array.ConvertAll(a, int.Parse); }
        public static long[] toLongArr(this string a) { return a.Select(c => c.toLong()).ToArray(); }
        public static long[] toLongArr(this string[] a) { return Array.ConvertAll(a, long.Parse); }
        public static double[] toDoubleArr(this string[] a) { return Array.ConvertAll(a, double.Parse); }
        public static char[] toCharArr(this string[] a) { return Array.ConvertAll(a, char.Parse); }
        public static int LowerBound<T>(this T[] a, T x) where T : IComparable{
            Array.Sort(a);
            int lb = -1, ub = a.Length;
            while(ub - lb > 1){
                int mid = (ub + lb) / 2;
                if(a[mid].CompareTo(x) >= 0) ub = mid;
                else lb = mid;
            }
            return ub;
        }
        public static int UpperBound<T>(this T[] a, T x) where T : IComparable{
            Array.Sort(a);
            int lb = -1, ub = a.Length;
            while(ub - lb > 1){
                int mid = (ub + lb) / 2;
                if(a[mid].CompareTo(x) > 0) ub = mid;
                else lb = mid;
            }
            return ub;
        }
    }
    #endregion
}