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
        int N;
        int[] A;
        void Solve() {
            io.i(out N);
            io.ini(out A, N);
            //+-+-...
            long sum1 = 0;
            long ans1 = 0;
            N.REP(i => {
                sum1 += A[i];
                if(!i.Odd()){//sum=+
                    if (sum1 <= 0) {
                        ans1 += 1 - sum1;
                        sum1 = 1;
                    }
                }else{       //sum=-
                    if(sum1>=0){
                        ans1 += 1 + sum1;
                        sum1 = -1;
                    }
                }
            });
            //-+-+...
            long sum2 = 0;
            long ans2 = 0;
            N.REP(i => {
                sum2 += A[i];
                if (i.Odd()) {//sum=+
                    if (sum2 <= 0) {
                        ans2 += 1 - sum2;
                        sum2 = 1;
                    }
                } else {       //sum=-
                    if (sum2 >= 0) {
                        ans2 += 1 + sum2;
                        sum2 = -1;
                    }
                }
            });
            io.o(Math.Min(ans1, ans2));
        }

        ////////////////////////////////////////////////////////////
        public static void Main() { new MainClass().Stream(); }
        IO io = new IO();
        void Stream() { Solve(); io.writeFlush(); }
        //void Stream() { Test(); io.writeFlush(); }
        void Test() {
            Mat mat = new Mat();
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
        public void i<T, U, V, W>(out T v1, out U v2, out V v3, out W v4) {
            i(out v1); i(out v2); i(out v3); i(out v4);
        }
        public void i<T, U, V, W, X>(out T v1, out U v2, out V v3, out W v4, out X v5) {
            i(out v1); i(out v2); i(out v3); i(out v4); i(out v5);
        }
        public void ini<T>(out T[] a, int n) { a = new T[n]; for (int i = 0; i < n; i++) a[i] = tp.suitType<T>(String); }
        public void ini<T, U>(out T[] a, out U[] b, int n) {
            a = new T[n]; b = new U[n]; for (int i = 0; i < n; i++) { a[i] = i<T>(); b[i] = i<U>(); }
        }
        public void ini<T, U, V>(out T[] a, out U[] b, out V[] c, int n) {
            a = new T[n]; b = new U[n]; c = new V[n];
            for (int i = 0; i < n; i++) { a[i] = i<T>(); b[i] = i<U>(); c[i] = i<V>(); }
        }
        public void ini<T>(out T[,] a, int h, int w) {
            a = new T[h, w]; for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) a[i, j] = i<T>();
        }
        public void o<T>(T v) { Console.WriteLine(v); }
        public void o<T>(params T[] a) { Array.ForEach(a, n => o(n)); }
        public void o<T>(T[,] a) { a.GetLength(0).REP(i => { a.GetLength(1).REP(j => or(a[i, j] + " ")); br(); }); }
        public void ol<T>(T v) { Console.Write(v + " "); }
        public void ol<T>(params T[] a) { o(connect<T>(a)); }
        public void or<T>(T a) { Console.Write(a); }
        public void br() { o(""); }
        public void writeFlush() { Console.Out.Flush(); }
        private string connect<T>(params T[] s) { return string.Join(" ", s); }
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
        public int mod = 1000000007;//10^9+7
        public long Pow(long a, long b) {
            if (b == 0) return 1;
            if (b % 2 == 1) return (a % mod * Pow(a % mod, b - 1) % mod) % mod;
            else return Pow(a * a % mod, b / 2) % mod;
        }
        public long Fact(long n) { long ret = 1; for (long i = 1; i <= n; i++) ret = (ret * i) % mod; return ret; }
        public long C(long n, long r) {
            if (r == 0 || n == r) return 1;
            if (n == 0) return 0;
            if (n < 0 || n < r) throw new ArgumentException("n,r invalid");
            else return (Fact(n) % mod * Pow((Fact(n - r) % mod * Fact(r) % mod) % mod, mod - 2) % mod) % mod;
        }
        public long DupC(long n, long r) { return C(n + r - 1, r); }
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
        public long DigArr2Num(IEnumerable<int> enu) {return enu.Aggregate((v, n) => v * 10 + n);}
        public int Digit(long n) { return (n == 0) ? 1 : (int)Math.Log10(n) + 1; }
        public int DigVal(int n, int dig) { return (n % (int)Pow(10, dig)) / (int)Pow(10, dig - 1); }
        public long Tousa(long a, long d, long n) { return a + (n - 1) * d; }
        public long TousaSum(long a, long d, long n) { return n * (2 * a + (n - 1) * d) / 2; }
        public IEnumerable<int[]> enuP(int[] Arr, int Use = -1) {//????
            Use = (Use != -1) ? Use : Arr.Length; if (Use == 0 || Arr.Length < Use) yield break;
            var s = new Stack<List<int>>();
            Arr.Length.REPR(i => s.Push(new List<int>() { i }));
            while (s.Count > 0) {
                var cur = s.Pop();
                if (cur.Count == Use) {
                    var ret = new List<int>(); cur.ForEach(X => ret.Add(Arr[X]));
                    yield return ret.ToArray();
                } else
                    Arr.Length.REPR(i => { if (!cur.Contains(i)) s.Push(new List<int>(cur) { i }); });
            }
        }
        public IEnumerable<int[]> enuC(int[] Arr, int Use = -1) {//???????
            Use = (Use != -1) ? Use : Arr.Length; if (Use == 0 || Arr.Length < Use) yield break;
            var s = new Stack<Tuple<int, List<int>>>();
            Arr.Length.REPR(i => s.Push(Tuple.Create(i, new List<int>() { Arr[i] })));
            while (s.Count > 0) {
                var cur = s.Pop();
                if (cur.Item2.Count == Use)yield return cur.Item2.ToArray();
                else for (int i = Arr.GetUpperBound(0); i > cur.Item1; i--)
                        s.Push(Tuple.Create(i, new List<int>(cur.Item2) { Arr[i] }));
            }
        }
        public IEnumerable<int[]> enuDupP(int[] Arr, int Use = -1) {//??????
            Use = (Use != -1) ? Use : Arr.Length; if (Use == 0) yield break; var s = new Stack<List<int>>();
            Arr.Length.REPR(i => s.Push(new List<int>() { Arr[i] }));
            while (s.Count > 0) {
                var cur = s.Pop();
                if (cur.Count == Use)yield return cur.ToArray();
                else Arr.Length.REPR(i => s.Push(new List<int>(cur) { Arr[i] }));
            }
        }
        public IEnumerable<int[]> enuDupC(int[] Arr, int Use = -1) {//???????
            Use = (Use != -1) ? Use : Arr.Length; if (Use == 0) yield break;
            var s = new Stack<Tuple<int, List<int>>>();
            Arr.Length.REPR(i => s.Push(Tuple.Create(i, new List<int>() { Arr[i] })));
            while (s.Count > 0) {
                var cur = s.Pop();
                if (cur.Item2.Count == Use)yield return cur.Item2.ToArray();
                else for (int i = Arr.GetUpperBound(0); i >= cur.Item1; i--)
                        s.Push(Tuple.Create(i, new List<int>(cur.Item2) { Arr[i] }));
            }
        }
        public IEnumerable<long[]> enuPart(string str) {
            var s = new Stack<Tuple<string, List<long>, int>>();
            s.Push(Tuple.Create(str[0].ToString(), new List<long>(), 1));
            while (s.Count > 0) {
                var cur = s.Pop();
                if (cur.Item3 >= str.Length) yield return (new List<long>(cur.Item2) { cur.Item1.toLong() }).ToArray();
                 else {
                    s.Push(Tuple.Create(cur.Item1 + str[cur.Item3], new List<long>(cur.Item2), cur.Item3 + 1));
                    s.Push(Tuple.Create(str[cur.Item3].ToString(), new List<long>(cur.Item2) { cur.Item1.toLong() }, cur.Item3 + 1));
                }
            }
        }
    }
    class Time {
        public int[] M = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
        public int[] D = { 31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        public Time() { D[1] = 28; }
        public Time(int y) { D[1] = isLeapYear(y) ? 29 : 28; }
        public bool isLeapYear(int y) { return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)); }
    }
    #endregion
    #region Data
    class AssociativeArray<T> : IEnumerable {//hack:KeyValuePair??????????
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
        public T MaxKey => dic.First(d => d.Value == MaxVal).Key;//TLE
        public T MinKey => dic.First(d => d.Value == MinVal).Key;//TLE
        public T MaxK() { var maxV = MaxVal; return dic.First(d => d.Value == maxV).Key; }
        public T MinK() { var minV = MinVal; return dic.First(d => d.Value == minV).Key; }
        public bool conK(T k) { return dic.ContainsKey(k); }
        public bool anyK(params T[] k) { return k.Any(key => conK(key)); }
        public bool allK(params T[] k) { return k.All(key => conK(key)); }
        public void Show() { foreach (var v in dic) { Console.WriteLine(v.Key + " : " + v.Value); } }
        public IEnumerator GetEnumerator() { foreach (var kp in dic) yield return kp; }
        public T[] ValueSortedKey(bool inc=true) {//test
            return (inc? (dic.OrderBy(kp => kp.Value)):(dic.OrderByDescending(kp=>kp.Value)))
                .ThenBy(kp => kp.Key).ToDictionary(kp => kp.Key, kp => kp.Value).Keys.ToArray();     
        }
        //:sort->array
    }
    class Index {
        public int[] Comp(int[] bef) {
            int[] aft = new int[bef.Length];
            var tmp = bef.Distinct().OrderBy(v => v).Select((v, i) => new { v, i }).ToDictionary(p => p.v, p => p.i);
            aft = bef.Select(v => tmp[v]).ToArray();
            return aft;
        }
    }
    class BasicGraph {//??
        public List<Tuple<int, long>>[] G;
        public void Init(int n) { G = new List<Tuple<int, long>>[n + 1]; G.Length.REP(i => G[i] = new List<Tuple<int, long>>()); }
        public void Dir(int[] f, int[] t) { f.Length.REP(i => G[f[i]].Add(Tuple.Create(t[i], 1L))); }
        public void Dir(int[] f, int[] t, long[] c) { f.Length.REP(i => G[f[i]].Add(Tuple.Create(t[i], c[i]))); }
        public void NonDir(int[] f, int[] t) { f.Length.REP(i => { G[f[i]].Add(Tuple.Create(t[i], 1L)); G[t[i]].Add(Tuple.Create(f[i], 1L)); }); }
        public void NonDir(int[] f, int[] t, long[] c) { f.Length.REP(i => { G[f[i]].Add(Tuple.Create(t[i], c[i])); G[t[i]].Add(Tuple.Create(f[i], c[i])); }); }
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
    class ShortestPath {
        public long INF = (long)1e15; protected int I = -1; protected int V; protected int E; public long[] cost;
        public List<Tuple<int, long>>[] Adj; protected bool isNonDir = true;
        public void Init(int n) { I = n + 1; V = n; Adj = new List<Tuple<int, long>>[I]; I.REP(i => Adj[i] = new List<Tuple<int, long>>()); }
        public void AddPath(int f, int t, long c) {
            E++;
            if (isNonDir) {
                Adj[f].Add(Tuple.Create(t, c)); Adj[t].Add(Tuple.Create(f, c));
            } else {
                Adj[f].Add(Tuple.Create(t, c));
            }
        }
        public void AddPath(int[] f, int[] t, long[] c) { f.Length.REP(i => AddPath(f[i], t[i], c[i])); }
    }
    class Dijkstra : ShortestPath {//?????????,??
        public long MinCost(int f, int t) {
            cost = new long[I]; cost.Set(INF); cost[f] = 0;
            var pq = new PQueue<Tuple<int, long>>(); pq.Enqueue(Tuple.Create(f, 0L));//(from,cost)
            while (pq.Count > 0) {
                var cur = pq.Dequeue();
                if (cost[cur.Item1] < cur.Item2) continue; Adj[cur.Item1].Count.REP(i => {
                    var tmp = Adj[cur.Item1][i];
                    if (cost[tmp.Item1] > cost[cur.Item1] + tmp.Item2) {
                        cost[tmp.Item1] = cost[cur.Item1] + tmp.Item2; pq.Enqueue(Tuple.Create(tmp.Item1, cost[tmp.Item1]));
                    }
                });
            }
            return cost[t];
        }
    }
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
    class WarshallFloyd {//????Adj????????...TODO:??????
        private int E; private int INF = (int)1e9; public long[,] G;
        public void Init(int n) { E = n + 1; G = new long[E, E]; G.Set(INF); E.REP(i => G[i, i] = 0); }
        public void AddPath(int f, int t, long c) { G[f, t] = c; G[t, f] = c; }
        public void AddPath(int[] f, int[] t) { f.Length.REP(i => AddPath(f[i], t[i], 1)); }
        public void AddPath(int[] f, int[] t, long[] c) { f.Length.REP(i => AddPath(f[i], t[i], c[i])); }
        public void Run() { G = MinCostArr(); }
        public long[,] MinCostArr() { E.REP(i => E.REP(j => E.REP(k => G[j, k] = Math.Min(G[j, k], G[j, i] + G[i, k])))); return G; }
    }
    class UnionFind {
        public long[] parent; public long[] depth; private int I;
        public void Init(int n) { I = n + 1; parent = new long[I]; depth = new long[I]; I.REP(i => parent[i] = i); }
        public long Find(long x) { return (parent[x] == x) ? x : parent[x] = Find(parent[x]); }
        public void Unite(long x, long y) {
            x = Find(x); y = Find(y); if (x == y) return;
            if (depth[x] < depth[y]) parent[x] = y; else { parent[y] = x; if (depth[x] == depth[y]) depth[x]++; }
        }
        public bool Same(int a, int b) { return Find(a) == Find(b); }
        public long Size(int x) { return depth[Find(x)]; }
    }
    class Kruskal : ShortestPath {//TODO:test,
        public long Run() {
            var L = Adj.Select((l, i) => Tuple.Create(i, l[i].Item1, l[i].Item2)).OrderBy(t => t.Item3).ToList();
            //var li = new List<Tuple<int, int, long>>();
            //I.REP(i =>{ foreach (var t in Adj[i]) li.Add(Tuple.Create(i, t.Item1, t.Item2));});
            //li = li.OrderBy(t => t.Item3).ToList();//li = li.OrderByDescending(t => t.Item3).ToList();
            var uf = new UnionFind(); uf.Init(V); long ret = 0;
            foreach (var t in L) {
                if (!uf.Same(t.Item1, t.Item2)) {
                    ret += t.Item3; uf.Unite(t.Item1, t.Item2);
                }
            }
            return ret;
        }
    }
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
    }
    static class BitEx {
        public static bool Any(this BitArray b) { foreach (bool f in b) if (f) return true; return false; }
        public static bool All(this BitArray b) { foreach (bool f in b) if (!f) return false; return true; }
        public static bool None(this BitArray b) { return !Any(b); }
        public static void Flip(this BitArray b, int index) { b.Set(index, !b.Get(index)); }
    }
    static class IEnumerableEx {
        //
    }
    #endregion
}