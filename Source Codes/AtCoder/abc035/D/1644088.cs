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
        ////////////////////////////////////////////////////////////
        int N, M, T;
        int[] A;
        int[] a, b;
        long[] c;
        void Solve() {
            //input
            io.i(out N, out M, out T);
            io.ini(out A, N);
            io.ini(out a, out b, out c, M);
            //cal
            var dij = new Dijkstra(false);           //start->A[i]
            var revDij = new Dijkstra(false);     //A[i]->start
            dij.Init(N);
            revDij.Init(N);
            dij.AddPath(a, b, c);
            revDij.AddPath(b, a, c);
            var ans = 0L;
            dij.Run(1);
            revDij.Run(1);
            for (int i = 0; i < N; ++i)
                if (dij.PathExist(i + 1) && revDij.PathExist(i + 1))
                    if (dij.cost[i + 1] + revDij.cost[i + 1] < T)
                        ans = Math.Max(ans, (long)A[i] * (T - (dij.cost[i + 1] + revDij.cost[i + 1])));
            //ret
            Console.WriteLine(ans);
        }

        ////////////////////////////////////////////////////////////
        public static void Main() { new MainClass().Stream(); }
        IO io = new IO();
        void Stream() { Solve(); io.writeFlush(); }
        //void Stream() { Test(); io.writeFlush(); }
        void Test() {
           var pq = new PQueue<edge>(1);

        }
        #region MockMacro
        //cannot use break,continue,goto
        void FOR(int a, int b, Action<int> act) { for (int i = a; i < b; ++i) act(i); }
        void FORR(int a, int b, Action<int> act) { for (int i = a - 1; i >= b; --i) act(i); }
        #endregion
        ////////////////////////////////////////////////////////////
    }
    #region default
    class IO {
        string[] nextBuffer;
        int BufferCnt;
        char[] cs = new char[] { ' ' };
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput())
        {
            AutoFlush = false
        };
        public IO() {
            nextBuffer = new string[0];
            BufferCnt = 0;
            Console.SetOut(sw);
        }
        public string Next() {
            if (BufferCnt < nextBuffer.Length)
                return nextBuffer[BufferCnt++];
            string st = Console.ReadLine();
            while (st == "")
                st = Console.ReadLine();
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
        public T i<T>() { return suitType<T>(String); }
        public void i<T>(out T v) { v = suitType<T>(String); }
        public void i<T, U>(out T v1, out U v2) { i(out v1); i(out v2); }
        public void i<T, U, V>(out T v1, out U v2, out V v3) { i(out v1); i(out v2); i(out v3); }
        public void i<T, U, V, W>(out T v1, out U v2, out V v3, out W v4) {
            i(out v1); i(out v2); i(out v3); i(out v4);
        }
        public void i<T, U, V, W, X>(out T v1, out U v2, out V v3, out W v4, out X v5) {
            i(out v1); i(out v2); i(out v3); i(out v4); i(out v5);
        }
        public void ini<T>(out T[] a, int n) { a = new T[n]; for (int i = 0; i < n; ++i) a[i] = suitType<T>(String); }
        public void ini<T, U>(out T[] a, out U[] b, int n) {
            a = new T[n]; b = new U[n]; for (int i = 0; i < n; ++i) { a[i] = i<T>(); b[i] = i<U>(); }
        }
        public void ini<T, U, V>(out T[] a, out U[] b, out V[] c, int n) {
            a = new T[n]; b = new U[n]; c = new V[n];
            for (int i = 0; i < n; ++i) { a[i] = i<T>(); b[i] = i<U>(); c[i] = i<V>(); }
        }
        public void ini<T>(out T[,] a, int h, int w) {
            a = new T[h, w]; for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) a[i, j] = i<T>();
        }
        public void o<T>(T v) { Console.WriteLine(v); }
        public void o<T>(params T[] a) { Array.ForEach(a, n => o(n)); }
        public void o<T>(T[,] a) {
            int a0 = a.GetLength(0), a1 = a.GetLength(1);
            for (int i = 0; i < a0; ++i) {
                for (int j = 0; j < a1 - 1; ++j)
                    Console.Write(a[i, j] + " ");
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
        private T convertType<T, U>(U v) { return (T)Convert.ChangeType(v, typeof(T)); }
        private T suitType<T>(string s) {
            if (typeEQ<T, int>()) return convertType<T, int>(int.Parse(s));
            if (typeEQ<T, long>()) return convertType<T, long>(long.Parse(s));
            if (typeEQ<T, double>()) return convertType<T, double>(double.Parse(s));
            if (typeEQ<T, char>()) return convertType<T, char>(char.Parse(s));
            return convertType<T, string>(s);
        }
    }
    class PQueue<T> where T : struct,IComparable<T> {
        public List<T> heap; private Comparison<T> comp; private IComparer<T> comparer;
        private int size; private int type;//type=0->min
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
        public long mod = 1000000007;//10^9+7
        public long Pow(long a, long b) {
            if (b == 0) return 1;
            if (b % 2 == 1) return (a % mod * Pow(a % mod, b - 1) % mod) % mod;
            else return Pow(a * a % mod, b / 2) % mod;
        }
        public long Fact(long n) { long ret = 1; for (long i = 1; i <= n; i++) ret = (ret * i) % mod; return ret; }
        public long ModC(long n, long r) {
            if (r == 0 || n == r) return 1;
            if (n == 0) return 0;
            if (n < 0 || n < r) throw new ArgumentException("n,r invalid");
            else return (Fact(n) % mod * Pow((Fact(n - r) % mod * Fact(r) % mod) % mod, mod - 2) % mod) % mod;
        }
        public long[,] C(int N) {
            long[,] Co = new long[N + 1, N + 1];
            (N + 1).REP(i => (i + 1).REP(j => Co[i, j] = (j == 0 || j == i) ? 1L : Co[i - 1, j - 1] + Co[i - 1, j]));
            return Co;
        }
        public long DupC(long n, long r) { return ModC(n + r - 1, r); }
        public long P(long n, long r) { return Fact(n) / (Fact(n - r)); }//test
        public bool isPrime(long n) {
            if (n == 2) return true; if (n < 2 || n % 2 == 0) return false;
            for (long v = 3; v <= (long)Math.Sqrt(n); v += 2) if (n % v == 0) return false;
            return true;
        }
        public long LCM(long a, long b) { return a * (b / GCD(a, b)); }
        public long LCM(params long[] a) { return a.Aggregate((v, n) => LCM(v, n)); }
        public long GCD(long a, long b) { if (a < b) Swap(ref a, ref b); return b == 0 ? a : GCD(b, a % b); }
        public long GCD(params long[] array) { return array.Aggregate((v, n) => GCD(v, n)); }
        public T Max<T>(params T[] a) { return a.Max(); }
        public T Min<T>(params T[] a) { return a.Min(); }
        public void Swap<T>(ref T a, ref T b) { T tmp = a; a = b; b = tmp; }
        public double Dis(int x1, int y1, int x2, int y2) { return Math.Sqrt(Math.Pow((x2 - x1), 2) + Math.Pow((y2 - y1), 2)); }
        public int mDis(int x1, int y1, int x2, int y2) { return Math.Abs(x1 - x2) + Math.Abs(y1 - y2); }
        public int[] DigArr(int n) { int[] ret = new int[Digit(n)]; ret.Length.REP(i => ret[i] = DigVal(n, i + 1)); return ret; }
        public long DigArr2Num(IEnumerable<int> enu) { return enu.Aggregate((v, n) => v * 10 + n); }
        public int Digit(long n) { return (n == 0) ? 1 : (int)Math.Log10(n) + 1; }
        public int DigVal(int n, int dig) { return (n % (int)Pow(10, dig)) / (int)Pow(10, dig - 1); }
        public long Tousa(long a, long d, long n) { return a + (n - 1) * d; }
        public long TousaSum(long a, long d, long n) { return n * (2 * a + (n - 1) * d) / 2; }
        public long[] EnuDivsor(long N) {
            var ret = new SortedSet<long>();
            for (long i = 1; i * i <= N; i++)
                if (N % i == 0) { ret.Add(i); ret.Add(N / i); }
            return ret.ToArray();
        }
        public Dictionary<long, long> PrimeFactor(long n) {
            var ret = new Dictionary<long, long>();
            for (int i = 2; i * i <= n; ++i) {
                if (!ret.ContainsKey(i)) ret[i] = 0;
                while (n % i == 0) {
                    ++ret[i];
                    n /= i;
                }
            }
            return ret.Where(kp => kp.Value != 0).ToDictionary(kp => kp.Key, kp => kp.Value);
        }
        public IEnumerable<int[]> enuP(int[] Arr, int Use = -1) {//????
            Use = (Use != -1) ? Use : Arr.Length;
            if (Use == 0 || Arr.Length < Use)
                yield break;
            var s = new Stack<List<int>>();
            for (int i = Arr.Length - 1; i >= 0; i--)
                s.Push(new List<int>() { i });
            while (s.Count > 0) {
                var cur = s.Pop();
                if (cur.Count == Use) {
                    var ret = new List<int>();
                    cur.ForEach(X => ret.Add(Arr[X]));
                    yield return ret.ToArray();
                } else
                    for (int i = Arr.Length - 1; i >= 0; i--)
                        if (!cur.Contains(i))
                            s.Push(new List<int>(cur) { i });
            }
        }
        public IEnumerable<int[]> enuC(int[] Arr, int Use = -1) {//???????
            Use = (Use != -1) ? Use : Arr.Length;
            if (Use == 0 || Arr.Length < Use) yield break;
            var s = new Stack<Tuple<int, List<int>>>();
            Arr.Length.REPR(i => s.Push(Tuple.Create(i, new List<int>() { Arr[i] })));
            while (s.Count > 0) {
                var cur = s.Pop();
                if (cur.Item2.Count == Use) yield return cur.Item2.ToArray();
                else for (int i = Arr.GetUpperBound(0); i > cur.Item1; i--)
                        s.Push(Tuple.Create(i, new List<int>(cur.Item2) { Arr[i] }));
            }
        }
        public IEnumerable<int[]> enuDupP(int[] Arr, int Use = -1) {//??????
            Use = (Use != -1) ? Use : Arr.Length; if (Use == 0) yield break; var s = new Stack<List<int>>();
            Arr.Length.REPR(i => s.Push(new List<int>() { Arr[i] }));
            while (s.Count > 0) {
                var cur = s.Pop();
                if (cur.Count == Use) yield return cur.ToArray();
                else Arr.Length.REPR(i => s.Push(new List<int>(cur) { Arr[i] }));
            }
        }
        public IEnumerable<int[]> enuDupC(int[] Arr, int Use = -1) {//???????
            Use = (Use != -1) ? Use : Arr.Length; if (Use == 0) yield break;
            var s = new Stack<Tuple<int, List<int>>>();
            Arr.Length.REPR(i => s.Push(Tuple.Create(i, new List<int>() { Arr[i] })));
            while (s.Count > 0) {
                var cur = s.Pop();
                if (cur.Item2.Count == Use) yield return cur.Item2.ToArray();
                else for (int i = Arr.GetUpperBound(0); i >= cur.Item1; i--)
                        s.Push(Tuple.Create(i, new List<int>(cur.Item2) { Arr[i] }));
            }
        }
        public IEnumerable<string[]> enuPart(string str) {
            var s = new Stack<Tuple<string, List<string>, int>>();
            s.Push(Tuple.Create(str[0].ToString(), new List<string>(), 1));
            while (s.Count > 0) {
                var cur = s.Pop();
                if (cur.Item3 >= str.Length) yield return (new List<string>(cur.Item2) { cur.Item1 }).ToArray();
                else {
                    s.Push(Tuple.Create(cur.Item1 + str[cur.Item3], new List<string>(cur.Item2), cur.Item3 + 1));
                    s.Push(Tuple.Create(str[cur.Item3].ToString(), new List<string>(cur.Item2) { cur.Item1 }, cur.Item3 + 1));
                }
            }
        }
    }
    #endregion
    #region Data
    class AssociativeArray<T> : IEnumerable {
        public Dictionary<T, int> dic;
        public AssociativeArray() { dic = new Dictionary<T, int>(); }
        public AssociativeArray(params T[] a) { dic = new Dictionary<T, int>(); Add(a); }
        public void Add(T a) { if (!conK(a)) dic[a] = 0; dic[a]++; }
        public void Add(params T[] a) { a.Length.REP(i => { if (!conK(a[i])) dic[a[i]] = 0; dic[a[i]]++; }); }
        public void Set(T k, int v) { if (!dic.ContainsKey(k)) dic[k] = 0; dic[k] = v; }
        public void Remove(params T[] a) { a.Length.REP(i => { if (conK(a[i])) dic.Remove(a[i]); }); }
        public T[] Keys() { return dic.Keys.ToArray<T>(); }
        public int Val(T k) { return (dic.ContainsKey(k)) ? dic[k] : 0; }
        public int ValSum => dic.Values.Sum();
        public int KeyNum => dic.Keys.Count;
        public int MaxVal => dic.Values.Max();
        public int MinVal => dic.Values.Min();
        public T MaxKey => MaxK();
        public T MinKey => MinK();
        public T MaxK() { var maxV = MaxVal; return dic.First(d => d.Value == maxV).Key; }
        public T MinK() { var minV = MinVal; return dic.First(d => d.Value == minV).Key; }
        public T[] MaxKeys() {
            var maxV = MaxVal;
            return dic.Where(kp => kp.Value == maxV).ToDictionary(kp => kp.Key, kp => kp.Value).Keys.ToArray();
        }
        public T[] MinKeys() {
            var minV = MinVal;
            return dic.Where(kp => kp.Value == minV).ToDictionary(kp => kp.Key, kp => kp.Value).Keys.ToArray();
        }
        public bool conK(T k) { return dic.ContainsKey(k); }
        public bool anyK(params T[] k) { return k.Any(key => conK(key)); }
        public bool allK(params T[] k) { return k.All(key => conK(key)); }
        public void Show() { foreach (var v in dic) { Console.WriteLine(v.Key + " : " + v.Value); } }
        public T[] ValueSortedKey(bool inc = true) {
            return (inc ? (dic.OrderBy(kp => kp.Value)) : (dic.OrderByDescending(kp => kp.Value)))
                .ThenBy(kp => kp.Key).ToDictionary(kp => kp.Key, kp => kp.Value).Keys.ToArray();
        }
        public IEnumerator GetEnumerator() { foreach (var kp in dic) yield return kp; }
        //:sort->array
    }
    class TreeDis {//TODO:shortestPath
        public List<Tuple<long, long>>[] g; public long[] a2other; private int type;
        public TreeDis(int type = 0) { this.type = type; }//0->bfs,other->dfs
        public void Init(long n) { g = new List<Tuple<long, long>>[n + 1]; g.Length.REP(i => g[i] = new List<Tuple<long, long>>()); }
        public void Run(long[] a, long[] b) { a.Length.REP(i => { g[a[i]].Add(Tuple.Create(b[i], 1L)); g[b[i]].Add(Tuple.Create(a[i], 1L)); }); }
        public void Run(long[] a, long[] b, long[] w) { a.Length.REP(i => { g[a[i]].Add(Tuple.Create(b[i], w[i])); g[b[i]].Add(Tuple.Create(a[i], w[i])); }); }
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
                    a2other[v.Item1] = a2other[c.Item1] + v.Item2; s.Push(Tuple.Create(v.Item1, c.Item1));
                }
            }
        }
    }
    public struct edge : IComparable<edge> {
        public int to;
        public long cost;
        public edge(int to,long cost) { this.to = to;this.cost = cost; }
        public int CompareTo(edge e) { return cost.CompareTo(e.cost); }
        //public int CompareTo(IComparable<edge> e) { return e.CompareTo(e.cost); }
    }
    class ShortestPath {
        protected int I = -1;       //??1~N
        protected int V;             //???
        protected int E;             //???
        protected bool isNonDir = true;     //???
        public long INF = (long)1e15;       //???
        public long[] cost;                        //??
        //public List<Tuple<int, long>>[] Adj;//Adj[from]=(to,cost)
        public List<edge>[] Adj;
        //        public void Init(int n) { I = n + 1; V = n; Adj = new List<Tuple<int, long>>[I]; for (int i = 0; i < I; ++i) Adj[i] = new List<Tuple<int, long>>(); }
        public void Init(int n) { I = n + 1; V = n; Adj = new List<edge>[I]; for (int i = 0; i < I; ++i) Adj[i] = new List<edge>(); }
        //        public void AddPath(int f, int t, long c = 1) { E++; Adj[f].Add(Tuple.Create(t, c)); if (isNonDir) Adj[t].Add(Tuple.Create(f, c)); }
        public void AddPath(int f, int t, long c = 1) { E++; Adj[f].Add(new edge(t, c)); if (isNonDir) Adj[t].Add(new edge(f, c)); }
        public void AddPath(int[] f, int[] t, long[] c) { for (int i = 0; i < f.Length; ++i) AddPath(f[i], t[i], c[i]); }
        public void AddPath(int[] f, int[] t) { for (int i = 0; i < f.Length; ++i) AddPath(f[i], t[i]); }
    }
    class Dijkstra : ShortestPath {//?????????,????
        public Dijkstra(bool isNonDir = true) { this.isNonDir = isNonDir; }
        public long MinCost(int f, int t) {            Run(f);            return cost[t];        }
        public long MinCost(int t) {            return cost[t];        }
        public void Run(int f) {
            cost = new long[I];            for (int i = 0; i < I; ++i) cost[i] = INF;            cost[f] = 0;
            var pq = new PQueue<edge>(); pq.Enqueue(new edge(f, 0L));//(from,cost)
            while (!pq.Empty()) {
                var cur = pq.Dequeue();
                if (cost[cur.to] < cur.cost) continue;
                for (int i = 0; i < Adj[cur.to].Count; ++i) {
                    var tmp = Adj[cur.to][i];
                    if (cost[tmp.to] > cur.cost + tmp.cost) {
                        cost[tmp.to] = cur.cost + tmp.cost;
                        pq.Enqueue(new edge(tmp.to, cost[tmp.to]));
                    }
                }
            }
        }
        public bool PathExist(int t) {
            return cost[t] != INF;
        }
    }
    /*
    class BellmanFord : ShortestPath {
        private bool[] neg;
        public BellmanFord() { }
        public BellmanFord(bool isNonDir) { this.isNonDir = isNonDir; }
        public long MinCost(int f, int t) {
            cost = new long[I]; cost.Set(INF); cost[f] = 0; neg = new bool[I];
            for (int i = 0; i < I - 1; i++) {
                I.REP(j => Adj[j].Count.REP(k => {
                    var cur = Adj[j][k];
                    if (cost[cur.Item1] > cost[j] + cur.Item2)
                        cost[cur.Item1] = cost[j] + cur.Item2;
                }));
            }
            for (int i = 0; i < I; i++) {
                I.REP(j => Adj[j].Count.REP(k => {
                    var cur = Adj[j][k];
                    if (cost[cur.Item1] > cost[j] + cur.Item2) {
                        cost[cur.Item1] = cost[j] + cur.Item2;
                        neg[cur.Item1] = true;
                    }
                    if (neg[j]) neg[cur.Item1] = true;
                }));
            }
            return cost[t];
        }
        public bool loopExist() { return neg[I - 1]; }
    }
    */
    class WF : ShortestPath {
        public WF() { }
        public WF(bool isNonDir) { this.isNonDir = isNonDir; }
        public void Run() {
        }
    }
    class WarshallFloyd {
        private int E;
        private bool isNonDir;
        public long INF = (long)1e15;
        public long[,] BefG;
        public long[,] G;
        public WarshallFloyd(bool isNonDir = true) { this.isNonDir = isNonDir; }
        public void Init(int n) {
            E = n + 1; G = new long[E, E]; BefG = new long[E, E];
            for (int i = 0; i < E; ++i) for (int j = 0; j < E; ++j) { G[i, j] = INF; BefG[i, j] = INF; }
            for (int i = 0; i < E; ++i) { G[i, i] = 0; BefG[i, i] = 0; }
        }
        public void AddPath(int f, int t, long c = 1) {
            if (isNonDir) { G[f, t] = c; G[t, f] = c; BefG[f, t] = c; BefG[t, f] = c; } else { G[f, t] = c; BefG[f, t] = c; }
        }
        public void AddPath(int[] f, int[] t) { for (int i = 0; i < f.Length; ++i) AddPath(f[i], t[i], 1); }
        public void AddPath(int[] f, int[] t, long[] c) { for (int i = 0; i < f.Length; ++i) AddPath(f[i], t[i], c[i]); }
        public void Run() { G = MinCostArr(); }
        public long[,] MinCostArr() { for (int i = 0; i < E; ++i) for (int j = 0; j < E; ++j) for (int k = 0; k < E; ++k) G[j, k] = Math.Min(G[j, k], G[j, i] + G[i, k]); return G; }
        //????????
        public int[] MinPath(int from, int to) {
            var ret = new List<int>(); var cur = from; while (cur != to) {
                ret.Add(cur);
                for (int i = 1; i < E; ++i) { if (BefG[cur, i] + G[i, to] == G[cur, to]) { if (i == cur) continue; cur = i; break; } }
            }
            ret.Add(cur); return ret.ToArray();
        }
        public bool isMinPath(int a, int b, long c) { for (int i = 0; i < E; ++i) if (G[i, a] + c == G[i, b]) return true; return false; }
        //????????????
        public long MinCost() {
            long orig = 0;
            for (int i = 0; i < E; ++i)
                for (int j = i + 1; j < E; ++j) {
                    bool isOrig = true;
                    for (int k = 0; k < E; ++k) { if (k == i || k == j) continue; if (G[i, j] == G[i, k] + G[k, j]) { isOrig = false; break; } }
                    if (isOrig) orig += G[i, j];
                }
            return orig;
        }
    }
    class UnionFind {
        int[] dat;
        public void Init(int n) {
            dat = new int[n + 1];
            for (int i = 0; i <= n; ++i)
                dat[i] = -1;
        }
        public void Unite(int x, int y) {
            x = Root(x); y = Root(y);
            if (x == y) return;
            if (dat[y] < dat[x]) swap(ref x, ref y);
            dat[x] += dat[y];
            dat[y] = x;
        }
        public bool Find(int x, int y) { return Root(x) == Root(y); }
        public int Root(int x) { return dat[x] < 0 ? x : dat[x] = Root(dat[x]); }
        public int Size(int x) { return -dat[Root(x)]; }
        void swap(ref int a, ref int b) { int tmp = b; b = a; a = tmp; }
    }
    /*
    class Kruskal : ShortestPath {
        public Kruskal() { }
        public Kruskal(bool isNonDir) { this.isNonDir = isNonDir; }
        public long Run() {
            var uf = new UnionFind(); var ret = 0L; var L = new List<Tuple<int, int, long>>(); uf.Init(V);
            for (int i = 0; i < I; ++i)
                for (int j = 0; j < Adj[i].Count; ++i)
                    L.Add(Tuple.Create(i, Adj[i][j].Item1, Adj[i][j].Item2));
            L = L.OrderBy(t => t.Item3).ToList();
            for (int i = 0; i < L.Count; ++i) if (!uf.Find(L[i].Item1, L[i].Item2)) { ret += L[i].Item3; uf.Unite(L[i].Item1, L[i].Item2); }
            return ret;
        }
    }
    */
    #endregion
    #region Ex
    static class StringEX {
        public static string Reversed(this string s) { return string.Join("", s.Reverse()); }
        public static string Repeat(this string s, int n) { return string.Concat(Enumerable.Repeat(s, n).ToArray()); }
        public static int toInt(this string s) { int n; return (int.TryParse(s.TrimStart('0'), out n)) ? n : 0; }
        public static int toInt(this char c) { return toInt(c.ToString()); }
        public static int toInt(this char[] c) { return toInt(new string(c)); }
        public static long toLong(this string s) { long n; return (long.TryParse(s.TrimStart('0'), out n)) ? n : (long)0; }
        public static long toLong(this char c) { return toLong(c.ToString()); }
        public static long toLong(this char[] c) { return toLong(new string(c)); }
        public static string toString(this char[] c) { return new string(c); }
    }
    static class NumericEx {
        public static string pad0<T>(this T v, int n) { return v.ToString().PadLeft(n, '0'); }
        public static double RoundOff(this double v, int n) { return Math.Round(v, n - 1, MidpointRounding.AwayFromZero); }
        public static bool Odd(this int v) { return v % 2 != 0; }
        public static bool Odd(this long v) { return v % 2 != 0; }
        public static void REP(this int v, Action<int> act) { for (int i = 0; i < v; ++i) act(i); }
        public static void REPR(this int v, Action<int> act) { for (int i = v - 1; i >= 0; --i) act(i); }
    }
    static class ArrayEX {
        public static T[] Sort<T>(this T[] a) { Array.Sort(a); return a; }
        public static T[] SortR<T>(this T[] a) { Array.Sort(a); Array.Reverse(a); return a; }
        public static void Set<T>(this T[] a, T v) { a.Length.REP(i => a[i] = v); }
        public static void Set<T>(this T[,] a, T v) { a.GetLength(0).REP(i => a.GetLength(1).REP(j => a[i, j] = v)); }
        public static int[] toIntArr(this string[] a) { return Array.ConvertAll(a, int.Parse); }
        public static long[] toLongArr(this string[] a) { return Array.ConvertAll(a, long.Parse); }
        public static double[] toDoubleArr(this string[] a) { return Array.ConvertAll(a, double.Parse); }
        public static char[] toCharArr(this string[] a) { return Array.ConvertAll(a, char.Parse); }
    }
    static class BitEx {
        public static bool Any(this BitArray b) { foreach (bool f in b) if (f) return true; return false; }
        public static bool All(this BitArray b) { foreach (bool f in b) if (!f) return false; return true; }
        public static bool None(this BitArray b) { return !Any(b); }
        public static void Flip(this BitArray b, int index) { b.Set(index, !b.Get(index)); }
    }
    static class IEnumerableEx {

    }
    #endregion
}