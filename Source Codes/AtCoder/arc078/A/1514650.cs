using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
namespace Program {
    class MainClass {
        //C#Lover///////////////////////////////////////////////////
        int N;
        int[] A;
        void Solve() {
            N = io.Int;
            A = new int[N];
            N.rep(i => A[i] = io.Int);
                  
            long aSum = 0;
            long sSum = 0;

            N.rep(i => sSum += A[i]);

            aSum += A[0];
            sSum -= A[0];
            long ans = Math.Abs(sSum-aSum);

            for (int i = 1; i < N - 1; i++) {
                aSum += A[i];
                sSum -= A[i];
                ans = Math.Min(ans, Math.Abs(sSum-aSum));
            }

            io.o(ans);

        }
        ////////////////////////////////////////////////////////////
        public static void Main(string[] args) { new MainClass().Stream(); }
        IO io = new IO();
        void Stream() { Solve(); io.writeFlush(); }
        //void Stream() { Test(); io.writeFlush(); }
        void Test() {        }
        #region MockMacro
        //Hack Update
        //cannot use break,continue,goto
        void FOR(int a, int b, Action<int> act) { for (int i = a; i < b; i ++) act(i); }
        void REP(int n, Action<int> act) { for (int i = 0; i < n ; i ++) act(i); }
        string JOIN(params string[] s) { return string.Join(" ", s); }

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
    class PQueue<T> where T : IComparable {
        public List<T> heap;
        private Comparison<T> comp;
        private IComparer<T> comparer;
        private int size = 0;
        private int type;
        public PQueue(int type = 0) : this(Comparer<T>.Default) { this.type = type; }
        public PQueue(IComparer<T> comparer) : this(16, comparer.Compare) { this.comparer = comparer; }
        public PQueue(Comparison<T> comparison) : this(16, comparison) { }
        public PQueue(int capacity, Comparison<T> comparison) { this.heap = new List<T>(capacity); this.comp = comparison; }
        public void Enqueue(T item) {
            this.heap.Add(item); var i = size++;
            while (i > 0) { var p = (i - 1) >> 1; if (Compare(this.heap[p], item) <= 0) break; this.heap[i] = heap[p]; i = p; }
            this.heap[i] = item;
        }
        public T Dequeue() {
            var ret = this.heap[0]; var x = this.heap[--size]; var i = 0;
            while ((i << 1) + 1 < size) {
                var a = (i << 1) + 1; var b = (i << 1) + 2; if (b < size && Compare(heap[b], heap[a]) < 0) a = b;
                if (Compare(heap[a], x) >= 0) break; heap[i] = heap[a]; i = a;
            }
            heap[i] = x; heap.RemoveAt(size);
            return ret;
        }
        public T Peek() { return heap[0]; }
        public int Count { get { return size; } }
        public bool Any() { return size > 0; }
        public bool Empty() { return !Any(); }
        public bool Contains(T v) { return heap.Contains(v); }
        private int Compare(T x, T y) { return type == 0 ? x.CompareTo(y) : y.CompareTo(x); }
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
            if (r == 0 || n == r) return 1;else if (n <= 0||n<r) return 0;//n<0||n<r:invalid
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
    class BasicGraph{//?????
        public List<Tuple<long, long>>[] G;
        public void Init(long n) { G = new List<Tuple<long, long>>[n + 1]; M.REP(G.Length, i => G[i] = new List<Tuple<long, long>>()); }
        public void Dir(long[] f, long[] t) { M.REP(f.Length, i => { G[f[i]].Add(Tuple.Create(t[i], 1L)); }); }
        public void Dir(long[] f, long[] t,long[] c) { M.REP(f.Length, i => { G[f[i]].Add(Tuple.Create(t[i], c[i])); }); }
        public void NonDir(long[] f, long[] t) { M.REP(f.Length, i => { G[f[i]].Add(Tuple.Create(t[i], 1L));G[t[i]].Add(Tuple.Create(f[i], 1L)); }); }
        public void NonDir(long[] f, long[] t, long[] c) { M.REP(f.Length, i => { G[f[i]].Add(Tuple.Create(t[i], c[i]));G[t[i]].Add(Tuple.Create(f[i], c[i])); }); }
    }
    class TreeDis {//test
        public List<Tuple<long, long>>[] g; public long[] a2other; private int type;
        public TreeDis(int type = 0) { this.type = type; }//0->bfs,other->dfs
        public void Init(long n) { g = new List<Tuple<long, long>>[n + 1]; M.REP(g.Length, i => g[i] = new List<Tuple<long, long>>()); }
        public void Run(long[] a, long[] b) { M.REP(a.Length, i => { g[a[i]].Add(Tuple.Create(b[i], 1L)); g[b[i]].Add(Tuple.Create(a[i], 1L)); }); }
        public void Run(long[] a, long[] b, long[] w) { M.REP(a.Length, i => { g[a[i]].Add(Tuple.Create(b[i], w[i])); g[b[i]].Add(Tuple.Create(a[i], w[i])); }); }
        public long[] a2iArr(long a) { a2other = new long[g.Count()]; if (type == 0) BFS(a); else DFS(a); return a2other; }
        private void BFS(long a) {
            var q = new Queue<Tuple<long, long>>(); q.Enqueue(Tuple.Create(a, -1L));
            while (q.Count > 0) {
                var c = q.Dequeue();
                foreach (var v in g[c.Item1]) {
                    if (v.Item1 == c.Item2) continue;
                    a2other[v.Item1] = a2other[c.Item1] + v.Item2; q.Enqueue(Tuple.Create(v.Item1, c.Item1));
                }
            }
        }
        private void DFS(long a) {
            var s = new Stack<Tuple<long, long>>(); s.Push(Tuple.Create(a, -1L));
            while (s.Count > 0) {
                var c = s.Pop();
                foreach (var v in g[c.Item1]) {
                    if (v.Item1 == c.Item2) continue;
                    a2other[v.Item1] = a2other[c.Item1] + v.Item2;s.Push(Tuple.Create(v.Item1, c.Item1));
                }
            }
        }
    }
    class Dijkstra {//?test,TODO:????
        private int Index = -1; private long INF = (int)1e9; private long[,] m;
        public Dijkstra() { }
        public void init(int n) {
            Index = n + 1; m = new long[Index, Index];
            M.REP(Index, i => M.REP(Index, j => m[i, j] = INF)); M.REP(Index, i => m[i, i] = 0);
        }
        public void AddPath(long f, long t, long w) { m[f, t] = Math.Min(m[f, t], w); m[t, f] = m[f, t]; }
        public long GetMinCost(long f, long t) {
            long[] w = new long[Index];
            M.REP(Index, i => w[i] = INF); w[f] = 0;
            var pq = new PQueue<Tuple<long, long>>(); pq.Enqueue(Tuple.Create(0L, f));//cost<-from
            while (pq.Count > 0) {
                var c = pq.Dequeue(); if (c.Item2 < c.Item1) continue;
                M.REP(Index, i => {
                    long w2i = m[c.Item2, i] == INF ? INF : c.Item1 + m[c.Item2, i];
                    if (w2i < w[i]) { w[i] = w2i; pq.Enqueue(Tuple.Create(w2i, (long)i)); }
                });
            }
            return w[t];
        }
    }
    class WarshallFloyd {//TODO:update
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
    class UnionFind {
        public long[] parent; public long[] depth;
        public void Init(long n) { parent = new long[n]; depth = new long[n]; M.REP(n, i => parent[i] = i); }
        public long Find(long x) { return (parent[x] == x) ? x : parent[x] = Find(parent[x]); }
        public void Unite(long x, long y) {
            x = Find(x); y = Find(y); if (x == y) return;
            if (depth[x] < depth[y]) parent[x] = y; else { parent[y] = x; if (depth[x] == depth[y]) depth[x]++; }
        }
        public bool Same(long a, long b) { return Find(a) == Find(b); }
    }
    class Index { 
        public int[] Comp(int[] bef){
            int[] aft = new int[bef.Length];
            var tmp = bef.Distinct().OrderBy(v => v).Select((v, i) => new { v, i }).ToDictionary(p => p.v, p => p.i);
            aft = bef.Select(v => tmp[v]).ToArray();
            return aft;
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
        public static double RoundOff(this double v,int n) {return Math.Round(v, n-1, MidpointRounding.AwayFromZero);}
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
        public static void REP(int n, Action<int> a) { for (int i = 0; i < n; i++) a(i); }
        public static void REP(long n, Action<long> a) { for (long i = 0; i < n; i++) a(i); }
    }
    static class TestEx{
        public static void rep(this int v, Action<int> act) { for (int i = 0; i < v; i++) act(i); }        
    }
    #endregion
}